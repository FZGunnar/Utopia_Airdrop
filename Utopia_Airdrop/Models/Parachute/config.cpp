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
	class Utopia_Car_Parachute: HouseNoDestruct
	{
		scope = 1;
		displayName = "Car Parachute";
		model = "Utopia_Airdrop\Models\Parachute\Car_Parachute.p3d";
	};
	class Utopia_Container_Parachute: HouseNoDestruct
	{
		scope = 1;
		displayName = "Container Parachute";
		model = "Utopia_Airdrop\Models\Parachute\Container_Parachute.p3d";
	};
	class Utopia_Crate_Parachute: HouseNoDestruct
	{
		scope = 1;
		displayName = "Crate Parachute";
		model = "Utopia_Airdrop\Models\Parachute\Crate_Parachute.p3d";
	};
};