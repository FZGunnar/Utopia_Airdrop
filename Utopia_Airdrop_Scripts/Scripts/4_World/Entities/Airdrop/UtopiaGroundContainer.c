class UtopiaGroundContainer extends Container_Base
{
	protected Particle airdropParticleGround;

	protected int markerId;
	bool m_hasNetting = false;

	void UtopiaGroundContainer()
	{
		EOnInit();
		RegisterNetSyncVariableBool("m_hasNetting");

		UtopiaLogger().LogDebug("[AIRDROP] UtopiaGroundContainer");

		SetAllowDamage(false);

		if(GetGame().IsServer())
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DefineLifeTime, 3000, false);	
	}

	void SetMarkerId(int id)
	{
		this.markerId = id;
	}

	void DefineLifeTime()
	{
		UtopiaLogger().LogDebug("[AIRDROP] UtopiaGroundContainer::DefineLifeTime - LifeTime: " + GetUtopiaAirdropModule().settings.dropCrateContainerLifetimeInSeconds);
		if(GetUtopiaAirdropModule() && GetUtopiaAirdropModule().settings.dropCrateContainerLifetimeInSeconds)
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, GetUtopiaAirdropModule().settings.dropCrateContainerLifetimeInSeconds*1000, false, this);	
	}

	void DeleteMarker()
	{
		#ifdef BASICMAP
			UtopiaMarkerManager.RemoveBMMarker(markerId);
		#endif

		#ifdef LBmaster_Groups
			UtopiaMarkerManager.RemoveLBMarker(markerId);
		#endif
	}
	
	void ~UtopiaGroundContainer()
	{
		if(GetGame().IsServer()){
			DeleteMarker();
			LookForVehicleNearbyToDelete();
		}
	
		if (airdropParticleGround)
			airdropParticleGround.Stop();
	}

	void LookForVehicleNearbyToDelete()
	{
		array<Object> objects = new array<Object>;
		array<CargoBase> cargos = new array<CargoBase>;
		GetGame().GetObjectsAtPosition3D(GetPosition(), 1.5, objects, cargos);
		for (int i = objects.Count() - 1; i >= 0; i--)
		{
			CarScript car = CarScript.Cast(objects[i]);
			if(car)
			{
				GetGame().ObjectDelete(car);
				UtopiaLogger().LogDebug("vehicle close to drop as be removed");
				return;
			}
		}
	}

	void EOnInit()
	{
		UtopiaLogger().LogDebug("[AIRDROP] Container: EOnInit");
		
		// Ensure the container is placed on the surface
		vector pos = GetPosition();
		pos[1] = GetGame().SurfaceY(pos[0], pos[2]);
		SetPosition(pos);

		if (GetGame().IsClient() || !GetGame().IsMultiplayer()) 
			airdropParticleGround = Particle.PlayOnObject(ParticleList.AIRDROP_PARTICLE_GROUND, this, GetMemoryPointPos("particule_pos"));
	}


	override bool OnStoreLoad( ParamsReadContext ctx, int version )
    {
      if ( !super.OnStoreLoad( ctx, version ) )
        return false;

	  GetGame().ObjectDelete(this);
      return true;
    }

	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}

	override bool CanPutInCargo ( EntityAI parent )
	{
		return false;
	}

	override bool IsInventoryVisible()
    {
        return true;
    }

	override bool CanUseConstruction()
    {
        return true;
    }

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionRemoveNetting);
	}

	void RemoveNetting()
	{
		if (GetGame().IsServer())
		{
			m_hasNetting = false;
			SetSynchDirty();
		}
	}

	bool HasNetting()
	{
		return m_hasNetting;
	}
}

class Utopia_Airdrop_Openable extends UtopiaGroundContainer
{
	protected bool m_IsOpened;
	private bool m_IsOpenable;
	private bool m_IsOpenedLocal = false;
	
	void Utopia_Airdrop_Openable()
	{
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
		RegisterNetSyncVariableBool("m_IsOpened");

		if(GetGame().IsServer())
			Open();
	}

	void LockInventory()
	{
		if(GetGame().IsServer() && GetInventory()){
			GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);		
			SetSynchDirty();
		}
	}

	void UnlockInventory()
	{
		if(GetGame().IsServer() && GetInventory()){
			GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
			SetSynchDirty();
		}
	}

	override void Open()
	{
		m_IsOpened = true;
		SoundSynchRemote();
		UpdateVisualState();
		UnlockInventory();
		SetSynchDirty();
	}

	override void Close()
	{
		m_IsOpened = false;
		SoundSynchRemote();
		UpdateVisualState();
		LockInventory();
		SetSynchDirty();
	}

	override bool IsOpen()
	{
		return m_IsOpened;
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if ( m_IsOpened != m_IsOpenedLocal )
		{		
			if ( IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
			{
				SoundOpenPlay();
			}
			
			if ( !IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
			{
				SoundClosePlay();
			}	
			m_IsOpenedLocal = m_IsOpened;
		}
		
		UpdateVisualState();
	}
	
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );		
		ctx.Write( m_IsOpened );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		if (!ctx.Read( m_IsOpened ) )
			return false;
		
		if ( m_IsOpened )
			Open();
		else
			Close();
		
		return true;
	}


	void UpdateVisualState()
    {
        if ( IsOpen() )
        {
            SetAnimationPhase("Door1",1);
            SetAnimationPhase("Door2",1);
            SetAnimationPhase("Door3",1);
            SetAnimationPhase("Door4",1);
        }
        else
        {
            SetAnimationPhase("Door1",0);
            SetAnimationPhase("Door2",0);
            SetAnimationPhase("Door3",0);
            SetAnimationPhase("Door4",0);
        }
    }
	
	void SoundOpenPlay()
	{
	}
	
	void SoundClosePlay()
	{
	}

    override bool CanPutInCargo( EntityAI parent )
    {
        return false;
    }
    override bool CanPutIntoHands( EntityAI parent )
    {
        return false;
    }
	override bool CanReceiveItemIntoCargo(EntityAI item)
	{
		return IsOpen();
	}
	
	override bool CanReleaseCargo(EntityAI attachment)
	{
		return IsOpen();
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(AIR_ActionCustomOpen);
        // AddAction(AIR_ActionCustomClose);
	}
};

class Utopia_Airdrop_Container extends Utopia_Airdrop_Openable {};
class Utopia_Airdrop_Crate extends Utopia_Airdrop_Openable
{
	void Utopia_Airdrop_Crate()
	{
		if (GetGame().IsServer())
		{
			m_hasNetting = true; // we have netting
			Open();
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(AddNetting, 5000, false);
		}
	}

	void AddNetting()
	{
		Print("Spawning netting");
		GetInventory().CreateInInventory("Utopia_Crate_Netting");
	}

	override void RemoveNetting()
	{
		super.RemoveNetting();

		int slot_id = InventorySlots.GetSlotIdFromString("CrateNetting");
		EntityAI attachment = GetInventory().FindAttachment(slot_id);
		if (attachment)
		{
			if (attachment && attachment.GetType() == "Utopia_Crate_Netting")
			{
				attachment.Delete();
			}
		}
	}
};

class Utopia_Airdrop_Cage extends UtopiaGroundContainer{};
