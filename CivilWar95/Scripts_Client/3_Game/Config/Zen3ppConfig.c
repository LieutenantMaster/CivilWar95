class Zen3ppConfig
{
	// Static constant config version (is NOT saved to json)
	static const string CONFIG_VERSION = "1";

	// Config location
	private const static string zenModFolder = "$profile:\\Zenarchist\\";
	private const static string zenConfigName = "Zen3ppConfig.json";

	// Config data
	string ConfigVersion = "";
	int RestrictionTime = 10;
	ref TStringArray ViewRestrictedItems =
	{
		"Weapon",
		"Grenade",
		"RemoteDetonatorTrigger"
	};

	// Restricted areas (ie. X/Z coordinate and a radius)
	ref array<ref ZenViewRestrictionZone> FirstPersonZones = new array<ref ZenViewRestrictionZone>;

	// Load config file or create default file if config doesn't exsit
	void Load()
	{
		if (FileExist(zenModFolder + zenConfigName))
		{	// If config exists, load file
			JsonFileLoader<Zen3ppConfig>.JsonLoadFile(zenModFolder + zenConfigName, this);

			// If version mismatch, backup old version of json before replacing it
			if (ConfigVersion != CONFIG_VERSION)
			{
				JsonFileLoader<Zen3ppConfig>.JsonSaveFile(zenModFolder + zenConfigName + "_old", this);
			}
			else
			{
				// Config exists and version matches, stop here.
				return;
			}
		}

		// Set new config version
		ConfigVersion = CONFIG_VERSION;

		FirstPersonZones.Insert(new ZenViewRestrictionZone("Bunker", 682, 1162, 250));

		// Save config
		Save();
	};

	// Save config
	void Save()
	{
		if (!FileExist(zenModFolder))
			MakeDirectory(zenModFolder);

		// Save JSON config
		JsonFileLoader<Zen3ppConfig>.JsonSaveFile(zenModFolder + zenConfigName, this);
	}
};

// Define a view restriction zone
class ZenViewRestrictionZone
{
	string Name = "";
	float X;
	float Z;
	int Radius;

	void ZenViewRestrictionZone(string name, float x, float z, int r)
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

// Save config data
ref Zen3ppConfig m_Zen3ppConfig;

// Helper function to return Config data storage object
static Zen3ppConfig GetZen3ppConfig()
{
	if (!m_Zen3ppConfig)
	{
		Print("[Zen3ppConfig] Init");
		m_Zen3ppConfig = new Zen3ppConfig;
#ifdef SERVER
		m_Zen3ppConfig.Load();
#endif
	}

	return m_Zen3ppConfig;
};