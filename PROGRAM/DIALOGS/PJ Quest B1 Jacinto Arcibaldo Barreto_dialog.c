//nclude "DIALOGS\PJ Quest B1 Jacinto Arcibaldo Barreto_dialog.h"
// object Dialog; declared in dialog.c
// ref NPChar; declared in dialog.c

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog, "Links");

	makeref(NPChar, CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	switch (Dialog.CurrentNode)
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

			if (npchar.quest.meeting == "0")
			{
				dialog.text = DLG_TEXT[0] + npchar.name + " " + npchar.middlename + " " + npchar.lastname + DLG_TEXT[1] + address_form.spa + DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3] + pchar.name + " " + pchar.lastname + DLG_TEXT[4];
				Link.l1.go = "node_1";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "quests";
				link.l2 = DLG_TEXT[7];
				link.l2.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;

		case "node_1":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "quests";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "node_2";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

		case "quests":
			dialog.text = DLG_TEXT[13] + address_form.spa + DLG_TEXT[14];

			if (B12A_IsStarted() && !B12A_IsCompleted())
			{
				string b12aStatus;
				b12aStatus = B12A_GetStatus();

				if (b12aStatus == B12A_STATUS_OFFER)
				{
					link.l30 = DLG_TEXT[29];
					link.l30.go = "B1_2A_offer_1";
				}
				switch (b12aStatus)
				{
					case B12A_STATUS_DELIVERY:
						link.l31 = DLG_TEXT[35];
						link.l31.go = "B1_2A_repeat";
					break;

					case B12A_STATUS_REDMOND_NIGHT:
						link.l31 = DLG_TEXT[35];
						link.l31.go = "B1_2A_repeat";
					break;

					case B12A_STATUS_STOLEN:
						if (B12A_GetReportTarget() != "portugal")
						{
							link.l32 = DLG_TEXT[37];
							link.l32.go = "B1_2A_report_stolen_1";
						}
						if (B12A_GetReportTarget() == "portugal")
						{
							link.l33 = DLG_TEXT[38];
							link.l33.go = "B1_2A_report_repeat";
						}
					break;

					case B12A_STATUS_REPORT_CHOICE:
						if (B12A_GetReportTarget() != "portugal")
						{
							link.l32 = DLG_TEXT[37];
							link.l32.go = "B1_2A_report_stolen_1";
						}
						if (B12A_GetReportTarget() == "portugal")
						{
							link.l33 = DLG_TEXT[38];
							link.l33.go = "B1_2A_report_repeat";
						}
					break;
				}
			}

			if (CheckQuestAttribute("nigel_con_parri_checker", "win_win") || CheckQuestAttribute("nigel_con_parri_checker", "win"))
			{
				link.l1 = DLG_TEXT[15];
				link.l1.go = "garri";
			}

			if (CheckAttribute(pchar, "quest_S3_city"))
			{
				if (pchar.quest_S3_city == "Conceicao")
				{
					if (CheckAttribute(pchar, "quest_S3_status"))
					{
						bool s3_dialogue = false;

						switch (pchar.quest_S3_status)
						{
							case "accepted":
								s3_dialogue = true;
							break;
							case "investigation":
								s3_dialogue = true;
							break;
							case "candidate_target_kill":
								s3_dialogue = true;
							break;
							case "candidate_target_release":
								s3_dialogue = true;
							break;
						}

						if (s3_dialogue)
						{
							if (!CheckAttribute(pchar, "quest_S3_informant_governor"))
							{
								link.l20 = DLG_TEXT[47];
								link.l20.go = "S3_governor_start";
							}
							else
							{
								link.l21 = DLG_TEXT[48];
								link.l21.go = "S3_governor_repeat";
							}
						}
					}
				}
			}
			link.l99 = DLG_TEXT[16];
			link.l99.go = "exit";
		break;

		case "B1_2A_offer_1":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "B1_2A_offer_2";
		break;

		case "B1_2A_offer_2":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "B1_2A_offer_complete";
		break;

		case "B1_2A_offer_complete":
			QuestComplete_B1_2A("PJ_B1_2A_PORTUGAL_HANDOFF");
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
		break;

		case "B1_2A_repeat":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
		break;

		case "B1_2A_report_stolen_1":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "B1_2A_report_stolen_2";
		break;

		case "B1_2A_report_stolen_2":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "B1_2A_report_stolen_3";
		break;

		case "B1_2A_report_stolen_3":
			QuestComplete_B1_2A("PJ_B1_2A_REPORT_PORTUGAL");
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
		break;

		case "B1_2A_report_repeat":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
		break;

		case "garri":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "garri_2";
		break;

		case "garri_2":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			if (CheckQuestAttribute("nigel_con_parri_checker", "win_win"))
			{
				link.l1.go = "garri_3";
			}
			else
			{
				link.l1.go = "exit";
			}
			AddQuestrecord("nigel", "15");
			DeleteAttribute(PChar, "quest.nigel_con_parri_checker");
			PChar.quest.con_parri_expired.over = "yes";
			AddMoneyToCharacter(pchar, 3000);
			ChangeCharacterReputation(pchar, 1);
			AddDialogExitQuest("nigel_third_encounter");
		break;

		case "garri_3":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "garri_4";
		break;

		case "garri_4":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 6000);
			ChangeCharacterReputation(pchar, 1);
		break;

		case "j_day":
			dialog.text = Pchar.name + " " + Pchar.lastname + DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "continue1";
		break;

		case "continue1":
			LAi_QuestDelay("ex_dialog", 2);
			DialogExit();
			NextDiag.CurrentNode = "j_day2";
		break;

		case "j_day2":
			dialog.text = Pchar.name + " " + Pchar.lastname + DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
		break;

		case "S3_governor_start":
			if (CheckAttribute(pchar, "quest_S3_target_truth"))
			{
				if (pchar.quest_S3_target_truth == "guilty")
				{
					dialog.text = DLG_TEXT[49] + pchar.quest_S3_target_name + DLG_TEXT[50];
				}
				else
				{
					dialog.text = DLG_TEXT[51] + pchar.quest_S3_target_name + DLG_TEXT[52];
				}
			}
			else
			{
				dialog.text = DLG_TEXT[51] + pchar.quest_S3_target_name + DLG_TEXT[52];
			}
			link.l1 = DLG_TEXT[53];
			link.l1.go = "S3_governor_done";
		break;

		case "S3_governor_done":
			pchar.quest_S3_informant_governor = true;
			Log_SetStringToLog("S3 informant answered");
			DialogExit();
		break;

		case "S3_governor_repeat":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "exit";
		break;

		case "exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
