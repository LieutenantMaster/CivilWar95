/**
 * CV95_TU95.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CV95_TU95: CV95_AIRBase
{
	override string GetSoundToPlay()
	{
		return "c130j_loop_int";
	}

	override void CV95_ExecuteOnTarget()
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
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(StopSiren, 8500, false);
		}
	}
	
	void BombHit(Object bomba)
	{
		if(bomba) bomba.SetHealth("", "", 0.0);
	}
};