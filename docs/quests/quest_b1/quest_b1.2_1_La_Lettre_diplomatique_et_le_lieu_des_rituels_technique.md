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

`B1.2` repose sur quatre documents coeur, completes par deux annexes de dialogues detaillees:

- `docs/quests/quest_b1/quest_b1.2_1_La_Lettre_diplomatique_et_le_lieu_des_rituels_technique.md`
- `docs/quests/quest_b1/quest_b1.2_2_La_Lettre_diplomatique_et_le_lieu_des_rituels_pilotage.md`
- `docs/quests/quest_b1/quest_b1.2_3_La_Lettre_diplomatique_et_le_lieu_des_rituels_questbook.md`
- `docs/quests/quest_b1/quest_b1.2_4_La_Lettre_diplomatique_et_le_lieu_des_rituels_dialogues.md`
- `docs/quests/quest_b1/quest_b1.2_5_La_Lettre_diplomatique_et_le_lieu_des_rituels_dialogues_b1_2a.md`
- `docs/quests/quest_b1/quest_b1.2_6_La_Lettre_diplomatique_et_le_lieu_des_rituels_dialogues_b1_2b.md`

## Scope

Contraintes:

- aucun nouvel asset binaire obligatoire;
- garder la narration centree sur le doute, l'enquete et la manipulation politique;
- `B1.2a` doit etre surtout une quete de transport, d'echec et de repositionnement politique;
- `B1.2b` doit faire basculer vers une enquete urbaine, puis un assaut naval et une confrontation terrestre;
- la lettre et le cadeau ne doivent pas etre recuperables dans `B1.2`;
- la guerre ne doit pas eclater tout de suite, mais apres un delai controle.

## Availability

Conditions cibles:

- `B1.1` terminee;
- Silehard deja sur `PJ Quest B1 Robert Christopher Silehard_dialog.c`;
- `B1.2a` disponible apres la fermeture propre de `B1.1`;
- `B1.2b` ouverte par le meme trigger qui ferme `B1.2a`;
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
4. Le joueur choisit a quel gouverneur rapporter l'affaire en premier.
5. Silehard entre en colere et ordonne une enquete discrete et rapide.
6. Le meme trigger ferme `B1.2a` et ouvre `B1.2b`.

### B1.2b

1. Silehard relance l'enquete et demande d'identifier d'abord le pays des faux soldats.
2. Malcolm peut rappeler explicitement de questionner les habitants des villes.
3. Le joueur mene l'enquete a `Douwesen`.
4. Les temoins confirment l'origine hollandaise des expressions entendues.
5. Les temoins renvoient vers un Francais mal habille vu pres des faux soldats.
6. Le joueur retrouve le gouverneur francais a `Falaise de Fleur`, puis son espion dans la meme piece.
7. L'espion explique que les Hollandais ont pris la mer vers une ile separee a `Isla Muelle` et qu'un rite va s'y tenir.
8. Le joueur retourne voir Silehard.
9. Silehard donne la localisation finale: `Cote eloignee`, puis la grotte du rite.
10. Le joueur detruit la defense navale de la baie: `1 fregate` et `1 corvette`.
11. Il atteint la grotte et interrompt le rite.
12. Les faux soldats reapparaissent comme pretres de Shango menes par un `chef des pretres`.
13. Tous meurent au combat sans reveler ou sont les objets.
14. Silehard revient a une colere plus froide, constate que les morts correspondent aux dissidents et affirme avoir repris la main politiquement.
15. Un delai de quatorze jours prepare la guerre.
16. `B1.3` se declenche automatiquement.

## State Machine

Etat global recommande:

