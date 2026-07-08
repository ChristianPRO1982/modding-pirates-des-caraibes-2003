//nclude "DIALOGS\PJ Quest S1 Elizabeth_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	int RandQuestSum;
	int n;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	



	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			Diag.TempNode = "Start";
			
			dialog.snd1 = "Voice\ARSI\ARSI001";
			dialog.snd2 = "Voice\ARSI\ARSI001";
			dialog.snd3 = "Voice\ARSI\ARSI001";
			// d.Text = RandPhrase(DLG_TEXT[0] + Address_Form.Eng + DLG_TEXT[1], DLG_TEXT[2], DLG_TEXT[3] + Address_Form.Eng + DLG_TEXT[4], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			d.Text = DLG_TEXT[0];
			// Link.l1 = DLG_TEXT[1] + PChar.name + " " + PChar.lastname + DLG_TEXT[2] + PChar.ship.name + DLG_TEXT[3];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Continue_01";
		break;

		case "Continue_01":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "Start";
		break;

		case "Start":
			Diag.TempNode = "Start";
			dialog.snd = "Voice\ARSI\ARSI001";
			if (pchar.quest_S1_allQuestsCompleted == false) {
				if (pchar.quest_S1_step != 1) GenerateTreasureHunterQuest("Quebradas Costillas", 11);
				d.Text = DLG_TEXT[4];
				Link.l1 = DLG_TEXT[5];
				Link.l1.go = "Continue_02";
			} else {
				d.Text = DLG_TEXT[24];
				Link.l1 = DLG_TEXT[25];
				Link.l1.go = "Continue_06";
			}
		break;

		case "Continue_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = pchar.quest_S1_island + DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "agreeded";
			Link.l2 = DLG_TEXT[8];
			Link.l2.go = "exit";
		break;

		case "agreeded":
			pchar.quest_S1_startIsland = "QuebradasCostillas";
			Diag.TempNode = "Waiting";
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "Continue_03";
		break;

		case "Continue_03":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[11];
			Link.l1.go = "Continue_04";
		break;

		case "Continue_04":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("quest_S1_agreeded");
		break;

		case "Waiting":
			if (pchar.quest_S1_step == 0) {
				dialog.snd = "Voice\ARSI\ARSI001";
				d.Text = DLG_TEXT[23];
				Link.l1.go = "start";
			} else {
				dialog.snd = "Voice\ARSI\ARSI001";
				d.Text = DLG_TEXT[12];
				Link.l1.go = "Continue_05";
			}
		break;

		case "Continue_05":
			DialogExit();
		break;

		case "Continue_06":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "exit";
		break;

		case "complete_quest":
			Diag.TempNode = "Start";
			dialog.text = DLG_TEXT[13] + (makeint(pchar.quest_S1_gain_gold_jewelry) * 20) + DLG_TEXT[14] + (makeint(pchar.quest_S1_gain_gold_jewelry) * makeint(pchar.skill.Leadership)) + DLG_TEXT[15] + pchar.quest_S1_gain_gold_jewelry_text;
			Link.l1 = DLG_TEXT[16];
			link.l1.go = "gain";
			Link.l2 = DLG_TEXT[17];
			link.l2.go = "disagree";
		break;

		case "gain":
			AddMoneyToCharacter(pchar, makeint(pchar.quest_S1_gain_gold) * makeint(pchar.skill.Leadership));
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry1) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry1");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry2) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry2");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry3) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry3");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry4) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry4");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry5) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry5");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry6) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry6");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry7) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry7");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry8) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry8");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry9) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry9");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry10) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry10");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry11) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry11");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry12) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry12");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry13) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry13");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry14) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry14");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry15) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry15");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry16) * makeint(pchar.skill.Leadership); n++) {GiveItem2Character(Pchar, "jewelry16");}
			
			Diag.TempNode = "Start";
			
			dialog.text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
			AddDialogExitQuest("quest_S1_closed");
		break;

		case "disagree":
			ChangeCharacterReputation(pchar, -5);
			dialog.text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19];
			link.l1.go = "gain";
			Link.l2 = DLG_TEXT[20];
			link.l2.go = "fight";
		break;

		case "fight":
			link.l1.go = "exit";
			AddDialogExitQuest("quest_S1_fight");
		break;



		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}