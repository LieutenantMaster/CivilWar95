/**
 * ARMig21.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ARMig21
{
	private float m_Speed;
	private float m_Height;

	void CV95SetupRandom(ARPlace activeARPlaces, ARConfig activeARConfig, vector targetpos, float speed, float altitude)
	{
		m_ActiveMig21Places = activeARPlaces;
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

			velocity[0] = velocity[0] * m_Speed * dt;
			velocity[2] = velocity[2] * m_Speed * dt;
			
			vector transform[4];
			GetTransform( transform );
			transform[3] = transform[3] + velocity;
		vector position = GetPosition();
			transform[3][1] = GetGame().SurfaceY(position[0], position[2]) + m_Height;

			MoveInTime( transform, dt );

			if (EOnBeforeDelete())
			{
				GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().ObjectDelete, 0, false, this );
			}
		}
	}
};