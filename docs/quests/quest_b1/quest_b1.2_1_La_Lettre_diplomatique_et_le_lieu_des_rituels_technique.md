# B1.2 - La Lettre diplomatique et le lieu des rituels - Technique

## Overview

`B1.2` couvre deux sous-quetes consecutives:

- `B1.2a - La Lettre de cachet et le cadeau diplomatique`
- `B1.2b - La Lettre derobee`

Ce bloc doit:

- transformer la confiance acquise en `B1.1` en implication politique;
- faire disparaitre la lettre et le cadeau diplomatique;
- introduire les faux soldats anglais, l'espion francais et le lieu des rituels;
- faire echouer definitivement l'accord Portugal-Angleterre;
- lancer la guerre apres un delai de quatorze jours;
- preparer `B1.3`.

Ce document fait autorite pour la logique technique cible de `B1.2`.

## Documents

`B1.2` repose sur quatre documents coeur, completes par une annexe de dialogues pour `B1.2a`:

- `docs/quests/quest_b1/quest_b1.2_1_La_Lettre_diplomatique_et_le_lieu_des_rituels_technique.md`
- `docs/quests/quest_b1/quest_b1.2_2_La_Lettre_diplomatique_et_le_lieu_des_rituels_pilotage.md`
- `docs/quests/quest_b1/quest_b1.2_3_La_Lettre_diplomatique_et_le_lieu_des_rituels_questbook.md`
- `docs/quests/quest_b1/quest_b1.2_4_La_Lettre_diplomatique_et_le_lieu_des_rituels_dialogues.md`
- `docs/quests/quest_b1/quest_b1.2_4_La_Lettre_diplomatique_et_le_lieu_des_rituels_dialogues_b1_2a.md`

## Scope

Contraintes:

- aucun nouvel asset binaire obligatoire;
- garder la narration centree sur le doute et l'enquete;
- `B1.2a` doit etre surtout une quete d'enquete et de deplacement;
- `B1.2b` doit ajouter une vraie phase navale et une confrontation terrestre;
- la lettre et le cadeau ne doivent pas etre recupereables dans `B1.2`;
- la guerre ne doit pas eclater tout de suite, mais apres un delai controle.

## Availability

Conditions cibles:

- `B1.1` terminee;
- Silehard deja sur `Robert Christopher Silehard PJ_dialog.c`;
- `B1.2a` disponible apres la fermeture propre de `B1.1`;
- `B1.2b` disponible seulement apres la fin de `B1.2a`;
- `B1.3` disponible automatiquement quatorze jours apres la fin de `B1.2b`.

## Quest Headers

Headers recommandes:

```text
PJ_B1_2A
PJ_B1_2B
```

Note complementaire:

- le dossier contient deja `quest_b1_shango_history_4_questbook.md`, qui prevoit aussi un livre de bord fil rouge pour l'ensemble de `B1`;
- ce fil rouge n'a pas besoin d'etre implemente en meme temps que les headers de sous-quete.

## Core Loop

### B1.2a

1. Le gouverneur portugais remet la lettre et le cadeau au joueur.
2. Le joueur rejoint Redmond.
3. Une scene nocturne declenche l'interception par de faux soldats anglais.
4. Un vieillard francais oriente l'enquete vers Douwesen.
5. Le joueur identifie l'origine hollandaise des faux soldats.
6. Il choisit a quel gouverneur rapporter l'affaire.
7. Il fouille une cabane et trouve une note mentionnant le lieu des rituels.
8. Il retrouve l'espion francais a Falaise de Fleur.
9. `B1.2a` se ferme et `B1.2b` s'ouvre.

### B1.2b

1. Silehard relance l'enquete.
2. Des soldats anglais guident le joueur vers le lieu des rituels.
3. Le joueur detruit une protection navale a Isla Muelle.
4. Il atteint le site terrestre.
5. Les Hollandais dissidents avouent avoir double leur propre organisation pour l'or.
6. Tous meurent.
7. Ni la lettre ni le cadeau ne sont retrouves.
8. Silehard reagit avec colere.
9. Un delai de quatorze jours prepare la guerre.
10. `B1.3` se declenche automatiquement.

## State Machine

Etat global recommande:

```text
not_started
b1_2a_offer
b1_2a_delivery
b1_2a_redmond_night
b1_2a_stolen
b1_2a_douwesen_inquiry
b1_2a_report_choice
b1_2a_cabin_search
b1_2a_completed
b1_2b_offer
b1_2b_devils_throat
b1_2b_naval_assault
b1_2b_ritual_site
b1_2b_dissidents_dead
b1_2b_no_objects
b1_2b_completed
b1_2b_war_timer
b1_3_ready
```

Branche critique:

```text
B1.2a report choice
   |
   +--> report to Portuguese governor
   |
   +--> report to English governor
```

Cette branche:

- ne change pas la narration immediate;
- memorise seulement une trace de fidelite;
- sert de bonus differe a la fin de `B1.3`.

