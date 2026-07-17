// B1.1 - Les Fils de l'Ombre d'Inty

#define B11_HEADER "PJ_B1_1"

#define B11_STATUS_NOT_STARTED "not_started"
#define B11_STATUS_INTRO_COLLECT "intro_collect"
#define B11_STATUS_INTRO_READY_REPORT "intro_ready_report"
#define B11_STATUS_MUELLE_PENDING "muelle_pending"
#define B11_STATUS_CONCEICAO_PENDING "conceicao_pending"
#define B11_STATUS_DOUWESEN_PENDING "douwesen_pending"
#define B11_STATUS_JUNGLE_CLUE_PENDING "jungle_clue_pending"
#define B11_STATUS_DIG_READY "dig_ready"
#define B11_STATUS_FINAL_READY "final_ready"
#define B11_STATUS_COMPLETED "completed"
#define B11_STATUS_CLOSED "closed"

#define B11_MUELLE_STATE_PENDING "pending"
#define B11_MUELLE_STATE_WAIT "wait"
#define B11_MUELLE_STATE_SHIP_OFFER "ship_offer"
#define B11_MUELLE_STATE_DONE "done"

#define B11_CONCEICAO_STATE_PENDING "pending"
#define B11_CONCEICAO_STATE_WAIT "wait"
#define B11_CONCEICAO_STATE_SHIP_OFFER "ship_offer"
#define B11_CONCEICAO_STATE_DONE "done"

#define B11_DOUWESEN_STATE_PENDING "pending"
#define B11_DOUWESEN_STATE_DONE "done"

#define B11_LOCATION_REDMOND "Redmond_Residence"
#define B11_LOCATION_MUELLE "Muelle_shore_02"
#define B11_LOCATION_CONCEICAO "Conceicao_shore_01"
#define B11_LOCATION_DOUWESEN "Douwesen_shore_01"
#define B11_LOCATION_JUNGLE "Douwesen_Jungle_03"

#define B11_NPC_MUELLE_ENGLISH "PJ_B1_1_EnglishContact_Muelle"
#define B11_NPC_MUELLE_GUARD "PJ_B1_1_SpanishGuard_Muelle"
#define B11_NPC_CONCEICAO_ENGLISH "PJ_B1_1_EnglishContact_Conceicao"
#define B11_NPC_CONCEICAO_GUARD "PJ_B1_1_PortugueseGuard_Conceicao"
#define B11_NPC_DOUWESEN_ENGLISH "PJ_B1_1_EnglishContact_Douwesen"
#define B11_NPC_DOUWESEN_DUTCH "PJ_B1_1_DutchContact_Douwesen"

#define B11_DIALOG_FILE "Robert Christopher Silehard PJ_dialog.c"

#define B11_ITEM_FEET "PJ_B1_1_STATUE_FEET"
#define B11_ITEM_BODY "PJ_B1_1_STATUE_BODY"
#define B11_ITEM_ARMS "PJ_B1_1_STATUE_ARMS"
#define B11_ITEM_HEAD "PJ_B1_1_STATUE_HEAD"
#define B11_ITEM_FULL "PJ_B1_1_STATUE_FULL"

