/**
 * CW95_ArmedTripwireTrap.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_ArmedTripwireTrap: TripwireTrap
{
    void CW95_ArmedTripwireTrap()
    {
		SetState(DEPLOYED);
        StartActivate(null);
    }
};
