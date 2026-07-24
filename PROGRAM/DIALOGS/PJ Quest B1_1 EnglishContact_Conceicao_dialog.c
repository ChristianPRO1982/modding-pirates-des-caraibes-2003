//nclude "DIALOGS\PJ Quest B1_1 EnglishContact_Conceicao_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	aref Link, Diag;

	PChar = GetMainCharacter();

	DeleteAttribute(&Dialog, "Links");

	makeref(NPChar, CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "First time":
			Diag.CurrentNode = "B1_1_conceicao_contact";
			Dialog.CurrentNode = "B1_1_conceicao_contact";
		break;

		case "B1_1_conceicao_contact":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "B1_1_conceicao_contact_2";
		break;

		case "B1_1_conceicao_contact_2":
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "B1_1_conceicao_contact_exit";
		break;

		case "B1_1_conceicao_contact_exit":
			Diag.CurrentNode = "B1_1_conceicao_contact";
			Diag.TempNode = "B1_1_conceicao_contact";
			DialogExit();
			AddDialogExitQuest("PJ_B1_1_CONCEICAO_CONTACT_SHIP");
		break;

		case "B1_1_conceicao_contact_ship":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "B1_1_conceicao_contact_ship_2";
		break;

		case "B1_1_conceicao_contact_ship_2":
			d.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "B1_1_conceicao_contact_ship_exit";
		break;

		case "B1_1_conceicao_contact_ship_exit":
			Diag.CurrentNode = "B1_1_conceicao_contact_ship";
			Diag.TempNode = "B1_1_conceicao_contact_ship";
			DialogExit();
			AddDialogExitQuest("PJ_B1_1_CONCEICAO_PIECE_OBTAINED");
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}
