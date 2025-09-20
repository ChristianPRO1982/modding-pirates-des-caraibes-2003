//nclude "DIALOGS\PJ Quest M1 Chui A-poo_dialog.h"
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
			d.Text = DLG_TEXT[0] + PChar.name + " " + PChar.lastname + DLG_TEXT[1] + PChar.ship.name + DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "Start";
		break;

		case "Start":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[6];
			Link.l2.go = "Continue_01";
		break;

		case "Continue_01":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[7];
			Link.l1 = DLG_TEXT[8];
			Link.l1.go = "agreeded";
			Link.l2 = DLG_TEXT[9];
			Link.l2.go = "exit";
		break;

		case "agreeded":
			Diag.TempNode = "Waiting";
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[10] + DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "exit";
		break;

		case "Waiting":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "exit";
		break;



		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}