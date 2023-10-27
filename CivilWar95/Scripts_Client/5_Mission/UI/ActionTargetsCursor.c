/**
 * ActionTargetsCursor.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ActionTargetsCursor
{
	// Hide action target cursor until player has completed lie-down emote
	override void Update()
	{
		if (m_Player && m_Player.GetSimulationTimeStamp() < 300)
			m_Hidden = true;

		super.Update();
	}
};