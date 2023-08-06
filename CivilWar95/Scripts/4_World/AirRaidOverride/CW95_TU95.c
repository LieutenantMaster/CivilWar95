/**
 * CW95_TU95.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_TU95: CW95_AIRBase
{
	// Siren stuff, will probably need to move it to it's own class one day
	protected vector m_Siren_Location;
	protected ARSiren m_Siren;
	protected bool m_hasSiren;

	void CW95_TU95()
	{
		m_NameSoundSets = {"Expansion_C130J_Loop_SoundSet"};
	}

	override void OnEventReached()
	{
		BombExplode(m_ActiveARConfig.NumOfBombs);
	}

    void BombExplode(int bombnum)
	{
		vector posi = m_Location;

		vector bombing;
		float t;
		float u;
		float v;
		float w;
		float x;
		float y;
		int r = 80;
		
		u =  Math.RandomFloatInclusive(0.0, 1.0);
		v =  Math.RandomFloatInclusive(0.0, 1.0);
	
		w = r * Math.Sqrt(u);
		t = 2 * Math.PI * v;
		x = w * Math.Cos(t); 
		y = w * Math.Sin(t);

		bombing[0] = posi[0]+x;
		bombing[2] = posi[2]+y;

		Object bomba = GetGame().CreateObject("ARBomb", bombing); //bombing

		bomba.PlaceOnSurface();
		vector ori = bomba.GetOrientation();
        if ( ori[2] == -180 || ori[2] == 180 )
        {
            ori[2] = 0;
            bomba.SetOrientation( ori );
        }
		bomba.Update();
		bomba.SetHealth("", "", 0.0);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(BombHit, 150, false, bomba);

		int rndinterval = Math.RandomInt(200,1000);
		
		bombnum--;
		if (bombnum > 0)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(BombExplode, rndinterval, false, bombnum );
		}
        else
		{
			// Shouldn't be needed since we call OnEventStop when we are about to delete the plane
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(OnEventStop, 8500, false);
		}
	}
	
	void BombHit(Object bomb)
	{
		if (bomb)
			bomb.SetHealth("", "", 0.0);
	}

	override void OnEventIncoming(float distance)
	{
		if ( !m_Siren )
		{
			if ( distance <= 2000 )
			{
				m_Siren = Object.Cast(GetGame().CreateObject("ARSiren", m_Siren_Location));
				ARLogger.Log("Started siren at coords " + m_Siren_Location);
			}
		}
	}
	
	override void OnEventStart()
	{
		m_hasSiren = true;
		m_Siren_Location = m_ActiveARPlaces.sirenpos.ToVector();
	}
	
	override void OnEventStop()
	{
		if ( !m_hasSiren || !m_Siren )
			return;

		m_Siren.Stop();
		m_Siren.Update();
		
		ARLogger.Log("Stopped siren at coords " + m_Siren.GetPosition());
	}
};