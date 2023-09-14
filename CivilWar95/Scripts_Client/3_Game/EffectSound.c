/**
 * EffectSound.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class EffectSound
{
	AbstractWave CW95_GetWave()
	{
		return m_SoundWaveObject;
	}

	void CW95_SkipTo(float second)
    {
        m_SoundWaveObject.Restart();
        m_SoundWaveObject.Skip(second);
    }
};