#define B11_EVENT_START "PJ_B1_1_START"
#define B11_EVENT_INTRO_ITEMS_COMPLETE "PJ_B1_1_INTRO_ITEMS_COMPLETE"
#define B11_EVENT_INTRO_REPORT_COMPLETE "PJ_B1_1_INTRO_REPORT_COMPLETE"
#define B11_EVENT_MUELLE_SPAIN_FIRST "PJ_B1_1_MUELLE_SPAIN_FIRST"
#define B11_EVENT_MUELLE_CONTACT_SHIP "PJ_B1_1_MUELLE_CONTACT_SHIP"
#define B11_EVENT_MUELLE_RETURN "PJ_B1_1_MUELLE_RETURN"
#define B11_EVENT_MUELLE_PIECE_OBTAINED "PJ_B1_1_MUELLE_PIECE_OBTAINED"
#define B11_EVENT_CONCEICAO_PORTUGAL_FIRST "PJ_B1_1_CONCEICAO_PORTUGAL_FIRST"
#define B11_EVENT_CONCEICAO_CONTACT_SHIP "PJ_B1_1_CONCEICAO_CONTACT_SHIP"
#define B11_EVENT_CONCEICAO_RETURN "PJ_B1_1_CONCEICAO_RETURN"
#define B11_EVENT_CONCEICAO_PIECE_OBTAINED "PJ_B1_1_CONCEICAO_PIECE_OBTAINED"
#define B11_EVENT_DOUWESEN_ARMS_OBTAINED "PJ_B1_1_DOUWESEN_ARMS_OBTAINED"
#define B11_EVENT_JUNGLE_HINT_FOUND "PJ_B1_1_JUNGLE_HINT_FOUND"
#define B11_EVENT_DIG_COMPLETED "PJ_B1_1_DIG_COMPLETED"
#define B11_EVENT_HEAD_OBTAINED "PJ_B1_1_HEAD_OBTAINED"
#define B11_EVENT_ASSEMBLE_FULL_STATUE "PJ_B1_1_ASSEMBLE_FULL_STATUE"
#define B11_EVENT_FINAL_REPORT_COMPLETE "PJ_B1_1_FINAL_REPORT_COMPLETE"
#define B11_EVENT_CLEANUP "PJ_B1_1_CLEANUP"

string B11_GetStatus()
{
	ref pchar = GetMainCharacter();
	if (!CheckAttribute(pchar, "quest_b1_1_status"))
	{
		return B11_STATUS_NOT_STARTED;
	}
	return pchar.quest_b1_1_status;
}

void B11_SetStatus(string status)
{
	ref pchar = GetMainCharacter();
	pchar.quest_b1_1_status = status;
}

string B11_GetMuelleState()
{
	ref pchar = GetMainCharacter();
	if (!CheckAttribute(pchar, "quest_b1_1_muelle_state"))
	{
		return "";
	}
	return pchar.quest_b1_1_muelle_state;
}

void B11_SetMuelleState(string state)
{
	ref pchar = GetMainCharacter();
	pchar.quest_b1_1_muelle_state = state;
}

string B11_GetConceicaoState()
{
	ref pchar = GetMainCharacter();
	if (!CheckAttribute(pchar, "quest_b1_1_conceicao_state"))
	{
		return "";
	}
	return pchar.quest_b1_1_conceicao_state;
}

void B11_SetConceicaoState(string state)
{
	ref pchar = GetMainCharacter();
	pchar.quest_b1_1_conceicao_state = state;
}

string B11_GetDouwesenState()
{
	ref pchar = GetMainCharacter();
	if (!CheckAttribute(pchar, "quest_b1_1_douwesen_state"))
	{
		return "";
	}
	return pchar.quest_b1_1_douwesen_state;
}

void B11_SetDouwesenState(string state)
{
	ref pchar = GetMainCharacter();
	pchar.quest_b1_1_douwesen_state = state;
}

bool B11_IsStarted()
{
	string status = B11_GetStatus();
	return status != B11_STATUS_NOT_STARTED && status != B11_STATUS_CLOSED;
}

bool B11_IsCompleted()
{
	string status = B11_GetStatus();
	return status == B11_STATUS_COMPLETED || status == B11_STATUS_CLOSED;
}

int B11_GetNpcIndex(string npcId)
{
	return GetCharacterIndex(npcId);
}

bool B11_HasNpc(string npcId)
{
	return B11_GetNpcIndex(npcId) >= 0;
}

void B11_HideNpc(string npcId)
{
	if (!B11_HasNpc(npcId))
	{
		return;
	}
	ChangeCharacterAddress(characterFromID(npcId), "none", "");
}

void B11_PlaceNpc(string npcId, string location, string group)
{
	if (!B11_HasNpc(npcId))
	{
		return;
	}
	PlaceCharacter(characterFromID(npcId), group, location);
}

void B11_SetNpcCitizen(string npcId)
{
	if (!B11_HasNpc(npcId))
	{
		return;
	}
	LAi_SetCitizenType(characterFromID(npcId));
}

void B11_SetNpcGuardian(string npcId)
{
	if (!B11_HasNpc(npcId))
	{
		return;
	}
	LAi_SetGuardianType(characterFromID(npcId));
}

