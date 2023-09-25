/**
 * CW95VehicleWpnFireRocket.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95VehicleWpnFireRocket: ExpansionWeaponFireBase
{
	override void FireServer( Weapon_Base weapon, int muzzleIndex, DayZPlayerImplement player, vector pos, vector dir )
	{
		CW95_ProjectileRocket rocket;
		if ( Class.CastTo( rocket, GetGame().CreateObject( "CW95_ProjectileRocket", pos ) ) )
		{
			rocket.SetDirection( dir );
			rocket.SetPosition( pos );

			rocket.CreateDynamicPhysics( PhxInteractionLayers.DYNAMICITEM );
			rocket.EnableDynamicCCD( true );

			vector velocity = dir * 70.0;
			float mass = dBodyGetMass( rocket );

			SetVelocity( rocket, velocity );
			dBodyApplyForce( rocket, velocity * mass );
		}
	}
	
	override void FireClient( Weapon_Base weapon, int muzzleIndex, DayZPlayerImplement player, vector pos, vector dir )
	{
	}
};
