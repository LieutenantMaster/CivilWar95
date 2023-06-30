class CfgPatches
{
	class CV95_Objects_BuilderItems
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
	class ArmedTripwireTrap: TripwireTrap {};

	class LandMineTrap;
	class ArmedLandMineTrap: LandMineTrap {};

	class BearTrap;
	class ArmedBearTrap: BearTrap {};

	class Grenade_ChemGas;
	class ArmedGrenade_ChemGas: Grenade_ChemGas {};

	class M67Grenade;
	class ArmedM67Grenade: M67Grenade {};

	class RGD5Grenade;
	class ArmedRGD5Grenade: RGD5Grenade {};

	class FlashGrenade;
	class ArmedFlashGrenade: FlashGrenade {};

	class HouseNoDestruct;
	class CV95_Effect_Base: HouseNoDestruct
	{
		scope=0;
	};
	class CV95_Effect_CAMP_FIRE_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CAMP_SMALL_FIRE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CAMP_NORMAL_FIRE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CAMP_SMALL_SMOKE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CAMP_NORMAL_SMOKE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CAMP_FIRE_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CAMP_STEAM_2END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CAMP_STEAM_EXTINGUISH_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CAMP_STOVE_FIRE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CAMP_STOVE_FIRE_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CAMP_STOVE_FIRE_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CAMP_NO_IGNITE_WIND: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_HOUSE_FIRE_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_HOUSE_SMALL_FIRE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_HOUSE_SMALL_SMOKE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_HOUSE_NORMAL_FIRE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_HOUSE_NORMAL_SMOKE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_HOUSE_FIRE_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_HOUSE_FIRE_STEAM_2END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BARREL_FIRE_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BARREL_SMALL_FIRE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BARREL_SMALL_SMOKE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BARREL_NORMAL_FIRE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BARREL_NORMAL_SMOKE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BARREL_FIRE_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BARREL_FIRE_STEAM_2END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_OVEN_FIRE_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_OVEN_SMALL_FIRE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_OVEN_NORMAL_FIRE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_OVEN_FIRE_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_COOKING_BOILING_EMPTY: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_COOKING_BOILING_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_COOKING_BOILING_DONE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_COOKING_BAKING_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_COOKING_BAKING_DONE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_COOKING_DRYING_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_COOKING_DRYING_DONE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_COOKING_BURNING_DONE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_TORCH_T3: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_TORCH_T1: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_TORCH_T2: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BROOM_TORCH_T1: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BROOM_TORCH_T2: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BROOM_TORCH_T3: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_ROADFLARE_BURNING_INIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_ROADFLARE_BURNING_MAIN: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_ROADFLARE_BURNING_ENDING: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_ROADFLARE_BURNING_SMOKE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FLAREPROJ_FIRE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FLAREPROJ_ACTIVATE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FLAREPROJ_ACTIVATE_RED: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FLAREPROJ_ACTIVATE_GREEN: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FLAREPROJ_ACTIVATE_BLUE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_DIGGING_STASH: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_RDG2_BLACK_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_RDG2_BLACK_LOOP: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_RDG2_BLACK_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_RDG2_WHITE_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_RDG2_WHITE_LOOP: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_RDG2_WHITE_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_GREEN_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_GREEN_LOOP: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_GREEN_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_PURPLE_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_PURPLE_LOOP: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_PURPLE_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_RED_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_RED_LOOP: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_RED_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_WHITE_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_WHITE_LOOP: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_WHITE_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_YELLOW_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_YELLOW_LOOP: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_YELLOW_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_BLACK_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_BLACK_LOOP: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M18_BLACK_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_M84: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_RGD5: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_M67: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_POWER_GENERATOR_SMOKE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BARBED_WIRE_SPARKS: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_EASTER_EGG_ACTIVATE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BLEEDING_SOURCE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BLEEDING_SOURCE_LIGHT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BLOOD_SURFACE_DROPS: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BLOOD_SURFACE_CHUNKS: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_VOMIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BREATH_VAPOUR_LIGHT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BREATH_VAPOUR_MEDIUM: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BREATH_VAPOUR_HEAVY: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_VOMIT_CHUNKS: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_MUZZLE_FLASH_SVD_STAR: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_SOLO_MUZZLE_FLASH: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_FNX: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_FNX_SUPPRESSED: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_PARTICLE_TEST: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_PARTICLE_CASING: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_PARTICLE_CASING_RAISE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_CZ75: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_AKM: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_AKM_SUPPRESSED: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_IZH18: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_IZH18_SUPPRESSED: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_MP5K: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_MP5K_2: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_MP5K_SUPPRESSED: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_MP5K_COMPENSATOR: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_UMP45: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_M4A1: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_MP133: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_PELLETS: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_MOSIN9130: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_MOSIN_COMPENSATOR: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_CZ527: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_SKS: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_WINCHESTER70: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_VSS: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_AK74: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_AK101: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_MAGNUM: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_CZ61: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_LONG_WINDED_SMOKE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GUN_LONG_WINDED_SMOKE_SMALL: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_SMOKING_BARREL: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_SMOKING_BARREL_SMALL: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_SMOKING_BARREL_HEAVY: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_SMOKING_BARREL_STEAM: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_SMOKING_BARREL_STEAM_SMALL: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_SMARKS_CHAMBER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_TEST: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_DISTANT_DUST: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_TEST_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_TEST2: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_TEST_ENTER_DEBUG: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_TEST_RICOCHET_DEBUG: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_TEST_EXIT_DEBUG: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_TEST_NO_MATERIAL_ERROR: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_WOOD_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_WOOD_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_WOOD_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_CONCRETE_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_CONCRETE_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_CONCRETE_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_FOLIAGE_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_FOLIAGE_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_FOLIAGE_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_GRASS_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_GRASS_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_DIRT_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_DIRT_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_DIRT_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_RUBBER_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_RUBBER_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_RUBBER_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_GRAVEL_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_GRAVEL_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_GRAVEL_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_PLASTER_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_PLASTER_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_PLASTER_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_METAL_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_METAL_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_METAL_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_MEAT_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_MEAT_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_MEAT_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_MEATBONES_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_MEATBONES_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_MEATBONES_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_GLASS_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_GLASS_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_GLASS_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_WATER_SMALL_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_WATER_MEDIUM_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_WATER_LARGE_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_TEXTILE_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_TEXTILE_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_TEXTILE_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_SAND_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_SAND_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_SAND_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_PLASTIC_ENTER: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_PLASTIC_RICOCHET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_IMPACT_PLASTIC_EXIT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_EXPLOSION_LANDMINE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_EXPLOSION_TEST: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_SMOKING_HELI_WRECK: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_AURORA_SANTA_WRECK: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_SMOKE_GENERIC_WRECK: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_SMOKING_CAR_ENGINE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_EVAPORATION: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_HATCHBACK_COOLANT_OVERHEATING: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_HATCHBACK_COOLANT_OVERHEATED: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_HATCHBACK_ENGINE_OVERHEATING: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_HATCHBACK_ENGINE_OVERHEATED: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_HATCHBACK_EXHAUST_SMOKE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_ENV_SWARMING_FLIES: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BONFIRE_FIRE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_BONFIRE_SMOKE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_SPOOKY_MIST: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_VOMIT_BLOOD: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CONTAMINATED_AREA_GAS_TINY: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CONTAMINATED_AREA_GAS_AROUND: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CONTAMINATED_AREA_GAS_BIGASS: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CONTAMINATED_AREA_GAS_GROUND: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CONTAMINATED_AREA_GAS_SHELL: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FIREWORKS_SHOT: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FIREWORKS_EXPLOSION_RED: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FIREWORKS_EXPLOSION_GREEN: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FIREWORKS_EXPLOSION_BLUE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FIREWORKS_EXPLOSION_YELLOW: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FIREWORKS_EXPLOSION_PINK: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FIREWORKS_FUSE: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FIREWORKS_AFTERBURN_START: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_FIREWORKS_AFTERBURN_END: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_GRENADE_CHEM_BREAK: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_CLAYMORE_EXPLOSION: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_PLASTIC_EXPLOSION: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_WATER_JET: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_WATER_JET_WEAK: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_WATER_SPILLING: CV95_Effect_Base
	{
		scope=2;
	};
	class CV95_Effect_DROWNING_BUBBLES: CV95_Effect_Base
	{
		scope=2;
	};
};