void B11_AssignDialog(string npcId, string nodeName)
{
	ref chref;

	if (!B11_HasNpc(npcId))
	{
		return;
	}

	chref = characterFromID(npcId);
	chref.Dialog.Filename = B11_DIALOG_FILE;
	chref.Dialog.CurrentNode = nodeName;
	chref.Dialog.TempNode = nodeName;
}

void B11_DespawnAllSceneNpcs()
{
	B11_HideNpc(B11_NPC_MUELLE_ENGLISH);
	B11_HideNpc(B11_NPC_MUELLE_GUARD);
	B11_HideNpc(B11_NPC_CONCEICAO_ENGLISH);
	B11_HideNpc(B11_NPC_CONCEICAO_GUARD);
	B11_HideNpc(B11_NPC_DOUWESEN_ENGLISH);
	B11_HideNpc(B11_NPC_DOUWESEN_DUTCH);
}

void B11_SpawnMuelleScene()
{
	if (B11_GetMuelleState() == B11_MUELLE_STATE_DONE)
	{
		return;
	}

	B11_PlaceNpc(B11_NPC_MUELLE_GUARD, B11_LOCATION_MUELLE, "goto");
	B11_SetNpcGuardian(B11_NPC_MUELLE_GUARD);
	B11_AssignDialog(B11_NPC_MUELLE_GUARD, "B1_1_muelle_guard");

	if (B11_GetMuelleState() != B11_MUELLE_STATE_WAIT)
	{
		B11_PlaceNpc(B11_NPC_MUELLE_ENGLISH, B11_LOCATION_MUELLE, "goto");
		B11_SetNpcCitizen(B11_NPC_MUELLE_ENGLISH);
		if (B11_GetMuelleState() == B11_MUELLE_STATE_SHIP_OFFER)
		{
			B11_AssignDialog(B11_NPC_MUELLE_ENGLISH, "B1_1_muelle_contact_ship");
		}
		else
		{
			B11_AssignDialog(B11_NPC_MUELLE_ENGLISH, "B1_1_muelle_contact");
		}
	}
}

void B11_SpawnConceicaoScene()
{
	if (B11_GetConceicaoState() == B11_CONCEICAO_STATE_DONE)
	{
		return;
	}

	B11_PlaceNpc(B11_NPC_CONCEICAO_GUARD, B11_LOCATION_CONCEICAO, "goto");
	B11_SetNpcGuardian(B11_NPC_CONCEICAO_GUARD);
	B11_AssignDialog(B11_NPC_CONCEICAO_GUARD, "B1_1_conceicao_guard");

	if (B11_GetConceicaoState() != B11_CONCEICAO_STATE_WAIT)
	{
		B11_PlaceNpc(B11_NPC_CONCEICAO_ENGLISH, B11_LOCATION_CONCEICAO, "goto");
		B11_SetNpcCitizen(B11_NPC_CONCEICAO_ENGLISH);
		if (B11_GetConceicaoState() == B11_CONCEICAO_STATE_SHIP_OFFER)
		{
			B11_AssignDialog(B11_NPC_CONCEICAO_ENGLISH, "B1_1_conceicao_contact_ship");
		}
		else
		{
			B11_AssignDialog(B11_NPC_CONCEICAO_ENGLISH, "B1_1_conceicao_contact");
		}
	}
}

void B11_SpawnDouwesenScene()
{
	if (B11_GetDouwesenState() == B11_DOUWESEN_STATE_DONE)
	{
		return;
	}

	B11_PlaceNpc(B11_NPC_DOUWESEN_ENGLISH, B11_LOCATION_DOUWESEN, "goto");
	B11_SetNpcCitizen(B11_NPC_DOUWESEN_ENGLISH);
	B11_AssignDialog(B11_NPC_DOUWESEN_ENGLISH, "B1_1_douwesen_english");
	B11_PlaceNpc(B11_NPC_DOUWESEN_DUTCH, B11_LOCATION_DOUWESEN, "goto");
	B11_SetNpcCitizen(B11_NPC_DOUWESEN_DUTCH);
	B11_AssignDialog(B11_NPC_DOUWESEN_DUTCH, "B1_1_douwesen_dutch");
}

void B11_DisarmMuelleTimer()
{
	ref pchar = GetMainCharacter();
	pchar.quest.PJ_B1_1_MUELLE_RETURN.over = "yes";
}

