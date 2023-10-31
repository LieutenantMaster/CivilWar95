class CfgPatches
{
	class CW95_Objects_Overrides_Vanilla_Clothing
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Characters_Vests",
            "DZ_Characters_Backpacks",
			"DZ_Characters_Tops",
			"DZ_Characters_Pants"
		};
	};
};

class CfgVehicles
{
	class Clothing;	
    class GhillieSuit_ColorBase: Clothing
    {
        inventorySlot[]+= {"Armband","Hips"};
    };
    class GhillieBushrag_ColorBase: Clothing
    {
        inventorySlot[]+= {"Armband","Hips"};
    };
    class GhillieTop_ColorBase: Clothing
    {
        inventorySlot[]+= {"Armband","Hips"};
    };
	
	class SmershVest : Clothing
	{
		itemSize[]={4,5};
		itemsCargoSize[]={4,5};
		inventorySlot[]+=
		{
			"Hips"
		};
		itemInfo[]+=
		{
			"Hips"
		};
	};
	class PressVest_ColorBase: Clothing
	{
		itemSize[]={3,4};
		itemsCargoSize[]={6,4};
	};
	class UKAssVest_ColorBase: Clothing
	{
		itemSize[]={5,5};
		itemsCargoSize[]={6,5};
	};
	class HighCapacityVest_ColorBase: Clothing
	{
		itemSize[]={4,3};
		itemsCargoSize[]={7,5};
	};
	class LeatherStorageVest_ColorBase: Clothing
	{
		itemSize[]={3,3};
		itemsCargoSize[]={7,5};
	};
	class HuntingVest: Clothing
	{
		itemSize[]={3,4};
		itemsCargoSize[]={7,5};
	};
	class PoliceVest: Clothing
	{
		itemSize[]={3,4};
		itemsCargoSize[]={4,5};
	};

	class Sweater_ColorBase: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={4,3};
	};
	class Shirt_ColorBase: Clothing
	{
		itemSize[]={3,3};
		itemsCargoSize[]={5,4};
	};
	class TShirt_ColorBase: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={4,3};
	};
	class Hoodie_ColorBase: Clothing
	{
		itemSize[]={3,3};
		itemsCargoSize[]={5,4};
	};
	class TacticalShirt_ColorBase: Clothing
	{
		itemSize[]={3,2};
	};
	class HikingJacket_ColorBase: Clothing
	{
		itemSize[]={3,5};
		itemsCargoSize[]={6,5};
	};
	class Raincoat_ColorBase: Clothing
	{
		itemSize[]={3,3};
		itemsCargoSize[]={5,4};
	};
	class TorsoCover_Improvised: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={4,3};
	};
	class M65Jacket_ColorBase: Clothing
	{
		itemSize[]={3,2};
	};
	class TTsKOJacket_ColorBase: Clothing
	{
		itemSize[]={3,2};
	};
	class GorkaEJacket_ColorBase: Clothing
	{
		itemSize[]={3,2};
	};
	class RidersJacket_ColorBase: Clothing
	{
		itemSize[]={3,5};
		itemsCargoSize[]={6,5};
	};
	class WoolCoat_ColorBase: Clothing
	{
		itemSize[]={3,5};
		itemsCargoSize[]={6,5};
	};
	class TrackSuitJacket_ColorBase: Clothing
	{
		itemSize[]={3,3};
		itemsCargoSize[]={5,4};
	};
	class PoliceJacket: Clothing
	{
		itemSize[]={3,5};
		itemsCargoSize[]={6,5};
	};
	class PoliceJacketOrel: Clothing
	{
		itemSize[]={3,5};
		itemsCargoSize[]={6,5};
	};
	class ParamedicJacket_ColorBase: Clothing
	{
		itemSize[]={3,5};
		itemsCargoSize[]={7,6};
	};
	class FirefighterJacket_ColorBase: Clothing
	{
		itemSize[]={3,5};
		itemsCargoSize[]={7,6};
	};
	class PrisonUniformJacket: Clothing
	{
		itemSize[]={3,3};
		itemsCargoSize[]={5,4};
	};
	class MiniDress_ColorBase: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={5,4};
	};
	class QuiltedJacket_ColorBase: Clothing
	{
		itemSize[]={3,3};
		itemsCargoSize[]={6,5};
	};
	class BomberJacket_ColorBase: Clothing
	{
		itemSize[]={3,3};
		itemsCargoSize[]={6,5};
	};
	class LeatherJacket_ColorBase: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={7,6};
	};
	class HuntingJacket_ColorBase: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={7,6};
	};
	class MedicalScrubsShirt_ColorBase: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={4,3};
	};
	class LabCoat: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={5,4};
	};
	class NurseDress_ColorBase: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={5,4};
	};
	class USMCJacket_ColorBase: Clothing
	{
		itemSize[]={3,2};
	};
	class Blouse_ColorBase: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={4,3};
	};
	class NBCJacketBase: Clothing
	{
		itemSize[]={2,3};
	};
	class DenimJacket: Clothing
	{
		itemSize[]={3,3};
		itemsCargoSize[]={6,5};
	};
	class TelnyashkaShirt: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={4,3};
	};
	class ChernarusSportShirt: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={4,3};
	};
	class JumpsuitJacket_ColorBase: Clothing
	{
		itemSize[]={3,3};
		itemsCargoSize[]={6,5};
	};
	class BDUJacket: Clothing
	{
		itemSize[]={3,2};
	};
	class ManSuit_ColorBase: Clothing
	{
		itemSize[]={3,3};
		itemsCargoSize[]={6,5};
	};
	class WomanSuit_ColorBase: Clothing
	{
		itemSize[]={3,3};
		itemsCargoSize[]={6,5};
	};
	class LeatherShirt_ColorBase: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={4,3};
	};
	class Chainmail: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={4,4};
	};
	
	class Jeans_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={5,4};
	};
	class CargoPants_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={6,4};
	};
	class TTSKOPants: Clothing
	{
		itemSize[]={3,2};
	};
	class HunterPants_ColorBase: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={6,4};
	};
	class CanvasPants_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={5,4};
	};
	class CanvasPantsMidi_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={5,4};
	};
	class TrackSuitPants_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={5,4};
	};
	class GorkaPants_ColorBase: Clothing
	{
		itemSize[]={3,2};
	};
	class PolicePants: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={5,4};
	};
	class PolicePantsOrel: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={6,4};
	};
	class ParamedicPants_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={6,4};
	};
	class FirefightersPants_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={6,4};
	};
	class PrisonUniformPants: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={5,4};
	};
	class LeatherPants_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={6,4};
	};
	class MedicalScrubsPants_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={5,4};
	};
	class USMCPants_ColorBase: Clothing
	{
		itemSize[]={3,2};
	};
	class SlacksPants_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={5,4};
	};
	class BDUPants: Clothing
	{
		itemSize[]={3,2};
	};
	class NBCPantsBase: Clothing
	{
		itemSize[]={3,2};
	};
	class Breeches_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={5,4};
	};
	class ShortJeans_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={5,4};
	};
	class Skirt_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={5,4};
	};
	class JumpsuitPants_ColorBase: Clothing
	{
		itemSize[]={3,2};
		itemsCargoSize[]={5,4};
	};
	class LegsCover_Improvised: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={4,3};
	};
	class Chainmail_Leggings: Clothing
	{
		itemSize[]={2,3};
		itemsCargoSize[]={4,4};
	};
};
