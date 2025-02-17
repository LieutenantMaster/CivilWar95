class CfgPatches
{
	class CW95_Objects_Overrides_Vanilla_Gear
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Consumables",
			"DZ_Gear_Containers",

			"DZ_Weapons_Archery_Crossbow",
			"DZ_Weapons_Magazines",
			"DZ_Weapons_Projectiles",
			"DZ_Weapons_Melee",
		};
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

class cfgWeapons
{
	class Archery_Base;
	class Crossbow_Base: Archery_Base
	{
		itemSize[]={8,3};
	};
};

class CfgVehicles
{
    class Inventory_Base;
	class AK_Bayonet: Inventory_Base
	{
		inventorySlot[]+={"Knife"};
	};
	class M9A1_Bayonet: Inventory_Base
	{
		inventorySlot[]+={"Knife"};
	};
	class WoodenLog: Inventory_Base
	{
		itemSize[]={3,9};
    };
	
	class Container_Base;
	class PlateCarrierPouches : Container_Base
	{
		inventorySlot[]+=
		{
			"VestHolster",
			"Belt_Right"
		};
	};

	class CigarettePack_ColorBase;
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
};

class CfgAmmo
{
	class MeleeDamage;
	class MeleeBlunt: MeleeDamage
	{
		class DamageApplied
		{
			type="Melee";
			bleedThreshold=0;
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
			bleedThreshold=0;
			class Health
			{
				damage=2;
			};
			class Blood
			{
				damage=0;
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
			bleedThreshold=0;
			class Health
			{
				damage=7;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=20;
			};
		};
	};
};
