class CfgPatches
{
	class CW95_Scripts_Client
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Scripts",
			"DayZExpansion_Scripts",
			"DayZExpansion_Market_Scripts",
			"DayZExpansion_BaseBuilding_Scripts",
			"AirRaid"
		};
	};
};

class CfgMods
{
	class DZ_CivilWar95
	{
		dir = "CivilWar95/CivilWar95";
		extra = 0;
		type = "mod";

		name = "CivilWar95";

		tooltip = "CivilWar95";
		overview = "";
		author = "LieutenantMaster";
		authorID = "";
		inputs="CivilWar95/CivilWar95/Data/inputs.xml";

		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts_Client/Common",
					"CivilWar95/CivilWar95/Scripts_Client/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts_Client/Common",
					"CivilWar95/CivilWar95/Scripts_Client/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts_Client/Common",
					"CivilWar95/CivilWar95/Scripts_Client/5_Mission"
				};
			};
		};
	};
};
