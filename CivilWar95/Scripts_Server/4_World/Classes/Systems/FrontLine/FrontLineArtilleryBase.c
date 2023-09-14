/**
 * FrontLineArtilleryBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class FrontLineArtilleryBase: FrontLineEventBase
{
    override void Spawn()
    {
        m_NewPosition += Vector(Math.RandomFloatInclusive(-m_Radius, m_Radius), 0, Math.RandomFloatInclusive(m_Radius, m_Radius + 400));
        
        //m_Quantity          // How many rounds
        //m_NewPosition       // Firing pos
        //m_TargetPos         // Impact pos
        //m_Radius            // Impact Radius
        //GetArtilleryType()  // Ammo used

        //rpc stuff
    }

    static int GetArtilleryType()
    {
        return FrontLineArtilleryTypes.TOXIC;
    }
};

/*
ERPCs.RPC_SOUND_ARTILLERY
// Actual code we will need
{
    vector firingPosition;
    vector impactPosition;
    float soundDelay; // between 10 and 20 seconds
    
    Param3<vector, vector, float> playArtyShotSound = new Param3<vector, vector, float>(vector.Zero, vector.Zero, 0);
    if (!ctx.Read(playArtyShotSound))
        break;

    firingPosition = playArtyShotSound.param1;
    impactPosition = playArtyShotSound.param2;
    soundDelay = playArtyShotSound.param3;

    if (firingPosition == vector.Zero)
        break;
    
    if (!GetGame().GetPlayer())
        break;
    
    m_ArtySound = SEffectManager.PlaySound("Artillery_Distant_SoundSet", firingPosition, 0.1, 0.1);
    m_ArtySound.SetAutodestroy(true);
    
    // We remove the amount of time the incoming sound lasts
    soundDelay -= 5;
    // We convert to milliseconds
    soundDelay *= 1000;
    GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DelayedMidAirDetonation, soundDelay, false, impactPosition);
    break;
}

void DelayedMidAirDetonation(vector impactPosition)
{
    EffectSound artilleryFallSound = SEffectManager.PlaySound("Artillery_Fall_SoundSet", impactPosition);
    artilleryFallSound.SetAutodestroy(true);
}
*/