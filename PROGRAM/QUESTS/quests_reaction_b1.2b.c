// B1.2b - La Lettre derobee

#define B12B_HEADER "PJ_B1_2B"
#define B12B_TRANS_SUBQUEST "B1.2b"

#define B12B_GROUP_CAPTAINS "B12B_NAVAL_CAPTAINS"
#define B12B_GROUP_PRIESTS "B12B_SHANGO_PRIESTS"

#define B12B_STATUS_NOT_STARTED "not_started"
#define B12B_STATUS_DOUWESEN_INQUIRY "douwesen_inquiry"
#define B12B_STATUS_FRENCH_GOVERNOR "french_governor"
#define B12B_STATUS_FRENCH_SPY "french_spy"
#define B12B_STATUS_RETURN_SILEHARD "return_silehard"
#define B12B_STATUS_NAVAL_ASSAULT "naval_assault"
#define B12B_STATUS_RITUAL_CAVE "ritual_cave"
#define B12B_STATUS_PRIESTS_DEAD "priests_dead"
#define B12B_STATUS_COMPLETED "completed"
#define B12B_STATUS_CLOSED "closed"

#define B12B_EVENT_MALCOLM_HINT "PJ_B1_2B_MALCOLM_HINT"
#define B12B_EVENT_WITNESS1 "PJ_B1_2B_WITNESS1"
#define B12B_EVENT_WITNESS2 "PJ_B1_2B_WITNESS2"
#define B12B_EVENT_WITNESS3 "PJ_B1_2B_WITNESS3"
#define B12B_EVENT_FRENCH_GOVERNOR "PJ_B1_2B_FRENCH_GOVERNOR"
#define B12B_EVENT_FRENCH_SPY "PJ_B1_2B_FRENCH_SPY"
#define B12B_EVENT_SILEHARD_DESTINATION "PJ_B1_2B_SILEHARD_DESTINATION"
#define B12B_EVENT_NAVAL_SCENE "PJ_B1_2B_NAVAL_SCENE"
#define B12B_EVENT_NAVAL_FIGHT "PJ_B1_2B_NAVAL_FIGHT"
#define B12B_EVENT_NAVAL_DONE "PJ_B1_2B_NAVAL_DONE"
#define B12B_EVENT_RITUAL_SCENE "PJ_B1_2B_RITUAL_SCENE"
#define B12B_EVENT_PRIEST_FIGHT "PJ_B1_2B_PRIEST_FIGHT"
#define B12B_EVENT_PRIESTS_DONE "PJ_B1_2B_PRIESTS_DONE"
#define B12B_EVENT_FINAL_REPORT "PJ_B1_2B_FINAL_REPORT"
#define B12B_EVENT_WAR_TIMER_READY "PJ_B1_2B_WAR_TIMER_READY"

bool B12B_HasFleetDestroyed()
{
	ref pchar = GetMainCharacter();
	return CheckAttribute(pchar, "quest_b1_2b_fleet_destroyed") && sti(pchar.quest_b1_2b_fleet_destroyed) == true;
}

bool B12B_IsRitualUnlockedStatus(string status)
{
	switch (status)
	{
		case B12B_STATUS_RITUAL_CAVE:
			return true;
		break;

		case B12B_STATUS_PRIESTS_DEAD:
			return true;
		break;

		case B12B_STATUS_COMPLETED:
			return true;
		break;

		case B12B_STATUS_CLOSED:
			return true;
		break;
	}

	return false;
}

bool B12B_IsWitnessInquiryStatus(string status)
{
	switch (status)
	{
		case B12B_STATUS_DOUWESEN_INQUIRY:
			return true;
		break;

		case B12B_STATUS_FRENCH_GOVERNOR:
			return true;
		break;
	}

	return false;
}

bool B12B_IsSpyCleanStatus(string status)
{
	switch (status)
	{
		case B12B_STATUS_FRENCH_SPY:
			return true;
		break;

		case B12B_STATUS_RETURN_SILEHARD:
			return true;
		break;

		case B12B_STATUS_NAVAL_ASSAULT:
			return true;
		break;

		case B12B_STATUS_RITUAL_CAVE:
			return true;
		break;

		case B12B_STATUS_PRIESTS_DEAD:
			return true;
		break;
	}

	return false;
}

