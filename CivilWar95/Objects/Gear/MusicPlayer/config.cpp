/**
 * config.cpp
 *
 * © 2023 CivilWar95
 * By LieutenantMaster and Niphoria
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CfgPatches
{
	class CW95_Objects_Gear_MusicPlayer
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Vehicles_Wheeled"
		};
	};
};
class CfgVehicles
{
	class Car;
	class CarScript: Car
	{
		attachments[]+=
		{
			"CW95_Radio"
		};
	};
	
	class Inventory_Base;
	class CW95_MusicPlayer: Inventory_Base
	{
		scope=2;
		rotationFlags=1;
		displayName="$STR_CW95_MUSICPLAYER_NAME";
		descriptionShort="$STR_CW95_MUSICPLAYER_DESC";
		model="CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Models\musicPlayer.p3d";
		weight=200;
		itemSize[]={2,2};
		soundImpactType="plastic";
		inventorySlot[]=
		{
			"CW95_Radio",
			"Belt_Left"
		};
		attachments[]=
		{
			"BatteryD",
			"CW95_Cassette"
		};
		hiddenSelections[]=
		{
			"camo",
			"door",
			"light_power"
		};
		hiddenSelectionsTextures[]=
		{
			"CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Textures\musicPlayer_co.paa",
			"dz\characters\headgear\data\motohelmetvisor_ca.paa",
			"CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Textures\musicPlayer_co.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayer.rvmat",
			"CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayerGlass.rvmat",
			"CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayer.rvmat"
		};	
		class NoiseCassette
		{
			strength=30;
			type="sound";
		};
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=0;
			energyUsagePerSecond=0.006;
			plugType=1;
			attachmentAction=1;
			wetnessExposure=0.1;
		};
		class AnimationSources
		{
			class AnimRotate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class Door: AnimRotate{};

			class Button_Play: AnimRotate{};
			class Button_Rewind: AnimRotate{};
			class Button_Fastforward: AnimRotate{};
			class Button_Stop: AnimRotate{};
			class Button_Pause: AnimRotate{};
			
			class Slider_Volume: AnimRotate{};
			class Slider_MusicPlay1: AnimRotate{};
			class Slider_MusicPlay2: AnimRotate{};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						{1.0,{"CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayer.rvmat","CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayerGlass.rvmat"}},
						{0.69999999,{"CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayer.rvmat","CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayerGlass.rvmat"}},
						{0.5,{"CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayer_damage.rvmat","CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayerGlass_damage.rvmat"}},
						{0.30000001,{"CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayer_damage.rvmat","CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayerGlass_damage.rvmat"}},
						{0.0,{"CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayer_destruct.rvmat","CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Rvmats\musicPlayerGlass_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class CW95_Cassette_Base: Inventory_Base
	{
		scope=0;
		displayName="$STR_CW95_CASSETTEBASE_NAME";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		model="\dz\gear\tools\cassette.p3d";
		soundImpactType="plastic";
		inventorySlot[]=
		{
			"CW95_Cassette"
		};
		weight=50;
		itemSize[]={2,1};
		// time in seconds how long the song lasts
		trackTime = 1.0;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						{1,{"DZ\gear\tools\data\cassette.rvmat"}},
						{0.69999999,{"DZ\gear\tools\data\cassette.rvmat"}},
						{0.5,{"DZ\gear\tools\data\cassette_damage.rvmat"}},
						{0.30000001,{"DZ\gear\tools\data\cassette_damage.rvmat"}},
						{0,{"DZ\gear\tools\data\cassette_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class CW95_Cassette_BosanskaArtiljerija: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 216.0;
		displayName="Bosanska Artiljerija";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_BosanskaArtiljerija_Music"
		};
	};
	class CW95_Cassette_Rossiya: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 188.0;
		displayName="ChDKZ Anthem";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_Rossiya_Music"
		};
	};
	class CW95_Cassette_ChernarussianAnthem: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 78.0;
		displayName="Chernarussian Anthem";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_ChernarussianAnthem_Music"
		};
	};
	class CW95_Cassette_CrniBombarderi: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 133.0;
		displayName="Crni Bombarderi";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_CrniBombarderi_Music"
		};
	};
	class CW95_Cassette_DarkIsTheNight: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 168.0;
		displayName="Dark Is The Night";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_DarkIsTheNight_Music"
		};
	};
	class CW95_Cassette_DontTellMomImInChechnya: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 186.0;
		displayName="DontTell Mom Im In Chechnya";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_DontTellMomImInChechnya_Music"
		};
	};
	class CW95_Cassette_International: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 238.0;
		displayName="International";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_International_Music"
		};
	};
	class CW95_Cassette_Karavan: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 209.0;
		displayName="Karavan";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_Karavan_Music"
		};
	};
	class CW95_Cassette_Katyusha: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 129.0;
		displayName="Katyusha";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_Katyusha_Music"
		};
	};
	class CW95_Cassette_Kombat: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 300.0;
		displayName="Kombat";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_Kombat_Music"
		};
	};
	class CW95_Cassette_MyDadIsAWarCriminal: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 143.0;
		displayName="My Dad Is A War Criminal";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_MyDadIsAWarCriminal_Music"
		};
	};
	class CW95_Cassette_NoviGod: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 238.0;
		displayName="NoviGod";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_NoviGod_Music"
		};
	};
	class CW95_Cassette_OjAlijaAljo: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 183.0;
		displayName="OjAlijaAljo";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_OjAlijaAljo_Music"
		};
	};
	class CW95_Cassette_PolyushkaPolye: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 194.0;
		displayName="Polyushka Polye";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_PolyushkaPolye_Music"
		};
	};
	class CW95_Cassette_RemoveTakistani: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 306.0;
		displayName="Remove Takistani";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_RemoveTakistani_Music"
		};
	};
	class CW95_Cassette_ThreeChoppersOverMozdok: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 185.0;
		displayName="Three Choppers Over Mozdok";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_ThreeChoppersOverMozdok_Music"
		};
	};
	class CW95_Cassette_Troika: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 199.0;
		displayName="Troika";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_Troika_Music"
		};
	};
	class CW95_Cassette_TheBigHangover: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 138.0;
		displayName="TheBigHangover";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_TheBigHangover_Music"
		};
	};
	class CW95_Cassette_Atas: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 206.0;
		displayName="Atas";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_Atas_Music"
		};
	};
	class CW95_Cassette_PoslednyayaLyubov: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 261.0;
		displayName="PoslednyayaLyubov";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_PoslednyayaLyubov_Music"
		};
	};
	class CW95_Cassette_DavaiZa: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 250.0;
		displayName="DavaiZa";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_DavaiZa_Music"
		};
	};
	class CW95_Cassette_MilyeZelyonyeGlaza: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 184.0;
		displayName="MilyeZelyonyeGlaza";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_MilyeZelyonyeGlaza_Music"
		};
	};
	class CW95_Cassette_Kukushka: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 387.0;
		displayName="Kukushka";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_Kukushka_Music"
		};
	};
	class CW95_Cassette_Leto: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 354.0;
		displayName="Leto";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_Leto_Music"
		};
	};
	class CW95_Cassette_GruppaKrovi: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 284.0;
		displayName="GruppaKrovi";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_GruppaKrovi_Music"
		};
	};
	class CW95_Cassette_Zvezda: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 266.0;
		displayName="Zvezda";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_Zvezda_Music"
		};
	};
	class CW95_Cassette_Peremen: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 292.0;
		displayName="Peremen";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_Peremen_Music"
		};
	};
	class CW95_Cassette_ChDKZAnthem: CW95_Cassette_Base
	{
		scope=2;
		trackTime = 133.0;
		displayName="ChDKZAnthem";
		descriptionShort="$STR_CW95_CASSETTEBASE_DESC";
		Tracks[] = 
		{
			"CW95_ChDKZAnthem_Music"
		};
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	//class ProxyCW95Radio: ProxyAttachment
	//{
	//	scope=2;
	//	inventorySlot[]=
	//	{
	//		"CW95_ExternalBag"
	//	};
		//model="Silens-Nox-Redux\CW95_CLOTHES\Attachments\NBCBag\Models\cannister.p3d";
	//};
	class ProxyCW95_Cassette: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"CW95_Cassette"
		};
		model="\dz\gear\tools\cassette.p3d";
	};
};
class CfgSlots
{
	class Slot_CW95_ExternalBag
	{
		name="CW95_ExternalBag";
		displayName="External Bag";
		ghostIcon="set:dayz_inventory image:back";
	};
	class Slot_CW95_Cassette
	{
		name="CW95_Cassette";
		displayName="$STR_CW95_CASSETTEBASE_NAME";
		ghostIcon="plant";
	};
	class Slot_CW95_Radio
	{
		name="CW95_Radio";
		displayName="$STR_CW95_MUSICPLAYER_NAME";
		ghostIcon="plant";
	};
};
