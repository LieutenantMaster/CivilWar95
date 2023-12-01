class SharedSettings
{
	static int VERSION = 1;
	
	int RestrictionTime;
	ref array<ref CW95ConflictZone> ConflictZones = new array<ref CW95ConflictZone>;
	
	void SharedSettings()
	{
		ConflictZones = new ref array< ref CW95ConflictZone >;
	}

	static ref SharedSettings Load()
	{
		ref SharedSettings m_Settings = new SharedSettings();
		bool save;
		
		if (!FileExist(CW95_PATH_PROFILE_SETTINGS))
			MakeDirectory(CW95_PATH_PROFILE_SETTINGS);
		
		if (FileExist(CW95_PATH_SETTINGS_SHARED))
		{
			JsonFileLoader<SharedSettings>.JsonLoadFile(CW95_PATH_SETTINGS_SHARED, m_Settings);

			if ( m_Settings.VERSION != VERSION )
			{
				if ( m_Settings.VERSION < 1 )
				{
					// My changes here
				}

				m_Settings.VERSION = VERSION;
				save = true;
			}
		}
		else
		{
			m_Settings.Defaults();
			save = true;
		}

		if ( save )
			JsonFileLoader<SharedSettings>.JsonSaveFile(CW95_PATH_SETTINGS_SHARED, m_Settings);
		
		return m_Settings;
	}
	
	void Defaults()
	{
		RestrictionTime = 10;
		ConflictZones.Insert(new CW95ConflictZone("Bunker", 682, 1162, 250));
	}
};

// Define a view restriction zone
class CW95ConflictZone
{
	string Name = string.Empty;
	int X;
	int Z;
	int Radius;

	void CW95ConflictZone(string name, int x, int z, int r)
	{
		Name = name;
		X = x;
		Z = z;
		Radius = r;
	}

	bool CheckZone(vector checkPos)
	{
		if (checkPos) 
		{
			vector pos = Vector(checkPos[0], 0, checkPos[2]);
			if (vector.Distance(pos, Vector(X, 0, Z)) <= Radius)
				return true;
		}

		return false;
	}
};

ref SharedSettings m_SharedSettings;
static SharedSettings GetSharedSettings()
{
	if (!m_SharedSettings)
	{
		m_SharedSettings = new SharedSettings;
#ifdef SERVER
		m_SharedSettings.Load();
#endif
	}

	return m_SharedSettings;
};