bool B12B_IsRecognizedEvent(string sQuestName)
{
	switch (sQuestName)
	{
		case B12B_EVENT_MALCOLM_HINT:
			return true;
		break;

		case B12B_EVENT_WITNESS1:
			return true;
		break;

		case B12B_EVENT_WITNESS2:
			return true;
		break;

		case B12B_EVENT_WITNESS3:
			return true;
		break;

		case B12B_EVENT_FRENCH_GOVERNOR:
			return true;
		break;

		case B12B_EVENT_FRENCH_SPY:
			return true;
		break;

		case B12B_EVENT_SILEHARD_DESTINATION:
			return true;
		break;

		case B12B_EVENT_NAVAL_SCENE:
			return true;
		break;

		case B12B_EVENT_NAVAL_FIGHT:
			return true;
		break;

		case B12B_EVENT_NAVAL_DONE:
			return true;
		break;

		case B12B_EVENT_RITUAL_SCENE:
			return true;
		break;

		case B12B_EVENT_PRIEST_FIGHT:
			return true;
		break;

		case B12B_EVENT_PRIESTS_DONE:
			return true;
		break;

		case B12B_EVENT_FINAL_REPORT:
			return true;
		break;

		case B12B_EVENT_WAR_TIMER_READY:
			return true;
		break;
	}

	return false;
}

void B12B_SetReloadEnabled(string locationId, string reloadId, bool enabled)
{
	int locIdx = FindLocation(locationId);

	if (locIdx < 0)
	{
		return;
	}

	Locations[locIdx].reload.(reloadId).disable = enabled ? 0 : 1;
}

void B12B_ApplyTravelLocks()
{
	string status = B12B_GetStatus();
	bool shoreEnabled = B12B_HasFleetDestroyed();
	bool caveEnabled = B12B_HasFleetDestroyed();
	bool ritualEnabled = B12B_IsRitualUnlockedStatus(status);

	if (!B12B_IsStarted())
	{
		return;
	}

	Island_SetReloadEnableLocal("IslaMuelle", "reload_2", shoreEnabled);
	B12B_SetReloadEnabled("Muelle_shore_02", "l1", caveEnabled);
	B12B_SetReloadEnabled("Muelle_shore_02", "l3", caveEnabled);
	B12B_SetReloadEnabled("Muelle_Cave", "l1", ritualEnabled);
}

void B12B_ResetFakeGuardPresentation()
{
	ref guard1;
	ref guard2;
	ref guard3;
	ref guard4;
	ref chief;

	guard1 = characterFromID(B12_NPC_GUARD1);
	guard2 = characterFromID(B12_NPC_GUARD2);
	guard3 = characterFromID(B12_NPC_GUARD3);
	guard4 = characterFromID(B12_NPC_GUARD4);
	chief = characterFromID(B12_NPC_GUARD_CHIEF);

	B12_SetModel(guard1, "offic_eng", "man");
	B12_SetModel(guard2, "offic_eng", "man");
	B12_SetModel(guard3, "offic_eng", "man");
	B12_SetModel(guard4, "offic_eng", "man");
	B12_SetModel(chief, "offic_eng", "man");

	B12_SetDialogFile(B12_NPC_GUARD1, B12_DIALOG_FILE_GUARD);
	B12_SetDialogFile(B12_NPC_GUARD2, B12_DIALOG_FILE_GUARD);
	B12_SetDialogFile(B12_NPC_GUARD3, B12_DIALOG_FILE_GUARD);
	B12_SetDialogFile(B12_NPC_GUARD4, B12_DIALOG_FILE_GUARD);
	B12_SetDialogFile(B12_NPC_GUARD_CHIEF, B12_DIALOG_FILE_GUARD_CHIEF);

	B12_SetDialogNode(B12_NPC_GUARD1, "First time");
	B12_SetDialogNode(B12_NPC_GUARD2, "First time");
	B12_SetDialogNode(B12_NPC_GUARD3, "First time");
	B12_SetDialogNode(B12_NPC_GUARD4, "First time");
	B12_SetDialogNode(B12_NPC_GUARD_CHIEF, "First time");

	LAi_SetGuardianType(guard1);
	LAi_SetGuardianType(guard2);
	LAi_SetGuardianType(guard3);
	LAi_SetGuardianType(guard4);
	LAi_SetGuardianType(chief);
}

void B12B_ClearNavalDeathHooks()
{
	ref pchar = GetMainCharacter();

	DeleteAttribute(pchar, "quest.PJ_B1_2B_NAVAL_CAPTAIN1_DEAD");
	DeleteAttribute(pchar, "quest.PJ_B1_2B_NAVAL_CAPTAIN2_DEAD");
}

