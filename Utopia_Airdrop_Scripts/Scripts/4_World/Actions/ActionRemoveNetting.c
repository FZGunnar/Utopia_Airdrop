class ActionRemoveNettingCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(GetUtopiaAirdropModule().settings.removeNettingTimeInSeconds);
	}
};

class ActionRemoveNetting : ActionContinuousBase
{
    void ActionRemoveNetting()
	{
    	m_CallbackClass = ActionRemoveNettingCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
        m_FullBody = true;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
    }

    override void CreateConditionComponents()
	{
	    m_ConditionTarget = new CCTCursor(UAMaxDistances.SMALL * 0.5);
        m_ConditionItem = new CCINone;
    }

    override string GetText() { return "Remove Netting"; }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
    	if( !target ) return false;

		if(!IsInReach(player, target, UAMaxDistances.DEFAULT)) return false;

		string leverSelection = target.GetObject().GetActionComponentName(target.GetComponentIndex());
		if(leverSelection && leverSelection == "lever")
			return false;
		
		UtopiaGroundContainer building = UtopiaGroundContainer.Cast(target.GetObject());
		if(building)			
			return building.HasNetting();		
		return false;
    }

    override bool ActionConditionContinue(ActionData action_data) { return true; }
	override typename GetInputType() { return ContinuousInteractActionInput; }
	override void OnFinishProgressServer( ActionData action_data )
	{
        Utopia_Airdrop_Crate building = Utopia_Airdrop_Crate.Cast(action_data.m_Target.GetObject());
		if(building)			
			building.RemoveNetting();
	}
}
