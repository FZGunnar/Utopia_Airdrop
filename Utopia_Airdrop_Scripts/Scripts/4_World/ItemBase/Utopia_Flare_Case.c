class Utopia_Flare_Case: ItemBase
{	
	protected ref OpenableBehaviour m_Openable;

	void Utopia_Flare_Case()
	{
		m_Openable = new OpenableBehaviour(false);
		RegisterNetSyncVariableBool("m_Openable.m_IsOpened");
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}
	
	override void EEInit()
	{
		super.EEInit();		
        GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);  
	}

	override void Open()
	{
		m_Openable.Open();
		SoundSynchRemote();
		UpdateVisualState();
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
	}

	override void Close()
	{
		m_Openable.Close();
		SoundSynchRemote();
		UpdateVisualState();
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
	}

	override bool IsOpen()
	{
		return m_Openable.IsOpened();
	}
	
	void UpdateVisualState()
    {
        if ( IsOpen() )
        {
            SetAnimationPhase("door1",1);
			SetAnimationPhase("door2",1);
        }
        else
        {
            SetAnimationPhase("door1",0);
			SetAnimationPhase("door2",0);
        }
		
    }
	
	override bool CanReceiveItemIntoCargo(EntityAI cargo)
	{
		return IsOpen();
	}
	
	override bool CanReleaseCargo(EntityAI attachment)
	{
		return IsOpen();
	}

	override bool CanDisplayAttachmentSlot(string slot_name)
	{		
		return true;
	}

	override void OnVariablesSynchronized()
    {
        super.OnVariablesSynchronized();
                
        if ( IsPlaceSound() )
        {
            PlayPlaceSound();
        }
        else
        {
            if ( IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
            {
                SoundSafeOpenPlay();
            }
            
            if ( !IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
            {
                SoundSafeClosePlay();
            }
        }
        
        UpdateVisualState();
    }
    
    void SoundSafeOpenPlay()
    {
        EffectSound sound =    SEffectManager.PlaySound( "Container_open_SoundSet", GetPosition() );
        sound.SetSoundAutodestroy( true );
    }
    
    void SoundSafeClosePlay()
    {
        EffectSound sound =    SEffectManager.PlaySound( "Container_close_SoundSet", GetPosition() );
        sound.SetSoundAutodestroy( true );
    }
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(Case_ActionCustomOpen);
        // AddAction(Case_ActionCustomClose);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
};