void B12B_CleanupNavalDefense()
{
	B12B_ClearNavalDeathHooks();
	Group_DeleteGroup(B12B_GROUP_CAPTAINS);
	SetCharacterShipLocation(characterFromID(B12_NPC_CAPTAIN1), "none");
	SetCharacterShipLocation(characterFromID(B12_NPC_CAPTAIN2), "none");
	B11_HideNpc(B12_NPC_CAPTAIN1);
	B11_HideNpc(B12_NPC_CAPTAIN2);
}

bool B12B_AreNavalCaptainsDead()
{
	if (!B11_HasNpc(B12_NPC_CAPTAIN1) || !B11_HasNpc(B12_NPC_CAPTAIN2))
	{
		return false;
	}

	return LAi_IsDead(characterFromID(B12_NPC_CAPTAIN1)) && LAi_IsDead(characterFromID(B12_NPC_CAPTAIN2));
}

void B12B_PrepareNavalDefense()
{
	ref pchar = GetMainCharacter();
	ref captain1;
	ref captain2;

	if (B12B_HasFleetDestroyed())
	{
		return;
	}
	if (CheckAttribute(pchar, "quest_b1_2b_naval_prepared"))
	{
		return;
	}

	captain1 = characterFromID(B12_NPC_CAPTAIN1);
	captain2 = characterFromID(B12_NPC_CAPTAIN2);

	B12B_CleanupNavalDefense();
	B12_SetDialogFile(B12_NPC_CAPTAIN1, B12_DIALOG_FILE_CAPTAIN);
	B12_SetDialogFile(B12_NPC_CAPTAIN2, B12_DIALOG_FILE_CAPTAIN);
	B12_SetDialogNode(B12_NPC_CAPTAIN1, "B1_2B_captain");
	B12_SetDialogNode(B12_NPC_CAPTAIN2, "B1_2B_captain_repeat");

	captain1.nation = HOLLAND;
	captain1.Ship.Type = SHIP_FRIGATE_HOLLAND;
	SetBaseShipData(captain1);
	captain1.Ship.Name = "Furie de Shango";

	captain2.nation = HOLLAND;
	captain2.Ship.Type = SHIP_CORVETTE_HOLLAND;
	SetBaseShipData(captain2);
	captain2.Ship.Name = "Veilleur de Muelle";

	SetCharacterRelationBoth(GetCharacterIndex(B12_NPC_CAPTAIN1), GetMainCharacterIndex(), RELATION_ENEMY);
	SetCharacterRelationBoth(GetCharacterIndex(B12_NPC_CAPTAIN2), GetMainCharacterIndex(), RELATION_ENEMY);

	Group_CreateGroup(B12B_GROUP_CAPTAINS);
	Group_AddCharacter(B12B_GROUP_CAPTAINS, B12_NPC_CAPTAIN1);
	Group_AddCharacter(B12B_GROUP_CAPTAINS, B12_NPC_CAPTAIN2);
	Group_SetGroupCommander(B12B_GROUP_CAPTAINS, B12_NPC_CAPTAIN1);
	Group_SetTaskAttack(B12B_GROUP_CAPTAINS, PLAYER_GROUP);
	Group_SetPursuitGroup(B12B_GROUP_CAPTAINS, PLAYER_GROUP);
	Group_SetAddress(B12B_GROUP_CAPTAINS, "IslaMuelle", "Quest_Ships", "Quest_Ship_2");
	Group_LockTask(B12B_GROUP_CAPTAINS);

	pchar.quest.PJ_B1_2B_NAVAL_CAPTAIN1_DEAD.win_condition.l1 = "NPC_Death";
	pchar.quest.PJ_B1_2B_NAVAL_CAPTAIN1_DEAD.win_condition.l1.character = B12_NPC_CAPTAIN1;
	pchar.quest.PJ_B1_2B_NAVAL_CAPTAIN1_DEAD.win_condition = B12B_EVENT_NAVAL_DONE;

	pchar.quest.PJ_B1_2B_NAVAL_CAPTAIN2_DEAD.win_condition.l1 = "NPC_Death";
	pchar.quest.PJ_B1_2B_NAVAL_CAPTAIN2_DEAD.win_condition.l1.character = B12_NPC_CAPTAIN2;
	pchar.quest.PJ_B1_2B_NAVAL_CAPTAIN2_DEAD.win_condition = B12B_EVENT_NAVAL_DONE;

	pchar.quest_b1_2b_naval_prepared = true;
	Log_SetStringToLog("PJ B1.2b: naval defense prepared");
}

string B12B_GetStatus()
{
	ref pchar = GetMainCharacter();

	if (!CheckAttribute(pchar, "quest_b1_2b_status"))
	{
		return B12B_STATUS_NOT_STARTED;
	}
	if (pchar.quest_b1_2b_status == "")
	{
		return B12B_STATUS_NOT_STARTED;
	}
	return pchar.quest_b1_2b_status;
}

