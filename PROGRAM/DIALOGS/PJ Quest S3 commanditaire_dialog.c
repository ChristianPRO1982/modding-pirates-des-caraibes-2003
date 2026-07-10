//nclude "DIALOGS\PJ Quest S3 commanditaire_dialog.h"
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

			if (questStatus == "target_killed")
			{
				d.Text = DLG_TEXT[17];
				Link.l1 = DLG_TEXT[19];
				Link.l1.go = "Reward_Exit";
			}
			else
			{
				if (questStatus == "target_released")
				{
					d.Text = DLG_TEXT[20];
					Link.l1 = DLG_TEXT[21];
					Link.l1.go = "Duel_01";
				}
				else
				{
					if (questStatus == "accepted" || questStatus == "investigation" || questStatus == "candidate_target_kill" || questStatus == "candidate_target_release")
					{
						d.Text = DLG_TEXT[15];
						Link.l1 = DLG_TEXT[16];
						Link.l1.go = "exit";
					}
					else
					{
						if (questStatus == "commanditaire_paid" || questStatus == "commanditaire_duel" || questStatus == "completed" || questStatus == "closed")
						{
							d.Text = DLG_TEXT[24];
							Link.l1 = DLG_TEXT[19];
							Link.l1.go = "exit";
						}
						else
						{
							d.Text = DLG_TEXT[0];
							Link.l1 = DLG_TEXT[1];
							Link.l1.go = "Offer_01";
							Link.l2 = DLG_TEXT[2];
							Link.l2.go = "Refuse";
						}
					}
				}
			}
		break;

		case "Start":
			dialog.snd = "Voice\ARSI\ARSI001";
			Diag.TempNode = "Start";
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Offer_01";
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "Refuse";
		break;

		case "Offer_01":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[3];
			Link.l1 = DLG_TEXT[4];
			Link.l1.go = "Offer_02";
			Link.l2 = DLG_TEXT[12];
			Link.l2.go = "Refuse";
		break;

		case "Offer_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "Offer_03";
			Link.l2 = DLG_TEXT[8];
			Link.l2.go = "Offer_More_01";
			Link.l3 = DLG_TEXT[12];
			Link.l3.go = "Refuse";
		break;

		case "Offer_03":
			dialog.snd = "Voice\ARSI\ARSI001";
			if (!CheckAttribute(PChar, "quest_S3_target_name"))
			{
				S3_SetGeneratedTargetData();
			}
			d.Text = DLG_TEXT[7];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Accept";
			Link.l2 = DLG_TEXT[12];
			Link.l2.go = "Refuse";
		break;

		case "Offer_More_01":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "Offer_More_02";
		break;

		case "Offer_More_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			if (!CheckAttribute(PChar, "quest_S3_target_name"))
			{
				S3_SetGeneratedTargetData();
			}
			d.Text = DLG_TEXT[7];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Accept";
			Link.l2 = DLG_TEXT[12];
			Link.l2.go = "Refuse";
		break;

		case "Accept":
			dialog.snd = "Voice\ARSI\ARSI001";
			Diag.TempNode = "Waiting";
			if (!CheckAttribute(PChar, "quest_S3_target_name"))
			{
				S3_SetGeneratedTargetData();
			}
			d.Text = DLG_TEXT[13] + PChar.quest_S3_target_name + DLG_TEXT[25];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "Accept_Exit";
		break;

		case "Accept_Exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("quest_S3_offer_accept");
		break;

		case "Refuse":
			Diag.TempNode = "Finished";
			DialogExit();
			AddDialogExitQuest("quest_S3_offer_refuse");
		break;

		case "Waiting":
			dialog.snd = "Voice\ARSI\ARSI001";
			Diag.TempNode = "Waiting";
			d.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "exit";
		break;

		case "ReturnKill":
			dialog.snd = "Voice\ARSI\ARSI001";
			Diag.TempNode = "ReturnKill";
			d.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "Reward_Exit";
		break;

		case "Reward_Exit":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "Reward_Quest";
		break;

		case "Reward_Quest":
			Diag.CurrentNode = "Finished";
			DialogExit();
			AddDialogExitQuest("quest_S3_collect_reward");
		break;

		case "ReturnRelease":
			dialog.snd = "Voice\ARSI\ARSI001";
			Diag.TempNode = "ReturnRelease";
			d.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "Duel_01";
		break;

		case "Duel_01":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "Duel_Quest";
		break;

		case "Duel_Quest":
			Diag.CurrentNode = "Finished";
			DialogExit();
			AddDialogExitQuest("quest_S3_start_duel");
		break;

		case "Finished":
			dialog.snd = "Voice\ARSI\ARSI001";
			Diag.TempNode = "Finished";
			d.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "exit";
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}