## Invariants

- la lettre et le cadeau ne doivent pas rester utilisables apres la scene de vol;
- les faux soldats ne doivent pas etre combattables pendant l'interception;
- l'espion francais doit rester ambigu mais utile;
- l'enquete a Douwesen doit confirmer l'origine hollandaise sans reveler encore Shango;
- `B1.2b` doit donner une victoire militaire et un echec diplomatique;
- aucun survivant dissident ne doit rester interrogable apres la confrontation;
- le declenchement de guerre doit etre differe de quatorze jours;
- `B1.3` doit partir automatiquement, pas via un nouveau PNJ aleatoire.

## Suggested Flags

| Flag | Role |
|---|---|
| `pchar.quest_b1_2_status` | Etat global de `B1.2` |
| `pchar.quest_b1_2a_status` | Etat de `B1.2a` |
| `pchar.quest_b1_2b_status` | Etat de `B1.2b` |
| `pchar.quest_b1_2a_report_target` | `portugal` ou `england` |
| `pchar.quest_b1_2a_douwesen_witnesses` | Nombre de temoignages valides |
| `pchar.quest_b1_2a_note_found` | Note du lieu des rituels trouvee |
| `pchar.quest_b1_2b_fleet_destroyed` | Flotte detruite |
| `pchar.quest_b1_2b_dissidents_dead` | Tous les Hollandais morts |
| `pchar.quest_b1_2b_letter_missing` | Lettre toujours perdue |
| `pchar.quest_b1_2b_gift_missing` | Cadeau toujours perdu |
| `pchar.quest_b1_2b_war_timer_started` | Timer de quatorze jours lance |
| `pchar.quest_b1_3_available` | Ouverture de `B1.3` |

## Runtime Surfaces

Fichiers cibles probables:

- `PROGRAM/DIALOGS/Robert Christopher Silehard PJ_dialog.c`
- `PROGRAM/DIALOGS/French/Robert Christopher Silehard PJ_dialog.h`
- `PROGRAM/QUESTS/quests_reaction.c`
- `PROGRAM/Characters/French/init/TempQuestCharacters.c`
- `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`

Fichiers additionnels probables:

- dialogue du gouverneur portugais;
- dialogue de l'espion francais;
- dialogues des soldats anglais et des faux soldats anglais;
- dialogues de temoins a Douwesen;
- dialogue des Hollandais dissidents;
- `globals.txt` si des notifications courtes sont ajoutees.

## Location Anchors

Ancrages verifies ou candidats:

| Usage narratif | Candidat repo | Statut |
|---|---|---|
| Silehard | `Redmond_Residence` | verrouille |
| gouverneur portugais | `Conceicao_townhall` ou equivalent | a verrouiller |
| arrivee nocturne a Redmond | zone port / ville de `Redmond` | a verrouiller |
| Douwesen, enquete | ville et PNJ civils de `Douwesen` | a verrouiller |
| cabane jungle | lieu de jungle reutilisable | a verrouiller |
| rendez-vous final francais | ville de `FalaiseDeFleur` | verrouille au niveau ile |
| Gorge du Diable | `Redmond_Shore_01`, nom runtime `Devil's Throat` | verrouille |
| Cote eloignee | `Muelle_shore` ou `Muelle_shore_02` | a verrouiller |
| lieu des rituels | interior/jungle Isla Muelle ou lieu de quete dedie | a verrouiller |

## Timer Strategy

Deux usages temporels distincts:

### 1. Attente contextuelle de `B1.2a`

- la scene de vol doit preferer une arrivee nocturne a Redmond.

### 2. Delai politique de `B1.2b`

- a la fin de `B1.2b`, lancer un timer de quatorze jours;
- pendant ce delai, pas de nouvelle mission `B1`;
- a expiration, poser les relations de guerre et ouvrir `B1.3`.

## Bonus Differe

Le choix du gouverneur prevenu en `B1.2a` memorise une fidelite.

Effet cible:

- si le joueur finit `B1.3` du cote coherent avec son rapport, appliquer un bonus de fin;
- si le joueur change de camp ou finit neutre, pas de bonus.

Le bonus ne doit toucher que:

- or;
- XP;
- eventuellement reputation.

## Final State

En sortie de `B1.2`:

- `B1.2a` et `B1.2b` sont fermees;
- la lettre et le cadeau restent perdus;
- la guerre n'est pas encore visible pendant quatorze jours;
- `pchar.quest_b1_3_available` sera pose a l'expiration du timer;
- la France est encore neutre a ce stade.

## Anti-patterns

- Faire de `B1.2a` une simple cinematique sans enquete jouable.
- Rendre recuperables la lettre ou le cadeau en `B1.2b`.
- Donner au joueur une preuve definitive contre Silehard.
- Faire demarrer la guerre immediatement apres le retour final.
- Transformer les dissidents hollandais en representants officiels de la Hollande.
