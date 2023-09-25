class CfgPatches
{
	class CW95_Objects_BuilderItems
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};

class CfgVehicles
{
	class TripwireTrap;
	class CW95_ArmedTripwireTrap: TripwireTrap {};

	class LandMineTrap;
	class CW95_ArmedLandMineTrap: LandMineTrap {};

	class BearTrap;
	class CW95_ArmedBearTrap: BearTrap {};

	class Grenade_ChemGas;
	class CW95_ArmedGrenade_ChemGas: Grenade_ChemGas {};

	class M67Grenade;
	class CW95_ArmedM67Grenade: M67Grenade {};

	class RGD5Grenade;
	class CW95_ArmedRGD5Grenade: RGD5Grenade {};

	class FlashGrenade;
	class CW95_ArmedFlashGrenade: FlashGrenade {};

	class HouseNoDestruct;
	class CW95_DynamicEffect_Base: HouseNoDestruct
	{
		scope=0;
		model="CivilWar95\CivilWar95\Objects\BuilderItems\invInteract.p3d";
	};
	class CW95_DynamicFire_Base: CW95_DynamicEffect_Base {};
	class CW95_DynamicFire_Light: CW95_DynamicFire_Base
	{
		scope=2;
	};
	class CW95_DynamicFire_Normal: CW95_DynamicFire_Base
	{
		scope=2;
	};
	class CW95_DynamicFire_Heavy: CW95_DynamicFire_Base
	{
		scope=2;
	};

