/**
 * LargeTentBackPack.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class LargeTentBackPack
{
	// Detect tent backpack being placed anywhere other than the player's back
	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.EEItemLocationChanged(oldLoc, newLoc);

		if (GetGame().IsDedicatedServer())
		{
			if (newLoc.GetType() != InventoryLocationType.ATTACHMENT)
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ZenPackTent, 1);
			}
		}
	}

	// Convert this tent backpack back into a packed tent
	private void ZenPackTent()
	{
		GetInventory().ReplaceItemWithNew(InventoryMode.SERVER, new ReplaceZenTentLambda(this, "LargeTent"));
	}

	// Only allow attaching tent to player
	override bool CanPutAsAttachment(EntityAI parent)
	{
		return super.CanPutAsAttachment(parent) && parent && parent.IsInherited(PlayerBase);
	}
};
