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
            "DZ_Worlds_Chernarusplus_World"
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
