class CfgPatches
{
	class Utopia_Airdrop
	{
		units[] = {"Utopia_Flare_Case"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Utopia_Flare_Case_Base: Inventory_Base
	{
		scope = 0;
		displayName = "Flare Case";
		descriptionShort = "";
		model = "Utopia_Airdrop\Models\Flare\Box\Utopia_Flare_Case.p3d";
		weight = 500;
		itemSize[] = {4,3};
		hiddenSelections[] = {"camo"};
		rotationFlags = 2;
		overrideDrawArea = 3.0;
		carveNavmesh = 1;
		forceFarBubble = "true";
		attachments[] = 
		{
			"Flare_Bullet_1",
			"Flare_Bullet_2",
			"Flare_Bullet_3",
			"Flare_Bullet_4",
			"Flare_Bullet_5",
			"Flare_Bullet_6",
			"Flare_Bullet_7",
			"Flare_Bullet_8",
			"Flare_Bullet_9",
			"Flare_Bullet_10",
			"Airdrop_Flaregun"
		};
		class GUIInventoryAttachmentsProps
		{
			class FlareGun
			{
				name = "Airdrop_Flaregun";
				description = "";
				attachmentSlots[] = {"Airdrop_Flaregun"};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
			class Flare_Ammo
			{
				name = "Flare_Ammo";
				description = "";
				attachmentSlots[] = 
				{
					"Flare_Bullet_1",
					"Flare_Bullet_2",
					"Flare_Bullet_3",
					"Flare_Bullet_4",
					"Flare_Bullet_5",
					"Flare_Bullet_6",
					"Flare_Bullet_7",
					"Flare_Bullet_8",
					"Flare_Bullet_9",
					"Flare_Bullet_10"
				};
				icon = "set:dayz_inventory image:cat_common_cargo";
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {0,0};
			openable = 1;
			allowOwnedCargoManipulation = 1;
		};
		class AnimationSources
		{
			class door1
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1.5;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0,{}}};
				};
			};
		};
	};
	class Utopia_Flare_Case: Utopia_Flare_Case_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] = 
		{
			"utopia_airdrop\models\flare\textures\case_co.paa"
		};
	};
};
