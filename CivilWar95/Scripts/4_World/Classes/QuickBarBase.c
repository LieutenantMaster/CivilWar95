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
