string DLG_TEXT[24] = {
"Bonjour capitaine. Vous semblez savoir ecouter sans vous moquer des gens simples.",
"Je peux au moins essayer. Qui etes-vous ?",
"Je m'appelle Llewellyn Brooker. Je viens des rues de Redmond, et aujourd'hui elles me paraissent bien etroites.",
"Que vous arrive-t-il donc ?",
"Je suis epris de Magdalen Spooner. Elle vaut mieux que toutes les vitrines de joailliers de Redmond, et c'est bien mon probleme.",
"Je ne suis pas certain de pouvoir me fier a vous. Redmond a la langue trop legere pour confier pareil secret au premier capitaine venu.",
"Je comprends. Je vous laisse donc a votre silence.",
"Je crois que votre reputation parle pour vous mieux que bien des sermons.",
"Alors dites-moi ce qui vous tourmente.",
"Magdalen ne veut pas d'une promesse vide. Elle veut un anneau en or serti d'emeraudes, digne d'une demande faite sans mendier a ma famille.",
"Redmond n'est pourtant pas avare en familles riches. Pourquoi ne pas attendre ?",
"Parce qu'il ne me reste qu'une semaine. Un autre pretendant doit revenir d'Europe, fortune faite, et sa mere le pousse deja vers elle.",
"Vous voulez donc gagner cette course avant son retour.",
"Oui. Si vous m'aidez, je ne pourrai vous offrir que ma gratitude, mais elle sera sincere.",
"Tres bien. Je veux bien porter cette affaire jusqu'au bout.",
"Desole, mais cette comedie mondaine se jouera sans moi.",
"Merci, capitaine ",
". Remettez cet anneau a Magdalen Spooner, et dites-lui que pour une fois Redmond a vu juste sur un homme.",
"Je vais m'en charger.",
"Avez-vous des nouvelles de Magdalen ? Le temps file plus vite que les ragots de Redmond."
};

void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;

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
			Link.l1.go = "Start";
		break;

		case "Start":
			Diag.TempNode = "Start";
			dialog.snd = "Voice\ARSI\ARSI001";
			if (pchar.reputation > 64)
			{
				d.Text = DLG_TEXT[7];
				Link.l1 = DLG_TEXT[8];
				Link.l1.go = "Continue_02";
			}
			else
			{
				d.Text = DLG_TEXT[5];
				Link.l1 = DLG_TEXT[6];
				Link.l1.go = "exit";
			}
		break;

		case "Continue_02":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "Continue_03";
		break;

		case "Continue_03":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "Continue_04";
		break;

		case "Continue_04":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "agreeded";
			Link.l2 = DLG_TEXT[15];
			Link.l2.go = "exit";
		break;

		case "agreeded":
			Diag.TempNode = "Waiting";
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[16] + pchar.lastname + DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "Continue_05";
		break;
		
		case "Continue_05":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("quest_S2_agreeded");
		break;

		case "Waiting":
			dialog.snd = "Voice\ARSI\ARSI001";
			d.Text = DLG_TEXT[19];
			Link.l1.go = "Continue_06";
		break;
		
		case "Continue_06":
			DialogExit();
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}
