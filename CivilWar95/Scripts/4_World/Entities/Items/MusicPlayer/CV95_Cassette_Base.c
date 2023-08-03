/**
 * CV95_Cassette_Base.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CV95_Cassette_Base: Inventory_Base
{
    private float currentPlaytime = -1;     // Current tick of the music (timestamp)
    private float m_CassetteLength;         // Amount of ticks the music has (length of the music)

    void CV95_Cassette_Base()
    {
        m_CassetteLength = ConfigGetFloat("trackTime");
        RegisterNetSyncVariableFloat("currentPlaytime");
    }

	#ifdef EXPANSION_MODSTORAGE
	override void CF_OnStoreSave(CF_ModStorageMap storage)
	{
		super.CF_OnStoreSave(storage);

		auto ctx = storage[DZ_CivilWar95];
		if (!ctx) return;

        ctx.Write( currentPlaytime );
	}

	override bool CF_OnStoreLoad(CF_ModStorageMap storage)
	{
		if (!super.CF_OnStoreLoad(storage))
			return false;

		auto ctx = storage[DZ_CivilWar95];
		if (!ctx) return true;

        if ( !ctx.Read( currentPlaytime ) )
            return false;

		return true;
	}
	#else
    override void OnStoreSave( ParamsWriteContext ctx )
    {
        super.OnStoreSave( ctx );

        ctx.Write( currentPlaytime );
    }
    
    override bool OnStoreLoad( ParamsReadContext ctx, int version )
    {
        if ( !super.OnStoreLoad( ctx, version ) )
            return false;
        
        if ( !ctx.Read( currentPlaytime ) )
            return false;

        return true;
    }
    #endif

    float GetCurrPlaytime()
    {
        return currentPlaytime;
    }

    void SetCurrPlaytime(float playTime)
    {
        currentPlaytime = playTime;
    }

    // same as the function above but I want the above function
    // to be as light as possible
    void RewindCurrPlaytime(float playTime)
    {
        currentPlaytime = currentPlaytime + playTime;

        if(currentPlaytime < 0)
            currentPlaytime = 0;
    }

    void FastForwardCurrPlaytime(float playTime)
    {
        currentPlaytime = currentPlaytime + playTime;

        if(currentPlaytime > m_CassetteLength)
            currentPlaytime = m_CassetteLength;
    }
};
