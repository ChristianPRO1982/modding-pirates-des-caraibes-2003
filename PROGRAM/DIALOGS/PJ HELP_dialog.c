#include "DIALOGS\PJ HELP_dialog.h"
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
			// d.Text = RandPhrase(DLG_TEXT[0] + Address_Form.Eng + DLG_TEXT[1], DLG_TEXT[2], DLG_TEXT[3] + Address_Form.Eng + DLG_TEXT[4], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1] + PChar.name + " " + PChar.lastname + DLG_TEXT[2] + PChar.ship.name + DLG_TEXT[3];
			Link.l1.go = "exit";
		break;



		case "exit":
			trace("Dialog Temp Node = " + Diag.TempNode);
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}