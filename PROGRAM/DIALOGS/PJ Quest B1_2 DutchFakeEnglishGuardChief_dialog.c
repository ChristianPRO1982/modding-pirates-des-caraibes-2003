//nclude "DIALOGS\PJ Quest B1_2 DutchFakeEnglishGuardChief_dialog.h"

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
			Dialog.CurrentNode = "B1_2A_theft";
		break;

		case "B1_2A_theft":
			d.Text = "Pas un geste. Tu portes une lettre de cachet anglaise et un cadeau diplomatique de Conceicao pour Silehard. Donne-les.";
			Link.l1 = "Et depuis quand les soldats anglais savent-ils si bien ce que je transporte ?";
			Link.l1.go = "B1_2A_theft_2";
			Diag.TempNode = "B1_2A_theft";
		break;

		case "B1_2A_theft_2":
			d.Text = "Tu comptes pour du lard et des haricots dans cette affaire. Ne force pas ma patience, capitaine.";
			Link.l1 = "Vous avez une maniere bien etrange de parler pour un Anglais.";
			Link.l1.go = "B1_2A_theft_3";
		break;

		case "B1_2A_theft_3":
			d.Text = "Porter de l'eau a la mer serait moins inutile que de te laisser jouer le heros ici. Le singe est sorti de la manche. La guerre marche deja.";
			Link.l1 = "Tres bien... prenez votre lettre et votre coffre.";
			Link.l1.go = "B1_2A_theft_complete";
		break;

		case "B1_2A_theft_complete":
			QuestComplete_B1_2A("PJ_B1_2A_THEFT_COMPLETE");
			d.Text = "Bonne decision. Reprends ta route, oublie cette conversation, et remercie-nous de te laisser vivre.";
			Link.l1 = "Je n'oublierai rien.";
			Link.l1.go = "exit";
		break;

		case "exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
