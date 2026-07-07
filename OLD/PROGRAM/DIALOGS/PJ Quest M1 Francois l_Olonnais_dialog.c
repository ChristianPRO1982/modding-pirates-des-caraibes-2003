//nclude "DIALOGS\PJ Quest M1 Francois l_Olonnais_dialog.h"
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
			d.Text = PChar.name + " " + PChar.lastname + DLG_TEXT[2] + PChar.ship.name + DLG_TEXT[3];
			Link.l1 = DLG_TEXT[4];
			Link.l1.go = "Continue_02";
		break;

		case "Continue_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "Continue_03";
		break;

		case "Continue_03":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[7];
			Link.l1 = DLG_TEXT[8];
			Link.l1.go = "Continue_04";
		break;

		case "Continue_04":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "Continue_05";
		break;

		case "Continue_05":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[11] + PChar.name + " " + PChar.lastname + DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Continue_06";
		break;

		case "Continue_06":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "Continue_07";
		break;

		case "Continue_07":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[16];
			Link.l1.go = "Continue_08";
		break;

		case "Start":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "Continue_08";
		break;

		case "Continue_08":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "Continue_09";
		break;

		case "Continue_09":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "Continue_10";
			Link.l2 = DLG_TEXT[22];
			Link.l2.go = "exit";
		break;

		case "Continue_10":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "Continue_11";
			Link.l2 = DLG_TEXT[25];
			Link.l2.go = "exit";
		break;

		case "Continue_11":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "Continue_12";
		break;

		case "Continue_12":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "Continue_13";
		break;

		case "Continue_13":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "last_question";
		break;

		case "last_question":
			Diag.TempNode = "last_question";
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "Continue_14";
			Link.l2 = DLG_TEXT[34];
			Link.l2.go = "exit";
		break;

		case "Continue_14":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "Continue_15";
		break;

		case "Continue_15":
			Diag.CurrentNode = "Waiting";
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[37];
			Link.l1 = DLG_TEXT[38];
			Link.l1.go = "agreeded";
		break;

		case "agreeded":
			DialogExit();
			AddDialogExitQuest("quest_M1_agreeded");
		break;

		case "Waiting":
			Diag.TempNode = "Waiting";
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[39] + PChar.name + " " + PChar.lastname + ".";
			Link.l1.go = "exit";
		break;

		case "FightingInRedmondFort_won":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[40];
			Link.l1.go = "Continue_16";
		break;

		case "Continue_16":
			Diag.CurrentNode = "Waiting";
			DialogExit();
		break;

		case "FightingInFalaiseDeFleurFort_won":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[41];
			Link.l1.go = "Continue_17";
		break;

		case "Continue_17":
			Diag.CurrentNode = "Waiting";
			DialogExit();
		break;

		case "FightingInConceicaoFort_won":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[42];
			Link.l1.go = "Continue_18";
		break;

		case "Continue_18":
			Diag.CurrentNode = "Waiting";
			DialogExit();
		break;

		case "FightingInIslaMuelleFort_won":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[43];
			Link.l1.go = "Continue_19";
		break;

		case "Continue_19":
			Diag.CurrentNode = "Waiting";
			DialogExit();
		break;

		case "FightingInDouwesenFort_won":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[44];
			Link.l1.go = "Continue_20";
		break;

		case "Continue_20":
			Diag.CurrentNode = "Waiting";
			DialogExit();
		break;

		case "FightingInGreenfordFort_won":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[45];
			Link.l1.go = "Continue_21";
		break;

		case "Continue_21":
			Diag.CurrentNode = "Waiting";
			DialogExit();
		break;

		case "FightingInOxbayFort_won":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[46];
			Link.l1.go = "Continue_22";
		break;

		case "Continue_22":
			Diag.CurrentNode = "Waiting";
			DialogExit();
		break;

		case "PrisonDialog":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = PChar.name + " " + PChar.lastname + DLG_TEXT[47] + PChar.ship.name + DLG_TEXT[48];
			Link.l1 = DLG_TEXT[49];
			Link.l1.go = "Continue_23";
		break;
		
		case "Continue_23":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[50];
			Link.l1 = DLG_TEXT[51];
			Link.l1.go = "Continue_24";
		break;
		
		case "Continue_24":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[52];
			Link.l1 = DLG_TEXT[53];
			AddDialogExitQuest("quest_M1_END_1");
			DialogExit();
		break;



		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}