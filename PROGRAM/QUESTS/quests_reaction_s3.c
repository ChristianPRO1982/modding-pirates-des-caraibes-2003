// ajout PJ
int S3_GetRunId()
{
	ref pchar = GetMainCharacter();

	if (!CheckAttribute(pchar, "quest_S3_run_id"))
	{
		pchar.quest_S3_run_id = 0;
	}

	return makeint(pchar.quest_S3_run_id);
}

bool S3_IsQuestStartedStatus(string status)
{
	switch (status)
	{
		case "accepted":
			return true;
		break;
		case "investigation":
			return true;
		break;
		case "candidate_target_kill":
			return true;
		break;
		case "candidate_target_release":
			return true;
		break;
		case "target_killed":
			return true;
		break;
		case "target_released":
			return true;
		break;
		case "commanditaire_paid":
			return true;
		break;
		case "commanditaire_duel":
			return true;
		break;
	}

	return false;
}

bool S3_IsQuestActive()
{
	ref pchar = GetMainCharacter();
	string status;

	if (!CheckAttribute(pchar, "quest_S3_status"))
	{
		return false;
	}

	status = pchar.quest_S3_status;
	if (status == "")
	{
		return false;
	}
	if (status == "closed")
	{
		return false;
	}
	if (status == "completed")
	{
		return false;
	}
	if (status == "spawned")
	{
		return false;
	}
	if (status == "offered")
	{
		return false;
	}

	return true;
}

bool S3_IsCommanditaireHour()
{
	int hour;

	hour = makeint(GetHour());
	return hour >= 0 && hour <= 23;
	// return hour >= 16 && hour <= 22;
}

bool S3_IsTargetHour()
{
	int hour;

	hour = makeint(GetHour());
	return hour >= 0 && hour <= 23;
	// return hour >= 8 && hour <= 15;
}

bool S3_IsCommanditaireStatus(string status)
{
	switch (status)
	{
		case "spawned":
			return true;
		break;
		case "offered":
			return true;
		break;
		case "target_killed":
			return true;
		break;
		case "target_released":
			return true;
		break;
	}

	return false;
}

bool S3_IsTargetStatus(string status)
{
	switch (status)
	{
		case "accepted":
			return true;
		break;
		case "investigation":
			return true;
		break;
		case "candidate_target_kill":
			return true;
		break;
		case "candidate_target_release":
			return true;
		break;
	}

	return false;
}

bool S3_HasDeadline()
{
	ref pchar = GetMainCharacter();

	if (!CheckAttribute(pchar, "quest_S3_deadline_day")) return false;
	if (!CheckAttribute(pchar, "quest_S3_deadline_month")) return false;
	if (!CheckAttribute(pchar, "quest_S3_deadline_year")) return false;
	return true;
}

bool S3_IsDeadlineExpired()
{
	ref pchar = GetMainCharacter();
	int deadlineYear;
	int deadlineMonth;
	int deadlineDay;
	string status;

	if (!CheckAttribute(pchar, "quest_S3_status"))
	{
		return false;
	}

	status = pchar.quest_S3_status;
	if (!S3_IsQuestStartedStatus(status))
	{
		return false;
	}

	if (!S3_HasDeadline())
	{
		return false;
	}

	deadlineYear = sti(pchar.quest_S3_deadline_year);
	deadlineMonth = sti(pchar.quest_S3_deadline_month);
	deadlineDay = sti(pchar.quest_S3_deadline_day);

	if (GetDataYear() > deadlineYear) return true;
	if (GetDataYear() < deadlineYear) return false;
	if (GetDataMonth() > deadlineMonth) return true;
	if (GetDataMonth() < deadlineMonth) return false;
	if (GetDataDay() > deadlineDay) return true;

	return false;
}

string S3_GetCommanditaireId()
{
	return "PJ_S3_Commanditaire";
}

string S3_GetTargetId()
{
	return "PJ_S3_Target";
}

string S3_GetWitnessId()
{
	return "PJ_S3_Witness";
}

string S3_GetCityKeyFromLocation(string locationId)
{
	switch (locationId)
	{
		case "Redmond_town_exit_2": return "Redmond"; break;
		case "Falaise_de_fleur_location_02": return "FalaiseDeFleur"; break;
		case "Conceicao_town_exit": return "Conceicao"; break;
		case "Muelle_town_exit": return "IslaMuelle"; break;
		case "Douwesen_town_exit": return "Douwesen"; break;
		case "Greenford_town_exit": return "Greenford"; break;
		case "Oxbay_town_exit": return "Oxbay"; break;
	}

	return "";
}

string S3_GetExteriorLocationFromCity(string cityKey)
{
	switch (cityKey)
	{
		case "Redmond": return "Redmond_town_exit_2"; break;
		case "FalaiseDeFleur": return "Falaise_de_fleur_location_02"; break;
		case "Conceicao": return "Conceicao_town_exit"; break;
		case "IslaMuelle": return "Muelle_town_exit"; break;
		case "Douwesen": return "Douwesen_town_exit"; break;
		case "Greenford": return "Greenford_town_exit"; break;
		case "Oxbay": return "Oxbay_town_exit"; break;
	}

	return "";
}

bool S3_IsEligibleLocation(string locationId)
{
	return S3_GetCityKeyFromLocation(locationId) != "";
}

void S3_HideAllNpcs()
{
	PlaceCharacter(characterFromID(S3_GetCommanditaireId()), "goto", "none");
	PlaceCharacter(characterFromID(S3_GetTargetId()), "goto", "none");
	PlaceCharacter(characterFromID(S3_GetWitnessId()), "goto", "none");
}

