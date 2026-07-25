//nclude "DIALOGS\PJ Quest B1_2 FrenchSpy_dialog.h"

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
			if (B12B_GetStatus() == B12B_STATUS_FRENCH_SPY)
			{
				Dialog.CurrentNode = "B1_2B_clean";
			}
			else
			{
				Dialog.CurrentNode = "B1_2B_ragged";
			}
		break;

		case "B1_2B_ragged":
			d.Text = "Les haillons me servent mieux que les salons, capitaine. Si vous cherchez des certitudes, allez parler a ceux qui portent une couronne.";
			Link.l1 = "Je vois. Vous preferez garder vos verites pour plus tard.";
			Link.l1.go = "exit";
			Diag.TempNode = "B1_2B_ragged";
		break;

		case "B1_2B_clean":
			d.Text = "Nous nous sommes deja croises, mais la misere est un meilleur deguisement qu'un uniforme bien brosse.";
			Link.l1 = "Je vous reconnais a peine sans vos haillons.";
			Link.l1.go = "B1_2B_clean_2";
			Diag.TempNode = "B1_2B_clean_repeat";
		break;

		case "B1_2B_clean_2":
			d.Text = "Je n'ai pas pu les suivre jusqu'au bout. Les Hollandais ont pris la mer vers une ile separee, du cote de Isla Muelle.";
			Link.l1 = "Et vous ignorez leur plage exacte ?";
			Link.l1.go = "B1_2B_clean_3";
		break;

		case "B1_2B_clean_3":
			QuestComplete_B1_2B("PJ_B1_2B_FRENCH_SPY");
			d.Text = "J'ignore la plage. J'ignore leur dernier abri. Mais j'ai entendu parler d'un rite, et d'une secte dangereuse. Shango.";
			Link.l1 = "C'est peu, mais assez pour relancer la piste.";
			Link.l1.go = "exit";
		break;

		case "B1_2B_clean_repeat":
			d.Text = "Je vous ai deja livre l'essentiel : Isla Muelle, une ile separee, et un rite de Shango. Pour le reste, retournez voir Silehard.";
			Link.l1 = "Je m'en souviendrai.";
			Link.l1.go = "exit";
		break;

		case "exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
