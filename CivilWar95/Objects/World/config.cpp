class CfgPatches
{
	class CW95_Objects_World
    {
        units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]=
        {
            "DZ_Data",
            "DZ_Worlds_Chernarusplus_World",
            "DayZExpansion_Worlds_IntroScenes"
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
                17,
                30
            };
			overcast=0.49;
			rain=0.0;
			fog=0.67;
			windspeed=0.22;
			MappingFiles[]=
			{
                "CivilWar95/CivilWar95/Scripts_Client/Data/CW95_Chernogorsk"
			};
			CustomPose=-1;
			HandItem="";
			CanRotate=0;
			CanUseInCharacterCreation=1;
		};
	};
};

class CfgWorlds
{
    class DefaultWorld;
    class CAWorld: DefaultWorld
    {
        class Weather
        {
            class VolFog
            {
                CameraFog = 0.0;
                Item1[] = {400.0,0.06,0.93,0.13,1.0}; //>> 800.0,0.06,0.93,0.13,1.0
                Item2[] = {700.0,0.02,0.9,0.05,1.0}; //>> 1300.0,0.02,0.9,0.05,1.0
            };
        };
    };
    class ChernarusPlus: CAWorld
    {
        clutterGrid = 1;
        clutterDist = 50;
        noDetailDist = 5;
        fullDetailDist = 2;
    };
};
