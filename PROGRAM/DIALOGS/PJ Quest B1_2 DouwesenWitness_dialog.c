//nclude "DIALOGS\PJ Quest B1_2 DouwesenWitness_dialog.h"

string B12W_GetWitnessEvent(ref NPChar)
{
	switch (NPChar.id)
	{
		case "PJ_B1_2_DouwesenWitness1":
			return "PJ_B1_2B_WITNESS1";
		break;
		case "PJ_B1_2_DouwesenWitness2":
			return "PJ_B1_2B_WITNESS2";
		break;
	}
	return "PJ_B1_2B_WITNESS3";
}

string B12W_GetOpening(ref NPChar)
{
	switch (NPChar.id)
	{
		case "PJ_B1_2_DouwesenWitness1":
			return "Bah, tout ca, c'est participer pour du lard et des haricots.";
		break;
		case "PJ_B1_2_DouwesenWitness2":
			return "Parler encore de cette histoire ? Ce serait porter de l'eau a la mer.";
		break;
	}
	return "Depuis hier, tout le monde jase. Le singe est sorti de la manche, comme on dit chez nous.";
}

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
			Dialog.CurrentNode = "B1_2B_witness_1";
		break;

		case "B1_2B_witness_1":
			d.Text = B12W_GetOpening(NPChar);
			Link.l1 = "Qu'est-ce que cela veut dire, exactement ?";
			Link.l1.go = "B1_2B_witness_2";
			Link.l2 = "J'ai surtout besoin d'un renseignement sur des soldats anglais.";
			Link.l2.go = "B1_2B_witness_3";
			Diag.TempNode = "B1_2B_witness_repeat";
		break;

		case "B1_2B_witness_2":
			d.Text = "Que certains hommes se fatiguent pour rien. Ce n'est qu'une facon de parler, capitaine.";
			Link.l1 = "Justement. J'ai croise des soldats anglais qui parlaient d'une facon etrange.";
			Link.l1.go = "B1_2B_witness_3";
		break;

		case "B1_2B_witness_3":
			d.Text = "Des soldats anglais qui sonnaient hollandais ? Oui. Presses, nerveux, pas du coin.";
			Link.l1 = "Tu as remarque autre chose ?";
			Link.l1.go = "B1_2B_witness_4";
		break;

		case "B1_2B_witness_4":
			QuestComplete_B1_2B(B12W_GetWitnessEvent(NPChar));
			d.Text = "Un Francais mal habille trainait pres d'eux et posait les memes questions que toi. Va voir du cote de Falaise de Fleur si tu tiens a remonter cette piste.";
			Link.l1 = "Cela me suffit pour l'instant.";
			Link.l1.go = "exit";
		break;

		case "B1_2B_witness_repeat":
			d.Text = "Je t'ai deja dit ce que je savais : ces faux Anglais sentaient la Hollande, et un Francais en haillons tournait autour d'eux.";
			Link.l1 = "Tres bien.";
			Link.l1.go = "exit";
		break;

		case "exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
