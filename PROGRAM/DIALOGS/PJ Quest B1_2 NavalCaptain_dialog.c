//nclude "DIALOGS\PJ Quest B1_2 NavalCaptain_dialog.h"

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
			Dialog.CurrentNode = "B1_2B_captain";
		break;

		case "B1_2B_captain":
			d.Text = "Vous entrez dans une baie fermee, capitaine. Une fregate, une corvette, et nous deux pour compter les morts.";
			Link.l1 = "Alors je vais simplifier votre comptabilite.";
			Link.l1.go = "B1_2B_captain_2";
			Diag.TempNode = "B1_2B_captain_repeat";
		break;

		case "B1_2B_captain_2":
			QuestComplete_B1_2B("PJ_B1_2B_NAVAL_FIGHT");
			d.Text = "Trop tard pour reculer. La baie de la Cote eloignee vous engloutira avec le reste.";
			Link.l1 = "Essayez donc.";
			Link.l1.go = "exit";
		break;

		case "B1_2B_captain_repeat":
			d.Text = "Pas un pas de plus. La baie reste fermee et le rite reste protege.";
			Link.l1 = "Nous allons voir cela.";
			Link.l1.go = "exit";
		break;

		case "exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
