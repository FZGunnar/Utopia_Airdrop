class UtopiaAirdropPlane extends House
{
	private int airdropPlaneHeight = 250;
	private float airdropSpeed = 20.0;
	protected bool dropInitiated;
	protected vector dropLocation;
	protected float dropAccuracy;
	protected float angle;
	protected EffectSound sound;

	protected ref UtopiaAirdropLocation airdropLocation;

	void UtopiaAirdropPlane()
	{
		UtopiaLogger().LogDebug("[AIRDROP] UtopiaAirdropPlane");

		SetEventMask( EntityEvent.SIMULATE );
		StartPlaneSound();
	}

	void SetupPlane(UtopiaAirdropLocation tAirdropLocation)
	{
		UtopiaLogger().LogDebug("[AIRDROP] SetupPlane for plane: " + this.GetType());

		// Check settings and parameters before setup
		if (!GetUtopiaAirdropModule() || !GetUtopiaAirdropModule().settings)
		{
			UtopiaLogger().LogError("[AIRDROP] Unable to setup plane due to missing settings.");
			return;
		}

		airdropPlaneHeight = GetUtopiaAirdropModule().settings.heliHeightFromGround;
		airdropSpeed = GetUtopiaAirdropModule().settings.heliSpeed;
		airdropLocation = tAirdropLocation;

		UtopiaLogger().LogDebug("[AIRDROP] SetupPlane: dropPosition: " + airdropLocation.dropPosition);
		dropLocation = airdropLocation.dropPosition;
		UtopiaLogger().LogDebug("[AIRDROP] SetupPlane: dropLocation: " + dropLocation);
		dropAccuracy = airdropLocation.radius;
		UtopiaLogger().LogDebug("[AIRDROP] SetupPlane: dropAccuracy: " + dropAccuracy);

		SetOrientation(Vector(GetOrientation()[0], 0, 0));
		SetDirection(GetDirection());
		angle = CalculateAngleTo(dropLocation);

		UtopiaLogger().LogDebug("[AIRDROP] Plane setup completed for plane type: " + this.GetType());
	}


	void ~UtopiaAirdropPlane()
	{
		if (sound)
			sound.Stop();
	}

	protected void StartPlaneSound()
	{
		if (GetGame().IsClient())
			PlaySoundLoop("utopiaHeliSound", 1000);
	}

	override void EOnSimulate( IEntity owner, float dt )
	{
        if ( GetGame().IsServer() )
        {
            vector velocity = CalculateVelocity(dt);
            MoveWithInterpolation(velocity, dt);
            CheckForDrop();
        }
	}

    protected vector CalculateVelocity(float deltaTime)
    {
		vector velocity = Vector( Math.Cos( angle ), 0, Math.Sin( angle ) );
		velocity[0] = velocity[0] * (airdropSpeed) * deltaTime;
		velocity[2] = velocity[2] * (airdropSpeed) * deltaTime;
        return velocity;
    }

    protected void MoveWithInterpolation(vector velocity, float deltaTime)
	{
		vector transform[4];
		GetTransform(transform);
		transform[3] = transform[3] + velocity;
		
		// Ensure the plane flies at the correct height above the ground
		transform[3][1] = GetGame().SurfaceY(transform[3][0], transform[3][2]) + airdropPlaneHeight;

		MoveInTime(transform, deltaTime);
	}

	protected void CheckForDrop()
	{
		vector position = GetPosition();
		
		// Calculate the distance based on X and Z coordinates only
		float distanceToTargetXZ = Math.Sqrt(Math.Pow(position[0] - dropLocation[0], 2) + Math.Pow(position[2] - dropLocation[2], 2));

		// Check if the plane is within dropAccuracy distance on the X and Z coordinates
		if (!dropInitiated && distanceToTargetXZ <= dropAccuracy)
		{
			// Optional: Add an altitude check if necessary
			if (position[1] >= 150)  // Replace requiredAltitude with your desired height check
			{
				ActivateDrop(position);  // Trigger the drop
				dropInitiated = true;  // Prevent multiple drops
			}
			else
			{
				// If altitude is not high enough, log or handle accordingly
				UtopiaLogger().LogDebug("[AIRDROP] Plane at insufficient altitude: " + position[1].ToString());
			}
		}
	}


	protected void ActivateDrop(vector position)
	{
		UtopiaLogger().LogDebug("[AIRDROP] Activating Drop at position: " + position.ToString());
		CreateAirdropContainerAtCurrentPosition(position);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DeleteSelfAfterDelay, 30000, false);
	}


	protected void CreateAirdropContainerAtCurrentPosition(vector position)
	{
		UtopiaLogger().LogDebug("[AIRDROP] Plane altitude: " + position[1]);
		UtopiaLogger().LogDebug("[AIRDROP] Spawning container at: " + position.ToString());

		UtopiaAirdropContainer airdropContainer = airdropLocation.PickContainer();
		UtopiaFallingContainer container = UtopiaFallingContainer.Cast(GetGame().CreateObject(airdropContainer.containerName, position, false, true, true));
		
		if (container)
		{
			container.SetOrientation(Vector(0, 0, 0));
			// Pass all three parameters: airdropContainer, airdropLocation.markerId, and airdropLocation
			container.SetupContainer(airdropContainer, airdropLocation.markerId, airdropLocation);
			UtopiaLogger().LogDebug("[AIRDROP] Container spawned at: " + container.GetPosition().ToString());
		}
		else
		{
			UtopiaLogger().LogError("[AIRDROP] Failed to create airdrop container.");
		}
	}


	protected void DeleteSelfAfterDelay()
	{
		GetGame().ObjectDelete(this);
	}

	bool EOnBeforeDelete()
	{
		return !IsInsideMapBoundary(GetPosition());
	}

	protected bool IsInsideMapBoundary(vector position)
	{
		const float MIN_X = -10.0;
		const float MAX_X = 15470.0;
		const float MIN_Y = -10.0;
		const float MAX_Y = 15470.0;

		return (position[0] > MIN_X && position[0] < MAX_X && position[2] > MIN_Y && position[2] < MAX_Y);
	}

	protected float CalculateAngleTo(vector targetLocation)
	{
		vector position = GetPosition();
		return Math.Atan2(targetLocation[2] - position[2], targetLocation[0] - position[0]);
	}
};

class Utopia_S64_Skycrane extends UtopiaAirdropPlane{};

class Utopia_AH64D_Apache extends UtopiaAirdropPlane{};

class Utopia_V22_Osprey extends UtopiaAirdropPlane{};

class PlayerAirDropPlane extends UtopiaAirdropPlane{};




