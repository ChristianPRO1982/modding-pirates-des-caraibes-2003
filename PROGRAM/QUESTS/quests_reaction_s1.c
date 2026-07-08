// S1 - treasure hunter

bool S1_DEV_COMPLETE_ALL_QUESTS_ON_WIN = true;

string S1_GetLeaderId(string startIsland)
{
	switch (startIsland)
	{
		case "Redmond":
			return "Elizabeth Goodale TQC 2";
		break;
		case "FleurDeFalaise":
			return "Eustache Busket TQC 2";
		break;
		case "Conceicao":
			return "Bartolomeo Portugues TQC 2";
		break;
		case "IslaMuelle":
			return "Benito Bonito TQC 2";
		break;
		case "Douwesen":
			return "Hendrick van Hoven TQC 2";
		break;
		case "Oxbay_Greenford":
			return "Wimund TQC 2";
		break;
		case "Oxbay_Oxbay":
			return "Samuel Bellamy TQC 2";
		break;
		case "QuebradasCostillas":
			return "Edward Thatch TQC 2";
		break;
	}
	return "";
}

string S1_GetStarterId(string startIsland)
{
	switch (startIsland)
	{
		case "Redmond":
			return "Elizabeth Goodale TQC 1";
		break;
		case "FleurDeFalaise":
			return "Eustache Busket TQC 1";
		break;
		case "Conceicao":
			return "Bartolomeo Portugues TQC 1";
		break;
		case "IslaMuelle":
			return "Benito Bonito TQC 1";
		break;
		case "Douwesen":
			return "Hendrick van Hoven TQC 1";
		break;
		case "Oxbay_Greenford":
			return "Wimund TQC 1";
		break;
		case "Oxbay_Oxbay":
			return "Samuel Bellamy TQC 1";
		break;
		case "QuebradasCostillas":
			return "Edward Thatch TQC 1";
		break;
	}
	return "";
}

string S1_GetStarterVisibleAttr(string startIsland)
{
	switch (startIsland)
	{
		case "Redmond":
			return "quest_S1_Elizabeth_Goodale_TQC1_visible";
		break;
		case "FleurDeFalaise":
			return "quest_S1_Eustache_Busket_TQC1_visible";
		break;
		case "Conceicao":
			return "quest_S1_Bartolomeo_Portugues_TQC1_visible";
		break;
		case "IslaMuelle":
			return "quest_S1_Benito_Bonito_TQC1_visible";
		break;
		case "Douwesen":
			return "quest_S1_Hendrick_van_Hoven_TQC1_visible";
		break;
		case "Oxbay_Greenford":
			return "quest_S1_Wimund_TQC1_visible";
		break;
		case "Oxbay_Oxbay":
			return "quest_S1_Samuel_Bellamy_TQC1_visible";
		break;
		case "QuebradasCostillas":
			return "quest_S1_Edward_Thatch_TQC1_visible";
		break;
	}
	return "";
}

bool S1_GetFightCrewIds(string startIsland, ref crew1Id, ref crew2Id, ref crew3Id)
{
	switch (startIsland)
	{
		case "Redmond":
			crew1Id = "TQC for fight 1 1";
			crew2Id = "TQC for fight 1 2";
			crew3Id = "TQC for fight 1 3";
			return true;
		break;
		case "FleurDeFalaise":
			crew1Id = "TQC for fight 2 1";
			crew2Id = "TQC for fight 2 2";
			crew3Id = "TQC for fight 2 3";
			return true;
		break;
		case "Conceicao":
			crew1Id = "TQC for fight 3 1";
			crew2Id = "TQC for fight 3 2";
			crew3Id = "TQC for fight 3 3";
			return true;
		break;
		case "IslaMuelle":
			crew1Id = "TQC for fight 4 1";
			crew2Id = "TQC for fight 4 2";
			crew3Id = "TQC for fight 4 3";
			return true;
		break;
		case "Douwesen":
			crew1Id = "TQC for fight 5 1";
			crew2Id = "TQC for fight 5 2";
			crew3Id = "TQC for fight 5 3";
			return true;
		break;
		case "Oxbay_Greenford":
			crew1Id = "TQC for fight 6 1";
			crew2Id = "TQC for fight 6 2";
			crew3Id = "TQC for fight 6 3";
			return true;
		break;
		case "Oxbay_Oxbay":
			crew1Id = "TQC for fight 7 1";
			crew2Id = "TQC for fight 7 2";
			crew3Id = "TQC for fight 7 3";
			return true;
		break;
		case "QuebradasCostillas":
			crew1Id = "TQC for fight 8 1";
			crew2Id = "TQC for fight 8 2";
			crew3Id = "TQC for fight 8 3";
			return true;
		break;
	}
	return false;
}

void S1_ClearQuestRuntime()
{
	ref PChar = GetMainCharacter();

	pchar.quest_S1_numQuests = 0;
	pchar.quest_S1_step = 0;
	pchar.quest_S1_Unearthing = false;
	pchar.quest_S1_failed = false;
	pchar.quest_S1_currentQuestWon = false;
	pchar.quest_S1_gain_gold_jewelry = 0;
	pchar.quest_S1_gain_gold_jewelry_text = "";
	pchar.quest_S1_gain_gold = 0;
	pchar.quest_S1_gain_jewelry1 = 0;
	pchar.quest_S1_gain_jewelry2 = 0;
	pchar.quest_S1_gain_jewelry3 = 0;
	pchar.quest_S1_gain_jewelry4 = 0;
	pchar.quest_S1_gain_jewelry5 = 0;
	pchar.quest_S1_gain_jewelry6 = 0;
	pchar.quest_S1_gain_jewelry7 = 0;
	pchar.quest_S1_gain_jewelry8 = 0;
	pchar.quest_S1_gain_jewelry9 = 0;
	pchar.quest_S1_gain_jewelry10 = 0;
	pchar.quest_S1_gain_jewelry11 = 0;
	pchar.quest_S1_gain_jewelry12 = 0;
	pchar.quest_S1_gain_jewelry13 = 0;
	pchar.quest_S1_gain_jewelry14 = 0;
	pchar.quest_S1_gain_jewelry15 = 0;
	pchar.quest_S1_gain_jewelry16 = 0;
}

void S1_ResetQuestConditions()
{
	ref PChar = GetMainCharacter();

	pchar.quest.quest_S1_step1.over = "yes";
	pchar.quest.quest_S1_step1 = "completed";
	pchar.quest.quest_S1_step2.over = "yes";
	pchar.quest.quest_S1_step2 = "completed";
	pchar.quest.quest_S1_step3.over = "yes";
	pchar.quest.quest_S1_step3 = "completed";
	pchar.quest.quest_S1_step4.over = "yes";
	pchar.quest.quest_S1_step4 = "completed";
	pchar.quest.quest_S1_step5.over = "yes";
	pchar.quest.quest_S1_step5 = "completed";
	pchar.quest.quest_S1_completed_1.over = "yes";
	pchar.quest.quest_S1_completed_1 = "completed";
	pchar.quest.quest_S1_completed_2.over = "yes";
	pchar.quest.quest_S1_completed_2 = "completed";
	pchar.quest.quest_S1_fight.over = "yes";
	pchar.quest.quest_S1_fight = "completed";
	pchar.quest.quest_S1_fight_won.over = "yes";
	pchar.quest.quest_S1_fight_won = "completed";
}

