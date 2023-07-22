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
};

/*
//! Proof of concept here
modded class TacticalBaconCan_Opened
{
	override bool GetEmptyItemReplacement(out string typeName)
	{
		typeName = "Compass";

		return true;
	}
};
*/