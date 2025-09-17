//nclude "DIALOGS\PJ PNJ voyage.h"
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
			
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			Dialog.snd = "voice\QCSI\QCSI001"
			// d.Text = RandPhrase(DLG_TEXT[0] + Address_Form.Eng + DLG_TEXT[1], DLG_TEXT[2], DLG_TEXT[3] + Address_Form.Eng + DLG_TEXT[4], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1] + PChar.name + " " + PChar.lastname + DLG_TEXT[2] + PChar.ship.name + DLG_TEXT[3];
			Link.l1.go = "Start";
		break;

		case "Start":
			Diag.CurrentNode = Diag.TempNode;
			dialog.snd = "voice\QCSI\QCSI001";
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[6];
			Link.l2.go = "PJ_DIALOG_Conceicao";
			Link.l3 = DLG_TEXT[7];
			Link.l3.go = "PJ_DIALOG_Douwesen";
			Link.l4 = DLG_TEXT[8];
			Link.l4.go = "PJ_DIALOG_FalaiseDeFleur";
			Link.l5 = DLG_TEXT[9];
			Link.l5.go = "PJ_DIALOG_IslaMuelle";
			Link.l6 = DLG_TEXT[10];
			Link.l6.go = "PJ_DIALOG_Greenford";
			Link.l7 = DLG_TEXT[11];
			Link.l7.go = "PJ_DIALOG_Oxbay";
			Link.l8 = DLG_TEXT[12];
			Link.l8.go = "PJ_DIALOG_QuebradasCostillas";
			Link.l9 = DLG_TEXT[13];
			Link.l9.go = "PJ_DIALOG_Redmond";
		break;

		case "PJ_DIALOG_Conceicao":
			DialogExit();
			pchar.quest.PJ_teleportation = "Conceicao_town";
			pchar.quest.PJ_teleportation.port = "Conceicao_port";
			pchar.quest.PJ_teleportation.goto1 = "goto";
			pchar.quest.PJ_teleportation.goto2 = "goto2";
			AddDialogExitQuest("PJ_QR_teleportation_1");
		break;

		case "PJ_DIALOG_Douwesen":
			DialogExit();
			pchar.quest.PJ_teleportation = "Douwesen_town";
			pchar.quest.PJ_teleportation.port = "Douwesen_port";
			pchar.quest.PJ_teleportation.goto1 = "goto";
			pchar.quest.PJ_teleportation.goto2 = "goto2";
			AddDialogExitQuest("PJ_QR_teleportation_1");
		break;

		case "PJ_DIALOG_FalaiseDeFleur":
			DialogExit();
			pchar.quest.PJ_teleportation = "Falaise_de_fleur_townhall";
			pchar.quest.PJ_teleportation.port = "Falaise_De_Fleur_port_01";
			pchar.quest.PJ_teleportation.goto1 = "goto";
			pchar.quest.PJ_teleportation.goto2 = "goto4";
			AddDialogExitQuest("PJ_QR_teleportation_1");
		break;

		case "PJ_DIALOG_IslaMuelle":
			DialogExit();
			pchar.quest.PJ_teleportation = "Muelle_town_01";
			pchar.quest.PJ_teleportation.port = "Muelle_port";
			pchar.quest.PJ_teleportation.goto1 = "goto";
			pchar.quest.PJ_teleportation.goto2 = "goto2";
			AddDialogExitQuest("PJ_QR_teleportation_1");
		break;

		case "PJ_DIALOG_Greenford":
			DialogExit();
			pchar.quest.PJ_teleportation = "Greenford_town";
			pchar.quest.PJ_teleportation.port = "Greenford_port";
			pchar.quest.PJ_teleportation.goto1 = "goto";
			pchar.quest.PJ_teleportation.goto2 = "goto2";
			AddDialogExitQuest("PJ_QR_teleportation_1");
		break;

		case "PJ_DIALOG_Oxbay":
			DialogExit();
			pchar.quest.PJ_teleportation = "Oxbay_town";
			pchar.quest.PJ_teleportation.port = "Oxbay_port";
			pchar.quest.PJ_teleportation.goto1 = "goto";
			pchar.quest.PJ_teleportation.goto2 = "goto2";
			AddDialogExitQuest("PJ_QR_teleportation_1");
		break;

		case "PJ_DIALOG_QuebradasCostillas":
			DialogExit();
			pchar.quest.PJ_teleportation = "QC_town";
			pchar.quest.PJ_teleportation.port = "QC_port";
			pchar.quest.PJ_teleportation.goto1 = "goto";
			pchar.quest.PJ_teleportation.goto2 = "goto2";
			AddDialogExitQuest("PJ_QR_teleportation_1");
		break;

		case "PJ_DIALOG_Redmond":
			DialogExit();
			pchar.quest.PJ_teleportation = "Redmond_town_01";
			pchar.quest.PJ_teleportation.port = "Redmond_port";
			pchar.quest.PJ_teleportation.goto1 = "goto";
			pchar.quest.PJ_teleportation.goto2 = "goto12";
			AddDialogExitQuest("PJ_QR_teleportation_1");
		break;



		case "exit":
			trace("Dialog Temp Node = " + Diag.TempNode);
			pchar.quest.PJ_teleportation = "";
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}