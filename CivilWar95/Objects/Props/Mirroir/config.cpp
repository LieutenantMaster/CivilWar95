class CfgPatches
{
	class CW95_Objects_Props_Mirroir
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
	class CW95_TraderMachineACoudre: ExpansionTraderStaticBase
	{
		scope=1;
		displayName="Machine à coudre";
		descriptionShort="";
		model = "DayZExpansion\Objects\Structures\Props\jigsaw.p3d";
	};
};