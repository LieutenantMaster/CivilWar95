modded class ActionSmokeCigSelf
{
	private static float CV95_MAXPLAYERHEALTH = 75;

	override string GetText()
	{
		return "Fumer";
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);

		float currHealth = action_data.m_Player.GetHealth();
		if( currHealth < CV95_MAXPLAYERHEALTH )
		{
			currHealth = currHealth + Math.Lerp(currHealth, CV95_MAXPLAYERHEALTH, 1 * action_data.m_Player.GetDeltaT());
			action_data.m_Player.SetHealth(currHealth);
		}
    }
};