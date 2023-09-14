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
	class CW95_Gear_Radio
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Radio"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class CW95_Whistle_Base : Inventory_Base
	{
		scope=0;
		WhistleSoundSet="CW95_Whistle_01_SoundSet";
		WhistleLength=1531;
		WhistleLengthDelay=3531;
	};
	class CW95_Whistle_Generic : CW95_Whistle_Base
	{
		scope=0;
		displayName="Sifflet (à bille)";
		descriptionShort="Les sifflets partagent avec les flûtes le mécanisme d'induction de l'air par biseau pour produire un son.";
		model="CivilWar95\CivilWar95\Objects\Gear\Radio\Whistles\whistle01.p3d";
		WhistleSoundSet="CW95_Whistle_01_SoundSet";
		WhistleLength=1531;
		WhistleLengthDelay=3531;
		weight=100;
		absorbency=0.5;
		itemSize[]={2,1};
		lootTag[]=
		{
			"Police",
			"Hunting",
			"Camping",
			"Military_east"
		};
		hiddenSelections[]=
		{
			"camo"
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeLightBlunt";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1.8;
			};
		};
	};
	class CW95_Whistle_Mat : CW95_Whistle_Generic
	{
		scope=2;
		WhistleSoundSet="CW95_Whistle_02_SoundSet";
		WhistleLength=1840;
		WhistleLengthDelay=2440;
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Gear\Radio\Whistles\data\Whistle_mat_co.paa"
		};
	};
	class CW95_Whistle_Shiny : CW95_Whistle_Generic
	{
		scope=2;
		WhistleSoundSet="CW95_Whistle_03_SoundSet";
		WhistleLength=1917;
		WhistleLengthDelay=2817;
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Gear\Radio\Whistles\data\Whistle_shiny_co.paa"
		};
	};
	class CW95_Whistle_Toy : CW95_Whistle_Generic
	{
		scope=2;
		WhistleSoundSet="CW95_Whistle_04_SoundSet";
		WhistleLength=4060;
		WhistleLengthDelay=5060;
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Gear\Radio\Whistles\data\Whistle_toy_co.paa"
		};
	};
};