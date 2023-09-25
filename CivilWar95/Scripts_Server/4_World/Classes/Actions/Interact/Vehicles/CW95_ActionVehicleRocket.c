/**
 * CW95_ActionVehicleRocket.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class CW95_ActionVehicleRocket
{
	private ref Timer m_RocketTimer;

	private int m_Rockets;

	private ExpansionHelicopterScript m_Heli;

	void CW95_ActionVehicleRocket()
	{
		m_RocketTimer = new Timer();
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{		
		if ( m_RocketTimer && m_RocketTimer.IsRunning() )
			return false;

		return super.ActionCondition(player, target, item);
	}

	override void OnExecuteServer( ActionData action_data )
	{
		if ( m_RocketTimer && m_RocketTimer.IsRunning() )
			return;

		HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
		if ( vehCommand )
		{
			Transport trans = vehCommand.GetTransport();
			if ( trans )
			{
				if ( Class.CastTo(m_Heli, trans) )
				{
					m_Rockets = m_Heli.GetRocketAmount();
					
					m_RocketTimer.Run( 0.0375, this, "SpawnRocket", NULL, true ); 
				}
			}
		}
	}

	protected void SpawnRocket()
	{
		if ( !m_Heli )
		{
			m_RocketTimer.Stop();
			return;
		}

		m_Rockets -= 1;

		CW95_Projectile_Base rocket;
		//ModelToWorld(m_Heli.GetMemoryPointPos("rocket_pos"))
		if ( Class.CastTo( rocket, GetGame().CreateObject( "CW95_ProjectileRocket", m_Heli.GetPosition() + "0 20 0" )))
		{
			//vector dir = m_Heli.GetMemoryPointPos("rocket_dir");
			//vector dir = vector.Direction( m_Heli.GetMemoryPointPos("rocket_pos"), m_Heli.GetMemoryPointPos("rocket_dir") );

			//vector dirOffset = Vector(1,1,1) + Vector(Math.RandomFloatInclusive(-0.01, 0.01), 0, Math.RandomFloatInclusive(-0.01, 0.01));
			//dir = dir * dirOffset;

			vector dir = m_Heli.GetDirection();
			rocket.SetDirection( dir );

			rocket.SetPosition( m_Heli.GetPosition() + (vector.Aside * m_Heli.GetRocketPosOffset(m_Rockets)) );//.ModelToWorld(m_Heli.GetMemoryPointPos("rocket_pos")) );

			rocket.CreateDynamicPhysics( PhxInteractionLayers.DYNAMICITEM );
			rocket.EnableDynamicCCD( true );

			float speed = m_Heli.GetSpeedometer() / 2;

			SetVelocity( rocket, dir * 350 );
			dBodyApplyForce( rocket, dir * (dBodyGetMass( rocket ) / 4) );
			//rocket.ForceFarBubble(true);
			//rocket.Unpin();
		}

		if ( m_Rockets <= 0 )
			m_RocketTimer.Stop();
	}
};