string B12B_GetPublishedStep(string status)
{
	if (status == "")
	{
		return B1_STEP_NONE;
	}

	switch (status)
	{
		case B12B_STATUS_NOT_STARTED:
			return B1_STEP_NONE;
		break;

		case B12B_STATUS_COMPLETED:
			return B1_STEP_COMPLETED;
		break;

		case B12B_STATUS_CLOSED:
			return B1_STEP_COMPLETED;
		break;
	}

	return status;
}

bool B12B_CanPublishToTransverseState()
{
	return !B1_IsAnotherSubquestActive(B12B_TRANS_SUBQUEST);
}

void B12B_PublishTransverseState(string status)
{
	string step = B12B_GetPublishedStep(status);

	if (step == B1_STEP_NONE)
	{
		return;
	}
	if (!B12B_CanPublishToTransverseState())
	{
		return;
	}

	B1_SetState(B12B_TRANS_SUBQUEST, step);
}

void B12B_SetStatus(string status)
{
	ref pchar = GetMainCharacter();

	pchar.quest_b1_2b_status = status;
	B12B_PublishTransverseState(status);
}

bool B12B_IsStarted()
{
	string status = B12B_GetStatus();

	switch (status)
	{
		case B12B_STATUS_NOT_STARTED:
			return false;
		break;

		case B12B_STATUS_CLOSED:
			return false;
		break;
	}

	return true;
}

bool B12B_IsCompleted()
{
	string status = B12B_GetStatus();

	switch (status)
	{
		case B12B_STATUS_COMPLETED:
			return true;
		break;

		case B12B_STATUS_CLOSED:
			return true;
		break;
	}

	return false;
}

bool B12B_IsTransverseActive()
{
	return B1_IsSubquestActive(B12B_TRANS_SUBQUEST);
}

bool B12B_IsTransverseCompleted()
{
	return B1_IsSubquestCompleted(B12B_TRANS_SUBQUEST);
}

void B12B_SyncTransverseState()
{
	B12B_PublishTransverseState(B12B_GetStatus());
}

int B12B_GetWitnessCount()
{
	ref pchar = GetMainCharacter();

	if (!CheckAttribute(pchar, "quest_b1_2b_douwesen_witnesses"))
	{
		return 0;
	}
	return sti(pchar.quest_b1_2b_douwesen_witnesses);
}

void B12B_SetWitnessCount(int count)
{
	ref pchar = GetMainCharacter();

	pchar.quest_b1_2b_douwesen_witnesses = count;
}

bool B12B_HasWitness(string witnessId)
{
	ref pchar = GetMainCharacter();
	string attrName = "quest_b1_2b_witness_" + witnessId;

	return CheckAttribute(pchar, attrName) && sti(pchar.(attrName)) == true;
}

void B12B_MarkWitness(string witnessId)
{
	ref pchar = GetMainCharacter();
	string attrName = "quest_b1_2b_witness_" + witnessId;

	pchar.(attrName) = true;
}

void B12B_ResetRuntime()
{
	ref pchar = GetMainCharacter();

	DeleteAttribute(pchar, "quest_b1_2b_malcolm_hint");
	DeleteAttribute(pchar, "quest_b1_2b_douwesen_witnesses");
	DeleteAttribute(pchar, "quest_b1_2b_witness_PJ_B1_2_DouwesenWitness1");
	DeleteAttribute(pchar, "quest_b1_2b_witness_PJ_B1_2_DouwesenWitness2");
	DeleteAttribute(pchar, "quest_b1_2b_witness_PJ_B1_2_DouwesenWitness3");
	DeleteAttribute(pchar, "quest_b1_2b_french_spy_met");
	DeleteAttribute(pchar, "quest_b1_2b_silehard_location_known");
	DeleteAttribute(pchar, "quest_b1_2b_fleet_destroyed");
	DeleteAttribute(pchar, "quest_b1_2b_priests_dead");
	DeleteAttribute(pchar, "quest_b1_2b_naval_scene_started");
	DeleteAttribute(pchar, "quest_b1_2b_ritual_scene_started");
	DeleteAttribute(pchar, "quest_b1_2b_naval_prepared");
	DeleteAttribute(pchar, "quest_b1_2b_war_timer_started");
	DeleteAttribute(pchar, "quest_b1_3_available");
	B12B_ClearNavalDeathHooks();
	B12B_CleanupNavalDefense();
	B12B_ResetFakeGuardPresentation();
	B12_HideCoreB12Npcs();
	B11_HideNpc(B12_NPC_SPY);
}

