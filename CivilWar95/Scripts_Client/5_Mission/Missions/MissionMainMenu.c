/**
 * MissionMainMenu.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class MissionMainMenu
{
	override void PlayMusic()
	{		
		SoundParams soundParams = new SoundParams("CW95_Music_1_SoundSet");
		SoundObjectBuilder soundBuilder	= new SoundObjectBuilder(soundParams);
		SoundObject soundObject = soundBuilder.BuildSoundObject();
		soundObject.SetKind(WaveKind.WAVEMUSIC);
		m_MenuMusic = GetGame().GetSoundScene().Play2D(soundObject, soundBuilder);
		m_MenuMusic.Loop(true);
		m_MenuMusic.Play();
	}
};