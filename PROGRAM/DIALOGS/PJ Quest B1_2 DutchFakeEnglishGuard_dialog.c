//nclude "DIALOGS\PJ Quest B1_2 DutchFakeEnglishGuard_dialog.h"

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
			if (B12B_IsStarted() && B12B_GetStatus() == B12B_STATUS_RITUAL_CAVE)
			{
				Dialog.CurrentNode = "B1_2B_priest";
			}
			else
			{
				Dialog.CurrentNode = "B1_2A_guard";
			}
		break;

		case "B1_2A_guard":
			d.Text = "Ordres du roi. Ne restez pas dans nos jambes, capitaine.";
			Link.l1 = "Vous jouez bien la comedie pour des soldats anglais.";
			Link.l1.go = "exit";
			Diag.TempNode = "B1_2A_guard";
		break;

		case "B1_2B_priest":
			d.Text = "Shango ne vous doit ni explication ni merci. Ecartez-vous ou mourez.";
			Link.l1 = "Je vois que l'uniforme vous allait mieux.";
			Link.l1.go = "exit";
			Diag.TempNode = "B1_2B_priest";
		break;

		case "exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
