#ifdef EXPANSIONMODMARKET
modded class ExpansionMarketTraderZone
{
	void IncrementStock( float percent )
	{
		IncrementStock_Internal(percent);
	}

	protected void IncrementStock_Internal( int percent )
	{
		foreach (string clsName, int stock: Stock)
		{
			ExpansionMarketItem marketItem = ExpansionMarketCategory.GetGlobalItem( clsName, false );
			if ( !marketItem )
				continue;

			if ( marketItem.IsStaticStock() )
			{
				percent = 1;
			}
			else if ( percent > marketItem.MaxStockThreshold )
			{
				percent = ( marketItem.MaxStockThreshold / 100 ) * percent;
			}

			Stock.Set( className, percent );
		}
	}
};
#endif