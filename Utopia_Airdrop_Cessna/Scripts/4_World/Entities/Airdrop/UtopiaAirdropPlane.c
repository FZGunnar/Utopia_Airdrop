class Utopia_Cessna extends UtopiaAirdropPlane
{
	protected void StartPlaneSound()
	{
		if (GetGame().IsClient())
			PlaySoundLoop("utopiaHeliSound", 1000);
	}
};