class CfgPatches
{
	class Custom_Proxies
	{
		units[]=
		{
			"Drill_Rig_Built"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[] = 
		{
			"DZ_Data"
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class Grenade_Base: Inventory_Base
	{
		absorbency = 0.5;
		itemSize[] = {1,2};
		inventorySlot[] += {"VestGrenadeA","VestGrenadeB","VestGrenadeC","VestGrenadeD","Grenade1","Grenade2","Grenade3","Grenade4","Grenade5","Grenade6"};
	};
	class AmmoBox: Container_Base
	{
		inventorySlot[] += {"AmmoBox1","AmmoBox2","AmmoBox3","AmmoBox4","AmmoBox5","AmmoBox6"};
	};
	class BandageDressing: Container_Base
	{
		inventorySlot[] += {"Bandage_Dressing1","Bandage_Dressing2","Bandage_Dressing3"};
	};
	class Firstaidkit: Container_Base
	{
		inventorySlot[] += {"Firstaidkit1","Firstaidkit2","Firstaidkit3","Firstaidkit4"};
	};
	class NailBox: Container_Base
	{
		inventorySlot[] += {"NailBox1","NailBox2","NailBox3"};
	};
};
class CfgSlots {
	class Slot_CrateNetting 
	{
		name = "CrateNetting";
		displayName = "CrateNetting";
		ghostIcon = "set:dayz_inventory image:cat_common_cargo";
	};
	class Slot_Drill_Rig_Built 
	{
		name = "Drill_Rig_Built";
		displayName = "Drill_Rig_Built";
		ghostIcon = "set:dayz_inventory image:cat_common_cargo";
	};
	class Slot_Shoulder1
	{
		name = "Shoulder1";
		displayName = "Shoulder1";
		ghostIcon = "shoulderleft";
	};
	class Slot_Shoulder2
	{
		name = "Shoulder2";
		displayName = "Shoulder2";
		ghostIcon = "shoulderleft";
	};
	class Slot_Shoulder3
	{
		name = "Shoulder3";
		displayName = "Shoulder3";
		ghostIcon = "shoulderleft";
	};
	class Slot_Shoulder4
	{
		name = "Shoulder4";
		displayName = "Shoulder4";
		ghostIcon = "shoulderleft";
	};
	class Slot_Shoulder5
	{
		name = "Shoulder5";
		displayName = "Shoulder5";
		ghostIcon = "shoulderleft";
	};
	class Slot_Shoulder6
	{
		name = "Shoulder6";
		displayName = "Shoulder6";
		ghostIcon = "shoulderleft";
	};
	class Slot_Shoulder7
	{
		name = "Shoulder7";
		displayName = "Shoulder7";
		ghostIcon = "shoulderleft";
	};
	class Slot_Pistol1
	{
		name = "Pistol1";
		displayName = "Pistol1";
		ghostIcon = "pistol";
	};
	class Slot_Pistol2
	{
		name = "Pistol2";
		displayName = "Pistol2";
		ghostIcon = "pistol";
	};
	class Slot_Pistol3
	{
		name = "Pistol3";
		displayName = "Pistol3";
		ghostIcon = "pistol";
	};
	class Slot_Pistol4
	{
		name = "Pistol4";
		displayName = "Pistol4";
		ghostIcon = "pistol";
	};
	class Slot_Pistol5
	{
		name = "Pistol5";
		displayName = "Pistol5";
		ghostIcon = "pistol";
	};
	class Slot_Pistol6
	{
		name = "Pistol6";
		displayName = "Pistol6";
		ghostIcon = "pistol";
	};
	class Slot_Grenade1
	{
		name = "Grenade1";
		displayName = "Grenade1";
		ghostIcon = "grenade";
	};
	class Slot_Grenade2
	{
		name = "Grenade2";
		displayName = "Grenade2";
		ghostIcon = "grenade";
	};
	class Slot_Grenade3
	{
		name = "Grenade3";
		displayName = "Grenade3";
		ghostIcon = "grenade";
	};
	class Slot_AmmoBox1
	{
		name = "AmmoBox1";
		displayName = "AmmoBox1";
		ghostIcon = "AmmoBox";
	};
	class Slot_AmmoBox2
	{
		name = "AmmoBox2";
		displayName = "AmmoBox2";
		ghostIcon = "AmmoBox";
	};
	class Slot_AmmoBox3
	{
		name = "AmmoBox3";
		displayName = "AmmoBox3";
		ghostIcon = "AmmoBox";
	};
	class Slot_AmmoBox4
	{
		name = "AmmoBox4";
		displayName = "AmmoBox4";
		ghostIcon = "AmmoBox";
	};
	class Slot_AmmoBox5
	{
		name = "AmmoBox5";
		displayName = "AmmoBox5";
		ghostIcon = "AmmoBox";
	};
	class Slot_NailBox1
	{
		name = "NailBox1";
		displayName = "NailBox1";
		ghostIcon = "set:dayz_inventory image:nails";
	};
	class Slot_NailBox2
	{
		name = "NailBox2";
		displayName = "NailBox2";
		ghostIcon = "set:dayz_inventory image:nails";
	};
	class Slot_NailBox3
	{
		name = "NailBox3";
		displayName = "NailBox3";
		ghostIcon = "set:dayz_inventory image:nails";
	};
	class Slot_NailBox4
	{
		name = "NailBox4";
		displayName = "NailBox4";
		ghostIcon = "set:dayz_inventory image:nails";
	};
	class Slot_Bandage_Dressing1
	{
		name = "Bandage_Dressing1";
		displayName = "Bandage_Dressing1";
		ghostIcon = "set:dayz_inventory image:medicalbandage";
	};
	class Slot_Bandage_Dressing2
	{
		name = "Bandage_Dressing2";
		displayName = "Bandage_Dressing2";
		ghostIcon = "set:dayz_inventory image:medicalbandage";
	};
	class Slot_Bandage_Dressing3
	{
		name = "Bandage_Dressing3";
		displayName = "Bandage_Dressing3";
		ghostIcon = "set:dayz_inventory image:medicalbandage";
	};
	class Slot_firstaidkit1
	{
		name = "firstaidkit1";
		displayName = "firstaidkit1";
		ghostIcon = "set:dayz_inventory image:firstaidkit";
	};
	class Slot_firstaidkit2
	{
		name = "firstaidkit2";
		displayName = "firstaidkit2";
		ghostIcon = "set:dayz_inventory image:firstaidkit";
	};
	class Slot_firstaidkit3
	{
		name = "firstaidkit3";
		displayName = "firstaidkit3";
		ghostIcon = "set:dayz_inventory image:firstaidkit";
	};
	class Slot_firstaidkit4
	{
		name = "firstaidkit4";
		displayName = "firstaidkit4";
		ghostIcon = "set:dayz_inventory image:firstaidkit";
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyCrateNetting: ProxyAttachment
	{
		inventorySlot[] = {"CrateNetting"};
		model = "Utopia_Airdrop\Models\Container\Proxies\CrateNetting.p3d";
	};
	class ProxyDrill_Rig_Built: ProxyAttachment
	{
		inventorySlot[] = {"Drill_Rig_Built"};
		model = "Utopia_Airdrop\Models\Container\Proxies\Drill_Rig_Built.p3d";
	};
	class ProxyShoulder1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Shoulder1";
		model = "Utopia_Airdrop\Models\Container\Proxies\Shoulder1.p3d";
	};
	class ProxyShoulder2: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Shoulder2";
		model = "Utopia_Airdrop\Models\Container\Proxies\Shoulder2.p3d";
	};
	class ProxyShoulder3: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Shoulder3";
		model = "Utopia_Airdrop\Models\Container\Proxies\Shoulder3.p3d";
	};
	class ProxyShoulder4: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Shoulder4";
		model = "Utopia_Airdrop\Models\Container\Proxies\Shoulder4.p3d";
	};
	class ProxyShoulder5: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Shoulder5";
		model = "Utopia_Airdrop\Models\Container\Proxies\Shoulder5.p3d";
	};
	class ProxyShoulder6: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Shoulder6";
		model = "Utopia_Airdrop\Models\Container\Proxies\Shoulder6.p3d";
	};
	class ProxyShoulder7: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Shoulder7";
		model = "Utopia_Airdrop\Models\Container\Proxies\Shoulder7.p3d";
	};
	class ProxyPistol1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Pistol1";
		model = "Utopia_Airdrop\Models\Container\Proxies\Pistol1.p3d";
	};
	class ProxyPistol2: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Pistol2";
		model = "Utopia_Airdrop\Models\Container\Proxies\Pistol2.p3d";
	};
	class ProxyPistol3: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Pistol3";
		model = "Utopia_Airdrop\Models\Container\Proxies\Pistol3.p3d";
	};
	class ProxyPistol4: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Pistol4";
		model = "Utopia_Airdrop\Models\Container\Proxies\Pistol4.p3d";
	};
	class ProxyPistol5: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Pistol5";
		model = "Utopia_Airdrop\Models\Container\Proxies\Pistol5.p3d";
	};
	class ProxyPistol6: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Pistol6";
		model = "Utopia_Airdrop\Models\Container\Proxies\Pistol6.p3d";
	};
	class ProxyGrenade1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Grenade1";
		model = "Utopia_Airdrop\Models\Container\Proxies\Grenade1.p3d";
	};
	class ProxyGrenade2: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Grenade2";
		model = "Utopia_Airdrop\Models\Container\Proxies\Grenade2.p3d";
	};
	class ProxyGrenade3: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Grenade3";
		model = "Utopia_Airdrop\Models\Container\Proxies\Grenade3.p3d";
	};
	class ProxyAmmoBox1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "AmmoBox1";
		model = "Utopia_Airdrop\Models\Container\Proxies\AmmoBox1.p3d";
	};
	class ProxyAmmoBox2: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "AmmoBox2";
		model = "Utopia_Airdrop\Models\Container\Proxies\AmmoBox2.p3d";
	};
	class ProxyAmmoBox3: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "AmmoBox3";
		model = "Utopia_Airdrop\Models\Container\Proxies\AmmoBox3.p3d";
	};
	class ProxyAmmoBox4: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "AmmoBox4";
		model = "Utopia_Airdrop\Models\Container\Proxies\AmmoBox4.p3d";
	};
	class ProxyAmmoBox5: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "AmmoBox5";
		model = "Utopia_Airdrop\Models\Container\Proxies\AmmoBox5.p3d";
	};
	class ProxyNailBox1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "NailBox1";
		model = "Utopia_Airdrop\Models\Container\Proxies\NailBox1.p3d";
	};
	class ProxyNailBox2: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "NailBox2";
		model = "Utopia_Airdrop\Models\Container\Proxies\NailBox2.p3d";
	};
	class ProxyNailBox3: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "NailBox3";
		model = "Utopia_Airdrop\Models\Container\Proxies\NailBox3.p3d";
	};
	class ProxyNailBox4: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "NailBox4";
		model = "Utopia_Airdrop\Models\Container\Proxies\NailBox4.p3d";
	};
	class ProxyBandage_Dressing1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Bandage_Dressing1";
		model = "Utopia_Airdrop\Models\Container\Proxies\Bandage_Dressing1.p3d";
	};
	class ProxyBandage_Dressing2: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Bandage_Dressing2";
		model = "Utopia_Airdrop\Models\Container\Proxies\Bandage_Dressing2.p3d";
	};
	class ProxyBandage_Dressing3: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Bandage_Dressing3";
		model = "Utopia_Airdrop\Models\Container\Proxies\Bandage_Dressing3.p3d";
	};
	class ProxyFirstaidkit1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Firstaidkit1";
		model = "Utopia_Airdrop\Models\Container\Proxies\Firstaidkit1.p3d";
	};
	class ProxyFirstaidkit2: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Firstaidkit2";
		model = "Utopia_Airdrop\Models\Container\Proxies\Firstaidkit2.p3d";
	};
	class ProxyFirstaidkit3: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Firstaidkit3";
		model = "Utopia_Airdrop\Models\Container\Proxies\Firstaidkit3.p3d";
	};
	class ProxyFirstaidkit4: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Firstaidkit4";
		model = "Utopia_Airdrop\Models\Container\Proxies\Firstaidkit4.p3d";
	};
	class ProxyMetalPlate1: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Material_MetalSheets";
		model = "Utopia_Airdrop\Models\Container\Proxies\MetalPlate1.p3d";
	};
};