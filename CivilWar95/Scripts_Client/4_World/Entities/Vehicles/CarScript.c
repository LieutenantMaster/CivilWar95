/**
 * CarScript.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class CarScript
{	
	override bool IsFuelStation()
	{
		return false;
	}

	bool HasFuelToGive()
	{
		return !IsRuined() && !IsEmpty();
	}

	bool HasArmement()
	{
		return false;
	}

	bool HasDecoys()
	{
		return false;
	}

	bool CanFireFromSeatIndex(PlayerBase player)
	{
		return false;
	}

	bool CanDecoyFromSeatIndex(PlayerBase player)
	{
		return false;
	}

	override void DamageCrew(float dmg)
	{
		for ( int c = 0; c < CrewSize(); ++c )
		{
			Human crew = CrewMember( c );
			if ( !crew )
				continue;

			PlayerBase player;
			if ( Class.CastTo(player, crew ) )
			{
				float shockTemp = Math.InverseLerp(GameConstants.CARS_CONTACT_DMG_THRESHOLD, GameConstants.CARS_CONTACT_DMG_KILLCREW, dmg);
				shockTemp = Math.Clamp(shockTemp,0,1);
				float shock = Math.Lerp( 50, 150, shockTemp );
				float hp = Math.Lerp( 1, 20, shockTemp );
				
				player.AddHealth("", "Shock", -shock );
				player.AddHealth("", "Health", -hp );
			}
		}
	}
};
