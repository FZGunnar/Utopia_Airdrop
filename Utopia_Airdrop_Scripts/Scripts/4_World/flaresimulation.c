class FlareSimulation_Car_Flare : FlareSimulation
{
	void FlareSimulation_Car_Flare()
	{
		m_ScriptedLight	 = FlareLightCar_Flare;//
		m_ParticleId	 = ParticleList.FLAREPROJ_ACTIVATE_CAR;
	}
}
class FlareSimulation_Container_Flare : FlareSimulation
{
	void FlareSimulation_Container_Flare()
	{
		m_ScriptedLight	 = FlareLightContainer_Flare;//
		m_ParticleId	 = ParticleList.FLAREPROJ_ACTIVATE_CONT;
	}
}
class FlareSimulation_Crate_Flare : FlareSimulation
{
	void FlareSimulation_Crate_Flare()
	{
		m_ScriptedLight	 = FlareLightCrate_Flare;//
		m_ParticleId	 = ParticleList.FLAREPROJ_ACTIVATE_CRATE;
	}
}
