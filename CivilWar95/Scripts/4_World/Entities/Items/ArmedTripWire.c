class ArmedTripwireTrap: TripwireTrap
{
    void ArmedTripwireTrap()
    {
		SetState(DEPLOYED);
        StartActivate(null);
    }
};
