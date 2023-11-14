class CfgPatches
{
	class CW95_Sounds_Gear_InventorySounds
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Data",
			"DZ_Characters_Backpacks",
			"DZ_Characters_Belts",
			"DZ_Characters_Glasses",
			"DZ_Characters_Gloves",
			"DZ_Characters_Headgear",
			"DZ_Characters_Masks",
			"DZ_Characters_Pants",
			"DZ_Characters_Shoes",
			"DZ_Characters_Tops",
			"DZ_Characters_Vests",
			"DZ_Gear_Books",
			"DZ_Gear_Camping",
			"DZ_Gear_Consumables",
			"DZ_Gear_Containers",
			"DZ_Gear_Cooking",
			"DZ_Gear_Crafting",
			"DZ_Gear_Cultivation",
			"DZ_Gear_Drinks",
			"DZ_Gear_Food",
			"DZ_Gear_Medical",
			"DZ_Gear_Navigation",
			"DZ_Gear_Optics",
			"DZ_Radio",
			"DZ_Gear_Tools",
			"DZ_Gear_Traps",
			"DZ_Vehicles_Parts",
			"DZ_Vehicles_Wheeled",
			"DZ_Weapons_Ammunition",
			"DZ_Weapons_Lights",
			"DZ_Weapons_Magazines",
			"DZ_Weapons_Muzzles",
			"DZ_Weapons_Optics",
			"DZ_Weapons_Supports",
			"DZ_Weapons_Firearms",
			"DZ_Weapons_Melee_Blade",
			"DZ_Weapons_Melee_Blunt",
			"DZ_Weapons_Melee_Powered"
		};
		author = "Niphoria"; // Thanks <3
		name = "";
	};
};

class CfgSoundShaders
{
	class CW95_SoundShader_Base
	{
		volume=3;
		range=7.5;
		radius=1.5;
	};
	class CW95_ShotgunShell_Move_SoundShader: CW95_SoundShader_Base
	{
		volume=1;
		samples[]=
		{
			
			{
				"DZ\sounds\weapons\shells\shell_12ga_default_1",
				1
			},
			
			{
				"DZ\sounds\weapons\shells\shell_12ga_default_2",
				1
			},
			
			{
				"DZ\sounds\weapons\shells\shell_12ga_default_3",
				1
			},
			
			{
				"DZ\sounds\weapons\shells\shell_12ga_default_4",
				1
			},
			
			{
				"DZ\sounds\weapons\shells\shell_12ga_default_5",
				1
			}
		};
	};
	class CW95_Bullet_Move_SoundShader: CW95_SoundShader_Base
	{
		samples[]=
		{
			
			{
				"DZ\sounds\weapons\firearms\magnum\handling\magnum_bullet_in_01",
				1
			},
			
			{
				"DZ\sounds\weapons\firearms\magnum\handling\magnum_bullet_in_02",
				1
			},
			
			{
				"DZ\sounds\weapons\firearms\magnum\handling\magnum_bullet_in_03",
				1
			},
			
			{
				"DZ\sounds\weapons\firearms\magnum\handling\magnum_bullet_in_04",
				1
			},
			
			{
				"DZ\sounds\weapons\firearms\magnum\handling\magnum_bullet_in_05",
				1
			}
		};
	};
	class CW95_Item_Move_Small_SoundShader: CW95_SoundShader_Base
	{
		samples[]=
		{
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\runErc_1",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\runErc_2",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\runErc_3",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\runErc_4",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\runErc_5",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\runErc_6",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\runErc_7",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\runErc_8",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\sprintErc_1",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\sprintErc_2",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\sprintErc_3",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\sprintErc_4",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\sprintErc_5",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\sprintErc_6",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\sprintErc_7",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\small\sprintErc_8",
				1
			}
		};
	};
	class CW95_Item_Move_Regular_SoundShader: CW95_SoundShader_Base
	{
		range=13.5;
		samples[]=
		{
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\runErc_1",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\runErc_2",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\runErc_3",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\runErc_4",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\runErc_5",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\runErc_6",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\runErc_7",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\runErc_8",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\sprintErc_1",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\sprintErc_2",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\sprintErc_3",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\sprintErc_4",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\sprintErc_5",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\sprintErc_6",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\sprintErc_7",
				1
			},
			
			{
				"DZ\sounds\Characters\movement\attachment\Backpack\military\sprintErc_8",
				1
			}
		};
	};
};

class CfgSoundSets
{
	class CW95_SoundSet_Base
	{
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
		distanceFilter="defaultDistanceFilter";
	};
	class CW95_ShotgunShell_Move_Smoll: CW95_SoundSet_Base
	{
		soundShaders[]=
		{
			"CW95_ShotgunShell_Move_SoundShader"
		};
	};
	class CW95_Bullet_Move_Smoll: CW95_SoundSet_Base
	{
		soundShaders[]=
		{
			"CW95_Bullet_Move_SoundShader"
		};
	};
	class CW95_Item_Move_Small: CW95_SoundSet_Base
	{
		soundShaders[]=
		{
			"CW95_Item_Move_Small_SoundShader"
		};
	};
	class CW95_Item_Move_Regular: CW95_SoundSet_Base
	{
		soundShaders[]=
		{
			"CW95_Item_Move_Regular_SoundShader"
		};
	};
};

