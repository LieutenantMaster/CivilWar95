/**
 * ActionSmokeCigSelf.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

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