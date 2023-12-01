class CW95_ActionMeasureFuel: ActionSingleUseBase
{	
	protected float m_FuelQuantity;

	void CW95_ActionMeasureFuel()
	{
		m_FullBody = false;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
	
	override string GetText()
	{
		if (m_FuelQuantity != -1)
			return string.Empty + m_FuelQuantity + "L";

		return "Measure fuel level";
	}

	override void CreateConditionComponents() 
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        CarScript car = CarScript.Cast( target.GetObject() );
        if (car)
		{
			array<string> selections = new array<string>;
			target.GetObject().GetActionComponentNameList(target.GetComponentIndex(), selections);
            for (int s = 0; s < selections.Count(); s++)
			{
                if ( selections[s] == car.GetActionCompNameFuel() )
				{
                    vector refillPointPos = car.GetRefillPointPosWS();
                    float dist = vector.DistanceSq(refillPointPos, player.GetPosition());
                    float distanceFuel = car.GetActionDistanceFuel() * car.GetActionDistanceFuel();
					
                    if (dist <= distanceFuel)
                        return true;
                }
            }
        }

		return false;
	}

    override void OnExecute( ActionData action_data )
	{
		CarScript car = CarScript.Cast( action_data.m_Target.GetObject() );
        if (car)
		{
            float fuelCapacity = car.GetFluidCapacity( CarFluid.FUEL );
            float currentFuel = car.GetFluidFraction( CarFluid.FUEL );
            m_FuelQuantity = currentFuel * fuelCapacity;
        }
	}
};
