/**
 * Cooking.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class Cooking
{
	override void ProcessItemToCook(notnull ItemBase pItem, ItemBase cookingEquip, Param2<CookingMethodType, float> pCookingMethod, out Param2<bool, bool> pStateFlags)
	{
		Inventory_Base item_to_disinfect = Inventory_Base.Cast(pItem);
		
		if ( item_to_disinfect && item_to_disinfect.CanBeDisinfected() )
		{
			bool hasWater = cookingEquip.IsLiquidPresent() && (cookingEquip.GetQuantity() / cookingEquip.GetQuantityMax()) > 0.2;
			float cooking_equipment_temp = cookingEquip.GetTemperature();
			if ( hasWater && cooking_equipment_temp >= 100 )
			{
				item_to_disinfect.SetWet( GameConstants.STATE_DAMP );
				item_to_disinfect.SetTemperature(60);
				item_to_disinfect.RemoveAllAgents();
				item_to_disinfect.SetCleanness( 1 );
				return;
			}
		}		
		
		super.ProcessItemToCook(pItem,  cookingEquip, pCookingMethod, pStateFlags);
	}
};
