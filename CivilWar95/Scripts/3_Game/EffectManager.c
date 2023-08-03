/**
 * SEffectManager.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class SEffectManager
{
    static EffectSound CV95_PlaySoundOnObjectWOPlay(string sound_set, Object parent_object, float play_fade_in = 0, float stop_fade_out = 0, bool loop = false)
	{
		EffectSound effect_sound = CreateSound(sound_set, parent_object.GetPosition(), play_fade_in, stop_fade_out, loop);
		
		effect_sound.SetParent( parent_object );
		effect_sound.SetLocalPosition( vector.Zero );
		
		return effect_sound;
	}
}