/**
 * ExpansionCodeLock.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

/*
#ifdef EXPANSIONMODBASEBUILDING
modded class ExpansionCodeLock
{
    private string m_OriginalOwnerId;

	override string CW95_GetOriginalCodeOwner()
	{
		return m_OriginalOwnerId;
	}

	override void SetUser( PlayerBase player )
	{
        super.SetUser(player);
        
        m_OriginalOwnerId = player.GetIdentityUID();
	}

	#ifdef EXPANSION_MODSTORAGE
	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		auto ctx = storage[DZ_CivilWar95];
		if (!ctx) return;
        
        ctx.Write( m_OriginalOwnerId );
	}
	
	override bool CF_OnStoreLoad(CF_ModStorageMap storage)
	{
		if (!super.CF_OnStoreLoad(storage))
			return false;

		auto ctx = storage[DZ_CivilWar95];
		if (!ctx) return true;

		string m_OriginalOwnerId;
		if (!ctx.Read(m_OriginalOwnerId))
        {
            if ( m_KnownUIDs.Count() > 0 )
            {
                m_OriginalOwnerId = m_KnownUIDs[0];
            } else {
			    return false;
            }
        }

		return true;
	}
	#endif
};
#endif
*/