	class CW95_Effect_Base: HouseNoDestruct
	{
		scope=0;
	};
	class CW95_Effect_CAMP_FIRE_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CAMP_SMALL_FIRE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CAMP_NORMAL_FIRE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CAMP_SMALL_SMOKE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CAMP_NORMAL_SMOKE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CAMP_FIRE_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CAMP_STEAM_2END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CAMP_STEAM_EXTINGUISH_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CAMP_STOVE_FIRE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CAMP_STOVE_FIRE_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CAMP_STOVE_FIRE_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CAMP_NO_IGNITE_WIND: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_HOUSE_FIRE_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_HOUSE_SMALL_FIRE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_HOUSE_SMALL_SMOKE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_HOUSE_NORMAL_FIRE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_HOUSE_NORMAL_SMOKE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_HOUSE_FIRE_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_HOUSE_FIRE_STEAM_2END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BARREL_FIRE_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BARREL_SMALL_FIRE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BARREL_SMALL_SMOKE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BARREL_NORMAL_FIRE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BARREL_NORMAL_SMOKE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BARREL_FIRE_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BARREL_FIRE_STEAM_2END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_OVEN_FIRE_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_OVEN_SMALL_FIRE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_OVEN_NORMAL_FIRE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_OVEN_FIRE_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_COOKING_BOILING_EMPTY: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_COOKING_BOILING_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_COOKING_BOILING_DONE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_COOKING_BAKING_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_COOKING_BAKING_DONE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_COOKING_DRYING_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_COOKING_DRYING_DONE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_COOKING_BURNING_DONE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_TORCH_T3: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_TORCH_T1: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_TORCH_T2: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BROOM_TORCH_T1: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BROOM_TORCH_T2: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BROOM_TORCH_T3: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_ROADFLARE_BURNING_INIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_ROADFLARE_BURNING_MAIN: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_ROADFLARE_BURNING_ENDING: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_ROADFLARE_BURNING_SMOKE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FLAREPROJ_FIRE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FLAREPROJ_ACTIVATE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FLAREPROJ_ACTIVATE_RED: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FLAREPROJ_ACTIVATE_GREEN: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FLAREPROJ_ACTIVATE_BLUE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_DIGGING_STASH: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_RDG2_BLACK_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_RDG2_BLACK_LOOP: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_RDG2_BLACK_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_RDG2_WHITE_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_RDG2_WHITE_LOOP: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_RDG2_WHITE_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_GREEN_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_GREEN_LOOP: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_GREEN_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_PURPLE_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_PURPLE_LOOP: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_PURPLE_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_RED_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_RED_LOOP: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_RED_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_WHITE_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_WHITE_LOOP: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_WHITE_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_YELLOW_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_YELLOW_LOOP: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_YELLOW_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_BLACK_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_BLACK_LOOP: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M18_BLACK_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_M84: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_RGD5: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_M67: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_POWER_GENERATOR_SMOKE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BARBED_WIRE_SPARKS: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_EASTER_EGG_ACTIVATE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BLEEDING_SOURCE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BLEEDING_SOURCE_LIGHT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BLOOD_SURFACE_DROPS: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BLOOD_SURFACE_CHUNKS: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_VOMIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BREATH_VAPOUR_LIGHT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BREATH_VAPOUR_MEDIUM: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BREATH_VAPOUR_HEAVY: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_VOMIT_CHUNKS: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_MUZZLE_FLASH_SVD_STAR: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_SOLO_MUZZLE_FLASH: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_FNX: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_FNX_SUPPRESSED: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_PARTICLE_TEST: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_PARTICLE_CASING: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_PARTICLE_CASING_RAISE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_CZ75: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_AKM: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_AKM_SUPPRESSED: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_IZH18: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_IZH18_SUPPRESSED: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_MP5K: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_MP5K_2: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_MP5K_SUPPRESSED: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_MP5K_COMPENSATOR: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_UMP45: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_M4A1: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_MP133: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_PELLETS: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_MOSIN9130: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_MOSIN_COMPENSATOR: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_CZ527: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_SKS: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_WINCHESTER70: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_VSS: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_AK74: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_AK101: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_MAGNUM: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_CZ61: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_LONG_WINDED_SMOKE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GUN_LONG_WINDED_SMOKE_SMALL: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_SMOKING_BARREL: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_SMOKING_BARREL_SMALL: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_SMOKING_BARREL_HEAVY: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_SMOKING_BARREL_STEAM: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_SMOKING_BARREL_STEAM_SMALL: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_SMARKS_CHAMBER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_TEST: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_DISTANT_DUST: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_TEST_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_TEST2: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_TEST_ENTER_DEBUG: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_TEST_RICOCHET_DEBUG: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_TEST_EXIT_DEBUG: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_TEST_NO_MATERIAL_ERROR: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_WOOD_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_WOOD_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_WOOD_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_CONCRETE_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_CONCRETE_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_CONCRETE_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_FOLIAGE_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_FOLIAGE_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_FOLIAGE_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_GRASS_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_GRASS_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_DIRT_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_DIRT_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_DIRT_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_RUBBER_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_RUBBER_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_RUBBER_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_GRAVEL_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_GRAVEL_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_GRAVEL_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_PLASTER_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_PLASTER_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_PLASTER_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_METAL_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_METAL_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_METAL_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_MEAT_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_MEAT_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_MEAT_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_MEATBONES_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_MEATBONES_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_MEATBONES_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_GLASS_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_GLASS_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_GLASS_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_WATER_SMALL_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_WATER_MEDIUM_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_WATER_LARGE_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_TEXTILE_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_TEXTILE_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_TEXTILE_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_SAND_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_SAND_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_SAND_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_PLASTIC_ENTER: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_PLASTIC_RICOCHET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_IMPACT_PLASTIC_EXIT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_EXPLOSION_LANDMINE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_EXPLOSION_TEST: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_SMOKING_HELI_WRECK: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_AURORA_SANTA_WRECK: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_SMOKE_GENERIC_WRECK: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_SMOKING_CAR_ENGINE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_EVAPORATION: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_HATCHBACK_COOLANT_OVERHEATING: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_HATCHBACK_COOLANT_OVERHEATED: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_HATCHBACK_ENGINE_OVERHEATING: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_HATCHBACK_ENGINE_OVERHEATED: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_HATCHBACK_EXHAUST_SMOKE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_ENV_SWARMING_FLIES: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BONFIRE_FIRE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_BONFIRE_SMOKE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_SPOOKY_MIST: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_VOMIT_BLOOD: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CONTAMINATED_AREA_GAS_TINY: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CONTAMINATED_AREA_GAS_AROUND: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CONTAMINATED_AREA_GAS_BIGASS: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CONTAMINATED_AREA_GAS_GROUND: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CONTAMINATED_AREA_GAS_SHELL: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FIREWORKS_SHOT: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FIREWORKS_EXPLOSION_RED: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FIREWORKS_EXPLOSION_GREEN: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FIREWORKS_EXPLOSION_BLUE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FIREWORKS_EXPLOSION_YELLOW: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FIREWORKS_EXPLOSION_PINK: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FIREWORKS_FUSE: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FIREWORKS_AFTERBURN_START: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_FIREWORKS_AFTERBURN_END: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_GRENADE_CHEM_BREAK: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_CLAYMORE_EXPLOSION: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_PLASTIC_EXPLOSION: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_WATER_JET: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_WATER_JET_WEAK: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_WATER_SPILLING: CW95_Effect_Base
	{
		scope=2;
	};
	class CW95_Effect_DROWNING_BUBBLES: CW95_Effect_Base
	{
		scope=2;
	};
};