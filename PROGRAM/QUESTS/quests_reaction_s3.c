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

bool S3_IsQuestActive()
{
	ref pchar = GetMainCharacter();
	string status;

	if (!CheckAttribute(pchar, "quest_S3_status"))
	{
		return false;
	}

	status = pchar.quest_S3_status;
	switch (status)
	{
		case "":
			return false;
		break;
		case "closed":
			return false;
		break;
		case "completed":
			return false;
		break;
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
	ref ch;

	ch = characterFromID(S3_GetCommanditaireId());
	ch.name = "Marius";
	ch.lastname = "Leroux";
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

	if (CheckAttribute(pchar, "quest_S3_target_gender") && pchar.quest_S3_target_gender == "female")
	{
		ch.name = "Jeanne";
		ch.lastname = "Mercier";
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
		ch.name = "Jean-Baptiste";
		ch.lastname = "Lemoine";
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
	ref ch;

	ch = characterFromID(S3_GetWitnessId());
	ch.name = "Bastien";
	ch.lastname = "Ravel";
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
	DeleteAttribute(pchar, "quest_S3_target_id");
	DeleteAttribute(pchar, "quest_S3_witness_id");
	DeleteAttribute(pchar, "quest_S3_target_name");
	DeleteAttribute(pchar, "quest_S3_target_gender");
	DeleteAttribute(pchar, "quest_S3_target_truth");
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

void S3_SetGeneratedTargetData()
{
	ref pchar = GetMainCharacter();

	if (rand(5) == 0)
	{
		pchar.quest_S3_target_gender = "female";
		pchar.quest_S3_target_name = "Jeanne Mercier";
	}
	else
	{
		pchar.quest_S3_target_gender = "male";
		pchar.quest_S3_target_name = "Jean-Baptiste Lemoine";
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
