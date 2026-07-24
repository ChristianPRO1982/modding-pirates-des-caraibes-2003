//nclude "DIALOGS\PJ Quest B1_1 PortugueseGuard_Conceicao_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	aref Link, Diag;

	PChar = GetMainCharacter();

	DeleteAttribute(&Dialog, "Links");

	makeref(NPChar, CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		case "First time":
			Diag.CurrentNode = "B1_1_conceicao_guard";
			Dialog.CurrentNode = "B1_1_conceicao_guard";
		break;

		case "B1_1_conceicao_guard":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			Diag.TempNode = "B1_1_conceicao_guard";
			if (CheckAttribute(PChar, "quest_b1_1_conceicao_state") && PChar.quest_b1_1_conceicao_state == "wait")
			{
				d.Text = DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "exit";
			}
			else
			{
				d.Text = DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3];
				Link.l1.go = "B1_1_conceicao_guard_2";
			}
		break;

		case "B1_1_conceicao_guard_2":
			QuestComplete_B1_1("PJ_B1_1_CONCEICAO_PORTUGAL_FIRST");
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "exit";
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}