void B12B_SetSpyRagged()
{
	ref spy;

	if (!B11_HasNpc(B12_NPC_SPY))
	{
		return;
	}

	spy = characterFromID(B12_NPC_SPY);
	B12_SetModel(spy, "brodyaga", "man");
	B12_SetDialogFile(B12_NPC_SPY, B12_DIALOG_FILE_SPY);
	B12_SetDialogNode(B12_NPC_SPY, "B1_2B_ragged");
	B11_PlaceNpc(B12_NPC_SPY, "Douwesen_tavern", "goto");
	LAi_SetCitizenType(spy);
}

void B12B_SetSpyClean()
{
	ref spy;

	if (!B11_HasNpc(B12_NPC_SPY))
	{
		return;
	}

	spy = characterFromID(B12_NPC_SPY);
	B12_SetModel(spy, "chameleon", "man");
	B12_SetDialogFile(B12_NPC_SPY, B12_DIALOG_FILE_SPY);
	B12_SetDialogNode(B12_NPC_SPY, "B1_2B_clean");
	B11_PlaceNpc(B12_NPC_SPY, "Falaise_de_fleur_townhall", "goto");
	LAi_SetCitizenType(spy);
}

void B12B_SpawnDouwesenWitnesses()
{
	string status = B12B_GetStatus();

	if (!B12B_IsWitnessInquiryStatus(status))
	{
		B11_HideNpc(B12_NPC_WITNESS1);
		B11_HideNpc(B12_NPC_WITNESS2);
		B11_HideNpc(B12_NPC_WITNESS3);
		return;
	}

	B12_SetDialogFile(B12_NPC_WITNESS1, B12_DIALOG_FILE_WITNESS);
	B12_SetDialogFile(B12_NPC_WITNESS2, B12_DIALOG_FILE_WITNESS);
	B12_SetDialogFile(B12_NPC_WITNESS3, B12_DIALOG_FILE_WITNESS);
	B12_SetDialogNode(B12_NPC_WITNESS1, "First time");
	B12_SetDialogNode(B12_NPC_WITNESS2, "First time");
	B12_SetDialogNode(B12_NPC_WITNESS3, "First time");

	B11_PlaceNpc(B12_NPC_WITNESS1, "Douwesen_town", "goto");
	B11_PlaceNpc(B12_NPC_WITNESS2, "Douwesen_town", "goto");
	B11_PlaceNpc(B12_NPC_WITNESS3, "Douwesen_town", "goto");
	LAi_SetCitizenType(characterFromID(B12_NPC_WITNESS1));
	LAi_SetCitizenType(characterFromID(B12_NPC_WITNESS2));
	LAi_SetCitizenType(characterFromID(B12_NPC_WITNESS3));
}

void B12B_StartQuest()
{
	ref pchar = GetMainCharacter();

	if (B12B_IsStarted() || B12B_IsCompleted())
	{
		return;
	}

	B12B_ResetRuntime();
	DeleteQuestHeader(B12B_HEADER);
	SetQuestHeader(B12B_HEADER);
	AddQuestRecord(B12B_HEADER, "1");
	B12B_SetStatus(B12B_STATUS_DOUWESEN_INQUIRY);
	pchar.quest_b1_status = "b1_2b_started";
	B12B_SetSpyRagged();
	B12B_SpawnDouwesenWitnesses();
	Log_SetStringToLog("PJ B1.2b: investigation started");
}

void B12B_RecordMalcolmHint()
{
	ref pchar = GetMainCharacter();

	if (CheckAttribute(pchar, "quest_b1_2b_malcolm_hint"))
	{
		return;
	}

	pchar.quest_b1_2b_malcolm_hint = true;
	AddQuestRecord(B12B_HEADER, "2");
	Log_SetStringToLog("PJ B1.2b: Malcolm hint taken");
}

void B12B_RegisterWitness(string witnessId)
{
	int count;

	if (B12B_HasWitness(witnessId))
	{
		return;
	}

	B12B_MarkWitness(witnessId);
	count = B12B_GetWitnessCount() + 1;
	B12B_SetWitnessCount(count);

	if (count >= 3)
	{
		B12B_SetStatus(B12B_STATUS_FRENCH_GOVERNOR);
		AddQuestRecord(B12B_HEADER, "3");
		Log_SetStringToLog("PJ B1.2b: Douwesen inquiry complete");
	}
}

