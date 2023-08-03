/**
 * CV95_AIRBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CV95_AIRBase: BuildingSuper
{
	protected EffectSound m_EntitySound;

	ref ARPlace m_ActiveARPlaces;
	ref ARConfig m_ActiveARConfig;

	protected float m_Speed;
	protected float m_Height;
	protected float m_Angle;
	
	protected bool m_ReachedTarget;
	protected vector m_Location;
	protected float m_Radius;
	
	protected vector m_Siren_Location;	
	protected bool m_hasSiren;

	void CV95_AIRBase()
	{
		SetEventMask( EntityEvent.CONTACT | EntityEvent.SIMULATE );
		
		#ifndef SERVER
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(InitSound, 1, false);
		#endif
	}
	
	void ~CV95_AIRBase()
	{
		if (m_EntitySound)
			m_EntitySound.Stop();
	}

	void CV95Setup(ARPlace activeARPlaces, ARConfig activeARConfig, vector targetpos, float speed, float altitude)
	{
		m_ActiveARPlaces = activeARPlaces;
		m_ActiveARConfig = activeARConfig;
		
		m_Speed = speed;
		m_Height = altitude;
		m_Location = targetpos;
		m_Radius = 300;

		vector position = GetPosition();
		m_Angle = Math.Atan2( targetpos[2] - position[2], targetpos[0] - position[0] );
	}
	
	void InitSound()
	{
		if ( GetGame() && GetGame().GetPlayer() )
			PlaySound(GetSoundToPlay(), 4000);
	}

	override void EOnSimulate( IEntity owner, float dt )
	{
		if ( GetGame().IsServer() )
			CV95Simulate(dt);
	}

	void CV95Simulate( float dt )
	{
		vector velocity = Vector( Math.Cos( m_Angle ), 0, Math.Sin( m_Angle ) );

		velocity[0] = velocity[0] * m_Speed * dt;
		velocity[2] = velocity[2] * m_Speed * dt;
		
		vector transform[4];
		GetTransform( transform );
		transform[3] = transform[3] + velocity;
		vector position = GetPosition();
		transform[3][1] = GetGame().SurfaceY(position[0], position[2]) + m_Height;

		MoveInTime( transform, dt );

		if (CV95_EOnBeforeDelete())
			CV95_ClearAll();
	}

	void CV95_ExecuteOnTarget()
	{
	}

	void CV95_ClearAll()
	{
		StopSiren();
		GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().ObjectDelete, 0, false, this );
	}

	bool CV95_EOnBeforeDelete()
	{
		vector position = GetPosition();
		if ( !m_ReachedTarget )
		{
			float dist = Math.Sqrt(Math.Pow(m_Location[0] - position[0], 2) + Math.Pow(m_Location[2] - position[2], 2));
			if (dist <= Math.RandomFloat(0, m_Radius)) 
			{
				if ( !m_ReachedTarget )
				{
					ARLogger.Log( this.GetType() + " Reached it's target");
					CV95_ExecuteOnTarget();
					m_ReachedTarget = true;
				}
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
	
	void SirenPos(vector sirenpos)
	{
		m_hasSiren = true;

		m_Siren_Location = sirenpos;
		ARLogger.Log("Started siren at coords " + m_Siren_Location);
		Object m_sirena = Object.Cast(GetGame().CreateObject("ARSiren", m_Siren_Location));
	}	
	
	void StopSiren()
	{
		if ( !m_hasSiren )
			return;

		ref array<Object> objects = new array<Object>;
		
		GetGame().GetObjectsAtPosition(m_Siren_Location, 1, objects, NULL);
		
		for (int i = 0; i < objects.Count(); ++i)
		{
		    Object obj = Object.Cast( objects.Get(i) );

		    if (GetGame().ObjectIsKindOf(obj,"ARSiren"))
		    {
				ARSiren sirena = ARSiren.Cast(obj);
				sirena.Stop();
				sirena.Update();
				
				ARLogger.Log("Stopped siren at coords " + obj.GetPosition());
		    }
		}
	}

	string GetSoundToPlay()
	{
		return "";
	}

	bool IsInRect(float x, float y, float min_x, float max_x, float min_y, float max_y) 
	{
		if ( x > min_x && x < max_x && y > min_y && y < max_y ) return true;
		return false;
	}
};