void S1_ResetLastQuestConditions()
{
	ref PChar = GetMainCharacter();
	pchar.quest.quest_S1_lastQuest_1.over = "yes";
	pchar.quest.quest_S1_lastQuest_1 = "completed";
	pchar.quest.quest_S1_lastQuest_2.over = "yes";
	pchar.quest.quest_S1_lastQuest_2 = "completed";
	pchar.quest.quest_S1_lastQuest_3.over = "yes";
	pchar.quest.quest_S1_lastQuest_3 = "completed";
	pchar.quest.quest_S1_lastQuest_4.over = "yes";
	pchar.quest.quest_S1_lastQuest_4 = "completed";
}

void S1_MarkAllQuestsCompleted()
{
	ref PChar = GetMainCharacter();

	pchar.quest_S1_quest_1_completed = true;
	pchar.quest_S1_quest_2_completed = true;
	pchar.quest_S1_quest_3_completed = true;
	pchar.quest_S1_quest_4_completed = true;
	pchar.quest_S1_quest_5_completed = true;
	pchar.quest_S1_quest_6_completed = true;
	pchar.quest_S1_quest_7_completed = true;
	pchar.quest_S1_quest_8_completed = true;
	pchar.quest_S1_quest_9_completed = true;
	pchar.quest_S1_quest_10_completed = true;
	pchar.quest_S1_quest_11_completed = true;
	pchar.quest_S1_quest_12_completed = true;
	pchar.quest_S1_quest_13_completed = true;
	pchar.quest_S1_quest_14_completed = true;
	pchar.quest_S1_quest_15_completed = true;
	pchar.quest_S1_quest_16_completed = true;
	pchar.quest_S1_quest_17_completed = true;
	pchar.quest_S1_quest_18_completed = true;
	pchar.quest_S1_quest_19_completed = true;
	pchar.quest_S1_quest_20_completed = true;
}

void S1_MarkCurrentQuestCompleted()
{
	ref PChar = GetMainCharacter();

	switch (makeint(pchar.quest_S1_numQuests))
	{
		case 1: pchar.quest_S1_quest_1_completed = true; break;
		case 2: pchar.quest_S1_quest_2_completed = true; break;
		case 3: pchar.quest_S1_quest_3_completed = true; break;
		case 4: pchar.quest_S1_quest_4_completed = true; break;
		case 5: pchar.quest_S1_quest_5_completed = true; break;
		case 6: pchar.quest_S1_quest_6_completed = true; break;
		case 7: pchar.quest_S1_quest_7_completed = true; break;
		case 8: pchar.quest_S1_quest_8_completed = true; break;
		case 9: pchar.quest_S1_quest_9_completed = true; break;
		case 10: pchar.quest_S1_quest_10_completed = true; break;
		case 11: pchar.quest_S1_quest_11_completed = true; break;
		case 12: pchar.quest_S1_quest_12_completed = true; break;
		case 13: pchar.quest_S1_quest_13_completed = true; break;
		case 14: pchar.quest_S1_quest_14_completed = true; break;
		case 15: pchar.quest_S1_quest_15_completed = true; break;
		case 16: pchar.quest_S1_quest_16_completed = true; break;
		case 17: pchar.quest_S1_quest_17_completed = true; break;
		case 18: pchar.quest_S1_quest_18_completed = true; break;
		case 19: pchar.quest_S1_quest_19_completed = true; break;
		case 20: pchar.quest_S1_quest_20_completed = true; break;
	}
}

int S1_CountCompletedQuests()
{
	ref PChar = GetMainCharacter();
	int n;

	n = 0;
	if (pchar.quest_S1_quest_1_completed == true) n++;
	if (pchar.quest_S1_quest_2_completed == true) n++;
	if (pchar.quest_S1_quest_3_completed == true) n++;
	if (pchar.quest_S1_quest_4_completed == true) n++;
	if (pchar.quest_S1_quest_5_completed == true) n++;
	if (pchar.quest_S1_quest_6_completed == true) n++;
	if (pchar.quest_S1_quest_7_completed == true) n++;
	if (pchar.quest_S1_quest_8_completed == true) n++;
	if (pchar.quest_S1_quest_9_completed == true) n++;
	if (pchar.quest_S1_quest_10_completed == true) n++;
	if (pchar.quest_S1_quest_11_completed == true) n++;
	if (pchar.quest_S1_quest_12_completed == true) n++;
	if (pchar.quest_S1_quest_13_completed == true) n++;
	if (pchar.quest_S1_quest_14_completed == true) n++;
	if (pchar.quest_S1_quest_15_completed == true) n++;
	if (pchar.quest_S1_quest_16_completed == true) n++;
	if (pchar.quest_S1_quest_17_completed == true) n++;
	if (pchar.quest_S1_quest_18_completed == true) n++;
	if (pchar.quest_S1_quest_19_completed == true) n++;
	if (pchar.quest_S1_quest_20_completed == true) n++;
	return n;
}

void S1_ClearCompletedQuestFlags()
{
	ref PChar = GetMainCharacter();

	pchar.quest_S1_quest_1_completed = false;
	pchar.quest_S1_quest_2_completed = false;
	pchar.quest_S1_quest_3_completed = false;
	pchar.quest_S1_quest_4_completed = false;
	pchar.quest_S1_quest_5_completed = false;
	pchar.quest_S1_quest_6_completed = false;
	pchar.quest_S1_quest_7_completed = false;
	pchar.quest_S1_quest_8_completed = false;
	pchar.quest_S1_quest_9_completed = false;
	pchar.quest_S1_quest_10_completed = false;
	pchar.quest_S1_quest_11_completed = false;
	pchar.quest_S1_quest_12_completed = false;
	pchar.quest_S1_quest_13_completed = false;
	pchar.quest_S1_quest_14_completed = false;
	pchar.quest_S1_quest_15_completed = false;
	pchar.quest_S1_quest_16_completed = false;
	pchar.quest_S1_quest_17_completed = false;
	pchar.quest_S1_quest_18_completed = false;
	pchar.quest_S1_quest_19_completed = false;
	pchar.quest_S1_quest_20_completed = false;
}

