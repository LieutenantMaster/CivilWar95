class bldr_misc_barbedwire: House
{
	void bldr_misc_barbedwire()
	{
		CW95_StaticBarbedWire wireObj = CW95_StaticBarbedWire.Cast(Object.Cast(GetGame().CreateObject("CW95_StaticBarbedWire", "0 0 0")));

		if (wireObj)
		{
			wireObj.SetPosition(GetPosition());
			wireObj.SetOrientation(GetOrientation());
			wireObj.SetupDamageZone("-1 0 -0.4", "1 0.7 0.4");
		}
	}
};

class bldr_expansion_BarbedWire: House
{
	void bldr_expansion_BarbedWire()
	{
		CW95_StaticBarbedWire wireObj = CW95_StaticBarbedWire.Cast(Object.Cast(GetGame().CreateObject("CW95_StaticBarbedWire", "0 0 0")));

		if (wireObj)
		{
			wireObj.SetPosition(GetPosition());
			wireObj.SetOrientation(GetOrientation());
			wireObj.SetupDamageZone("-2.96 0 -0.77", "2.97 1.36 0.74");
		}
	}
};
class bldr_expansionBarbedWire: bldr_expansion_BarbedWire {};

class misc_barbedwire: House
{
	void misc_barbedwire()
	{
		CW95_StaticBarbedWire wireObj = CW95_StaticBarbedWire.Cast(Object.Cast(GetGame().CreateObject("CW95_StaticBarbedWire", "0 0 0")));

		if (wireObj)
		{
			wireObj.SetPosition(GetPosition());
			wireObj.SetOrientation(GetOrientation());
			wireObj.SetupDamageZone("-2.2 -1 -1", "2 1 1");
		}
	}
};

class misc_razorwire: House
{
	void misc_razorwire()
	{
		CW95_StaticBarbedWire wireObj = CW95_StaticBarbedWire.Cast(Object.Cast(GetGame().CreateObject("CW95_StaticBarbedWire", "0 0 0")));

		if (wireObj)
		{
			wireObj.SetPosition(GetPosition());
			wireObj.SetOrientation(GetOrientation());
			wireObj.SetupDamageZone("-4.3 -1 -1.1", "4.3 1.1 1.1");
		}
	}
};

class CW95_StaticBarbedWire: Inventory_Base
{
	protected ref AreaDamageLoopedDeferred_NoVehicle m_AreaDamage;

	void CW95_StaticBarbedWire()
	{
		SetPilotLight(true);
		SetIsHologram(true);
	}
	
	void ~CW95_StaticBarbedWire()
	{
		if ( m_AreaDamage )
			m_AreaDamage.Destroy();
	}

	void SetupDamageZone(string min, string max)
	{
		m_AreaDamage = new AreaDamageLoopedDeferred_NoVehicle(this);
		m_AreaDamage.SetDamageComponentType(AreaDamageComponentTypes.HITZONE);
		m_AreaDamage.SetLoopInterval(2);
		m_AreaDamage.SetDeferDuration(0.5);
		m_AreaDamage.SetExtents(min.ToVector(), max.ToVector());
		m_AreaDamage.SetHitZones( { "Torso","LeftHand","LeftLeg","LeftFoot","RightHand","RightLeg","RightFoot" } );
		m_AreaDamage.SetAmmoName("BarbedWireHit");
		m_AreaDamage.Spawn();
	}
};