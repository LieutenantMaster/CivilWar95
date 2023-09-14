/**
 * EmoteSneeze.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class EmoteSneeze: EmoteBase
{
	void EmoteSneeze()
	{
		m_ID = EmoteConstants.ID_EMOTE_SNEEZE;
		m_InputActionName = "EmoteSneeze";
		m_StanceMaskAdditive = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMaskFullbody = DayZPlayerConstants.STANCEMASK_PRONE;
		m_AdditiveCallbackUID = SymptomIDs.SYMPTOM_SNEEZE;
		m_FullbodyCallbackUID = SymptomIDs.SYMPTOM_SNEEZE;
		m_HideItemInHands = false;
	}
};
