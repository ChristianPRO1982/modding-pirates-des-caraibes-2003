//nclude "DIALOGS\QC citizen_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	int chance;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\QCSI\QCSI001";
			
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			dialog.text = randphrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";

			// ajout PJ
			if (quest_M2_right_track() && PChar.money >= 5)
			{
				Link.l1 = DLG_TEXT[11];
				Link.l1.go = "PJ_M2_01";
				Link.l2 = DLG_TEXT[12];
				Link.l2.go = "exit";
			}
			// fin ajout PJ

			if (pchar.quest.main_line == "blaze_talk_with_silehard_complete" && characters[GetCharacterIndex("Ines Diaz")].quest.rheims != "speak_with_humans")
			{
				Dialog.snd = "voice\QCSI\QCSI001";
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5] + characters[GetCharacterIndex(DLG_TEXT[6])].name + " " + characters[GetCharacterIndex(DLG_TEXT[7])].lastname + DLG_TEXT[8];
				link.l1.go = "search_rheims";
				AddQuestRecord("Blaze_search_Rheims", "12");
				characters[GetCharacterIndex("Ines Diaz")].quest.rheims = "speak_with_humans";
			}
			NextDiag.TempNode = "first time";
		break;

		case "search_rheims":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
		break;

		// ajout PJ
		case "PJ_M2_01":
			PChar.money = makeint(PChar.money) - 5;
			if (PChar.quest_M2_lastPort == "1") {
				d.Text = quest_M2_final_clue();
				Link.l1 = DLG_TEXT[14];
				Link.l1.go = "exit";
			} else {
				chance = makeint(PChar.skill.Sneak) + Rand(20 - makeint(PChar.skill.Sneak));
				
				if (chance < 2 && PChar.quest_M2_last_citizen != NPChar.id) {
					d.Text = DLG_TEXT[13];
					Link.l1 = DLG_TEXT[14];
					Link.l1.go = "exit";
				}
				if (chance >= 2 && PChar.quest_M2_last_citizen != NPChar.id) {
					d.Text = quest_M2_PNJ_clue();
					Link.l1 = DLG_TEXT[60];
					Link.l1.go = "PJ_M2_02";
				}
				if (PChar.quest_M2_last_citizen == NPChar.id) {
					d.Text = DLG_TEXT[62];
					Link.l1 = DLG_TEXT[14];
					Link.l1.go = "exit";
				}

				PChar.quest_M2_last_citizen = NPChar.id; // pour ne pas questionner deux fois de suite le mкme citoyen (NPChar.id)
			}
		break;
		
		case "PJ_M2_02":
				chance = makeint(PChar.skill.Sneak) + Rand(20 - makeint(PChar.skill.Sneak));

				if (chance < 2) {
					d.Text = DLG_TEXT[61];
				}
				else {
					int next_port = quest_M2_next_port_answer();
					if (next_port > 0) {
						d.Text = quest_M2_robber_gender_pronoun() + DLG_TEXT[15 + next_port * 6 + Rand(5)];
					}
					if (next_port == 0) {
						d.Text = quest_M2_robber_gender_pronoun() +  DLG_TEXT[15 + Rand(5)] + " " + quest_M2_robber_gender_pronoun() + DLG_TEXT[51 + Rand(2)];
					}
					if (next_port == -1) {
						d.Text = quest_M2_robber_gender_pronoun() +  DLG_TEXT[15 + Rand(5)] + " " + quest_M2_robber_gender_pronoun() + DLG_TEXT[54 + Rand(2)];
					}
					if (next_port == -2) {
						d.Text = quest_M2_robber_gender_pronoun() +  DLG_TEXT[15 + Rand(5)] + " " + quest_M2_robber_gender_pronoun() + DLG_TEXT[57 + Rand(2)];
					}
				}

				Link.l1 = DLG_TEXT[14];
				Link.l1.go = "exit";
		break;
		// fin ajout PJ

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