void S3_ClearRuntimeQuestEvents()
{
	ref pchar = GetMainCharacter();

	pchar.quest.quest_S3_target_dead.over = "yes";
	pchar.quest.quest_S3_commanditaire_dead.over = "yes";
	pchar.quest.quest_S3_witness_talk.over = "yes";
	pchar.quest.quest_S3_deadline_expired.over = "yes";
}

void S3_ClearInformants()
{
	ref pchar = GetMainCharacter();

	DeleteAttribute(pchar, "quest_S3_informant_priest");
	DeleteAttribute(pchar, "quest_S3_informant_governor");
	DeleteAttribute(pchar, "quest_S3_informant_tavernier");
	DeleteAttribute(pchar, "quest_S3_informant_merchant");
	DeleteAttribute(pchar, "quest_S3_informant_shipyard");
}

void S3_PrepareCommanditaireCharacter()
{
	ref pchar;
	ref ch;

	pchar = GetMainCharacter();
	ch = characterFromID(S3_GetCommanditaireId());
	if (!CheckAttribute(pchar, "quest_S3_commanditaire_firstname") || !CheckAttribute(pchar, "quest_S3_commanditaire_lastname"))
	{
		S3_SetGeneratedCommanditaireIdentity();
	}
	ch.name = pchar.quest_S3_commanditaire_firstname;
	ch.lastname = pchar.quest_S3_commanditaire_lastname;
	ch.model = "capitan1";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.greeting = "Gr_falaise de fleur citizen";
	ch.nation = FRANCE;
	ch.Dialog.Filename = "PJ Quest S3 commanditaire_dialog.c";
	ch.Dialog.CurrentNode = "First time";
	LAi_SetCitizenType(ch);
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
}

void S3_PrepareTargetCharacter()
{
	ref pchar;
	ref ch;

	pchar = GetMainCharacter();
	ch = characterFromID(S3_GetTargetId());
	ch.Dialog.Filename = "PJ Quest S3 target_dialog.c";
	ch.Dialog.CurrentNode = "First time";

	if (!CheckAttribute(pchar, "quest_S3_target_name"))
	{
		S3_SetGeneratedTargetData();
	}

	if (CheckAttribute(pchar, "quest_S3_target_gender") && pchar.quest_S3_target_gender == "female")
	{
		if (!CheckAttribute(pchar, "quest_S3_target_firstname") || !CheckAttribute(pchar, "quest_S3_target_lastname"))
		{
			S3_SetGeneratedTargetFemaleIdentity();
		}
		ch.name = pchar.quest_S3_target_firstname;
		ch.lastname = pchar.quest_S3_target_lastname;
		ch.model = "towngirl4";
		ch.sex = "woman";
		ch.sound_type = "female_citizen";
		ch.greeting = "Gr_Woman_French citizen";
		ch.model.animation = "towngirl";
		ch.headModel = "h_towngirl4";
		ch.FaceId = "0";
	}
	else
	{
		if (!CheckAttribute(pchar, "quest_S3_target_firstname") || !CheckAttribute(pchar, "quest_S3_target_lastname"))
		{
			S3_SetGeneratedTargetMaleIdentity();
		}
		ch.name = pchar.quest_S3_target_firstname;
		ch.lastname = pchar.quest_S3_target_lastname;
		ch.model = "man1";
		ch.sex = "man";
		ch.sound_type = "male_citizen";
		ch.greeting = "Gr_falaise de fleur citizen";
		ch.model.animation = "man";
		ch.headModel = "h_man1";
		ch.FaceId = "0";
	}

	ch.nation = FRANCE;
	LAi_SetCitizenType(ch);
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
}

void S3_PrepareWitnessCharacter()
{
	ref pchar;
	ref ch;

	pchar = GetMainCharacter();
	ch = characterFromID(S3_GetWitnessId());
	if (!CheckAttribute(pchar, "quest_S3_witness_firstname") || !CheckAttribute(pchar, "quest_S3_witness_lastname"))
	{
		S3_SetGeneratedWitnessIdentity();
	}
	ch.name = pchar.quest_S3_witness_firstname;
	ch.lastname = pchar.quest_S3_witness_lastname;
	ch.model = "bocman";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.greeting = "Gr_falaise de fleur citizen";
	ch.nation = FRANCE;
	ch.Dialog.Filename = "PJ Quest S3 witness_dialog.c";
	ch.Dialog.CurrentNode = "First time";
	LAi_SetCitizenType(ch);
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
}

void S3_OpenQuestHeaders()
{
	DeleteQuestHeader("PJ_S3");
	SetQuestHeader("PJ_S3");
	DeleteQuestHeader("PJ_S3_CODEX");
	SetQuestHeader("PJ_S3_CODEX");
	AddQuestRecord("PJ_S3_CODEX", "1");
	AddQuestRecord("PJ_S3_CODEX", "2");
	AddQuestRecord("PJ_S3_CODEX", "3");
	AddQuestRecord("PJ_S3_CODEX", "4");
	AddQuestRecord("PJ_S3_CODEX", "5");
	AddQuestRecord("PJ_S3_CODEX", "6");
	AddQuestRecord("PJ_S3_CODEX", "7");
	AddQuestRecord("PJ_S3_CODEX", "8");
	AddQuestRecord("PJ_S3_CODEX", "9");
	AddQuestRecord("PJ_S3_CODEX", "10");
	AddQuestRecord("PJ_S3_CODEX", "11");
}

void S3_CloseQuestHeaders()
{
	CloseQuestHeader("PJ_S3");
	CloseQuestHeader("PJ_S3_CODEX");
}

