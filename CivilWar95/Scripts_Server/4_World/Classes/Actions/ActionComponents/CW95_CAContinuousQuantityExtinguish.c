modded class CW95_CAContinuousQuantityExtinguish
{
	override void CalcAndSetQuantity( ActionData action_data )
	{
        if ( m_SpentUnits )
        {
            m_SpentUnits.param1 = m_SpentQuantity;
            SetACData( m_SpentUnits );
        }
        
        CW95_DynamicFire_Base fireplace_target = CW95_DynamicFire_Base.Cast( action_data.m_Target.GetObject() );
        if ( fireplace_target )
        {				
            //add wetness to fireplace targets, set fire state to extinguishing
            float wetness_inc = ( m_SpentQuantity / 1000 ) * m_WetnessGainMultiplier;
            fireplace_target.DealWaterDamage( wetness_inc );
            
            //subtract quantity from water source
            action_data.m_MainItem.AddQuantity( -m_SpentQuantity );
        }
	}
	
	override int Interrupt( ActionData action_data )
	{
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( UASoftSkillsWeight.ROUGH_MEDIUM );
		
		return super.Interrupt( action_data );
	}
};
