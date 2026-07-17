# B1.3 - La Valse des Felons et Tourne-Casaques - Technique

## Overview

`B1.3` couvre:

- `B1.3 - La Valse des Felons et Tourne-Casaques`
- `B1.3a - Kidnaping de la fille du gouverneur francais`

Cette partie est la campagne de guerre de l'arc `B1`.

Elle doit:

- faire vivre la "drole de guerre" issue de `B1.2`;
- donner au joueur dix missions de guerre et de duplicite;
- memoriser ses fidelites, trahisons et succes;
- ouvrir eventuellement l'entree de la France via `B1.3a`;
- produire l'issue politique qui branche vers `B1.4a`, `B1.4b`, `B1.4c` ou `B1.4d`.

## Documents

- `docs/quests/quest_b1/quest_b1.3_1_La_Valse_des_Felons_et_Tourne_Casaques_technique.md`
- `docs/quests/quest_b1/quest_b1.3_2_La_Valse_des_Felons_et_Tourne_Casaques_pilotage.md`
- `docs/quests/quest_b1/quest_b1.3_3_La_Valse_des_Felons_et_Tourne_Casaques_questbook.md`
- `docs/quests/quest_b1/quest_b1.3_4_La_Valse_des_Felons_et_Tourne_Casaques_dialogues.md`

## Scope

`B1.3` n'est pas une seule mission longue mais une campagne.

Contraintes:

- dix missions principales maximum;
- une meme ossature doit supporter plusieurs choix de loyaute;
- `B1.3a` reste une branche laterale structurelle, pas une quete completement separee du reste de la campagne;
- les resultats doivent pouvoir se resumer par des compteurs et quelques flags clefs;
- la France reste neutre jusqu'a l'evenement de la fille du gouverneur.

## Availability

Conditions cibles:

- `B1.2b` terminee;
- timer de quatorze jours arrive a son terme;
- relations de guerre posees;
- `pchar.quest_b1_3_available = "yes"`.

## Quest Headers

Headers recommandes:

```text
PJ_B1_3
PJ_B1_3A
```

## Campaign Model

La campagne `B1.3` doit etre pensee comme une boucle:

1. attribution de mission;
2. execution;
3. debriefing;
4. lecture de loyaute / trahison;
5. mise a jour des scores;
6. mission suivante.

## Mission Families

Les dix missions n'ont pas encore toutes leur nom final, mais elles doivent rester dans ces familles:

1. renseignement / espionnage;
2. sabotage;
3. escorte;
4. diplomatie sous contrainte;
5. action navale limitee;
6. transport ou liaison sensible;
7. operation de prisonnier / extraction;
8. faux drapeau ou manipulation;
9. mission de pression politique;
10. operation de cloture de campagne.

## State Machine

Etat global recommande:

```text
not_started
war_declared
mission_01_open
mission_01_done
mission_02_open
...
mission_10_open
mission_10_done
b1_3a_offer
b1_3a_active
b1_3a_completed
campaign_resolution
b1_4_ready
```

## Scoring Model

Compteurs recommandes:

| Flag | Role |
|---|---|
| `pchar.quest_b1_3_score_england_holland` | Points donnes au camp anglo-hollandais |
| `pchar.quest_b1_3_score_spain_portugal` | Points donnes au camp hispano-portugais |
| `pchar.quest_b1_3_betrayal_count` | Nombre de trahisons ouvertes |
| `pchar.quest_b1_3_missions_completed` | Missions principales accomplies |
| `pchar.quest_b1_3_alignment` | Tendance finale du joueur |

## Resolution Families

Sept fins cibles au niveau politique:

1. neutre;
2. allie Angleterre-Hollande;
3. incorpore Angleterre-Hollande;
4. hero Angleterre-Hollande;
5. allie Espagne-Portugal;
6. incorpore Espagne-Portugal;
7. hero Espagne-Portugal.

Ces fins doivent ensuite determiner le branchement vers `B1.4`.

## `B1.3a` Trigger

Condition narrative cible:

- si le joueur a obtenu six victoires confirmees pour le camp hispano-portugais;
- si la France est encore neutre;
- alors le gouverneur francais signale le kidnaping de sa fille.

`B1.3a` doit:

- prouver que Shango veut maintenir la France hors du conflit;
- permettre de sauver la fille vivante;
- ouvrir ensuite la possibilite de `B1.4d`.

## France Entry Logic

Etats minimaux:

- `not_considering_entry`
- `considering_entry`
- `daughter_kidnapped`
- `daughter_rescued_alive`
- `france_enters_war`
- `france_remains_neutral`

## Runtime Surfaces

Fichiers cibles probables:

- `PROGRAM/QUESTS/quests_reaction.c`
- `PROGRAM/DIALOGS/...` des gouverneurs et contacts de guerre
- `PROGRAM/Characters/French/init/TempQuestCharacters.c`
- `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`

Fichiers potentiellement touches plus tard:

- relations entre nations;
- eventuels PNJ-officiers recrutables;
- navires et escortes de mission.

## Suggested Flags

| Flag | Role |
|---|---|
| `pchar.quest_b1_3_status` | Etat global de campagne |
| `pchar.quest_b1_3_current_mission` | Mission active `01..10` |
| `pchar.quest_b1_3_score_england_holland` | Score camp 1 |
| `pchar.quest_b1_3_score_spain_portugal` | Score camp 2 |
| `pchar.quest_b1_3_betrayal_count` | Trahisons |
| `pchar.quest_b1_3a_status` | Etat de la fille du gouverneur |
| `pchar.quest_b1_france_status` | Etat politique francais |
| `pchar.quest_b1_3_final_outcome` | Une des 7 resolutions |
| `pchar.quest_b1_4_branch` | Branche suivante retenue |

## Branches to `B1.4`

Sorties cibles:

- neutre -> `B1.4a`
- route Shango / anglo-hollandaise -> `B1.4b`
- route hispano-portugaise sans France salvatrice -> `B1.4c`
- route hispano-portugaise avec France engagee et fille sauvee -> `B1.4d`

## Anti-patterns

- Ecrire dix quetes sans ossature commune.
- Faire de `B1.3a` une quete independante sans effet geopolitique.
- Ne memoriser que le dernier camp choisi au lieu d'un historique de campagne.
- Oublier de preparer la branche `B1.4` a la fin de `B1.3`.