void S3_ResetRuntime()
{
	ref pchar = GetMainCharacter();

	S3_HideAllNpcs();
	S3_ClearRuntimeQuestEvents();
	S3_ClearInformants();

	DeleteAttribute(pchar, "quest_S3_status");
	DeleteAttribute(pchar, "quest_S3_city");
	DeleteAttribute(pchar, "quest_S3_commanditaire_id");
	DeleteAttribute(pchar, "quest_S3_commanditaire_name");
	DeleteAttribute(pchar, "quest_S3_commanditaire_firstname");
	DeleteAttribute(pchar, "quest_S3_commanditaire_lastname");
	DeleteAttribute(pchar, "quest_S3_target_id");
	DeleteAttribute(pchar, "quest_S3_witness_id");
	DeleteAttribute(pchar, "quest_S3_witness_name");
	DeleteAttribute(pchar, "quest_S3_witness_firstname");
	DeleteAttribute(pchar, "quest_S3_witness_lastname");
	DeleteAttribute(pchar, "quest_S3_target_name");
	DeleteAttribute(pchar, "quest_S3_target_firstname");
	DeleteAttribute(pchar, "quest_S3_target_lastname");
	DeleteAttribute(pchar, "quest_S3_target_gender");
	DeleteAttribute(pchar, "quest_S3_target_truth");
	DeleteAttribute(pchar, "quest_S3_deadline_day");
	DeleteAttribute(pchar, "quest_S3_deadline_month");
	DeleteAttribute(pchar, "quest_S3_deadline_year");
	DeleteAttribute(pchar, "quest_S3_reward_gold");
	DeleteAttribute(pchar, "quest_S3_city_reward_gold");
	DeleteAttribute(pchar, "quest_S3_target_killed");
	DeleteAttribute(pchar, "quest_S3_target_released");
	DeleteAttribute(pchar, "quest_S3_commanditaire_killed");
	DeleteAttribute(pchar, "quest_S3_city_bad_reputation");
}

void S3_FinalizeQuest(string resolution)
{
	ref pchar = GetMainCharacter();

	pchar.quest_S3_resolution = resolution;
	pchar.quest_S3_completed = true;
	pchar.quest_S3_status = "completed";
	S3_CloseQuestHeaders();
	S3_ResetRuntime();
}

void S3_SetRunCity(string cityKey)
{
	ref pchar = GetMainCharacter();

	pchar.quest_S3_city = cityKey;
	pchar.quest_S3_commanditaire_id = S3_GetCommanditaireId();
	pchar.quest_S3_target_id = S3_GetTargetId();
	pchar.quest_S3_witness_id = S3_GetWitnessId();
}

void S3_StartDeadlineTimer()
{
	ref pchar = GetMainCharacter();

	pchar.quest_S3_deadline_day = GetAddingDataDay(0, 0, 2);
	pchar.quest_S3_deadline_month = GetAddingDataMonth(0, 0, 2);
	pchar.quest_S3_deadline_year = GetAddingDataYear(0, 0, 2);

	pchar.quest.quest_S3_deadline_expired.win_condition.l1 = "Timer";
	pchar.quest.quest_S3_deadline_expired.win_condition.l1.date.day = sti(pchar.quest_S3_deadline_day);
	pchar.quest.quest_S3_deadline_expired.win_condition.l1.date.month = sti(pchar.quest_S3_deadline_month);
	pchar.quest.quest_S3_deadline_expired.win_condition.l1.date.year = sti(pchar.quest_S3_deadline_year);
	pchar.quest.quest_S3_deadline_expired.win_condition = "quest_S3_deadline_expired";
}

void S3_ExpireAcceptedQuest()
{
	S3_CloseQuestHeaders();
	S3_ResetRuntime();
}

