class AIR_ActionCustomOpen: ActionInteractBase
{
	void AIR_ActionCustomOpen()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.OpenDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "#open";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;

		if(!IsInReach(player, target, UAMaxDistances.DEFAULT)) return false;

		string leverSelection = target.GetObject().GetActionComponentName(target.GetComponentIndex());
		if(leverSelection && leverSelection == "lever")
			return false;
		
		Utopia_Airdrop_Openable building = Utopia_Airdrop_Openable.Cast(target.GetObject());
		if(building)			
			return !building.IsOpen() && !building.HasNetting();		
		return false;
	}
	
	override void OnStartServer( ActionData action_data )
	{
		Utopia_Airdrop_Openable building = Utopia_Airdrop_Openable.Cast(action_data.m_Target.GetObject());
		if(building)		
		{	
			building.Open();
			return;
		}
	}
};