//nclude "DIALOGS\PJ Quest B1 Robert Christopher Silehard_dialog.h"

bool B11_IsSilehard(ref NPChar)
{
	return NPChar.id == "Robert Christopher Silehard";
}

void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	aref Link, Diag;
	string NPC_meeting;

	PChar = GetMainCharacter();

	DeleteAttribute(&Dialog, "Links");

	makeref(NPChar, CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	trace("----------------------------------" + Dialog.CurrentNode);
	switch(Dialog.CurrentNode)
	{
		// Service commun
		case "exit":
			NPChar.quest.meeting = NPC_meeting;
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if (!B11_IsSilehard(NPChar))
			{
				d.Text = DLG_TEXT[45];
				Link.l1 = DLG_TEXT[46];
				Link.l1.go = "exit";
				Diag.TempNode = "First time";
				break;
			}

			d.Text = DLG_TEXT[0] + PChar.name + " " + PChar.lastname + DLG_TEXT[1] + PChar.ship.name + DLG_TEXT[2] + DLG_TEXT[3];
			Link.l1 = DLG_TEXT[4];
			Link.l1.go = "meeting";
			NPC_meeting = "1";

			Diag.TempNode = "First time";
		break;

		case "meeting":
			// la ligne si dessous uniquement pour le développement de la quête G1
			Island_SetReloadEnableLocal("IslaMuelle", "reload_2", true);
			d.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[9];
			Link.l2.go = "exit";
			Diag.TempNode = "meeting";
		break;

		case "quest lines":
			B11_SyncTransverseState();
			B12A_SyncTransverseState();
			d.Text = DLG_TEXT[7];
			Link.l99 = DLG_TEXT[9];
			Link.l99.go = "exit";

			if (!CheckAttribute(pchar, "quest_PJ_sidequests_unlocked") || sti(pchar.quest_PJ_sidequests_unlocked) != true)
			{
				d.Text = DLG_TEXT[8];
				break;
			}

			if (B12A_IsStarted() && !B12A_IsCompleted())
			{
				if (B12A_GetStatus() == B12A_STATUS_OFFER)
				{
					Link.l1 = DLG_TEXT[66];
					Link.l1.go = "B1_2A_offer_reminder";
					break;
				}
				if (B12A_GetStatus() == B12A_STATUS_DELIVERY || B12A_GetStatus() == B12A_STATUS_REDMOND_NIGHT)
				{
					Link.l1 = DLG_TEXT[68];
					Link.l1.go = "B1_2A_delivery_reminder";
					break;
				}
				if (B12A_GetStatus() == B12A_STATUS_STOLEN || B12A_GetStatus() == B12A_STATUS_REPORT_CHOICE)
				{
					Link.l1 = "Les objets diplomatiques m'ont ete voles avant mon retour.";
					Link.l1.go = "B1_2A_stolen_1";
					break;
				}
			}

			if (B1_IsAnotherSubquestActive(B11_TRANS_SUBQUEST) && !B1_IsSubquestActive(B12A_TRANS_SUBQUEST))
			{
				break;
			}

			if (B12A_CanStartQuest())
			{
				Link.l1 = DLG_TEXT[57];
				Link.l1.go = "B1_2A_start_1";
				break;
			}

			if (B11_CanStartQuest())
			{
				Link.l1 = DLG_TEXT[10];
				Link.l1.go = "B1_1_start_1";
				break;
			}

			if (B11_IsCompleted() || B11_IsTransverseCompleted())
			{
				Link.l1 = DLG_TEXT[15];
				Link.l1.go = "B1_1_completed_repeat";
				break;
			}

			if (pchar.quest_b1_1_status == "intro_collect")
			{
				Link.l1 = DLG_TEXT[11];
				Link.l1.go = "B1_1_intro_reminder";
			}
			if (pchar.quest_b1_1_status == "intro_ready_report")
			{
				if (B11_HasAllIntroItems())
				{
					Link.l1 = DLG_TEXT[12];
					Link.l1.go = "B1_1_intro_turnin_1";
				}
				else
				{
					Link.l1 = DLG_TEXT[11];
					Link.l1.go = "B1_1_intro_reminder";
				}
			}
			if (pchar.quest_b1_1_status == "muelle_pending" || pchar.quest_b1_1_status == "conceicao_pending" || pchar.quest_b1_1_status == "douwesen_pending" || pchar.quest_b1_1_status == "jungle_clue_pending" || pchar.quest_b1_1_status == "dig_ready")
			{
				Link.l1 = DLG_TEXT[13];
				if (pchar.quest_b1_1_status == "muelle_pending")
				{
					Link.l1.go = "B1_1_muelle_reminder";
				}
				if (pchar.quest_b1_1_status == "conceicao_pending")
				{
					Link.l1.go = "B1_1_conceicao_reminder";
				}
				if (pchar.quest_b1_1_status == "douwesen_pending")
				{
					Link.l1.go = "B1_1_douwesen_reminder";
				}
				if (pchar.quest_b1_1_status == "jungle_clue_pending")
				{
					Link.l1.go = "B1_1_jungle_reminder";
				}
				if (pchar.quest_b1_1_status == "dig_ready")
				{
					Link.l1.go = "B1_1_dig_reminder";
				}
			}
			if (pchar.quest_b1_1_status == "final_ready")
			{
				Link.l1 = DLG_TEXT[14];
				Link.l1.go = "B1_1_final_turnin_1";
			}
		break;

		// Silehard B1.1
		case "B1_1_start_1":
			d.Text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "B1_1_start_2";
			Link.l2 = DLG_TEXT[18];
			Link.l2.go = "exit";
		break;

		case "B1_1_start_2":
			d.Text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "B1_1_start_accept";
		break;

		case "B1_1_start_accept":
			QuestComplete_B1_1("PJ_B1_1_START");
			d.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "exit";
		break;

		case "B1_2A_start_1":
			d.Text = DLG_TEXT[58];
			Link.l1 = DLG_TEXT[59];
			Link.l1.go = "B1_2A_start_2";
		break;

		case "B1_2A_start_2":
			d.Text = DLG_TEXT[60];
			Link.l1 = DLG_TEXT[61];
			Link.l1.go = "B1_2A_start_3";
		break;

		case "B1_2A_start_3":
			d.Text = DLG_TEXT[62];
			Link.l1 = DLG_TEXT[63];
			Link.l1.go = "B1_2A_start_accept";
		break;

		case "B1_2A_start_accept":
			QuestComplete_B1_2A("PJ_B1_2A_START");
			d.Text = DLG_TEXT[64];
			Link.l1 = DLG_TEXT[65];
			Link.l1.go = "exit";
		break;

		case "B1_2A_offer_reminder":
			d.Text = DLG_TEXT[66];
			Link.l1 = DLG_TEXT[67];
			Link.l1.go = "exit";
		break;

		case "B1_2A_delivery_reminder":
			d.Text = DLG_TEXT[68];
			Link.l1 = DLG_TEXT[69];
			Link.l1.go = "exit";
		break;

		case "B1_2A_stolen_1":
			if (B12A_GetReportTarget() == "portugal")
			{
				d.Text = "Et vous avez donc cru bon d'aller d'abord trouver Barreto. Apres tout ce que je vous avais explique sur ce qui menace deja ces mers.";
			}
			else
			{
				d.Text = "Voles ? Ici, sous mon nez ? Cette lettre de cachet et ce cadeau n'etaient pas de simples marques de courtoisie.";
			}
			Link.l1 = "Ils m'attendaient. Ce n'etait ni un hasard, ni un simple vol. De faux soldats anglais.";
			Link.l1.go = "B1_2A_stolen_2";
		break;

		case "B1_2A_stolen_2":
			d.Text = "Alors ils savaient ce qu'ils prenaient. Nous sommes tres decus... Je suis tres decu par cette issue.";
			Link.l1 = "Leur parler trahissait autre chose. Des tournures etranges. Presque hollandaises.";
			Link.l1.go = "B1_2A_stolen_3";
		break;

		case "B1_2A_stolen_3":
			if (B12A_GetReportTarget() == "")
			{
				QuestComplete_B1_2A("PJ_B1_2A_REPORT_ENGLAND");
			}
			QuestComplete_B1_2A("PJ_B1_2A_SILEHARD_TRANSITION");
			d.Text = "Bien. Vous allez reprendre leur piste. Vite. Proprement. Sans bruit. Je veux une enquete efficace, rapide et discrete. Retrouvons d'abord leur pays, puis leur port.";
			Link.l1 = "Je vais leur trouver un accent, puis un refuge.";
			Link.l1.go = "exit";
		break;

		case "B1_1_intro_reminder":
			d.Text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "exit";
		break;

		case "B1_1_intro_turnin_1":
			if (!B11_HasAllIntroItems())
			{
				d.Text = DLG_TEXT[23];
				Link.l1 = DLG_TEXT[24];
				Link.l1.go = "exit";
				break;
			}
			d.Text = DLG_TEXT[25];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "B1_1_intro_turnin_2";
		break;

		case "B1_1_intro_turnin_2":
			if (!B11_HasAllIntroItems())
			{
				d.Text = DLG_TEXT[23];
				Link.l1 = DLG_TEXT[24];
				Link.l1.go = "exit";
				break;
			}
			d.Text = DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "B1_1_intro_turnin_3";
		break;

		case "B1_1_intro_turnin_3":
			if (!B11_HasAllIntroItems())
			{
				d.Text = DLG_TEXT[23];
				Link.l1 = DLG_TEXT[24];
				Link.l1.go = "exit";
				break;
			}
			QuestComplete_B1_1("PJ_B1_1_INTRO_REPORT_COMPLETE");
			d.Text = DLG_TEXT[29];
			Link.l1 = DLG_TEXT[30];
			Link.l1.go = "exit";
		break;

		case "B1_1_stage2_reminder":
			B11_SyncTransverseState();
			d.Text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "exit";
		break;

		case "B1_1_muelle_reminder":
			d.Text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "exit";
		break;

		case "B1_1_conceicao_reminder":
			d.Text = DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
		break;

		case "B1_1_douwesen_reminder":
			d.Text = DLG_TEXT[51];
			Link.l1 = DLG_TEXT[52];
			Link.l1.go = "exit";
		break;

		case "B1_1_jungle_reminder":
			d.Text = DLG_TEXT[53];
			Link.l1 = DLG_TEXT[54];
			Link.l1.go = "exit";
		break;

		case "B1_1_dig_reminder":
			d.Text = DLG_TEXT[55];
			Link.l1 = DLG_TEXT[56];
			Link.l1.go = "exit";
		break;

		case "B1_1_final_turnin_1":
			d.Text = DLG_TEXT[31];
			Link.l1 = DLG_TEXT[32];
			Link.l1.go = "B1_1_final_turnin_2";
		break;

		case "B1_1_final_turnin_2":
			d.Text = DLG_TEXT[33];
			Link.l1 = DLG_TEXT[34];
			Link.l1.go = "B1_1_final_turnin_3";
		break;

		case "B1_1_final_turnin_3":
			QuestComplete_B1_1("PJ_B1_1_FINAL_REPORT_COMPLETE");
			d.Text = DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "exit";
		break;

		case "B1_1_completed_repeat":
			d.Text = DLG_TEXT[37];
			Link.l1 = DLG_TEXT[38];
			Link.l1.go = "exit";
		break;

	}
}
