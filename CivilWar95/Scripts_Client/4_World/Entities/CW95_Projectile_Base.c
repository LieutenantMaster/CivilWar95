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

class CW95_Projectile_Base: Grenade_Base
{
	protected bool m_PinnedSync;
	protected bool m_Exploded;
	protected float m_SafetyDelay;

	void CW95_Projectile_Base()
	{
		//SetEventMask(EntityEvent.CONTACT | EntityEvent.SIMULATE);
		SetEventMask(EntityEvent.CONTACT); //! TODO: Investigate why this can cause server crash

		SetFuseDelay(5);
		SetPinnable(false);

		m_SafetyDelay = m_FuseDelay - 0.1; 

#ifndef SERVER
		CW95_ClientEarlyStartEffect();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( CW95_ClientStartEffect, 250, false );
#endif
	}

	override void Pin()
	{
		// You cant pin back a missile/bomb
	}

	void CW95_ClientEarlyStartEffect()
	{

	}

	void CW95_ClientStartEffect()
	{

	}

	void CW95_ClientEndEffect()
	{
		
	}
	
#ifndef SERVER
	override void OnExplosionEffects(Object source, Object directHit, int componentIndex, string surface, vector pos, vector surfNormal, float energyFactor, float explosionFactor, bool isWater, string ammoType)
	{
		super.OnExplosionEffects(source, directHit, componentIndex, surface, pos, surfNormal, energyFactor, explosionFactor, isWater, ammoType);

		CW95_ClientEndEffect();
	}
#endif

	override bool CanPutInCargo (EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

	override bool CanExplodeInFire()
	{
		return true;
	}
};