void B12B_GovernorRedirect()
{
	B12B_SetStatus(B12B_STATUS_FRENCH_SPY);
	AddQuestRecord(B12B_HEADER, "4");
	B12B_SetSpyClean();
	Log_SetStringToLog("PJ B1.2b: french governor redirected to spy");
}

void B12B_SpyBriefingComplete()
{
	ref pchar = GetMainCharacter();

	pchar.quest_b1_2b_french_spy_met = true;
	B12B_SetStatus(B12B_STATUS_RETURN_SILEHARD);
	AddQuestRecord(B12B_HEADER, "5");
	Log_SetStringToLog("PJ B1.2b: spy delivered Isla Muelle lead");
}

void B12B_SilehardDestination()
{
	ref pchar = GetMainCharacter();

	pchar.quest_b1_2b_silehard_location_known = true;
	B12B_SetStatus(B12B_STATUS_NAVAL_ASSAULT);
	AddQuestRecord(B12B_HEADER, "6");
	AddQuestRecord(B12B_HEADER, "7");
	B12B_PrepareNavalDefense();
	B12B_ApplyTravelLocks();
	Log_SetStringToLog("PJ B1.2b: Silehard named shore and cave");
}

void B12B_StartNavalScene()
{
	if (B12B_GetStatus() != B12B_STATUS_NAVAL_ASSAULT)
	{
		return;
	}
	if (B12B_HasFleetDestroyed())
	{
		return;
	}

	B12B_PrepareNavalDefense();
	Log_SetStringToLog("Une fregate et une corvette hollandaises barrent l'acces a la Cote eloignee.");
}

void B12B_StartNavalFight()
{
	B12B_StartNavalScene();
}

void B12B_FinishNavalFight()
{
	ref pchar = GetMainCharacter();

	if (B12B_HasFleetDestroyed())
	{
		return;
	}
	if (!B12B_AreNavalCaptainsDead())
	{
		return;
	}

	pchar.quest_b1_2b_fleet_destroyed = true;
	DeleteAttribute(pchar, "quest_b1_2b_naval_prepared");
	B12B_SetStatus(B12B_STATUS_RITUAL_CAVE);
	AddQuestRecord(B12B_HEADER, "8");
	B12B_CleanupNavalDefense();
	B12B_ApplyTravelLocks();
	Log_SetStringToLog("PJ B1.2b: bay defense destroyed");
}

void B12B_PreparePriests()
{
	ref guard1;
	ref guard2;
	ref guard3;
	ref guard4;
	ref chief;

	guard1 = characterFromID(B12_NPC_GUARD1);
	guard2 = characterFromID(B12_NPC_GUARD2);
	guard3 = characterFromID(B12_NPC_GUARD3);
	guard4 = characterFromID(B12_NPC_GUARD4);
	chief = characterFromID(B12_NPC_GUARD_CHIEF);

	B12_SetModel(guard1, "animists2", "man");
	B12_SetModel(guard2, "animists2", "man");
	B12_SetModel(guard3, "animists2", "man");
	B12_SetModel(guard4, "animists2", "man");
	B12_SetModel(chief, "animists2", "man");

	B12_SetDialogFile(B12_NPC_GUARD1, B12_DIALOG_FILE_PRIEST);
	B12_SetDialogFile(B12_NPC_GUARD2, B12_DIALOG_FILE_PRIEST);
	B12_SetDialogFile(B12_NPC_GUARD3, B12_DIALOG_FILE_PRIEST);
	B12_SetDialogFile(B12_NPC_GUARD4, B12_DIALOG_FILE_PRIEST);
	B12_SetDialogFile(B12_NPC_GUARD_CHIEF, B12_DIALOG_FILE_PRIEST_CHIEF);

	B12_SetDialogNode(B12_NPC_GUARD1, "B1_2B_priest");
	B12_SetDialogNode(B12_NPC_GUARD2, "B1_2B_priest");
	B12_SetDialogNode(B12_NPC_GUARD3, "B1_2B_priest");
	B12_SetDialogNode(B12_NPC_GUARD4, "B1_2B_priest");
	B12_SetDialogNode(B12_NPC_GUARD_CHIEF, "B1_2B_priest_chief");

	B11_PlaceNpc(B12_NPC_GUARD1, "Muelle_ANIMISTS", "goto");
	B11_PlaceNpc(B12_NPC_GUARD2, "Muelle_ANIMISTS", "goto");
	B11_PlaceNpc(B12_NPC_GUARD3, "Muelle_ANIMISTS", "goto");
	B11_PlaceNpc(B12_NPC_GUARD4, "Muelle_ANIMISTS", "goto");
	B11_PlaceNpc(B12_NPC_GUARD_CHIEF, "Muelle_ANIMISTS", "goto");

	LAi_SetGuardianType(guard1);
	LAi_SetGuardianType(guard2);
	LAi_SetGuardianType(guard3);
	LAi_SetGuardianType(guard4);
	LAi_SetActorType(chief);
}

