class CfgPatches
{
	class Utopia_Airdrop_Scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"Utopia_Airdrop",
			"Utopia_Core"
		};
	};
};
class CfgMods
{
	class Utopia_Airdrop
	{
		dir="Utopia_Airdrop_Scripts";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="Utopia_Airdrop_Scripts";
		credits="TheDmitri,Scarabyte,Genesis,Gunner";
		author="TheDmitri";
		authorID="0";
		version="1.3";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"LBmaster_Groups/scripts/Common",
					"BasicMapDefine/scripts/Common",
					"Utopia_Airdrop_Scripts/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"LBmaster_Groups/scripts/Common",
					"BasicMapDefine/scripts/Common",
					"Utopia_Airdrop_Scripts/scripts/4_World"
				};
			};
		};
	};
};
class CfgVehicles
{
	class Container_Base;
	class Roadflare;
	class UtopiaAirdropFlare: Roadflare
	{
		scope=2;
		displayName = "Airdrop Flare";
		descriptionShort = "Use it to call an airdrop";
	};
	class AIR_Door_Base: Container_Base
	{
		scope=0;
		varQuantityDestroyOnMin=0;
		quantityBar=1;
		carveNavmesh=1;
		bounding="BSphere";
		overrideDrawArea="3.0";
		visibilityModifier=0.94999999;
		alignHologramToTerain=1;
		physLayer="item_large";
		simulation="inventoryItem";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};
};
class CfgSoundShaders
{
	class baseCharacter_SoundShader;
	class Container_open_SoundShader: baseCharacter_SoundShader
	{
		samples[] = 
		{
			{"DZ\sounds\environment\buildings\doors\metal\doormetalsmallopenabit_1",3.1622777}
		};
		volume = 1.3;
	};
	class Container_close_SoundShader: baseCharacter_SoundShader
	{
		samples[] = 
		{
			{"DZ\sounds\environment\buildings\doors\wood\doorwoodlargeopenabit_5",3.1622777}
		};
		volume = 1.3;
	};	
};

class CfgSoundSets
{
	class baseCharacter_SoundSet;
	class Container_open_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[] = 
		{	
			"Container_open_SoundShader"
		};
	};
	
	class Container_close_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[] = 
		{	
			"Container_close_SoundShader"
		};
	};
};
class CfgSounds
{
	class default
	{
		name = "";
		titles[] = {};
	};
	class utopiaHeliSound: default
	{
		sound[] = {"\Utopia_Airdrop_Scripts\Datasets\sounds\heliSound",10,1,1500};
	};
};

class CfgWeapons
{
	class RifleCore;
	class Rifle_Base: RifleCore
	{
		inventorySlot[]+=
		{
			"Shoulder",
			"Melee",
			"Shoulder1",
			"Shoulder2",
			"Shoulder3",
			"Shoulder4",
			"Shoulder5",
			"Shoulder6",
			"Shoulder7",
			"Shoulder8",
			"Shoulder9",
			"Shoulder10",
			"Shoulder11",
			"Shoulder12",
			"Shoulder13",
			"Shoulder14",
			"Shoulder15",
			"Shoulder16",
			"Shoulder17",
			"Shoulder18",
			"Shoulder19",
			"Shoulder20"
		};
	};
};

class CfgSlots
{
	class Slot_Shoulder1
	{
		name="Shoulder1";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder2
	{
		name="Shoulder2";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder3
	{
		name="Shoulder3";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder4
	{
		name="Shoulder4";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder5
	{
		name="Shoulder5";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder6
	{
		name="Shoulder6";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder7
	{
		name="Shoulder7";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder8
	{
		name="Shoulder8";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder9
	{
		name="Shoulder9";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder10
	{
		name="Shoulder10";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder11
	{
		name="Shoulder11";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder12
	{
		name="Shoulder12";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder13
	{
		name="Shoulder13";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder14
	{
		name="Shoulder14";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder15
	{
		name="Shoulder15";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder16
	{
		name="Shoulder16";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder17
	{
		name="Shoulder17";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder18
	{
		name="Shoulder18";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder19
	{
		name="Shoulder19";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
	class Slot_Shoulder20
	{
		name="Shoulder20";
		displayName="$STR_CfgShoulder0";
		ghostIcon="set:dayz_inventory image:shoulderleft";
	};
};