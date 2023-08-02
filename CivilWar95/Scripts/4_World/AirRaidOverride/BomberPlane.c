modded class BomberPlane
{
	private float m_Speed;
	private float m_Height;
	private bool m_hasSiren;

	void CV95SetupRandom(ARPlace activeARPlaces, ARConfig activeARConfig, vector targetpos, float speed, float altitude)
	{
		m_ActiveARPlaces = activeARPlaces;
		m_ActiveARConfig = activeARConfig;
		
		m_Speed =  speed;
		m_Height = altitude;
		m_Location = targetpos;
		m_Radius = 300;

		vector position = GetPosition();
		m_Angle = Math.Atan2( targetpos[2] - position[2], targetpos[0] - position[0] );
	}

	override void EOnSimulate( IEntity owner, float dt )
	{
		if ( GetGame().IsServer() )
		{
			vector velocity = Vector( Math.Cos( m_Angle ), 0, Math.Sin( m_Angle ) );

			velocity[0] = velocity[0] * (m_Speed * 10) * dt;
			velocity[2] = velocity[2] * (m_Speed * 10) * dt;
			
			vector transform[4];
			GetTransform( transform );
			transform[3] = transform[3] + velocity;

			vector position = GetPosition();
			transform[3][1] = GetGame().SurfaceY(position[0], position[2]) + m_Height;

			MoveInTime( transform, dt );

			EOnBeforeBombing();

			if (EOnBeforeDelete())
			{
				if (m_hasSiren)
					StopSirena();

				GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().ObjectDelete, 0, false, this );
			}
		}
	}

	override void SirenPos(vector sirenpos)
	{
		m_hasSiren = true;
		super.SirenPos(sirenpos);
	}
};