void GenerateTreasureHunterQuests()
{
	ref PChar = GetMainCharacter();
	int n = 0;

	pchar.quest_S1_treasure_hunter_1_win_condition_step1_island = "Conceicao"; n++;
	pchar.quest_S1_treasure_hunter_2_win_condition_step1_island = "Conceicao"; n++;
	pchar.quest_S1_treasure_hunter_3_win_condition_step1_island = "Douwesen"; n++;
	pchar.quest_S1_treasure_hunter_4_win_condition_step1_island = "Douwesen"; n++;
	pchar.quest_S1_treasure_hunter_5_win_condition_step1_island = "Falaise de Fleur"; n++;
	pchar.quest_S1_treasure_hunter_6_win_condition_step1_island = "Falaise de Fleur"; n++;
	pchar.quest_S1_treasure_hunter_7_win_condition_step1_island = "Isla Muelle"; n++;
	pchar.quest_S1_treasure_hunter_8_win_condition_step1_island = "Isla Muelle"; n++;
	pchar.quest_S1_treasure_hunter_9_win_condition_step1_island = "Quebradas Costillas"; n++;
	pchar.quest_S1_treasure_hunter_10_win_condition_step1_island = "Quebradas Costillas"; n++;
	pchar.quest_S1_treasure_hunter_11_win_condition_step1_island = "Redmond"; n++;
	pchar.quest_S1_treasure_hunter_12_win_condition_step1_island = "Redmond"; n++;
	pchar.quest_S1_treasure_hunter_13_win_condition_step1_island = "Oxbay"; n++;
	pchar.quest_S1_treasure_hunter_14_win_condition_step1_island = "Oxbay"; n++;
	pchar.quest_S1_treasure_hunter_15_win_condition_step1_island = "Oxbay"; n++;
	pchar.quest_S1_treasure_hunter_16_win_condition_step1_island = "Oxbay"; n++;
	pchar.quest_S1_treasure_hunter_17_win_condition_step1_island = "Oxbay"; n++;
	pchar.quest_S1_treasure_hunter_18_win_condition_step1_island = "Oxbay"; n++;
	pchar.quest_S1_treasure_hunter_19_win_condition_step1_island = "Redmond"; n++;
	pchar.quest_S1_treasure_hunter_20_win_condition_step1_island = "Isla Muelle"; n++;

	pchar.quest_S1_nbQuests = n;
	pchar.quest_S1_numQuests = 0;
	pchar.quest_S1_quest_1_completed = false;
	pchar.quest_S1_quest_2_completed = false;
	pchar.quest_S1_quest_3_completed = false;
	pchar.quest_S1_quest_4_completed = false;
	pchar.quest_S1_quest_5_completed = false;
	pchar.quest_S1_quest_6_completed = false;
	pchar.quest_S1_quest_7_completed = false;
	pchar.quest_S1_quest_8_completed = false;
	pchar.quest_S1_quest_9_completed = false;
	pchar.quest_S1_quest_10_completed = false;
	pchar.quest_S1_quest_11_completed = false;
	pchar.quest_S1_quest_12_completed = false;
	pchar.quest_S1_quest_13_completed = false;
	pchar.quest_S1_quest_14_completed = false;
	pchar.quest_S1_quest_15_completed = false;
	pchar.quest_S1_quest_16_completed = false;
	pchar.quest_S1_quest_17_completed = false;
	pchar.quest_S1_quest_18_completed = false;
	pchar.quest_S1_quest_19_completed = false;
	pchar.quest_S1_quest_20_completed = false;
	pchar.quest_S1_allQuestsCompleted = false;
	pchar.quest_S1_step = 0;
	pchar.quest_S1_Unearthing = false;
	pchar.quest_S1_failed = false;
	pchar.quest_S1_currentQuestWon = false;
	pchar.quest_S1_gain_gold_jewelry = 0;
	pchar.quest_S1_gain_gold_jewelry_text = "";
	pchar.quest_S1_gain_gold = 0;
	pchar.quest_S1_gain_jewelry1 = 0;
	pchar.quest_S1_gain_jewelry2 = 0;
	pchar.quest_S1_gain_jewelry3 = 0;
	pchar.quest_S1_gain_jewelry4 = 0;
	pchar.quest_S1_gain_jewelry5 = 0;
	pchar.quest_S1_gain_jewelry6 = 0;
	pchar.quest_S1_gain_jewelry7 = 0;
	pchar.quest_S1_gain_jewelry8 = 0;
	pchar.quest_S1_gain_jewelry9 = 0;
	pchar.quest_S1_gain_jewelry10 = 0;
	pchar.quest_S1_gain_jewelry11 = 0;
	pchar.quest_S1_gain_jewelry12 = 0;
	pchar.quest_S1_gain_jewelry13 = 0;
	pchar.quest_S1_gain_jewelry14 = 0;
	pchar.quest_S1_gain_jewelry15 = 0;
	pchar.quest_S1_gain_jewelry16 = 0;
	pchar.quest_S1_no_treasure_here_text = 1;
	pchar.quest_S1_final_enabled = true;
	S1_ResetLastQuestConditions();
}

