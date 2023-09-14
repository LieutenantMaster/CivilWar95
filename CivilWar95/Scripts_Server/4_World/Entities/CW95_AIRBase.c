/**
 * CW95_AIRBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class CW95_AIRBase
{
	ref ARPlace m_ActiveARPlaces;
	ref ARConfig m_ActiveARConfig;

	protected autoptr TStringArray m_AnimSelections = {"rotor"};

	// Plane data, will need to expand with turn rate stuff
	protected float m_TargetSpeed;
	protected float m_Speed;
	protected float m_Height;
	protected float m_Angle;
	
	// Objective stuff
	protected bool m_ReachedTarget;
	protected vector m_Location;
	protected float m_Radius;

	// Mostly cosmetics stuff
	protected float m_RotorAnimationPosition;
	protected float m_FollowTerrainFraction = 0.7;
	protected float m_DefaultPitch = 0.0;
	protected float m_MaxPitch = -45.0;
	protected float m_PlaneSize = -10.0;

	// Smooth Altitude required variables
	protected int m_TargetAltitudeBufferCount;
	protected float m_TargetAltitudeBuffer[40];
	protected float m_PrevTargetAltitude;

	private Object m_HitObject;
	private vector m_HitPosition;
	private vector m_HitNormal;
	private float m_HitFraction;

	void CW95Setup(ARPlace activeARPlaces, ARConfig activeARConfig, vector targetpos, float speed, float altitude)
	{
		m_ActiveARPlaces = activeARPlaces;
		m_ActiveARConfig = activeARConfig;
		
		m_TargetSpeed = speed;
		m_Speed = speed;
		m_Height = altitude;
		m_Location = targetpos;
		m_Radius = 300;

		vector position = GetPosition();
		m_Angle = Math.Atan2( targetpos[2] - position[2], targetpos[0] - position[0] );
	}

	override void EOnSimulate( IEntity owner, float dt )
	{
		CW95Simulate(dt);
	}

	protected void CW95Simulate( float dt )
	{
		vector velocity = Vector( Math.Cos( m_Angle ), 0, Math.Sin( m_Angle ) );

		velocity[0] = velocity[0] * m_Speed * dt;
		velocity[2] = velocity[2] * m_Speed * dt;
				
		vector transform[4];
		GetTransform( transform );
		transform[3] = transform[3] + velocity;
		float angle;
		transform[3][1] = CW95SimulateAltitude(velocity, dt, angle);

		MoveInTime( transform, dt );

		vector angles = GetAngles();
		angles[0] = angle;
		SetAngles(angles);

		CW95Animate(dt);

		if (CW95_EOnBeforeDelete())
			CW95_ClearAll();
	}

	protected float CW95SimulateAltitude(vector velocity, float dt, out float angle )
	{
		vector position = GetPosition();
		vector angles = GetAngles();
		//! Plane will be at this pos in 1s - react to terrain elevation changes in advance
		float terrainY = GetTerrainY( position + velocity );
		float altitude = position[1];
		float targetAltitude = Math.Lerp( altitude, terrainY + m_Height, m_FollowTerrainFraction );
		float targetAltitudeSum;

		//! Altitude buffer for smoothing
		for ( int i = 0; i < 40; i++ )
		{
			float bufferVal;

			if ( i < 39 )
				bufferVal = m_TargetAltitudeBuffer[i + 1];
			else
				bufferVal = targetAltitude;

			m_TargetAltitudeBuffer[i] = bufferVal;

			targetAltitudeSum += bufferVal;
		}

		if ( m_TargetAltitudeBufferCount < 40 )
			m_TargetAltitudeBufferCount++;

		targetAltitude = targetAltitudeSum / m_TargetAltitudeBufferCount;

		if ( m_TargetAltitudeBufferCount > 1 )
		{
			float signScale;

			if ( targetAltitude < altitude )
			{
				//! Descend at half the rate of ascend (if we have to ascend again directly afterwards, this makes the transition smoother)
				signScale = 0.5;
			}
			else
			{
				signScale = -1.0;
			}

			float f = Math.Min( Math.Max( angles[0] / -m_MaxPitch * signScale, 0 ), 1.0 );

			float allowedAltitudeDelta;
			float allowedAltitudeDeltaNominal = m_Speed * dt;  //! Nominal at abs pitch angle of 45 deg
			float allowedAltitudeDeltaMin = allowedAltitudeDeltaNominal * 0.10;  //! 10% of nominal, still allows decent reaction time

			allowedAltitudeDelta = Math.Lerp( allowedAltitudeDeltaMin, allowedAltitudeDeltaNominal, f );

			if ( targetAltitude < m_PrevTargetAltitude - allowedAltitudeDelta )
			{
				targetAltitude = m_PrevTargetAltitude - allowedAltitudeDelta;
			}
			else if ( targetAltitude > m_PrevTargetAltitude + allowedAltitudeDelta )
			{
				targetAltitude = m_PrevTargetAltitude + allowedAltitudeDelta;
			}
		}

		m_PrevTargetAltitude = targetAltitude;


		float delta = targetAltitude - altitude;

		m_Speed = m_TargetSpeed;

		if ( m_Speed > 0 )
		{
			//! Adjust pitch
			angle = m_MaxPitch * ( delta / m_Speed ) + m_DefaultPitch;
		}

		if ( delta > 5 )
		{
			if ( altitude < 120 )
				m_Speed = m_TargetSpeed - (m_TargetSpeed / delta);
			else if ( altitude > 120 )
				m_Speed = m_TargetSpeed - (m_TargetSpeed / delta);
		}
		else if ( delta < -5 && altitude > 120)
		{
			m_Speed = m_TargetSpeed + (m_TargetSpeed / delta);
		}

		return altitude + delta * dt;
	}

	protected float GetTerrainY( vector position )
	{
		//! Make sure we clamp surfaceY to sea level (when plane is over water)
		float terrainY = Math.Max( GetGame().SurfaceY( position[0], position[2] ), GetGame().SurfaceGetSeaLevel() );

		vector start = Vector( position[0], position[1] - m_PlaneSize - 12.0, position[2] );
		vector end = Vector( position[0], terrainY, position[2] );

		PhxInteractionLayers collisionLayerMask = PhxInteractionLayers.TERRAIN | PhxInteractionLayers.WATERLAYER;

		//! Note: If this wasn't a static method and we pass 'this' (our plane) as ignoreObj like we normally would, it crashes the host. Why DayZ, WHY?
		if ( DayZPhysics.SphereCastBullet( start, end, m_PlaneSize, collisionLayerMask, NULL, m_HitObject, m_HitPosition, m_HitNormal, m_HitFraction ) )
		{
			if ( m_HitPosition[1] > terrainY && Math.AbsFloat( position[1] - m_HitPosition[1] ) > m_PlaneSize )
				terrainY = m_HitPosition[1];
		}

		return terrainY;
	}

	protected void CW95Animate( float dt )
	{
		m_RotorAnimationPosition += 1 * dt * 20.0 / ( Math.PI * 2.0 );
		if ( m_RotorAnimationPosition >= 1 )
			m_RotorAnimationPosition -= 1;
		
		foreach(string animName: m_AnimSelections)
		{
			SetAnimationPhase( animName, m_RotorAnimationPosition );
		}
	}

	protected void CW95_ClearAll()
	{
		OnEventStop();
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().ObjectDelete, 0, false, this );
	}

	protected bool CW95_EOnBeforeDelete()
	{
		vector position = GetPosition();
		float dist = Math.Sqrt(Math.Pow(m_Location[0] - position[0], 2) + Math.Pow(m_Location[2] - position[2], 2));
		if ( !m_ReachedTarget )
		{
			if (dist <= Math.RandomFloat(0, m_Radius)) 
			{
				if ( !m_ReachedTarget )
				{
					ARLogger.Log( this.GetType() + " Reached it's target");
					OnEventReached();
					m_ReachedTarget = true;
				}
			}
			else
			{
				OnEventIncoming(dist);
			}
		}
		else
		{
			if ( !IsInRect( position[0], position[2], -10.0, 15470.0, -10.0, 15470.0 ) )
			{
				ARLogger.Log( this.GetType() + " is out of map, going to despawn");
				return true;
			}
		}
		return false;
	}
	
	// Called after spawning the FIRST plane of the event
	void OnEventStart()
	{
	}

	// Called every ticks, provide the remaining distance from the target until OnEventReached() is called
	void OnEventIncoming(float distance)
	{
	}

	// Called when the plane is from within the radius of the target
	void OnEventReached()
	{
	}
	
	// Called when about to delete all the planes of the event
	void OnEventStop()
	{
	}

	//! TODO: move to a global library
	bool IsInRect(float x, float y, float min_x, float max_x, float min_y, float max_y) 
	{
		if ( x > min_x && x < max_x && y > min_y && y < max_y ) return true;
		return false;
	}
};