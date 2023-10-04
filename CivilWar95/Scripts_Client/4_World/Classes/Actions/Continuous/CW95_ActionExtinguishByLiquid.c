class CW95_ActionExtinguishByLiquidCB : ActionContinuousBaseCB
{
	private const float TIME_TO_REPEAT 				= 0.5;
	private const float WETNESS_GAIN_MULTIPLIER 	= 50.0;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CW95_CAContinuousQuantityExtinguish( UAQuantityConsumed.FIREPLACE_LIQUID, TIME_TO_REPEAT, WETNESS_GAIN_MULTIPLIER );
		CW95_CAContinuousQuantityExtinguish.Cast(m_ActionData.m_ActionComponent).MultiplyQuantityUsed(m_ActionData.m_MainItem.GetLiquidThroughputCoef());
	}
};

class CW95_ActionExtinguishByLiquid: ActionContinuousBase
{
	void CW95_ActionExtinguishByLiquid()
	{
		m_CallbackClass = CW95_ActionExtinguishByLiquidCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		m_FullBody = true;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
		m_Text = "#extinguish";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINotRuinedAndEmpty;
		m_ConditionTarget = new CCTObject(UAMaxDistances.SMALL);
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        CW95_DynamicFire_Base fireplace_target = CW95_DynamicFire_Base.Cast( target.GetObject() );
		if ( fireplace_target && item )
        {
			if ( !item.IsDamageDestroyed() && (item.GetLiquidType() & (GROUP_LIQUID_BLOOD | LIQUID_WATER | LIQUID_RIVERWATER | LIQUID_BEER)) )
			{
				return true;
			}
		}
		
		return false;
	}
};
