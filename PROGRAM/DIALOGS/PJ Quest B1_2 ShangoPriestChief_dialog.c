//nclude "DIALOGS\PJ Quest B1_2 ShangoPriestChief_dialog.h"

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
			Dialog.CurrentNode = "B1_2B_priest_chief";
		break;

		case "B1_2B_priest_chief":
			d.Text = "Tu arrives tard, capitaine. Les soldats que tu as vus sont morts depuis longtemps. Il ne reste ici que des serviteurs de Shango.";
			Link.l1 = "Serviteurs ou voleurs, cela revient au meme tant que vous gardez ce qui ne vous appartient pas.";
			Link.l1.go = "B1_2B_priest_chief_2";
			Diag.TempNode = "B1_2B_priest_chief";
		break;

		case "B1_2B_priest_chief_2":
			d.Text = "Nous avons pris ce qu'il fallait prendre. Les objets ne te seront pas rendus, pas plus que leur destination.";
			Link.l1 = "Alors tu mourras sans autre aveu.";
			Link.l1.go = "B1_2B_priest_chief_3";
		break;

		case "B1_2B_priest_chief_3":
			QuestComplete_B1_2B("PJ_B1_2B_PRIEST_FIGHT");
			d.Text = "Le rite nous eleve. Ton acier ne nous rendra pas moins necessaires.";
			Link.l1 = "Nous allons le verifier tout de suite.";
			Link.l1.go = "exit";
		break;

		case "exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