```text
not_started
b1_2a_offer
b1_2a_delivery
b1_2a_redmond_night
b1_2a_stolen
b1_2a_report_choice
b1_2a_completed
b1_2b_offer
b1_2b_malcolm_hint
b1_2b_douwesen_inquiry
b1_2b_french_governor
b1_2b_french_spy
b1_2b_return_silehard
b1_2b_naval_assault
b1_2b_ritual_cave
b1_2b_priests_dead
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

- ne change pas la narration immediate de `B1.2b`;
- memorise seulement une trace de fidelite;
- sert de bonus differe a la fin de `B1.3`.

## Invariants

- la lettre et le cadeau ne doivent pas rester utilisables apres la scene de vol;
- les faux soldats ne doivent pas etre combattables pendant l'interception;
- `B1.2a` se termine sur la colere de Silehard, pas sur l'enquete urbaine;
- l'enquete a `Douwesen` doit confirmer l'origine hollandaise sans reveler encore toute la structure de Shango;
- Malcolm peut etre plus spoilant que les autres PNJ;
- l'espion francais ne doit pas connaitre la plage exacte ni la grotte exacte;
- `B1.2b` doit donner une victoire militaire et un echec diplomatique;
- aucun survivant pretre dissident ne doit rester interrogable apres la confrontation;
- le declenchement de guerre doit etre differe de quatorze jours;
- le dialogue final de Silehard parle de "quelques semaines", pas d'un delai chiffrable;
- `B1.3` doit partir automatiquement, pas via un nouveau PNJ aleatoire.

## Suggested Flags

| Flag | Role |
|---|---|
| `pchar.quest_b1_2_status` | Etat global de `B1.2` |
| `pchar.quest_b1_2a_status` | Etat de `B1.2a` |
| `pchar.quest_b1_2b_status` | Etat de `B1.2b` |
| `pchar.quest_b1_2a_report_target` | `portugal` ou `england` |
| `pchar.quest_b1_2b_malcolm_hint` | Aide de Malcolm deja donnee |
| `pchar.quest_b1_2b_douwesen_witnesses` | Nombre de temoignages valides |
| `pchar.quest_b1_2b_french_spy_met` | Espion francais informe |
| `pchar.quest_b1_2b_silehard_location_known` | `Cote eloignee` et grotte connues |
| `pchar.quest_b1_2b_fleet_destroyed` | Flotte detruite |
| `pchar.quest_b1_2b_priests_dead` | Tous les pretres hollandais morts |
| `pchar.quest_b1_2b_letter_missing` | Lettre toujours perdue |
| `pchar.quest_b1_2b_gift_missing` | Cadeau toujours perdu |
| `pchar.quest_b1_2b_war_timer_started` | Timer de quatorze jours lance |
| `pchar.quest_b1_3_available` | Ouverture de `B1.3` |

## Runtime Surfaces

Fichiers cibles probables:

- `PROGRAM/DIALOGS/PJ Quest B1 Robert Christopher Silehard_dialog.c`
- `PROGRAM/DIALOGS/French/PJ Quest B1 Robert Christopher Silehard_dialog.h`
- `PROGRAM/QUESTS/quests_reaction.c`
- `PROGRAM/Characters/French/init/TempQuestCharacters.c`
- `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`

Fichiers additionnels probables:

- dialogue du gouverneur portugais;
- dialogue du gouverneur francais;
- dialogue de Malcolm;
- dialogue de l'espion francais;
- dialogues des faux soldats anglais;
- dialogues de temoins a `Douwesen`;
- dialogue du `chef des pretres` et des pretres hollandais;
- `globals.txt` si des notifications courtes sont ajoutees.

## Location Anchors

Ancrages verifies ou candidats:

| Usage narratif | Candidat repo | Statut |
|---|---|---|
| Silehard | `Redmond_Residence` | verrouille |
| gouverneur portugais | `Conceicao_townhall` ou equivalent | a verrouiller |
| arrivee nocturne a Redmond | zone port / ville de `Redmond` | a verrouiller |
| Douwesen, enquete | ville et PNJ civils de `Douwesen` | verrouille au niveau narratif |
| gouverneur francais et espion | bureau du gouverneur a `FalaiseDeFleur` | verrouille au niveau narratif |
| Cote eloignee | debarquement de `Isla Muelle`, runtime a verifier entre `Muelle_shore` et `Muelle_shore_02` | nom narratif verrouille |
| lieu des rituels | grotte a `Isla Muelle` | type verrouille |

## Timer Strategy

Deux usages temporels distincts:

### 1. Attente contextuelle de `B1.2a`

- la scene de vol doit preferer une arrivee nocturne a Redmond.

### 2. Delai politique de `B1.2b`

- a la fin de `B1.2b`, lancer un timer de quatorze jours;
- pendant ce delai, pas de nouvelle mission `B1`;
- le dialogue final de Silehard parle seulement de "quelques semaines";
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
- Silehard affirme avoir repris la main en secret avant l'ouverture de `B1.3`;
- `pchar.quest_b1_3_available` sera pose a l'expiration du timer;
- la France est encore neutre a ce stade.

## Anti-patterns

- Faire de `B1.2a` une simple cinematique sans enquete jouable.
- Laisser `Douwesen` et la piste du Francais en `B1.2a`.
- Rendre recuperables la lettre ou le cadeau en `B1.2b`.
- Donner au joueur une preuve definitive contre Silehard.
- Faire demarrer la guerre immediatement apres le retour final.
- Transformer les dissidents hollandais en representants officiels de la Hollande.
