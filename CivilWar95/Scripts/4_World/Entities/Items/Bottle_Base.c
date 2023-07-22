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
