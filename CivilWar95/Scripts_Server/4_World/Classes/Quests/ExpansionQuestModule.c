/**
 * ExpansionQuestModule.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class ExpansionQuestModule
{
    bool EXIsOtherQuestInstanceActive(int questID, int activeAmount = 0)
    {
        set<ref ExpansionQuest> activeQuestInstances = m_ActiveQuestInstances[questID];
        return activeQuestInstances && activeQuestInstances.Count() > activeAmount;
    }
};
