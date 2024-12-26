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
	class Container_Base;
	class Inventory_Base;
	class AIR_Door_Base;
	class Utopia_Airdrop_Container_Base: AIR_Door_Base
	{
		scope = 0;
		displayName = "Airdrop Container";
		forceFarBubble = "true";
		alignHologramToTerain = 1;
		model = "Utopia_Airdrop\Models\Container\Airdrop_Container.p3d";
		class Cargo
		{
			itemsCargoSize[] = {10,100};
			openable = 1;
			allowOwnedCargoManipulation = 1;
		};
		hiddenSelections[] = 
		{
			"camo"
		};
		attachments[]=
		{
			"Drill_Rig_Built",
			"Shoulder1",
			"Shoulder2",
			"Shoulder3",
			"Pistol1",
			"Pistol2",
			"AmmoBox1",
			"AmmoBox2",
			"AmmoBox3",
			"Grenade1",
			"Grenade2",
			"Grenade3",
			"NailBox1",
			"NailBox2",
			"NailBox3",
			"Material_MetalSheets",
			"Bandage_Dressing1",
			"Bandage_Dressing2",
			"Bandage_Dressing3",
			"Firstaidkit1",
			"Firstaidkit2",
			"Firstaidkit3",
			"Firstaidkit4"
		};
		class GUIInventoryAttachmentsProps
		{
			class Drill_Rig_Built
			{
				name = "Drill Rig";
				description = "";
				attachmentSlots[] =
				{
					"Drill_Rig_Built"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
			class Military
			{
				name = "Military Pallets";
				description = "";
				attachmentSlots[] = 
				{
					"Shoulder1",
					"Shoulder2",
					"Shoulder3",
					"Pistol1",
					"Pistol2",
					"AmmoBox1",
					"AmmoBox2",
					"AmmoBox3",
					"Grenade1",
					"Grenade2",
					"Grenade3"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
			class Building
			{
				name = "Building Pallet";
				description = "";
				attachmentSlots[] = 
				{
					"NailBox1",
					"NailBox2",
					"NailBox3",
					"Material_MetalSheets"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
			class Medical
			{
				name = "Medical Pallet";
				description = "";
				attachmentSlots[] = 
				{
					"Bandage_Dressing1",
					"Bandage_Dressing2",
					"Bandage_Dressing3",
					"Firstaidkit1",
					"Firstaidkit2",
					"Firstaidkit3",
					"Firstaidkit4"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
		};
		class AnimationSources
		{
			class door1
			{
				source="user";
				initPhase=0;
				animPeriod=1.5;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000000;
				};
			};
		};
	};
	class Utopia_Airdrop_Container: Utopia_Airdrop_Container_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = 
		{
			"Utopia_Airdrop\Models\Container\Textures\Container_New_co.paa"
		};
	};
	class Utopia_Crate_Netting: Inventory_Base
	{
		scope = 2;
		model = "Utopia_Airdrop\Models\Crate\Proxies\Netting.p3d";
		inventorySlot[]=
		{
			"CrateNetting"
		};
		hiddenSelections[] = 
		{
			"camo1"
		};
		hiddenSelectionsTextures[] =
		{
			"utopia_airdrop\models\crate\textures\crate_bottom_co.paa"
		};
	};
	class Utopia_Airdrop_Crate_Base: AIR_Door_Base
	{
		scope = 0;
		model = "Utopia_Airdrop\Models\Crate\Airdrop_Crate.p3d";
		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		yawPitchRollLimit[] = {10, 10, 10};
		physLayer = "item_large";
		forceFarBubble = "true";
		hiddenSelections[] = 
		{
			"camo1",
			"camo2",
			"camo3"
		};
		attachments[]=
		{
			"CrateNetting",
			"Shoulder1",
			"Shoulder2",
			"Shoulder3",
			"Shoulder4",
			"Shoulder5",
			"Shoulder6",
			"Shoulder7",
			"Pistol1",
			"Pistol2",
			"Pistol3",
			"Pistol4",
			"Pistol5",
			"Pistol6",
			"AmmoBox1",
			"AmmoBox2",
			"AmmoBox3",
			"AmmoBox4",
			"AmmoBox5",
			"Grenade1",
			"Grenade2",
			"Grenade3",
			"NailBox1",
			"NailBox2",
			"NailBox3",
			"NailBox4",
			"Firstaidkit1",
			"Firstaidkit2",
			"Firstaidkit3",
			"Firstaidkit4"
		};
		class Cargo
		{
			itemsCargoSize[]={10,100};
			openable=1;
			allowOwnedCargoManipulation=1;
		};
		class GUIInventoryAttachmentsProps
		{
			class CrateNetting
			{
				name = "CrateNetting";
				description = "";
				attachmentSlots[] = 
				{
					"CrateNetting"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
			class Assault_Rifles
			{
				name = "Assault_Rifles";
				description = "";
				attachmentSlots[] = 
				{
					"Shoulder1",
					"Shoulder2",
					"Shoulder3",
					"Shoulder4",
					"Shoulder5",
					"Shoulder6",
					"Shoulder7"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
			class Pistols
			{
				name = "Pistols";
				description = "";
				attachmentSlots[] = 
				{
					"Pistol1",
					"Pistol2",
					"Pistol3",
					"Pistol4",
					"Pistol5",
					"Pistol6"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
			class Military
			{
				name = "Military";
				description = "";
				attachmentSlots[] = 
				{
					"AmmoBox1",
					"AmmoBox2",
					"AmmoBox3",
					"AmmoBox4",
					"AmmoBox5",
					"Grenade1",
					"Grenade2",
					"Grenade3"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
			class Building
			{
				name = "Building";
				description = "";
				attachmentSlots[] = 
				{
					"NailBox1",
					"NailBox2",
					"NailBox3",
					"NailBox4"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
			class Medical
			{
				name = "Medical";
				description = "";
				attachmentSlots[] = 
				{
					"Firstaidkit1",
					"Firstaidkit2",
					"Firstaidkit3",
					"Firstaidkit4"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
		};
		class AnimationSources
		{
			class door1
			{
				source="user";
				initPhase=0;
				animPeriod=1.5;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1000000;
				};
			};
		};
	};
	class Utopia_Airdrop_Crate: Utopia_Airdrop_Crate_Base
	{
		scope = 2;
		displayName = "Airdrop Crate";
		hiddenSelectionsTextures[] =
		{
			"utopia_airdrop\models\crate\textures\crate_bottom_co.paa",
			"utopia_airdrop\models\crate\textures\case_co.paa",
			"utopia_airdrop\models\crate\textures\mesh_co.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"utopia_airdrop\models\crate\textures\crate_bottom.rvmat",
			"utopia_airdrop\models\crate\textures\case.rvmat",
			""
		};
	};
	class Utopia_Airdrop_Cage_Base: Container_Base
	{
		scope = 0;
		model = "Utopia_Airdrop\Models\Cage\Airdrop_Cage.p3d";
		slopeTolerance = 0.3;
		alignHologramToTerain = 1;
		yawPitchRollLimit[] = {10, 10, 10};
		physLayer = "item_large";
		forceFarBubble = "true";
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
	};
	class Utopia_Airdrop_Cage: Utopia_Airdrop_Cage_Base
	{
		scope = 2;
		displayName = "Airdrop Car Cage";
		hiddenSelectionsTextures[] =
		{
			"Utopia_Airdrop\Models\Parachute\Textures\Airdrop_Car_co.paa"
		};
	};
	class Utopia_Drill_Rig_Built_Base: Inventory_Base
	{
		scope = 0;
		model = "Utopia_Airdrop\Models\Container\Drill_Rig\Drill_Rig_Built.p3d";
		displayName = "Drill Rig Built";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {4,3};
		rotationFlags = 17;
		inventorySlot[]=
		{
			"Drill_Rig_Built"
		};
		attachments[]=
		{
			"BatteryD"
		};
		class GUIInventoryAttachmentsProps
		{
			class Battery
			{
				name="Battery";
				description="";
				attachmentSlots[]=
				{
					"BatteryD"
				};
				icon="cat_common_cargo";
			};
		};
		class EnergyManager
		{
			hasIcon = 1;
			energyUsagePerSecond = 0.01;
			plugType = 1;
			attachmentAction = 1;
			updateInterval = 40;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[]= {{1,{}},{0.69999999,{}},{0.5,{}},{0.30000001,{}},{0,{}}};
				};
			};
		};
	};
	class Utopia_Drill_Rig_Built: Utopia_Drill_Rig_Built_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"Utopia_Airdrop\Models\Container\Textures\Drill_co.paa"
		};
	};
	class Utopia_Drill_Rig_Base: Inventory_Base
	{
		scope = 0;
		model = "Utopia_Airdrop\Models\Container\Drill_Rig\Drill_Rig.p3d";
		displayName = "Drill Rig";
		descriptionShort = "";
		weight = 500;
		itemSize[] = {4,3};
		rotationFlags = 17;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[]= {{1,{}},{0.69999999,{}},{0.5,{}},{0.30000001,{}},{0,{}}};
				};
			};
		};
	};
	class Utopia_Drill_Rig: Utopia_Drill_Rig_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"Utopia_Airdrop\Models\Container\Textures\Drill_co.paa"
		};
	};
	class Utopia_Drill_Base: Inventory_Base
	{
		scope = 0;
		displayName = "Drill";
		descriptionShort = "Drill";
		model = "Utopia_Airdrop\Models\Container\Drill\Drill.p3d";
		weight = 500;
		itemSize[] = {4,3};
		rotationFlags = 17;
		hiddenSelections[]=
		{
			"camo"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[]= {{1,{}},{0.69999999,{}},{0.5,{}},{0.30000001,{}},{0,{}}};
				};
			};
		};
	};
	class Utopia_Drill: Utopia_Drill_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"Utopia_Airdrop\Models\Container\Textures\Drill_co.paa"
		};
	};
};