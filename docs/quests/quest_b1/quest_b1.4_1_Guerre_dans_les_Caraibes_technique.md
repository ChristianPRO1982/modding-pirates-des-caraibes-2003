# B1.4 - Guerre dans les Caraibes - Technique

## Overview

`B1.4` est le bloc de resolution a embranchements.

Il couvre:

- `B1.4a - Guerre dans les Caraibes`
- `B1.4b - Guerre dans les Caraibes - La Confrerie de Shango`
- `B1.4c - Guerre dans les Caraibes - destruction de la Confrerie de Shango`
- `B1.4d - Guerre dans les Caraibes - l'Eglise contre la Confrerie de Shango`

Cette partie doit:

- convertir l'issue de `B1.3` en branche finale;
- laisser un court point de choix au joueur neutre;
- proposer une route Shango;
- proposer une route hispano-portugaise seculiere;
- proposer une route franco-ecclesiale complete avec Inty puis infiltration de Shango;
- mener jusqu'au duel final contre Silehard et a la solution du sosie.

## Documents

- `docs/quests/quest_b1/quest_b1.4_1_Guerre_dans_les_Caraibes_technique.md`
- `docs/quests/quest_b1/quest_b1.4_2_Guerre_dans_les_Caraibes_pilotage.md`
- `docs/quests/quest_b1/quest_b1.4_3_Guerre_dans_les_Caraibes_questbook.md`
- `docs/quests/quest_b1/quest_b1.4_4_Guerre_dans_les_Caraibes_dialogues.md`

## Branch Selector

Sortie de `B1.3` -> branche `B1.4`:

| Condition | Branche |
|---|---|
| joueur neutre | `B1.4a` |
| joueur aligne anglo-hollandais / route Shango | `B1.4b` |
| joueur hispano-portugais sans route francaise complete | `B1.4c` |
| joueur hispano-portugais + France engagee + fille sauvee vivante | `B1.4d` |

## Scope of Each Branch

### `B1.4a`

- mini-quete de choix de camp;
- but: sortir de la neutralite et rebrancher vers `B1.4b` ou `B1.4c`.

### `B1.4b`

- integration du joueur dans la Confrerie de Shango;
- missions de bras arme;
- choix de rester corsaire ou d'integrer plus profondement la structure.

### `B1.4c`

- route hispano-portugaise;
- reconnaissance du controle de Shango sur les gouvernements anglais et hollandais;
- destruction des forces armees puis decapitation de la secte;
- remplacement de Silehard par un sosie en sortie.

### `B1.4d`

- route francaise et ecclesiale;
- revelation de la guerre secrete Inty/Shango;
- fin d'Inty;
- infiltration de Shango avec Danielle Greene;
- destruction interne;
- fregate des dignitaires;
- convoi de poudre;
- duel final contre Silehard;
- solution politique du sosie.

## State Machine

Etat global recommande:

```text
branch_select
b1_4a_active
b1_4a_completed
b1_4b_active
b1_4b_completed
b1_4c_active
b1_4c_completed
b1_4d_active
b1_4d_inty_phase
b1_4d_shango_infiltration
b1_4d_dignitaries_destroyed
b1_4d_powder_convoy
b1_4d_silehard_finale
epilogue_sosie
completed
```

## Shared Final Structure

Malgre les branches, le dernier bloc narratif doit converger autant que possible vers:

1. affaiblissement terminal de Shango;
2. confrontation directe ou quasi directe avec Silehard;
3. duel final;
4. mort de Silehard ou mort du joueur par trahison si le choix "accepter" est retenu;
5. solution politique du sosie pour etouffer la verite.

## Suggested Flags

| Flag | Role |
|---|---|
| `pchar.quest_b1_4_branch` | branche choisie |
| `pchar.quest_b1_4_status` | etat global |
| `pchar.quest_b1_4a_choice_done` | neutre sorti de sa neutralite |
| `pchar.quest_b1_4b_shango_rank` | profondeur d'integration a Shango |
| `pchar.quest_b1_4c_shango_exposed` | reconnaissance politique de Shango |
| `pchar.quest_b1_4d_inty_destroyed` | Inty purgee |
| `pchar.quest_b1_4d_shango_infiltrated` | infiltration reussie |
| `pchar.quest_b1_silehard_alive` | etat final de Silehard |
| `pchar.quest_b1_silehard_double_installed` | sosie en place |

## Runtime Surfaces

Fichiers cibles probables:

- `PROGRAM/QUESTS/quests_reaction.c`
- `PROGRAM/DIALOGS/PJ Quest B1 Robert Christopher Silehard_dialog.c`
- dialogues de Danielle Greene;
- dialogues des gouverneurs francais / espagnols / portugais;
- dialogues des autorites religieuses;
- `TempQuestCharacters.c`;
- `quests_texts.txt`.

## Tone Constraints

- `B1.4b` peut assumer l'absurde rituel de Shango, mais sans casser la menace;
- `B1.4d` peut devenir plus grave et plus revelateur;
- le duel final contre Silehard doit rester le point de convergence dramatique;
- le sosie doit etre traite comme une solution politique absurde mais froide.

## Anti-patterns

- Faire quatre branches totalement sans points communs.
- Reveler toute la verite sur Shango avant `B1.4`.
- Oublier la convergence finale sur Silehard et le sosie.
- Traiter Inty comme aussi fanatique et irreconciliable que Shango sur la route `B1.4d`.
