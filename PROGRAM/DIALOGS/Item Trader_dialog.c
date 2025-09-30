//nclude "DIALOGS\Item Trader_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	int chance;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "Items":
			if (npchar.quest.item_date != lastspeak_date)
			{
				GiveItemToTrader(npchar);
				npchar.quest.item_date = lastspeak_date;
			}
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			// ajout PJ
			d.Text = DLG_TEXT[0];
			if (quest_M2_right_track()) {
				Link.l1 = DLG_TEXT[3];
				Link.l1.go = "PJ_M2_01";
				Link.l2 = DLG_TEXT[1];
				Link.l2.go = "Items";
				Link.l3 = DLG_TEXT[2];
				Link.l3.go = "exit";
			} else {
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "Items";
				Link.l2 = DLG_TEXT[2];
				Link.l2.go = "exit";
			}
			// fin ajout PJ
		break;

		// ajout PJ
		case "PJ_M2_01":
			chance = makeint(PChar.skill.Sneak) + Rand(20 - makeint(PChar.skill.Sneak));
			
			if (chance < 18 && PChar.quest_M2_last_citizen != NPChar.id) {
				d.Text = DLG_TEXT[4];
				Link.l1 = DLG_TEXT[51];
				Link.l1.go = "PJ_M2_02";
			}
			if (chance >= 18 && PChar.quest_M2_last_citizen != NPChar.id) {
				d.Text = quest_M2_PNJ_clue();
				Link.l1 = DLG_TEXT[51];
				Link.l1.go = "PJ_M2_02";
			}
			if (PChar.quest_M2_last_citizen == NPChar.id) {
				d.Text = DLG_TEXT[53];
				Link.l1 = DLG_TEXT[5];
				Link.l1.go = "exit";
			}

			PChar.quest_M2_last_citizen = NPChar.id; // pour ne pas questionner deux fois de suite le mкme citoyen (NPChar.id)
		break;
		
		case "PJ_M2_02":
			chance = makeint(PChar.skill.Sneak) + Rand(20 - makeint(PChar.skill.Sneak));

			if (chance < 12) {
				d.Text = DLG_TEXT[52];
			}
			else {
				int next_port = quest_M2_next_port_answer();
				if (next_port > 0) {
					d.Text = quest_M2_robber_gender_pronoun() + DLG_TEXT[6 + next_port * 6 + Rand(5)];
				}
				if (next_port == 0) {
					d.Text = quest_M2_robber_gender_pronoun() +  DLG_TEXT[6 + Rand(5)] + " " + quest_M2_robber_gender_pronoun() + DLG_TEXT[42 + Rand(2)];
				}
				if (next_port == -1) {
					d.Text = quest_M2_robber_gender_pronoun() +  DLG_TEXT[6 + Rand(5)] + " " + quest_M2_robber_gender_pronoun() + DLG_TEXT[45 + Rand(2)];
				}
				if (next_port == -2) {
					d.Text = quest_M2_robber_gender_pronoun() +  DLG_TEXT[6 + Rand(5)] + " " + quest_M2_robber_gender_pronoun() + DLG_TEXT[48 + Rand(2)];
				}
			}

			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "exit";
		break;
		// fin ajout PJ
	}
}