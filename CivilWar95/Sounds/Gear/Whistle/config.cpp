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
	class CV95_Sounds_Gear_Whistle
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
	class CV95_Whistle_Base_Low_SoundShader
	{
		range=40;
	};
	class CV95_Whistle_Base_Normal_SoundShader
	{
		range=125;
	};
	class CV95_Whistle_Base_Far_SoundShader
	{
		range=175;
	};
	class CV95_Whistle_Base_Extreme_SoundShader
	{
		range=225;
	};
	class CV95_Whistle_01_SoundShader: CV95_Whistle_Base_Normal_SoundShader
	{
		samples[]={{"CivilWar95\CivilWar95\Sounds\Gear\Whistle\CV95_Whitlse_01", 1}};
		volume=0.5;
	};
	class CV95_Whistle_02_SoundShader: CV95_Whistle_Base_Normal_SoundShader
	{
		samples[]={{"CivilWar95\CivilWar95\Sounds\Gear\Whistle\CV95_Whitlse_02", 1}};
		volume=0.5;
	};
	class CV95_Whistle_03_SoundShader: CV95_Whistle_Base_Far_SoundShader
	{
		samples[]={{"CivilWar95\CivilWar95\Sounds\Gear\Whistle\CV95_Whitlse_03", 1}};
		volume=0.4;
	};
	class CV95_Whistle_04_SoundShader: CV95_Whistle_Base_Low_SoundShader
	{
		samples[]={{"CivilWar95\CivilWar95\Sounds\Gear\Whistle\CV95_Whitlse_04", 1}};
		volume=0.4;
	};
	class CV95_Whistle_05_SoundShader: CV95_Whistle_Base_Extreme_SoundShader
	{
		samples[]={{"CivilWar95\CivilWar95\Sounds\Gear\Whistle\CV95_Whitlse_05", 1}};
		volume=0.5;
	};
	class CV95_Whistle_06_SoundShader: CV95_Whistle_Base_Low_SoundShader
	{
		samples[]={{"CivilWar95\CivilWar95\Sounds\Gear\Whistle\CV95_Whitlse_06", 1}};
		volume=0.5;
	};
};

class CfgSoundSets
{
	class CV95_Whistle_Base_SoundSet
	{
		sound3DProcessingType="Vehicle_Ext_3DProcessingType";
		distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve="vehicleEngineAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class CV95_Whistle_01_SoundSet: CV95_Whistle_Base_SoundSet
	{
		soundShaders[]=
		{
			"CV95_Whistle_01_SoundShader"
		};
		loop=1;
	};
	class CV95_Whistle_02_SoundSet: CV95_Whistle_Base_SoundSet
	{
		soundShaders[]=
		{
			"CV95_Whistle_02_SoundShader"
		};
		loop=1;
	};
	class CV95_Whistle_03_SoundSet: CV95_Whistle_Base_SoundSet
	{
		soundShaders[]=
		{
			"CV95_Whistle_03_SoundShader"
		};
		loop=1;
	};
	class CV95_Whistle_04_SoundSet: CV95_Whistle_Base_SoundSet
	{
		soundShaders[]=
		{
			"CV95_Whistle_04_SoundShader"
		};
		loop=1;
	};
	class CV95_Whistle_05_SoundSet: CV95_Whistle_Base_SoundSet
	{
		soundShaders[]=
		{
			"CV95_Whistle_05_SoundShader"
		};
		loop=1;
	};
	class CV95_Whistle_06_SoundSet: CV95_Whistle_Base_SoundSet
	{
		soundShaders[]=
		{
			"CV95_Whistle_06_SoundShader"
		};
		doppler=1;
	};
};