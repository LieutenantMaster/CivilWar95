class CfgPatches
{
	class CV95_Scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Scripts"
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
		//inputs="CivilWar95/CivilWar95/Data/inputs.xml";

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
					"CivilWar95/CivilWar95/Scripts/Common",
					"CivilWar95/CivilWar95/Scripts/1_Core"
				};
			};
			class gameLibScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts/Common",
					"CivilWar95/CivilWar95/Scripts/2_GameLib"
				};
			};
			class gameScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts/Common",
					"CivilWar95/CivilWar95/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts/Common",
					"CivilWar95/CivilWar95/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts/Common",
					"CivilWar95/CivilWar95/Scripts/5_Mission"
				};
			};
		};
	};
};
