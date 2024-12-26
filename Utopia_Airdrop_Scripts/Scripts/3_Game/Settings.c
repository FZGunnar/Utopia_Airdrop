class UtopiaAirdropSettings
{
    string version = UTOPIA_AIRDROP_VERSION;
    int heliHeightFromGround = 250;
    float heliSpeed = 50.0;
    int dropCrateContainerLifetimeInSeconds = 1800;
    int removeNettingTimeInSeconds = 15;
    int minPlayersToStartAirdrop;
    int startDelayMin;
    int pkgIntervalMin;
    float awayMin;
    string title;
    string droppedMsg;
    string startMsg;
    string planeType = "Utopia_S64_Skycrane"; // Default plane type
    bool showMarkerForFlareDrop;
    vector leftBottomCornerMap;
    vector rightUpCornerMap;
    ref array<ref UtopiaAirdropFlareContainer> flareAirdropContainers;
    ref array<ref UtopiaAirdropLocation> dropLocations;
    ref array<ref UtopiaAirdropLootPool> lootPools;
    [NonSerialized()]
    ref array<Man> players;

    void UtopiaAirdropSettings()
    {
        dropLocations = new array<ref UtopiaAirdropLocation>();
        lootPools = new array<ref UtopiaAirdropLootPool>();
        flareAirdropContainers = new array<ref UtopiaAirdropFlareContainer>();
        players = new array<Man>();
    }

    void DefaultSettings()
        {
        vector position1 = Vector(12218, 0, 12545);
        vector position2 = Vector(12005, 0, 12694);
        vector position3 = Vector(12115, 0, 12394);

        // Adjust the Y-coordinate to the ground level
        position1[1] = GetGame().SurfaceY(position1[0], position1[2]);
        position2[1] = GetGame().SurfaceY(position2[0], position2[2]);
        position3[1] = GetGame().SurfaceY(position3[0], position3[2]);

        dropLocations.Insert(new UtopiaAirdropLocation("Krasnostav Airstrip - 1", position1, 50, "Utopia_S64_Skycrane"));
        dropLocations[0].airdropContainers.Insert(new UtopiaAirdropContainer(true, "Utopia_Car_Parachute"));
        dropLocations[0].airdropContainers[0].lootPools.Insert("Tier - 4");
        dropLocations[0].airdropContainers[0].lootPools.Insert("Tier - 5");
        dropLocations[0].airdropContainers[0].lootPools.Insert("Tier - 6");
        dropLocations[0].airdropContainers.Insert(new UtopiaAirdropContainer(false, "Utopia_Crate_Parachute"));
        dropLocations[0].airdropContainers[1].lootPools.Insert("Tier - 1");
        dropLocations[0].airdropContainers[1].lootPools.Insert("Tier - 2");
        dropLocations[0].airdropContainers[1].lootPools.Insert("Tier - 3");
        dropLocations[0].airdropContainers.Insert(new UtopiaAirdropContainer(false, "Utopia_Container_Parachute"));
        dropLocations[0].airdropContainers[2].lootPools.Insert("Tier - 1");
        dropLocations[0].airdropContainers[2].lootPools.Insert("Tier - 2");
        dropLocations[0].airdropContainers[2].lootPools.Insert("Tier - 3");
        dropLocations[0].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Autumn"); // Configure creatures
        dropLocations[0].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Flat");
        dropLocations[0].numberOfCreatures = 5; // Set the number of creatures to spawn for this location

        dropLocations.Insert(new UtopiaAirdropLocation("Krasnostav Airstrip - 2", position2, 50, "Utopia_S64_Skycrane"));
        dropLocations[1].airdropContainers.Insert(new UtopiaAirdropContainer(true, "Utopia_Car_Parachute"));
        dropLocations[1].airdropContainers[0].lootPools.Insert("Tier - 4");
        dropLocations[1].airdropContainers[0].lootPools.Insert("Tier - 5");
        dropLocations[1].airdropContainers[0].lootPools.Insert("Tier - 6");
        dropLocations[1].airdropContainers.Insert(new UtopiaAirdropContainer(false, "Utopia_Crate_Parachute"));
        dropLocations[1].airdropContainers[1].lootPools.Insert("Tier - 1");
        dropLocations[1].airdropContainers[1].lootPools.Insert("Tier - 2");
        dropLocations[1].airdropContainers[1].lootPools.Insert("Tier - 3");
        dropLocations[1].airdropContainers.Insert(new UtopiaAirdropContainer(false, "Utopia_Container_Parachute"));
        dropLocations[1].airdropContainers[2].lootPools.Insert("Tier - 1");
        dropLocations[1].airdropContainers[2].lootPools.Insert("Tier - 2");
        dropLocations[1].airdropContainers[2].lootPools.Insert("Tier - 3");
        dropLocations[1].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Summer"); // Configure different creatures for this location
        dropLocations[1].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Summer");
        dropLocations[1].numberOfCreatures = 3;

        dropLocations.Insert(new UtopiaAirdropLocation("Krasnostav Airstrip - 3", position3, 50, "Utopia_S64_Skycrane"));
        dropLocations[2].airdropContainers.Insert(new UtopiaAirdropContainer(false, "Utopia_Container_Parachute"));
        dropLocations[2].airdropContainers[0].lootPools.Insert("Tier - 1");
        dropLocations[2].airdropContainers[0].lootPools.Insert("Tier - 2");
        dropLocations[2].airdropContainers[0].lootPools.Insert("Tier - 3");
        dropLocations[2].airdropContainers.Insert(new UtopiaAirdropContainer(false, "Utopia_Crate_Parachute"));
        dropLocations[2].airdropContainers[1].lootPools.Insert("Tier - 1");
        dropLocations[2].airdropContainers[1].lootPools.Insert("Tier - 2");
        dropLocations[2].airdropContainers[1].lootPools.Insert("Tier - 3");
        dropLocations[2].airdropContainers.Insert(new UtopiaAirdropContainer(false, "Utopia_Container_Parachute"));
        dropLocations[2].airdropContainers[2].lootPools.Insert("Tier - 1");
        dropLocations[2].airdropContainers[2].lootPools.Insert("Tier - 2");
        dropLocations[2].airdropContainers[2].lootPools.Insert("Tier - 3");
        dropLocations[2].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Winter"); // Configure creatures for this location
        dropLocations[2].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Winter");
        dropLocations[2].numberOfCreatures = 8;

        flareAirdropContainers.Insert(new UtopiaAirdropFlareContainer(true, "Utopia_Car_Parachute", "Bullet_Car_Flare"));
        flareAirdropContainers[0].lootPools.Insert("Tier - 4");
        flareAirdropContainers[0].lootPools.Insert("Tier - 5");
        flareAirdropContainers[0].lootPools.Insert("Tier - 6");
        flareAirdropContainers[0].planeType = "Utopia_AH64D_Apache"; // Specify the plane type for this flare
        flareAirdropContainers[0].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Summer"); // Configure creatures for this flare
        flareAirdropContainers[0].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Summer");
        flareAirdropContainers.Insert(new UtopiaAirdropFlareContainer(false, "Utopia_Crate_Parachute", "UtopiaAirdropFlare"));
        flareAirdropContainers[1].lootPools.Insert("Tier - 1");
        flareAirdropContainers[1].lootPools.Insert("Tier - 2");
        flareAirdropContainers[1].lootPools.Insert("Tier - 3");
        flareAirdropContainers[1].planeType = "Utopia_V22_Osprey"; // Different plane for this flare
        flareAirdropContainers[1].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Winter");
        flareAirdropContainers[1].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Winter");
        flareAirdropContainers.Insert(new UtopiaAirdropFlareContainer(false, "Utopia_Crate_Parachute", "UtopiaAirdropFlare"));
        flareAirdropContainers[2].lootPools.Insert("Tier - 1");
        flareAirdropContainers[2].lootPools.Insert("Tier - 2");
        flareAirdropContainers[2].lootPools.Insert("Tier - 3");
        flareAirdropContainers[2].planeType = "Utopia_V22_Osprey"; // Different plane for this flare
        flareAirdropContainers[2].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Winter");
        flareAirdropContainers[2].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Winter");

        flareAirdropContainers.Insert(new UtopiaAirdropFlareContainer(true, "Utopia_Car_Parachute", "UtopiaAirdropFlare"));
        flareAirdropContainers[3].lootPools.Insert("Tier - 4");
        flareAirdropContainers[3].lootPools.Insert("Tier - 5");
        flareAirdropContainers[3].lootPools.Insert("Tier - 6");
        flareAirdropContainers[3].planeType = "Utopia_AH64D_Apache"; // Specify the plane type for this flare
        flareAirdropContainers[3].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Summer"); // Configure creatures for this flare
        flareAirdropContainers[3].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Summer");
        flareAirdropContainers.Insert(new UtopiaAirdropFlareContainer(false, "Utopia_Crate_Parachute", "UtopiaAirdropFlare"));
        flareAirdropContainers[4].lootPools.Insert("Tier - 4");
        flareAirdropContainers[4].lootPools.Insert("Tier - 5");
        flareAirdropContainers[4].lootPools.Insert("Tier - 6");
        flareAirdropContainers[4].planeType = "Utopia_AH64D_Apache"; // Specify the plane type for this flare
        flareAirdropContainers[4].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Summer"); // Configure creatures for this flare
        flareAirdropContainers[4].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Summer");
        flareAirdropContainers.Insert(new UtopiaAirdropFlareContainer(false, "Utopia_Container_Parachute", "UtopiaAirdropFlare"));
        flareAirdropContainers[5].lootPools.Insert("Tier - 1");
        flareAirdropContainers[5].lootPools.Insert("Tier - 2");
        flareAirdropContainers[5].lootPools.Insert("Tier - 3");
        flareAirdropContainers[5].planeType = "Utopia_V22_Osprey"; // Different plane for this flare
        flareAirdropContainers[5].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Winter");
        flareAirdropContainers[5].creaturesToSpawn.Insert("ZmbM_PatrolNormal_Winter");
        

        lootPools.Insert(new UtopiaAirdropLootPool("Tier - 1", 5));
		lootPools[0].items.Insert(new UtopiaAirdropItem("AKM",1));
		lootPools[0].items.Insert(new UtopiaAirdropItem("M4A1",1));
		lootPools.Insert(new UtopiaAirdropLootPool("Tier - 2", 3));
		lootPools[1].items.Insert(new UtopiaAirdropItem("AK74",1));
		lootPools[1].items.Insert(new UtopiaAirdropItem("AKM",1));
		lootPools.Insert(new UtopiaAirdropLootPool("Tier - 3",  1));
		lootPools[2].items.Insert(new UtopiaAirdropItem("AKM",1));
		lootPools[2].items[0].attachments.Insert(new UtopiaAirdropAttachment("Mag_AKM_Drum75Rnd",1));
		lootPools[2].items[0].attachments.Insert(new UtopiaAirdropAttachment("AK_WoodBttstck",1));
		lootPools[2].items.Insert(new UtopiaAirdropItem("RGD5Grenade",1));

        lootPools.Insert(new UtopiaAirdropLootPool("Tier - 4",  1));
		lootPools[3].items.Insert(new UtopiaAirdropItem("OffroadHatchback",1));
		lootPools[3].items[0].attachments.Insert(new UtopiaAirdropAttachment("SparkPlug",1));
		lootPools[3].items[0].attachments.Insert(new UtopiaAirdropAttachment("CarBattery",1));
        lootPools[3].items[0].attachments.Insert(new UtopiaAirdropAttachment("CarRadiator",1));
		lootPools[3].items[0].attachments.Insert(new UtopiaAirdropAttachment("HeadlightH7",1));
        lootPools[3].items[0].attachments.Insert(new UtopiaAirdropAttachment("HeadlightH7",1));
		lootPools[3].items[0].attachments.Insert(new UtopiaAirdropAttachment("HatchbackDoors_CoDriver",1));
        lootPools[3].items[0].attachments.Insert(new UtopiaAirdropAttachment("HatchbackDoors_Driver",1));
		lootPools[3].items[0].attachments.Insert(new UtopiaAirdropAttachment("HatchbackHood",1));
        lootPools[3].items[0].attachments.Insert(new UtopiaAirdropAttachment("HatchbackTrunk",1));
		lootPools[3].items[0].attachments.Insert(new UtopiaAirdropAttachment("HatchbackWheel",1));
        lootPools[3].items[0].attachments.Insert(new UtopiaAirdropAttachment("HatchbackWheel",1));
        lootPools[3].items[0].attachments.Insert(new UtopiaAirdropAttachment("HatchbackWheel",1));
        lootPools[3].items[0].attachments.Insert(new UtopiaAirdropAttachment("HatchbackWheel",1));

        lootPools.Insert(new UtopiaAirdropLootPool("Tier - 5",  1));
		lootPools[4].items.Insert(new UtopiaAirdropItem("CivilianSedan",1));
		lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("SparkPlug",1));
		lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("CarBattery",1));
        lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("CarRadiator",1));
		lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("HeadlightH7",1));
        lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("HeadlightH7",1));
		lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("CivSedanDoors_Driver_WhiteRust",1));
        lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("CivSedanDoors_CoDriver_WhiteRust",1));
        lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("CivSedanDoors_BackLeft_WhiteRust",1));
        lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("CivSedanDoors_BackRight_WhiteRust",1));
		lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("CivSedanHood_WhiteRust",1));
        lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("CivSedanTrunk_WhiteRust",1));
		lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("CivSedanWheel",1));
        lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("CivSedanWheel",1));
        lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("CivSedanWheel",1));
        lootPools[4].items[0].attachments.Insert(new UtopiaAirdropAttachment("CivSedanWheel",1));

        lootPools.Insert(new UtopiaAirdropLootPool("Tier - 6",  1));
		lootPools[5].items.Insert(new UtopiaAirdropItem("Sedan_02_Grey",1));
		lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("SparkPlug",1));
		lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("CarBattery",1));
        lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("CarRadiator",1));
		lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("HeadlightH7",1));
        lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("HeadlightH7",1));
		lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("Sedan_02_Door_2_1_GreyRust",1));
        lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("Sedan_02_Door_2_2_GreyRust",1));
        lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("Sedan_02_Door_2_1_GreyRust",1));
        lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("Sedan_02_Door_2_2_GreyRust",1));
		lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("Sedan_02_Hood_GreyRust",1));
        lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("Sedan_02_Trunk_GreyRust",1));
		lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("Sedan_02_Wheel",1));
        lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("Sedan_02_Wheel",1));
        lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("Sedan_02_Wheel",1));
        lootPools[5].items[0].attachments.Insert(new UtopiaAirdropAttachment("Sedan_02_Wheel",1));

		// Set up other default settings
		pkgIntervalMin = 5;
		startDelayMin = 5;
		awayMin = 2;
        minPlayersToStartAirdrop = 1;
		title = "Air Drop";
		droppedMsg = "The Air Drop has reached the ground";
		startMsg = "An Air Drop is on its way to %1";
        rightUpCornerMap = Vector(14900.0,0.0,14000.0); // if we are creating add these positions
        Save();
    }

    void Save()
    {
        //save json file
        JsonFileLoader<UtopiaAirdropSettings>.JsonSaveFile(UTOPIA_AIRDROP_CONFIG_FILE, this);
    }

    static void MakeDirectoryIfNotExist()
    {
        if(!FileExist(UTOPIA_AIRDROP_ROOT_FOLDER)){
            MakeDirectory(UTOPIA_AIRDROP_ROOT_FOLDER);
        }

        if(!FileExist(UTOPIA_AIRDROP_CONFIG_FOLDER)){
            MakeDirectory(UTOPIA_AIRDROP_CONFIG_FOLDER);
        }
    }

    void CheckVersions()
    {
        if(version != UTOPIA_AIRDROP_VERSION)
        {
            version = UTOPIA_AIRDROP_VERSION;
            heliHeightFromGround = 250;
            heliSpeed = 50.0;
            dropCrateContainerLifetimeInSeconds = 1800;
            leftBottomCornerMap = Vector(0.0,0.0,0.0);
            rightUpCornerMap = Vector(14900.0,0.0,14000.0);
            Save();
        }
    }

    static UtopiaAirdropSettings Load()
    {
        UtopiaAirdropSettings settings = new UtopiaAirdropSettings();

        MakeDirectoryIfNotExist();

        if(FileExist(UTOPIA_AIRDROP_CONFIG_FILE))
        {
            JsonFileLoader<UtopiaAirdropSettings>.JsonLoadFile(UTOPIA_AIRDROP_CONFIG_FILE, settings);
            settings.CheckVersions();
            return settings;
        }

        settings.DefaultSettings();
        return settings;
    }
}