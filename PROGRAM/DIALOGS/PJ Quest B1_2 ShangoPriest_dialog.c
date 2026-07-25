//nclude "DIALOGS\PJ Quest B1_2 ShangoPriest_dialog.h"

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
			Dialog.CurrentNode = "B1_2B_priest";
		break;

		case "B1_2B_priest":
			d.Text = "Les soldats que vous avez suivis sont morts. Il ne reste ici que des serviteurs de Shango.";
			Link.l1 = "Alors servez-le bien. Ce sera votre dernier office.";
			Link.l1.go = "exit";
			Diag.TempNode = "B1_2B_priest";
		break;

		case "exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
