class CfgPatches
{
	class CW95_Objects_Overrides
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters_Vests",
			"DZ_Gear_Consumables",
			"DZ_Gear_Containers",
			"DZ_Weapons_Magazines",
			"DZ_Weapons_Melee",
			"DZ_Animals_ursus_arctos",

			"DayZExpansion_Core_Objects_CircuitBoard",
			"DayZExpansion_Core_Objects_Currencies",
			"DayZExpansion_Objects_Firearms_RPG7",
			"DayZExpansion_Objects_Gear_Guitar",
			"DayZExpansion_Market_Objects",
			"DayZExpansion_Objects_Misc",

			"CJ_Passport",
			"TF_Magazine_AK",
			"MuchDecos_Standalone",
			"CannabisPlus_Cigarette",
			"Pizzaria"
		};
	};
};

class CfgSlots
{
	class Slot_ExpansionMoney
	{
		name="ExpansionMoney";
		displayName="";
		selection="ExpansionMoney";
	};
};

class cfgWeapons
{
	class ExpansionRPG7Base;
	class ExpansionRPG7: ExpansionRPG7Base
	{
		weight=5200;
		itemSize[] = {9,6};
	};
	class Rifle_Base;
	class AK74_Base: Rifle_Base
	{
		magazines[]+=
		{
			"TF_Mag_AK74_Plastic30Rnd",
			"TF_Mag_AK74_Plum30Rnd",
			"TF_Mag_AK74_Bakelit30Rnd"
		};
	};
};

class CfgVehicles
{
	// Add backpack slot to Large Tent (LargeTent.c converts it into backpack version)
	class TentBase;
	class LargeTent : TentBase
	{
		inventorySlot[] +=
		{
			"Back"
		};
		itemInfo[] +=
		{
			"Clothing",
			"Back"
		};
	};