void S3_SetGeneratedCommanditaireIdentity()
{
	ref pchar = GetMainCharacter();

	switch (rand(29))
	{
		case 0:
			pchar.quest_S3_commanditaire_firstname = "Charles";
			pchar.quest_S3_commanditaire_lastname = "dit le Rat d'égout";
		break;
		case 1:
			pchar.quest_S3_commanditaire_firstname = "Edgar";
			pchar.quest_S3_commanditaire_lastname = "dit le Furet";
		break;
		case 2:
			pchar.quest_S3_commanditaire_firstname = "Silas";
			pchar.quest_S3_commanditaire_lastname = "dit la Suie";
		break;
		case 3:
			pchar.quest_S3_commanditaire_firstname = "Victor";
			pchar.quest_S3_commanditaire_lastname = "dit le Brouillard";
		break;
		case 4:
			pchar.quest_S3_commanditaire_firstname = "Tobias";
			pchar.quest_S3_commanditaire_lastname = "dit le Crochet";
		break;
		case 5:
			pchar.quest_S3_commanditaire_firstname = "Abel";
			pchar.quest_S3_commanditaire_lastname = "dit la Griffe";
		break;
		case 6:
			pchar.quest_S3_commanditaire_firstname = "Elias";
			pchar.quest_S3_commanditaire_lastname = "dit le Corbeau";
		break;
		case 7:
			pchar.quest_S3_commanditaire_firstname = "Morris";
			pchar.quest_S3_commanditaire_lastname = "dit le Verrou";
		break;
		case 8:
			pchar.quest_S3_commanditaire_firstname = "Gideon";
			pchar.quest_S3_commanditaire_lastname = "dit le Cendreux";
		break;
		case 9:
			pchar.quest_S3_commanditaire_firstname = "Barnaby";
			pchar.quest_S3_commanditaire_lastname = "dit le Chiffon Noir";
		break;
		case 10:
			pchar.quest_S3_commanditaire_firstname = "Rupert";
			pchar.quest_S3_commanditaire_lastname = "dit la Lanterne Morte";
		break;
		case 11:
			pchar.quest_S3_commanditaire_firstname = "Jonas";
			pchar.quest_S3_commanditaire_lastname = "dit le Bec de Rat";
		break;
		case 12:
			pchar.quest_S3_commanditaire_firstname = "Crispin";
			pchar.quest_S3_commanditaire_lastname = "dit le Casse-Bourse";
		break;
		case 13:
			pchar.quest_S3_commanditaire_firstname = "Walter";
			pchar.quest_S3_commanditaire_lastname = "dit le Crachat";
		break;
		case 14:
			pchar.quest_S3_commanditaire_firstname = "Dorian";
			pchar.quest_S3_commanditaire_lastname = "dit la Brume";
		break;
		case 15:
			pchar.quest_S3_commanditaire_firstname = "Phineas";
			pchar.quest_S3_commanditaire_lastname = "dit le Taupier";
		break;
		case 16:
			pchar.quest_S3_commanditaire_firstname = "Oswald";
			pchar.quest_S3_commanditaire_lastname = "dit le Chien Crevé";
		break;
		case 17:
			pchar.quest_S3_commanditaire_firstname = "Neville";
			pchar.quest_S3_commanditaire_lastname = "dit la Rouille";
		break;
		case 18:
			pchar.quest_S3_commanditaire_firstname = "Quentin";
			pchar.quest_S3_commanditaire_lastname = "dit le Ruisseau Noir";
		break;
		case 19:
			pchar.quest_S3_commanditaire_firstname = "Jasper";
			pchar.quest_S3_commanditaire_lastname = "dit le Goupil";
		break;
		case 20:
			pchar.quest_S3_commanditaire_firstname = "Lionel";
			pchar.quest_S3_commanditaire_lastname = "dit le Clou";
		break;
		case 21:
			pchar.quest_S3_commanditaire_firstname = "Harold";
			pchar.quest_S3_commanditaire_lastname = "dit le Couteau Tordu";
		break;
		case 22:
			pchar.quest_S3_commanditaire_firstname = "Duncan";
			pchar.quest_S3_commanditaire_lastname = "dit la Boue";
		break;
		case 23:
			pchar.quest_S3_commanditaire_firstname = "Cedric";
			pchar.quest_S3_commanditaire_lastname = "dit le Sifflet";
		break;
		case 24:
			pchar.quest_S3_commanditaire_firstname = "Ambrose";
			pchar.quest_S3_commanditaire_lastname = "dit la Charette Grince";
		break;
		case 25:
			pchar.quest_S3_commanditaire_firstname = "Percival";
			pchar.quest_S3_commanditaire_lastname = "dit le Croc";
		break;
		case 26:
			pchar.quest_S3_commanditaire_firstname = "Basil";
			pchar.quest_S3_commanditaire_lastname = "dit le Drap Sale";
		break;
		case 27:
			pchar.quest_S3_commanditaire_firstname = "Cornelius";
			pchar.quest_S3_commanditaire_lastname = "dit la Balafre";
		break;
		case 28:
			pchar.quest_S3_commanditaire_firstname = "Nathaniel";
			pchar.quest_S3_commanditaire_lastname = "dit le Caniveau";
		break;
		case 29:
			pchar.quest_S3_commanditaire_firstname = "Gregory";
			pchar.quest_S3_commanditaire_lastname = "dit le Rat de Cave";
		break;
	}

	pchar.quest_S3_commanditaire_name = pchar.quest_S3_commanditaire_firstname + " " + pchar.quest_S3_commanditaire_lastname;
}

