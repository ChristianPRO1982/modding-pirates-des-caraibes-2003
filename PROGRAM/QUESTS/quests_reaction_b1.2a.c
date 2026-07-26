// B1.2a - La Lettre de cachet et le cadeau diplomatique

#define B12A_HEADER "PJ_B1_2A"
#define B12A_TRANS_SUBQUEST "B1.2a"

#define B12_NPC_GUARD1 "PJ_B1_2_DutchFakeEnglishGuard1"
#define B12_NPC_GUARD2 "PJ_B1_2_DutchFakeEnglishGuard2"
#define B12_NPC_GUARD3 "PJ_B1_2_DutchFakeEnglishGuard3"
#define B12_NPC_GUARD4 "PJ_B1_2_DutchFakeEnglishGuard4"
#define B12_NPC_GUARD_CHIEF "PJ_B1_2_DutchFakeEnglishGuardChief"
#define B12_NPC_SPY "PJ_B1_2_FrenchSpy_Ragged"
#define B12_NPC_WITNESS1 "PJ_B1_2_DouwesenWitness1"
#define B12_NPC_WITNESS2 "PJ_B1_2_DouwesenWitness2"
#define B12_NPC_WITNESS3 "PJ_B1_2_DouwesenWitness3"
#define B12_NPC_CAPTAIN1 "PJ_B1_2_NavalCaptain1"
#define B12_NPC_CAPTAIN2 "PJ_B1_2_NavalCaptain2"

#define B12_DIALOG_FILE_BARRETO_PJ "PJ Quest B1 Jacinto Arcibaldo Barreto_dialog.c"
#define B12_DIALOG_FILE_GUARD "PJ Quest B1_2 DutchFakeEnglishGuard_dialog.c"
#define B12_DIALOG_FILE_GUARD_CHIEF "PJ Quest B1_2 DutchFakeEnglishGuardChief_dialog.c"
#define B12_DIALOG_FILE_SPY "PJ Quest B1_2 FrenchSpy_dialog.c"
#define B12_DIALOG_FILE_WITNESS "PJ Quest B1_2 DouwesenWitness_dialog.c"
#define B12_DIALOG_FILE_CAPTAIN "PJ Quest B1_2 NavalCaptain_dialog.c"
#define B12_DIALOG_FILE_PRIEST "PJ Quest B1_2 ShangoPriest_dialog.c"
#define B12_DIALOG_FILE_PRIEST_CHIEF "PJ Quest B1_2 ShangoPriestChief_dialog.c"

#define B12A_STATUS_NOT_STARTED "not_started"
#define B12A_STATUS_OFFER "offer"
#define B12A_STATUS_DELIVERY "delivery"
#define B12A_STATUS_REDMOND_NIGHT "redmond_night"
#define B12A_STATUS_STOLEN "stolen"
#define B12A_STATUS_REPORT_CHOICE "report_choice"
#define B12A_STATUS_COMPLETED "completed"
#define B12A_STATUS_CLOSED "closed"

#define B12A_EVENT_START "PJ_B1_2A_START"
#define B12A_EVENT_PORTUGAL_HANDOFF "PJ_B1_2A_PORTUGAL_HANDOFF"
#define B12A_EVENT_THEFT_SCENE "PJ_B1_2A_THEFT_SCENE"
#define B12A_EVENT_THEFT_COMPLETE "PJ_B1_2A_THEFT_COMPLETE"
#define B12A_EVENT_REPORT_PORTUGAL "PJ_B1_2A_REPORT_PORTUGAL"
#define B12A_EVENT_REPORT_ENGLAND "PJ_B1_2A_REPORT_ENGLAND"
#define B12A_EVENT_SILEHARD_TRANSITION "PJ_B1_2A_SILEHARD_TRANSITION"

string B12A_GetStatus()
{
	ref pchar = GetMainCharacter();

	if (!CheckAttribute(pchar, "quest_b1_2a_status") || pchar.quest_b1_2a_status == "")
	{
		return B12A_STATUS_NOT_STARTED;
	}
	return pchar.quest_b1_2a_status;
}

string B12A_GetPublishedStep(string status)
{
	if (status == B12A_STATUS_NOT_STARTED || status == "")
	{
		return B1_STEP_NONE;
	}
	if (status == B12A_STATUS_COMPLETED || status == B12A_STATUS_CLOSED)
	{
		return B1_STEP_COMPLETED;
	}
	return status;
}

bool B12A_CanPublishToTransverseState()
{
	return !B1_IsAnotherSubquestActive(B12A_TRANS_SUBQUEST);
}

void B12A_PublishTransverseState(string status)
{
	string step = B12A_GetPublishedStep(status);

	if (step == B1_STEP_NONE)
	{
		return;
	}
	if (!B12A_CanPublishToTransverseState())
	{
		return;
	}

	B1_SetState(B12A_TRANS_SUBQUEST, step);
}

