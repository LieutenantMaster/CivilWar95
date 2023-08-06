/**
 * MissionGameplay.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class MissionGameplay
{
	protected bool m_VirtualCompassToggled = false;

	override void OnUpdate( float timeslice )
	{
		super.OnUpdate( timeslice );

		bool inputIsFocused = false;		
		Widget focusedWidget = GetFocus();

		// Is the player writing ?
		if ( focusedWidget )
		{
			if ( focusedWidget.ClassName().Contains( "EditBoxWidget" ) || focusedWidget.ClassName().Contains( "MultilineEditBoxWidget" ) )
			{
				inputIsFocused = true;
			}
		}
		Input input 			= GetGame().GetInput();
		UIScriptedMenu topMenu 	= m_UIManager.GetMenu(); // if this guy exist, then we are in a menu
		PlayerBase playerPB 	= PlayerBase.Cast( GetGame().GetPlayer() );
		
		// We first check if the player exist (maybe he is still loading)
		if ( playerPB && playerPB.GetHumanInventory() ) 
		{
			// Then we check if the player is alive
			if ( playerPB.GetPlayerState() == EPlayerStates.ALIVE && !playerPB.IsUnconscious() )
			{
				if ( !topMenu && !inputIsFocused )
				{
					// we check when the player start pressing (or holding) the keybind
					if ( input.LocalPress( "UAVirtualCompassHold", false ) || input.LocalHold( "UAVirtualCompassHold", false ) )
					{
						// now we check if the virtual compass is already toggled and if the player can toggle it
						if ( !m_VirtualCompassToggled && IsPlayerStateValid(playerPB) )
						{
							m_VirtualCompassToggled = true;
							playerPB.ShowVirtualCompass(playerPB.HasCompass());
						}
					}
				}
			}

			if ( m_VirtualCompassToggled )
			{
				// if you ALT TAB you can keep the compass hud even if you stopped pressing
				// allowing you to keep it no matter what. So instead of checking if the key is beind held
				// we simply check if the player is still allowed to have the compass
				// this won't fix ALL the potential ways to do it, but it should greatly reduce it
				if ( !IsPlayerStateValid(playerPB) || input.LocalRelease( "UAVirtualCompassHold", false ) || topMenu )
				{
					m_VirtualCompassToggled = false;
					playerPB.HideVirtualCompass();
				}
			}
		}
	}

	private bool IsPlayerStateValid(PlayerBase player)
	{
		// Does the player has a compass on him ?
		if ( player.HasCompass() == "" )
			return false;

		// Is he in 3rd person, aiming or handcuffed ?
		if ( player.IsInThirdPerson() || player.IsInOptics() || player.IsInIronsights() || player.IsRestrained() )
			return false;
		
		return true;
	}
};
