class CfgPatches
{
	class Utopia_Airdrop
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Pistols",
			"DZ_Weapons_Firearms",
			"DZ_Weapons_Magazines"
		};
	};
};
class Mode_Safe;
class Mode_SemiAuto;
class Mode_Single;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoPistol;
class cfgWeapons
{
	class Flaregun;
	class Airdrop_Flaregun_Base: Flaregun
	{
		scope=0;
		displayName="Airdrop Flaregun";
		descriptionShort="A Flaregun for calling in Airdrops";
		model="Utopia_Airdrop\Models\Flare\Gun\Utopia_FlareGun.p3d";
		attachments[]={};
		itemSize[]={2,2};
		weight=400;
		absorbency=0;
		repairableWithKits[]={1};
		repairCosts[]={25};
		PPDOFProperties[]={1,0.5,10,250,4,10};
		WeaponLength=0.634148;
		barrelArmor=3.125;
		isSuicideWeapon=0;
		chamberSize=1;
		chamberedRound="";
		magazines[]={};
		chamberableFrom[]=
		{
			"Ammo_Car_Flare",
			"Ammo_Container_Flare",
			"Ammo_Crate_Flare"
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		inventorySlot[]=
		{
			"Airdrop_Flaregun"
		};
		DisplayMagazine=0;
		ejectType=2;
		recoilModifier[]={1,1,1};
		class NoiseShoot
		{
			strength=50;
			type="shot";
		};
		modes[]=
		{
			"Single"
		};
		class Single: Mode_Single
		{
			soundSetShot[]=
			{
				"Flare_Gun_Shot_SoundSet",
				"Flare_Gun_Tail_SoundSet",
				"Flare_Gun_InteriorTail_SoundSet"
			};
			reloadTime=0.13;
			dispersion=0.029999999;
			magazineSlot="magazine";
		};
		class OpticsInfo: OpticsInfoPistol
		{
			memoryPointCamera="eye";
			discreteDistance[]={25};
			discreteDistanceInitIndex=0;
			modelOptics="-";
			distanceZoomMin=100;
			distanceZoomMax=100;
		};
		class NoiseFlare
		{
			strength=30;
			type="shot";
		};
		weaponStateAnim="dz\anims\anm\player\reloads\Flaregun\w_Flaregun_states.anm";
		boneRemap[]=
		{
			"hammer",
			"Weapon_Bone_02",
			"barrel",
			"Weapon_Bone_01",
			"trigger",
			"Weapon_Trigger",
			"bullet",
			"Weapon_Bullet"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=150;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\weapons\pistols\flaregun\data\flaregun.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\pistols\flaregun\data\flaregun.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\pistols\flaregun\data\flaregun_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\pistols\flaregun\data\flaregun_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\pistols\flaregun\data\flaregun_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class Particles
		{
			class OnFire
			{
				class MuzzleFlashForward
				{
					ignoreIfSuppressed=1;
					illuminateWorld=1;
					overrideParticle="weapon_shot_fnx_01";
				};
				class SmokeCloud
				{
					overrideParticle="weapon_shot_winded_smoke_small";
				};
			};
			class OnOverheating
			{
				shotsToStartOverheating=1;
				maxOverheatingValue=1;
				overheatingDecayInterval=1;
				class OpenChamberSmoke
				{
					onlyIfBoltIsOpen=1;
					overrideParticle="smoking_barrel_small";
					overridePoint="Nabojnicestart";
				};
			};
			class OnBulletCasingEject
			{
				class ChamberSmokeRaise
				{
					overrideParticle="weapon_shot_chamber_smoke_raise";
					overridePoint="Nabojnicestart";
				};
			};
		};
	};
	class Airdrop_Flaregun: Airdrop_Flaregun_Base
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"utopia_airdrop\models\flare\textures\gun_co.paa",
			"utopia_airdrop\models\flare\textures\gun_silver_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"utopia_airdrop\models\flare\textures\Gun.rvmat",
			"utopia_airdrop\models\flare\textures\Gun_Wood.rvmat"
		};
	};
};
