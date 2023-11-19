/**
 * Expansion_RPG_Explosion.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class Expansion_RPG_Explosion
{
	override void ExplodeNow()
	{
		Explode(DT_EXPLOSION, "CW95_ProjectileRPG_Ammo");

#ifndef SERVER
        m_ParticleExplosion = Particle.PlayInWorld(ParticleList.EXPANSION_EXPLOSION_ROCKET, GetPosition());
#endif
	}
};