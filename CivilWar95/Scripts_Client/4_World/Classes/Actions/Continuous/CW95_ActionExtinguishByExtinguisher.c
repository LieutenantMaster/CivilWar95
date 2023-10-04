class CW95_ActionExtinguishByExtinguisherCB : ActionContinuousBaseCB
{
	private const float TIME_TO_REPEAT				= 0.5;
	private const float WETNESS_GAIN_MULTIPLIER 	= 200.0;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CW95_CAContinuousQuantityExtinguish( UAQuantityConsumed.FIREPLACE_EXTINGUISHER, TIME_TO_REPEAT, WETNESS_GAIN_MULTIPLIER );
		CW95_CAContinuousQuantityExtinguish.Cast(m_ActionData.m_ActionComponent).MultiplyQuantityUsed(m_ActionData.m_MainItem.GetLiquidThroughputCoef());
	}
};

class CW95_ActionExtinguishByExtinguisher: ActionContinuousBase
{
	void CW95_ActionExtinguishByExtinguisher()
	{
		m_CallbackClass = CW95_ActionExtinguishByExtinguisherCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_FIREESTINGUISHER;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
		m_Text = "#extinguish";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINotRuinedAndEmpty;
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
        CW95_DynamicFire_Base fireplace_target = CW95_DynamicFire_Base.Cast( target.GetObject() );
		if ( fireplace_target && item )
			return !item.IsDamageDestroyed();
		
		return false;
	}
};
