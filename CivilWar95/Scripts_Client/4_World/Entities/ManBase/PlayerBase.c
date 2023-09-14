/**
 * PlayerBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class PlayerBase
{
	//protected bool m_IsWounded;
	//protected autoprt TIntArray m_Injuries;

	override void SetActions()
	{
		super.SetActions();

		AddAction(CW95_ActionKnockAtDoor);
    }

	#ifdef EXPANSION_MODSTORAGE
	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		auto ctx = storage[DZ_CivilWar95];
		if (!ctx) return;

		ctx.Write(eAI_GetFactionTypeID());
	}
	
	override bool CF_OnStoreLoad(CF_ModStorageMap storage)
	{
		if (!super.CF_OnStoreLoad(storage))
			return false;

		auto ctx = storage[DZ_CivilWar95];
		if (!ctx) return true;

        int factionTypeID;
		if (!ctx.Read(factionTypeID))
			return false;
            
		typename factionType = eAIFaction.GetTypeByID(factionTypeID);
		if (factionType)
		{
			eAIFaction faction = eAIFaction.Cast(factionType.Spawn());
			if (faction)
			{
				if (GetGroup())
				{
					GetGroup().SetFaction(faction);
				}
				else
				{
					eAIGroup group = eAIGroup.GetGroupByLeader(this, true, faction);
				}
			}
		}

		return true;
	}
	#endif
	
	override EStatLevels GetStatLevelHealth()
	{
		float health = GetHealth("","");
		return GetStatLevel(health, 20, 40, 70, 85);
	}

	override void OnCommandVehicleStart()
	{
		super.OnCommandVehicleStart();
		
		if ( GetInventory() )
			GetInventory().UnlockInventory(LOCK_FROM_SCRIPT);		
	}
	
	override void OnCommandVehicleFinish()
	{
		if ( GetInventory() )
			GetInventory().LockInventory(LOCK_FROM_SCRIPT);
		
		super.OnCommandVehicleFinish();		
	}

	static bool IsWounded()
	{
		return false;
	}
	
	bool FindWoundType( int woundType )
	{
		return false;
	}
};
