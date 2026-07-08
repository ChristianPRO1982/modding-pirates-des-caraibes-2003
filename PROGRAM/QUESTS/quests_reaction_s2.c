int S2_GetActiveVariant()
{
	ref pchar = GetMainCharacter();
	return makeint(pchar.quest_S2_started);
}

string S2_GetVariantCityKey(int variant)
{
	switch (variant)
	{
		case 1: return "Redmond"; break;
		case 2: return "FalaiseDeFleur"; break;
		case 3: return "Conceicao"; break;
		case 4: return "IslaMuelle"; break;
		case 5: return "Douwesen"; break;
		case 6: return "Greenford"; break;
		case 7: return "Oxbay"; break;
	}
	return "";
}

int S2_GetVariantFromLoverLocation(string locationId)
{
	switch (locationId)
	{
		case "Redmond_town_04": return 1; break;
		case "Falaise_De_Fleur_location_02": return 2; break;
		case "Conceicao_town": return 3; break;
		case "Muelle_town_02": return 4; break;
		case "Douwesen_town": return 5; break;
		case "Greenford_town": return 6; break;
		case "Oxbay_town": return 7; break;
	}
	return 0;
}

int S2_GetVariantFromLadyLocation(string locationId)
{
	switch (locationId)
	{
		case "Redmond_town_03": return 1; break;
		case "Falaise_De_Fleur_location_03": return 2; break;
		case "Conceicao_town": return 3; break;
		case "Muelle_town_04": return 4; break;
		case "Douwesen_town": return 5; break;
		case "Greenford_town": return 6; break;
		case "Oxbay_town": return 7; break;
	}
	return 0;
}

string S2_GetLoverLocation(int variant)
{
	switch (variant)
	{
		case 1: return "Redmond_town_04"; break;
		case 2: return "Falaise_De_Fleur_location_02"; break;
		case 3: return "Conceicao_town"; break;
		case 4: return "Muelle_town_02"; break;
		case 5: return "Douwesen_town"; break;
		case 6: return "Greenford_town"; break;
		case 7: return "Oxbay_town"; break;
	}
	return "";
}

string S2_GetLadyLocation(int variant)
{
	switch (variant)
	{
		case 1: return "Redmond_town_03"; break;
		case 2: return "Falaise_De_Fleur_location_03"; break;
		case 3: return "Conceicao_town"; break;
		case 4: return "Muelle_town_04"; break;
		case 5: return "Douwesen_town"; break;
		case 6: return "Greenford_town"; break;
		case 7: return "Oxbay_town"; break;
	}
	return "";
}

string S2_GetLoverId(int variant)
{
	switch (variant)
	{
		case 1: return "Llewellyn Brooker"; break;
		case 2: return "Fabrisse De Lucien"; break;
		case 3: return "Florencio Baiano"; break;
		case 4: return "Cricorium Taffarel"; break;
		case 5: return "Ghijsbrecht Van Der Hagen"; break;
		case 6: return "Rawlin Feaver"; break;
		case 7: return "Rys Scorer"; break;
	}
	return "";
}

string S2_GetLadyId(int variant)
{
	switch (variant)
	{
		case 1: return "Magdalen Spooner"; break;
		case 2: return "Donatienne de La Fayette"; break;
		case 3: return "Violamte Pinto"; break;
		case 4: return "Alejandrina Acosto"; break;
		case 5: return "Tjaatje Meilink-Roelofsz"; break;
		case 6: return "Astrid Weather"; break;
		case 7: return "Valeria Pride"; break;
	}
	return "";
}

string S2_GetFinalNpcId()
{
	return "Fabiola Rochefort";
}

string S2_GetJewelryId(int variant)
{
	switch (variant)
	{
		case 1: return "jewelry7"; break;
		case 2: return "jewelry10"; break;
		case 3: return "jewelry14"; break;
		case 4: return "jewelry13"; break;
		case 5: return "jewelry6"; break;
		case 6: return "jewelry15"; break;
		case 7: return "jewelry16"; break;
	}
	return "";
}

