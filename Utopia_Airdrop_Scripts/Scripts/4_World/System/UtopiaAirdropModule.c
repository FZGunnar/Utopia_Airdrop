static ref UtopiaAirdropModule GetUtopiaAirdropModule()
{
    return UtopiaAirdropModule.Cast(CF_ModuleCoreManager.Get(UtopiaAirdropModule));
}

[CF_RegisterModule(UtopiaAirdropModule)]
class UtopiaAirdropModule : CF_ModuleWorld
{
    ref UtopiaAirdropSettings settings;
    int minPlayersToStartAirdrop = 2; // Default minimum player count   
    ref array<Man> players = new array<Man>;
    
    override void OnInit()
    {
        super.OnInit();
        EnableMissionStart();
        EnableUpdate();
        EnableInvokeConnect();

        UtopiaLogger.Log("[AIRDROP] UtopiaAirdropModule - OnInit", "Airdrop");  // Updated log with centralized UtopiaLogger
        GetRPCManager().AddRPC("Utopia_Airdrop", "ClientCallAirdropByFlare", this, SingleplayerExecutionType.Both);
        GetRPCManager().AddRPC("Utopia_Airdrop", "SyncToClient", this);
    }

    UtopiaAirdropSettings GetUtopiaAirdropSettings()
    {
        return settings;
    }

    void ClientCallAirdropByFlare(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (GetGame().IsServer())
        {
            Param2<vector, string> data;//skip
            if (!ctx.Read(data)) return;

            vector calledPosition = data.param1;//skip
            string calledFlare = data.param2;//skip

            UtopiaLogger.Log(string.Format("[AIRDROP] Called by %1", calledFlare), "Airdrop");

            if (settings && settings.flareAirdropContainers)
            {
                vector pos = Vector(calledPosition[0], 0, calledPosition[2]);
                UtopiaAirdropLocation airdropLocation = new UtopiaAirdropLocation("Unknown location", pos, 5, calledFlare);

                UtopiaLogger.Log(string.Format("[AIRDROP] [%2] Airdrop will be requested at position: %1", pos.ToString(), calledFlare), "Airdrop");

                foreach (UtopiaAirdropFlareContainer container : settings.flareAirdropContainers)
                {
                    if (container.itemName == calledFlare)
                    {
                        // Use flare-specific plane type and creatures for this airdrop location
                        airdropLocation.planeType = container.planeType;
                        airdropLocation.creaturesToSpawn = container.creaturesToSpawn;
                        
                        // Insert the container configuration for this flare
                        airdropLocation.airdropContainers.Insert(UtopiaAirdropContainer.Cast(container));
                    }
                }

                if (airdropLocation.airdropContainers.Count() > 0)
                {
                    if (settings.showMarkerForFlareDrop)
                        ShowMarker(airdropLocation);

                    SendNotification(string.Format(settings.startMsg, airdropLocation.name));
                    RequestAirdropAtLocation(airdropLocation);
                }
            }
        }
    }



    void SyncToClient(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
        Param1<autoptr UtopiaAirdropSettings> data;
        if (!ctx.Read(data)) return;

        settings = data.param1;
        Print("[SyncToClient] Config has been synced");
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(PlayerBase.Cast(target).MessageImportant, 5000, false, "Config has been synced");
        // PlayerBase.Cast(target).MessageImportant("Config has been synced");
	}

    override void OnInvokeConnect(Class sender, CF_EventArgs args)
	{
		super.OnInvokeConnect(sender, args);

		auto player = CF_EventPlayerArgs.Cast(args).Player;
		
        GetRPCManager().SendRPC("Utopia_Airdrop", "SyncToClient", new Param1<autoptr UtopiaAirdropSettings>(settings), true, player.GetIdentity(), player);
	}

