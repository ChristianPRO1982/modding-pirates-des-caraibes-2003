//nclude "DIALOGS\PJ Quest S2 Fabiola Rochefort_dialog.h"
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
			Link.l1.go = "Continue_02";
		break;

		case "Continue_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Continue_03";
		break;

		case "Continue_03":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "Continue_04";
		break;

		case "Continue_04":
			for(n = 1; n <= rand(makeint(pchar.skill.Sneak)) + makeint(pchar.rank); n++) {GiveItem2Character(Pchar, "jewelry6");}
			for(n = 1; n <= rand(makeint(pchar.skill.Sneak)) + makeint(pchar.rank); n++) {GiveItem2Character(Pchar, "jewelry7");}
			for(n = 1; n <= rand(makeint(pchar.skill.Sneak)) + makeint(pchar.rank); n++) {GiveItem2Character(Pchar, "jewelry10");}
			for(n = 1; n <= rand(makeint(pchar.skill.Sneak)) + makeint(pchar.rank); n++) {GiveItem2Character(Pchar, "jewelry13");}
			for(n = 1; n <= rand(makeint(pchar.skill.Sneak)) + makeint(pchar.rank); n++) {GiveItem2Character(Pchar, "jewelry14");}
			for(n = 1; n <= rand(makeint(pchar.skill.Sneak)) + makeint(pchar.rank); n++) {GiveItem2Character(Pchar, "jewelry15");}
			for(n = 1; n <= rand(makeint(pchar.skill.Sneak)) + makeint(pchar.rank); n++) {GiveItem2Character(Pchar, "jewelry16");}
			AddDialogExitQuest("quest_S2_lastQuest_closed");
			DialogExit();
		break;
	}
}