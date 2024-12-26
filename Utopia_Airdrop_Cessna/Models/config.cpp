class CfgPatches
{
	class Utopia_Airdrop_Cessna
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
	class AIR_Door_Base;
	class Utopia_Cessna: HouseNoDestruct
	{
		scope = 1;
		displayName = "Cessna";
		forceFarBubble = "true";
		model = "Utopia_Airdrop_Cessna\Models\Airplane\Utopia_Cessna.p3d";
		hiddenSelections[] = 
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[] =
		{
			"Utopia_Airdrop_Cessna\Models\Textures\plane_body_1_co.paa",
			"Utopia_Airdrop_Cessna\Models\Textures\plane_body_11_co.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"Utopia_Airdrop_Cessna\Models\Textures\plane_body_1.rvmat",
			"Utopia_Airdrop_Cessna\Models\Textures\plane_body_11.rvmat"
		};
	};
	class Utopia_Military_Flat_Parachute: HouseNoDestruct
	{
		scope = 1;
		displayName = "Military Flat Parachute";
		model = "Utopia_Airdrop_Cessna\Models\Parachute\Military_Flat_Parachute.p3d";
	};
	class Utopia_Military_Medium_Parachute: HouseNoDestruct
	{
		scope = 1;
		displayName = "Military Medium Parachute";
		model = "Utopia_Airdrop_Cessna\Models\Parachute\Military_Medium_Parachute.p3d";
	};
	class Utopia_Military_Airdrop_Flat_Base: AIR_Door_Base
	{
		scope= 0;
		displayName="Flat Airdrop Military Storage";
		descriptionShort="Flat Airdrop Military Storage";
		model="Utopia_Airdrop_Cessna\Models\Military_Crates\Flat\Military_Flat.p3d";
		hiddenSelections[]=
		{
			"camo",
			"parts"
		};
		attachments[]=
		{
			"Shoulder1",
			"Shoulder2",
			"Shoulder3",
			"Shoulder4"
		};
		class Cargo
		{
			itemsCargoSize[]={10,7};
			openable=1;
			allowOwnedCargoManipulation=1;
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
		class GUIInventoryAttachmentsProps
		{
			class Weapons
			{
				name = "Weapons";
				description = "";
				attachmentSlots[] = 
				{
					"Shoulder1",
					"Shoulder2",
					"Shoulder3",
					"Shoulder4"
				};
				icon = "set:dayz_inventory image:shoulderleft";
			};
		};
	};
	class Utopia_Military_Airdrop_Flat: Utopia_Military_Airdrop_Flat_Base
	{
		scope= 2;
		hiddenSelectionsTextures[]=
		{
			"Utopia_Airdrop_Cessna\Models\Textures\Military_co.paa",
			"Utopia_Airdrop_Cessna\Models\Textures\Parts_co.paa"
		};
	};	
	class Utopia_Military_Airdrop_Medium_Base: AIR_Door_Base
	{
		scope= 0;
		displayName="Medium Airdrop Military Storage";
		descriptionShort="A Airdrop Medium Military Storage Chest";
		model="Utopia_Airdrop_Cessna\Models\Military_Crates\Medium\Military_Medium.p3d";
		attachments[]=
		{
			"Shoulder1",
			"Shoulder2",
			"Pistol1",
			"Pistol2",
			"AmmoBox1",
			"AmmoBox2"
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3"
		};
		class Cargo
		{
			itemsCargoSize[]={10,7};
			openable=1;
			allowOwnedCargoManipulation=1;
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
		class GUIInventoryAttachmentsProps
		{
			class AmmoBox
			{
				name = "AmmoBox";
				description = "";
				attachmentSlots[] = 
				{
					"AmmoBox1",
					"AmmoBox2"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
			class Weapons
			{
				name = "Weapons";
				description = "";
				attachmentSlots[] = 
				{
					"Shoulder1",
					"Shoulder2"
				};
				icon = "set:dayz_inventory image:shoulderleft";
			};
			class Pistols
			{
				name = "Pistols";
				description = "";
				attachmentSlots[] = 
				{
					"Pistol1",
					"Pistol2"
				};
				icon = "set:dayz_inventory image:shoulderleft";
			};
		};
	};
	class Utopia_Military_Airdrop_Medium: Utopia_Military_Airdrop_Medium_Base
	{
		scope= 2;
		hiddenSelectionsTextures[]=
		{
			"Utopia_Airdrop_Cessna\Models\Textures\Military_co.paa",
			"Utopia_Airdrop_Cessna\Models\Textures\Inside_co.paa",
			"Utopia_Airdrop_Cessna\Models\Textures\Parts_co.paa"
		};
	};
};