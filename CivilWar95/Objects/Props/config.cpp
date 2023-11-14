class CfgPatches
{
	class CW95_Objects_Props
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DayZExpansion_Market_Objects"
		};
	};
};

class CfgVehicles
{
	class ExpansionTraderStaticBase;
	class CW95_TraderMirrorStand: ExpansionTraderStaticBase
	{
		scope=1;
		displayName="Mirroir sur Pied";
		descriptionShort="Mirroir mirroir, mon beau mirroir, dit moi qui est le plus beau.";
		model="\CivilWar95\CivilWar95\Objects\Props\Mirroir\Mirroir.p3d";
	};
};