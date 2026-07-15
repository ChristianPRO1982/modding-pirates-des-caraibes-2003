//nclude "DIALOGS\PJ Quest S3 target_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string questStatus;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	questStatus = "";
	if (CheckAttribute(PChar, "quest_S3_status"))
	{
		questStatus = PChar.quest_S3_status;
	}

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
			Diag.TempNode = "First time";

			if (questStatus == "target_released")
			{
				d.Text = DLG_TEXT[15];
				Link.l1 = DLG_TEXT[16];
				Link.l1.go = "exit";
			}
			else
			{
				if (questStatus == "target_killed")
				{
					d.Text = DLG_TEXT[17];
					Link.l1 = DLG_TEXT[18];
					Link.l1.go = "exit";
				}
				else
				{
					d.Text = DLG_TEXT[0];
					Link.l1 = DLG_TEXT[1];
					Link.l1.go = "Investigate_01";
				}
			}
		break;

		case "Investigate_01":
			dialog.snd = "Voice\ARSI\ARSI001";
			Diag.TempNode = "Investigate_01";
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "Investigate_02";
		break;

		case "Investigate_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[6];
			Link.l2.go = "Release_01";
			Link.l3 = DLG_TEXT[9];
			Link.l3.go = "Kill_01";
		break;

		case "Release_01":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[7];
			Link.l1 = DLG_TEXT[8];
			Link.l1.go = "Release_Quest";
			Link.l2 = DLG_TEXT[4];
			Link.l2.go = "Investigate_02";
		break;

		case "Release_Quest":
			Diag.CurrentNode = "Released";
			DialogExit();
			AddDialogExitQuest("quest_S3_target_release");
		break;

		case "Kill_01":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Kill_02";
			Link.l2 = DLG_TEXT[4];
			Link.l2.go = "Investigate_02";
		break;

		case "Kill_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "Kill_Quest";
		break;

		case "Kill_Quest":
			Diag.CurrentNode = "Finished";
			DialogExit();
			AddDialogExitQuest("quest_S3_target_kill");
		break;

		case "Released":
			dialog.snd = "Voice\ARSI\ARSI001";
			Diag.TempNode = "Released";
			d.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "exit";
		break;

		case "Finished":
			dialog.snd = "Voice\ARSI\ARSI001";
			Diag.TempNode = "Finished";
			d.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "exit";
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}
