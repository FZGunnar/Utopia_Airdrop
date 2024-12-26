//this class contains all usefull methods that can be required for a project purpose.
class UtopiaAirdropHelper {

    static ItemBase SetQuantity(ItemBase item, int quantity)
	{
		Magazine mag = Magazine.Cast(item);
		if (mag)
			mag.ServerSetAmmoCount(quantity);
		else
			item.SetQuantity(quantity);

		return item;
	}

    /**
    * @brief Spawns entities within a specified radius around a given position.
    *
    * This method spawns a specified number of entities from the provided list within a circular area defined by the center position and the radius. It randomly selects entities from the list, generates random positions using the `GetRandomPosition()` method, and creates the objects in the game world using the `CreateObject()` function. Each spawned entity's name and position are logged using the `UtopiaLogger().LogInfo()` function.
    * 
    * @param entities The list of entities to spawn.
    * @param entityToSpawnCount The number of entities to spawn.
    * @param position The center position around which the entities will be spawned.
    * @param radius The radius of the circular area within which the entities will be spawned.
    */
    void SpawnEntitiesInRadius(TStringArray entities, int entityToSpawnCount, vector position, int radius)
    {
        if(entityToSpawnCount > entities.Count()){
            UtopiaLogger().LogError("Could not create entities not enough element in the list!");
            return;
        }

        for(int i = entityToSpawnCount - 1; i >= 0; i--){
            int rndIndex = entities.GetRandomIndex(); 

            vector newPosition = GetRandomPosition(position, radius);
            UtopiaLogger().LogInfo("Entity " + entities[rndIndex] + "spawned at: " + newPosition.ToString());
            
            Object obj = GetGame().CreateObject(entities[rndIndex], newPosition, false, true, true);
            entities.RemoveOrdered(rndIndex);
        }
    }

    /**
    * @brief Generates a random position within a given radius around a specified position.
    *
    * This method generates a random position within a circular area defined by the center position and the radius. It uses a randomly generated angle and distance to calculate the x and z coordinates of the position. The y coordinate is obtained by calling the `GetGame().SurfaceY()` function with the calculated x and z coordinates.
    * 
    * @param position The center position around which the random position will be generated.
    * @param radius The radius of the circular area within which the random position will be generated.
    * 
    * @return The randomly generated position within the specified radius of the center position.
    */
    vector GetRandomPosition(vector position, int radius)
    {
        float angle = Math.RandomFloatInclusive(0, 2 * 3.14);
        float distance = Math.RandomFloatInclusive(0, radius);

        float x = position[0] + distance*Math.Cos(angle);
        float z = position[1] + distance*Math.Sin(angle);

        return Vector(x, GetGame().SurfaceY(x,z), z);
    }

    static UtopiaAirdropLootPool GetPoolFromName(string poolName)
	{
        UtopiaAirdropSettings templateSettings = UtopiaAirdropSettings.Load();
        if(!templateSettings)
            return null;

		foreach(UtopiaAirdropLootPool pool: templateSettings.lootPools)
		{
            if(pool.lootPoolName == poolName)
                return pool;
		}

		return null;
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

    static void GenerateReward(UtopiaFallingContainer container, vector position, vector orientation)
    {
        UtopiaGroundContainer rewardContainer = UtopiaGroundContainer.Cast(GetGame().CreateObject(container.GetContainerClassName(), position));
        if(!rewardContainer)
        {
            UtopiaLogger().LogError("[REWARD] " + container.GetContainerClassName() +" couldn't be created! Check syntax!");
            return;
        }

        rewardContainer.SetOrientation(Vector(0,0,0));
        rewardContainer.SetMarkerId(container.markerId);
        
        UtopiaLogger().LogInfo("[REWARD] " + container.GetContainerClassName() +" has been created!");

        string poolName = container.airdropContainer.PickLootPool();
        UtopiaAirdropLootPool pool = GetPoolFromName(poolName);
            if(!pool)
                return;

        if(container.airdropContainer.isCarDrop){
            GenerateCar(rewardContainer, pool);
            return;
        }
        
        GenerateRewardContainer(rewardContainer, pool);

        Utopia_Airdrop_Openable openableItem;
        if(Class.CastTo(openableItem, rewardContainer)){
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CloseContainer, 500, false, openableItem);
        }
    }

    static void CloseContainer(Utopia_Airdrop_Openable container)
    {
        container.Close();
    }

