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
			"DZ_Weapons_Melee"
		};
	};
};

class CfgVehicles
{
    class Inventory_Base;
	class WoodenLog: Inventory_Base
	{
		itemSize[]={3,9};
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