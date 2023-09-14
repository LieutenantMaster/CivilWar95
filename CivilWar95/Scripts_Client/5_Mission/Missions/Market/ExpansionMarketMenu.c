#ifdef EXPANSIONMODMARKET
modded class ExpansionMarketMenu
{
	override string GetPreviewClassName(string className, bool ignoreBaseBuildingKits = false)
	{
		if (GetGame().ConfigIsExisting("CfgVehicles " + className + " deployable") )
		{
			return GetGame().ConfigGetTextOut( "CfgVehicles " + className + " deployable" );
		}
		else if (!ignoreBaseBuildingKits && className.IndexOf("kit") == className.Length() - 3)
		{
			// MyClassnameKIT => MyClassname
			string previewClassName = className.Substring(0, className.Length() - 3);
			if (GetGame().ConfigIsExisting("CfgVehicles " + previewClassName))
				return previewClassName;

			// MyClassname_KIT => MyClassname
			previewClassName = className.Substring(0, className.Length() - 4);
			if (GetGame().ConfigIsExisting("CfgVehicles " + previewClassName))
				return previewClassName;
		}

		return super.GetPreviewClassName(className, ignoreBaseBuildingKits);
	}
};
#endif