	// Define large tent backpack object
	class Clothing;
	class LargeTentBackpack : Clothing
	{
		scope = 2;
		displayName = "$STR_ZEN_LARGETENT0";
		descriptionShort = "$STR_ZEN_LARGETENT1";
		model = "\dz\gear\camping\large_tent_backpack.p3d";
		inventorySlot[] +=
		{
			"Back"
		};
		itemInfo[] +=
		{
			"Clothing",
			"Back"
		};
		rotationFlags = 16;
		itemSize[] = { 10,4 };
		itemsCargoSize[] = { 0,0 };
		weight = 90000;
		varWetMax = 0.49000001;
		heatIsolation = 0.69999999;
		visibilityModifier = 0.80000001;
		soundAttType = "Military";
		randomQuantity = 4;
		class ClothingTypes
		{
			male = "dz\gear\camping\large_tent_backpack.p3d";
			female = "dz\gear\camping\large_tent_backpack.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 2000;
					transferToAttachmentsCoef = 0.5;
					healthLevels[] =
					{

						{
							1,

							{
								"DZ\gear\camping\data\bagpack.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\gear\camping\data\bagpack.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\gear\camping\data\bagpack_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\gear\camping\data\bagpack_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\gear\camping\data\bagpack_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet = "pickUpBackPack_Metal_Light_SoundSet";
					id = 796;
				};
				class pickUpItem
				{
					soundSet = "pickUpBackPack_Metal_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "taloonbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class PoliceVest;
	class PoliceVest_Black: PoliceVest
	{
		itemsCargoSize[]={6,7};
    };
	/*
	// msp ou dex ou willstride
	class Defender_Vest_Black: TODO
	{
		itemsCargoSize[]={6,7};
    };
	*/

    class Inventory_Base;
	class ExpansionMoneyBanknote_Base: Inventory_Base
	{
		canBeSplit=1;
		inventorySlot[]+=
		{
			"ExpansionMoney"
		};
    };
	class ExpansionBanknoteUSD: ExpansionMoneyBanknote_Base
	{
		weight=0;
	};
	class ExpansionBanknoteEuro: ExpansionMoneyBanknote_Base
	{
		weight=0;
	};
	class ExpansionBanknoteHryvnia: ExpansionMoneyBanknote_Base
	{
		weight=0;
	};

	class CP_Cigarette: Inventory_Base
	{
		inventorySlot[]+=
		{
			"Mask"
		};
	};

	class cigarette_mung: Clothing
	{
		inventorySlot[]+=
		{
			"Mask"
		};
	};
	class CJ_Pass: Inventory_Base
	{
		attachments[]+=
		{
			"ExpansionMoney"
		};
    };
	//!--------------- MuchDecos ---------------
	class MD_Item;
	class MD_TV: MD_Item
	{
		itemsSize[]={6,5};
		displayName = "$STR_CW95_MD_TV_NAME";
		descriptionShort = "$STR_CW95_MD_TV_DESC";
	};
	class MD_Radio: MD_Item
	{
		itemsSize[]={4,3};
		displayName = "$STR_CW95_MD_Radio_NAME";
		descriptionShort = "$STR_CW95_MD_Radio_DESC";
	};
	class MD_OldRadio: MD_Item
	{
		itemsSize[]={3,3};
		displayName = "$STR_CW95_MD_OldRadio_NAME";
		descriptionShort = "$STR_CW95_MD_OldRadio_DESC";
	};
	
	//!--------------- DAYZ EXPANSION ---------------
	class ExpansionCircuitBoardBase;
	class ExpansionCircuitBoard_MK1: ExpansionCircuitBoardBase
	{
		displayName = "$STR_CW95_ExpansionCircuitBoard_MK1_NAME";
		descriptionShort = "$STR_CW95_ExpansionCircuitBoard_MK1_DESC";
	};
	class ExpansionCircuitBoard_MK2: ExpansionCircuitBoardBase
	{
		displayName = "$STR_CW95_ExpansionCircuitBoard_MK2_NAME";
		descriptionShort = "$STR_CW95_ExpansionCircuitBoard_MK2_DESC";
	};
	class ExpansionCircuitBoard_MK3: ExpansionCircuitBoardBase
	{
		displayName = "$STR_CW95_ExpansionCircuitBoard_MK3_NAME";
		descriptionShort = "$STR_CW95_ExpansionCircuitBoard_MK3_DESC";
	};

	class ExpansionMoneyBar_Base;
	class ExpansionSilverBar: ExpansionMoneyBar_Base
	{
		descriptionShort = "$STR_CW95_ExpansionSilverBar_DESC";
	};
	class ExpansionGoldBar: ExpansionMoneyBar_Base
	{
		descriptionShort = "$STR_CW95_ExpansionGoldBar_DESC";
	};
	class ExpansionSilverNugget: ExpansionMoneyBar_Base
	{
		descriptionShort = "$STR_CW95_ExpansionSilverNugget_DESC";
	};
	class ExpansionGoldNugget: ExpansionMoneyBar_Base
	{
		descriptionShort = "$STR_CW95_ExpansionGoldNugget_DESC";
	};

	class Pliers;
	class ExpansionBoltCutters: Pliers
	{
		displayName = "$STR_CW95_ExpansionBoltCutters_NAME";
		descriptionShort = "$STR_CW95_ExpansionBoltCutters_DESC";
	};
	class Expansion_Guitar: Inventory_Base
	{
		displayName = "$STR_CW95_Expansion_Guitar_NAME";
		descriptionShort = "$STR_CW95_Expansion_Guitar_DESC";
	};
	class Expansion_Guitar_Old: Expansion_Guitar
	{
		displayName = "$STR_CW95_Expansion_Guitar_Old_NAME";
		descriptionShort = "$STR_CW95_Expansion_Guitar_Old_DESC";
	};
	
	//!--------------- Air Raid ---------------
	class HouseNoDestruct;
	class CW95_TU95: Inventory_Base
	{
		scope=1;
		model="AirRaid\model\tucko.p3d";
		forceFarBubble="true";
	};
	class CW95_Mig21: Inventory_Base
	{
		scope=1;
		model="AirRaid\model\Mig21.p3d";
		forceFarBubble="true";
	};
	class CW95_Mi24: Inventory_Base
	{
		scope=1;
		model="AirRaid\model\Mi24.p3d";
		forceFarBubble="true";
	};
	/*
	class CW95_Mi8: HouseNoDestruct
	{
		scope=1;
		model=".p3d";
	};
	*/
	class CW95_Mi6: Inventory_Base
	{
		scope=1;
		model="AirRaid\model\Mi6.p3d";
		forceFarBubble="true";
	};
	class Expansion_RPG_Explosion: HouseNoDestruct
	{
		scope=2;
		model="\DZ\data\lightpoint.p3d";
		ammoType="CW95_ProjectileRPG_Ammo";
	};
	class CW95_Rocket_Explosion: HouseNoDestruct
	{
		scope=2;
		model="\DZ\data\lightpoint.p3d";
		ammoType="CW95_ProjectileRocket_Ammo";
	};
	class Roadflare;
	class CW95_ProjectileRocket: Roadflare
	{
		scope=2;
		model = "\dz\weapons\ammunition\rocket_rpg7_inflight.p3d";
	};
	
	class Raz_Pizza_Base;
	class Raz_WolfSteakMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Shashlik";
	};
	class Raz_BoarSteakMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Shashlik";
	};
	class Raz_DeerSteakMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Shashlik";
	};
	class Raz_SheepSteakMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "L'Imigrovitch";
	};
	class Raz_GoatSteakMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Krasnovitch";
	};
	class Raz_BearSteakMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Krasnovitch";
	};
	class Raz_FoxSteakMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Krasnovitch";
	};
	class Raz_CowSteakMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Krasnovitch";
	};
	class Raz_Cheese_Pizza: Raz_Pizza_Base
	{
		displayName = "La Randoneuse";
	};
	class Raz_ChickenBreastMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Blaskovitch";
	};
	class Raz_HumanSteakMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Akimov";
	};
	class Raz_Mushroom_Pizza: Raz_Pizza_Base
	{
		displayName = "La Clodovitch";
	};
	class Raz_CarpFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_MackerelFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_PikeFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_CodFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_SalmonFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_apokot_big_silver_crucian_fillet_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_apokot_pike_fillet_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_CrayfishFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_NorthanpikeFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_LargemouthbassFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_WhitebassFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_BlackbassFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_TroutFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_BrownTroutFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_BrookTroutFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_LakeTroutFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_CutthroatTroutFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_PerchFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_CatfishFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_MinnowFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_BluegillFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_SaugerFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_BowfinFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_SlimysculpinFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_AngelfishFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_AsianseabassFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_BluemarlinFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_BonitaFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_CherrysalmonFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_FlatheadmulletFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_LeopardsharkFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_PacificcodFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_RedheadcichlidFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_RoughneckrockFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_SeverumFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_ShrimpFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_BluetangFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_HairtailfishFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_HumpheadwrasseFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_SiamesetigerfishFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_ClamFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_MusselFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_Blackdevilsnail_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_KingcrabFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_JellyfishFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_LobsterFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_GreatwhitesharkFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_AngelsharkFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
	class Raz_geb_YellowfintunaFilletMeat_Pizza: Raz_Pizza_Base
	{
		displayName = "La Berez";
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyExpansionMoney: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"ExpansionMoney"
		};
	};
};

