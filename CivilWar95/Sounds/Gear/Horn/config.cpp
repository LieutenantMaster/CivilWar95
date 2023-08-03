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
	class CV95_Sounds_Gear_Horn
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
	class CV95_Horn_Base_Extreme_SoundShader
	{
		range=400;
	};
	class CV95_Horn_01_SoundShader: CV95_Horn_Base_Extreme_SoundShader
	{
		samples[]={{"CivilWar95\CivilWar95\Sounds\Gear\Horn\CV95_Horn_01", 1}};
		volume=1.0;
	};
};

class CfgSoundSets
{
	class CV95_Horn_Base_SoundSet
	{
		sound3DProcessingType="Vehicle_Ext_3DProcessingType";
		distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve="vehicleEngineAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class CV95_Horn_01_SoundSet: CV95_Horn_Base_SoundSet
	{
		soundShaders[]=
		{
			"CV95_Horn_01_SoundShader"
		};
		loop=1;
	};
};