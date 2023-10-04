/**
 * MPFP_Stop.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class MPFP_Stop
{
	override void OnEndServer( ActionData action_data )
	{	
		CW95_MusicPlayer mPlayer = CW95_MusicPlayer.Cast( action_data.m_MainItem );
		if( mPlayer )
			mPlayer.StopAllActions();
	}
};
