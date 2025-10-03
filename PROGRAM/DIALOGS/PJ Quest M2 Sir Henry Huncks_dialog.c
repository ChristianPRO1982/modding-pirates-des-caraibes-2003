//nclude "DIALOGS\PJ Quest M2 Sir Henry Huncks_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	int RandQuestSum;
	int n;
	string category;
	string value;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	



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
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Continue_01";
		break;

		case "Continue_01":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "Start";
		break;

		case "Start":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[4] + quest_M2_clues_list_get() + DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[7];
			Link.l2.go = "hair";
			Link.l3 = DLG_TEXT[8];
			Link.l3.go = "eyes";
			Link.l4 = DLG_TEXT[9];
			Link.l4.go = "style";
			Link.l5 = DLG_TEXT[10];
			Link.l5.go = "accessory";
			Link.l6 = DLG_TEXT[11];
			Link.l6.go = "passion";
			Link.l7 = DLG_TEXT[12];
			Link.l7.go = "skill";
			Link.l8 = DLG_TEXT[13];
			Link.l8.go = "mark";
			Link.l9 = DLG_TEXT[14];
			Link.l9.go = "language";
			Link.l10 = DLG_TEXT[15];
			Link.l10.go = "home_port";
			Link.l11 = DLG_TEXT[16];
			Link.l11.go = "man";
			Link.l12 = DLG_TEXT[17];
			Link.l12.go = "woman";
		break;

		case "hair":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19]; // black
			Link.l1.go = "hair_black";
			Link.l2 = DLG_TEXT[20]; // red
			Link.l2.go = "hair_red";
			Link.l3 = DLG_TEXT[21]; // blond
			Link.l3.go = "hair_blond";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
			Link.l5 = DLG_TEXT[66]; // forget it
			Link.l5.go = "hair_forget";
		break;

		case "hair_black":
			quest_M2_clues_list_update("hair", "noir");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "hair_red":
			quest_M2_clues_list_update("hair", "roux");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "hair_blond":
			quest_M2_clues_list_update("hair", "blond");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "hair_forget":
			quest_M2_clues_list_update("hair", "");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "eyes":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23]; // brown
			Link.l1.go = "eyes_brown";
			Link.l2 = DLG_TEXT[24]; // green
			Link.l2.go = "eyes_green";
			Link.l3 = DLG_TEXT[25]; // blue
			Link.l3.go = "eyes_blue";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
			Link.l5 = DLG_TEXT[66]; // forget it
			Link.l5.go = "eyes_forget";
		break;

		case "eyes_brown":
			quest_M2_clues_list_update("eyes", "marron");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "eyes_green":
			quest_M2_clues_list_update("eyes", "vert");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "eyes_blue":
			quest_M2_clues_list_update("eyes", "bleu");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "eyes_forget":
			quest_M2_clues_list_update("eyes", "");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "style":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27]; // simple
			Link.l1.go = "style_simple";
			Link.l2 = DLG_TEXT[28]; // elegant
			Link.l2.go = "style_elegant";
			Link.l3 = DLG_TEXT[29]; // flashy
			Link.l3.go = "style_flashy";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
			Link.l5 = DLG_TEXT[66]; // forget it
			Link.l5.go = "style_forget";
		break;

		case "style_simple":
			quest_M2_clues_list_update("style", "simple");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "style_elegant":
			quest_M2_clues_list_update("style", "élégant");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "style_flashy":
			quest_M2_clues_list_update("style", "haillons");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "style_forget":
			quest_M2_clues_list_update("style", "");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "accessory":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31]; // compass
			Link.l1.go = "accessory_compass";
			Link.l2 = DLG_TEXT[32]; // ring
			Link.l2.go = "accessory_ring";
			Link.l3 = DLG_TEXT[33]; // spyglass
			Link.l3.go = "accessory_spyglass";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
			Link.l5 = DLG_TEXT[66]; // forget it
			Link.l5.go = "accessory_forget";
		break;

		case "accessory_compass":
			quest_M2_clues_list_update("accessory", "compas marin");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "accessory_ring":
			quest_M2_clues_list_update("accessory", "bague");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "accessory_spyglass":
			quest_M2_clues_list_update("accessory", "longue-vue");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "accessory_forget":
			quest_M2_clues_list_update("accessory", "");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "passion":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[34];
			Link.l1 = DLG_TEXT[35]; // antiques
			Link.l1.go = "passion_antiques";
			Link.l2 = DLG_TEXT[36]; // poetry
			Link.l2.go = "passion_poetry";
			Link.l3 = DLG_TEXT[37]; // seagulls
			Link.l3.go = "passion_seagulls";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
			Link.l5 = DLG_TEXT[66]; // forget it
			Link.l5.go = "passion_forget";
		break;

		case "passion_antiques":
			quest_M2_clues_list_update("passion", "antiquités");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "passion_poetry":
			quest_M2_clues_list_update("passion", "poésie");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "passion_seagulls":
			quest_M2_clues_list_update("passion", "animaux");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "passion_forget":
			quest_M2_clues_list_update("passion", "");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "skill":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[38];
			Link.l1 = DLG_TEXT[39]; // climbing
			Link.l1.go = "skill_climbing";
			Link.l2 = DLG_TEXT[40]; // talking
			Link.l2.go = "skill_talking";
			Link.l3 = DLG_TEXT[41]; // disguise
			Link.l3.go = "skill_disguise";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
			Link.l5 = DLG_TEXT[66]; // forget it
			Link.l5.go = "skill_forget";
		break;

		case "skill_climbing":
			quest_M2_clues_list_update("skill", "escalade");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "skill_talking":
			quest_M2_clues_list_update("skill", "discours");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "skill_disguise":
			quest_M2_clues_list_update("skill", "déguisement");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "skill_forget":
			quest_M2_clues_list_update("skill", "");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "mark":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[43]; // scar
			Link.l1.go = "mark_scar";
			Link.l2 = DLG_TEXT[44]; // tattoo
			Link.l2.go = "mark_tattoo";
			Link.l3 = DLG_TEXT[45]; // limp
			Link.l3.go = "mark_limp";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
			Link.l5 = DLG_TEXT[66]; // forget it
			Link.l5.go = "mark_forget";
		break;

		case "mark_scar":
			quest_M2_clues_list_update("mark", "cicatrice");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "mark_tattoo":
			quest_M2_clues_list_update("mark", "tatouage");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "mark_limp":
			quest_M2_clues_list_update("mark", "Boite légèrement");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "mark_forget":
			quest_M2_clues_list_update("mark", "");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "language":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47]; // spanish
			Link.l1.go = "language_spanish";
			Link.l2 = DLG_TEXT[48]; // french
			Link.l2.go = "language_french";
			Link.l3 = DLG_TEXT[49]; // english
			Link.l3.go = "language_english";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
			Link.l5 = DLG_TEXT[66]; // forget it
			Link.l5.go = "language_forget";
		break;

		case "language_spanish":
			quest_M2_clues_list_update("language", "espagnol");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "language_french":
			quest_M2_clues_list_update("language", "français");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "language_english":
			quest_M2_clues_list_update("language", "anglais");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "language_forget":
			quest_M2_clues_list_update("language", "");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "home_port":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[50];
			Link.l1 = DLG_TEXT[51]; // seville
			Link.l1.go = "port_seville";
			Link.l2 = DLG_TEXT[52]; // la rochelle
			Link.l2.go = "port_la_rochelle";
			Link.l3 = DLG_TEXT[53]; // plymouth
			Link.l3.go = "port_plymouth";
			Link.l4 = DLG_TEXT[54]; // unsure
			Link.l4.go = "exit";
			Link.l5 = DLG_TEXT[66]; // forget it
			Link.l5.go = "home_port_forget";
		break;

		case "port_seville":
			quest_M2_clues_list_update("home_port", "Séville");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "port_la_rochelle":
			quest_M2_clues_list_update("home_port", "La Rochelle");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "port_plymouth":
			quest_M2_clues_list_update("home_port", "Plymouth");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "home_port_forget":
			quest_M2_clues_list_update("home_port", "");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[65];
			Link.l1.go = "Continue_02";
		break;

		case "man":
			quest_M2_clues_list_update("gender", "homme");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[55];
			Link.l1 = DLG_TEXT[56];
			Link.l1.go = "Continue_02";
		break;

		case "woman":
			quest_M2_clues_list_update("gender", "femme");
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[57];
			Link.l1 = DLG_TEXT[58];
			Link.l1.go = "Continue_02";
		break;

		case "Continue_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[59] + quest_M2_robbers_list();
			Link.l1 = DLG_TEXT[60];
			Link.l1.go = "OneSuspect";
			switch (makeint(PChar.quest.quest_M2.clue.nb_suspects))
			{
				case 0:
					Link.l1.go = "NoSuspect";
				break;
				case 1:
					Link.l1.go = "OneSuspect";
				break;
				default:
					Link.l1.go = "exit";
				break;
			}
		break;

		case "NoSuspect":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[61];
			Link.l1 = DLG_TEXT[62];
			Link.l1.go = "exit";
		break;

		case "OneSuspect":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[63];
			Link.l1 = DLG_TEXT[64];
			Link.l1.go = "exit";
			quest_M2_create_warrant();
		break;



		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}