void B12B_StartRitualScene()
{
	ref pchar = GetMainCharacter();

	if (CheckAttribute(pchar, "quest_b1_2b_ritual_scene_started"))
	{
		return;
	}

	pchar.quest_b1_2b_ritual_scene_started = true;
	AddQuestRecord(B12B_HEADER, "9");
	B12B_PreparePriests();
	LAi_LockFightMode(pchar, true);
	LAi_ActorDialog(characterFromID(B12_NPC_GUARD_CHIEF), pchar, "", 12.0, 1.0);
}

void B12B_StartPriestFight()
{
	LAi_LockFightMode(GetMainCharacter(), false);
	LAi_SetWarriorType(characterFromID(B12_NPC_GUARD_CHIEF));
	LAi_SetWarriorType(characterFromID(B12_NPC_GUARD1));
	LAi_SetWarriorType(characterFromID(B12_NPC_GUARD2));
	LAi_SetWarriorType(characterFromID(B12_NPC_GUARD3));
	LAi_SetWarriorType(characterFromID(B12_NPC_GUARD4));

	LAi_group_MoveCharacter(characterFromID(B12_NPC_GUARD_CHIEF), B12B_GROUP_PRIESTS);
	LAi_group_MoveCharacter(characterFromID(B12_NPC_GUARD1), B12B_GROUP_PRIESTS);
	LAi_group_MoveCharacter(characterFromID(B12_NPC_GUARD2), B12B_GROUP_PRIESTS);
	LAi_group_MoveCharacter(characterFromID(B12_NPC_GUARD3), B12B_GROUP_PRIESTS);
	LAi_group_MoveCharacter(characterFromID(B12_NPC_GUARD4), B12B_GROUP_PRIESTS);

	LAi_group_SetCheck(B12B_GROUP_PRIESTS, B12B_EVENT_PRIESTS_DONE);
	LAi_group_FightGroups(B12B_GROUP_PRIESTS, LAI_GROUP_PLAYER, true);
}

void B12B_FinishPriestFight()
{
	ref pchar = GetMainCharacter();

	pchar.quest_b1_2b_priests_dead = true;
	B12B_SetStatus(B12B_STATUS_PRIESTS_DEAD);
	AddQuestRecord(B12B_HEADER, "10");
	B12B_ResetFakeGuardPresentation();
	B12_HideCoreB12Npcs();
	LAi_LockFightMode(pchar, false);
	B12B_ApplyTravelLocks();
	Log_SetStringToLog("PJ B1.2b: priests eliminated");
}

void B12B_FinalReport()
{
	ref pchar = GetMainCharacter();

	AddQuestRecord(B12B_HEADER, "11");
	AddQuestRecord(B12B_HEADER, "12");
	CloseQuestHeader(B12B_HEADER);
	B12B_SetStatus(B12B_STATUS_CLOSED);
	pchar.quest_b1_status = "b1_2b_completed";
	pchar.quest_b1_2b_war_timer_started = true;
	B12B_CleanupNavalDefense();
	B12B_ResetFakeGuardPresentation();
	B12_HideCoreB12Npcs();
	B11_HideNpc(B12_NPC_SPY);
	B12B_ApplyTravelLocks();
	pchar.quest.PJ_B1_2B_WAR_TIMER.win_condition.l1 = "Timer";
	pchar.quest.PJ_B1_2B_WAR_TIMER.win_condition.l1.date.day = GetAddingDataDay(0, 0, 14);
	pchar.quest.PJ_B1_2B_WAR_TIMER.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 14);
	pchar.quest.PJ_B1_2B_WAR_TIMER.win_condition.l1.date.year = GetAddingDataYear(0, 0, 14);
	pchar.quest.PJ_B1_2B_WAR_TIMER.win_condition = B12B_EVENT_WAR_TIMER_READY;
	Log_SetStringToLog("PJ B1.2b: war timer started");
}

void B12B_WarTimerReady()
{
	ref pchar = GetMainCharacter();

	pchar.quest_b1_3_available = "yes";
	pchar.quest_b1_status = "b1_3_available";
	Log_SetStringToLog("PJ B1.3 available");
}

