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
	class CW95_Sounds_Gear_ZoomingSounds
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};

class CfgSoundShaders
{
	class baseCharacter_SoundShader;
	class zoom_Base_SoundShader: baseCharacter_SoundShader
	{
		volume=0.55000001;
		range=20;
	};
	class zoom_in_Base_SoundShader: zoom_Base_SoundShader
	{
		samples[]=
		{
			
			{
				"DZ\sounds\weapons\firearms\M4A1\handling\jamming_01",
				1
			}
		};
	};
	class zoom_out_Base_SoundShader: zoom_Base_SoundShader
	{
		samples[]=
		{
			
			{
				"DZ\sounds\weapons\firearms\M4A1\handling\hand_0",
				1
			}
		};
		volume=0.5;
	};
};

class CfgSoundSets
{
	class baseCharacter_SoundSet;
	class zoom_in_Base_SoundSet: baseCharacter_SoundSet
	{
		frequencyRandomizer=1;
		volumeRandomizer=1;
		soundShaders[]=
		{
			"zoom_in_Base_SoundShader"
		};
	};
	class zoom_out_Base_SoundSet: baseCharacter_SoundSet
	{
		frequencyRandomizer=1;
		volumeRandomizer=1;
		soundShaders[]=
		{
			"zoom_out_Base_SoundShader"
		};
	};
};
