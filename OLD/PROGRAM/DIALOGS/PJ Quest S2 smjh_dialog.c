//nclude "DIALOGS\PJ Quest S2 smjh_dialog.h"
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
	
	// smjh = Suivez-Moi-Jeune-Homme (c'est un mot de la langue française ! )
	string amantFirstName, amantLastName, smjhFirstName, smjhLastName, smjhJewelry, smjhJewelryID;
	switch (pchar.location) {
		case "Redmond_town_03": amantFirstName = "Llewellyn"; amantLastName = "Brooker"; smjhFirstName = "Magdalen"; smjhLastName = "Spooner"; smjhJewelry = "une bague en or sertie d'emeraudes."; smjhJewelryID = "jewelry7"; break;
		case "Falaise_De_Fleur_location_03": amantFirstName = "Fabrisse"; amantLastName = "De Lucien"; smjhFirstName = "Donatienne"; smjhLastName = "de La Fayette"; smjhJewelry = "une bague en or sertie de saphirs."; smjhJewelryID = "jewelry10"; break;
		case "Conceicao_town": amantFirstName = "Florencio"; amantLastName = "Baiano"; smjhFirstName = "Violamte"; smjhLastName = "Pinto"; smjhJewelry = "une broche en or."; smjhJewelryID = "jewelry14"; break;
		case "Muelle_town_04": amantFirstName = "Cricorium"; amantLastName = "Taffarel"; smjhFirstName = "Alejandrina"; smjhLastName = "Acosto"; smjhJewelry = "une broche en argent de son pays natal."; smjhJewelryID = "jewelry13"; break;
		case "Douwesen_town": amantFirstName = "Ghijsbrecht"; amantLastName = "Van Der Hagen"; smjhFirstName = "Tjaatje"; smjhLastName = "Meilink-Roelofsz"; smjhJewelry = "bague en argent sertie de saphirs."; smjhJewelryID = "jewelry6"; break;
		case "Greenford_town": amantFirstName = "Rawlin"; amantLastName = "Feaver"; smjhFirstName = "Astrid"; smjhLastName = "Weather"; smjhJewelry = "un pendetif en emeraude."; smjhJewelryID = "jewelry15"; break;
		case "Oxbay_town": amantFirstName = "Rys"; amantLastName = "Scorer"; smjhFirstName = "Valeria"; smjhLastName = "Pride"; smjhJewelry = "un collier en pierres precieuses."; smjhJewelryID = "jewelry16"; break;
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
			d.Text = DLG_TEXT[4] + smjhFirstName + " " + smjhLastName;
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Start";
		break;

		case "Start":
			Diag.TempNode = "Start";
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7] + amantFirstName + " " + amantLastName + ".";
			Link.l1.go = "Continue_02";
		break;

		case "Continue_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[8];
			if (CheckCharacterItem(Pchar,smjhJewelryID)) {
				Link.l1 = DLG_TEXT[12];
				Link.l1.go = "Continue_04";
			} else {
				Link.l1 = DLG_TEXT[9];
				Link.l1.go = "Continue_03";
			}
		break;

		case "Continue_03":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "exit";
		break;

		case "Continue_04":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[13] + smjhJewelry + DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "congratulation";
		break;

		case "congratulation":
			Diag.TempNode = "thanks";
			TakeItemFromCharacter(Pchar, smjhJewelryID);
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[16] + PChar.lastname + ".";
			Link.l1 = DLG_TEXT[17] + smjhLastName + ".";
			Link.l1.go = "exit";
			AddDialogExitQuest("quest_S2_closed_1");
		break;

		case "thanks":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[18];
			Link.l1.go = "Continue_05";
		break;
		
		case "Continue_05":
			DialogExit();
		break;



		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}