void B11_DisarmConceicaoTimer()
{
	ref pchar = GetMainCharacter();
	pchar.quest.PJ_B1_1_CONCEICAO_RETURN.over = "yes";
}

void B11_DisarmAllQuestConditions()
{
	B11_DisarmMuelleTimer();
	B11_DisarmConceicaoTimer();
}

void B11_ArmMuelleTimer()
{
	ref pchar = GetMainCharacter();
	B11_DisarmMuelleTimer();
	pchar.quest.PJ_B1_1_MUELLE_RETURN.win_condition.l1 = "Timer";
	pchar.quest.PJ_B1_1_MUELLE_RETURN.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
	pchar.quest.PJ_B1_1_MUELLE_RETURN.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
	pchar.quest.PJ_B1_1_MUELLE_RETURN.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
	pchar.quest.PJ_B1_1_MUELLE_RETURN.win_condition = B11_EVENT_MUELLE_RETURN;
}

void B11_ArmConceicaoTimer()
{
	ref pchar = GetMainCharacter();
	B11_DisarmConceicaoTimer();
	pchar.quest.PJ_B1_1_CONCEICAO_RETURN.win_condition.l1 = "Timer";
	pchar.quest.PJ_B1_1_CONCEICAO_RETURN.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
	pchar.quest.PJ_B1_1_CONCEICAO_RETURN.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
	pchar.quest.PJ_B1_1_CONCEICAO_RETURN.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
	pchar.quest.PJ_B1_1_CONCEICAO_RETURN.win_condition = B11_EVENT_CONCEICAO_RETURN;
}

string B11_GetIntroItemId(int index)
{
	switch (index)
	{
		case 1: return "indian1"; break;
		case 2: return "indian2"; break;
		case 3: return "indian3"; break;
		case 4: return "indian4"; break;
		case 5: return "indian5"; break;
		case 6: return "indian6"; break;
		case 7: return "indian7"; break;
		case 8: return "indian8"; break;
		case 9: return "indian9"; break;
		case 10: return "indian10"; break;
		case 11: return "indian11"; break;
		case 12: return "indian12"; break;
		case 13: return "indian13"; break;
		case 14: return "indian14"; break;
		case 15: return "indian15"; break;
		case 16: return "indian16"; break;
	}
	return "";
}

bool B11_HasAllIntroItems()
{
	ref pchar = GetMainCharacter();
	int i;
	string itemId;

	for (i = 1; i <= 16; i++)
	{
		itemId = B11_GetIntroItemId(i);
		if (!CheckCharacterItem(pchar, itemId))
		{
			return false;
		}
	}
	return true;
}

void B11_RemoveAllIntroItems()
{
	ref pchar = GetMainCharacter();
	int i;
	string itemId;

	for (i = 1; i <= 16; i++)
	{
		itemId = B11_GetIntroItemId(i);
		if (CheckCharacterItem(pchar, itemId))
		{
			TakeItemFromCharacter(pchar, itemId);
		}
	}
}

bool B11_HasPieceFeet()
{
	return CheckCharacterItem(GetMainCharacter(), B11_ITEM_FEET);
}

bool B11_HasPieceBody()
{
	return CheckCharacterItem(GetMainCharacter(), B11_ITEM_BODY);
}

bool B11_HasPieceArms()
{
	return CheckCharacterItem(GetMainCharacter(), B11_ITEM_ARMS);
}

bool B11_HasPieceHead()
{
	return CheckCharacterItem(GetMainCharacter(), B11_ITEM_HEAD);
}

bool B11_HasAllPieces()
{
	return B11_HasPieceFeet() && B11_HasPieceBody() && B11_HasPieceArms() && B11_HasPieceHead();
}

bool B11_HasFullStatue()
{
	return CheckCharacterItem(GetMainCharacter(), B11_ITEM_FULL);
}

void B11_RemoveAllPieces()
{
	ref pchar = GetMainCharacter();

	if (B11_HasPieceFeet()) { TakeItemFromCharacter(pchar, B11_ITEM_FEET); }
	if (B11_HasPieceBody()) { TakeItemFromCharacter(pchar, B11_ITEM_BODY); }
	if (B11_HasPieceArms()) { TakeItemFromCharacter(pchar, B11_ITEM_ARMS); }
	if (B11_HasPieceHead()) { TakeItemFromCharacter(pchar, B11_ITEM_HEAD); }
}