class CfgVehicles
{
	class Static;
	class Inventory_Base: Static
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"CW95_Item_Move_Small"
		};
	};
	class ItemOptics: Inventory_Base
	{
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};
	};
	class Clothing_Base;
	class Edible_Base;
	class Book_Base;
	class Clothing: Clothing_Base{};
	class Switchable_Base;
	class Container_Base;
	class HouseNoDestruct;
	class TentBase;
	class Box_Base;
	class WorldContainer_Base;
	class Bottle_Base;
	class Transmitter_Base;
	class FishingRod_Base;
	class Powered_Base;
	class Trap_Base;
	class ItemBarrel;
	class ItemSuppressor;
	class FishingRod_Base_New: FishingRod_Base
	{
	};
	class BaseBuildingBase: Inventory_Base{};
	class TaloonBag_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class TortillaBag: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class CourierBag: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class FurCourierBag: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class ImprovisedBag: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class FurImprovisedBag: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class DryBag_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class HuntingBag: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class MountainBag_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"taloonbag_drop_SoundSet"
		};
	};
	class SmershBag: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class ChildBag_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class GhillieBushrag_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Cloth_Back_walkCro_ghillie_Soundset",
			"Cloth_Back_runCro_ghillie_Soundset",
			"Cloth_Back_walkErc_ghillie_Soundset",
			"Cloth_Back_walkRasErc_ghillie_Soundset",
			"Cloth_Back_runErc_ghillie_Soundset",
			"Cloth_Back_runRasErc_ghillie_Soundset",
			"Cloth_Back_sprintErc_ghillie_Soundset",
			"Cloth_Back_shortmove_ghillie_Soundset"
		};
	};
	class GhillieTop_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Cloth_Back_walkCro_ghillie_Soundset",
			"Cloth_Back_runCro_ghillie_Soundset",
			"Cloth_Back_walkErc_ghillie_Soundset",
			"Cloth_Back_walkRasErc_ghillie_Soundset",
			"Cloth_Back_runErc_ghillie_Soundset",
			"Cloth_Back_runRasErc_ghillie_Soundset",
			"Cloth_Back_sprintErc_ghillie_Soundset",
			"Cloth_Back_shortmove_ghillie_Soundset"
		};
	};
	class GhillieSuit_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Cloth_Back_walkCro_ghillie_Soundset",
			"Cloth_Back_runCro_ghillie_Soundset",
			"Cloth_Back_walkErc_ghillie_Soundset",
			"Cloth_Back_walkRasErc_ghillie_Soundset",
			"Cloth_Back_runErc_ghillie_Soundset",
			"Cloth_Back_runRasErc_ghillie_Soundset",
			"Cloth_Back_sprintErc_ghillie_Soundset",
			"Cloth_Back_shortmove_ghillie_Soundset"
		};
	};
	class LeatherSack_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"taloonbag_drop_SoundSet"
		};
	};
	class AssaultBag_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"taloonbag_drop_SoundSet"
		};
	};
	class CoyoteBag_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"taloonbag_drop_SoundSet"
		};
	};
	class AliceBag_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"taloonbag_drop_SoundSet"
		};
	};
	class LargeTentBackPack: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"mediumtent_drop_SoundSet"
		};
	};
	class CivilianBelt: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"WorkingGloves_pickup_SoundSet",
			"WorkingGloves_drop_SoundSet"
		};
	};
	class MilitaryBelt: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"WorkingGloves_pickup_SoundSet",
			"WorkingGloves_drop_SoundSet"
		};
	};
	class LeatherKnifeSheath: Clothing
	{	
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"WorkingGloves_pickup_SoundSet",
			"WorkingGloves_drop_SoundSet"
		};
	};
	class NylonKnifeSheath: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"WorkingGloves_pickup_SoundSet",
			"WorkingGloves_drop_SoundSet"
		};
	};
	class LeatherBelt_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"WorkingGloves_pickup_SoundSet",
			"WorkingGloves_drop_SoundSet"
		};
	};
	class SportGlasses_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"SportGlasses_pickup_SoundSet",
			"SportGlasses_drop_SoundSet"
		};
	};
	class AviatorGlasses: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"SportGlasses_pickup_SoundSet",
			"SportGlasses_drop_SoundSet"
		};
	};
	class DesignerGlasses: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"SportGlasses_pickup_SoundSet",
			"SportGlasses_drop_SoundSet"
		};
	};
	class ThickFramesGlasses: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"SportGlasses_pickup_SoundSet",
			"SportGlasses_drop_SoundSet"
		};
	};
	class ThinFramesGlasses: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"SportGlasses_pickup_SoundSet",
			"SportGlasses_drop_SoundSet"
		};
	};
	class TacticalGoggles: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"SportGlasses_pickup_SoundSet",
			"SportGlasses_drop_SoundSet"
		};
	};
	class NVGHeadstrap: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"WorkingGloves_pickup_SoundSet",
			"WorkingGloves_drop_SoundSet"
		};
	};
	class NVGoggles: ItemOptics
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};
	};
	class WorkingGloves_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"WorkingGloves_pickup_SoundSet",
			"WorkingGloves_drop_SoundSet"
		};
	};
	class TacticalGloves_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"WorkingGloves_pickup_SoundSet",
			"WorkingGloves_drop_SoundSet"
		};
	};
	class NBCGloves_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"WorkingGloves_pickup_SoundSet",
			"WorkingGloves_drop_SoundSet"
		};
	};
	class SurgicalGloves_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"WorkingGloves_pickup_SoundSet",
			"WorkingGloves_drop_SoundSet"
		};
	};
	class LeatherGloves_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"WorkingGloves_pickup_SoundSet",
			"WorkingGloves_drop_SoundSet"
		};
	};
	class OMNOGloves_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"WorkingGloves_pickup_SoundSet",
			"WorkingGloves_drop_SoundSet"
		};
	};
	class BallisticHelmet_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"BallisticHelmet_drop_SoundSet"
		};
	};
	class BaseballCap_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class ZSh3PilotHelmet: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_drop_SoundSet"
		};
	};
	class ConstructionHelmet_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_drop_SoundSet"
		};
	};
	class BurlapSackCover: Clothing
	{ 
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class BeanieHat_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class Ushanka_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class PumpkinHelmet: Clothing
	{ 
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class MotoHelmet_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_drop_SoundSet"
		};
	};
	class DarkMotoHelmet_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_drop_SoundSet"
		};
	};
	class Headtorch_ColorBase: Switchable_Base
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"WorkingGloves_pickup_SoundSet",
			"WorkingGloves_drop_SoundSet"
		};
	};
	class Bandana_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class BandanaHead_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class RadarCap_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class MilitaryBeret_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class FlatCap_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class ZmijovkaCap_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class CowboyHat_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class BoonieHat_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class OfficerHat: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class PoliceCap: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class PilotkaCap: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class TankerHelmet: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class GorkaHelmet: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_drop_SoundSet"
		};
	};
	class FirefightersHelmet_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_drop_SoundSet"
		};
	};
	class SkateHelmet_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_drop_SoundSet"
		};
	};
	class WeldingMask: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_drop_SoundSet"
		};
	};
	class PrisonerCap: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class GhillieHood_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Cloth_Back_walkCro_ghillie_Soundset",
			"Cloth_Back_runCro_ghillie_Soundset",
			"Cloth_Back_walkErc_ghillie_Soundset",
			"Cloth_Back_walkRasErc_ghillie_Soundset",
			"Cloth_Back_runErc_ghillie_Soundset",
			"Cloth_Back_runRasErc_ghillie_Soundset",
			"Cloth_Back_sprintErc_ghillie_Soundset",
			"Cloth_Back_shortmove_ghillie_Soundset"
		};
	};
	class LeatherHat_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class MedicalScrubsHat_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class GreatHelm: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"GreatHelm_drop_SoundSet"
		};
	};
	class Ssh68Helmet: Clothing
	{ 
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"BallisticHelmet_drop_SoundSet"
		};
	};
	class DirtBikeHelmet_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_drop_SoundSet"
		};
	};
	class DirtBikeHelmet_Visor: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_pickup_SoundSet"
		};
	};
	class DirtBikeHelmet_Mouthguard: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_pickup_SoundSet"
		};
	};
	class NBCHoodBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class HockeyHelmet_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_drop_SoundSet"
		};
	};
	class SantasHat: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class Mich2001Helmet: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"BallisticHelmet_drop_SoundSet"
		};
	};
	class GasMask: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_pickup_SoundSet"
		};
	};
	class BandanaMask_ColorBase: Clothing
	{	
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class NioshFaceMask: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class GP5GasMask: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_pickup_SoundSet"
		};
	};
	class AirborneMask: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_pickup_SoundSet"
		};
	};
	class GP5GasMask_Filter: Inventory_Base
	{	
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_pickup_SoundSet"
		};
	};
	class Balaclava3Holes_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_pickup_SoundSet"
		};
	};
	class SantasBeard: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class MouthRag: Clothing
	{	
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class SurgicalMask: Clothing
	{ 
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class HockeyMask: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_pickup_SoundSet"
		};
	};
	class Jeans_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class CargoPants_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class TTSKOPants: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class HunterPants_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class CanvasPants_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class CanvasPantsMidi_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class TrackSuitPants_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class GorkaPants_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class PolicePants: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class PolicePantsOrel: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class ParamedicPants_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class FirefightersPants_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class PrisonUniformPants: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class LeatherPants_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class MedicalScrubsPants_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class USMCPants_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class SlacksPants_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class CW95UPants: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class NBCPantsBase: Clothing
	{	
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class Breeches_ColorBase: Clothing
	{	
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class ShortJeans_ColorBase: Clothing
	{	
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class Skirt_ColorBase: Clothing
	{	
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class JumpsuitPants_ColorBase: Clothing
	{	
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};

	class AthleticShoes_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_pickup_SoundSet"
		};
	};
	class HikingBoots_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_drop_SoundSet"
		};
	};
	class HikingBootsLow_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_pickup_SoundSet"
		};
	};
	class Wellies_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_drop_SoundSet"
		};
	};
	class WorkingBoots_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_pickup_SoundSet"
		};
	};
	class JungleBoots_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_pickup_SoundSet"
		};
	};
	class DressShoes_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_pickup_SoundSet"
		};
	};
	class MilitaryBoots_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_drop_SoundSet"
		};
	};
	class CombatBoots_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_drop_SoundSet"
		};
	};
	class JoggingShoes_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_pickup_SoundSet"
		};
	};
	class LeatherShoes_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_pickup_SoundSet"
		};
	};
	class Sneakers_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_pickup_SoundSet"
		};
	};
	class NBCBootsBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_pickup_SoundSet"
		};
	};
	class Ballerinas_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_pickup_SoundSet"
		};
	};
	class TTSKOBoots: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_drop_SoundSet"
		};
	};
	class Armband_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_drop_SoundSet"
		};
	};
	class Sweater_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"AthleticShoes_drop_SoundSet"
		};
	};
	class Shirt_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class TShirt_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class Hoodie_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class TacticalShirt_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class HikingJacket_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class Raincoat_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class M65Jacket_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class TTsKOJacket_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class GorkaEJacket_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class RidersJacket_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class WoolCoat_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class TrackSuitJacket_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class PoliceJacket: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class PoliceJacketOrel: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class ParamedicJacket_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class FirefighterJacket_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class PrisonUniformJacket: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};		
	class MiniDress_ColorBase: Clothing
	{	
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class QuiltedJacket_ColorBase: Clothing
	{	
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class BomberJacket_ColorBase: Clothing
	{	
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};	
	class LeatherJacket_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class HuntingJacket_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class MedicalScrubsShirt_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class LabCoat: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class NurseDress_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class USMCJacket_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class Blouse_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class NBCJacketBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class DenimJacket: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class TelnyashkaShirt: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class ChernarusSportShirt: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class JumpsuitJacket_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class CW95UJacket: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class ManSuit_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class WomanSuit_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class LeatherShirt_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};	
	class PlateCarrierVest: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"SmershVest_pickup_SoundSet",
			"SmershVest_drop_SoundSet"
		};
	};	
	class SmershVest: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"SmershVest_pickup_SoundSet",
			"SmershVest_drop_SoundSet"
		};
	};	
	class PressVest_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"SmershVest_pickup_SoundSet",
			"SmershVest_drop_SoundSet"
		};
	};	
	class UKAssVest_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"SmershVest_pickup_SoundSet",
			"SmershVest_drop_SoundSet"
		};
	};
	class PoliceVest: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"SmershVest_pickup_SoundSet",
			"SmershVest_drop_SoundSet"
		};
	};
	class PlateCarrierHolster: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class ChestHolster: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class HighCapacityVest_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"SmershVest_pickup_SoundSet",
			"SmershVest_drop_SoundSet"
		};
	};
	class LeatherStorageVest_ColorBase: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class HuntingVest: Clothing
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class ReflexVest: Clothing
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class ItemBook: Book_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"taloonbag_drop_SoundSet"
		};
	};
	class MediumTent: TentBase
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpTent_SoundSet",
			"pickUpTentLight_SoundSet",
			"mediumtent_drop_SoundSet"
		};
	};
	class LargeTent: TentBase
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"mediumtent_movement_sprint_SoundSet",
			"mediumtent_drop_SoundSet"
		};
	};
	class CarTent: TentBase
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"mediumtent_movement_sprint_SoundSet",
			"mediumtent_drop_SoundSet"
		};
	};
	class PartyTent: TentBase
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpTent_SoundSet",
			"pickUpTentLight_SoundSet",
			"mediumtent_drop_SoundSet"
		};
	};
	class CamoNetShelter: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};
	};
	class FenceKit: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};
	};
	class WatchtowerKit: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};
	};
	class BarbedWire: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;		
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};
	};
	class CombinationLock: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovelLight_SoundSet"
		};
	};
	class CombinationLock4: CombinationLock
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovelLight_SoundSet"
		};
	};
	class CamoNet: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class SeaChest: Container_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpSeaChest_SoundSet",
			"seachest_movement_SoundSet"
		};
	};
	class WoodenCrate: Container_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpSeaChest_SoundSet",
			"seachest_movement_SoundSet"
		};
	};
	class Spotlight: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"powergenerator_movement_walk_SoundSet"
		};
	};
	class XmasLights: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};
	};
	class Refridgerator: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"powergenerator_movement_walk_SoundSet",
			"pickUpPowerGenerator_SoundSet"
		};
	};
	class PowerGenerator: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"powergenerator_movement_walk_SoundSet",
			"pickUpPowerGenerator_SoundSet"
		};
	};
	class CableReel: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"cablereel_drop_SoundSet"
		};
	};
	class BatteryCharger: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"batterycharger_drop_SoundSet"
		};
	};
	class HescoBox: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class Fabric: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class ShelterBase: TentBase
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"mediumtent_movement_walk_SoundSet"
		};
	};
	class TerritoryFlagKit: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};
	};
	class Flag_Base: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Shirt_pickup_SoundSet"
		};
	};
	class Paper: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpPaper_SoundSet"
		};
	};
	class DuctTape: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"rope_tieup_back_SoundSet"
		};
	};
	class Rag: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Bandage_loop_SoundSet"
		};
	};
	class BurlapStrip: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class Stone: Inventory_Base
	{

		
	};
	class SmallStone: Inventory_Base
	{
	};
	class Firewood: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"woodenlog_drop_SoundSet"
		};
	};
	class Battery9V: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};
	};
	class LargeGasCanister: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovelLight_SoundSet"
		};
	};
	class MediumGasCanister: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovelLight_SoundSet"
		};
	};
	class SmallGasCanister: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovelLight_SoundSet"
		};
	};
	class ButaneCanister: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovelLight_SoundSet"
		};
	};
	class Spraycan_ColorBase: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovelLight_SoundSet"
		};
	};
	class Matchbox: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"MatchOut_SoundSet"
		};
	};
	class NailBox: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};
	};
	class Roadflare: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};
	};
	class Chemlight_ColorBase: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};
	};
	class Pelt_Base: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class TannedLeather: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class Hook: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};
	};
	class BoneHook: Inventory_Base
	{
	};
	class Bark_ColorBase: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"bark_pickup_SoundSet",
			"bark_drop_SoundSet"
		};
	};
	class Nail: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"CW95_Bullet_Move_Smoll"
		};
	};
	class Bone: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};
	};
	class Bait: Inventory_Base
	{

	};
	class BoneBait: Inventory_Base
	{

	};
	class GardenLime: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpGardenLimeLight_SoundSet",
			"pickUpGardenLime_SoundSet"
		};
	};
	class Netting: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpPlantMaterial_SoundSet"
		};
	};
	class WoodenPlank: Inventory_Base
	{
		ItemMoveMinVolume = 1.0;
		ItemMoveMaxVolume = 2.0;
		ItemMoveSounds[] = 
		{
			"woodenlog_pickup_SoundSet"
		};
	};
	class MetalPlate: Inventory_Base
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"pickUpBackPack_Metal_SoundSet",
			"pickUpBackPack_Metal_Light_SoundSet"
		};
	};
	class WoodenLog: Inventory_Base
	{
		ItemMoveMinVolume = 1.0;
		ItemMoveMaxVolume = 2.0;
		ItemMoveSounds[] = 
		{
			"woodenlog_pickup_SoundSet"
		};
	};
	class Barrel_ColorBase: Container_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"barrel_drop_SoundSet"
		};
	};
	class Refrigerator: WorldContainer_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBarrelLight_SoundSet"
		};
	};
		
	class RefrigeratorMinsk: WorldContainer_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"barrel_drop_SoundSet"
		};
	};
	class TrashCan: WorldContainer_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBarrelLight_SoundSet"
		};
	};
	class FirstAidKit: Container_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class SmallProtectorCase: Container_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"smallprotectorcase_pickup_SoundSet"
		};
	};
	class PlateCarrierPouches: Container_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_SoundSet"
		};
	};
	class AmmoBox: Container_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammobox_drop_SoundSet"
		};
	};
	class Bear_ColorBase: Container_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_SoundSet"
		};
	};
	class WaterproofBag_ColorBase: Container_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpGardenLimeLight_SoundSet"
		};
	};
	class GiftBox_Base: Container_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_SoundSet"
		};
	};
	class FireplaceBase: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpFireplaceLight_SoundSet",
			"pickUpFireplace_SoundSet"
		};
	};
	class BarrelHoles_ColorBase: FireplaceBase
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"barrel_drop_SoundSet"
		};
	};
	class Pot: Bottle_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpPot_SoundSet",
			"pickUpPotLight_SoundSet"
		};
	};
	class FryingPan: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpPot_SoundSet",
			"pickUpPotLight_SoundSet"
		};
	};
	class PortableGasStove: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovelLight_SoundSet"
		};
	};
	class PortableGasLamp: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovelLight_SoundSet"
		};
	};
	class Candle: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};
	};
	class PetrolLighter: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};
	};
	class Tripod: Inventory_Base
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};
	};
	class BurlapSack: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class Rope: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"rope_struggle_SoundSet"
		};
	};
	class MetalWire: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;	
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};
	};
	class WoodenStick: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};
	};
	class Torch: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};
	};
	class ChickenFeather: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpPlantMaterial_SoundSet"
		};
	};
	class LongWoodenStick: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};
	};
	class SharpWoodenStick: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;	
		ItemMoveSounds[] = 
		{		
			"hatchet_pickup_SoundSet"
		};
	};
	class GorkaHelmetVisor: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"DarkMotoHelmet_pickup_SoundSet"
		};
	};
	class HandDrillKit: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;	
		ItemMoveSounds[] = 
		{
			"bark_drop_SoundSet"
		};
	};
	class Spear: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};
	};
	class SeedBase: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"seeds_pickup_SoundSet"
		};
	};
	class TomatoSeedsPack: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"seedpack_pickup_SoundSet"
		};
	};
	class PepperSeedsPack: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"seedpack_pickup_SoundSet"
		};
	};
	class PumpkinSeedsPack: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"seedpack_pickup_SoundSet"
		};
	};
	class ZucchiniSeedsPack: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"seedpack_pickup_SoundSet"
		};
	};
	class CannabisSeedsPack: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"seedpack_pickup_SoundSet"
		};
	};
	class PlantMaterial: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpPlantMaterial_SoundSet"
		};
	};
	class AntiPestsSpray: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBackPack_Plastic_Light_SoundSet"
		};
	};
	class Canteen: Bottle_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;	
		ItemMoveSounds[] = 
		{
			"WaterBottle_pickup_SoundSet"
		};
	};
	class WaterBottle: Bottle_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;	
		ItemMoveSounds[] = 
		{
			"WaterBottle_pickup_SoundSet"
		};
	};
	class Vodka: Bottle_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"SodaCan_drop_SoundSet"
		};
	};
	class WaterPouch_ColorBase: Bottle_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};
	};
	class SodaCan_ColorBase: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"SodaCan_pickup_SoundSet"
		};
	};
	class SodaCan_Empty: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"SodaCan_pickup_SoundSet"
		};
	};
	class BoxCerealCrunchin: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_BoxShake_Soundset"
		};
	};
	class PowderedMilk: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBloodBag_SoundSet"
		};
	};
	class SmallGuts: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class Guts: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class Rice: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class Marmalade: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Marmalade_pickup_SoundSet"
		};
	};
	class BakedBeansCan: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"BakedBeansCan_pickup_SoundSet"
		};
	};
	class BakedBeansCan_Opened: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"BakedBeansCan_pickup_SoundSet"
		};
	};
	class PeachesCan: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"BakedBeansCan_pickup_SoundSet"
		};
	};
	class PeachesCan_Opened: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"BakedBeansCan_pickup_SoundSet"
		};
	};
	class TacticalBaconCan: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"BakedBeansCan_pickup_SoundSet"
		};
	};
	class TacticalBaconCan_Opened: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"BakedBeansCan_pickup_SoundSet"
		};
	};
	class SpaghettiCan: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"BakedBeansCan_pickup_SoundSet"
		};
	};
	class SpaghettiCan_Opened: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"BakedBeansCan_pickup_SoundSet"
		};
	};
	class SardinesCan: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"BakedBeansCan_pickup_SoundSet"
		};
	};
	class SardinesCan_Opened: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"BakedBeansCan_pickup_SoundSet"
		};
	};
	class TunaCan: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"BakedBeansCan_pickup_SoundSet"
		};
	};
	class TunaCan_Opened: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"BakedBeansCan_pickup_SoundSet"
		};
	};
	class Apple: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Apple_pickup_SoundSet"
		};
	};
	class Plum: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class Pear: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class Banana: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class Orange: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class Tomato: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class GreenBellPepper: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class Zucchini: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class Pumpkin: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class SlicedPumpkin: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class Potato: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class Kiwi: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class SambucusBerry: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class CaninaBerry: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class Cannabis: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Zucchini_pickup_SoundSet"
		};
	};
	class HumanSteakMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class GoatSteakMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class MouflonSteakMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class BoarSteakMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class PigSteakMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class DeerSteakMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class WolfSteakMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class BearSteakMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class CowSteakMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class SheepSteakMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class FoxSteakMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class ChickenBreastMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class RabbitLegMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class CarpFilletMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class MackerelFilletMeat: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class Lard: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class Carp: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class Sardines: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class Mackerel: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class Worm: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class MushroomBase: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Eating_TakeFood_Soundset"
		};
	};
	class BandageDressing: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Bandage_loop_SoundSet"
		};
	};
	class DisinfectantSpray: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBackPack_Plastic_Light_SoundSet"
		};
	};
	class DisinfectantAlcohol: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"SodaCan_drop_SoundSet"
		};
	};
	class PurificationTablets: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"purificationtablets_pickup_SoundSet"
		};
	};
	class CharcoalTablets: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"purificationtablets_pickup_SoundSet"
		};
	};
	class PainkillerTablets: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"purificationtablets_pickup_SoundSet"
		};
	};
	class VitaminBottle: Edible_Base
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"vitaminbottle_pickup_SoundSet"
		};
	};
	class TetracyclineAntibiotics: Edible_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"purificationtablets_pickup_SoundSet"
		};
	};
	class Epinephrine: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBackPack_Plastic_Light_SoundSet"
		};
	};
	class Morphine: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBackPack_Plastic_Light_SoundSet"
		};
	};
	class Syringe: Epinephrine
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Syringe_splash_SoundSet"
		};
	};
	class ClearSyringe: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Syringe_splash_SoundSet"
		};
	};
	class BloodSyringe: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Syringe_splash_SoundSet"
		};
	};
	class InjectionVial: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"injectionvial_pickup_SoundSet"
		};
	};
	class SalineBag: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBloodBag_SoundSet"
		};
	};
	class StartKitIV: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBloodBag_SoundSet"
		};
	};
	class SalineBagIV: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBloodBag_SoundSet"
		};
	};
	class BloodBagEmpty: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBloodBag_SoundSet"
		};
	};
	class BloodBagFull: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBloodBag_SoundSet"
		};
	};
	class BloodBagIV: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBloodBag_SoundSet"
		};
	};
	class BloodTestKit: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBloodBag_SoundSet"
		};
	};
	class Splint: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};
	};
	class Thermometer: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};
	};
	class Defibrillator: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"sewingkit_pickup_SoundSet"
		};
	};
	class CigarettePack_ColorBase: Inventory_Base
	{	
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"sewingkit_pickup_SoundSet"
		};
	};
	class ItemMap: Inventory_Base
	{
	};
	class ItemCompass: Inventory_Base
	{
	};
	class ChernarusMap: ItemMap
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpPaper_SoundSet"
		};	
	};
	class Compass: ItemCompass
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"compass_open_SoundSet", 
			"compass_close_SoundSet" 
		};	
	};
	class Rangefinder: ItemOptics
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class Binoculars: ItemOptics
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class PersonalRadio: Transmitter_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class BaseRadio: Transmitter_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class Megaphone: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_drop_SoundSet"
		};	
	};
	class Radio: Inventory_Base
	{	
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_drop_SoundSet"
		};	
	};
	class Flashlight: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class Pen_ColorBase: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class CanOpener: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class Heatpack: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class MessTin: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_drop_SoundSet"
		};	
	};
	class Pliers: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpPliers_SoundSet"
		};	
	};
	class Lockpick: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"lockpicker_move_in_SoundSet",
			"lockpicker_move_out_SoundSet"
		};	
	};
	class WeaponCleaningKit: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_drop_SoundSet"
		};	
	};
	class SewingKit: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"sewingkit_pickup_SoundSet"
		};	
	};
	class LeatherSewingKit: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"sewingkit_pickup_SoundSet"
		};	
	};
	class Handcuffs: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"sewingkit_pickup_SoundSet"
		};	
	};
	class HandcuffKeys: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class Cassette: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class Shovel: Inventory_Base
	{
		ItemMoveMinVolume = 0.05;
		ItemMoveMaxVolume = 0.3;	
		ItemMoveSounds[] = 
		{
			"pickUpShovel_SoundSet"
		};	
	};
	class FieldShovel: Inventory_Base
	{
		ItemMoveMinVolume = 0.05;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_light_SoundSet"
		};	
	};
	class Crowbar: Inventory_Base
	{
		ItemMoveMinVolume = 0.05;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"pickUpShovel_SoundSet"
		};	
	};
	class FireExtinguisher: Inventory_Base
	{
		ItemMoveMinVolume = 0.05;
		ItemMoveMaxVolume = 0.2;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class Hammer: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};	
	};
	class MeatTenderizer: Inventory_Base
	{
		ItemMoveMinVolume = 0.05;
		ItemMoveMaxVolume = 0.2;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class Wrench: Inventory_Base
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class LugWrench: Inventory_Base
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_light_SoundSet"
		};	
	};
	class Pipe: Inventory_Base
	{
		ItemMoveMinVolume = 0.05;
		ItemMoveMaxVolume = 0.2;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class Screwdriver: Inventory_Base
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class Sickle: Inventory_Base
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.15;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class Hacksaw: Inventory_Base
	{
		ItemMoveMinVolume = 0.05;
		ItemMoveMaxVolume = 0.2;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class KitchenKnife: Inventory_Base
	{
		ItemMoveMinVolume = 0.05;
		ItemMoveMaxVolume = 0.2;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class SteakKnife: Inventory_Base
	{
		ItemMoveMinVolume = 0.05;
		ItemMoveMaxVolume = 0.2;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class HayHook: Inventory_Base
	{
		ItemMoveMinVolume = 0.05;
		ItemMoveMaxVolume = 0.2;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class StoneKnife: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};
	};
	class Mace: Inventory_Base
	{
		ItemMoveMinVolume = 0.05;
		ItemMoveMaxVolume = 0.2;
		ItemMoveSounds[] = 
		{
			"pickUpShovel_SoundSet"
		};	
	};
	class FarmingHoe: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovel_SoundSet"
		};	
	};
	class ImprovisedFishingRod: FishingRod_Base_New
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};	
	};
	class ObsoleteFishingRod: FishingRod_Base_New
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class FishingRod: FishingRod_Base_New
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class SledgeHammer: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovel_SoundSet"
		};	
	};
	class Iceaxe: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovel_SoundSet"
		};	
	};
	class Broom: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovel_SoundSet"
		};	
	};
	class Paddle: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovel_SoundSet"
		};	
	};
	class ElectronicRepairKit: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"sewingkit_drop_SoundSet"
		};	
	};
	class EpoxyPutty: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;	
		ItemMoveSounds[] = 
		{
			"pickUpBackPack_Plastic_Light_SoundSet"
		};	
	};
	class Whetstone: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet" 
		};	
	};
	class HandSaw: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpBackPack_Plastic_Light_SoundSet"
		};	
	};
	class BearTrap: Trap_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"beartrap_movement_walk_SoundSet"
		};	
	};
	class LandMineTrap: Trap_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class SmallFishTrap: Trap_Base
	{	
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;	
		ItemMoveSounds[] = 
		{
			"WaterBottle_pickup_SoundSet"
		};	
	};
	class FishNetTrap: Trap_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCourierBag_Light_SoundSet"
		};	
	};
	class TripwireTrap: Trap_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};	
	};
	class RabbitSnareTrap: Trap_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};	
	};
	class TruckBattery: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"carbattery_drop_SoundSet"
		};	
	};
	class CarBattery: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"carbattery_drop_SoundSet"
		};	
	};
	class BrakeFluid: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"engineoil_pickup_SoundSet"
		};	
	};
	class EngineOil: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"engineoil_pickup_SoundSet"
		};	
	};
	class CarRadiator: Inventory_Base
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"pickUpBackPack_Metal_SoundSet",
			"pickUpBackPack_Metal_Light_SoundSet"
		};	
	};
	class HeadlightH7: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class HeadlightH7_Box: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class SparkPlug: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"	
		};	
	};
	class TireRepairKit: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"smallprotectorcase_pickup_SoundSet"	
		};	
	};
	class CanisterGasoline: Bottle_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCanisterGasolineLight_SoundSet",
			"pickUpCanisterGasoline_SoundSet"
		};	
	};
	class CarWheel: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchbackwheel_drop_SoundSet"
		};	
	};
	class CarDoor: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchbackdoors_driver_pickup_SoundSet"
		};	
	};
	class AmmoBox_556x45_20Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_556x45Tracer_20Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_308Win_20Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_308WinTracer_20Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_762x54_20Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_762x54Tracer_20Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_762x39_20Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_762x39Tracer_20Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_22_50Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_357_20Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_45ACP_25rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_9x19_25rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_380_35rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_00buck_10rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_12gaSlug_10Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_12gaRubberSlug_10Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_12gaBeanbag_10Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_545x39_20Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_545x39Tracer_20Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_9x39AP_20Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class AmmoBox_9x39_20Rnd: Box_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"ammoboxUnpack_SoundSet"
		};	
	};
	class UniversalLight: Switchable_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class TLRLight: Switchable_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class AK_Bayonet: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"CombatKnife_drop_SoundSet"
		};	
	};
	class M9A1_Bayonet: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"CombatKnife_drop_SoundSet"
		};	
	};
	class Mosin_Bayonet: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"CombatKnife_drop_SoundSet"
		};	
	};
	class SKS_Bayonet: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"CombatKnife_drop_SoundSet"
		};	
	};
	class Mosin_Compensator: ItemSuppressor
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class MP5_Compensator: ItemSuppressor
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class ImprovisedSuppressor: ItemSuppressor
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;	
		ItemMoveSounds[] = 
		{
			"WaterBottle_pickup_SoundSet"
		};	
	};
	class M4_Suppressor: ItemSuppressor
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class AK_Suppressor: ItemSuppressor
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class PistolSuppressor: ItemSuppressor
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class MakarovPBSuppressor: ItemSuppressor
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class M4_OEBttstck: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class M4_MPBttstck: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class M4_CQBBttstck: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class AK_WoodBttstck: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class AK74_WoodBttstck: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class AK_FoldingBttstck: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class AK_PlasticBttstck: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class AKS74U_Bttstck: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class MP5k_StockBttstck: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class Red9Bttstck: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class Fal_OeBttstck: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class Fal_FoldingBttstck: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class Saiga_Bttstck: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class M4_PlasticHndgrd: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class M4_RISHndgrd: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class M4_MPHndgrd: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class AK_WoodHndgrd: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class AK74_Hndgrd: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class AK_RailHndgrd: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class AK_PlasticHndgrd: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class MP5_PlasticHndgrd: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class MP5_RailHndgrd: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class M249_Hndgrd: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class M249_RisHndgrd: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class AtlasBipod: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class M249_Bipod: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpCableReelLight_SoundSet"
		};	
	};
	class GhillieAtt_ColorBase: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Cloth_Back_walkCro_ghillie_Soundset",
			"Cloth_Back_runCro_ghillie_Soundset",
			"Cloth_Back_walkErc_ghillie_Soundset",
			"Cloth_Back_walkRasErc_ghillie_Soundset",
			"Cloth_Back_runErc_ghillie_Soundset",
			"Cloth_Back_runRasErc_ghillie_Soundset",
			"Cloth_Back_sprintErc_ghillie_Soundset",
			"Cloth_Back_shortmove_ghillie_Soundset"
		};	
	};
	class Grenade_Base: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class WoodAxe: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovel_SoundSet"
		};	
	};
	class Hatchet: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_light_SoundSet"
		};	
	};
	class FirefighterAxe: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovel_SoundSet"
		};	
	};
	class Cleaver: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};	
	};
	class CombatKnife: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"CombatKnife_drop_SoundSet"
		};	
	};
	class HuntingKnife: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"CombatKnife_drop_SoundSet"
		};	
	};
	class Machete: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"CombatKnife_drop_SoundSet"
		};	
	};
	class Pitchfork: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet"
		};	
	};
	class Pickaxe: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovel_SoundSet"
		};	
	};
	class Sword: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpShovel_SoundSet"
		};	
	};
	class BaseballBat: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet",
			"hatchet_pickup_light_SoundSet"
		};	
	};
	class NailedBaseballBat: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet",
			"hatchet_pickup_light_SoundSet"
		};	
	};
	class PipeWrench: Inventory_Base
	{
		ItemMoveMinVolume = 0.05;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class BrassKnuckles_ColorBase: Inventory_Base
	{
		ItemMoveMinVolume = 0.05;
		ItemMoveMaxVolume = 0.2;
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class TelescopicBaton: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"Baton_deploy_SoundSet"
		};	
	};
	class HockeyStick: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet",
			"hatchet_pickup_light_SoundSet"
		};	
	};
	class NewHockeyStick: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet",
			"hatchet_pickup_light_SoundSet"
		};	
	};
	class PoliceBaton: Inventory_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet",
			"hatchet_pickup_light_SoundSet"
		};	
	};
	class Chainsaw: Switchable_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"pickUpPowerGenerator_SoundSet"
		};	
	};
	class CattleProd: Powered_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet",
			"hatchet_pickup_light_SoundSet"
		};	
	};
	class StunBaton: Powered_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"hatchet_pickup_SoundSet",
			"hatchet_pickup_light_SoundSet"
		};	
	};
};

