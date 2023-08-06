/**
 * CW95_Mi6.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_Mi6: CW95_AIRBase
{
	void CW95_Mi6()
	{
		m_FollowTerrainFraction = 0.95;
		m_DefaultPitch = 10.0;
		m_MaxPitch = 25.0;
		m_NameSoundSets = {"CW95_GenericHeliEngine_Loop_CfgSoundSet","CW95_GenericHeliRotor_Loop_CfgSoundSet"};
	}
};