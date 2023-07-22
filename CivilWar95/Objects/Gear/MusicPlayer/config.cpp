class CfgPatches
{
	class CV95_Objects_Gear_MusicPlayer
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
			"CV95_Radio"
		};
	};
	
	class Inventory_Base;
	class CV95_MusicPlayer: Inventory_Base
	{
		scope=2;
		rotationFlags=1;
		displayName="Cassette Player";
		descriptionShort="Put some cassettes in me senpai";
		model="CivilWar95\CivilWar95\Objects\Gear\MusicPlayer\Models\musicPlayer.p3d";
		weight=200;
		itemSize[]={2,2};
		soundImpactType="plastic";
		inventorySlot[]=
		{
			"CV95_Radio",
			"Belt_Left"
		};
		attachments[]=
		{
			"BatteryD",
			"CV95_Cassette"
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
	class CV95_Cassette_Base: Inventory_Base
	{
		scope=0;
		displayName="Ooopsie woopsie";
		descriptionShort="Someone made an oopsie woopsie and didnt replace me with actual names :C";
		model="\dz\gear\tools\cassette.p3d";
		soundImpactType="plastic";
		inventorySlot[]=
		{
			"CV95_Cassette"
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
	class CV95_Cassette_BosanskaArtiljerija: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 216.0;
		displayName="Bosanska Artiljerija";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_BosanskaArtiljerija_Music"
		};
	};
	class CV95_Cassette_ChDKZAnthem: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 188.0;
		displayName="ChDKZ Anthem";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_ChDKZAnthem_Music"
		};
	};
	class CV95_Cassette_ChernarussianAnthem: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 133.0;
		displayName="Chernarussian Anthem";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_ChernarussianAnthem_Music"
		};
	};
	class CV95_Cassette_CrniBombarderi: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 133.0;
		displayName="Crni Bombarderi";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_CrniBombarderi_Music"
		};
	};
	class CV95_Cassette_DarkIsTheNight: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 168.0;
		displayName="Dark Is The Night";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_DarkIsTheNight_Music"
		};
	};
	class CV95_Cassette_DontTellMomImInChechnya: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 186.0;
		displayName="DontTell Mom Im In Chechnya";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_DontTellMomImInChechnya_Music"
		};
	};
	class CV95_Cassette_International: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 238.0;
		displayName="International";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_International_Music"
		};
	};
	class CV95_Cassette_Karavan: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 209.0;
		displayName="Karavan";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_Karavan_Music"
		};
	};
	class CV95_Cassette_Katyusha: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 129.0;
		displayName="Katyusha";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_Katyusha_Music"
		};
	};
	class CV95_Cassette_Kombat: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 300.0;
		displayName="Kombat";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_Kombat_Music"
		};
	};
	class CV95_Cassette_MyDadIsAWarCriminal: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 143.0;
		displayName="My Dad Is A War Criminal";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_MyDadIsAWarCriminal_Music"
		};
	};
	class CV95_Cassette_NoviGod: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 238.0;
		displayName="NoviGod";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_NoviGod_Music"
		};
	};
	class CV95_Cassette_OjAlijaAljo: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 183.0;
		displayName="OjAlijaAljo";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_OjAlijaAljo_Music"
		};
	};
	class CV95_Cassette_PolyushkaPolye: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 194.0;
		displayName="Polyushka Polye";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_PolyushkaPolye_Music"
		};
	};
	class CV95_Cassette_RemoveTakistani: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 306.0;
		displayName="Remove Takistani";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_RemoveTakistani_Music"
		};
	};
	class CV95_Cassette_ThreeChoppersOverMozdok: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 185.0;
		displayName="Three Choppers Over Mozdok";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_ThreeChoppersOverMozdok_Music"
		};
	};
	class CV95_Cassette_Troika: CV95_Cassette_Base
	{
		scope=2;
		trackTime = 199.0;
		displayName="Troika";
		descriptionShort="...";
		Tracks[] = 
		{
			"CV95_Troika_Music"
		};
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	//class ProxyCV95Radio: ProxyAttachment
	//{
	//	scope=2;
	//	inventorySlot[]=
	//	{
	//		"CV95_ExternalBag"
	//	};
		//model="Silens-Nox-Redux\CV95_CLOTHES\Attachments\NBCBag\Models\cannister.p3d";
	//};
	class ProxyCV95_Cassette: ProxyAttachment
	{
		scope=2;
		inventorySlot[]=
		{
			"CV95_Cassette"
		};
		model="\dz\gear\tools\cassette.p3d";
	};
};
class CfgSlots
{
	class Slot_CV95_ExternalBag
	{
		name="CV95_ExternalBag";
		displayName="External Bag";
		ghostIcon="set:dayz_inventory image:back";
	};
	class Slot_CV95_Cassette
	{
		name="CV95_Cassette";
		displayName="Cassette";
		ghostIcon="plant";
	};
	class Slot_CV95_Radio
	{
		name="CV95_Radio";
		displayName="Cassette Player";
		ghostIcon="plant";
	};
};