class CfgMagazines
{
	class DefaultMagazine;
	class Magazine_Base: DefaultMagazine
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"MagRifle_empty_in_SoundSet"
		};	
	};
	class Ammunition_Base: Magazine_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"CW95_Bullet_Move_Smoll"
		};	
	};
	class Ammo_12gaPellets: Ammunition_Base
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"CW95_ShotgunShell_Move_Smoll"
		};	
	};
	class Ammo_12gaSlug: Ammunition_Base
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"CW95_ShotgunShell_Move_Smoll"
		};	
	};
	class Ammo_12gaRubberSlug: Ammunition_Base
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"CW95_ShotgunShell_Move_Smoll"
		};	
	};
	class Ammo_12gaBeanbag: Ammunition_Base
	{
		ItemMoveMinVolume = 0.1;
		ItemMoveMaxVolume = 0.3;
		ItemMoveSounds[] = 
		{
			"CW95_ShotgunShell_Move_Smoll"
		};	
	};
	class Ammo_Flare: Ammunition_Base
	{
		ItemMoveMinVolume = 0.2;
		ItemMoveMaxVolume = 0.4;
		ItemMoveSounds[] = 
		{
			"CW95_ShotgunShell_Move_Smoll"
		};	
	};
	class Ammo_ArrowComposite: Ammunition_Base
	{
		ItemMoveSounds[] = 
		{
			"CW95_Item_Move_Small"
		};	
	};
	class Ammo_SharpStick: Ammunition_Base
	{
		ItemMoveSounds[] = 
		{
			"CW95_Item_Move_Small"
		};	
	};
	class Ammo_ArrowPrimitive: Ammunition_Base
	{
		ItemMoveSounds[] = 
		{
			"CW95_Item_Move_Small"
		};	
	};
	class Ammo_ArrowBoned: Ammunition_Base
	{
		ItemMoveSounds[] = 
		{
			"CW95_Item_Move_Small"
		};	
	};
	class Ammo_ArrowBolt: Ammunition_Base
	{
		ItemMoveSounds[] = 
		{
			"CW95_Item_Move_Small"
		};	
	};
	class Ammo_DartSyringe: Ammunition_Base
	{
		ItemMoveSounds[] = 
		{
			"CW95_Item_Move_Small"
		};	
	};
	class Mag_357Speedloader_6Rnd: Magazine_Base
	{
		ItemMoveSounds[] = 
		{
			"PSO11Optic_pickup_SoundSet"
		};	
	};
	class Mag_CLIP762x54_5Rnd: Magazine_Base
	{
		ItemMoveSounds[] = 
		{
			"CW95_Bullet_Move_Smoll"
		};	
	};
	class Mag_762x54Snaploader_2Rnd: Magazine_Base
	{
		ItemMoveSounds[] = 
		{
			"CW95_Bullet_Move_Smoll"
		};	
	};
	class Mag_308WinSnaploader_2Rnd: Magazine_Base
	{
		ItemMoveSounds[] = 
		{
			"CW95_Bullet_Move_Smoll"
		};	
	};
	class Mag_CLIP762x39_10Rnd: Magazine_Base
	{
		ItemMoveSounds[] = 
		{
			"CW95_Bullet_Move_Smoll"
		};	
	};
	class Mag_CLIP9x19_10Rnd: Magazine_Base
	{
		ItemMoveSounds[] = 
		{
			"CW95_Bullet_Move_Smoll"
		};	
	};
	class Mag_12gaSnaploader_2Rnd: Magazine_Base
	{
		ItemMoveSounds[] = 
		{
			"CW95_ShotgunShell_Move_Smoll"
		};	
	};
};
