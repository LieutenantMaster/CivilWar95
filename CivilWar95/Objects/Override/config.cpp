class CfgPatches
{
	class CV95_Objects_Overrides
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Consumables",
			"DZ_Weapons_Melee",

			"DayZExpansion_Core_Objects_CircuitBoard",
			"DayZExpansion_Core_Objects_Currencies",
			"DayZExpansion_Objects_Gear_Guitar",
			"DayZExpansion_Objects_Misc"//,

			//"PB_SmallMetalPlate"
		};
	};
};

class CfgVehicles
{
    class Inventory_Base;
	class CigarettePack_ColorBase;
	class Pliers;

	class ExpansionCircuitBoardBase;
	class ExpansionMoneyBar_Base;

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

	//!--------------- Doors and Barricade ---------------
	class PB_SmallMetalPlate: Inventory_Base
	{
		displayName = "$STR_CW95_PB_SmallMetalPlate_NAME";
		descriptionShort = "$STR_CW95_PB_SmallMetalPlate_DESC";
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
				damage=10;
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
};