    void InitializeModule()
    {
        UtopiaLogger.Log("UtopiaAirdropModule has started", "Airdrop");

        if (GetGame().IsServer())
        {
            settings = UtopiaAirdropSettings.Load();

            if (settings == null)
            {
                UtopiaLogger.Log("Failed to load UtopiaAirdropSettings!", "Airdrop");
                return;
            }

            minPlayersToStartAirdrop = settings.minPlayersToStartAirdrop;

            if (settings.dropLocations.Count() == 0)
            {
                UtopiaLogger.Log("No drop locations defined!", "Airdrop");
                return;
            }

            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StartEventScheduler, settings.startDelayMin * 60000, false);
        }
    }

    void StartEventScheduler()
    {
        AirdropEventHandler();
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(AirdropEventHandler, settings.pkgIntervalMin * 60000, true);
    }

    void AirdropEventHandler()
    {
        UtopiaLogger.Log("[AIRDROP] AirdropEventHandler dropLocations count: " + settings.dropLocations.Count(), "Airdrop");
        UtopiaLogger.Log("[AIRDROP] Player count: " + players.Count(), "Airdrop");

        if (settings.dropLocations.Count() < 1)
        {
            UtopiaLogger.Log("[AIRDROP] All airdrop locations have been picked, no more locations to drop!", "Airdrop");
            return;
        }

        players.Clear();
        GetGame().GetPlayers(players);

        if (players.Count() < minPlayersToStartAirdrop)
        {
            UtopiaLogger.Log("[AIRDROP] Players to start the airdrop: " + players.Count(), "Airdrop");
            return;
        }

        int idx = settings.dropLocations.GetRandomIndex();
        UtopiaAirdropLocation airdropLocation = settings.dropLocations[idx];
        UtopiaLogger.Log("Location picked: " + airdropLocation.name, "Airdrop");

        ShowMarker(airdropLocation);

        SendNotification(string.Format(settings.startMsg, airdropLocation.name));

        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(RequestAirdropAtLocation, settings.awayMin * 60000, false, airdropLocation);
        settings.dropLocations.RemoveOrdered(idx);
    }

    void ShowMarker(UtopiaAirdropLocation airdropLocation)
    {
        UtopiaLogger.Log("[AIRDROP] ShowMarker", "Airdrop");

        // Set the correct Y-coordinate for the drop position
        airdropLocation.dropPosition[1] = GetGame().SurfaceY(airdropLocation.dropPosition[0], airdropLocation.dropPosition[2]);

        string name = "AIR DROP " + airdropLocation.name;
        UtopiaLogger.Log("[AIRDROP] ShowMarker " + name + " at " + airdropLocation.dropPosition.ToString(), "Airdrop");

         #ifdef BASICMAP
            UtopiaLogger().LogDebug("[AIRDROP] ShowMarker " + name + " at " + airdropLocation.dropPosition.ToString());
            BasicMapMarker marker = BasicMap().CreateAirdropServerMarker(name, airdropLocation.dropPosition);
            int markerId = UtopiaMarkerManager.AddBMMarker(marker);
            airdropLocation.SetMarkerId(markerId);
        #endif

        #ifdef LBmaster_Groups
        int lbMarkerId = UtopiaMarkerManager.AddLBMarker(name, airdropLocation.dropPosition, "Utopia_Airdrop\\Datasets\\airdrop.paa", {255, 188, 0});
        airdropLocation.SetMarkerId(lbMarkerId);
        UtopiaLogger.Log("[AIRDROP] LB marker created with ID: " + lbMarkerId, "Airdrop");
        #endif
    }



    #ifdef LBGROUP_SYSTEM
        // Separated logic to handle marker update into its own method
        void CreateLBMarker(UtopiaAirdropLocation airdropLocation)
        {
            UtopiaLogger().LogDebug("CreateLBMarker");
            string name = "AIR DROP " + airdropLocation.name;
        #ifdef LBmaster_Rework
                LBServerMarker marker = LBStaticMarkerManager.Get.AddTempServerMarker(name, airdropLocation.dropPosition, "Utopia_Airdrop\\Datasets\\airdrop.paa", ARGB(255, 226, 162, 34), false, true, true, true);
        #else

            LBServerMarker marker = LBStaticMarkerManager.Get.AddTempServerMarker(name, airdropLocation.dropPosition, "Utopia_Airdrop\\Datasets\\airdrop.paa", ARGB(255, 226, 162, 34), false, true, true, true);
        #endif
                if (!marker) {
                UtopiaLogger().LogError("CreateLBMarker: Failed to create marker for " + name);
                return;
            }

            int markerId = marker.uid; // Use the marker’s UID, not the marker itself
            airdropLocation.SetMarkerId(markerId); // Correctly use the ID for the UtopiaAirdropLocation

            }
        #endif 

        
    void RequestAirdropAtLocation(UtopiaAirdropLocation airdropLocation)
    {
        UtopiaLogger.Log("[AIRDROP] RequestAirdropAtLocation", "Airdrop");

        vector startingLocation = CalculateStartingLocation(airdropLocation);

        // Pass both the starting location and the airdrop location to the SpawnPlane function
        UtopiaAirdropPlane plane = SpawnPlane(startingLocation, airdropLocation);

        if (!plane)
        {
            UtopiaLogger.LogError("[AIRDROP] Plane couldn't be created! Check syntax!", "Airdrop");
            return;
        }

        plane.SetDirection(startingLocation - airdropLocation.dropPosition);
        plane.SetupPlane(airdropLocation);
    }

    
    vector CalculateStartingLocation(UtopiaAirdropLocation airdropLocation)
    {
        vector startingLocation;
        float angle = Math.RandomFloatInclusive(-Math.PI, Math.PI);
        startingLocation[0] = airdropLocation.dropPosition[0] + 3000 * Math.Cos(angle);
        startingLocation[2] = airdropLocation.dropPosition[2] + 3000 * Math.Sin(angle);

        while(startingLocation[0] < settings.leftBottomCornerMap[0] ||  startingLocation[0] > settings.rightUpCornerMap[0] || startingLocation[2] <  settings.leftBottomCornerMap[2] || startingLocation[2] >  settings.rightUpCornerMap[2])
        {
            angle = Math.RandomFloatInclusive(-Math.PI, Math.PI);
            startingLocation[0] = airdropLocation.dropPosition[0] + 3000 * Math.Cos(angle);
            startingLocation[2] = airdropLocation.dropPosition[2] + 3000 * Math.Sin(angle);
        }

        startingLocation = UtopiaAirdropHelper.SnapToGround(startingLocation);
        startingLocation[1] = startingLocation[1] + 500;
        return startingLocation;
    }

    static vector SnapToGround(vector pos)
	{
		float pos_x = pos[0];
		float pos_z = pos[2];
		float pos_y = GetGame().SurfaceY(pos_x, pos_z);
		vector tmp_pos = Vector(pos_x, pos_y, pos_z);
		tmp_pos[1] = tmp_pos[1] + pos[1];

		return tmp_pos;
	}

    UtopiaAirdropPlane SpawnPlane(vector startingLocation, UtopiaAirdropLocation location)
    {
        // Check if settings exist and log an error if not
        if (!GetUtopiaAirdropSettings())
        {
            UtopiaLogger().LogError("[AIRDROP] Failed to retrieve UtopiaAirdropSettings. Using default plane type.");
            return null;
        }

        // Define the planeType variable as a string
        string planeType = "";

        // Debug logging to ensure values are as expected
        UtopiaLogger().LogDebug("[AIRDROP] location.planeType: '" + location.planeType + "'");
        UtopiaLogger().LogDebug("[AIRDROP] GetUtopiaAirdropSettings().planeType: '" + GetUtopiaAirdropSettings().planeType + "'");

        // Check if location-specific plane type is set and not empty
        if (location.planeType && location.planeType.Trim() != "")
        {
            planeType = location.planeType.Trim(); // Use the location-specific plane type
            UtopiaLogger().LogDebug("[AIRDROP] Using location-specific plane type: '" + planeType + "'");
        }
        else if (GetUtopiaAirdropSettings().planeType && GetUtopiaAirdropSettings().planeType.Trim() != "")
        {
            planeType = GetUtopiaAirdropSettings().planeType.Trim(); // Use the default plane type from settings
            UtopiaLogger().LogDebug("[AIRDROP] Using default settings plane type: '" + planeType + "'");
        }
        else
        {
            UtopiaLogger().LogError("[AIRDROP] Plane type is null or empty. Defaulting to 'Utopia_S64_Skycrane'.");
            planeType = "Utopia_S64_Skycrane"; // Default to a known working type
        }

        // Log final plane type before creation
        UtopiaLogger().LogDebug("[AIRDROP] Final plane type for creation: '" + planeType + "' at starting location: " + startingLocation.ToString());

        // Create the plane object using the final plane type
        UtopiaAirdropPlane plane = UtopiaAirdropPlane.Cast(GetGame().CreateObject(planeType, startingLocation, false, true, true));
        if (!plane)
        {
            UtopiaLogger().LogError("[AIRDROP] Failed to create plane of type: '" + planeType + "'. Check class name and syntax.");
            return null;
        }

        // Successfully created the plane
        plane.SetPosition(startingLocation);
        UtopiaLogger().LogDebug("[AIRDROP] Plane created successfully at starting location: " + startingLocation.ToString() + ", Plane type: '" + planeType + "'");
        return plane;
    }





    void CreateEntitiesAroundContainer(vector position, array<string> creaturesToSpawn)
    {
        UtopiaLogger().LogDebug("[AIRDROP] CreateEntitiesAroundContainer called at position: " + position);

        if (!creaturesToSpawn || creaturesToSpawn.Count() == 0)
        {
            UtopiaLogger().LogError("[AIRDROP] No creatures defined for this location. Creatures will not be spawned.");
            return;
        }

        for (int i = 0; i < creaturesToSpawn.Count(); ++i) 
        {
            string creaturePicked = creaturesToSpawn.Get(i);
            UtopiaLogger().LogDebug("[AIRDROP] Creature to spawn: " + creaturePicked);

            vector creaturePosition = UtopiaAirdropHelper.SnapToGround(Vector(position[0] + Math.RandomFloat(-30.0, 30.0), 0, position[2] + Math.RandomFloat(-30.0, 30.0)));
            UtopiaLogger().LogDebug("[AIRDROP] Spawn location before creation: " + creaturePosition.ToString());

            // Use CreateObjectEx with ECE_PLACE_ON_SURFACE to spawn on the ground for all entity types
            EntityAI entity = EntityAI.Cast(GetGame().CreateObjectEx(creaturePicked, creaturePosition, ECE_PLACE_ON_SURFACE | ECE_INITAI | ECE_NOLIFETIME));

            if (entity) 
            {
                UtopiaLogger().LogDebug("[AIRDROP] Entity " + entity.GetType() + " spawned at location: " + entity.GetPosition());

                // Additional handling for specific entity types if needed
                DayZCreatureAI creatureAI = DayZCreatureAI.Cast(entity);
                if (creatureAI)
                {
                    UtopiaLogger().LogDebug("[AIRDROP] Configuring additional settings for creature AI.");
                    // Add AI-specific initialization here
                }
            }
            else 
            {
                UtopiaLogger().LogError("[AIRDROP] Failed to spawn entity " + creaturePicked);
            }
        }
    }




	void SendNotification(string message)
	{
		NotificationSystem.SendNotificationToPlayerIdentityExtended(null, 4, settings.title, message, "Utopia_Airdrop\\Datasets\\airdrop.paa");
	}

    override void OnMissionStart(Class sender, CF_EventArgs args)
    {
        super.OnMissionStart(sender, args);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(InitializeModule, 1000); 
    }
}
