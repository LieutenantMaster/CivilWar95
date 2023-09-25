class CW95_CAContinuousQuantityExtinguish: CAContinuousQuantityRepeat
{
	private float m_WetnessGainMultiplier 	= 1.0;
	
	void CW95_CAContinuousQuantityExtinguish( float quantity_used_per_second, float time_to_repeat, float wetness_gain_multiplier )
	{
		m_QuantityUsedPerSecond = quantity_used_per_second;
		m_DefaultTimeToRepeat = time_to_repeat;
		m_WetnessGainMultiplier = wetness_gain_multiplier;
	}
	
	override void CalcAndSetQuantity( ActionData action_data )
	{
		// Server side
	}
	
	void MultiplyQuantityUsed(float coef)
	{
		m_QuantityUsedPerSecond *= coef;
	}
};
