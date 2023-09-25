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
		InventoryLocation loc = new InventoryLocation;
		entity.GetInventory().GetCurrentInventoryLocation(loc);
		EntityAI parent = loc.GetParent();
		if ( parent )
		{
			parent.GetInventory().GetCurrentInventoryLocation(loc);
			if (loc.GetSlot() == InventorySlots.BACK)
				return false;
		}

		return super.CanAddAsShortcut(entity);
	}
};