void B12A_SetStatus(string status)
{
	ref pchar = GetMainCharacter();

	pchar.quest_b1_2a_status = status;
	B12A_PublishTransverseState(status);
}

string B12A_GetReportTarget()
{
	ref pchar = GetMainCharacter();

	if (!CheckAttribute(pchar, "quest_b1_2a_report_target"))
	{
		return "";
	}
	return pchar.quest_b1_2a_report_target;
}

void B12A_SetReportTarget(string target)
{
	ref pchar = GetMainCharacter();

	pchar.quest_b1_2a_report_target = target;
}

bool B12A_IsStarted()
{
	string status = B12A_GetStatus();
	return status != B12A_STATUS_NOT_STARTED && status != B12A_STATUS_CLOSED;
}

bool B12A_IsCompleted()
{
	string status = B12A_GetStatus();
	return status == B12A_STATUS_COMPLETED || status == B12A_STATUS_CLOSED;
}

bool B12A_IsTransverseCompleted()
{
	return B1_IsSubquestCompleted(B12A_TRANS_SUBQUEST);
}

void B12A_SyncTransverseState()
{
	B12A_PublishTransverseState(B12A_GetStatus());
}

bool B12A_B11Completed()
{
	ref pchar = GetMainCharacter();

	if (B11_IsCompleted() || B11_IsTransverseCompleted())
	{
		return true;
	}
	if (CheckAttribute(pchar, "quest_b1_status") && pchar.quest_b1_status == "b1_1_completed")
	{
		return true;
	}
	return false;
}

bool B12A_CanStartQuest()
{
	if (B12A_IsStarted() || B12A_IsCompleted() || B12A_IsTransverseCompleted())
	{
		return false;
	}
	if (!B12A_B11Completed())
	{
		return false;
	}
	if (B1_IsAnotherSubquestActive(B12A_TRANS_SUBQUEST))
	{
		return false;
	}
	return true;
}

bool B12_IsNightTime()
{
	int hour = makeint(GetHour());
	return hour >= 21 || hour < 6;
}

bool B12A_IsRedmondLandLocation(string locationId)
{
	if (locationId == "REDMOND_PORT") { return true; }
	if (locationId == "Redmond_town_01") { return true; }
	if (locationId == "Redmond_town_03") { return true; }
	if (locationId == "Redmond_town_04") { return true; }
	if (locationId == "Redmond_town_exit_1") { return true; }
	if (locationId == "Redmond_town_exit_2") { return true; }
	if (locationId == "Redmond_shore_01") { return true; }
	if (locationId == "Redmond_shore_02") { return true; }
	if (locationId == "Redmond_Residence") { return true; }
	return false;
}

void B12_SetDialogNode(string npcId, string nodeName)
{
	if (!B11_HasNpc(npcId))
	{
		return;
	}

	characterFromID(npcId).Dialog.CurrentNode = nodeName;
	characterFromID(npcId).Dialog.TempNode = nodeName;
}

void B12_SetDialogFile(string npcId, string dialogFile)
{
	if (!B11_HasNpc(npcId))
	{
		return;
	}

	characterFromID(npcId).Dialog.Filename = dialogFile;
}

void B12_SetModel(ref chref, string modelId, string animation)
{
	chref.model = modelId;
	chref.model.animation = animation;
	chref.headmodel = "h_" + modelId;
	FaceMaker(chref);
	SendMessage(chref, "lss", MSG_CHARACTER_SETMODEL, chref.model, chref.model.animation);
}

void B12A_SetBarretoDialog(string dialogFile)
{
	int idx = GetCharacterIndex("Jacinto Arcibaldo Barreto");
	ref chref;

	if (idx < 0)
	{
		return;
	}

	chref = GetCharacter(idx);
	chref.Dialog.Filename = dialogFile;
	chref.Dialog.CurrentNode = "First time";
	chref.Dialog.TempNode = "First time";
}

void B12_HideCoreB12Npcs()
{
	B11_HideNpc(B12_NPC_GUARD1);
	B11_HideNpc(B12_NPC_GUARD2);
	B11_HideNpc(B12_NPC_GUARD3);
	B11_HideNpc(B12_NPC_GUARD4);
	B11_HideNpc(B12_NPC_GUARD_CHIEF);
	B11_HideNpc(B12_NPC_WITNESS1);
	B11_HideNpc(B12_NPC_WITNESS2);
	B11_HideNpc(B12_NPC_WITNESS3);
	B11_HideNpc(B12_NPC_CAPTAIN1);
	B11_HideNpc(B12_NPC_CAPTAIN2);
}

