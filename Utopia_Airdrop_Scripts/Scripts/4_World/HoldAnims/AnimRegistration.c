modded class ModItemRegisterCallbacks
{
    override void RegisterPistol(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterPistol( pType, pBehavior); 
        pType.AddItemInHandsProfileIK("Airdrop_Flaregun_Base", "DZ/anims/workspaces/player/player_main/weapons/player_main_flaregun.asi", pBehavior, "DZ/anims/anm/player/ik/weapons/flaregun.anm", "DZ/anims/anm/player/reloads/Flaregun/w_Flaregun_states.anm");		
    }
};