void B1_2B_UpdateQuestTracker()
{
	ref pchar = GetMainCharacter();
	string status = B12B_GetStatus();

	B12B_SyncTransverseState();

	if (!B12B_IsStarted() || B12B_IsCompleted())
	{
		return;
	}
	if (B1_IsAnotherSubquestActive(B12B_TRANS_SUBQUEST))
	{
		return;
	}

	pchar.quest_in_progress = B12B_HEADER;
	pchar.quest_in_progress_step = status;
}

void B1_2B_EnforceState()
{
	string status = B12B_GetStatus();

	B12B_SyncTransverseState();

	if (!B12B_IsStarted() || B12B_IsCompleted())
	{
		return;
	}

	B12B_ApplyTravelLocks();

	if (B12B_IsWitnessInquiryStatus(status))
	{
		B12B_SpawnDouwesenWitnesses();
		B12B_SetSpyRagged();
	}
	if (B12B_IsSpyCleanStatus(status))
	{
		B12B_SpawnDouwesenWitnesses();
		B12B_SetSpyClean();
	}
	if (status == B12B_STATUS_NAVAL_ASSAULT)
	{
		if (!B12B_HasFleetDestroyed())
		{
			B12B_PrepareNavalDefense();
		}
	}
}

void B1_2B_ProcessLocationEnter()
{
	ref pchar = GetMainCharacter();
	string status = B12B_GetStatus();

	B12B_SyncTransverseState();

	if (B12B_IsWitnessInquiryStatus(status))
	{
		B12B_SpawnDouwesenWitnesses();
		B12B_SetSpyRagged();
	}
	if (status == B12B_STATUS_NAVAL_ASSAULT)
	{
		B12B_PrepareNavalDefense();

		if (pchar.location == "Muelle_shore_02")
		{
			Log_SetStringToLog("La baie n'est pas encore sure. Il faut d'abord couler la fregate et la corvette.");
		}
		if (pchar.location == "Muelle_Cave")
		{
			Log_SetStringToLog("La grotte devra attendre. Il faut d'abord balayer la defense navale.");
		}
		if (pchar.location == "Muelle_ANIMISTS")
		{
			Log_SetStringToLog("Le rite est encore protege par la baie. Reprenez la mer.");
		}
	}
	if (status == B12B_STATUS_RITUAL_CAVE)
	{
		if (pchar.location == "Muelle_ANIMISTS")
		{
			QuestComplete_B1_2B(B12B_EVENT_RITUAL_SCENE);
		}
	}
}

bool QuestComplete_B1_2B(string sQuestName)
{
	B12B_SyncTransverseState();

	if (!B12B_IsRecognizedEvent(sQuestName) && B1_IsAnotherSubquestActive(B12B_TRANS_SUBQUEST))
	{
		return false;
	}

	switch (sQuestName)
	{
		case B12B_EVENT_MALCOLM_HINT:
			B12B_RecordMalcolmHint();
			return true;
		break;

		case B12B_EVENT_WITNESS1:
			B12B_RegisterWitness(B12_NPC_WITNESS1);
			return true;
		break;

		case B12B_EVENT_WITNESS2:
			B12B_RegisterWitness(B12_NPC_WITNESS2);
			return true;
		break;

		case B12B_EVENT_WITNESS3:
			B12B_RegisterWitness(B12_NPC_WITNESS3);
			return true;
		break;

		case B12B_EVENT_FRENCH_GOVERNOR:
			B12B_GovernorRedirect();
			return true;
		break;

		case B12B_EVENT_FRENCH_SPY:
			B12B_SpyBriefingComplete();
			return true;
		break;

		case B12B_EVENT_SILEHARD_DESTINATION:
			B12B_SilehardDestination();
			return true;
		break;

		case B12B_EVENT_NAVAL_SCENE:
			B12B_StartNavalScene();
			return true;
		break;

		case B12B_EVENT_NAVAL_FIGHT:
			B12B_StartNavalFight();
			return true;
		break;

		case B12B_EVENT_NAVAL_DONE:
			B12B_FinishNavalFight();
			return true;
		break;

		case B12B_EVENT_RITUAL_SCENE:
			B12B_StartRitualScene();
			return true;
		break;

		case B12B_EVENT_PRIEST_FIGHT:
			B12B_StartPriestFight();
			return true;
		break;

		case B12B_EVENT_PRIESTS_DONE:
			B12B_FinishPriestFight();
			return true;
		break;

		case B12B_EVENT_FINAL_REPORT:
			B12B_FinalReport();
			return true;
		break;

		case B12B_EVENT_WAR_TIMER_READY:
			B12B_WarTimerReady();
			return true;
		break;
	}

	return false;
}
