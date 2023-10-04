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

	#ifdef DIAG
    protected float CW95_SellTaxPrice;
    protected float CW95_BuyTaxPrice;

	override void UpdateItemFieldFromBasicNetSync()
	{
		super.UpdateItemFieldFromBasicNetSync();

        CW95_BuyTaxPrice = 0;
        CW95_SellTaxPrice = 0;
		int color;
		PlayerBase player = GetGame().GetPlayer();

		if ( m_SellPrice > -1 )
		{
            if ( player.IsPlayerAtZeleno() )
            {
                CW95_SellTaxPrice = m_SellPrice * 0.3; // 30% increase
			    m_SellPrice = m_SellPrice + CW95_SellTaxPrice;

				market_item_sell_price_text.SetColor(color); 
				market_item_sell_price_icon.SetColor(color);

				m_MarketMenuController.MarketItemTotalSellPrice = ExpansionStatic.IntToCurrencyString(m_SellPrice, ",");
            }
		}
		if ( m_BuyPrice > -1 )
		{
            if ( player.IsPlayerAtZeleno() )
            {
                CW95_BuyTaxPrice = m_BuyPrice * 0.3; // 30% increase
			    m_BuyPrice = m_BuyPrice + CW95_BuyTaxPrice;

				if (m_MarketModule.GetPlayerWorth() >= m_BuyPrice)
					color = GetExpansionSettings().GetMarket().MarketMenuColors.Get("BaseColorText");
				else
					color = COLOR_EXPANSION_NOTIFICATION_EXPANSION;
				
				market_item_buy_price_text.SetColor(color); 
				market_item_buy_price_icon.SetColor(color);
				m_MarketMenuController.MarketItemTotalBuyPrice = ExpansionStatic.IntToCurrencyString(m_BuyPrice, ",");
            }	
		}
	}
	#endif
};
#endif