void TreasureHunterNextStep()
{
	ref PChar = GetMainCharacter();
	
	switch (makeint(pchar.quest_S1_numQuests)) {
		case 1://quete n°1 - Conceicao
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 4);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Conceicao_shore_02";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 5);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "Smugglers_Lair_exit";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://CONTINUE STEP
					pchar.quest.quest_S1_step3.win_condition.l1 = "location";
					pchar.quest.quest_S1_step3.win_condition.l1.location = "Conceicao_jungle_01";
					pchar.quest.quest_S1_step3.win_condition = "quest_S1_step3";
				break;
				case 4://CONTINUE STEP
					pchar.quest.quest_S1_step4.win_condition.l1 = "location";
					pchar.quest.quest_S1_step4.win_condition.l1.location = "Conceicao_town_exit";
					pchar.quest.quest_S1_step4.win_condition = "quest_S1_step4";
				break;
				case 5://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = -61;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = -54;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -6;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 0;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = -105;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = -95;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 2://quete n°2 - Conceicao
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 6);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Conceicao_shore_01";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://FINAL STEP
					AddQuestRecord("PJ_S1", 7);
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 1.4;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 5;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = 1;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 3;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = 34;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = 36;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 3://quete n°3 - Douwesen
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 8);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Douwesen_shore_01";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 9);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "Douwesen_jungle_01";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://CONTINUE STEP
					pchar.quest.quest_S1_step3.win_condition.l1 = "location";
					pchar.quest.quest_S1_step3.win_condition.l1.location = "Douwesen_jungle_02";
					pchar.quest.quest_S1_step3.win_condition = "quest_S1_step3";
				break;
				case 4://CONTINUE STEP
					pchar.quest.quest_S1_step4.win_condition.l1 = "location";
					pchar.quest.quest_S1_step4.win_condition.l1.location = "Rheims_house";
					pchar.quest.quest_S1_step4.win_condition = "quest_S1_step4";
				break;
				case 5://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 11;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 19;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = 2;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = 4;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 4://quete n°4 - Douwesen
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 10);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Douwesen_shore_02";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 11);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "Douwesen_jungle_03";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://CONTINUE STEP
					pchar.quest.quest_S1_step3.win_condition.l1 = "location";
					pchar.quest.quest_S1_step3.win_condition.l1.location = "Douwesen_town_exit";
					pchar.quest.quest_S1_step3.win_condition = "quest_S1_step3";
				break;
				case 4://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 35;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 41;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -2;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 1;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = 74;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = 80;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 5://quete n°5 - Fleur de Falaise
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 12);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Falaise_de_Fleur_shore";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://FINAL STEP
					AddQuestRecord("PJ_S1", 13);
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 100;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 126;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = 17;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = 55;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 6://quete n°6 - Fleur de Falaise
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 14);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Falaise_de_Fleur_shore";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 15);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "Falaise_de_Fleur_Jungle";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 11;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -2;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 2;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = -1;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = 2;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 7://quete n°7 - Isla Muelle
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 16);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "muelle_shore";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 17);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "muelle_passage";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 23;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 27;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = 0;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 20;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = -17;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = -7;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 8://quete n°8 - Isla Muelle
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 18);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "muelle_shore";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 19);
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 16;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 23;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = 0;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 20;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = -52;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = -45;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 9://quete n°9 - Quebradas Costillas
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 20);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "QC_port";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 21);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "QC_town_exit";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 13;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 15;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = 20;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = 28;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 10://quete n°10 - Quebradas Costillas
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 22);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "QC_port";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 23);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "QC_town_exit";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://CONTINUE STEP
					pchar.quest.quest_S1_step3.win_condition.l1 = "location";
					pchar.quest.quest_S1_step3.win_condition.l1.location = "QC_pirate_house";
					pchar.quest.quest_S1_step3.win_condition = "quest_S1_step3";
				break;
				case 4://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 17;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 19;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = -10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = -7;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 11://quete n°11 - Redmond
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 24);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Redmond_Shore_01";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://FINAL STEP
					AddQuestRecord("PJ_S1", 25);
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = -12;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = -7;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = 3;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 5;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = -23;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = -18;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 12://quete n°12 - Redmond
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 26);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Redmond_Shore_02";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 27);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "Redmond_jungle_01";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = -60;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = -54;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -3;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = -1;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = -107;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = -98;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 13://quete n°13 - Oxbay
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 28);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Oxbay_shore_02";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 29);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "oxbay_jungle_03";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://CONTINUE STEP
					pchar.quest.quest_S1_step3.win_condition.l1 = "location";
					pchar.quest.quest_S1_step3.win_condition.l1.location = "greenford_town_exit";
					pchar.quest.quest_S1_step3.win_condition = "quest_S1_step3";
				break;
				case 4://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 8;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 14;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = 3;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = 6;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 14://quete n°14 - Oxbay
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 30);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Oxbay_shore_02";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 31);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "oxbay_jungle_03";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://CONTINUE STEP
					pchar.quest.quest_S1_step3.win_condition.l1 = "location";
					pchar.quest.quest_S1_step3.win_condition.l1.location = "oxbay_jungle_02";
					pchar.quest.quest_S1_step3.win_condition = "quest_S1_step3";
				break;
				case 4://CONTINUE STEP
					pchar.quest.quest_S1_step4.win_condition.l1 = "location";
					pchar.quest.quest_S1_step4.win_condition.l1.location = "oxbay_town_exit";
					pchar.quest.quest_S1_step4.win_condition = "quest_S1_step4";
				break;
				case 5://CONTINUE STEP
					pchar.quest.quest_S1_step5.win_condition.l1 = "location";
					pchar.quest.quest_S1_step5.win_condition.l1.location = "oxbay_jungle_01";
					pchar.quest.quest_S1_step5.win_condition = "quest_S1_step5";
				break;
				case 6://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 16;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = 1;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = 4;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 15://quete n°15 - Oxbay
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 32);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Oxbay_shore_01";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 33);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "oxbay_jungle_01";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://CONTINUE STEP
					pchar.quest.quest_S1_step3.win_condition.l1 = "location";
					pchar.quest.quest_S1_step3.win_condition.l1.location = "oxbay_town_exit";
					pchar.quest.quest_S1_step3.win_condition = "quest_S1_step3";
				break;
				case 4://CONTINUE STEP
					pchar.quest.quest_S1_step4.win_condition.l1 = "location";
					pchar.quest.quest_S1_step4.win_condition.l1.location = "oxbay_jungle_02";
					pchar.quest.quest_S1_step4.win_condition = "quest_S1_step4";
				break;
				case 5://CONTINUE STEP
					pchar.quest.quest_S1_step5.win_condition.l1 = "location";
					pchar.quest.quest_S1_step5.win_condition.l1.location = "oxbay_cave_exit";
					pchar.quest.quest_S1_step5.win_condition = "quest_S1_step5";
				break;
				case 6://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 1;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 6;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = 4;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = 6;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 16://quete n°16 - Oxbay
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 34);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Oxbay_shore_01";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 35);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "oxbay_jungle_01";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://CONTINUE STEP
					pchar.quest.quest_S1_step3.win_condition.l1 = "location";
					pchar.quest.quest_S1_step3.win_condition.l1.location = "oxbay_town_exit";
					pchar.quest.quest_S1_step3.win_condition = "quest_S1_step3";
				break;
				case 4://CONTINUE STEP
					pchar.quest.quest_S1_step4.win_condition.l1 = "location";
					pchar.quest.quest_S1_step4.win_condition.l1.location = "oxbay_jungle_02";
					pchar.quest.quest_S1_step4.win_condition = "quest_S1_step4";
				break;
				case 5://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = -8;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 1;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = -14;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = -3;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 17://quete n°17 - Oxbay
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 36);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Oxbay_lighthouse";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://FINAL STEP
					AddQuestRecord("PJ_S1", 37);
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 24;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 27;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = 0;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 30;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = -31;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = -25;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 18://quete n°18 - Oxbay
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 41);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Oxbay_lighthouse";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 42);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "Oxbay_canyon";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = 57;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 61;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = 25;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = 30;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 19://quete n°19 - Redmond
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 43);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "Redmond_Shore_02";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 44);
					pchar.quest.quest_S1_step2.win_condition.l1 = "location";
					pchar.quest.quest_S1_step2.win_condition.l1.location = "Redmond_jungle_01";
					pchar.quest.quest_S1_step2.win_condition = "quest_S1_step2";
				break;
				case 3://CONTINUE STEP
					pchar.quest.quest_S1_step3.win_condition.l1 = "location";
					pchar.quest.quest_S1_step3.win_condition.l1.location = "Redmond_town_exit_2";
					pchar.quest.quest_S1_step3.win_condition = "quest_S1_step3";
				break;
				case 4://FINAL STEP
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = -21;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = -15;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = -20;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 10;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = -55;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = -51;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
		case 20://quete n°20 - Isla Muelle
			switch (makeint(pchar.quest_S1_step)) {
				case 1://FIRST STEP
					AddQuestRecord("PJ_S1", 45);
					pchar.quest.quest_S1_step1.win_condition.l1 = "location";
					pchar.quest.quest_S1_step1.win_condition.l1.location = "muelle_shore";
					pchar.quest.quest_S1_step1.win_condition = "quest_S1_step1";
				break;
				case 2://CONTINUE STEP
					AddQuestRecord("PJ_S1", 46);
					pchar.quest_S1_Unearthing = true;
					pchar.quest.quest_S1_completed_1.win_condition.l1 = "locator_PJ";
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocx = -3;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocx = 0;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocy = 0;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocy = 20;
					pchar.quest.quest_S1_completed_1.win_condition.l1.minLocz = 16;
					pchar.quest.quest_S1_completed_1.win_condition.l1.maxLocz = 19;
					pchar.quest.quest_S1_completed_1.win_condition = "quest_S1_completed_1";
				break;
			}
		break;
	}
}

