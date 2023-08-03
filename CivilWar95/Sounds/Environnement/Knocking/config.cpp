/**
 * config.cpp
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CfgPatches
{
	class CV95_Sounds_Gear_Knocking
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Sounds_Effects"
		};
	};
};

class CfgSoundShaders
{
	class CV95_Knocking_Base_SoundShader
	{
		range=30;
	};
	class CV95_Knocking_SoundShader: CV95_Knocking_Base_SoundShader
	{
		samples[] = {
            {"CivilWar95\CivilWar95\Sounds\Environnement\Knocking\CV95_Knock_01", 1},
            {"CivilWar95\CivilWar95\Sounds\Environnement\Knocking\CV95_Knock_02", 1},
            {"CivilWar95\CivilWar95\Sounds\Environnement\Knocking\CV95_Knock_03", 1},
            {"CivilWar95\CivilWar95\Sounds\Environnement\Knocking\CV95_Knock_04", 1},
            {"CivilWar95\CivilWar95\Sounds\Environnement\Knocking\CV95_Knock_05", 1},
            {"CivilWar95\CivilWar95\Sounds\Environnement\Knocking\CV95_Knock_06", 1},
            {"CivilWar95\CivilWar95\Sounds\Environnement\Knocking\CV95_Knock_07", 1},
            {"CivilWar95\CivilWar95\Sounds\Environnement\Knocking\CV95_Knock_08", 1},
            {"CivilWar95\CivilWar95\Sounds\Environnement\Knocking\CV95_Knock_09", 1},
            {"CivilWar95\CivilWar95\Sounds\Environnement\Knocking\CV95_Knock_10", 1},
            {"CivilWar95\CivilWar95\Sounds\Environnement\Knocking\CV95_Knock_11", 1},
            {"CivilWar95\CivilWar95\Sounds\Environnement\Knocking\CV95_Knock_12", 1}
        };
		volume=2.75;
	};
};

class CfgSoundSets
{
	class CV95_Knocking_Base_SoundSet
	{
		sound3DProcessingType="Vehicle_Ext_3DProcessingType";
		distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve="vehicleEngineAttenuationCurve";
		spatial=1;
		doppler=1;
		loop=0;
	};
	class CV95_Knocking_SoundSet: CV95_Knocking_Base_SoundSet
	{
		soundShaders[]=
		{
			"CV95_Knocking_SoundShader"
		};
		loop=1;
	};
};