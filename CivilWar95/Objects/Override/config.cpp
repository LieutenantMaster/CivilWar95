class CfgPatches
{
	class CV95_Objects_Overrides
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Gear_Consumables",
			"DZ_Weapons_Melee",

			"DayZExpansion_Core_Objects_CircuitBoard",
			"DayZExpansion_Core_Objects_Currencies",
			"DayZExpansion_Objects_Gear_Guitar",
			"DayZExpansion_Objects_Misc",

			"PB_SmallMetalPlate"
		};
	};
};

class CfgVehicles
{
    class Inventory_Base;
	class CigarettePack_ColorBase;
	class Pliers;

	class ExpansionCircuitBoardBase;
	class ExpansionMoneyBar_Base;

	class WoodenLog: Inventory_Base
	{
		itemSize[]={3,9};
    };
	class CigarettePack_Chernamorka: CigarettePack_ColorBase
	{
		displayName = "Paquet de cigarettes 'Chernamorka'";
		descriptionShort = "Un paquet de cigarettes de la marque 'Chernamorka'. La marque préférée des vrais patriotes.";
	};
	class CigarettePack_Merkur: CigarettePack_ColorBase
	{
		displayName = "Paquet de cigarettes 'Merkur'";
		descriptionShort = "Un paquet de cigarettes de la marque 'Chernamorka'. Pas de doute, on trouvera pas mieux niveau qualité.";
	};
	class CigarettePack_Partyzanka: CigarettePack_ColorBase
	{
		displayName = "Paquet de cigarettes 'Partyzanka'";
		descriptionShort = "Un paquet de cigarettes de la marque 'Chernamorka'. Le goût est semblable à du foin, mélangé à du compost. Parfait pour cracher ses poumons avec classe et volupté.";
	};
	
	//!--------------- DAYZ EXPANSION ---------------
	class ExpansionCircuitBoard_MK1: ExpansionCircuitBoardBase
	{
		displayName = "Circuit Imprimé - Mk.1";
		descriptionShort = "Un circuit imprimé de qualité médiocre. Ça doit pas valoir grand chose mais bon, faut bien manger, hein?";
	};
	class ExpansionCircuitBoard_MK2: ExpansionCircuitBoardBase
	{
		displayName = "Circuit Imprimé - Mk.2";
		descriptionShort = "Un circuit imprimé de bonne qualité. Si on oublie la fine couche de poussière sur les composants, quelqu'un le rachèterait sûrement.";
	};
	class ExpansionCircuitBoard_MK3: ExpansionCircuitBoardBase
	{
		displayName = "Circuit Imprimé - Mk.3";
		descriptionShort = "Un circuit imprimé moderne. Bien qu'usé par les intempéries et les bombardements, il semble encore utilisable. Il doit certainement valoir son pesant d'or.";
	};
	class ExpansionSilverBar: ExpansionMoneyBar_Base
	{
		descriptionShort = "Un lingot d'argent issu de la Banque Centrale Chernare de Chernogorsk, pur à 99,99%. Petit veinard, va. Attention à ne pas se faire coincer avec.";
	};
	class ExpansionGoldBar: ExpansionMoneyBar_Base
	{
		descriptionShort = "Un lingot d'or pillé de la Banque Centrale Chernare de Chernogorsk, pur à 99,99%. Avec ça, y'a de quoi mettre babushka à l'abri définitivement. À condition de ne pas se faire coincer avec. ";
	};
	class ExpansionSilverNugget: ExpansionMoneyBar_Base
	{
		descriptionShort = "Une pépite d'argent pur, pillé de la Banque Centrale Chernare de Chernogorsk.";
	};
	class ExpansionGoldNugget: ExpansionMoneyBar_Base
	{
		descriptionShort = "Une pépite d'or pur, pillé de la Banque Centrale Chernare de Chernogorsk. Rien de mieux pour courtiser les krasavitsi.";
	};
	class ExpansionBoltCutters: Pliers
	{
		displayName = "Pince MoyGaspadim";
		descriptionShort = "L'outil du parfait ferrailleur, aucun métal ne lui résiste. Utile pour découper de la tôle ou les doigts de vos adversaires.";
	};
	class Expansion_Guitar: Inventory_Base
	{
		displayName = "Guitare 'Washburn EA20 Festival 1987' dédicacée";
		descriptionShort = "Cette guitare, bien qu'elle ne soit plus jouable en l'état, est dédicacée par les membres du fameux groupe de rock soviétique Pino. On peut y lire la signature de Viktor Stoï. Nul doute que certains fans vendraient leur mère pour une telle pièce de musée...";
	};
	class Expansion_Guitar_Old: Expansion_Guitar
	{
		displayName = "Vieille guitare";
		descriptionShort = "Cette guitare est aussi détruite qu'un militaire un jeudi soir à la popote. Autant la transformer d'office en petit bois.";
	};

	//!--------------- Doors and Barricade ---------------
	class PB_SmallMetalPlate: Inventory_Base
	{
		displayName = "Petite tôle";
		descriptionShort = "Un matériau de construction basique, utile pour bricoler ou barricader son domicile.";
	};
};

class CfgAmmo
{
	class MeleeDamage;
	class MeleeBlunt: MeleeDamage
	{
		class DamageApplied
		{
			type="Melee";
			class Health
			{
				damage=10;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=35;
			};
		};
	};
};