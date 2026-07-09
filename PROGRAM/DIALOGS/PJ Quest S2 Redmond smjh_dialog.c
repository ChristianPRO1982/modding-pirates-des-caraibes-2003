//nclude "DIALOGS\PJ Quest S2 Redmond smjh_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string smjhJewelry;
	string smjhJewelryID;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	smjhJewelry = "une bague en or sertie d'emeraudes.";
	smjhJewelryID = "jewelry7";

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
			Diag.TempNode = "Start";
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Continue_02";
		break;

		case "Continue_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[6];
			if (CheckCharacterItem(Pchar,smjhJewelryID))
			{
				Link.l1 = DLG_TEXT[10];
				Link.l1.go = "Continue_04";
			}
			else
			{
				Link.l1 = DLG_TEXT[7];
				Link.l1.go = "Continue_03";
			}
		break;

		case "Continue_03":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "exit";
		break;

		case "Continue_04":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[11] + smjhJewelry + DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "congratulation";
		break;

		case "congratulation":
			Diag.TempNode = "thanks";
			TakeItemFromCharacter(Pchar, smjhJewelryID);
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[16] + PChar.lastname + DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "exit";
			AddDialogExitQuest("quest_S2_closed_1");
		break;

		case "thanks":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "Continue_05";
		break;
		
		case "Continue_05":
			DialogExit();
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}
