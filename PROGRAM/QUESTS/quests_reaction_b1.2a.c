// B1.2a - La Lettre de cachet et le cadeau diplomatique

#define B12A_HEADER "PJ_B1_2A"
#define B12A_TRANS_SUBQUEST "B1.2a"

#define B12A_STATUS_NOT_STARTED "not_started"
#define B12A_STATUS_OFFER "offer"
#define B12A_STATUS_DELIVERY "delivery"
#define B12A_STATUS_COMPLETED "completed"
#define B12A_STATUS_CLOSED "closed"

#define B12A_EVENT_START "PJ_B1_2A_START"
#define B12A_EVENT_PORTUGAL_HANDOFF "PJ_B1_2A_PORTUGAL_HANDOFF"

#define B12A_DIALOG_FILE_BARRETO_DEFAULT "Jacinto Arcibaldo Barreto_dialog.c"
#define B12A_DIALOG_FILE_BARRETO_PJ "PJ Quest B1 Jacinto Arcibaldo Barreto_dialog.c"

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

void B12A_SetBarretoDialog(string dialogFile)
{
	int idx = GetCharacterIndex("Jacinto Arcibaldo Barreto");
	ref chref;

	if (idx < 0)
	{
		return;
	}

	chref = GetCharacter(idx);
	chref.dialog.filename = dialogFile;
	chref.dialog.currentnode = "First time";
	chref.dialog.tempnode = "First time";
}

void B12A_ResetRuntime()
{
	ref pchar = GetMainCharacter();

	DeleteAttribute(pchar, "quest_b1_2a_letter_received");
	DeleteAttribute(pchar, "quest_b1_2a_gift_received");
}

void B12A_StartQuest()
{
	ref pchar = GetMainCharacter();

	if (!B12A_CanStartQuest())
	{
		return;
	}

	B12A_ResetRuntime();
	B12A_SetBarretoDialog(B12A_DIALOG_FILE_BARRETO_PJ);
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
}

bool QuestComplete_B1_2A(string sQuestName)
{
	B12A_SyncTransverseState();

	if (sQuestName != B12A_EVENT_START && sQuestName != B12A_EVENT_PORTUGAL_HANDOFF && B1_IsAnotherSubquestActive(B12A_TRANS_SUBQUEST))
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
	}

	return false;
}
