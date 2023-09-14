class CustomLoadingScreenData
{
	bool ShowLogo = true;
	string LogoPath = CW95_PATH_GUI + "cw95vert.edds";
	bool RandomizeBackgounds = true;
	int LoadingBarColor = ARGB(255, 199, 38, 81);
	bool UseCustomHints = true;
	string HintIconPath = CW95_PATH_GUI + "icons\\circle_info.edds";

	ref array<ref CustomLoadingScreenBackground> m_ExBackgrounds;

	void CustomLoadingScreenData()
	{
		m_ExBackgrounds = new array<ref CustomLoadingScreenBackground>;
		JsonFileLoader<array<ref CustomLoadingScreenBackground>>.JsonLoadFile(CW95_PATH_SCRIPTS + "Data\\LoadingImages.json", m_ExBackgrounds);
	}
};