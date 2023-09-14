/**
 * UiHintPanel.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class UiHintPanel
{
	protected const string m_ExDataPath = CW95_PATH_SCRIPTS + "Data\\Hints.json"; //! Custom hints json path
	protected ref CustomLoadingScreenData m_ExCustomLoadingScreenData;

	override protected void LoadContentList()
	{
		if (!m_ExCustomLoadingScreenData)
			m_ExCustomLoadingScreenData = new CustomLoadingScreenData();

		if (m_ExCustomLoadingScreenData && m_ExCustomLoadingScreenData.UseCustomHints)
		{
			JsonFileLoader<array<ref HintPage>>.JsonLoadFile(m_ExDataPath, m_ContentList);
		}
		else
		{
			JsonFileLoader<array<ref HintPage>>.JsonLoadFile(m_DataPath, m_ContentList);
		}
	}
};