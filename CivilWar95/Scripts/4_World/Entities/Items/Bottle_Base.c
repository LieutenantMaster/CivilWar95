/**
 * Bottle_Base.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class Bottle_Base
{
	ref RainProcurementManager m_RainProcurement;

    void Bottle_Base()
    {
		m_RainProcurement = new RainProcurementManager( this );
    }

    override void ProcessItemWetness( float delta, bool hasParent, bool hasRootAsPlayer, ItemBase refParentIB )
	{
        super.ProcessItemWetness(delta, hasParent, hasRootAsPlayer, refParentIB);
        
		if ( !hasRootAsPlayer && !hasParent && !m_RainProcurement.IsRunning() )
            m_RainProcurement.InitRainProcurement();
        else if ( m_RainProcurement.IsRunning() )
            m_RainProcurement.StopRainProcurement();            
    }
};
