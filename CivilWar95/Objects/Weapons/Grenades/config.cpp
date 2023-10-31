class CfgPatches
{
	class CW95_Weapons_Grenades
	{
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[] = { "DZ_Data" };
		units[] = {};
	};
};

class CfgVehicles
{
	class M18SmokeGrenade_Red;
	class CW95_ArtillerySmokeGrenade : M18SmokeGrenade_Red
	{
		scope = 2;
		displayName = "$STR_ZENARTILLERYGRENADE0";
		descriptionShort = "$STR_ZENARTILLERYGRENADE1";
		weight = 250;
		hiddenSelectionsTextures[] =
		{
			"CivilWar95\CivilWar95\Objects\Weapons\Grenades\data\artillerystrikegrenade_red_co.paa"
		};
		class EnergyManager
		{
			energyAtSpawn = 180; // 3 mins lifetime
			energyUsagePerSecond = 1;
			wetnessExposure = 0.1;
			updateInterval = 5;
		};
	};
	class M18SmokeGrenade_Green;
	class CW95_ArtillerySmokeGrenadeChem : M18SmokeGrenade_Green
	{
		scope = 2;
		displayName = "$STR_ZENARTILLERYCHEMGRENADE0";
		descriptionShort = "$STR_ZENARTILLERYCHEMGRENADE1";
		weight = 250;
		hiddenSelectionsTextures[] =
		{
			"CivilWar95\CivilWar95\Objects\Weapons\Grenades\data\artillerystrikegrenade_green_co.paa"
		};
		class EnergyManager
		{
			energyAtSpawn = 180; // 3 mins lifetime
			energyUsagePerSecond = 1;
			wetnessExposure = 0.1;
			updateInterval = 5;
		};
	};

	// Define bomb
	class Grenade_Base;
	class CW95_ArtilleryBomb : Grenade_Base
	{
		scope = 2;
		displayName = "ZenBangBang";
		model = "DZ\weapons\explosives\grenade.p3d";
		itemSize[] = { 1,1 };
		weight = 5000;
		forceFarBubble = "true";
		hiddenSelections[] = { "camo" };
		hiddenSelectionsTextures[] = { "dz\weapons\explosives\data\grenade_co.paa" };
		hiddenSelectionsMaterials[] = { "dz\weapons\explosives\data\grenade.rvmat" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 1;
					healthLevels[] = { {1,{"DZ\weapons\explosives\data\grenade.rvmat"}},{0.7,{"DZ\weapons\explosives\data\grenade.rvmat"}},{0.5,{"DZ\weapons\explosives\data\grenade_damage.rvmat"}},{0.3,{"DZ\weapons\explosives\data\grenade_damage.rvmat"}},{0,{"DZ\weapons\explosives\data\grenade_destruct.rvmat"}} };
				};
			};
		};
	};
};

class CfgAmmo
{
	class DefaultAmmo;
	class CW95_ArtilleryBomb_Ammo : DefaultAmmo
	{
		indirectHit = 1;
		indirectHitRange = 15;
		explosive = 1;
		typicalSpeed = 3;
		initSpeed = 3;
		simulation = "shotShell";
		simulationStep = 0.05;

		soundSetExplosion[] =
		{
			"Landmine_Explosion_SoundSet",
			"Plastic_Explosion_SoundSet",
			"Landmine_Explosion_Tail_SoundSet",
			"Plastic_Explosion_Tail_SoundSet"
		};

		class DamageApplied
		{
			type = "FragGrenade";
			class Health
			{
				damage = 1;
			};
			class Blood
			{
				damage = 1;
			};
			class Shock
			{
				damage = 33;
			};
		};
		class NoiseExplosion
		{
			strength = 100;
			type = "shot";
		};
	};
};