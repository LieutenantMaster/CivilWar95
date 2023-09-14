/**
 * EmoteWipeFace.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class EmoteWipeFace: EmoteBase
{
	void EmoteWipeFace()
	{
		m_ID = EmoteConstants.ID_EMOTE_WIPEFACE;
		m_InputActionName = "EmoteWipeFace";
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = SymptomIDs.SYMPTOM_FEVERBLUR;
		m_FullbodyCallbackUID = SymptomIDs.SYMPTOM_FEVERBLUR;
		m_HideItemInHands = false;
	}
};