    static void GenerateCar(EntityAI carCage, UtopiaAirdropLootPool pool)
    {
        Utopia_Airdrop_Cage cage = Utopia_Airdrop_Cage.Cast(carCage);
        if(!cage)
            return;

        if(pool.items.Count() < 1){
            return;
        }
        
        vector position = cage.ModelToWorld( cage.GetMemoryPointPos("spawn_pos ") );

        UtopiaAirdropItem airdropItem = pool.items[0];
        CarScript vehicle = CarScript.Cast(GetGame().CreateObject(airdropItem.name, position, false ));
		vehicle.SetPosition( position);
        vehicle.SetOrientation( Vector(0, 0, 0) );//skip

      	vehicle.Fill(CarFluid.OIL, vehicle.GetFluidCapacity(CarFluid.OIL));
		vehicle.Fill(CarFluid.COOLANT, vehicle.GetFluidCapacity(CarFluid.COOLANT));
		vehicle.Fill(CarFluid.BRAKE, vehicle.GetFluidCapacity(CarFluid.BRAKE));
        vehicle.Fill(CarFluid.FUEL, vehicle.GetFluidCapacity(CarFluid.FUEL));

      	foreach(UtopiaAirdropAttachment attachment: airdropItem.attachments)
        {
            EntityAI attach = vehicle.GetInventory().CreateAttachment(attachment.attachName);
            if(!attach)
            {
                attach = vehicle.GetInventory().CreateInInventory(attachment.attachName);
            }

            if(!attach)
            {
                UtopiaLogger().LogError("[REWARD] " + attachment.attachName +" couldn't be created! Check syntax! continue..."); 
                continue;
            }

            if(attachment.quantity != -1)
                attach = SetQuantity(attach, attachment.quantity);
        }

      	GetGame().RemoteObjectTreeDelete(vehicle);
	    GetGame().RemoteObjectTreeCreate(vehicle);
    }

    static void GenerateRewardContainer(EntityAI rewardContainer, UtopiaAirdropLootPool pool)
    {
        vector position = rewardContainer.GetPosition();
        vector orientation = rewardContainer.GetOrientation();
        int max = pool.maxItems;
        while(max > 0 && pool.items.Count() != 0)
        {
                int idx = pool.items.GetRandomIndex();
                UtopiaAirdropItem airdropItem = pool.items[idx];
                ItemBase item = ItemBase.Cast(GetGame().CreateObject(airdropItem.name, position));
                max--;

                if(!item){
                    UtopiaLogger().LogError("[REWARD] " + airdropItem.name +" couldn't be created! Check syntax! continue...");
                    continue;
                }
                
                if(airdropItem.quantity != -1)
                    item = SetQuantity(item, airdropItem.quantity);

                Weapon_Base wpn = Weapon_Base.Cast(item);
                foreach(UtopiaAirdropAttachment attachment: pool.items[idx].attachments)
                {
                    item.SetPosition(position);
                    EntityAI attach = EntityAI.Cast(GetGame().CreateObject(attachment.attachName , position ));

                    UtopiaLogger().LogInfo("attachment:"+attachment.attachName);

                    if(wpn && attach && attach.IsInherited(Magazine) && !attach.IsInherited(Ammunition_Base))
                    {
                        if(wpn.SpawnAttachedMagazine(attachment.attachName)){
                            UtopiaLogger().LogInfo("Mag has been attached successfully on weapon");
                        }
                        else{
                            UtopiaLogger().LogInfo("Mag was not able to be created on gun");
                        }
                        GetGame().ObjectDelete(attach);
                    }
                    else if(wpn && attach)
                    {
                        wpn.GetInventory().CreateAttachment(attachment.attachName);
                        UtopiaLogger().LogInfo("attachment has been attached successfully on weapon");
                        GetGame().ObjectDelete(attach);
                    }
                    else if(attach)
                    {
                        UtopiaLogger().LogInfo("attachment was not compatible with the weapon and was not created");
                        auto item2 = item.GetInventory().AddEntityToInventory(attach);
                        if (!item2) // we just put it in the box
                            rewardContainer.GetInventory().AddEntityToInventory(attach);
                    }
                }

                rewardContainer.GetInventory().AddEntityToInventory(item);
                pool.items.RemoveOrdered(idx);
        }

        rewardContainer.SetOrientation(orientation);

        GetGame().RemoteObjectTreeDelete(rewardContainer);
	    GetGame().RemoteObjectTreeCreate(rewardContainer);
    }
}