void GenerateTreasureHunterQuest(string startIsland, int alternativeQuestNumber)
{
	ref PChar = GetMainCharacter();
	int n;

	S1_ClearQuestRuntime();
	pchar.quest_S1_no_treasure_here_text = 1;

	if (rand(makeint(pchar.skill.Sneak)) < 3)
	{
		pchar.quest_S1_gain_gold = 1000 + (75 * makeint(pchar.rank)) + (5 * makeint(pchar.rank) * rand(makeint(pchar.skill.sneak)));
	}
	else
	{
		for (n = 1; n <= 10 + rand(makeint(pchar.rank)); n++)
		{
			if (makeint(pchar.skill.sneak) <= 3)
			{
				switch(rand(24) + 1)
				{
					case 1: pchar.quest_S1_gain_jewelry1 = makeint(pchar.quest_S1_gain_jewelry1) + 1; break;
					case 2: pchar.quest_S1_gain_jewelry2 = makeint(pchar.quest_S1_gain_jewelry2) + 1; break;
					case 3: pchar.quest_S1_gain_jewelry3 = makeint(pchar.quest_S1_gain_jewelry3) + 1; break;
					case 4: pchar.quest_S1_gain_jewelry4 = makeint(pchar.quest_S1_gain_jewelry4) + 1; break;
					case 5: pchar.quest_S1_gain_jewelry5 = makeint(pchar.quest_S1_gain_jewelry5) + 1; break;
					case 6: pchar.quest_S1_gain_jewelry6 = makeint(pchar.quest_S1_gain_jewelry6) + 1; break;
					case 7: pchar.quest_S1_gain_jewelry7 = makeint(pchar.quest_S1_gain_jewelry7) + 1; break;
					case 8: pchar.quest_S1_gain_jewelry8 = makeint(pchar.quest_S1_gain_jewelry8) + 1; break;
					case 9: pchar.quest_S1_gain_jewelry9 = makeint(pchar.quest_S1_gain_jewelry9) + 1; break;
					case 10: pchar.quest_S1_gain_jewelry8 = makeint(pchar.quest_S1_gain_jewelry8) + 1; break;
					case 11: pchar.quest_S1_gain_jewelry9 = makeint(pchar.quest_S1_gain_jewelry9) + 1; break;
					case 12: pchar.quest_S1_gain_jewelry10 = makeint(pchar.quest_S1_gain_jewelry10) + 1; break;
					case 13: pchar.quest_S1_gain_jewelry11 = makeint(pchar.quest_S1_gain_jewelry11) + 1; break;
					case 14: pchar.quest_S1_gain_jewelry12 = makeint(pchar.quest_S1_gain_jewelry12) + 1; break;
					case 15: pchar.quest_S1_gain_jewelry12 = makeint(pchar.quest_S1_gain_jewelry12) + 1; break;
					case 16: pchar.quest_S1_gain_jewelry13 = makeint(pchar.quest_S1_gain_jewelry13) + 1; break;
					case 17: pchar.quest_S1_gain_jewelry14 = makeint(pchar.quest_S1_gain_jewelry14) + 1; break;
					case 18: pchar.quest_S1_gain_jewelry15 = makeint(pchar.quest_S1_gain_jewelry15) + 1; break;
					case 19: pchar.quest_S1_gain_jewelry16 = makeint(pchar.quest_S1_gain_jewelry16) + 1; break;
					case 20: pchar.quest_S1_gain_jewelry16 = makeint(pchar.quest_S1_gain_jewelry16) + 1; break;
				}
			}
			if (makeint(pchar.skill.sneak) > 3 && makeint(pchar.skill.sneak) <= 6)
			{
				switch(rand(21) + 1)
				{
					case 1: pchar.quest_S1_gain_jewelry1 = makeint(pchar.quest_S1_gain_jewelry1) + 1; break;
					case 2: pchar.quest_S1_gain_jewelry1 = makeint(pchar.quest_S1_gain_jewelry1) + 1; break;
					case 3: pchar.quest_S1_gain_jewelry2 = makeint(pchar.quest_S1_gain_jewelry2) + 1; break;
					case 4: pchar.quest_S1_gain_jewelry3 = makeint(pchar.quest_S1_gain_jewelry3) + 1; break;
					case 5: pchar.quest_S1_gain_jewelry3 = makeint(pchar.quest_S1_gain_jewelry3) + 1; break;
					case 6: pchar.quest_S1_gain_jewelry4 = makeint(pchar.quest_S1_gain_jewelry4) + 1; break;
					case 7: pchar.quest_S1_gain_jewelry5 = makeint(pchar.quest_S1_gain_jewelry5) + 1; break;
					case 8: pchar.quest_S1_gain_jewelry6 = makeint(pchar.quest_S1_gain_jewelry6) + 1; break;
					case 9: pchar.quest_S1_gain_jewelry6 = makeint(pchar.quest_S1_gain_jewelry6) + 1; break;
					case 10: pchar.quest_S1_gain_jewelry7 = makeint(pchar.quest_S1_gain_jewelry7) + 1; break;
					case 11: pchar.quest_S1_gain_jewelry10 = makeint(pchar.quest_S1_gain_jewelry10) + 1; break;
					case 12: pchar.quest_S1_gain_jewelry11 = makeint(pchar.quest_S1_gain_jewelry11) + 1; break;
					case 13: pchar.quest_S1_gain_jewelry11 = makeint(pchar.quest_S1_gain_jewelry11) + 1; break;
					case 14: pchar.quest_S1_gain_jewelry13 = makeint(pchar.quest_S1_gain_jewelry13) + 1; break;
					case 15: pchar.quest_S1_gain_jewelry14 = makeint(pchar.quest_S1_gain_jewelry14) + 1; break;
					case 16: pchar.quest_S1_gain_jewelry15 = makeint(pchar.quest_S1_gain_jewelry15) + 1; break;
					case 17: pchar.quest_S1_gain_jewelry14 = makeint(pchar.quest_S1_gain_jewelry14) + 1; break;
					case 18: pchar.quest_S1_gain_jewelry15 = makeint(pchar.quest_S1_gain_jewelry15) + 1; break;
				}
			}
			if (makeint(pchar.skill.sneak) > 6 && makeint(pchar.skill.sneak) <= 9)
			{
				switch(rand(10) + 1)
				{
					case 1: pchar.quest_S1_gain_jewelry2 = makeint(pchar.quest_S1_gain_jewelry2) + 1; break;
					case 2: pchar.quest_S1_gain_jewelry4 = makeint(pchar.quest_S1_gain_jewelry4) + 1; break;
					case 3: pchar.quest_S1_gain_jewelry4 = makeint(pchar.quest_S1_gain_jewelry4) + 1; break;
					case 4: pchar.quest_S1_gain_jewelry5 = makeint(pchar.quest_S1_gain_jewelry5) + 1; break;
					case 5: pchar.quest_S1_gain_jewelry7 = makeint(pchar.quest_S1_gain_jewelry7) + 1; break;
					case 6: pchar.quest_S1_gain_jewelry7 = makeint(pchar.quest_S1_gain_jewelry7) + 1; break;
					case 7: pchar.quest_S1_gain_jewelry10 = makeint(pchar.quest_S1_gain_jewelry10) + 1; break;
					case 8: pchar.quest_S1_gain_jewelry13 = makeint(pchar.quest_S1_gain_jewelry13) + 1; break;
				}
			}
			if (makeint(pchar.skill.sneak) == 10)
			{
				switch(rand(5) + 1)
				{
					case 1: pchar.quest_S1_gain_jewelry2 = makeint(pchar.quest_S1_gain_jewelry2) + 1; break;
					case 2: pchar.quest_S1_gain_jewelry5 = makeint(pchar.quest_S1_gain_jewelry5) + 1; break;
					case 3: pchar.quest_S1_gain_jewelry10 = makeint(pchar.quest_S1_gain_jewelry10) + 1; break;
					case 4: pchar.quest_S1_gain_jewelry13 = makeint(pchar.quest_S1_gain_jewelry13) + 1; break;
				}
			}
		}
	}

	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_gold);
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry1) * 615;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry2) * 1538;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry3) * 769;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry4) * 1153;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry5) * 1538;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry6) * 769;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry7) * 961;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry8) * 384;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry9) * 307;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry10) * 1538;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry11) * 769;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry12) * 384;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry13) * 1538;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry14) * 769;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry15) * 769;
	pchar.quest_S1_gain_gold_jewelry = makeint(pchar.quest_S1_gain_gold_jewelry) + makeint(pchar.quest_S1_gain_jewelry16) * 384;

	if (makeint(pchar.quest_S1_gain_gold) > 0) pchar.quest_S1_gain_gold_jewelry_text = "pieces d'or uniquement.";
	if (makeint(pchar.quest_S1_gain_jewelry1) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry1 + " saphirs.";
	if (makeint(pchar.quest_S1_gain_jewelry2) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry2 + " diamant.";
	if (makeint(pchar.quest_S1_gain_jewelry3) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry3 + " rubis.";
	if (makeint(pchar.quest_S1_gain_jewelry4) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry4 + " emeraudes.";
	if (makeint(pchar.quest_S1_gain_jewelry5) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry5 + " pepites d'or.";
	if (makeint(pchar.quest_S1_gain_jewelry6) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry6 + " bagues en argent et saphirs.";
	if (makeint(pchar.quest_S1_gain_jewelry7) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry7 + " bagues en or et emeraude.";
	if (makeint(pchar.quest_S1_gain_jewelry8) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry8 + " bagues en bronze.";
	if (makeint(pchar.quest_S1_gain_jewelry9) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry9 + " croix en bronze.";
	if (makeint(pchar.quest_S1_gain_jewelry10) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry10 + " bagues en or et saphirs.";
	if (makeint(pchar.quest_S1_gain_jewelry11) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry11 + " grosses perles.";
	if (makeint(pchar.quest_S1_gain_jewelry12) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry12 + " petites perles.";
	if (makeint(pchar.quest_S1_gain_jewelry13) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry13 + " broches en argent.";
	if (makeint(pchar.quest_S1_gain_jewelry14) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry14 + " broches en or.";
	if (makeint(pchar.quest_S1_gain_jewelry15) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry15 + " pendetifs en emeraude.";
	if (makeint(pchar.quest_S1_gain_jewelry16) > 0) pchar.quest_S1_gain_gold_jewelry_text = pchar.quest_S1_gain_gold_jewelry_text + pchar.quest_S1_gain_jewelry16 + " colliers en pierres precieuses.";

	pchar.quest_S1_numQuests = makeint(rand(makeint(pchar.quest_S1_nbQuests) - 1)) + 1;
	switch (makeint(pchar.quest_S1_numQuests))
	{
		case 1: if (pchar.quest_S1_treasure_hunter_1_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 2: if (pchar.quest_S1_treasure_hunter_2_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 3: if (pchar.quest_S1_treasure_hunter_3_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 4: if (pchar.quest_S1_treasure_hunter_4_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 5: if (pchar.quest_S1_treasure_hunter_5_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 6: if (pchar.quest_S1_treasure_hunter_6_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 7: if (pchar.quest_S1_treasure_hunter_7_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 8: if (pchar.quest_S1_treasure_hunter_8_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 9: if (pchar.quest_S1_treasure_hunter_9_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 10: if (pchar.quest_S1_treasure_hunter_10_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 11: if (pchar.quest_S1_treasure_hunter_11_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 12: if (pchar.quest_S1_treasure_hunter_12_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 13: if (pchar.quest_S1_treasure_hunter_13_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 14: if (pchar.quest_S1_treasure_hunter_14_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 15: if (pchar.quest_S1_treasure_hunter_15_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 16: if (pchar.quest_S1_treasure_hunter_16_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 17: if (pchar.quest_S1_treasure_hunter_17_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 18: if (pchar.quest_S1_treasure_hunter_18_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 19: if (pchar.quest_S1_treasure_hunter_19_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
		case 20: if (pchar.quest_S1_treasure_hunter_20_win_condition_step1_island == startIsland) pchar.quest_S1_numQuests = alternativeQuestNumber; break;
	}

	switch (makeint(pchar.quest_S1_numQuests))
	{
		case 1: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_1_win_condition_step1_island; break;
		case 2: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_2_win_condition_step1_island; break;
		case 3: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_3_win_condition_step1_island; break;
		case 4: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_4_win_condition_step1_island; break;
		case 5: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_5_win_condition_step1_island; break;
		case 6: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_6_win_condition_step1_island; break;
		case 7: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_7_win_condition_step1_island; break;
		case 8: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_8_win_condition_step1_island; break;
		case 9: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_9_win_condition_step1_island; break;
		case 10: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_10_win_condition_step1_island; break;
		case 11: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_11_win_condition_step1_island; break;
		case 12: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_12_win_condition_step1_island; break;
		case 13: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_13_win_condition_step1_island; break;
		case 14: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_14_win_condition_step1_island; break;
		case 15: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_15_win_condition_step1_island; break;
		case 16: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_16_win_condition_step1_island; break;
		case 17: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_17_win_condition_step1_island; break;
		case 18: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_18_win_condition_step1_island; break;
		case 19: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_19_win_condition_step1_island; break;
		case 20: pchar.quest_S1_island = pchar.quest_S1_treasure_hunter_20_win_condition_step1_island; break;
	}
}

void S1_ProcessLocationEnter()
{
	ref pchar = GetMainCharacter();
	string homelocation;
	string starterVisibleAttr;

	homelocation = pchar.location;

	PlaceCharacter(characterFromID("Elizabeth Goodale TQC 1"), "goto", "none");
	PlaceCharacter(characterFromID("Elizabeth Goodale TQC 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 1 1"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 1 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 1 3"), "goto", "none");
	PlaceCharacter(characterFromID("Eustache Busket TQC 1"), "goto", "none");
	PlaceCharacter(characterFromID("Eustache Busket TQC 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 2 1"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 2 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 2 3"), "goto", "none");
	PlaceCharacter(characterFromID("Bartolomeo Portugues TQC 1"), "goto", "none");
	PlaceCharacter(characterFromID("Bartolomeo Portugues TQC 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 3 1"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 3 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 3 3"), "goto", "none");
	PlaceCharacter(characterFromID("Benito Bonito TQC 1"), "goto", "none");
	PlaceCharacter(characterFromID("Benito Bonito TQC 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 4 1"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 4 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 4 3"), "goto", "none");
	PlaceCharacter(characterFromID("Hendrick van Hoven TQC 1"), "goto", "none");
	PlaceCharacter(characterFromID("Hendrick van Hoven TQC 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 5 1"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 5 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 5 3"), "goto", "none");
	PlaceCharacter(characterFromID("Wimund TQC 1"), "goto", "none");
	PlaceCharacter(characterFromID("Wimund TQC 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 6 1"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 6 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 6 3"), "goto", "none");
	PlaceCharacter(characterFromID("Samuel Bellamy TQC 1"), "goto", "none");
	PlaceCharacter(characterFromID("Samuel Bellamy TQC 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 7 1"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 7 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 7 3"), "goto", "none");
	PlaceCharacter(characterFromID("Edward Thatch TQC 1"), "goto", "none");
	PlaceCharacter(characterFromID("Edward Thatch TQC 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 8 1"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 8 2"), "goto", "none");
	PlaceCharacter(characterFromID("TQC for fight 8 3"), "goto", "none");
	PlaceCharacter(characterFromID("Youyi TQC 1"), "goto", "none");
	PlaceCharacter(characterFromID("Youyi TQC 2"), "goto", "none");

	if (pchar.quest_S1_step == 0)
	{
		starterVisibleAttr = S1_GetStarterVisibleAttr("Redmond");
		if (rand(3) >= 0 && pchar.location == "Redmond_town_01" && CheckAttribute(pchar, starterVisibleAttr) && sti(pchar.(starterVisibleAttr)) == true)
		{
			PlaceCharacter(characterFromID("Elizabeth Goodale TQC 1"), "goto", homelocation);
		}

		starterVisibleAttr = S1_GetStarterVisibleAttr("FleurDeFalaise");
		if (rand(3) >= 0 && pchar.location == "Falaise_de_fleur_port_02" && CheckAttribute(pchar, starterVisibleAttr) && sti(pchar.(starterVisibleAttr)) == true)
		{
			PlaceCharacter(characterFromID("Eustache Busket TQC 1"), "goto", homelocation);
		}

		starterVisibleAttr = S1_GetStarterVisibleAttr("Conceicao");
		if (rand(3) >= 0 && pchar.location == "Conceicao_town" && CheckAttribute(pchar, starterVisibleAttr) && sti(pchar.(starterVisibleAttr)) == true)
		{
			PlaceCharacter(characterFromID("Bartolomeo Portugues TQC 1"), "goto", homelocation);
		}

		starterVisibleAttr = S1_GetStarterVisibleAttr("IslaMuelle");
		if (rand(3) >= 0 && pchar.location == "Muelle_town_02" && CheckAttribute(pchar, starterVisibleAttr) && sti(pchar.(starterVisibleAttr)) == true)
		{
			PlaceCharacter(characterFromID("Benito Bonito TQC 1"), "goto", homelocation);
		}

		starterVisibleAttr = S1_GetStarterVisibleAttr("Douwesen");
		if (rand(3) >= 0 && pchar.location == "Douwesen_town" && CheckAttribute(pchar, starterVisibleAttr) && sti(pchar.(starterVisibleAttr)) == true)
		{
			PlaceCharacter(characterFromID("Hendrick van Hoven TQC 1"), "goto", homelocation);
		}

		starterVisibleAttr = S1_GetStarterVisibleAttr("Oxbay_Greenford");
		if (rand(3) >= 0 && pchar.location == "Greenford_town" && CheckAttribute(pchar, starterVisibleAttr) && sti(pchar.(starterVisibleAttr)) == true)
		{
			PlaceCharacter(characterFromID("Wimund TQC 1"), "goto", homelocation);
		}

		starterVisibleAttr = S1_GetStarterVisibleAttr("Oxbay_Oxbay");
		if (rand(3) >= 0 && pchar.location == "Oxbay_town" && CheckAttribute(pchar, starterVisibleAttr) && sti(pchar.(starterVisibleAttr)) == true)
		{
			PlaceCharacter(characterFromID("Samuel Bellamy TQC 1"), "goto", homelocation);
		}

		starterVisibleAttr = S1_GetStarterVisibleAttr("QuebradasCostillas");
		if (rand(3) >= 0 && pchar.location == "QC_town" && CheckAttribute(pchar, starterVisibleAttr) && sti(pchar.(starterVisibleAttr)) == true)
		{
			PlaceCharacter(characterFromID("Edward Thatch TQC 1"), "goto", homelocation);
		}

		if (pchar.location == "QC_town" && pchar.quest_S1_allQuestsCompleted == true)
		{
			PlaceCharacter(characterFromID("Youyi TQC 1"), "goto", homelocation);
		}
	}
}

bool QuestComplete_S1(string sQuestName)
{
	ref PChar = GetMainCharacter();
	ref rCrew_leader, rCrew1, rCrew2, rCrew3;
	string leaderId, crew1Id, crew2Id, crew3Id, starterId, starterVisibleAttr;
	string homelocation, homelocator;
	int n;

	switch(sQuestName)
	{
		case "quest_S1_agreeded":
			DeleteQuestHeader("PJ_S1");
			SetQuestHeader("PJ_S1");
			pchar.quest_S1_step = 1;
			TreasureHunterNextStep();
			return true;
		break;

		case "quest_S1_step1":
			pchar.quest_S1_step = makeint(pchar.quest_S1_step) + 1;
			TreasureHunterNextStep();
			return true;
		break;

		case "quest_S1_step2":
			Log_SetStringToLog("C'est le bon chemin, continu !");
			pchar.quest_S1_step = makeint(pchar.quest_S1_step) + 1;
			TreasureHunterNextStep();
			return true;
		break;

		case "quest_S1_step3":
			Log_SetStringToLog("C'est le bon chemin, continu !");
			pchar.quest_S1_step = makeint(pchar.quest_S1_step) + 1;
			TreasureHunterNextStep();
			return true;
		break;

		case "quest_S1_step4":
			Log_SetStringToLog("C'est le bon chemin, continu !");
			pchar.quest_S1_step = makeint(pchar.quest_S1_step) + 1;
			TreasureHunterNextStep();
			return true;
		break;

		case "quest_S1_step5":
			Log_SetStringToLog("C'est le bon chemin, continu !");
			pchar.quest_S1_step = makeint(pchar.quest_S1_step) + 1;
			TreasureHunterNextStep();
			return true;
		break;

		case "quest_S1_completed_1":
			leaderId = S1_GetLeaderId(pchar.quest_S1_startIsland);
			if (leaderId == "")
			{
				DoQuestCheckDelay("quest_S1_closed", 0.0);
				return true;
			}
			if (pchar.quest_S1_failed == true)
			{
				ChangeCharacterReputation(pchar, -1);
				AddQuestRecord("PJ_S1", "2");
				Log_SetStringToLog(GlobalStringConvert("PJ_S1_failed"));
				DoQuestCheckDelay("quest_S1_closed", 1.0);
				return true;
			}
			AddQuestRecord("PJ_S1", "1");
			homelocation = pchar.location;
			rCrew_leader = characterFromID(leaderId);
			PlaceCharacter(rCrew_leader, "goto", homelocation);
			LAi_SetActorType(rCrew_leader);
			LAi_SetActorType(pchar);
			LAi_ActorFollow(pchar, rCrew_leader, "", 2.0);
			LAi_ActorFollow(rCrew_leader, pchar, "quest_S1_completed_2", 2.0);
			return true;
		break;

		case "quest_S1_completed_2":
			leaderId = S1_GetLeaderId(pchar.quest_S1_startIsland);
			if (leaderId == "")
			{
				return true;
			}
			AddPartyExp(pchar, makeint(pchar.rank) * 1000);
			LAi_type_actor_Reset(pchar);
			rCrew_leader = characterFromID(leaderId);
			LAi_ActorWaitDialog(pchar, rCrew_leader);
			LAi_ActorDialog(rCrew_leader, pchar, "pchar_back_to_player", 2.0, 1.0);
			characters[GetCharacterIndex(leaderId)].dialog.currentnode = "complete_quest";
			return true;
		break;

		case "quest_S1_fight":
			leaderId = S1_GetLeaderId(pchar.quest_S1_startIsland);
			starterId = S1_GetStarterId(pchar.quest_S1_startIsland);
			starterVisibleAttr = S1_GetStarterVisibleAttr(pchar.quest_S1_startIsland);
			if (leaderId == "" || starterId == "" || !S1_GetFightCrewIds(pchar.quest_S1_startIsland, &crew1Id, &crew2Id, &crew3Id))
			{
				DoQuestCheckDelay("quest_S1_closed", 0.0);
				return true;
			}

			homelocation = pchar.location;
			pchar.(starterVisibleAttr) = false;
			PlaceCharacter(characterFromID(starterId), "goto", "none");

			rCrew_leader = characterFromID(leaderId);
			rCrew1 = characterFromID(crew1Id);
			rCrew2 = characterFromID(crew2Id);
			rCrew3 = characterFromID(crew3Id);

			PlaceCharacter(rCrew_leader, "goto", homelocation);
			LAi_group_MoveCharacter(rCrew_leader, "S1_FIGHT");
			Pchar.quest.quest_S1_fight_won.win_condition.l1 = "NPC_Death";
			Pchar.quest.quest_S1_fight_won.win_condition.l1.character = leaderId;

			PlaceCharacter(rCrew1, "goto", homelocation);
			PlaceCharacter(rCrew2, "goto", homelocation);
			PlaceCharacter(rCrew3, "goto", homelocation);
			LAi_RemoveCheckMinHP(rCrew1);
			LAi_RemoveCheckMinHP(rCrew2);
			LAi_RemoveCheckMinHP(rCrew3);
			LAi_group_MoveCharacter(rCrew1, "S1_FIGHT");
			LAi_group_MoveCharacter(rCrew2, "S1_FIGHT");
			LAi_group_MoveCharacter(rCrew3, "S1_FIGHT");

			Pchar.quest.quest_S1_fight_won.win_condition.l2 = "NPC_Death";
			Pchar.quest.quest_S1_fight_won.win_condition.l2.character = crew1Id;
			Pchar.quest.quest_S1_fight_won.win_condition.l3 = "NPC_Death";
			Pchar.quest.quest_S1_fight_won.win_condition.l3.character = crew2Id;
			Pchar.quest.quest_S1_fight_won.win_condition.l4 = "NPC_Death";
			Pchar.quest.quest_S1_fight_won.win_condition.l4.character = crew3Id;
			Pchar.quest.quest_S1_fight_won.win_condition = "quest_S1_fight_won";

			LAi_group_FightGroups("S1_FIGHT", LAI_GROUP_PLAYER, true);
			return true;
		break;

		case "quest_S1_fight_won":
			ChangeCharacterReputation(pchar, -5);
			AddPartyExp(pchar, 50000);

			AddMoneyToCharacter(pchar, makeint(pchar.quest_S1_gain_gold) * 20);
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry1) * 20; n++) {GiveItem2Character(Pchar, "jewelry1");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry2) * 20; n++) {GiveItem2Character(Pchar, "jewelry2");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry3) * 20; n++) {GiveItem2Character(Pchar, "jewelry3");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry4) * 20; n++) {GiveItem2Character(Pchar, "jewelry4");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry5) * 20; n++) {GiveItem2Character(Pchar, "jewelry5");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry6) * 20; n++) {GiveItem2Character(Pchar, "jewelry6");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry7) * 20; n++) {GiveItem2Character(Pchar, "jewelry7");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry8) * 20; n++) {GiveItem2Character(Pchar, "jewelry8");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry9) * 20; n++) {GiveItem2Character(Pchar, "jewelry9");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry10) * 20; n++) {GiveItem2Character(Pchar, "jewelry10");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry11) * 20; n++) {GiveItem2Character(Pchar, "jewelry11");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry12) * 20; n++) {GiveItem2Character(Pchar, "jewelry12");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry13) * 20; n++) {GiveItem2Character(Pchar, "jewelry13");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry14) * 20; n++) {GiveItem2Character(Pchar, "jewelry14");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry15) * 20; n++) {GiveItem2Character(Pchar, "jewelry15");}
			for(n = 1; n <= makeint(pchar.quest_S1_gain_jewelry16) * 20; n++) {GiveItem2Character(Pchar, "jewelry16");}

			AddQuestRecord("PJ_S1", "3");
			DoQuestCheckDelay("quest_S1_closed", 1.0);
			return true;
		break;

		case "quest_S1_closed":
			CloseQuestHeader("PJ_S1");

			leaderId = S1_GetLeaderId(pchar.quest_S1_startIsland);
			if (leaderId != "")
			{
				rCrew_leader = characterFromID(leaderId);
				LAi_ActorGoToLocation(rCrew_leader, "reload", homelocator, "none", "", "", "", 10.0);
			}

			S1_ResetQuestConditions();
			S1_MarkCurrentQuestCompleted();
			if (S1_DEV_COMPLETE_ALL_QUESTS_ON_WIN == true)
			{
				S1_MarkAllQuestsCompleted();
			}
			if (makeint(pchar.quest_S1_final_enabled) == true && makeint(S1_CountCompletedQuests()) == makeint(pchar.quest_S1_nbQuests))
			{
				pchar.quest_S1_allQuestsCompleted = true;
				S1_ClearCompletedQuestFlags();
			}
			else
			{
				pchar.quest_S1_allQuestsCompleted = false;
			}
			S1_ClearQuestRuntime();
			return true;
		break;
	}

	return false;
}


