modded class UiHintPanel
{
	protected const string m_ExDataPath = CV95_PATH_SCRIPTS + "Data\\Hints.json"; //! Custom hints json path
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