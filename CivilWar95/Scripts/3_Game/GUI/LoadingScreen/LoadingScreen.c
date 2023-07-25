modded class LoadingScreen
{
	protected Widget m_ExPanelWidget;
	protected ImageWidget m_VanillaHintIcon;
	protected ImageWidget m_ExHintIcon;
	protected int m_ExBackgroundIndex = 0;

	protected const float LOADING_SCREEN_CHANGE_TIME = 2.5;
	protected float m_ExLoadingTime;
	protected float m_ExLoadingTimeStamp;

	protected ref CustomLoadingScreenData m_ExCustomLoadingScreenData;
	protected ref array<int> m_ShownBackgrounds;

	void LoadingScreen(DayZGame game)
	{
		m_ExCustomLoadingScreenData = new CustomLoadingScreenData();
		if (!m_ExCustomLoadingScreenData)
			return;
		
		m_ModdedWarning.Show(false);

		if (m_ExCustomLoadingScreenData.RandomizeBackgounds)
			m_ShownBackgrounds = new array<int>;

		m_ExPanelWidget = Widget.Cast(m_WidgetRoot.FindAnyWidget("PanelWidget1"));

		//! Hide vanilla hint icon
		float posHintIconX, posHintIconY;
		m_VanillaHintIcon = ImageWidget.Cast(m_WidgetRoot.FindAnyWidget("hintIcon"));
		m_VanillaHintIcon.GetScreenPos(posHintIconX, posHintIconY);
		m_VanillaHintIcon.Show(false);
		m_VanillaHintIcon.Unlink();

		//! Create custom hint icon
		m_ExHintIcon = ImageWidget.Cast(game.GetLoadingWorkspace().CreateWidgets(CV95_PATH_GUI + "layouts\\hint_icon.layout", m_ExPanelWidget));
		m_ExHintIcon.SetScreenPos(posHintIconX, posHintIconY, true);
		m_ExHintIcon.LoadImageFile(0, m_ExCustomLoadingScreenData.HintIconPath);

		//! Remove vanilla mask texture
		m_ImageWidgetBackground.LoadMaskTexture("");

		//! Replace and set logo
		if (m_ExCustomLoadingScreenData.ShowLogo && m_ExCustomLoadingScreenData.LogoPath != string.Empty)
		{
			float posLogoX, posLogoY;
			m_ImageLogoCorner.GetScreenPos(posLogoX, posLogoY);
			m_ImageLogoCorner.Show(false);
			m_ImageLogoCorner.Unlink();

			m_ImageLogoCorner = ImageWidget.Cast(game.GetLoadingWorkspace().CreateWidgets(CV95_PATH_GUI + "layouts\\logo.layout", m_ExPanelWidget));
			m_ImageLogoCorner.SetScreenPos(posLogoX, posLogoY, true);
			m_ImageLogoCorner.SetSize(256,256);

			m_ImageLogoMid.SetSize(256,256);
		}
		//! Hide vanilla logo
		else if (!m_ExCustomLoadingScreenData.ShowLogo)
		{
			m_ImageLogoCorner.Show(false);
		}

		if (m_ImageLogoCorner)
			m_ImageLogoCorner.LoadImageFile(0, m_ExCustomLoadingScreenData.LogoPath);

		if (m_ImageLogoMid)
			m_ImageLogoMid.LoadImageFile(0, m_ExCustomLoadingScreenData.LogoPath);


		if (m_ExCustomLoadingScreenData.LoadingBarColor != 0)
		{
			float posLoadingBarX, posLoadingBarY;
			m_ProgressLoading.GetScreenPos(posLoadingBarX, posLoadingBarY);
			m_ProgressLoading.Show(false);
			m_ProgressLoading.Unlink();

			m_ProgressLoading = ProgressBarWidget.Cast(game.GetLoadingWorkspace().CreateWidgets(CV95_PATH_GUI + "layouts\\loading_bar.layout", m_ExPanelWidget));
			m_ProgressLoading.SetScreenPos(posLoadingBarX, posLoadingBarY, true);
			m_ProgressLoading.SetColor(m_ExCustomLoadingScreenData.LoadingBarColor);
			ProgressAsync.SetProgressData(m_ProgressLoading);
		}
	}

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		m_ExLoadingTime += timeslice;
		if (m_ExLoadingTime >= LOADING_SCREEN_CHANGE_TIME)
		{
			SetBackgroundImage(m_ExBackgroundIndex);
			m_ExBackgroundIndex++;
			if (m_ExBackgroundIndex > (m_ExCustomLoadingScreenData.m_ExBackgrounds.Count() - 1))
				m_ExBackgroundIndex = 0;

			m_ExLoadingTime = 0;
		}
	}

	override void ShowEx(DayZGame game)
	{
		super.ShowEx(game);

		float loadingTime = m_ExLoadingTime;
		float tickTime = game.GetTickTime();

		if (m_ExLoadingTimeStamp < 0)
		{
			m_ExLoadingTime = 0;
		}
		else
		{
			m_ExLoadingTime += tickTime - m_ExLoadingTimeStamp;
		}

		m_ExLoadingTimeStamp = tickTime;

		if (m_ExLoadingTime >= LOADING_SCREEN_CHANGE_TIME)
		{
			SetBackgroundImage(m_ExBackgroundIndex);
			m_ExBackgroundIndex++;
			if (m_ExBackgroundIndex > (m_ExCustomLoadingScreenData.m_ExBackgrounds.Count() - 1))
				m_ExBackgroundIndex = 0;

			m_ExLoadingTime = 0;
		}
	}

	protected void SetBackgroundImage(int index)
	{
		CustomLoadingScreenBackground background = m_ExCustomLoadingScreenData.m_ExBackgrounds.Get(index);
		if (background && background.ImagePath != string.Empty)
		{
			m_ImageWidgetBackground.LoadImageFile(0, background.ImagePath, true);
			m_ImageWidgetBackground.SetImage(0);
		}
	}
};