void B11_GrantPieceIfMissing(string itemId, string attrName)
{
	ref pchar = GetMainCharacter();
	if (!CheckAttribute(pchar, attrName))
	{
		GiveItem2Character(pchar, itemId);
		pchar.(attrName) = "1";
	}
}

void B11_PayIntroReward()
{
	ref pchar = GetMainCharacter();
	if (CheckAttribute(pchar, "quest_b1_1_intro_reward_paid"))
	{
		return;
	}
	AddMoneyToCharacter(pchar, 3000);
	AddPartyExp(pchar, 3000 * makeint(pchar.rank));
	pchar.quest_b1_1_intro_reward_paid = "1";
}

void B11_PayFinalReward()
{
	ref pchar = GetMainCharacter();
	if (CheckAttribute(pchar, "quest_b1_1_final_reward_paid"))
	{
		return;
	}
	AddMoneyToCharacter(pchar, 8000);
	AddPartyExp(pchar, 8000 * makeint(pchar.rank));
	pchar.quest_b1_1_final_reward_paid = "1";
}

void B11_SetArcRunning()
{
	ref pchar = GetMainCharacter();
	pchar.quest_b1_status = "b1_1_started";
}

void B11_SetArcCompleted()
{
	ref pchar = GetMainCharacter();
	pchar.quest_b1_status = "b1_1_completed";
	pchar.quest_b1_2a_available = "yes";
}

void B11_ResetRuntime()
{
	ref pchar = GetMainCharacter();

	DeleteAttribute(pchar, "quest_b1_1_intro_reward_paid");
	DeleteAttribute(pchar, "quest_b1_1_final_reward_paid");
	DeleteAttribute(pchar, "quest_b1_1_hint_found");
	DeleteAttribute(pchar, "quest_b1_1_dig_done");
	DeleteAttribute(pchar, "quest_b1_1_piece_feet");
	DeleteAttribute(pchar, "quest_b1_1_piece_body");
	DeleteAttribute(pchar, "quest_b1_1_piece_arms");
	DeleteAttribute(pchar, "quest_b1_1_piece_head");
	DeleteAttribute(pchar, "quest_b1_1_muelle_state");
	DeleteAttribute(pchar, "quest_b1_1_conceicao_state");
	DeleteAttribute(pchar, "quest_b1_1_douwesen_state");
	DeleteAttribute(pchar, "quest_b1_2a_available");
}

void B11_StartQuest()
{
	ref pchar = GetMainCharacter();

	B11_DisarmAllQuestConditions();
	B11_DespawnAllSceneNpcs();
	B11_ResetRuntime();
	B11_SetArcRunning();
	B11_SetStatus(B11_STATUS_INTRO_COLLECT);
	DeleteQuestHeader(B11_HEADER);
	SetQuestHeader(B11_HEADER);
	AddQuestRecord(B11_HEADER, "1");
	AddQuestRecord(B11_HEADER, "2");
	Log_SetStringToLog("PJ B1.1: intro accepted");
}

void B11_AdvanceToIntroReadyReport()
{
	if (B11_GetStatus() != B11_STATUS_INTRO_COLLECT)
	{
		return;
	}
	if (!B11_HasAllIntroItems())
	{
		return;
	}
	B11_SetStatus(B11_STATUS_INTRO_READY_REPORT);
	AddQuestRecord(B11_HEADER, "3");
	Log_SetStringToLog("PJ B1.1: intro objects complete");
}

void B11_AdvanceToMuelle()
{
	B11_RemoveAllIntroItems();
	B11_PayIntroReward();
	B11_SetStatus(B11_STATUS_MUELLE_PENDING);
	B11_SetMuelleState(B11_MUELLE_STATE_PENDING);
	AddQuestRecord(B11_HEADER, "4");
}

