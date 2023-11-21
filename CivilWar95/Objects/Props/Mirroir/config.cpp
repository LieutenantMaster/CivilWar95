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
			"DayZExpansion_Market_Objects",
			"DayZExpansion_Quests_Teleporter"
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
	class Expansion_Teleporter_Base;
	class CW95_Teleporter: Expansion_Teleporter_Base
	{
		scope=1;
		model="\CivilWar95\CivilWar95\Objects\Props\Mirroir\Invis.p3d";
	};
};