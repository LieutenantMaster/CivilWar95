class CV95_ArmedTripwireTrap: TripwireTrap
{
    void CV95_ArmedTripwireTrap()
    {
		SetState(DEPLOYED);
        StartActivate(null);
    }
};