void B11_AdvanceToConceicao()
{
	B11_SetMuelleState(B11_MUELLE_STATE_DONE);
	B11_HideNpc(B11_NPC_MUELLE_ENGLISH);
	B11_HideNpc(B11_NPC_MUELLE_GUARD);
	B11_SetStatus(B11_STATUS_CONCEICAO_PENDING);
	B11_SetConceicaoState(B11_CONCEICAO_STATE_PENDING);
	AddQuestRecord(B11_HEADER, "7");
	Log_SetStringToLog("PJ B1.1: muelle piece obtained");
}

void B11_AdvanceToDouwesen()
{
	B11_SetConceicaoState(B11_CONCEICAO_STATE_DONE);
	B11_HideNpc(B11_NPC_CONCEICAO_ENGLISH);
	B11_HideNpc(B11_NPC_CONCEICAO_GUARD);
	B11_SetStatus(B11_STATUS_DOUWESEN_PENDING);
	B11_SetDouwesenState(B11_DOUWESEN_STATE_PENDING);
	AddQuestRecord(B11_HEADER, "10");
	Log_SetStringToLog("PJ B1.1: conceicao piece obtained");
}

void B11_AdvanceToJungle()
{
	B11_SetDouwesenState(B11_DOUWESEN_STATE_DONE);
	B11_HideNpc(B11_NPC_DOUWESEN_ENGLISH);
	B11_HideNpc(B11_NPC_DOUWESEN_DUTCH);
	B11_SetStatus(B11_STATUS_JUNGLE_CLUE_PENDING);
	AddQuestRecord(B11_HEADER, "11");
	Log_SetStringToLog("PJ B1.1: douwesen clue obtained");
}

void B11_AdvanceToDigReady()
{
	ref pchar = GetMainCharacter();
	if (CheckAttribute(pchar, "quest_b1_1_hint_found"))
	{
		return;
	}
	pchar.quest_b1_1_hint_found = "1";
	B11_SetStatus(B11_STATUS_DIG_READY);
	AddQuestRecord(B11_HEADER, "12");
}

void B11_AdvanceToFinalReady()
{
	B11_SetStatus(B11_STATUS_FINAL_READY);
	AddQuestRecord(B11_HEADER, "13");
}

void B11_FinalizeQuest()
{
	ref pchar = GetMainCharacter();

	if (B11_HasFullStatue())
	{
		TakeItemFromCharacter(pchar, B11_ITEM_FULL);
	}
	B11_PayFinalReward();
	B11_SetArcCompleted();
	B11_SetStatus(B11_STATUS_COMPLETED);
	AddQuestRecord(B11_HEADER, "14");
	CloseQuestHeader(B11_HEADER);
	DoQuestCheckDelay(B11_EVENT_CLEANUP, 0.0);
	Log_SetStringToLog("PJ B1.1: final report complete");
}

void B11_RunJungleAutoStep()
{
	ref pchar = GetMainCharacter();
	string status = B11_GetStatus();

	if (pchar.location != B11_LOCATION_JUNGLE)
	{
		return;
	}

	if (status == B11_STATUS_JUNGLE_CLUE_PENDING && !CheckAttribute(pchar, "quest_b1_1_hint_found"))
	{
		DoQuestCheckDelay(B11_EVENT_JUNGLE_HINT_FOUND, 0.0);
		return;
	}

	if (status == B11_STATUS_DIG_READY && !CheckAttribute(pchar, "quest_b1_1_dig_done"))
	{
		DoQuestCheckDelay(B11_EVENT_DIG_COMPLETED, 0.0);
	}
}

void B1_1_UpdateQuestTracker()
{
	ref pchar = GetMainCharacter();
	string status = B11_GetStatus();

	if (B11_IsCompleted())
	{
		return;
	}

	if (!B11_IsStarted())
	{
		return;
	}

	pchar.quest_in_progress = B11_HEADER;
	pchar.quest_in_progress_step = status;
}

void B1_1_EnforceState()
{
	string status = B11_GetStatus();

	if (status == B11_STATUS_NOT_STARTED || status == B11_STATUS_COMPLETED || status == B11_STATUS_CLOSED)
	{
		B11_DespawnAllSceneNpcs();
		return;
	}

	if (B11_GetMuelleState() == B11_MUELLE_STATE_WAIT)
	{
		B11_HideNpc(B11_NPC_MUELLE_ENGLISH);
	}

	if (B11_GetConceicaoState() == B11_CONCEICAO_STATE_WAIT)
	{
		B11_HideNpc(B11_NPC_CONCEICAO_ENGLISH);
	}
}

