// Extend grenade chemgas to create chemical cloud upon explosion
class CW95_ArtilleryBombChem: Grenade_ChemGas
{
	void CW95_ArtilleryBombChem()
	{
		SetAmmoType("CW95_ArtilleryBomb_Ammo");
		SetFuseDelay(1);
	}

	override void EOnInit(IEntity other, int extra)
	{
		#ifdef SERVER
		SetSynchDirty();
		#endif
	}

	override void Explode(int damageType, string ammoType = "")
	{
		super.Explode(damageType, ammoType);
		
		#ifdef SERVER
		SynchExplosion();
		vector offset = Vector(0, 0.1, 0);
		DamageSystem.ExplosionDamage(this, NULL, ammoType, GetPosition() + offset, damageType);
		DeleteThis();

		// Damage nearby objects defined in config
		CW95_ArtilleryBomb.DamageNearbyObjects(GetPosition());
		#endif
	}

	override void OnExplosionEffects(Object source, Object directHit, int componentIndex, string surface, vector pos, vector surfNormal, float energyFactor, float explosionFactor, bool isWater, string ammoType)
	{
		#ifndef SERVER
		vector n = surfNormal.VectorToAngles() + "0 90 0";

		Particle p2 = ParticleManager.GetInstance().PlayInWorld(ParticleList.EXPLOSION_LANDMINE, pos);
		p2.SetOrientation(n);

		Particle p3 = ParticleManager.GetInstance().PlayInWorld(ParticleList.IMPACT_METAL_RICOCHET, pos);
		p3.SetOrientation(n);

		Particle p4 = ParticleManager.GetInstance().PlayInWorld(ParticleList.IMPACT_GRAVEL_RICOCHET, pos);
		p4.SetOrientation(n);

		float dist = vector.Distance(pos, GetGame().GetPlayer().GetPosition());
		if (dist < 50)
			GetGame().GetPlayer().GetCurrentCamera().SpawnCameraShake(Math.InverseLerp(100, 0, dist) * 2);
		#endif
	}

	override void EEKilled(Object killer)
	{
		super.EEKilled(killer);
		Explode(DT_EXPLOSION, "CW95_ArtilleryBomb_Ammo");

		#ifdef SERVER
		SynchExplosion();
		#endif
	}

	void DeleteThis()
	{
		m_DeleteTimer = new Timer(CALL_CATEGORY_SYSTEM);
		m_DeleteTimer.Run(30, this, "DeleteSafe");
	}
};
