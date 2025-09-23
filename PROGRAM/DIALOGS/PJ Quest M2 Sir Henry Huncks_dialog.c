//nclude "DIALOGS\PJ Quest M2 Sir Henry Huncks_dialog.h"
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
			d.Text = DLG_TEXT[0];
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
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[4] + quest_M2_clues_list() + DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[7];
			Link.l2.go = "hair";
			Link.l3 = DLG_TEXT[8];
			Link.l3.go = "eyes";
			Link.l4 = DLG_TEXT[9];
			Link.l4.go = "clothes";
			Link.l5 = DLG_TEXT[10];
			Link.l5.go = "accessory";
			Link.l6 = DLG_TEXT[11];
			Link.l6.go = "passion";
			Link.l7 = DLG_TEXT[12];
			Link.l7.go = "skill";
			Link.l8 = DLG_TEXT[13];
			Link.l8.go = "distinguishing_mark";
			Link.l9 = DLG_TEXT[14];
			Link.l9.go = "language";
			Link.l10 = DLG_TEXT[15];
			Link.l10.go = "home_port";
			Link.l11 = DLG_TEXT[16];
			Link.l11.go = "man";
			Link.l12 = DLG_TEXT[17];
			Link.l12.go = "woman";
		break;

		case "hair":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19]; // black
			Link.l1.go = "Continue_02";
			Link.l2 = DLG_TEXT[20]; // red
			Link.l2.go = "Continue_02";
			Link.l3 = DLG_TEXT[21]; // blond
			Link.l3.go = "Continue_02";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
		break;

		case "eyes":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23]; // brown
			Link.l1.go = "Continue_02";
			Link.l2 = DLG_TEXT[24]; // green
			Link.l2.go = "Continue_02";
			Link.l3 = DLG_TEXT[25]; // blue
			Link.l3.go = "Continue_02";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
		break;

		case "clothes":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27]; // simple
			Link.l1.go = "Continue_02";
			Link.l2 = DLG_TEXT[28]; // elegant
			Link.l2.go = "Continue_02";
			Link.l3 = DLG_TEXT[29]; // flashy
			Link.l3.go = "Continue_02";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
		break;

		case "accessory":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31]; // compass
			Link.l1.go = "Continue_02";
			Link.l2 = DLG_TEXT[32]; // ring
			Link.l2.go = "Continue_02";
			Link.l3 = DLG_TEXT[33]; // spyglass
			Link.l3.go = "Continue_02";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
		break;

		case "passion":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[34];
			Link.l1 = DLG_TEXT[35]; // antiques
			Link.l1.go = "Continue_02";
			Link.l2 = DLG_TEXT[36]; // poetry
			Link.l2.go = "Continue_02";
			Link.l3 = DLG_TEXT[37]; // seagulls
			Link.l3.go = "Continue_02";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
		break;

		case "skill":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[38];
			Link.l1 = DLG_TEXT[39]; // climbing
			Link.l1.go = "Continue_02";
			Link.l2 = DLG_TEXT[40]; // talking
			Link.l2.go = "Continue_02";
			Link.l3 = DLG_TEXT[41]; // disguise
			Link.l3.go = "Continue_02";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
		break;

		case "distinguishing_mark":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[43]; // scar
			Link.l1.go = "Continue_02";
			Link.l2 = DLG_TEXT[44]; // tattoo
			Link.l2.go = "Continue_02";
			Link.l3 = DLG_TEXT[45]; // limp
			Link.l3.go = "Continue_02";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
		break;

		case "language":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47]; // spanish
			Link.l1.go = "Continue_02";
			Link.l2 = DLG_TEXT[48]; // french
			Link.l2.go = "Continue_02";
			Link.l3 = DLG_TEXT[49]; // english
			Link.l3.go = "Continue_02";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
		break;

		case "home_port":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[50];
			Link.l1 = DLG_TEXT[51]; // seville
			Link.l1.go = "Continue_02";
			Link.l2 = DLG_TEXT[52]; // la rochelle
			Link.l2.go = "Continue_02";
			Link.l3 = DLG_TEXT[53]; // plymouth
			Link.l3.go = "Continue_02";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
		break;

		case "man":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[55];
			Link.l1 = DLG_TEXT[56];
			Link.l1.go = "Continue_02";
		break;

		case "woman":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[57];
			Link.l1 = DLG_TEXT[58];
			Link.l1.go = "Continue_02";
		break;

		case "Continue_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[59] + quest_M2_robbers_list();
			Link.l1 = DLG_TEXT[60];
			Link.l1.go = "OneSuspect";
			switch (quest_M2_robbers_count())
			{
				case 0:
					Link.l1.go = "NoSuspect";
				break;
				case 1:
					Link.l1.go = "OneSuspect";
				break;
				default:
					Link.l1.go = "exit";
				break;
			}
		break;

		case "NoSuspect":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[61];
			Link.l1 = DLG_TEXT[62];
			Link.l1.go = "exit";
		break;

		case "OneSuspect":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[63];
			Link.l1 = DLG_TEXT[64];
			Link.l1.go = "exit";
			quest_M2_create_warrant();
		break;



		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}