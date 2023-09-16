modded class FuelStation
{
	protected int m_FuelMaxQuantity = 1000;
	protected float m_FuelQuantity;

	protected bool m_IsDestroyed;
	protected bool m_IsEmpty;
	
	void FuelStation()
	{
		RegisterNetSyncVariableBool("m_IsDestroyed");
		RegisterNetSyncVariableBool("m_IsEmpty");
	}

	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		
		m_IsDestroyed = true;
		SetSynchDirty();
	}

	void RemoveFuel(float quantity)
	{
		m_FuelQuantity -= quantity;
		if ( m_FuelQuantity <= 0 )
		{
			m_FuelQuantity = 0;
			m_IsEmpty = true;
		}

		SetSynchDirty();
	}

	void AddFuel(float quantity)
	{
		m_FuelQuantity += quantity;

		if ( m_FuelQuantity > m_FuelMaxQuantity )
			m_FuelQuantity = m_FuelMaxQuantity;
		else if ( m_FuelQuantity > 0 && m_IsEmpty )
			m_IsEmpty = false;

		SetSynchDirty();
	}
	
	override bool IsRuined()
	{
		return m_IsDestroyed;
	}
	
	bool IsEmpty()
	{
		return m_IsEmpty;
	}
};
