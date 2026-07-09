#include "DIALOGS\PJ HELP Malcolm Hatcher_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	int iGreeting;
	int iRumor;

	DeleteAttribute(&Dialog, "Links");

	makeref(NPChar, CharacterRef);
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

			Diag.TempNode = "First time";

			iGreeting = rand(2);
			iRumor = rand(2);
			switch (iGreeting)
			{
				case 0: d.Text = DLG_TEXT[0]; break;
				case 1: d.Text = DLG_TEXT[1]; break;
				case 2: d.Text = DLG_TEXT[2]; break;
			}

			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "exit";
		break;

		case "rumor_step1":
			switch (iRumor)
			{
				case 0: d.Text = DLG_TEXT[5]; break;
				case 1: d.Text = DLG_TEXT[6]; break;
				case 2: d.Text = DLG_TEXT[7]; break;
			}

			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "rumor_step2";

			Link.l2 = DLG_TEXT[11];
			Link.l2.go = "exit";
		break;

		case "rumor_step2":
			switch (iRumor)
			{
				case 0: d.Text = DLG_TEXT[8]; break;
				case 1: d.Text = DLG_TEXT[9]; break;
				case 2: d.Text = DLG_TEXT[10]; break;
			}

			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "exit";
		break;

		case "exit":
			DialogExit();
		break;
	}
}