/**
 * MP_Rewind.c
 *
 * © 2023 CivilWar95
 * By LieutenantMaster
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License.
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/

modded class MP_RewindAction
{
    override void OnEndServer(ActionData action_data)
	{
        CW95_MusicPlayer ntarget = CW95_MusicPlayer.Cast( action_data.m_Target.GetObject() );
		if( ntarget )
			ntarget.SetRewinding(true);

		Inventory_Base m_Cassette = ItemBase.Cast(ntarget.FindAttachmentBySlotName("CW95_Cassette"));
		m_Cassette.DecreaseHealth(string.Empty, string.Empty, -0.1);
    }
};
