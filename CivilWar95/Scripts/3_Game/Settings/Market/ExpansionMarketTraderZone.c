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

			percent = ( marketItem.MaxStockThreshold / 100 ) * percent;

			percent += Stock.Get( clsName );

			if ( percent > marketItem.MaxStockThreshold )
				percent = marketItem.MaxStockThreshold;

			if ( percent < marketItem.MinStockThreshold )
				percent = marketItem.MinStockThreshold;

			Stock.Set( clsName, percent );
		}
	}
};
#endif