void S3_SetGeneratedTargetMaleIdentity()
{
	ref pchar = GetMainCharacter();

	pchar.quest_S3_target_gender = "male";
	switch (rand(49))
	{
		case 0:
			pchar.quest_S3_target_firstname = "Mat";
			pchar.quest_S3_target_lastname = "Ahari";
		break;
		case 1:
			pchar.quest_S3_target_firstname = "James";
			pchar.quest_S3_target_lastname = "Bon";
		break;
		case 2:
			pchar.quest_S3_target_firstname = "Don";
			pchar.quest_S3_target_lastname = "Juan";
		break;
		case 3:
			pchar.quest_S3_target_firstname = "Arsene";
			pchar.quest_S3_target_lastname = "Larcin";
		break;
		case 4:
			pchar.quest_S3_target_firstname = "Vidocq";
			pchar.quest_S3_target_lastname = "Pasquier";
		break;
		case 5:
			pchar.quest_S3_target_firstname = "Hector";
			pchar.quest_S3_target_lastname = "Passepasse";
		break;
		case 6:
			pchar.quest_S3_target_firstname = "Robin";
			pchar.quest_S3_target_lastname = "Escroc";
		break;
		case 7:
			pchar.quest_S3_target_firstname = "Max";
			pchar.quest_S3_target_lastname = "Racket";
		break;
		case 8:
			pchar.quest_S3_target_firstname = "Oscar";
			pchar.quest_S3_target_lastname = "Niaque";
		break;
		case 9:
			pchar.quest_S3_target_firstname = "César";
			pchar.quest_S3_target_lastname = "Frappe";
		break;
		case 10:
			pchar.quest_S3_target_firstname = "Hugo";
			pchar.quest_S3_target_lastname = "Pique";
		break;
		case 11:
			pchar.quest_S3_target_firstname = "éo";
			pchar.quest_S3_target_lastname = "Clandestin";
		break;
		case 12:
			pchar.quest_S3_target_firstname = "Nico";
			pchar.quest_S3_target_lastname = "Tine";
		break;
		case 13:
			pchar.quest_S3_target_firstname = "Félix";
			pchar.quest_S3_target_lastname = "Crochet";
		break;
		case 14:
			pchar.quest_S3_target_firstname = "Basil";
			pchar.quest_S3_target_lastname = "Bourse";
		break;
		case 15:
			pchar.quest_S3_target_firstname = "Edgar";
			pchar.quest_S3_target_lastname = "Pogne";
		break;
		case 16:
			pchar.quest_S3_target_firstname = "Milo";
			pchar.quest_S3_target_lastname = "Minuit";
		break;
		case 17:
			pchar.quest_S3_target_firstname = "Simon";
			pchar.quest_S3_target_lastname = "Blesse";
		break;
		case 18:
			pchar.quest_S3_target_firstname = "Boris";
			pchar.quest_S3_target_lastname = "Baston";
		break;
		case 19:
			pchar.quest_S3_target_firstname = "Rémy";
			pchar.quest_S3_target_lastname = "Rififi";
		break;
		case 20:
			pchar.quest_S3_target_firstname = "Marcel";
			pchar.quest_S3_target_lastname = "Carambouille";
		break;
		case 21:
			pchar.quest_S3_target_firstname = "Gaston";
			pchar.quest_S3_target_lastname = "Gredin";
		break;
		case 22:
			pchar.quest_S3_target_firstname = "Luc";
			pchar.quest_S3_target_lastname = "Volteface";
		break;
		case 23:
			pchar.quest_S3_target_firstname = "Armand";
			pchar.quest_S3_target_lastname = "Magouille";
		break;
		case 24:
			pchar.quest_S3_target_firstname = "Sylvain";
			pchar.quest_S3_target_lastname = "Surin";
		break;
		case 25:
			pchar.quest_S3_target_firstname = "Théo";
			pchar.quest_S3_target_lastname = "Canaille";
		break;
		case 26:
			pchar.quest_S3_target_firstname = "Nestor";
			pchar.quest_S3_target_lastname = "Filou";
		break;
		case 27:
			pchar.quest_S3_target_firstname = "Pascal";
			pchar.quest_S3_target_lastname = "Embrouille";
		break;
		case 28:
			pchar.quest_S3_target_firstname = "Jules";
			pchar.quest_S3_target_lastname = "Cassecou";
		break;
		case 29:
			pchar.quest_S3_target_firstname = "Anton";
			pchar.quest_S3_target_lastname = "Rapine";
		break;
		case 30:
			pchar.quest_S3_target_firstname = "Bruno";
			pchar.quest_S3_target_lastname = "Passemuraille";
		break;
		case 31:
			pchar.quest_S3_target_firstname = "Gaspard";
			pchar.quest_S3_target_lastname = "Grappin";
		break;
		case 32:
			pchar.quest_S3_target_firstname = "Clovis";
			pchar.quest_S3_target_lastname = "Coupfourre";
		break;
		case 33:
			pchar.quest_S3_target_firstname = "Damien";
			pchar.quest_S3_target_lastname = "Dague";
		break;
		case 34:
			pchar.quest_S3_target_firstname = "Martin";
			pchar.quest_S3_target_lastname = "Fripon";
		break;
		case 35:
			pchar.quest_S3_target_firstname = "Achille";
			pchar.quest_S3_target_lastname = "Traquenard";
		break;
		case 36:
			pchar.quest_S3_target_firstname = "Leon";
			pchar.quest_S3_target_lastname = "Grimace";
		break;
		case 37:
			pchar.quest_S3_target_firstname = "Quentin";
			pchar.quest_S3_target_lastname = "Quiproquo";
		break;
		case 38:
			pchar.quest_S3_target_firstname = "Firmin";
			pchar.quest_S3_target_lastname = "Faussepiste";
		break;
		case 39:
			pchar.quest_S3_target_firstname = "Alaric";
			pchar.quest_S3_target_lastname = "Aigrefin";
		break;
		case 40:
			pchar.quest_S3_target_firstname = "Didier";
			pchar.quest_S3_target_lastname = "Doublefond";
		break;
		case 41:
			pchar.quest_S3_target_firstname = "Fabian";
			pchar.quest_S3_target_lastname = "Fumee";
		break;
		case 42:
			pchar.quest_S3_target_firstname = "Corbin";
			pchar.quest_S3_target_lastname = "Corbeau";
		break;
		case 43:
			pchar.quest_S3_target_firstname = "Marius";
			pchar.quest_S3_target_lastname = "Mainleste";
		break;
		case 44:
			pchar.quest_S3_target_firstname = "Auguste";
			pchar.quest_S3_target_lastname = "Mauvaiscoup";
		break;
		case 45:
			pchar.quest_S3_target_firstname = "Raoul";
			pchar.quest_S3_target_lastname = "Rancune";
		break;
		case 46:
			pchar.quest_S3_target_firstname = "Severin";
			pchar.quest_S3_target_lastname = "Sournois";
		break;
		case 47:
			pchar.quest_S3_target_firstname = "Isidore";
			pchar.quest_S3_target_lastname = "Triche";
		break;
		case 48:
			pchar.quest_S3_target_firstname = "Anatole";
			pchar.quest_S3_target_lastname = "Trahison";
		break;
		case 49:
			pchar.quest_S3_target_firstname = "Blaise";
			pchar.quest_S3_target_lastname = "Braconnier";
		break;
	}

	pchar.quest_S3_target_name = pchar.quest_S3_target_firstname + " " + pchar.quest_S3_target_lastname;
}