void B12A_ResetRuntime()
{
	ref pchar = GetMainCharacter();

	DeleteAttribute(pchar, "quest_b1_2a_letter_received");
	DeleteAttribute(pchar, "quest_b1_2a_gift_received");
	DeleteAttribute(pchar, "quest_b1_2a_report_target");
	DeleteAttribute(pchar, "quest_b1_2a_theft_scene_started");
	DeleteAttribute(pchar, "quest_b1_2a_theft_scene_done");
	B12_HideCoreB12Npcs();
	B11_HideNpc(B12_NPC_SPY);
}

void B12A_StartQuest()
{
	ref pchar = GetMainCharacter();

	if (!B12A_CanStartQuest())
	{
		return;
	}

	B12A_ResetRuntime();
	B12A_SetBarretoDialog(B12_DIALOG_FILE_BARRETO_PJ);
	pchar.quest_b1_status = "b1_2a_started";
	B12A_SetStatus(B12A_STATUS_OFFER);

	B1_AddJournalRecord("6");
	DeleteQuestHeader(B12A_HEADER);
	SetQuestHeader(B12A_HEADER);
	Log_SetStringToLog("PJ B1.2a: mission accepted");
}

void B12A_ReceivePortugalPackage()
{
	ref pchar = GetMainCharacter();

	if (B12A_GetStatus() != B12A_STATUS_OFFER)
	{
		return;
	}

	pchar.quest_b1_2a_letter_received = "yes";
	pchar.quest_b1_2a_gift_received = "yes";
	B12A_SetStatus(B12A_STATUS_DELIVERY);
	AddQuestRecord(B12A_HEADER, "1");
	Log_SetStringToLog("PJ B1.2a: portugal handoff complete");
}

void B12A_SpawnTheftGuards()
{
	B12_HideCoreB12Npcs();

	B12_SetDialogFile(B12_NPC_GUARD1, B12_DIALOG_FILE_GUARD);
	B12_SetDialogFile(B12_NPC_GUARD2, B12_DIALOG_FILE_GUARD);
	B12_SetDialogFile(B12_NPC_GUARD3, B12_DIALOG_FILE_GUARD);
	B12_SetDialogFile(B12_NPC_GUARD4, B12_DIALOG_FILE_GUARD);
	B12_SetDialogFile(B12_NPC_GUARD_CHIEF, B12_DIALOG_FILE_GUARD_CHIEF);

	B12_SetDialogNode(B12_NPC_GUARD1, "B1_2A_guard");
	B12_SetDialogNode(B12_NPC_GUARD2, "B1_2A_guard");
	B12_SetDialogNode(B12_NPC_GUARD3, "B1_2A_guard");
	B12_SetDialogNode(B12_NPC_GUARD4, "B1_2A_guard");
	B12_SetDialogNode(B12_NPC_GUARD_CHIEF, "B1_2A_theft");

	B11_PlaceNpc(B12_NPC_GUARD1, "REDMOND_PORT", "goto");
	B11_PlaceNpc(B12_NPC_GUARD2, "REDMOND_PORT", "goto");
	B11_PlaceNpc(B12_NPC_GUARD3, "REDMOND_PORT", "goto");
	B11_PlaceNpc(B12_NPC_GUARD4, "REDMOND_PORT", "goto");
	B11_PlaceNpc(B12_NPC_GUARD_CHIEF, "REDMOND_PORT", "goto");

	B11_SetNpcGuardian(B12_NPC_GUARD1);
	B11_SetNpcGuardian(B12_NPC_GUARD2);
	B11_SetNpcGuardian(B12_NPC_GUARD3);
	B11_SetNpcGuardian(B12_NPC_GUARD4);
	B11_SetNpcGuardian(B12_NPC_GUARD_CHIEF);
}

void B12A_BeginTheftTravel()
{
	ref pchar = GetMainCharacter();

	if (B12A_GetStatus() != B12A_STATUS_DELIVERY)
	{
		return;
	}
	if (!B12A_IsRedmondLandLocation(pchar.location))
	{
		return;
	}
	if (!B12_IsNightTime())
	{
		return;
	}
	if (CheckAttribute(pchar, "quest_b1_2a_theft_scene_started"))
	{
		return;
	}

	pchar.quest_b1_2a_theft_scene_started = "yes";
	B12A_SetStatus(B12A_STATUS_REDMOND_NIGHT);
	DoQuestReloadToLocation("REDMOND_PORT", "reload", "reload_2_city", B12A_EVENT_THEFT_SCENE);
}

void B12A_StartTheftScene()
{
	ref pchar = GetMainCharacter();

	B12A_SpawnTheftGuards();
	LAi_LockFightMode(pchar, true);
	LAi_SetActorType(characterFromID(B12_NPC_GUARD_CHIEF));
	LAi_ActorDialog(characterFromID(B12_NPC_GUARD_CHIEF), pchar, "", 12.0, 1.0);
}

