class CfgPatches
{
	class CW95_Scripts_Server
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Scripts",
			"DayZExpansion_Scripts",
			"CW95_Scripts_Client",
			"AirRaid",
		};
	};
};

class CfgMods
{
	class DZ_CivilWar95_Server
	{
		dir = "CivilWar95/CivilWar95";
		extra = 0;
		type = "mod";

		name = "CivilWar95";

		tooltip = "CivilWar95";
		overview = "";
		author = "LieutenantMaster";
		authorID = "";

		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class engineScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts_Server/Common",
					"CivilWar95/CivilWar95/Scripts_Server/1_Core"
				};
			};
			class gameLibScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts_Server/Common",
					"CivilWar95/CivilWar95/Scripts_Server/2_GameLib"
				};
			};
			class gameScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts_Server/Common",
					"CivilWar95/CivilWar95/Scripts_Server/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts_Server/Common",
					"CivilWar95/CivilWar95/Scripts_Server/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts_Server/Common",
					"CivilWar95/CivilWar95/Scripts_Server/5_Mission"
				};
			};
		};
	};
};
