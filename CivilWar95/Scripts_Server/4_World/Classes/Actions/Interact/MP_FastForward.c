/**
 * MP_FastForwardAction.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class MP_FastForwardAction
{
    override void OnEndServer(ActionData action_data)
	{
        CW95_MusicPlayer ntarget = CW95_MusicPlayer.Cast( action_data.m_Target.GetObject() );
		if( ntarget )
			ntarget.SetFastForwarding(true);
        
        Inventory_Base m_Cassette = ItemBase.Cast(ntarget.FindAttachmentBySlotName("CW95_Cassette"));
		m_Cassette.DecreaseHealth("", "", -0.1);
    }
};
