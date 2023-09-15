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
			"DayZExpansion_Worlds_IntroScenes",
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
			class engineScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts_Client/Common",
					"CivilWar95/CivilWar95/Scripts_Client/1_Core"
				};
			};
			class gameLibScriptModule
			{
				value = "";
				files[] =
				{
					"CivilWar95/CivilWar95/Scripts_Client/Common",
					"CivilWar95/CivilWar95/Scripts_Client/2_GameLib"
				};
			};
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

class cfgExpansionCharacterScenes
{
	class ChernarusPlus
	{
		delete SouthSvetlo;
		delete Cherno;
		delete Kamyshovo;
		delete twospooky;
		delete campfire_guitar;
		delete expansion_market_update;
		
 		class cw95_chernaruplus_chernogorsk_street
		{
			CameraPosition[]={6384.3, 10.52, 2538.92};
			CameraOrientation[]={33.8983, 0, -0};
			PlayerPosition[]={6386.5, 9.33248, 2541.93};
			PlayerOrientation[]={-138.983, 0, -0};
			fov=0.4;
            date[]=
            {
                1995,
                10,
                19,
                18,
                47
            };
			overcast=0.49;
			rain=0.0;
			fog=0.67;
			windspeed=0.22;
			MappingFiles[]=
			{
                "CivilWar95/CivilWar95/Scripts_Client/Data/CW95_Chernogorsk"
			};
			CustomPose=1054;
			HandItem="";
			CanRotate=0;
			CanUseInCharacterCreation=1;
		};
	};
};