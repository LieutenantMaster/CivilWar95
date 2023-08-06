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
	class CV95_Sounds_AirRaid
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DayZExpansion_Sounds_Vehicles_Air_Merlin","DZ_Sounds_Effects"};
	};
};

class CfgSoundShaders
{
	class CW95_GenericVehicle_Engine_SoundShader
	{
		range=2000;
	};
	class CW95_GenericHeliEngine_Loop_SoundShader: CW95_GenericVehicle_Engine_SoundShader
	{
		samples[] = {{"DayZExpansion\Sounds\Vehicles\Air\Merlin\Expansion_Merlin_Engine_Ext",1}};
		volume = 0.8;
	};
	class CW95_GenericHeliRotor_Loop_SoundShader: CW95_GenericVehicle_Engine_SoundShader
	{
		samples[] = {{"DayZExpansion\Sounds\Vehicles\Air\Merlin\Expansion_Merlin_Rotor_Ext",1}};
		volume = 0.8;
	};
	class CW95_GenericPlane_Loop_SoundShader: CW95_GenericVehicle_Engine_SoundShader
	{
		samples[] = {{"CivilWar95\CivilWar95\Sounds\AirRaid\CW95_Su34_Engine_Ext",1}};
		volume = 2;
	};
};

class CfgSoundSets
{
	class CW95_GenericVehicle_SoundSet
	{
		sound3DProcessingType="Vehicle_Ext_3DProcessingType";
		distanceFilter="softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve="vehicleEngineAttenuationCurve";
		volumeFactor=1;
		spatial=1;
		loop=0;
	};
	class CW95_GenericHeliEngine_Loop_CfgSoundSet: CW95_GenericVehicle_SoundSet
	{
		soundShaders[]=
		{
			"CW95_GenericHeliEngine_Loop_SoundShader"
		};
		volumeFactor=1;
	};
	class CW95_GenericHeliRotor_Loop_CfgSoundSet: CW95_GenericVehicle_SoundSet
	{
		soundShaders[]=
		{
			"CW95_GenericHeliRotor_Loop_SoundShader"
		};
		volumeFactor=1;
	};
	class CW95_GenericPlane_Loop_CfgSoundSet: CW95_GenericVehicle_SoundSet
	{
		soundShaders[]=
		{
			"CW95_GenericPlane_Loop_SoundShader"
		};
		volumeFactor=1;
	};
};