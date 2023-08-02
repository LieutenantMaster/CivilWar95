modded class AirRaid
{
	vector GetRandomMapBorder()
	{
		vector spawnpos = vector.Zero;
		switch(Math.RandomInt(0,4)) 
		{
            case 0: 
			{
                spawnpos[2] = Math.RandomFloat(0.0, 15360.0);
                break;
            }
            case 1: 
			{
                spawnpos[0] = 15360.0;
                spawnpos[2] = Math.RandomFloat(0.0, 15360.0);
                break;
            }
            case 2: 
			{
                spawnpos[0] = Math.RandomFloat(0.0, 15360.0);
                break;
            }
            case 3: 
			{
                spawnpos[0] = Math.RandomFloat(0.0, 15360.0);
                spawnpos[2] = 15360.0;
                break;
            }
        }
		return spawnpos;
	}

	int GetRandomIntMinus(int min, int max, int smoothing = 3)
	{
		int result = 0;
		for (int i=0; i < smoothing; i++)
		{
			result += Math.RandomIntInclusive(min, max);
		}

		return result / smoothing;
	}

	vector GetVeePos(int member_no, float scale = 100)
	{
		int offset = Math.Floor((member_no + 1) / 2);
		float scaled_offset = 2 * offset * scale;
		if (member_no % 2 == 0) return Vector(scaled_offset, 0, -scaled_offset); // Right side
		return Vector(-scaled_offset, 0, -scaled_offset); // Left Side
	}

	vector GetVeeSidePos(int member_no, bool rightSide, float scale = 100)
	{
		int offset = member_no + 1;
		float scaled_offset = 2 * offset * scale;
		if (member_no % 2 == 0 || rightSide) return Vector(scaled_offset, 0, -scaled_offset); // Right side
		return Vector(-scaled_offset, 0, -scaled_offset); // Left Side
	}

	vector Noise2D(vector pos)
	{
		pos[0] = pos[0] * Math.RandomFloat(-1.5, 1.5);
		pos[2] = pos[2] * Math.RandomFloat(-1.5, 1.5);
		return pos;
	}

	override void RandomStartBomber()
	{
		m_ActiveARPlaces = m_ActiveARConfig.AirRaidLocations.GetRandomElement();

		vector pos = GetRandomMapBorder();

		pos[1] = m_ActiveARConfig.BomberAltitude;

		int amount = GetRandomIntMinus(1,6,2);
		
		int formationSize = Math.RandomIntInclusive(40,60);
		vector targetpos = m_ActiveARPlaces.target.ToVector();
		vector planedir, bombingSpawn, posOffset, spawnPos;
		float Speed =  m_ActiveARConfig.BomberSpeed;
		float Height = m_ActiveARConfig.BomberAltitude;

		for (int i=0; i < amount; i++)
		{
			posOffset = GetVeePos(i, formationSize);
			spawnPos = Noise2D(pos + posOffset);
			BomberPlane plane = BomberPlane.Cast( GetGame().CreateObject( "BomberPlane", spawnPos, false, true, true) );
			
			bombingSpawn = targetpos + posOffset;
			bombingSpawn[1] = spawnPos[1];

			plane.CV95SetupRandom(m_ActiveARPlaces, m_ActiveARConfig, bombingSpawn, Speed, Height);
			plane.SetDirection(spawnPos - bombingSpawn);

			if ( i == 0 )
			{
				planedir = plane.GetDirection();
				plane.SirenPos(m_ActiveARPlaces.sirenpos.ToVector());
				SendNotif(m_ActiveARPlaces.name);
			}
		}

		int formationType = Math.RandomIntInclusive(1,3);
		formationSize = Math.RandomIntInclusive(20,40);
		
		vector posAhead;
        posAhead[0] = pos[0] + planedir[0] * Math.RandomIntInclusive(-3000,-2500);
        posAhead[1] = pos[1] + planedir[1] * Math.RandomIntInclusive(-3000,-2500);
        posAhead[2] = pos[2] + planedir[2] * Math.RandomIntInclusive(-3000,-2500);
		
		int escortCount = (Math.RandomIntInclusive(1, amount) - amount) + amount;

		for (int j=0; j < escortCount; j++)
		{
			posOffset;
			switch(formationType)
			{
				case 1:
				{
					posOffset = GetVeePos(j, formationSize);
					break;
				}
				case 2:
				{
					posOffset = GetVeeSidePos(j, true, formationSize);
					break;
				}
				case 3:
				{
					posOffset = GetVeeSidePos(j, false, formationSize);
					break;
				}
			}

			spawnPos = posAhead + posOffset;
			ARMig21 mig = ARMig21.Cast( GetGame().CreateObject( "ARMig21", spawnPos, false, true, true) );
			
			bombingSpawn;
			bombingSpawn = targetpos + posOffset;
			bombingSpawn[1] = spawnPos[1];

			mig.CV95SetupRandom(m_ActiveARPlaces, m_ActiveARConfig, bombingSpawn, 250, m_ActiveARConfig.BomberAltitude);
			mig.SetDirection(spawnPos - bombingSpawn);
		}
	}
	
	override void RandomMig21Fly()
	{
		m_ActiveMig21Places = m_ActiveARConfig.AirRaidLocations.GetRandomElement();
		
		vector pos = GetRandomMapBorder();
		pos[1] = 550;

		int amount = Math.RandomIntInclusive(1,3);
		int formationSize = Math.RandomIntInclusive(20,40);
		int formationType = Math.RandomIntInclusive(1,3);
		vector targetpos = m_ActiveARPlaces.target.ToVector();
		vector bombingSpawn, posOffset, spawnPos;

		for (int i=0; i < amount; i++)
		{
			switch(formationType)
			{
				case 1:
				{
					posOffset = GetVeePos(i, formationSize);
					break;
				}
				case 2:
				{
					posOffset = GetVeeSidePos(i, true, formationSize);
					break;
				}
				case 3:
				{
					posOffset = GetVeeSidePos(i, false, formationSize);
					break;
				}
			}
			spawnPos = Noise2D(pos + posOffset);
			ARMig21 plane = ARMig21.Cast( GetGame().CreateObject( "ARMig21", spawnPos, false, true, true) );
			
			bombingSpawn = targetpos + posOffset;
			bombingSpawn[1] = spawnPos[1];

			plane.CV95SetupRandom(m_ActiveARPlaces, m_ActiveARConfig, bombingSpawn, 250 + Math.RandomFloatInclusive(-1.0,1.0), pos[1]);
			plane.SetDirection(spawnPos - bombingSpawn);

			if ( i == 0 )
				SendNotif(m_ActiveARPlaces.name);
		}		
	}
	
	override void RandomMi24Fly()
	{
		m_ActiveMi24Places = m_ActiveARConfig.AirRaidLocations.GetRandomElement();
		
		vector pos = GetRandomMapBorder();
		pos[1] = Math.RandomIntInclusive(75,120);

		int amount = Math.RandomIntInclusive(1,2);
		int formationSize = Math.RandomIntInclusive(35,50);
		int formationType = Math.RandomIntInclusive(1,2);
		vector targetpos = m_ActiveARPlaces.target.ToVector();
		vector bombingSpawn, posOffset, spawnPos;

		for (int i=0; i < amount; i++)
		{
			switch(formationType)
			{
				case 1:
				{
					posOffset = GetVeeSidePos(i, true, formationSize);
					break;
				}
				case 2:
				{
					posOffset = GetVeeSidePos(i, false, formationSize);
					break;
				}
			}
			spawnPos = Noise2D(pos + posOffset);
			ARMi24 plane = ARMi24.Cast( GetGame().CreateObject( "ARMi24", spawnPos, false, true, true) );
			
			bombingSpawn = targetpos + posOffset;
			bombingSpawn[1] = spawnPos[1];

			plane.CV95SetupRandom(m_ActiveARPlaces, m_ActiveARConfig, bombingSpawn, 78 + Math.RandomFloatInclusive(-1.0,1.0), pos[1]);
			plane.SetDirection(spawnPos - bombingSpawn);

			if ( i == 0 )
				SendNotif(m_ActiveARPlaces.name);
		}
	}
};
