class UtopiaAirdropFlare: Roadflare
{
	protected bool used = false;

	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) )
            return false;
		
        return !used;
	}

	override bool CanPutIntoHands( EntityAI parent )
	{
		if(!super.CanPutIntoHands(parent) )
            return false;

		return !used;
	}

	override void OnStoreSave( ParamsWriteContext ctx )
	 {
		super.OnStoreSave(ctx);
		Param1<bool> data = new Param1<bool>(used);
		ctx.Write(data);
	 }

	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;

		Param1<bool>data = new Param1<bool>(false);
		if (ctx.Read(data))
		{
			used = data.param1;
			Print("used:" + used);
		}
		return true;
	}

	override void OnWorkStart()
	{
		super.OnWorkStart();

		if (used) {
			Print("flare already used");
			return;
		}

		// Mark the flare as used
		used = true;

		if (GetGame().IsServer())
		{
			// Log debug information
			UtopiaLogger().LogDebug("[AIRDROP] AirdropEventHandler - OnWorkStart triggered");

			UtopiaAirdropModule airdropModule = UtopiaAirdropModule.Cast(CF_ModuleCoreManager.Get(UtopiaAirdropModule));
			if (airdropModule && airdropModule.settings && airdropModule.settings.flareAirdropContainers)
			{
				vector pos = Vector(GetPosition()[0], 0, GetPosition()[2]);
				UtopiaAirdropLocation airdropLocation = new UtopiaAirdropLocation("Unknown location", pos, 5, GetType());

				// Log the current position being processed for the airdrop
				UtopiaLogger().LogDebug(string.Format("[AIRDROP] Airdrop will be requested at position: %1", pos.ToString()));

				// only contain the containers for item
				foreach (UtopiaAirdropFlareContainer container : airdropModule.settings.flareAirdropContainers)
				{
					if (container.itemName == GetType())
						airdropLocation.airdropContainers.Insert(UtopiaAirdropContainer.Cast(container));
				}

				if (airdropModule.settings.showMarkerForFlareDrop)
					airdropModule.ShowMarker(airdropLocation);

				airdropModule.SendNotification(string.Format(airdropModule.settings.startMsg, airdropLocation.name));
				airdropModule.RequestAirdropAtLocation(airdropLocation);

				PlayerBase player = PlayerBase.Cast(this.GetHierarchyRootPlayer());
				if (player)
					player.ServerDropEntity(this);
			}
		}
	}

	
}