string S2_GetJewelryText(int variant)
{
	switch (variant)
	{
		case 1: return "une bague en or sertie d'emeraudes."; break;
		case 2: return "une bague en or sertie de saphirs."; break;
		case 3: return "une broche en or."; break;
		case 4: return "une broche en argent de son pays natal."; break;
		case 5: return "bague en argent sertie de saphirs."; break;
		case 6: return "un pendetif en emeraude."; break;
		case 7: return "un collier en pierres precieuses."; break;
	}
	return "";
}

int S2_GetQuestCityRecord(int variant)
{
	switch (variant)
	{
		case 1: return 1; break;
		case 2: return 2; break;
		case 3: return 3; break;
		case 4: return 4; break;
		case 5: return 5; break;
		case 6: return 6; break;
		case 7: return 7; break;
	}
	return 0;
}

int S2_GetQuestContextRecord(int variant)
{
	switch (variant)
	{
		case 1: return 8; break;
		case 2: return 9; break;
		case 3: return 10; break;
		case 4: return 11; break;
		case 5: return 12; break;
		case 6: return 13; break;
		case 7: return 14; break;
	}
	return 0;
}

int S2_GetQuestSuccessRecord(int variant)
{
	return 15;
}

int S2_GetQuestFailureRecord()
{
	return 16;
}

int S2_GetQuestFinalRecord()
{
	return 17;
}

int S2_GetQuestTimeoutDays()
{
	return 7;
}

bool S2_IsVariantDone(int variant)
{
	ref pchar = GetMainCharacter();

	switch (variant)
	{
		case 1: return pchar.quest_S2_Redmond_done == true; break;
		case 2: return pchar.quest_S2_FalaiseDeFleur_done == true; break;
		case 3: return pchar.quest_S2_Conceicao_done == true; break;
		case 4: return pchar.quest_S2_IslaMuelle_done == true; break;
		case 5: return pchar.quest_S2_Douwesen_done == true; break;
		case 6: return pchar.quest_S2_Greenford_done == true; break;
		case 7: return pchar.quest_S2_Oxbay_done == true; break;
	}

	return false;
}

void S2_HideAllNpcs()
{
	int variant;
	string loverId;
	string ladyId;

	for (variant = 1; variant <= 7; variant++)
	{
		loverId = S2_GetLoverId(variant);
		ladyId = S2_GetLadyId(variant);
		if (loverId != "")
		{
			PlaceCharacter(characterFromID(loverId), "goto", "none");
		}
		if (ladyId != "")
		{
			PlaceCharacter(characterFromID(ladyId), "goto", "none");
		}
	}

	PlaceCharacter(characterFromID(S2_GetFinalNpcId()), "goto", "none");
}

// jewelry6 : bague en argent et saphir = 769
// jewelry7 : bague en or et emeraude = 961
// jewelry10 : bague en or et saphir = 1538
// jewelry13 : broche en argent = 1538
// jewelry14 : broche en or = 769
// jewelry15 : pendetif emeraude = 769
// jewelry16 : collier en pierres precieuses = 384

void S2_ProcessLocationEnter()
{
	ref pchar = GetMainCharacter();
	string homelocation;
	int variant;
	string loverId;

	homelocation = pchar.location;
	S2_HideAllNpcs();

	if (S2_GetActiveVariant() != 0)
	{
		return;
	}

	variant = S2_GetVariantFromLoverLocation(homelocation);
	if (variant == 0)
	{
		return;
	}

	if (S2_IsVariantDone(variant))
	{
		return;
	}

	if (rand(7) != 0)
	{
		return;
	}

	loverId = S2_GetLoverId(variant);
	if (loverId == "")
	{
		return;
	}

	PlaceCharacter(characterFromID(loverId), "goto", homelocation);
}

bool QuestComplete_S2(string sQuestName)
{
	return false;
}
