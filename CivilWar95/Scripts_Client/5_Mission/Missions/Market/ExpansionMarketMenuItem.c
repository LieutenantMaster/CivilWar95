#ifdef DIAG
modded class ExpansionMarketMenuItem
{
    protected float CW95_SellTaxPrice;
    protected float CW95_BuyTaxPrice;
    
    override void UpdatePrices()
	{
        Print("m_MarketModule.GetClientZone().m_DisplayName is " + m_MarketModule.GetClientZone().m_DisplayName);
        CW95_BuyTaxPrice = 0;
        CW95_SellTaxPrice = 0;
		//! Buy price
		if (m_CanBuy)
		{
			int price = 0;
			//! Can't pass in GetMarketItem() to FindPriceOfPurchase directly, causes NULL pointer. Fuck you EnforceScript.
			ExpansionMarketItem item = GetMarketItem();
			m_MarketModule.FindPriceOfPurchase(item, m_MarketModule.GetClientZone(), GetMarketMenu().GetMarketTrader(), 1, price, GetIncludeAttachments());

            //if ( m_MarketModule.GetClientZone().m_DisplayName == "Zelenogorsk" )
            {
                CW95_BuyTaxPrice = price * 0.3; // 30% increase
			    m_BuyPrice = price + CW95_BuyTaxPrice;
            }
            //else
			//    m_BuyPrice = price;

			m_ItemController.ItemBuyPrice = ExpansionStatic.IntToCurrencyString(m_BuyPrice, ",", true);
		}
		else
		{
			m_BuyPrice = -1;
			m_ItemController.ItemBuyPrice = "";
		}

		market_item_info_buy_price_icon.Show(m_BuyPrice > -1);

		//! Sell price
		if (m_CanSell)
		{
			array<EntityAI> items;
			if (m_PlayerStock != 0)
			{
				//! Player has the item
				items = m_MarketModule.LocalGetEntityInventory();
			}
			else
			{
				//! Player doesn't have the item
				items = new array<EntityAI>;
			}

			ExpansionMarketSell marketSell = new ExpansionMarketSell;
			marketSell.Item = GetMarketItem();
			marketSell.Trader = GetMarketMenu().GetTraderObject();
			m_MarketModule.FindSellPrice(PlayerBase.Cast(GetGame().GetPlayer()), items, m_ItemStock, 1, marketSell, m_PlayerStock != 0 || m_IncludeAttachments);


            //if ( m_MarketModule.GetClientZone().m_DisplayName == "Zelenogorsk" )
            {
                CW95_SellTaxPrice = marketSell.Price * 0.3; // 30% increase
			    m_SellPrice = marketSell.Price + CW95_SellTaxPrice;
            }
            //else
			//    m_SellPrice = marketSell.Price;

			m_ItemController.ItemSellPrice = ExpansionStatic.IntToCurrencyString(m_SellPrice, ",", true);
		}
		else
		{
			m_SellPrice = -1;
			m_ItemController.ItemSellPrice = "";
		}

		m_ItemController.NotifyPropertiesChanged({"ItemSellPrice", "ItemBuyPrice"});
		
		market_item_info_sell_price_panel.Show(m_SellPrice > -1);
	}
};
#endif