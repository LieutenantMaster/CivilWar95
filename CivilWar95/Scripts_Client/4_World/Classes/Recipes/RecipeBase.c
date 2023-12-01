/**
 * RecipeBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class RecipeBase
{
	// Hi-jack ingredient sound here whenever appropriate to cover multiple recipes
	// and to allow compatability with future vanilla updates (InsertIngredientEx() will be used directly to add sounds and this would be ignored)
	override void InsertIngredient(int index, string ingredient)
	{
		switch (ingredient)
		{
			case "SewingKit":
				InsertIngredientEx(index, ingredient, "Zen_SewingKit");
				return;
			case "LeatherSewingKit":
				InsertIngredientEx(index, ingredient, "Zen_LeatherSewingKit");
				return;
			case "Whetstone":
				InsertIngredientEx(index, ingredient, "Zen_SharpenMelee");
				return;
			case "WeaponCleaningKit":
				InsertIngredientEx(index, ingredient, "Zen_CleanWeapon");
				return;
			case "DisinfectantAlcohol":
			case "IodineTincture":
				InsertIngredientEx(index, ingredient, "Zen_DisinfectBottle");
				return;
			case "DisinfectantSpray":
				InsertIngredientEx(index, ingredient, "Zen_DisinfectSpray");
				return;
			case "DuctTape":
				InsertIngredientEx(index, ingredient, "Zen_DuctTape");
				return;
			case "Spraycan_ColorBase":
				InsertIngredientEx(index, ingredient, "Zen_SprayPaint");
				return;
			case "TireRepairKit":
				InsertIngredientEx(index, ingredient, "Zen_Rubber");
				return;
			case "SmallStone":
			case "Stone":
				InsertIngredientEx(index, ingredient, "Zen_BreakStone");
				return;
			case "BarbedWire":
				InsertIngredientEx(index, ingredient, "Zen_MetalWire");
				return;
			case "WoodenPlank":
				InsertIngredientEx(index, ingredient, "Zen_Wood");
				return;
			case "Nail":
				InsertIngredientEx(index, ingredient, "Zen_Nails");
				return;
			case "Flag_Base":
			case "Armband_ColorBase":
			case "Raincoat_ColorBase":
				InsertIngredientEx(index, ingredient, "Zen_CraftRag");
				return;
			case "ElectronicRepairKit":
				InsertIngredientEx(index, ingredient, "Zen_ElectronicRepair");
				return;
			case "Paper":
				InsertIngredientEx(index, ingredient, "Zen_Paper");
				return;
			default:
				break;
		}

		InsertIngredientEx(index, ingredient, string.Empty);
	};
}