void B1_1_ProcessLocationEnter()
{
	ref pchar = GetMainCharacter();
	string status = B11_GetStatus();

	if (!B11_IsStarted() || B11_IsCompleted())
	{
		return;
	}

	if (status == B11_STATUS_INTRO_COLLECT)
	{
		B11_AdvanceToIntroReadyReport();
	}

	switch (pchar.location)
	{
		case B11_LOCATION_MUELLE:
			if (status == B11_STATUS_MUELLE_PENDING)
			{
				B11_SpawnMuelleScene();
			}
		break;

		case B11_LOCATION_CONCEICAO:
			if (status == B11_STATUS_CONCEICAO_PENDING)
			{
				B11_SpawnConceicaoScene();
			}
		break;

		case B11_LOCATION_DOUWESEN:
			if (status == B11_STATUS_DOUWESEN_PENDING)
			{
				B11_SpawnDouwesenScene();
			}
		break;

		case B11_LOCATION_JUNGLE:
			B11_RunJungleAutoStep();
		break;
	}
}

bool QuestComplete_B1_1(string sQuestName)
{
	ref pchar = GetMainCharacter();

	switch (sQuestName)
	{
		case B11_EVENT_START:
			B11_StartQuest();
			return true;
		break;

		case B11_EVENT_INTRO_ITEMS_COMPLETE:
			B11_AdvanceToIntroReadyReport();
			return true;
		break;

		case B11_EVENT_INTRO_REPORT_COMPLETE:
			if (B11_GetStatus() != B11_STATUS_INTRO_READY_REPORT)
			{
				return true;
			}
			B11_AdvanceToMuelle();
			return true;
		break;

		case B11_EVENT_MUELLE_SPAIN_FIRST:
			if (B11_GetStatus() != B11_STATUS_MUELLE_PENDING)
			{
				return true;
			}
			if (B11_GetMuelleState() == B11_MUELLE_STATE_DONE || B11_GetMuelleState() == B11_MUELLE_STATE_WAIT)
			{
				return true;
			}
			B11_SetMuelleState(B11_MUELLE_STATE_WAIT);
			B11_HideNpc(B11_NPC_MUELLE_ENGLISH);
			AddQuestRecord(B11_HEADER, "5");
			B11_ArmMuelleTimer();
			Log_SetStringToLog("PJ B1.1: muelle failed by spanish guard");
			return true;
		break;

		case B11_EVENT_MUELLE_RETURN:
			if (B11_GetStatus() != B11_STATUS_MUELLE_PENDING)
			{
				return true;
			}
			B11_DisarmMuelleTimer();
			B11_SetMuelleState(B11_MUELLE_STATE_PENDING);
			return true;
		break;

		case B11_EVENT_MUELLE_CONTACT_SHIP:
			if (B11_GetStatus() != B11_STATUS_MUELLE_PENDING)
			{
				return true;
			}
			if (B11_GetMuelleState() == B11_MUELLE_STATE_DONE)
			{
				return true;
			}
			B11_SetMuelleState(B11_MUELLE_STATE_SHIP_OFFER);
			AddQuestRecord(B11_HEADER, "6");
			return true;
		break;

		case B11_EVENT_MUELLE_PIECE_OBTAINED:
			if (B11_GetStatus() != B11_STATUS_MUELLE_PENDING)
			{
				return true;
			}
			if (B11_GetMuelleState() == B11_MUELLE_STATE_DONE)
			{
				return true;
			}
			B11_DisarmMuelleTimer();
			B11_GrantPieceIfMissing(B11_ITEM_FEET, "quest_b1_1_piece_feet");
			B11_AdvanceToConceicao();
			return true;
		break;

		case B11_EVENT_CONCEICAO_PORTUGAL_FIRST:
			if (B11_GetStatus() != B11_STATUS_CONCEICAO_PENDING)
			{
				return true;
			}
			if (B11_GetConceicaoState() == B11_CONCEICAO_STATE_DONE || B11_GetConceicaoState() == B11_CONCEICAO_STATE_WAIT)
			{
				return true;
			}
			B11_SetConceicaoState(B11_CONCEICAO_STATE_WAIT);
			B11_HideNpc(B11_NPC_CONCEICAO_ENGLISH);
			AddQuestRecord(B11_HEADER, "8");
			B11_ArmConceicaoTimer();
			Log_SetStringToLog("PJ B1.1: conceicao failed by portuguese guard");
			return true;
		break;

		case B11_EVENT_CONCEICAO_RETURN:
			if (B11_GetStatus() != B11_STATUS_CONCEICAO_PENDING)
			{
				return true;
			}
			B11_DisarmConceicaoTimer();
			B11_SetConceicaoState(B11_CONCEICAO_STATE_PENDING);
			return true;
		break;

		case B11_EVENT_CONCEICAO_CONTACT_SHIP:
			if (B11_GetStatus() != B11_STATUS_CONCEICAO_PENDING)
			{
				return true;
			}
			if (B11_GetConceicaoState() == B11_CONCEICAO_STATE_DONE)
			{
				return true;
			}
			B11_SetConceicaoState(B11_CONCEICAO_STATE_SHIP_OFFER);
			AddQuestRecord(B11_HEADER, "9");
			return true;
		break;

		case B11_EVENT_CONCEICAO_PIECE_OBTAINED:
			if (B11_GetStatus() != B11_STATUS_CONCEICAO_PENDING)
			{
				return true;
			}
			if (B11_GetConceicaoState() == B11_CONCEICAO_STATE_DONE)
			{
				return true;
			}
			B11_DisarmConceicaoTimer();
			B11_GrantPieceIfMissing(B11_ITEM_BODY, "quest_b1_1_piece_body");
			B11_AdvanceToDouwesen();
			return true;
		break;

		case B11_EVENT_DOUWESEN_ARMS_OBTAINED:
			if (B11_GetStatus() != B11_STATUS_DOUWESEN_PENDING)
			{
				return true;
			}
			if (B11_GetDouwesenState() == B11_DOUWESEN_STATE_DONE)
			{
				return true;
			}
			B11_GrantPieceIfMissing(B11_ITEM_ARMS, "quest_b1_1_piece_arms");
			B11_AdvanceToJungle();
			return true;
		break;

		case B11_EVENT_JUNGLE_HINT_FOUND:
			if (B11_GetStatus() != B11_STATUS_JUNGLE_CLUE_PENDING)
			{
				return true;
			}
			B11_AdvanceToDigReady();
			return true;
		break;

		case B11_EVENT_DIG_COMPLETED:
			if (B11_GetStatus() != B11_STATUS_DIG_READY)
			{
				return true;
			}
			if (CheckAttribute(pchar, "quest_b1_1_dig_done"))
			{
				return true;
			}
			pchar.quest_b1_1_dig_done = "1";
			Log_SetStringToLog("PJ B1.1: dig completed");
			DoQuestCheckDelay(B11_EVENT_HEAD_OBTAINED, 0.0);
			return true;
		break;

		case B11_EVENT_HEAD_OBTAINED:
			if (B11_GetStatus() != B11_STATUS_DIG_READY)
			{
				return true;
			}
			B11_GrantPieceIfMissing(B11_ITEM_HEAD, "quest_b1_1_piece_head");
			if (B11_HasAllPieces())
			{
				DoQuestCheckDelay(B11_EVENT_ASSEMBLE_FULL_STATUE, 0.0);
			}
			return true;
		break;

		case B11_EVENT_ASSEMBLE_FULL_STATUE:
			if (!B11_HasAllPieces())
			{
				return true;
			}
			B11_RemoveAllPieces();
			GiveItem2Character(pchar, B11_ITEM_FULL);
			B11_AdvanceToFinalReady();
			return true;
		break;

		case B11_EVENT_FINAL_REPORT_COMPLETE:
			if (B11_GetStatus() != B11_STATUS_FINAL_READY)
			{
				return true;
			}
			if (!B11_HasFullStatue())
			{
				return true;
			}
			B11_FinalizeQuest();
			return true;
		break;

		case B11_EVENT_CLEANUP:
			B11_DisarmAllQuestConditions();
			B11_DespawnAllSceneNpcs();
			B11_SetStatus(B11_STATUS_CLOSED);
			return true;
		break;
	}

	return false;
}
