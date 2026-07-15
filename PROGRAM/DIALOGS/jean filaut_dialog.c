//nclude "DIALOGS\jean filaut_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

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
			Dialog.ani = "Gov_Dialog_2";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			Dialog.Text = DLG_TEXT[0] + npchar.name + " " + npchar.lastname + DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2] + pchar.name + " " + pchar.lastname + DLG_TEXT[3];
			Link.l1.go = "Second Time";
			NextDiag.TempNode = "Second time";
		break;

		case "Second time":
			dialog.text = DLG_TEXT[4] + Address_Form.fra + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "shipyard";
			link.l2 = DLG_TEXT[7];
			link.l2.go = "quest";
			link.l3 = DLG_TEXT[8];
			link.l3.go = "exit";
			NextDiag.TempNode = "Second time";
		break;

		case "quest":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Second time";
			link.l2 = DLG_TEXT[11];
						if (CheckAttribute(pchar, "quest_S3_city") && pchar.quest_S3_city == "FalaiseDeFleur")
			{
				if (CheckAttribute(pchar, "quest_S3_status"))
				{
					bool s3_dialogue = false;  					switch (pchar.quest_S3_status) 					{ 						case "accepted": 							s3_dialogue = true; 						break; 						case "investigation": 							s3_dialogue = true; 						break; 						case "candidate_target_kill": 							s3_dialogue = true; 						break; 						case "candidate_target_release": 							s3_dialogue = true; 						break; 					}  					if (s3_dialogue) 					{ 						if (!CheckAttribute(pchar, "quest_S3_informant_shipyard"))
							{
								link.l20 = "J'aurais besoin d'un avis de marin sur quelqu'un de cette ville.";
								link.l20.go = "S3_shipyard_start";
							}
							else
							{
								link.l21 = "Vous m'avez deja parle de cette personne.";
								link.l21.go = "S3_shipyard_repeat";
							}
					}
				}
			}
			link.l2.go = "exit";
		break;

		case "shipyard":
			dialog.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "SHIPYARD_interface";
			Link.l2 = DLG_TEXT[14];
			Link.l2.go = "Cannons_interface";
			Link.l3 = DLG_TEXT[15];
			Link.l3.go = "exit";
		break;

		case "SHIPYARD_interface":
			NextDiag.CurrentNode = NextDiag.TempNode;

			if (npchar.quest.Meeting != lastspeak_date)
			{
				int iTest_ship;

				DeleteAttribute(npchar, "shipyard");
			
				npchar.shipyard.ship1 = SHIP_TARTANE;

				iTest_ship = rand(2);
				if (iTest_ship == 1)
				{
					npchar.shipyard.ship2 = SHIP_BARQUE_FRANCE;
				}
				if (iTest_ship == 2) 
				{
					npchar.shipyard.ship2 = SHIP_BARQUE2_FRANCE;
				}

				iTest_ship = rand(2);
				if (iTest_ship == 1) npchar.shipyard.ship3 = SHIP_YACHT_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship3 = SHIP_YACHT2_FRANCE;
				
				iTest_ship = rand(2);
				if (iTest_ship == 1) npchar.shipyard.ship4 = SHIP_LUGGER_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship4 = SHIP_LUGGER2_FRANCE;

				iTest_ship = rand(3);
				if (iTest_ship == 1) npchar.shipyard.ship5 = SHIP_SLOOP_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship5 = SHIP_SLOOP2_FRANCE;
				
				iTest_ship = rand(3);
				if (iTest_ship == 1) npchar.shipyard.ship6 = SHIP_GALEOTH_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship6 = SHIP_GALEOTH2_FRANCE;
		
				iTest_ship = rand(3);
				if (iTest_ship == 1) npchar.shipyard.ship7 = SHIP_XEBEC_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship7 = SHIP_XEBEC2_FRANCE;
				
				iTest_ship = rand(4);
				if (iTest_ship == 1) npchar.shipyard.ship8 = SHIP_SCHOONER_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship8 = SHIP_SCHOONER2_FRANCE;
				
				iTest_ship = rand(4);
				if (iTest_ship == 1) npchar.shipyard.ship9 = SHIP_CARAVEL_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship9 = SHIP_CARAVEL2_FRANCE;
				
				iTest_ship = rand(4);
				if (iTest_ship == 1) npchar.shipyard.ship10 = SHIP_FLEUT_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship10 = SHIP_FLEUT2_FRANCE;
				
				iTest_ship = rand(5);
				if (iTest_ship == 1) npchar.shipyard.ship11 = SHIP_PINNACE_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship11 = SHIP_PINNACE2_FRANCE;
				
				iTest_ship = rand(5);
				if (iTest_ship == 1) npchar.shipyard.ship12 = SHIP_BRIG_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship12 = SHIP_BRIG2_FRANCE;
				
				iTest_ship = rand(5);
				if (iTest_ship == 1) npchar.shipyard.ship13 = SHIP_GALEON_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship13 = SHIP_GALEON2_FRANCE;

				iTest_ship = rand(6);
				if (iTest_ship == 1) npchar.shipyard.ship14 = SHIP_CORVETTE_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship14 = SHIP_CORVETTE2_FRANCE;

				iTest_ship = rand(6);
				if (iTest_ship == 1) npchar.shipyard.ship15 = SHIP_FRIGATE_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship15 = SHIP_FRIGATE2_FRANCE;

				iTest_ship = rand(7);
				if (iTest_ship == 1) npchar.shipyard.ship16 = SHIP_BATTLESHIP_FRANCE;
				if (iTest_ship == 2) npchar.shipyard.ship16 = SHIP_BATTLESHIP2_FRANCE;

				npchar.quest.Meeting = lastspeak_date;
			}
			
			DialogExit();
			LaunchShipyard(npchar);
		break;

		case "CANNONS_interface":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchCannons();
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		case "S3_shipyard_start":
			if (CheckAttribute(pchar, "quest_S3_target_truth") && pchar.quest_S3_target_truth == "guilty")
			{
				dialog.text = "Sur les quais, on reconnait les hommes nets et ceux qui cherchent toujours a embarquer avant l'aube. " + pchar.quest_S3_target_name + " a laisse derriere soi assez de signes pour faire froncer bien des sourcils.";
			}
			else
			{
				dialog.text = "Je vois passer les gens du port toute la journee. " + pchar.quest_S3_target_name + " n'a pas la demarche d'un coupe-jarret traque ni les habitudes d'un vrai malfaiteur. Je dirais qu'on charge cette personne un peu vite.";
			}
			link.l1 = "C'est note.";
			link.l1.go = "S3_shipyard_done";
		break;

		case "S3_shipyard_done":
			pchar.quest_S3_informant_shipyard = true;
			Log_SetStringToLog("S3 informant answered");
			DialogExit();
		break;

		case "S3_shipyard_repeat":
			dialog.text = "Je vous ai deja livre mon sentiment. Les quais n'ont rien ajoute depuis.";
			link.l1 = "Je comprends.";
			link.l1.go = "exit";
		break;
	}
}
