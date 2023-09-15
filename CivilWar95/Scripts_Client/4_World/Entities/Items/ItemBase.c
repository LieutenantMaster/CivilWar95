/**
 * ItemBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ItemBase
{
	static const float MAX_SOUND_RANGE = 25; // Mainly in place to stop bleed at long range

	bool IsPlayBackDevice()
	{
		return false;
	}

	bool GetEmptyItemReplacement(out string typeName)
	{
		//! TODO: Add in config.cpp a entry about item replacement to then scan here and return
		GetGame().ConfigGetText("cfgVehicles" + " " + GetType() + " "+ "EmptyReplaceWith", typeName);
		return (typeName != "");
	}

	bool ReplaceWithEmpty()
	{
		string typeName;
		if (GetEmptyItemReplacement(typeName))
		{
			PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
			if (player)
			{
				TurnItemIntoItemLambda lambda = new TurnItemIntoItemLambda(this, typeName, player);
				return player.ServerReplaceItemInHandsWithNew(lambda);
			}
		}

		return false;
	}

/*
#ifdef EXPANSIONMODBASEBUILDING
	string CW95_GetOriginalCodeOwner()
	{
		if (!IsInherited(ExpansionCodeLock) && !IsInherited(ExpansionSafeBase))
		{
			ExpansionCodeLock codelock = ExpansionGetCodeLock();
			if (codelock)
				return codelock.CW95_GetOriginalCodeOwner();
		}

		return "";
	}
	
	ExpansionCodeLock ExpansionGetCodeLock()
	{
		return ExpansionCodeLock.Cast(GetAttachmentByConfigTypeName("ExpansionCodeLock"));
	}
#endif
*/
};
