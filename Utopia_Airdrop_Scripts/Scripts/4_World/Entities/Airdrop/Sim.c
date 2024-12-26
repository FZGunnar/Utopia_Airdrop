modded class FlareSimulation_Car_Flare
{
	override void OnActivation(Entity flare)
	{
		super.OnActivation(flare);

		if ( !GetGame().IsServer())
		{
			UtopiaLogger().LogDebug("[AIRDROP] FlareSimulation_Car_Flare - OnActivation");
			GetRPCManager().SendRPC("Utopia_Airdrop", "ClientCallAirdropByFlare", new Param2<vector, string>(flare.GetPosition(), flare.GetType()));//skip
		}
	}
}
modded class FlareSimulation_Container_Flare
{
	override void OnActivation(Entity flare)
	{
		super.OnActivation(flare);

		if ( !GetGame().IsServer())
		{
			UtopiaLogger().LogDebug("[AIRDROP] FlareSimulation_Container_Flare - OnActivation");
			GetRPCManager().SendRPC("Utopia_Airdrop", "ClientCallAirdropByFlare", new Param2<vector, string>(flare.GetPosition(), flare.GetType()));//skip
		}
	}
}
modded class FlareSimulation_Crate_Flare
{
	override void OnActivation(Entity flare)
	{
		super.OnActivation(flare);

		if ( !GetGame().IsServer())
		{
			UtopiaLogger().LogDebug("[AIRDROP] FlareSimulation_Crate_Flare - OnActivation");
			GetRPCManager().SendRPC("Utopia_Airdrop", "ClientCallAirdropByFlare", new Param2<vector, string>(flare.GetPosition(), flare.GetType()));//skip
		}
	}
}
