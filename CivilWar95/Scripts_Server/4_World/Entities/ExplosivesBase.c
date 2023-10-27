/**
 * ExplosivesBase.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

#ifdef SERVER
modded class ExplosivesBase
{
	override void OnExplode()
	{
		super.OnExplode();

		// Get objects at position
		array<Object> objectsNearBomb = new array<Object>;
		GetGame().GetObjectsAtPosition(GetPosition(), 5, objectsNearBomb, null);

		for (int x = 0; x < objectsNearBomb.Count(); x++)
		{
			Object obj = objectsNearBomb[x];
			if (obj.IsInherited(TreeSoft) || obj.IsInherited(BushHard) || obj.IsInherited(BushSoft))
			{
				// Kill tree
				obj.SetHealth(0);
				dBodyDestroy(obj);
			}
		}
	}
};
#endif