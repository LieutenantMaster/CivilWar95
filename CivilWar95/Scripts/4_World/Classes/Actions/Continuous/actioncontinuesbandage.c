modded class ActionBandageSelfCB
{
	override void CreateActionComponent()
	{
		float effectivity = m_ActionData.m_MainItem.GetBandagingEffectivity();
		float adjusted_time_spent;
		
		if (effectivity > 0)
			adjusted_time_spent = UATimeSpent.BANDAGE / effectivity;

		m_ActionData.m_ActionComponent = new CAContinuousRepeat(adjusted_time_spent);
	}
};