void S3_SetGeneratedTargetFemaleIdentity()
{
	ref pchar = GetMainCharacter();

	pchar.quest_S3_target_gender = "female";
	switch (rand(19))
	{
		case 0:
			pchar.quest_S3_target_firstname = "Hélène";
			pchar.quest_S3_target_lastname = "Detrois";
		break;
		case 1:
			pchar.quest_S3_target_firstname = "Bella";
			pchar.quest_S3_target_lastname = "Donna";
		break;
		case 2:
			pchar.quest_S3_target_firstname = "Vera";
			pchar.quest_S3_target_lastname = "Volta";
		break;
		case 3:
			pchar.quest_S3_target_firstname = "Iris";
			pchar.quest_S3_target_lastname = "Noire";
		break;
		case 4:
			pchar.quest_S3_target_firstname = "Lola";
			pchar.quest_S3_target_lastname = "Larcin";
		break;
		case 5:
			pchar.quest_S3_target_firstname = "Carmen";
			pchar.quest_S3_target_lastname = "Fatale";
		break;
		case 6:
			pchar.quest_S3_target_firstname = "Nora";
			pchar.quest_S3_target_lastname = "Niaque";
		break;
		case 7:
			pchar.quest_S3_target_firstname = "Violette";
			pchar.quest_S3_target_lastname = "Venin";
		break;
		case 8:
			pchar.quest_S3_target_firstname = "Eva";
			pchar.quest_S3_target_lastname = "Sive";
		break;
		case 9:
			pchar.quest_S3_target_firstname = "Rita";
			pchar.quest_S3_target_lastname = "Rixe";
		break;
		case 10:
			pchar.quest_S3_target_firstname = "Sonia";
			pchar.quest_S3_target_lastname = "Sombre";
		break;
		case 11:
			pchar.quest_S3_target_firstname = "Bianca";
			pchar.quest_S3_target_lastname = "Brume";
		break;
		case 12:
			pchar.quest_S3_target_firstname = "Gloria";
			pchar.quest_S3_target_lastname = "Gifle";
		break;
		case 13:
			pchar.quest_S3_target_firstname = "Stella";
			pchar.quest_S3_target_lastname = "Surin";
		break;
		case 14:
			pchar.quest_S3_target_firstname = "Sylvia";
			pchar.quest_S3_target_lastname = "Vipere";
		break;
		case 15:
			pchar.quest_S3_target_firstname = "Morgane";
			pchar.quest_S3_target_lastname = "Morsure";
		break;
		case 16:
			pchar.quest_S3_target_firstname = "Clara";
			pchar.quest_S3_target_lastname = "Cassecoeur";
		break;
		case 17:
			pchar.quest_S3_target_firstname = "Diana";
			pchar.quest_S3_target_lastname = "Dague";
		break;
		case 18:
			pchar.quest_S3_target_firstname = "Paula";
			pchar.quest_S3_target_lastname = "Poudre";
		break;
		case 19:
			pchar.quest_S3_target_firstname = "Roxane";
			pchar.quest_S3_target_lastname = "Ruse";
		break;
	}

	pchar.quest_S3_target_name = pchar.quest_S3_target_firstname + " " + pchar.quest_S3_target_lastname;
}

void S3_SetGeneratedWitnessIdentity()
{
	ref pchar = GetMainCharacter();

	switch (rand(19))
	{
		case 0:
			pchar.quest_S3_witness_firstname = "Général";
			pchar.quest_S3_witness_lastname = "De Gaulle";
		break;
		case 1:
			pchar.quest_S3_witness_firstname = "Sherlock";
			pchar.quest_S3_witness_lastname = "Holmes";
		break;
		case 2:
			pchar.quest_S3_witness_firstname = "Zinédine";
			pchar.quest_S3_witness_lastname = "Zidane";
		break;
		case 3:
			pchar.quest_S3_witness_firstname = "Steve";
			pchar.quest_S3_witness_lastname = "Jobs";
		break;
		case 4:
			pchar.quest_S3_witness_firstname = "Albert";
			pchar.quest_S3_witness_lastname = "Einstein";
		break;
		case 5:
			pchar.quest_S3_witness_firstname = "Isaac";
			pchar.quest_S3_witness_lastname = "Newton";
		break;
		case 6:
			pchar.quest_S3_witness_firstname = "Leonardo";
			pchar.quest_S3_witness_lastname = "da Vinci";
		break;
		case 7:
			pchar.quest_S3_witness_firstname = "Victor";
			pchar.quest_S3_witness_lastname = "Hugo";
		break;
		case 8:
			pchar.quest_S3_witness_firstname = "Alexandre";
			pchar.quest_S3_witness_lastname = "Dumas";
		break;
		case 9:
			pchar.quest_S3_witness_firstname = "Napoléon";
			pchar.quest_S3_witness_lastname = "Bonaparte";
		break;
		case 10:
			pchar.quest_S3_witness_firstname = "Jules";
			pchar.quest_S3_witness_lastname = "César";
		break;
		case 11:
			pchar.quest_S3_witness_firstname = "Charlemagne";
			pchar.quest_S3_witness_lastname = "le Grand";
		break;
		case 12:
			pchar.quest_S3_witness_firstname = "Galilée";
			pchar.quest_S3_witness_lastname = "Galilée";
		break;
		case 13:
			pchar.quest_S3_witness_firstname = "Christophe";
			pchar.quest_S3_witness_lastname = "Colomb";
		break;
		case 14:
			pchar.quest_S3_witness_firstname = "Wolfgang";
			pchar.quest_S3_witness_lastname = "Mozart";
		break;
		case 15:
			pchar.quest_S3_witness_firstname = "Ludwig";
			pchar.quest_S3_witness_lastname = "Beethoven";
		break;
		case 16:
			pchar.quest_S3_witness_firstname = "Jean-Baptiste";
			pchar.quest_S3_witness_lastname = "Molière";
		break;
		case 17:
			pchar.quest_S3_witness_firstname = "Elvis";
			pchar.quest_S3_witness_lastname = "Presley";
		break;
		case 18:
			pchar.quest_S3_witness_firstname = "Michael";
			pchar.quest_S3_witness_lastname = "Jackson";
		break;
		case 19:
			pchar.quest_S3_witness_firstname = "Charlie";
			pchar.quest_S3_witness_lastname = "Chaplin";
		break;
	}

	pchar.quest_S3_witness_name = pchar.quest_S3_witness_firstname + " " + pchar.quest_S3_witness_lastname;
}

