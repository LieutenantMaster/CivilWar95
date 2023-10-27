/**
 * AirRaid.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class AirRaid
{
	// Map borders
	vector GetRandomMapBorder()
	{
		vector spawnpos = vector.Zero;
		float size = GetDayZGame().GetWorldSize();

		switch(Math.RandomIntInclusive(0,3)) 
		{
            case 0: 
			{
				spawnpos[0] = Math.RandomFloatInclusive(0, size);
                break;
            }
            case 1: 
			{
                spawnpos[0] = size;
				spawnpos[2] = Math.RandomFloatInclusive(0, size);
                break;
            }
            case 2: 
			{
				spawnpos[0] = Math.RandomFloatInclusive(0, size);
                break;
            }
            case 3: 
			{
				spawnpos[0] = Math.RandomFloatInclusive(0, size);
                spawnpos[2] = size;
                break;
            }
        }
		return spawnpos;
	}

	// Random but we smooth the result to get something closer to 0
	// usefull if we want to make something really rare
	int GetRandomIntMinus(int min, int max, int smoothing = 3)
	{
		int result = 0;
		for (int i=0; i < smoothing; i++)
		{
			result += Math.RandomIntInclusive(min, max);
		}

		return result / smoothing;
	}

	// EXP AI formations stuff
	//! TODO: grab from eAIFormations instead
	vector GetVeePos(int member_no, float scale = 100)
	{
		int offset = Math.Floor((member_no + 1) / 2);
		float scaled_offset = 2 * offset * scale;
		if (member_no % 2 == 0) return Vector(scaled_offset, 0, -scaled_offset); // Right side
		return Vector(-scaled_offset, 0, -scaled_offset); // Left Side
	}

	//! TODO: transfer this to eAIFormations
	vector GetVeeSidePos(int member_no, bool rightSide, float scale = 100)
	{
		int offset = member_no + 1;
		float scaled_offset = 2 * offset * scale;
		if (member_no % 2 == 0 || rightSide) return Vector(scaled_offset, 0, -scaled_offset); // Right side
		return Vector(-scaled_offset, 0, -scaled_offset); // Left Side
	}

	// Fake noise but will do for now
	//! TODO: Move all this functions into a global library
	vector Noise2D(vector pos)
	{
		pos[0] = pos[0] * Math.RandomFloat(-1.5, 1.5);
		pos[2] = pos[2] * Math.RandomFloat(-1.5, 1.5);
		return pos;
	}
	
	override void RandomStartBomber()
	{
		ARPlace locationCfg = m_ActiveARConfig.AirRaidLocations.GetRandomElement();
		int amount = Math.RandomIntInclusive(1,4);
		int formationSize = Math.RandomIntInclusive(20,40);
		int formationType = Math.RandomIntInclusive(1,3);
		float altitude = m_ActiveARConfig.BomberAltitude;
		float speed =  m_ActiveARConfig.BomberSpeed;
		bool triggerAlarm = true;

		vector pos;
		SpawnAirBase(locationCfg, "CW95_TU95", amount, formationSize, formationType, altitude, speed, pos);

		float Orispeed = speed;

		//! TODO: write a proper solution. This is aids
		if ( Math.RandomFloatInclusive(0.0,1.0) > 0.50 )
		{
			float multiplier;
			if ( Math.RandomFloatInclusive(0.0,1.0) > 0.75 )
			{
				amount = Math.RandomIntInclusive(1,3);
				formationSize = Math.RandomIntInclusive(35,50);
				formationType = Math.RandomIntInclusive(1,3);
				altitude = Math.RandomIntInclusive(55,80);
				speed = 60;

				multiplier = Math.RandomFloatInclusive(1.0,1.1);
				pos[0] = ( pos[0] / Orispeed ) * ( speed * multiplier );
				pos[1] = ( pos[1] / Orispeed ) * ( speed * multiplier );
				pos[2] = ( pos[2] / Orispeed ) * ( speed * multiplier );

				SpawnFollowerAirBase(locationCfg, pos, "CW95_Mi24", amount, formationSize, formationType, altitude, speed);
			}
			else
			{
				amount = Math.RandomIntInclusive(1,5);
				formationSize = Math.RandomIntInclusive(20,40);
				formationType = Math.RandomIntInclusive(1,3);
				altitude = Math.RandomIntInclusive(200,600);
				speed = 250;

				multiplier = Math.RandomFloatInclusive(0.9,1.1);
				pos[0] = ( pos[0] / Orispeed ) * ( speed * multiplier );
				pos[1] = ( pos[1] / Orispeed ) * ( speed * multiplier );
				pos[2] = ( pos[2] / Orispeed ) * ( speed * multiplier );

				SpawnFollowerAirBase(locationCfg, pos, "CW95_Mig21", amount, formationSize, formationType, altitude, speed);
			}
		}
	}
	
	override void RandomMig21Fly()
	{
		ARPlace locationCfg = m_ActiveARConfig.AirRaidLocations.GetRandomElement();
		int amount = Math.RandomIntInclusive(1,3);
		int formationSize = Math.RandomIntInclusive(20,40);
		int formationType = Math.RandomIntInclusive(1,3);
		float altitude = Math.RandomIntInclusive(400,600);
		float speed = 250;

		vector pos;
		SpawnAirBase(locationCfg, "CW95_Mig21", amount, formationSize, formationType, altitude, speed, pos);

		float Orispeed = speed;

		//! TODO: write a proper solution. This is aids
		if ( Math.RandomFloatInclusive(0.0,1.0) > 0.50 )
		{
			float multiplier;
			if ( Math.RandomFloatInclusive(0.0,1.0) > 0.75 )
			{
				amount = Math.RandomIntInclusive(1,2);
				formationSize = Math.RandomIntInclusive(35,50);
				formationType = Math.RandomIntInclusive(1,3);
				altitude = Math.RandomIntInclusive(55,80);
				speed = 60;

				multiplier = Math.RandomFloatInclusive(1.0,1.1);
				pos[0] = ( pos[0] / Orispeed ) * ( speed * multiplier );
				pos[1] = ( pos[1] / Orispeed ) * ( speed * multiplier );
				pos[2] = ( pos[2] / Orispeed ) * ( speed * multiplier );

				SpawnFollowerAirBase(locationCfg, pos, "CW95_Mi24", amount, formationSize, formationType, altitude, speed);
			}
			else
			{
				amount = Math.RandomIntInclusive(1,3);
				formationSize = Math.RandomIntInclusive(20,40);
				formationType = Math.RandomIntInclusive(1,3);
				altitude = Math.RandomIntInclusive(400,600);
				speed = 250;

				multiplier = Math.RandomFloatInclusive(0.9,1.1);
				pos[0] = ( pos[0] / Orispeed ) * ( speed * multiplier );
				pos[1] = ( pos[1] / Orispeed ) * ( speed * multiplier );
				pos[2] = ( pos[2] / Orispeed ) * ( speed * multiplier );

				SpawnFollowerAirBase(locationCfg, pos, "CW95_Mig21", amount, formationSize, formationType, altitude, speed);
			}
		}
	}
	
	override void RandomMi24Fly()
	{
		ARPlace locationCfg = m_ActiveARConfig.AirRaidLocations.GetRandomElement();
		int amount = Math.RandomIntInclusive(1,3);
		int formationSize = Math.RandomIntInclusive(35,50);
		int formationType = Math.RandomIntInclusive(1,3);
		float altitude = Math.RandomIntInclusive(55,80);
		float speed = 60;

		vector pos;
		SpawnAirBase(locationCfg, "CW95_Mi24", amount, formationSize, formationType, altitude, speed, pos);

		float Orispeed = speed;

		//! TODO: write a proper solution. This is aids
		if ( Math.RandomFloatInclusive(0.0,1.0) > 0.75 )
		{
			float multiplier;
			if ( Math.RandomFloatInclusive(0.0,1.0) > 0.25 )
			{
				amount = Math.RandomIntInclusive(1,3);
				formationSize = Math.RandomIntInclusive(35,50);
				formationType = Math.RandomIntInclusive(1,3);
				altitude = Math.RandomIntInclusive(55,80);
				speed = 60;

				multiplier = Math.RandomFloatInclusive(1.0,1.1);
				pos[0] = ( pos[0] / Orispeed ) * ( speed * multiplier );
				pos[1] = ( pos[1] / Orispeed ) * ( speed * multiplier );
				pos[2] = ( pos[2] / Orispeed ) * ( speed * multiplier );

				SpawnFollowerAirBase(locationCfg, pos, "CW95_Mi24", amount, formationSize, formationType, altitude, speed);
			}
			else
			{
				amount = Math.RandomIntInclusive(1,3);
				formationSize = Math.RandomIntInclusive(20,40);
				formationType = Math.RandomIntInclusive(1,3);
				altitude = Math.RandomIntInclusive(400,600);
				speed = 250;

				multiplier = Math.RandomFloatInclusive(0.9,1.1);
				pos[0] = ( pos[0] / Orispeed ) * ( speed * multiplier );
				pos[1] = ( pos[1] / Orispeed ) * ( speed * multiplier );
				pos[2] = ( pos[2] / Orispeed ) * ( speed * multiplier );

				SpawnFollowerAirBase(locationCfg, pos, "CW95_Mig21", amount, formationSize, formationType, altitude, speed);
			}
		}
	}
	
	override void RandomMi6Fly()
	{
		ARPlace locationCfg = m_ActiveARConfig.AirRaidLocations.GetRandomElement();
		int amount = Math.RandomIntInclusive(1,2);
		int formationSize = Math.RandomIntInclusive(35,50);
		int formationType = Math.RandomIntInclusive(1,3);
		float altitude = Math.RandomIntInclusive(55,80);
		float speed = 60;

		vector pos;
		SpawnAirBase(locationCfg, "CW95_Mi6", amount, formationSize, formationType, altitude, speed, pos);

		float Orispeed = speed;

		//! TODO: write a proper solution. This is aids
		if ( Math.RandomFloatInclusive(0.0,1.0) > 0.75 )
		{
			float multiplier;
			if ( Math.RandomFloatInclusive(0.0,1.0) > 0.25 )
			{
				amount = Math.RandomIntInclusive(1,3);
				formationSize = Math.RandomIntInclusive(35,50);
				formationType = Math.RandomIntInclusive(1,3);
				altitude = Math.RandomIntInclusive(55,80);
				speed = 60;

				multiplier = Math.RandomFloatInclusive(1.0,1.1);
				pos[0] = ( pos[0] / Orispeed ) * ( speed * multiplier );
				pos[1] = ( pos[1] / Orispeed ) * ( speed * multiplier );
				pos[2] = ( pos[2] / Orispeed ) * ( speed * multiplier );

				SpawnFollowerAirBase(locationCfg, pos, "CW95_Mi24", amount, formationSize, formationType, altitude, speed);
			}
			else
			{
				amount = Math.RandomIntInclusive(1,3);
				formationSize = Math.RandomIntInclusive(20,40);
				formationType = Math.RandomIntInclusive(1,3);
				altitude = Math.RandomIntInclusive(400,600);
				speed = 250;

				multiplier = Math.RandomFloatInclusive(0.9,1.1);
				pos[0] = ( pos[0] / Orispeed ) * ( speed * multiplier );
				pos[1] = ( pos[1] / Orispeed ) * ( speed * multiplier );
				pos[2] = ( pos[2] / Orispeed ) * ( speed * multiplier );

				SpawnFollowerAirBase(locationCfg, pos, "CW95_Mig21", amount, formationSize, formationType, altitude, speed);
			}
		}
	}

	//! TODO: Merge both functions and expand on it instead of having two different copies
	void SpawnFollowerAirBase(ARPlace locationCfg, vector pos, string classname, int amount, int formationSize, int formationType, float altitude, float speed)
	{
		vector targetpos = locationCfg.target.ToVector();
		vector bombingSpawn, posOffset, spawnPos;

		ARLogger.Log( "  Spawning " + amount + " " + classname);
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
			spawnPos[1] = altitude;
			CW95_AIRBase plane = CW95_AIRBase.Cast( GetGame().CreateObject( classname, spawnPos, false, false, true) );
			ARLogger.Log( "    id:" + i + " pos:" + spawnPos);
			
			bombingSpawn = targetpos + posOffset;
			bombingSpawn[1] = spawnPos[1];

			plane.CW95Setup(locationCfg, m_ActiveARConfig, bombingSpawn, speed + Math.RandomFloatInclusive(-1.0,1.0), altitude);
			plane.SetDirection(vector.Direction(spawnPos, bombingSpawn));
		}
	}

	void SpawnAirBase(ARPlace locationCfg, string classname, int amount, int formationSize, int formationType, float altitude, float speed, out vector pos)
	{
		vector mapEdgePos = GetRandomMapBorder();
		vector targetpos = locationCfg.target.ToVector();
		vector bombingSpawn, posOffset, spawnPos, dir;

		ARLogger.Log( "Spawning " + amount + " " + classname);

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
			spawnPos = Noise2D(mapEdgePos + posOffset);
			spawnPos[1] = altitude;
			CW95_AIRBase plane = CW95_AIRBase.Cast( GetGame().CreateObject( classname, spawnPos, false, false, true) );
			ARLogger.Log( "  id:" + i + " pos:" + spawnPos);
			
			bombingSpawn = targetpos + posOffset;
			bombingSpawn[1] = altitude;

			plane.CW95Setup(locationCfg, m_ActiveARConfig, bombingSpawn, speed + Math.RandomFloatInclusive(-1.0,1.0), altitude);
			plane.SetDirection(vector.Direction(spawnPos, bombingSpawn));
			ARLogger.Log( "  id:" + i + " pos:" + spawnPos + " dir:" + plane.GetDirection());

			if ( i == 0 )
			{
				plane.OnEventStart();
				pos = spawnPos;
				dir = plane.GetDirection();
				SendNotif(m_ActiveARPlaces.name);
			}
		}
	}
};