void B12A_CompleteTheftScene()
{
	ref pchar = GetMainCharacter();

	DeleteAttribute(pchar, "quest_b1_2a_letter_received");
	DeleteAttribute(pchar, "quest_b1_2a_gift_received");
	pchar.quest_b1_2b_letter_missing = "yes";
	pchar.quest_b1_2b_gift_missing = "yes";
	pchar.quest_b1_2a_theft_scene_done = "yes";
	B12A_SetStatus(B12A_STATUS_STOLEN);
	AddQuestRecord(B12A_HEADER, "2");
	AddQuestRecord(B12A_HEADER, "3");
	LAi_LockFightMode(pchar, false);
	B12_HideCoreB12Npcs();
	Log_SetStringToLog("PJ B1.2a: diplomatic objects stolen");
}

void B12A_ReportToPortugal()
{
	if (B12A_GetReportTarget() == "portugal")
	{
		return;
	}

	B12A_SetReportTarget("portugal");
	B12A_SetStatus(B12A_STATUS_REPORT_CHOICE);
	AddQuestRecord(B12A_HEADER, "4");
	Log_SetStringToLog("PJ B1.2a: portugal informed first");
}

void B12A_ReportToEngland()
{
	if (B12A_GetReportTarget() == "england")
	{
		return;
	}

	B12A_SetReportTarget("england");
	B12A_SetStatus(B12A_STATUS_REPORT_CHOICE);
	AddQuestRecord(B12A_HEADER, "5");
	Log_SetStringToLog("PJ B1.2a: england informed first");
}

void B12A_TransitionToB12B()
{
	ref pchar = GetMainCharacter();

	if (B12A_GetReportTarget() == "")
	{
		B12A_ReportToEngland();
	}

	AddQuestRecord(B12A_HEADER, "6");
	AddQuestRecord(B12A_HEADER, "7");
	CloseQuestHeader(B12A_HEADER);
	B12A_SetStatus(B12A_STATUS_CLOSED);
	pchar.quest_b1_status = "b1_2b_started";
	B12_HideCoreB12Npcs();
	LAi_LockFightMode(pchar, false);
	Log_SetStringToLog("PJ B1.2a: transition prepared for B1.2b");
}

void B1_2A_UpdateQuestTracker()
{
	ref pchar = GetMainCharacter();
	string status = B12A_GetStatus();

	B12A_SyncTransverseState();

	if (!B12A_IsStarted() || B12A_IsCompleted())
	{
		return;
	}
	if (B1_IsAnotherSubquestActive(B12A_TRANS_SUBQUEST))
	{
		return;
	}

	pchar.quest_in_progress = B12A_HEADER;
	pchar.quest_in_progress_step = status;
}

void B1_2A_EnforceState()
{
	B12A_SyncTransverseState();
}

void B1_2A_ProcessLocationEnter()
{
	B12A_SyncTransverseState();
	B12A_BeginTheftTravel();
}

bool QuestComplete_B1_2A(string sQuestName)
{
	B12A_SyncTransverseState();

	if (
		sQuestName != B12A_EVENT_START &&
		sQuestName != B12A_EVENT_PORTUGAL_HANDOFF &&
		sQuestName != B12A_EVENT_THEFT_SCENE &&
		sQuestName != B12A_EVENT_THEFT_COMPLETE &&
		sQuestName != B12A_EVENT_REPORT_PORTUGAL &&
		sQuestName != B12A_EVENT_REPORT_ENGLAND &&
		sQuestName != B12A_EVENT_SILEHARD_TRANSITION &&
		B1_IsAnotherSubquestActive(B12A_TRANS_SUBQUEST)
	)
	{
		return false;
	}

	switch (sQuestName)
	{
		case B12A_EVENT_START:
			B12A_StartQuest();
			return true;
		break;

		case B12A_EVENT_PORTUGAL_HANDOFF:
			B12A_ReceivePortugalPackage();
			return true;
		break;

		case B12A_EVENT_THEFT_SCENE:
			B12A_StartTheftScene();
			return true;
		break;

		case B12A_EVENT_THEFT_COMPLETE:
			B12A_CompleteTheftScene();
			return true;
		break;

		case B12A_EVENT_REPORT_PORTUGAL:
			B12A_ReportToPortugal();
			return true;
		break;

		case B12A_EVENT_REPORT_ENGLAND:
			B12A_ReportToEngland();
			return true;
		break;

		case B12A_EVENT_SILEHARD_TRANSITION:
			B12A_TransitionToB12B();
			return true;
		break;
	}

	return false;
}