void S3_SetGeneratedTargetData()
{
	ref pchar = GetMainCharacter();

	if (rand(5) == 0)
	{
		S3_SetGeneratedTargetFemaleIdentity();
	}
	else
	{
		S3_SetGeneratedTargetMaleIdentity();
	}

	if (rand(1) == 0)
	{
		pchar.quest_S3_target_truth = "innocent";
	}
	else
	{
		pchar.quest_S3_target_truth = "guilty";
	}
}

void S3_PlaceCommanditaire(string locationId)
{
	ref ch;

	ch = characterFromID(S3_GetCommanditaireId());
	ch.Dialog.CurrentNode = "First time";
	PlaceCharacter(ch, "goto", locationId);
}

void S3_PlaceTarget(string locationId)
{
	ref ch;

	ch = characterFromID(S3_GetTargetId());
	ch.Dialog.CurrentNode = "First time";
	PlaceCharacter(ch, "goto", locationId);
}

void S3_StartWitnessEncounter()
{
	ref pchar;
	ref witness;
	string locationId;

	pchar = GetMainCharacter();
	locationId = pchar.location;
	if (!S3_IsEligibleLocation(locationId))
	{
		locationId = S3_GetExteriorLocationFromCity(pchar.quest_S3_city);
	}

	witness = characterFromID(S3_GetWitnessId());
	witness.Dialog.CurrentNode = "First time";
	PlaceCharacter(witness, "goto", locationId);
	LAi_SetActorType(witness);
	LAi_SetActorType(pchar);
	LAi_ActorFollow(pchar, witness, "", 2.0);
	LAi_ActorFollow(witness, pchar, "quest_S3_witness_talk", 2.0);
}

void S3_StartTargetFight()
{
	ref pchar;
	ref target;
	string locationId;

	pchar = GetMainCharacter();
	target = characterFromID(S3_GetTargetId());
	locationId = pchar.location;

	PlaceCharacter(target, "goto", locationId);
	GiveItem2Character(target, BLADE_SABER);
	target.equip.blade = BLADE_SABER;
	EquipCharacterByItem(target, BLADE_SABER);
	LAi_SetWarriorType(target);
	target.Dialog.CurrentNode = "Finished";
	LAi_group_MoveCharacter(target, "S3_TARGET_GROUP");
	pchar.quest.quest_S3_target_dead.win_condition.l1 = "NPC_Death";
	pchar.quest.quest_S3_target_dead.win_condition.l1.character = S3_GetTargetId();
	pchar.quest.quest_S3_target_dead.win_condition = "quest_S3_target_dead";
	LAi_group_FightGroups("S3_TARGET_GROUP", LAI_GROUP_PLAYER, true);
}

void S3_StartCommanditaireDuel()
{
	ref pchar;
	ref ch;
	string locationId;

	pchar = GetMainCharacter();
	ch = characterFromID(S3_GetCommanditaireId());
	locationId = pchar.location;

	PlaceCharacter(ch, "goto", locationId);
	LAi_SetWarriorType(ch);
	ch.Dialog.CurrentNode = "Finished";
	LAi_group_MoveCharacter(ch, "S3_COMMANDITAIRE_GROUP");
	pchar.quest.quest_S3_commanditaire_dead.win_condition.l1 = "NPC_Death";
	pchar.quest.quest_S3_commanditaire_dead.win_condition.l1.character = S3_GetCommanditaireId();
	pchar.quest.quest_S3_commanditaire_dead.win_condition = "quest_S3_commanditaire_dead";
	LAi_group_FightGroups("S3_COMMANDITAIRE_GROUP", LAI_GROUP_PLAYER, true);
}

void S3_ProcessLocationEnter()
{
	ref pchar = GetMainCharacter();
	string locationId;
	string cityKey;
	string status;

	locationId = pchar.location;
	S3_HideAllNpcs();

	if (!CheckAttribute(pchar, "quest_PJ_sidequests_unlocked") || sti(pchar.quest_PJ_sidequests_unlocked) != true)
	{
		return;
	}

	if (S3_IsDeadlineExpired())
	{
		S3_ExpireAcceptedQuest();
		return;
	}

	if (!S3_IsEligibleLocation(locationId))
	{
		return;
	}

	if (!S3_IsQuestActive())
	{
		if (!S3_IsCommanditaireHour())
		{
			return;
		}
		if (rand(2) == 0)
		{
			return;
		}

		cityKey = S3_GetCityKeyFromLocation(locationId);
		pchar.quest_S3_status = "spawned";
		pchar.quest_S3_run_id = S3_GetRunId() + 1;
		S3_SetRunCity(cityKey);
		S3_SetGeneratedCommanditaireIdentity();
		S3_SetGeneratedTargetData();
		S3_SetGeneratedWitnessIdentity();
		S3_PrepareCommanditaireCharacter();
		S3_PrepareTargetCharacter();
		S3_PrepareWitnessCharacter();
		S3_PlaceCommanditaire(locationId);
		return;
	}

	status = pchar.quest_S3_status;
	if (!CheckAttribute(pchar, "quest_S3_city"))
	{
		return;
	}

	if (locationId != S3_GetExteriorLocationFromCity(pchar.quest_S3_city))
	{
		return;
	}

	S3_PrepareCommanditaireCharacter();
	S3_PrepareTargetCharacter();
	S3_PrepareWitnessCharacter();

	if (S3_IsCommanditaireStatus(status))
	{
		if (!S3_IsCommanditaireHour())
		{
			return;
		}

		S3_PlaceCommanditaire(locationId);
		return;
	}

	if (S3_IsTargetStatus(status))
	{
		if (!S3_IsTargetHour())
		{
			return;
		}

		S3_PlaceTarget(locationId);
		return;
	}
}

