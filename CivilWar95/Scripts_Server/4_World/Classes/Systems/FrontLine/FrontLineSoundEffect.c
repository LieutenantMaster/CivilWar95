/**
 * FrontLineSoundEffect.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class FrontLineSoundEffect: FrontLineEventBase
{
	void PlaySound(string soundset, vector position, float fadeIn = 0.1, float fadeOut = 0.1)
	{
        EffectSound soundToPlay = SEffectManager.PlaySound(soundset, position, fadeIn, fadeOut);
        soundToPlay.SetAutodestroy(true);
	}
};
