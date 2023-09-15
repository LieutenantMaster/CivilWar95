/**
 * DayZIntroScenePC.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class DayZIntroScenePC
{
	/*
	override void Expansion_HandleCustomScene(string childName)
	{
		switch (childName)
		{
			case "cw95_chernaruplus_chernogorsk_street": // 1.0
			{
                PPEffects.Init();
                PPEffects.DisableBurlapSackBlindness();
                PPEffects.SetVignette(0.3, 0, 0, 0, 255);
                
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater( SetRain, 55000, false, 0.4, 10);
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater( SetRain, 65000, false, 0.6, 127);
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater( SetRain, 128500, false, 0.1, 1);
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater( SetStorm, 130500, false, 1.0, 0);
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater( SetRain, 130500, false, 1.0, 1);
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater( SetRain, 193000, false, 0.1, 2);
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater( SetStorm, 193000, false, 0.0, 1);	
			}
			break;
		}
	}
	*/
	
	void SpawnAI(string loadout, vector[] waypoints, int speed)
	{
		
	}
	
	void SpawnEffect(string classname, vector position, vector direction = vector.Zero)
	{
		
	}
	
	void SetRain(float Strength, float Transition)
	{
		m_Weather.GetRain().SetLimits( 0.1, 1 );
		m_Weather.GetRain().Set( Strength, Transition, 0.1);
	}

	void SetStorm(float Strength, float Transition)
	{
		m_Weather.SetStorm( Strength, Transition, 0);
	}
	
	override protected void GetSelectedUserName()
	{
		string name;
		BiosUserManager user_manager = GetGame().GetUserManager();
		if( user_manager )
		{
			BiosUser user = user_manager.GetSelectedUser();
			if( user )
			{
				g_Game.SetPlayerGameName( user.GetName() );
				return;
			}
		}
		g_Game.SetPlayerGameName(GameConstants.DEFAULT_CHARACTER_NAME);
	}
};
