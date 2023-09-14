/**
 * QuickBarBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class QuickBarBase
{	
	override bool CanAddAsShortcut(EntityAI entity)
	{
		EntityAI ent = entity;
		while (!ent)
		{
			InventoryLocation loc = new InventoryLocation;
			if (!ent.GetInventory().GetCurrentInventoryLocation(loc))
				break;
			
			if (loc.GetSlot() == InventorySlots.BACK)
				return false;

			ent = loc.GetParent();
		}

		return super.CanAddAsShortcut(entity);
	}
};
