//nclude "DIALOGS\John  Filbert_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	ref PChar;
	PChar = GetMainCharacter();


	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Aeaeia ia?aue - ia?aay ano?a?a
		case "First time":
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Gov_Dialog_1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if (npchar.quest.meeting == "0")
			{
				Dialog.Text = DLG_TEXT[0] + address_form.eng + DLG_TEXT[1] + npchar.name + " " + npchar.lastname + DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3] + pchar.name + " " + pchar.lastname + DLG_TEXT[4];
				link.l1.go = "node_1";
			}
			NextDiag.TempNode = "Second time";
		break;

		case "second time":
			dialog.text = pcharrepphrase(DLG_TEXT[5] + address_form.eng + DLG_TEXT[6], DLG_TEXT[7]);
			Link.l1 = pcharrepphrase(DLG_TEXT[8] + npchar.name + DLG_TEXT[9], DLG_TEXT[10]); 
			link.l1.go = "node_1";
			
			NextDiag.TempNode = "Second time";
		break;

		case "node_1":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "market";
			link.l2 = DLG_TEXT[13];
			link.l2.go = "quests";
			link.l3 = DLG_TEXT[14];
			link.l3.go = "exit";
		break;

		case "market":
			dialog.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "trade_1";
			Link.l2 = DLG_TEXT[17];
			Link.l2.go = "items";
			Link.l3 = DLG_TEXT[18];
			Link.l3.go = "exit";
		break;

		case "trade_1":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchStore(GREENFORD_STORE);
		break;

		case "items":
			if (npchar.quest.item_date != lastspeak_date)
			{
				GiveItemToTrader(npchar);
				npchar.quest.item_date = lastspeak_date;
			}
			
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

		case "quests":
			iTest = 0;
			Dialog.text = DLG_TEXT[19];
			if (CheckAttribute(pchar, "quest.iQuantityGoods"))
			{
				int iQuantityShipGoods = pchar.quest.iQuantityGoods;
				int iQuestTradeGoods = pchar.quest.iTradeGoods;
			}
			if (CheckQuestAttribute("generate_trade_quest_progress", "begin") || CheckQuestAttribute("generate_trade_quest_progress",  "failed"))
			{
				if (CheckQuestAttribute("iTradeNation", npchar.nation) &&  GetSquadronGoods(pchar, iQuestTradeGoods) >= iQuantityShipGoods && pchar.quest.iTradeColony == pchar.location)
				{
					dialog.text = DLG_TEXT[20];
					link.l1 = DLG_TEXT[21];
					link.l1.go = "generate_quest_2";
				}
			}
			else
			{
				if (!CheckQuestAttribute("generate_trade_quest_progress", "begin"))
				{
					link.l1 = DLG_TEXT[22];
					link.l1.go = "generate_quest";
				}
			}
						if (CheckAttribute(pchar, "quest_S3_city") && pchar.quest_S3_city == "Greenford")
			{
				if (CheckAttribute(pchar, "quest_S3_status"))
				{
					bool s3_dialogue = false;  					switch (pchar.quest_S3_status) 					{ 						case "accepted": 							s3_dialogue = true; 						break; 						case "investigation": 							s3_dialogue = true; 						break; 						case "candidate_target_kill": 							s3_dialogue = true; 						break; 						case "candidate_target_release": 							s3_dialogue = true; 						break; 					}  					if (s3_dialogue) 					{ 						if (!CheckAttribute(pchar, "quest_S3_informant_merchant"))
							{
								link.l20 = "Je voudrais votre avis de marchand sur une personne de cette ville.";
								link.l20.go = "S3_merchant_start";
							}
							else
							{
								link.l21 = "Vous m'avez deja donne votre avis sur cette affaire.";
								link.l21.go = "S3_merchant_repeat";
							}
					}
				}
			}
			link.l99 = DLG_TEXT[23];
			Link.l99.go = "exit";
		break;

		case "generate_quest":
			if (npchar.quest.trade_date != lastspeak_date)
			{
				npchar.quest.trade_date = lastspeak_date;
				//i?iaa?ea a?a?aaaiinoe iai no?aiu oi?aiaoa
				if (GetNationRelation2MainCharacter(ENGLAND) == RELATION_ENEMY)
				{
					dialog.text = DLG_TEXT[24];
					link.l1 = DLG_TEXT[25];
					link.l1.go = "exit";
				}
				else
				{
					int iTradeNation = GenerateNationTrade(ENGLAND);
					if (iTradeNation < 0)
					{
						dialog.text = DLG_TEXT[26];
						link.l1 = DLG_TEXT[27];
						link.l1.go = "exit";
					}
					else
					{
						//i?iaa?yai eiii?o/yenii?o
						int iTradeGoods = rand(20) + 6;
						//i?iaa?yai naiaiaiia ianoi (i?e yoii aie?ii aiauaouny ii iaiuoae ia?a 100 aaeieo aua?aiiiai a?oca
						if (GetSquadronFreeSpace(pchar, iTradeGoods) < 100)
						{
							dialog.text = DLG_TEXT[28];
							link.l1 = DLG_TEXT[29];
							link.l1.go = "exit";
						}
						else
						{
							int iQuantityGoods = GetSquadronFreeSpace(pchar, iTradeGoods) - 20;
							int iMoney = ((iQuantityGoods *10+99)/100)*100;
							int iDaysExpired = 30;

							pchar.quest.iTradeGoods = iTradeGoods;
							pchar.quest.iQuantityGoods = iQuantityGoods;
							pchar.quest.iMoney = iMoney;
							pchar.quest.iTradeNation = iTradeNation;
							
							string sNation;

							switch (iTradeNation)
							{
								case FRANCE: sNation = FRA_COLONY; break;
								case SPAIN: sNation = SPA_COLONY; break;
								case HOLLAND: sNation = HOL_COLONY; break;
								case PORTUGAL: sNation = POR_COLONY; break;
								case ENGLAND: 
									int iColony = rand(2);
									switch (iColony)
									{
										case 0: sNation = RED_COLONY; pchar.quest.iTradeColony = "Redmond_store"; break;
										case 1: sNation = GREEN_COLONY; pchar.quest.iTradeColony = "Greenford_store"; break;
										case 2: sNation = OX_COLONY; pchar.quest.iTradeColony = "Oxbay_store"; break;
									}
								break;
							}
							dialog.text = DLG_TEXT[30] + sNation + DLG_TEXT[31] + pchar.quest.iMoney + DLG_TEXT[32];
							link.l1 = DLG_TEXT[33];
							link.l1.go = "exit_trade";
							link.l2  = DLG_TEXT[34];
							link.l2.go = "exit";
						}
					}
				}
			}
			else
			{
				dialog.text = DLG_TEXT[35];
				link.l1 = DLG_TEXT[36];
				link.l1.go = "exit";
			}
		break;
		
		case "exit_trade":
			AddDialogExitQuest("trade_quest_open");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "generate_quest_2":
			if (pchar.quest.generate_trade_quest_progress == "failed")
			{
				dialog.text = DLG_TEXT[37];
				link.l1 = DLG_TEXT[38];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, -1);
			}
			else
			{
				dialog.text = DLG_TEXT[39];
				link.l1 = DLG_TEXT[40];
				link.l1.go = "exit";
				ChangeCharacterReputation(pchar, 1);
				AddPartyExp(pchar, (makeint(pchar.quest.iMoney)/2));
				AddMoneyToCharacter(pchar, makeint(pchar.quest.iMoney));
				pchar.quest.generate_trade_quest_progress = "";
				pchar.quest.generate_trade_quest.over = "yes";
				RemoveCharacterGoods(pchar, makeint(pchar.quest.iTradeGoods), makeint(pchar.quest.iQuantityGoods));
			}
			AddDialogExitQuest("close_trade_quest");
		break;
		
		case "no_quests":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "node_1";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		case "S3_merchant_start":
			if (CheckAttribute(pchar, "quest_S3_target_truth") && pchar.quest_S3_target_truth == "guilty")
			{
				d.Text = "Un marchand apprend vite a reconnaitre les clients qui paient trop tard, mentent trop vite et changent trop souvent d'histoire. " + pchar.quest_S3_target_name + " m'inspire ce genre de mefiance. Je ne ferais pas credit a cette personne.";
			}
			else
			{
				d.Text = "Je juge les gens a leurs comptes, a leurs promesses et a la facon dont ils traitent ceux qui dependent d'eux. Jusqu'ici, je n'ai rien vu chez " + pchar.quest_S3_target_name + " qui merite un chatiment de sang.";
			}
			link.l1 = "Votre franchise m'est utile.";
			link.l1.go = "S3_merchant_done";
		break;

		case "S3_merchant_done":
			pchar.quest_S3_informant_merchant = true;
			Log_SetStringToLog("S3 informant answered");
			DialogExit();
		break;

		case "S3_merchant_repeat":
			d.Text = "Je vous ai deja dit ce que j'avais observe. Je n'ai rien a y ajouter pour le moment.";
			link.l1 = "Tres bien.";
			link.l1.go = "exit";
		break;
	}
}
