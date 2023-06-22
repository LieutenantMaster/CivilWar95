class CfgPatches
{
	class CV95_Objects_Overrides
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Consumables"
		};
	};
};

class CfgVehicles
{
    class Inventory_Base;
	class WoodenLog: Inventory_Base
	{
		itemSize[]={3,10};
    };
};