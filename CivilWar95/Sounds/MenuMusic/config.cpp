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
	class CW95_Sounds_MenuMusic
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
	class CW95_Music_1_SoundShader
	{
		samples[] = {{"\CivilWar95\CivilWar95\Sounds\MenuMusic\music1",1}};
		volume=1.0;
	};
};

class CfgSoundSets
{	
	class CW95_Music_1_SoundSet
	{
		soundShaders[]=
		{
			"CW95_Music_1_SoundShader"
		};
		volumeFactor=1;
		frequencyFactor=1;
		spatial=0;
	};
};