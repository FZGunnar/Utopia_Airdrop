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
	class Utopia_S64_Skycrane: HouseNoDestruct
	{
		scope = 1;
		displayName = "S64 Skycrane";
		forceFarBubble = "true";
		model = "Utopia_Airdrop\Models\Helicopters\S64_Skycrane\S64_Skycrane.p3d";
		hiddenSelections[] = 
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[] =
		{
			"Utopia_Airdrop\Models\Helicopters\S64_Skycrane\Textures\Body_co.paa",
			"Utopia_Airdrop\Models\Helicopters\S64_Skycrane\Textures\Parts_co.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"Utopia_Airdrop\Models\Helicopters\S64_Skycrane\Textures\Body.rvmat",
			"Utopia_Airdrop\Models\Helicopters\S64_Skycrane\Textures\Parts.rvmat"
		};
	};
	class Utopia_AH64D_Apache: HouseNoDestruct
	{
		scope = 1;
		displayName = "AH64D Apache";
		forceFarBubble = "true";
		model = "Utopia_Airdrop\Models\Helicopters\AH64D_Apache\AH64D_Apache.p3d";
		hiddenSelectionsTextures[] =
		{
			
		};
	};
	class Utopia_V22_Osprey: HouseNoDestruct
	{
		scope = 1;
		displayName = "V22 Osprey";
		forceFarBubble = "true";
		model = "Utopia_Airdrop\Models\Helicopters\V22_Osprey\V22_Osprey.p3d";
		hiddenSelectionsTextures[] =
		{
			
		};
	};
};