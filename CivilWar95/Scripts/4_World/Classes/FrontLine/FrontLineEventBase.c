class FrontLineEventBase
{
    private vector m_TargetPos;
    private vector m_NewPosition;
    private float m_Radius;
    private float m_MaxRadius;
    private float m_Quantity;
    
    private array<Object> m_Objects;

    void FrontLineEventBase(vector position, float radius, float quantity)
    {
        m_TargetPos = position;
        m_NewPosition   = position;
        m_Radius    = radius;
        m_Quantity  = quantity;

        m_MaxRadius = radius * 1.3;

        Spawn();
    }

    void Spawn()
    {        
        vector position;
        if ( vector.Distance(m_NewPosition, m_TargetPos) > m_MaxRadius )
        {
            m_NewPosition = m_TargetPos + Vector(Math.RandomFloatInclusive(-m_Radius, m_Radius), 0, Math.RandomFloatInclusive(-m_Radius, m_Radius));
        }
        else
        {
            m_NewPosition = m_NewPosition + Vector(Math.RandomFloatInclusive(-m_Radius, m_Radius), 0, Math.RandomFloatInclusive(-m_Radius, m_Radius));
        }
        
        m_Objects.Insert(GetGame().CreateObjectEx( GetItemToSpawn(), m_NewPosition, ECE_PLACE_ON_SURFACE ));

        if ( m_Quantity > 0 )
        {
            m_Quantity--;
            GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( Spawn, Math.RandomIntInclusive(2000, 10000), false );
        }
    }

    static string GetItemToSpawn()
    {
        return "";
    }

    bool ShouldDelete()
    {
        return true;
    }
};
