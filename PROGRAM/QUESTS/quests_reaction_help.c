// PJ HELP

void HELP_ProcessLocationEnter()
{
	ref pchar = GetMainCharacter();
	string homelocation;
	homelocation = pchar.location;
	
	switch (pchar.location)
	{
		case "Conceicao_port": PlaceCharacter(characterFromID("PJ HELP Malcolm Hatcher"), "goto", homelocation); break;
		case "Falaise_de_fleur_port_01": PlaceCharacter(characterFromID("PJ HELP Malcolm Hatcher"), "goto", homelocation); break;
		case "Redmond_port": PlaceCharacter(characterFromID("PJ HELP Malcolm Hatcher"), "goto", homelocation); break;
		case "Muelle_port": PlaceCharacter(characterFromID("PJ HELP Malcolm Hatcher"), "goto", homelocation); break;
		case "Douwesen_port": PlaceCharacter(characterFromID("PJ HELP Malcolm Hatcher"), "goto", homelocation); break;
		case "Greenford_port": PlaceCharacter(characterFromID("PJ HELP Malcolm Hatcher"), "goto", homelocation); break;
		case "Oxbay_port": PlaceCharacter(characterFromID("PJ HELP Malcolm Hatcher"), "goto", homelocation); break;
		case "QC_port": PlaceCharacter(characterFromID("PJ HELP Malcolm Hatcher"), "goto", homelocation); break;
	}
}