//nclude "DIALOGS\PJ HELP Malcolm Hatcher_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	int RandQuestSum;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	trace("Temp Node = " + Diag.TempNode);
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
			
			dialog.snd1 = "voice\QCSI\QCSI001";
			dialog.snd2 = "voice\QCSI\QCSI001";
			dialog.snd3 = "voice\QCSI\QCSI001";
			
			switch (rand(2))
			{
				case 0: d.Text = DLG_TEXT[0]; break;
				case 1: d.Text = DLG_TEXT[1]; break;
				case 2: d.Text = DLG_TEXT[2]; break;
			}
			B11_SyncTransverseState();
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "rumor_step_1";
			if (B11_IsTransverseActive())
			{
				Link.l3 = DLG_TEXT[17];
				Link.l3.go = "B1_1_help";
			}
			Link.l2 = DLG_TEXT[4];
			Link.l2.go = "exit";
		break;

		case "B1_1_help":
			dialog.snd = "voice\QCSI\QCSI001";
			B11_SyncTransverseState();
			switch (B1_GetStep())
			{
				case "intro_collect":
					d.Text = DLG_TEXT[18];
				break;

				case "intro_ready_report":
					d.Text = DLG_TEXT[19];
				break;

				case "muelle_pending":
					d.Text = DLG_TEXT[20];
				break;

				case "conceicao_pending":
					d.Text = DLG_TEXT[21];
				break;

				case "douwesen_pending":
					d.Text = DLG_TEXT[22];
				break;

				case "jungle_clue_pending":
					d.Text = DLG_TEXT[23];
				break;

				case "dig_ready":
					d.Text = DLG_TEXT[24];
				break;

				case "final_ready":
					d.Text = DLG_TEXT[25];
				break;

				default:
					d.Text = DLG_TEXT[26];
				break;
			}
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "exit";
		break;

		case "rumor_step_1":
			dialog.snd = "voice\QCSI\QCSI001";
			switch (rand(2))
			{
				case 0:
					d.Text = DLG_TEXT[5];
					Link.l1 = DLG_TEXT[8];
					Link.l1.go = "rumor_step_2_1";
					break;
				case 1:
					d.Text = DLG_TEXT[6];
					Link.l1 = DLG_TEXT[8];
					Link.l1.go = "rumor_step_2_2";
					break;
				case 2:
					d.Text = DLG_TEXT[7];
					Link.l1 = DLG_TEXT[8];
					Link.l1.go = "rumor_step_2_3";
					break;
			}
			Link.l2 = DLG_TEXT[12];
			Link.l2.go = "exit";
		break;

		case "rumor_step_2_1":
			dialog.snd = "voice\QCSI\QCSI001";
			d.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "rumor_step_3_1";
			Link.l2 = DLG_TEXT[16];
			Link.l2.go = "exit";
		break;

		case "rumor_step_2_2":
			dialog.snd = "voice\QCSI\QCSI001";
			d.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "rumor_step_3_2";
			Link.l2 = DLG_TEXT[16];
			Link.l2.go = "exit";
		break;

		case "rumor_step_2_3":
			dialog.snd = "voice\QCSI\QCSI001";
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "rumor_step_3_3";
			Link.l2 = DLG_TEXT[16];
			Link.l2.go = "exit";
		break;

		case "rumor_step_3_1":
			dialog.snd = "voice\QCSI\QCSI001";
			d.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "exit";
		break;

		case "rumor_step_3_2":
			dialog.snd = "voice\QCSI\QCSI001";
			d.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "exit";
		break;

		case "rumor_step_3_3":
			dialog.snd = "voice\QCSI\QCSI001";
			d.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "exit";
		break;

		case "exit":
			trace("Dialog Temp Node = " + Diag.TempNode);
			DialogExit();
		break;
		
	}
}