bool QuestComplete_S3(string sQuestName)
{
	ref pchar = GetMainCharacter();
	ref target;
	ref witness;
	string cityKey;

	switch (sQuestName)
	{
		case "quest_S3_offer_accept":
			cityKey = S3_GetCityKeyFromLocation(pchar.location);
			if (cityKey == "")
			{
				break;
			}

			S3_OpenQuestHeaders();
			S3_SetRunCity(cityKey);
			if (!CheckAttribute(pchar, "quest_S3_target_name"))
			{
				S3_SetGeneratedTargetData();
			}
			S3_PrepareCommanditaireCharacter();
			S3_PrepareTargetCharacter();
			S3_PrepareWitnessCharacter();
			S3_StartDeadlineTimer();
			pchar.quest_S3_reward_gold = 500 + (100 * makeint(pchar.rank));
			pchar.quest_S3_city_reward_gold = 250 + (50 * makeint(pchar.rank));
			pchar.quest_S3_status = "investigation";
			AddQuestRecord("PJ_S3", "1");
			if (CheckAttribute(pchar, "quest_S3_target_name"))
			{
				if (pchar.quest_S3_target_name == "Jean-Baptiste Lemoine")
				{
					AddQuestRecord("PJ_S3", "9");
				}
				else
				{
					if (pchar.quest_S3_target_name == "Jeanne Mercier")
					{
						AddQuestRecord("PJ_S3", "10");
					}
				}
			}
			return true;
		break;

		case "quest_S3_offer_refuse":
			pchar.quest_S3_status = "closed";
			S3_ResetRuntime();
			return true;
		break;

		case "quest_S3_deadline_expired":
			S3_ExpireAcceptedQuest();
			return true;
		break;

		case "quest_S3_target_release":
			pchar.quest_S3_target_released = true;
			pchar.quest_S3_status = "target_released";
			AddQuestRecord("PJ_S3", "3");
			return true;
		break;

		case "quest_S3_target_kill":
			pchar.quest_S3_status = "candidate_target_kill";
			S3_StartTargetFight();
			return true;
		break;

		case "quest_S3_target_dead":
			pchar.quest_S3_target_killed = true;
			pchar.quest_S3_status = "target_killed";
			AddQuestRecord("PJ_S3", "2");
			return true;
		break;

		case "quest_S3_collect_reward":
			AddMoneyToCharacter(pchar, makeint(pchar.quest_S3_reward_gold));
			pchar.quest_S3_status = "commanditaire_paid";
			if (pchar.quest_S3_target_truth == "guilty")
			{
				ChangeCharacterReputation(pchar, 3);
				AddPartyExp(pchar, 1000 * makeint(pchar.rank));
				AddQuestRecord("PJ_S3", "4");
				S3_FinalizeQuest("good_kill");
			}
			else
			{
				ChangeCharacterReputation(pchar, -7);
				AddPartyExp(pchar, 250 * makeint(pchar.rank));
				pchar.quest_S3_city_bad_reputation = true;
				AddQuestRecord("PJ_S3", "7");
				S3_FinalizeQuest("bad_kill");
			}
			return true;
		break;

		case "quest_S3_start_duel":
			if (pchar.quest_S3_target_truth == "guilty")
			{
				ChangeCharacterReputation(pchar, -3);
				AddPartyExp(pchar, 100 * makeint(pchar.rank));
				pchar.quest_S3_city_bad_reputation = true;
				AddQuestRecord("PJ_S3", "8");
				S3_FinalizeQuest("bad_release");
				return true;
			}

			pchar.quest_S3_status = "commanditaire_duel";
			S3_StartCommanditaireDuel();
			return true;
		break;

		case "quest_S3_commanditaire_dead":
			pchar.quest_S3_commanditaire_killed = true;

			if (pchar.quest_S3_target_truth == "innocent")
			{
				pchar.quest_S3_status = "completed";
				AddQuestRecord("PJ_S3", "5");
				S3_StartWitnessEncounter();
				return true;
			}

			ChangeCharacterReputation(pchar, -3);
			AddPartyExp(pchar, 100 * makeint(pchar.rank));
			pchar.quest_S3_city_bad_reputation = true;
			AddQuestRecord("PJ_S3", "8");
			S3_FinalizeQuest("bad_release");
			return true;
		break;

		case "quest_S3_witness_talk":
			LAi_type_actor_Reset(pchar);
			witness = characterFromID(S3_GetWitnessId());
			LAi_ActorWaitDialog(pchar, witness);
			LAi_ActorDialog(witness, pchar, "pchar_back_to_player", 2.0, 1.0);
			characters[GetCharacterIndex(S3_GetWitnessId())].dialog.currentnode = "First time";
			return true;
		break;

		case "quest_S3_witness_reward":
			AddMoneyToCharacter(pchar, makeint(pchar.quest_S3_city_reward_gold));
			ChangeCharacterReputation(pchar, 7);
			AddPartyExp(pchar, 1000 * makeint(pchar.rank));
			AddQuestRecord("PJ_S3", "6");
			S3_FinalizeQuest("good_release");
			return true;
		break;
	}

	return false;
}
// fin ajout PJ
