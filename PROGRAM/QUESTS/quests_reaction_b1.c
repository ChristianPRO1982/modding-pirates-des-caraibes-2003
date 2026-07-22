// B1 - Shared transverse state

#define B1_HEADER "PJ_B1"
#define B1_SUBQUEST_NONE "none"
#define B1_STEP_NONE "none"
#define B1_STEP_COMPLETED "completed"

void B1_EnsureJournalOpen()
{
	if (!CheckActiveQuest(B1_HEADER))
	{
		SetQuestHeader(B1_HEADER);
	}
}

void B1_AddJournalRecord(string textId)
{
	B1_EnsureJournalOpen();
	AddQuestRecord(B1_HEADER, textId);
}

string B1_GetSubquest()
{
	ref pchar = GetMainCharacter();
	if (!CheckAttribute(pchar, "quest.b1_subquest") || pchar.quest.b1_subquest == "")
	{
		return B1_SUBQUEST_NONE;
	}
	return pchar.quest.b1_subquest;
}

string B1_GetStep()
{
	ref pchar = GetMainCharacter();
	if (!CheckAttribute(pchar, "quest.b1_step") || pchar.quest.b1_step == "")
	{
		return B1_STEP_NONE;
	}
	return pchar.quest.b1_step;
}

void B1_SetState(string subquest, string step)
{
	ref pchar = GetMainCharacter();
	pchar.quest.b1_subquest = subquest;
	pchar.quest.b1_step = step;
}

bool B1_IsActiveStep(string step)
{
	return step != "" && step != B1_STEP_NONE && step != "not_started" && step != B1_STEP_COMPLETED && step != "closed";
}

bool B1_IsAnySubquestActive()
{
	return B1_IsActiveStep(B1_GetStep());
}

bool B1_IsSubquestActive(string subquest)
{
	return B1_GetSubquest() == subquest && B1_IsAnySubquestActive();
}

bool B1_IsSubquestCompleted(string subquest)
{
	return B1_GetSubquest() == subquest && B1_GetStep() == B1_STEP_COMPLETED;
}

bool B1_IsAnotherSubquestActive(string subquest)
{
	return B1_IsAnySubquestActive() && B1_GetSubquest() != subquest;
}
