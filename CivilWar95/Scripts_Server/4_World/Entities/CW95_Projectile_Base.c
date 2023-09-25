/**
 * CW95_Projectile_Base.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class CW95_Projectile_Base
{
	override void EOnContact(IEntity other, Contact extra) 
	{
		if ( !m_Exploded )//&& m_FuseTimer.GetRemaining() <= m_SafetyDelay )
		{
			m_Exploded = true;
			ActivateImmediate();
		}
	}

	override void OnDamageDestroyed(int oldLevel)
	{
		return;
		
		if ( !m_Exploded )
		{
			m_Exploded = true;
			ActivateImmediate();
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(Delete, 1000);
		}
	}
};
