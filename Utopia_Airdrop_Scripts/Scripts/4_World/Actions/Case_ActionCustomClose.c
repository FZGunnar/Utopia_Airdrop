class Case_ActionCustomClose: ActionInteractBase
{
	void Case_ActionCustomClose()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_HUDCursorIcon = CursorIcons.CloseDoors;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "#close";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;

		if(!IsInReach(player, target, UAMaxDistances.DEFAULT)) return false;

		string leverSelection = target.GetObject().GetActionComponentName(target.GetComponentIndex());
		if(leverSelection && leverSelection == "lever")
			return false;
		
		Utopia_Flare_Case building = Utopia_Flare_Case.Cast(target.GetObject());
		if(building)			
			return building.IsOpen();
			
		return false;
	}

	override void OnStartServer( ActionData action_data )
	{
		Utopia_Flare_Case building = Utopia_Flare_Case.Cast(action_data.m_Target.GetObject());
		if(building)		
		{	
			building.Close();
			return;
		}
	}
};