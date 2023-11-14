/**
 * CW95_DigUpGrave.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

class CW95_DigUpGraveCB: ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.BURY_BODY);
	}
};

class CW95_DigUpGrave: CW95_SearchGroundBase
{
	void CW95_DigUpGrave()
	{
		m_CallbackClass 	= CW95_DigUpGraveCB;
		m_Text 				= "#STR_CW95_ACTIONS_DIGUPGRAVE";

        SEARCH_OBJECTS = { "cemetery_grave1.p3d",
                            "cemetery_grave2.p3d",
                            "cemetery_grave3.p3d",
                            "cemetery_grave4.p3d",
                            "cemetery_smallcross.p3d",
                            "cemetery_tombstone1.p3d",
                            "cemetery_tombstone10.p3d",
                            "cemetery_tombstone11.p3d",
                            "cemetery_tombstone2.p3d",
                            "cemetery_tombstone3.p3d",
                            "cemetery_tombstone4.p3d",
                            "cemetery_tombstone5.p3d",
                            "cemetery_tombstone5_damaged.p3d",
                            "cemetery_tombstone6.p3d",
                            "cemetery_tombstone7.p3d",
                            "cemetery_tombstone8.p3d",
                            "cemetery_tombstone8_damaged.p3d",
                            "cemetery_tombstone9.p3d" };

        SEARCH_LOOT = { "Worm",
                        "Rope",
                        "Wellies_Black",
                        "Wellies_Brown",
                        "Wellies_Green",
                        "Wellies_Grey",
                        "Pot",
                        "PlantMaterial" };

        m_EffectId = ParticleList.IMPACT_DIRT_EXIT;
        m_LootChance = 6;
        m_BlacklistChance = 7;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        if ( !super.ActionCondition(player, target, item) )
            return false;

        int liquidType;
        string surfaceType;
        GetGame().SurfaceUnderObject(target.GetObject(), surfaceType, liquidType);
        
        return GetGame().IsSurfaceDigable(surfaceType);
	}
};
