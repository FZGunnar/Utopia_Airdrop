class CfgPatches
{
	class Utopia_Airdrop
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Weapons_Ammunition"};
		magazines[] = {"Ammo_Car_Flare","Ammo_Container_Flare","Ammo_Crate_Flare"};
		ammo[] = {"Bullet_Car_Flare","Bullet_Container_Flare","Bullet_Crate_Flare"};
	};
};
class cfgMagazines
{
	class Ammunition_Base;
	class Ammo_Flare_Base: Ammunition_Base
	{
		scope = 0;
		model = "Utopia_Airdrop\Models\Flare\Bullets\Flare_Bullet.p3d";
		weight = 0.005;
		count = 1;
		ammo = "Bullet_Car_Flare";
		hiddenSelections[] = 
		{
			"camo1",
			"camo2",
			"camo3"
		};
		inventorySlot[]=
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
	};
	class Ammo_Car_Flare: Ammo_Flare_Base
	{
		scope = 2;
		displayName = "Car Flare";
		descriptionShort = "A Flare to call in a Car Drop";
		ammo = "Bullet_Car_Flare";
		hiddenSelectionsTextures[]=
		{
			"Utopia_Airdrop\Models\Flare\Textures\FlareBullet_Blue_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"Utopia_Airdrop\Models\Flare\Textures\FlareBullet.rvmat",
			"Utopia_Airdrop\Models\Flare\Textures\FlareBullet_Gold.rvmat",
			"Utopia_Airdrop\Models\Flare\Textures\FlareBullet_Silver.rvmat"
		};
	};
	class Ammo_Container_Flare: Ammo_Flare_Base
	{
		scope = 2;
		displayName = "Container Flare";
		descriptionShort = "A Flare to call in a Container Drop";
		ammo = "Bullet_Container_Flare";
		hiddenSelectionsTextures[]=
		{
			"Utopia_Airdrop\Models\Flare\Textures\FlareBullet_Red_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"Utopia_Airdrop\Models\Flare\Textures\FlareBullet.rvmat",
			"Utopia_Airdrop\Models\Flare\Textures\FlareBullet_Gold.rvmat",
			"Utopia_Airdrop\Models\Flare\Textures\FlareBullet_Silver.rvmat"
		};
	};
	class Ammo_Crate_Flare: Ammo_Flare_Base
	{
		scope = 2;
		displayName = "Crate Flare";
		descriptionShort = "A Flare to call in a Crate Drop";
		ammo = "Bullet_Crate_Flare";
		hiddenSelectionsTextures[]=
		{
			"Utopia_Airdrop\Models\Flare\Textures\FlareBullet_Yellow_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"Utopia_Airdrop\Models\Flare\Textures\FlareBullet.rvmat",
			"Utopia_Airdrop\Models\Flare\Textures\FlareBullet_Gold.rvmat",
			"Utopia_Airdrop\Models\Flare\Textures\FlareBullet_Silver.rvmat"
		};
	};
};
class CfgAmmo
{
	class Bullet_Base;
	class Bullet_Car_Flare: Bullet_Base
	{
		scope = 1;
		ammo = "Ammo_Car_Flare";
		ammoItems[] = {"Ammo_Car_Flare"};
		//main configs that drive fx
		SimulationScriptClass = "FlareSimulation_Car_Flare";
		simulation = "shotIlluminating";
		timeToLive = 180;
		airFrictionChangeOnActivation=-0.07;//this is done to slow flare down and hover over target
		casing = "FxCartridge_Flare";
		spawnPileType = "Ammo_Car_Flare";
		round = "FxRound_Flare";
		airFriction = -0.004;//
		coefGravity = 0.02;
		typicalSpeed = 25;//
		initSpeed = 80;
		weight = 0.005;
		caliber = 0.0;
		hit = 5;
		indirectHit = 2;
		indirectHitRange = 0.2;
		simulationStep = 0.05;
		explosive = 0;
		soundHit[] = {"",0,1};
		deflecting = 240;		
		explosionTime = 180;
		radius = 240;
		soundFly[] = {};
		supersonicCrackNear[] = {};
		supersonicCrackFar[] = {};
		soundEngine[] = {"",0.099999994,1,100};
		class DamageApplied
		{
			type = "Projectile";
			dispersion = 0.0;
			bleedThreshold = 0;
			defaultDamageOverride[] = {{0.5,1.0}};
			class Health
			{
				damage = 10;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 0;
			};
		};
	};
	class Bullet_Container_Flare: Bullet_Base
	{
		scope = 1;
		ammo = "Ammo_Container_Flare";
		ammoItems[] = {"Ammo_Container_Flare"};
		SimulationScriptClass = "FlareSimulation_Container_Flare";
		airFrictionChangeOnActivation=-0.07;
		simulation = "shotIlluminating";
		casing = "FxCartridge_Flare";
		spawnPileType = "Ammo_Container_Flare";
		round = "FxRound_Flare";
		airFriction = -0.004;//
		coefGravity = 0.02;
		typicalSpeed = 25;//
		initSpeed = 80;
		weight = 0.005;
		caliber = 0.0;
		hit = 5;
		indirectHit = 2;
		indirectHitRange = 0.2;
		simulationStep = 0.05;
		explosive = 0;
		soundHit[] = {"",0,1};
		deflecting = 240;
		timeToLive = 180;
		explosionTime = 180;
		radius = 240;
		soundFly[] = {};
		supersonicCrackNear[] = {};
		supersonicCrackFar[] = {};
		soundEngine[] = {"",0.099999994,1,100};
		class DamageApplied
		{
			type = "Projectile";
			dispersion = 0.0;
			bleedThreshold = 0;
			defaultDamageOverride[] = {{0.5,1.0}};
			class Health
			{
				damage = 10;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 0;
			};
		};
	};
	class Bullet_Crate_Flare: Bullet_Base
	{
		scope = 1;
		ammo = "Ammo_Crate_Flare";
		ammoItems[] = {"Ammo_Crate_Flare"};
		SimulationScriptClass = "FlareSimulation_Crate_Flare";
		airFrictionChangeOnActivation=-0.07;
		simulation = "shotIlluminating";
		casing = "FxCartridge_Flare";
		spawnPileType = "Bullet_Crate_Flare";
		round = "FxRound_Flare";
		airFriction = -0.004;//
		coefGravity=0.009;
		typicalSpeed = 25;//
		initSpeed = 35;
		weight = 0.005;
		caliber = 0.0;
		hit = 5;
		indirectHit = 2;
		indirectHitRange = 0.2;
		simulationStep = 0.05;
		explosive = 0;
		soundHit[] = {"",0,1};
		deflecting = 170;
		timeToLive = 120;
		explosionTime = 120;
		radius = 240;
		soundFly[] = {};
		supersonicCrackNear[] = {};
		supersonicCrackFar[] = {};
		soundEngine[] = {"",0.099999994,1,100};
		class DamageApplied
		{
			type = "Projectile";
			dispersion = 0.0;
			bleedThreshold = 0;
			defaultDamageOverride[] = {{0.5,1.0}};
			class Health
			{
				damage = 10;
			};
			class Blood
			{
				damage = 100;
			};
			class Shock
			{
				damage = 0;
			};
		};
	};
};
class cfgAmmoTypes
{
	class AType_Bullet_Car_Flare
	{
		name = "Bullet_Car_Flare";
	};
	class AType_Bullet_Container_Flare
	{
		name = "Bullet_Container_Flare";
	};
	class AType_Bullet_Crate_Flare
	{
		name = "Bullet_Crate_Flare";
	};
};