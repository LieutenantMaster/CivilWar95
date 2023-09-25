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
			"DayZExpansion_Objects_Gear_Guitar",
			"DayZExpansion_Market_Objects",
			"DayZExpansion_Objects_Misc",

			"CJ_Passport",
			"TF_Magazine_AK",
			"MuchDecos_Standalone",
			"CannabisPlus_Cigarette"
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

class CfgVehicles
{
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
			"ExpansionMoney"
		};
	};

	class Clothing;
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
			"Mask"
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
};
