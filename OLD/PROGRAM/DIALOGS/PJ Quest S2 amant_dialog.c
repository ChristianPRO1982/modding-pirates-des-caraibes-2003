//nclude "DIALOGS\PJ Quest S2 amant_dialog.h"
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
	
	string amantFirstName, amantLastName, smjhFirstName, smjhLastName, smjhJewelry;
	switch (pchar.location) {
		case "Redmond_town_04": amantFirstName = "Llewellyn"; amantLastName = "Brooker"; smjhFirstName = "Magdalen"; smjhLastName = "Spooner"; smjhJewelry = "une bague en or sertie d'emeraudes."; break;
		case "Falaise_De_Fleur_location_02": amantFirstName = "Fabrisse"; amantLastName = "De Lucien"; smjhFirstName = "Donatienne"; smjhLastName = "de La Fayette"; smjhJewelry = "une bague en or sertie de saphirs."; break;
		case "Conceicao_town": amantFirstName = "Florencio"; amantLastName = "Baiano"; smjhFirstName = "Violamte"; smjhLastName = "Pinto"; smjhJewelry = "une broche en or."; break;
		case "Muelle_town_02": amantFirstName = "Cricorium"; amantLastName = "Taffarel"; smjhFirstName = "Alejandrina"; smjhLastName = "Acosto"; smjhJewelry = "une broche en argent de son pays natal."; break;
		case "Douwesen_town": amantFirstName = "Ghijsbrecht"; amantLastName = "Van Der Hagen"; smjhFirstName = "Tjaatje"; smjhLastName = "Meilink-Roelofsz"; smjhJewelry = "bague en argent sertie de saphirs."; break;
		case "Greenford_town": amantFirstName = "Rawlin"; amantLastName = "Feaver"; smjhFirstName = "Astrid"; smjhLastName = "Weather"; smjhJewelry = "un pendetif en emeraude."; break;
		case "Oxbay_town": amantFirstName = "Rys"; amantLastName = "Scorer"; smjhFirstName = "Valeria"; smjhLastName = "Pride"; smjhJewelry = "un collier en pierres precieuses."; break;
	}
	// jewelry6 : bague en argent et saphir = 769
	// jewelry7 : bague en or et emeraude = 961
	// jewelry10 : bague en or et saphir = 1538
	// jewelry13 : broche en argent = 1538
	// jewelry14 : broche en or = 769
	// jewelry15 : pendetif emeraude = 769
	// jewelry16 : collier en pierres precieuses = 384



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
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1] + PChar.name + " " + PChar.lastname + DLG_TEXT[2] + PChar.ship.name + DLG_TEXT[3];
			Link.l1.go = "Continue_01";
		break;

		case "Continue_01":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[4] + amantFirstName + " " + amantLastName + DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "Start";
		break;

		case "Start":
			Diag.TempNode = "Start";
			dialog.snd = "Voice\ARSI\ARSI001";
			if (pchar.reputation > 64) {
				d.Text = DLG_TEXT[9];
				Link.l1 = DLG_TEXT[10];
				Link.l1.go = "Continue_02";
			} else {
				d.Text = DLG_TEXT[7];
				Link.l1 = DLG_TEXT[8];
				Link.l1.go = "exit";
			}
		break;

		case "Continue_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[11] + smjhFirstName + " " + smjhLastName + DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Continue_03";
		break;

		case "Continue_03":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "Continue_04";
		break;

		case "Continue_04":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "agreeded";
			Link.l2 = DLG_TEXT[18];
			Link.l2.go = "exit";
		break;

		case "agreeded":
			Diag.TempNode = "Waiting";
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[19] + pchar.lastname + DLG_TEXT[20] + smjhFirstName + DLG_TEXT[21] + smjhJewelry;
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "Continue_05";
		break;
		
		case "Continue_05":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("quest_S2_agreeded");
		break;

		case "Waiting":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[23];
			Link.l1.go = "Continue_06";
		break;
		
		case "Continue_06":
			DialogExit();
		break;



		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}