//nclude "DIALOGS\PJ PNJ Trop Fort.h"
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
			Link.l1.go = "Start";
		break;

		case "Start":
			dialog.snd = "voice\QCSI\QCSI001";
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Gold";
			Link.l2 = DLG_TEXT[6];
			Link.l2.go = "XP";
			Link.l3 = DLG_TEXT[7];
			Link.l3.go = "Reputation";
		break;

		case "Gold":
			dialog.snd = "voice\QCSI\QCSI001";
			AddMoneyToCharacter(pchar, 50000);
			d.Text = DLG_TEXT[8];
			Link.l1.go = "exit";
		break;

		case "XP":
			dialog.snd = "voice\QCSI\QCSI001";
			AddPartyExp(pchar, 50000);
			d.Text = DLG_TEXT[8];
			Link.l1.go = "exit";
		break;

		case "Reputation":
			dialog.snd = "voice\QCSI\QCSI001";
			d.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "Reputations_GOOD";
			Link.l2 = DLG_TEXT[11];
			Link.l2.go = "REPUTATION_NEUTRAL";
			Link.l3 = DLG_TEXT[12];
			Link.l3.go = "Reputations_BAD";
		break;

		case "Reputations_GOOD":
			dialog.snd = "voice\QCSI\QCSI001";
			d.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "REPUTATION_PLAIN";
			Link.l2 = DLG_TEXT[19];
			Link.l2.go = "REPUTATION_GOOD";
			Link.l3 = DLG_TEXT[20];
			Link.l3.go = "REPUTATION_VERYGOOD";
			Link.l4 = DLG_TEXT[21];
			Link.l4.go = "REPUTATION_HERO";
		break;

		case "Reputations_BAD":
			dialog.snd = "voice\QCSI\QCSI001";
			d.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "REPUTATION_RASCAL";
			Link.l2 = DLG_TEXT[16];
			Link.l2.go = "REPUTATION_SWINDLER";
			Link.l3 = DLG_TEXT[15];
			Link.l3.go = "REPUTATION_BASTARD";
			Link.l4 = DLG_TEXT[14];
			Link.l4.go = "REPUTATION_HORROR";
		break;

		case "REPUTATION_HERO":
			dialog.snd = "voice\QCSI\QCSI001";
			pchar.reputation = REPUTATION_NEUTRAL;
			ChangeCharacterReputation(pchar, 40);
			d.Text = DLG_TEXT[8];
			Link.l1.go = "exit";
		break;

		case "REPUTATION_VERYGOOD":
			dialog.snd = "voice\QCSI\QCSI001";
			pchar.reputation = REPUTATION_NEUTRAL;
			ChangeCharacterReputation(pchar, 30);
			d.Text = DLG_TEXT[8];
			Link.l1.go = "exit";
		break;

		case "REPUTATION_GOOD":
			dialog.snd = "voice\QCSI\QCSI001";
			pchar.reputation = REPUTATION_NEUTRAL;
			ChangeCharacterReputation(pchar, 20);
			d.Text = DLG_TEXT[8];
			Link.l1.go = "exit";
		break;

		case "REPUTATION_PLAIN":
			dialog.snd = "voice\QCSI\QCSI001";
			pchar.reputation = REPUTATION_NEUTRAL;
			ChangeCharacterReputation(pchar, 10);
			d.Text = DLG_TEXT[8];
			Link.l1.go = "exit";
		break;

		case "REPUTATION_NEUTRAL":
			dialog.snd = "voice\QCSI\QCSI001";
			pchar.reputation = REPUTATION_NEUTRAL;
			d.Text = DLG_TEXT[8];
			Link.l1.go = "exit";
		break;

		case "REPUTATION_RASCAL":
			dialog.snd = "voice\QCSI\QCSI001";
			pchar.reputation = REPUTATION_NEUTRAL;
			ChangeCharacterReputation(pchar, -10);
			d.Text = DLG_TEXT[8];
			Link.l1.go = "exit";
		break;

		case "REPUTATION_SWINDLER":
			dialog.snd = "voice\QCSI\QCSI001";
			pchar.reputation = REPUTATION_NEUTRAL;
			ChangeCharacterReputation(pchar, -20);
			d.Text = DLG_TEXT[8];
			Link.l1.go = "exit";
		break;

		case "REPUTATION_BASTARD":
			dialog.snd = "voice\QCSI\QCSI001";
			pchar.reputation = REPUTATION_NEUTRAL;
			ChangeCharacterReputation(pchar, -30);
			d.Text = DLG_TEXT[8];
			Link.l1.go = "exit";
		break;

		case "REPUTATION_HORROR":
			dialog.snd = "voice\QCSI\QCSI001";
			pchar.reputation = REPUTATION_NEUTRAL;
			ChangeCharacterReputation(pchar, -40);
			d.Text = DLG_TEXT[8];
			Link.l1.go = "exit";
		break;



		case "exit":
			trace("Dialog Temp Node = " + Diag.TempNode);
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}