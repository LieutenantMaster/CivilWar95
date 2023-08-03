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
	class CV95_Gear_Radio
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
	class CV95_Whistle_Base : Inventory_Base
	{
		scope=0;
	};
	class CV95_Whistle_Generic : CV95_Whistle_Base
	{
		scope=0;
		displayName="Sifflet (à bille)";
		descriptionShort="Les sifflets partagent avec les flûtes le mécanisme d'induction de l'air par biseau pour produire un son.";
		model="CivilWar95\CivilWar95\Objects\Gear\Radio\Whistles\whistle01.p3d";
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
	class CV95_Whistle_Shiny : CV95_Whistle_Generic
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Gear\Radio\Whistles\data\Whistle_shiny_co.paa"
		};
	};
	class CV95_Whistle_Mat : CV95_Whistle_Generic
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Gear\Radio\Whistles\data\Whistle_mat_co.paa"
		};
	};
	//! Comedic whistle
	class CV95_Whistle_Toy : CV95_Whistle_Generic
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Gear\Radio\Whistles\data\Whistle_toy_co.paa"
		};
	};
	//! doesn't make sounds for the player but any entities will hear it
	class CV95_Whistle_Silenced : CV95_Whistle_Generic
	{
		scope=0;
	};
	class CV95_Whistle_Silenced_Shiny : CV95_Whistle_Silenced
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Gear\Radio\Whistles\data\Whistle_shiny_deaf_co.paa"
		};		
	};
	class CV95_Whistle_Silenced_Mat : CV95_Whistle_Silenced
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Gear\Radio\Whistles\data\Whistle_mat_deaf_co.paa"
		};
	};
};