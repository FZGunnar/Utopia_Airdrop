
class UtopiaFallingContainer extends House
{
	protected Particle airdropParticleAir;
    protected ref Timer fallTimer;
    protected bool landed = false;

	ref UtopiaAirdropContainer airdropContainer;
	ref UtopiaAirdropLocation airdropLocation;

	int markerId;

    void UtopiaFallingContainer() {
        InitContainer();
    }
    
    void ~UtopiaFallingContainer() {
        CleanupResources();
    }

	void SetupContainer(UtopiaAirdropContainer _airdropContainer, int _markerId, UtopiaAirdropLocation _airdropLocation) 
    {
        this.airdropContainer = _airdropContainer;
        this.markerId = _markerId;
        this.airdropLocation = _airdropLocation; // Store the reference to airdropLocation

        UtopiaAirdropModule airdropModule = GetUtopiaAirdropModule();
        if (airdropModule && airdropContainer && airdropLocation) // Check if airdropLocation is set
        {
            // Pass the airdrop location's creatures to spawn
            airdropModule.CreateEntitiesAroundContainer(GetPosition(), airdropLocation.creaturesToSpawn);
        }
    }

    // Initial setup for the container
    protected void InitContainer() {
        UtopiaLogger().LogDebug("[AIRDROP] Container drop started");
        
        InitializeParticles();
        InitializeFall();

        if (GetGame().IsServer()) {
            ScheduleDeletion();
        }
    }

    // Cleans up particles and timers
    protected void CleanupResources() {
        if (airdropParticleAir) {
            airdropParticleAir.Stop();
        }
        
        if (fallTimer) {
            fallTimer.Stop();
        }
    }

    // Handles creation of particles
    protected void InitializeParticles() {
        if (GetGame().IsClient() || !GetGame().IsMultiplayer()) {
            airdropParticleAir = Particle.PlayOnObject(ParticleList.AIRDROP_PARTICLE_AIR, this, GetMemoryPointPos("light"));
        }
    }

    // Sets up the fall timer if on server
    protected void InitializeFall() {
        if (GetGame().IsServer()) {
            fallTimer = new Timer();
            fallTimer.Run(0.01, this, "AirdropContainerFall", null, true);
        }
    }

    // Schedules deletion of the object after some time
    protected void ScheduleDeletion() {
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, 3600000, false, this);  
    }

    // Called periodically to simulate falling
    void AirdropContainerFall() {
        if (landed) {
            return;
        }

        if (GetGame().IsClient() || !GetGame().IsMultiplayer()) {
            HandleClientFall();
        }

        if (GetGame().IsServer()) {
            HandleServerFall();
        }
    }

    // Client-side handling of falling
    protected void HandleClientFall() {
        if (IsGround(0.5) && airdropParticleAir) {
            airdropParticleAir.Stop();
        }
    }

    // Server-side handling of falling
    protected void HandleServerFall() {
        if (!IsGround(0.5)) {
            EOnFall();
        } else {
            EOnLand();
        }
    }

	void EOnFall()
	{
		if (GetVelocity(this).Length() >= 0) 
		{
			CreateDynamicPhysics(PhxInteractionLayers.DYNAMICITEM);
			EnableDynamicCCD(true);

			SetOrientation(Vector(GetOrientation()[0], 0, 0));
			SetVelocity(this, Vector(0, -2, 0));
		}
	}

    // Handle landing logic
    void EOnLand() {
        if (landed) {
            return;
        }
        
        landed = true;
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DifferedEOnLand, 500, false);
    }

	void DifferedEOnLand()
    {
        AirdropContainerUnstuck();
        GenerateReward();
    }


	void GenerateReward()
    {
        UtopiaAirdropModule airdropModule = UtopiaAirdropModule.Cast(CF_ModuleCoreManager.Get(UtopiaAirdropModule));
        if(airdropModule && airdropContainer)
        {
            airdropModule.SendNotification(airdropModule.settings.droppedMsg);
            UtopiaAirdropHelper.GenerateReward(this, GetPosition(), GetOrientation());
        }
        GetGame().ObjectDelete(this);
    }

    void AirdropContainerUnstuck()
    {
        UtopiaLogger().LogDebug("[AIRDROP] AirdropContainerUnstuck");
        
        if (fallTimer)
            fallTimer.Stop();
        
        SetVelocity(this, Vector(0, 0, 0)); // Stop movement
        dBodySetAngularVelocity(this, Vector(0, 0, 0)); // Stop rotation
        dBodyActive(this, ActiveState.INACTIVE);
        dBodyDynamic(this, false);
        
        SetDirection(GetDirection());
        SetOrientation(Vector(GetOrientation()[0], 0, 0));

        // Ensure the container is placed on the surface
        PlaceOnSurface();
        SetPosition(Vector(GetPosition()[0], GetGame().SurfaceY(GetPosition()[0], GetPosition()[2]), GetPosition()[2]));
    }


	bool IsGround(float height)
	{
		vector start = this.GetPosition();
		vector end = this.GetPosition() - Vector(0, height, 0);
		
		vector hit;
		vector hitPos;
		
		int hitIndex;

		return DayZPhysics.RaycastRV(start, end, hitPos, hit, hitIndex, NULL, NULL, this);
	}

	bool IsObject()
	{
		set<Object> objects = new set<Object>;

		objects.Clear();

		vector start = this.GetPosition();
		vector end = this.GetPosition() - Vector(0, 5, 0);
		
		vector hit;
		vector hitPos;
		
		int hitIndex;

		DayZPhysics.RaycastRV(start, end, hitPos, hit, hitIndex, objects, NULL, this);

		return objects.Count() != 0;
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


	string GetContainerClassName()
	{
		return "Utopia_Airdrop_Crate";
	}
}

class Utopia_Crate_Parachute extends UtopiaFallingContainer
{
	override string GetContainerClassName()
	{
		return "Utopia_Airdrop_Crate";
	}
}

class Utopia_Container_Parachute extends UtopiaFallingContainer
{
	override string GetContainerClassName()
	{
		return "Utopia_Airdrop_Container";
	}
}

class Utopia_Car_Parachute extends UtopiaFallingContainer
{
	override string GetContainerClassName()
	{
		return "Utopia_Airdrop_Cage";
	}
}