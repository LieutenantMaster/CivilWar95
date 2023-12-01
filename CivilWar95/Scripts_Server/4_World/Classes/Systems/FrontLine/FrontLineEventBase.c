class FrontLineEventBase
{
    vector m_TargetPos;
    vector m_NewPosition;
    float m_Radius;
    float m_MaxRadius;
    float m_Quantity;
    
    array<Object> m_Objects;

    void FrontLineEventBase(vector position, float radius, float quantity)
    {
        m_TargetPos     = position;
        m_NewPosition   = position;
        m_Radius        = radius;
        m_Quantity      = quantity;

        m_MaxRadius     = radius * 1.3;

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
        return string.Empty;
    }

    bool ShouldDelete()
    {
        return true;
    }
};
