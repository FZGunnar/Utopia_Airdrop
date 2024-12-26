class CfgPatches
{
	class Utopia_Airdrop
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class Utopia_Static_V22_Osprey: HouseNoDestruct
	{
		scope = 1;
		displayName = "V22 Osprey";
		forceFarBubble = "true";
		model = "Utopia_Airdrop\Models\Static\V22_Osprey.p3d";
		hiddenSelectionsTextures[] =
		{
			
		};
	};
};