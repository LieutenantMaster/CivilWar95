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
			"DayZExpansion_Objects_Misc",

			"CJ_Passport"
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

class CfgMagazines
{
    class DefaultMagazine;
	class Magazine_Base: DefaultMagazine
	{
		inventorySlot[]+=
		{
			"VestGrenadeA",
			"VestGrenadeB",
			"VestGrenadeC",
			"VestGrenadeD"
		};
    };
};

class CfgVehicles
{
    class Inventory_Base;
	class Container_Base;
	class Clothing;
	class HouseNoDestruct;

	class PoliceVest;
	class CigarettePack_ColorBase;
	class Pliers;

	class ExpansionCircuitBoardBase;
	class ExpansionMoneyBar_Base;

	class Projectile;
	class ArmorType;
	class Melee;
	class Zone_Head;
	class Health;
	
	class AnimalBase;
	class Animal_UrsusArctos: AnimalBase
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=1400;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
				class Blood
				{
					hitpoints=8750;
				};
				class Shock
				{
					hitpoints=8750;
				};
			};
			class DamageZones
			{
				class Zone_Head
				{
					componentNames[]=
					{
						"Zone_Head"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.1;
					canBleed=0;
					class Health
					{
						hitpoints=440;
						transferToGlobalCoef=1;
					};
					class Blood: Health
					{
						hitpoints=8750;
					};
					class Shock: Health
					{
						hitpoints=8750;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=0.50999999;
							};
						};
						class Projectile: Melee
						{
							class Health: Health
							{
								damage=0.25;
							};
						};
						class FragGrenade: Melee
						{
						};
					};
				};
				class Zone_Neck: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Neck"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.1;
					class Health
					{
						hitpoints=525;
						transferToGlobalCoef=1;
					};
					class ArmorType: ArmorType
					{
						class Melee: Melee
						{
							class Health: Health
							{
								damage=0.15000001;
							};
						};
						class Projectile: Projectile
						{
							class Health: Health
							{
								damage=0.25;
							};
						};
					};
				};
				class Zone_Belly: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Belly"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.0099999998;
					class Health: Health
					{
						hitpoints=700;
					};
					class ArmorType: ArmorType
					{
						class Melee: Melee
						{
							class Health: Health
							{
								damage=0.15000001;
							};
						};
					};
				};
				class Zone_Pelvis: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Pelvis"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.0099999998;
					class Health: Health
					{
						hitpoints=875;
					};
					class ArmorType: ArmorType
					{
						class Melee: Melee
						{
							class Health: Health
							{
								damage=0.15000001;
							};
						};
					};
				};
				class Zone_Legs: Zone_Head
				{
					componentNames[]=
					{
						"Zone_Legs"
					};
					transferToZonesNames[]={};
					transferToZonesCoefs[]={};
					fatalInjuryCoef=0.0099999998;
					class Health: Health
					{
						hitpoints=350;
						transferToGlobalCoef=0;
					};
				};
			};
		};
	};

	class PoliceVest_Black: PoliceVest
	{
		itemsCargoSize[]={6,7};
    };
	/*
	class Defender_Vest_Black: TODO
	{
		itemsCargoSize[]={6,7};
    };
	*/

	class ExpansionMoneyBanknote_Base: Inventory_Base
	{
		canBeSplit=1;
		inventorySlot[]+=
		{
			"ExpansionMoney"
		};
    };

	class CJ_Pass: Inventory_Base
	{
		attachments[]+=
		{
			"ExpansionMoney"
		};
    };

	class WoodenLog: Inventory_Base
	{
		itemSize[]={3,9};
    };
	class CigarettePack_Chernamorka: CigarettePack_ColorBase
	{
		displayName = "$STR_CW95_CigarettePack_Chernamorka_NAME";
		descriptionShort = "$STR_CW95_CigarettePack_Chernamorka_DESC";
	};
	class CigarettePack_Merkur: CigarettePack_ColorBase
	{
		displayName = "$STR_CW95_CigarettePack_Merkur_NAME";
		descriptionShort = "$STR_CW95_CigarettePack_Merkur_DESC";
	};
	class CigarettePack_Partyzanka: CigarettePack_ColorBase
	{
		displayName = "$STR_CW95_CigarettePack_Partyzanka_NAME";
		descriptionShort = "$STR_CW95_CigarettePack_Partyzanka_DESC";
	};
	
	//!--------------- DAYZ EXPANSION ---------------
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
	
    class Clothing;
    class GhillieSuit_ColorBase: Clothing
    {
        inventorySlot[]+= {"Armband","Hips"};
    };
    class GhillieBushrag_ColorBase: Clothing
    {
        inventorySlot[]+= {"Armband","Hips"};
    };
    class GhillieTop_ColorBase: Clothing
    {
        inventorySlot[]+= {"Armband","Hips"};
    };

	class AK_Bayonet: Inventory_Base
	{
		inventorySlot[]+={"Knife"};
	};
	class M9A1_Bayonet: Inventory_Base
	{
		inventorySlot[]+={"Knife"};
	};
	
	class PlateCarrierPouches : Container_Base
	{
		inventorySlot[]=
		{
			"VestPouch",
			"VestHolster",
			"Belt_Right"
		};
	};
	
	class SmershVest : Clothing
	{
		inventorySlot[]=
		{
			"Vest",
			"Hips"
		};
		itemInfo[]=
		{
			"Clothing",
			"Vest",
			"Hips"
		};
	};
	
	//!--------------- Air Raid ---------------
	class CW95_TU95: HouseNoDestruct
	{
		scope=1;
		model="AirRaid\model\tucko.p3d";
		forceFarBubble="true";
	};
	class CW95_Mig21: HouseNoDestruct
	{
		scope=1;
		model="AirRaid\model\Mig21.p3d";
		forceFarBubble="true";
	};
	class CW95_Mi24: HouseNoDestruct
	{
		scope=1;
		model="AirRaid\model\Mi24.p3d";
	};
	/*
	class CW95_Mi8: HouseNoDestruct
	{
		scope=1;
		model=".p3d";
	};
	*/
	class CW95_Mi6: HouseNoDestruct
	{
		scope=1;
		model="AirRaid\model\Mi6.p3d";
	};
};

class CfgAmmo
{
	class MeleeDamage;
	class MeleeBlunt: MeleeDamage
	{
		class DamageApplied
		{
			type="Melee";
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
				damage=35;
			};
		};
	};
	class MeleeFistLight: MeleeDamage
	{
		class DamageApplied
		{
			type="Melee";
			bleedThreshold=0.1;
			class Health
			{
				damage=2;
			};
			class Blood
			{
				damage=30;
			};
			class Shock
			{
				damage=15;
			};
		};
	};
	class MeleeFistHeavy: MeleeDamage
	{
		class DamageApplied
		{
			type="Melee";
			bleedThreshold=0.1;
			class Health
			{
				damage=7;
			};
			class Blood
			{
				damage=50;
			};
			class Shock
			{
				damage=20;
			};
		};
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