class CfgAmmo
{
	class DefaultAmmo;
	class CW95_ProjectileRocket_Ammo: DefaultAmmo
	{
		indirectHit=1;
		indirectHitRange=3;
		explosive=1;
		typicalSpeed=3;
		initSpeed=3;
		simulation="shotShell";
		simulationStep=0.050000001;
		soundSetExplosion[]=
		{
			"Grenade_explosion_SoundSet",
			"Grenade_Tail_SoundSet"
		};
		class DamageApplied
		{
			type="FragGrenade";
			bleedThreshold=0.40000001;
			class Health
			{
				damage=5;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=50;
			};
		};
		class NoiseExplosion
		{
			strength=100;
			type="shot";
		};
	};
	class CW95_ProjectileRPG_Ammo: DefaultAmmo
	{
		indirectHit=1;
		indirectHitRange=3;
		explosive=1;
		typicalSpeed=3;
		initSpeed=3;
		simulation="shotShell";
		simulationStep=0.050000001;
		soundSetExplosion[]=
		{
			"Grenade_explosion_SoundSet",
			"Grenade_Tail_SoundSet"
		};
		class DamageApplied
		{
			type="FragGrenade";
			bleedThreshold=0.40000001;
			class Health
			{
				damage=60;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=70;
			};
		};
		class NoiseExplosion
		{
			strength=100;
			type="shot";
		};
	};
};

class CfgMagazines
{
	class Ammunition_Base;
	class ExpansionAmmoRPG: Ammunition_Base
	{
		scope = 2;
		displayName = "$STR_EXPANSION_RPG7_WARHEAD";
		descriptionShort = "$STR_EXPANSION_RPG7_WARHEAD_DESC";
		model="DayZExpansion\Objects\Weapons\Firearms\RPG7\fx\rpg7_ammoheat_round.p3d";
		rotationFlags = 34;
		itemSize[] = {4,2};
		weight = 2400;
		count = 1;
		ammo = "ExpansionRocketRPG";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = {{1.0,{"DZ\weapons\launchers\law\data\law_rocket.rvmat"}},{0.7,{"DZ\weapons\launchers\law\data\law_rocket.rvmat"}},{0.5,{"DZ\weapons\launchers\law\data\law_rocket_damage.rvmat"}},{0.3,{"DZ\weapons\launchers\law\data\law_rocket_damage.rvmat"}},{0.0,{"DZ\weapons\launchers\law\data\law_rocket_destruct.rvmat"}}};
				};
			};
		};
	};
};