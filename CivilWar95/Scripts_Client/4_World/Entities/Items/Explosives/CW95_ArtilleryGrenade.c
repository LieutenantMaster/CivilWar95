class CW95_ArtillerySmokeGrenade: M18SmokeGrenade_ColorBase
{
	int m_BombCount = 0;

	void CW95_ArtillerySmokeGrenade()
	{
		SetParticleSmokeStart(ParticleList.GRENADE_M18_RED_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_RED_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_RED_END);
	}

	override void OnWorkStart()
	{
		super.OnWorkStart();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StartBombs, Math.RandomInt(5000, 20000), false, this);
	}

	string GetBombType()
	{
		return "CW95_ArtilleryBomb";
	}

	void StartBombs()
	{
		int i;
		float currentDist = 50000;
		vector firePos;
		vector smokePos = GetPosition();

		for (i = 0; i < GetGame().GetMission().GetWorldData().GetArtyFiringPos().Count(); i++)
		{
			vector v = GetGame().GetMission().GetWorldData().GetArtyFiringPos().Get(i);
			float dist = vector.Distance(v, smokePos);

			if (dist < currentDist)
			{
				currentDist = dist;
				firePos = v;
			}
		}

		array<Man> all_players = new array<Man>;
		GetGame().GetPlayers(all_players);
		for (i = 0; i < all_players.Count(); i++)
		{
			PlayerBase player;
			Class.CastTo(player, all_players.Get(i));
			if (player)
				GetRPCManager().SendRPC("ZAS_RPC", "RPC_ZAS_ReceiveAirstrikeData", new Param1< vector >(firePos), true, player.GetIdentity(), player);
		}

		int randomDelay = Math.RandomInt(2, 6) * 1000;
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StartDroppingBombs, randomDelay, false, this);
	}

	void StartDroppingBombs()
	{
		m_BombCount = Math.RandomIntInclusive(8, 16);
		DropBomb();
	}

	void DropBomb()
	{
		vector pos = GetPosition();

		// Get radius & random x/y
		int radius = 25;
		float randomX = Math.RandomFloatInclusive(-radius, radius);
		float randomY = Math.RandomFloatInclusive(-radius, radius);

		// Set bomb position
		pos[0] = pos[0] + randomX;
		pos[2] = pos[2] + randomY;
		pos[1] = GetGame().SurfaceY(pos[0], pos[2]); // Get surface

		// Create bomb
		Object bomb = GetGame().CreateObject(GetBombType(), pos);
		bomb.PlaceOnSurface();
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DetonateBomb, Math.RandomInt(150, 300), false, bomb);

		m_BombCount = m_BombCount - 1;
		if (m_BombCount > 0)
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DropBomb, Math.RandomInt(200, 3000), false);
	}

	// When grenade_base is ruined it explodes
	void DetonateBomb(Object bomb)
	{
		bomb.SetHealth(0); 
	}
};

// Chem version
class CW95_ArtillerySmokeGrenadeChem : CW95_ArtillerySmokeGrenade
{
	void CW95_ArtillerySmokeGrenadeChem()
	{
		// Set chemical artillery colour
		SetParticleSmokeStart(ParticleList.GRENADE_M18_GREEN_START);
		SetParticleSmokeLoop(ParticleList.GRENADE_M18_GREEN_LOOP);
		SetParticleSmokeEnd(ParticleList.GRENADE_M18_GREEN_END);
	}

	override string GetBombType()
	{
		return "CW95_ArtilleryBombChem";
	}
};
