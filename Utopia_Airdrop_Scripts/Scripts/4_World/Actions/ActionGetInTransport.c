modded class ActionGetInTransport: ActionBase
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (player.GetItemInHands() && player.GetItemInHands().IsKindOf("UtopiaAirdropFlare"))
			return false;

		return super.ActionCondition(player, target, item);
	}
};
