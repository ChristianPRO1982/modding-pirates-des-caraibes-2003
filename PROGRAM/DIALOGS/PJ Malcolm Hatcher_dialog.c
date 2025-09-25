//nclude "DIALOGS\PJ Malcolm Hatcher_dialog.h"
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

			Diag.TempNode = "First time";

			n = rand(19);
			
			dialog.snd1 = "Voice\ARSI\ARSI001";
			dialog.snd2 = "Voice\ARSI\ARSI001";
			dialog.snd3 = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[(0 + 2*n)];
			Link.l1 = DLG_TEXT[(1 + 2*n)];
			Link.l1.go = "Continue_01";
		break;

		case "Continue_01":
			n = rand(4);
		
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[(40 + 4*n)];
			Link.l1 = DLG_TEXT[(41 + 4*n)];
			Link.l1.go = "advice";
			Link.l2 = DLG_TEXT[(42 + 4*n)];
			Link.l2.go = "memory_01";
			Link.l3 = DLG_TEXT[(43 + 4*n)];
			Link.l3.go = "exit";
		break;

		case "advice":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[180];
			Link.l1 = DLG_TEXT[181];
			Link.l1.go = "advice_01";
			Link.l2 = DLG_TEXT[182];
			Link.l2.go = "advice_02";
			Link.l3 = DLG_TEXT[187];
			Link.l3.go = "exit";
			Link.l4 = DLG_TEXT[188];
			Link.l4.go = "exit";
		break;

		case "advice_01":
			n = rand(6);

			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[197] + DLG_TEXT[(198 + n)];
			Link.l1 = DLG_TEXT[205];
			Link.l1.go = "continue_01";
		break;

		case "advice_02":
			n = rand(6);

			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[206] + DLG_TEXT[(207 + n)];
			Link.l1 = DLG_TEXT[214];
			Link.l1.go = "continue_01";
		break;

		case "memory_01":
			Diag.conte_de_malcolm = rand(19);
		
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[(60 + 6*Diag.conte_de_malcolm)];
			Link.l1 = DLG_TEXT[(61 + 6*Diag.conte_de_malcolm)];
			Link.l1.go = "memory_02";
		break;

		case "memory_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[(62 + 6*Diag.conte_de_malcolm)];
			Link.l1 = DLG_TEXT[(63 + 6*Diag.conte_de_malcolm)];
			Link.l1.go = "memory_03";
		break;

		case "memory_03":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[(64 + 6*Diag.conte_de_malcolm)];
			Link.l1 = DLG_TEXT[(65 + 6*Diag.conte_de_malcolm)];
			Link.l1.go = "Continue_01";
		break;
		// pchar.quest_S1_allQuestsCompleted
		// pchar.quest.quest_S2_lastQuest = "completed



		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}