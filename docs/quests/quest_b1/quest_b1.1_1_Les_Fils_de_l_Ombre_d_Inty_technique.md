# B1.1 - Les Fils de l'Ombre d'Inty - Technique

## Overview

`B1.1` ouvre le grand arc `B1 - Shango`.

Cette quete doit:

- installer la confiance entre le joueur et Silehard;
- rendre Silehard utile et credible;
- commencer a le rendre suspect sans preuve;
- montrer l'existence d'un reseau anglais clandestin en terres ennemies;
- introduire le nom des Fils de l'Ombre d'Inty comme une ancienne secte supposee disparue;
- preparer directement `B1.2a`.

Ce document fait autorite pour la logique technique cible de `B1.1`.
Les autres docs du dossier servent de support de pilotage, de journal de quete et de scenes de dialogue.

## Documents

`B1.1` est decoupe en quatre documents:

- `docs/quests/quest_b1/quest_b1.1_1_Les_Fils_de_l_Ombre_d_Inty_technique.md`
- `docs/quests/quest_b1/quest_b1.1_2_Les_Fils_de_l_Ombre_d_Inty_pilotage.md`
- `docs/quests/quest_b1/quest_b1.1_3_Les_Fils_de_l_Ombre_d_Inty_questbook.md`
- `docs/quests/quest_b1/quest_b1.1_4_Les_Fils_de_l_Ombre_d_Inty_dialogues.md`

## Scope

`B1.1` doit rester compatible avec le modding par fichiers plats du depot.

Contraintes:

- aucun nouvel asset binaire obligatoire;
- aucun nouveau lieu obligatoire;
- priorite aux fichiers actifs deja charges par le runtime;
- reutiliser le plus possible les personnages, lieux et patterns deja presents;
- conserver les changements concentres autour de `PROGRAM/`, `RESOURCE/INI/TEXTS/FRENCH/` et `docs/`;
- garder la narration joueur floue sur la vraie nature de Shango et sur l'activite actuelle d'Inty.

## Point d'entree runtime

Le point d'entree de `B1.1` doit partir du Silehard de fin de quete principale, pas du Silehard historique de debut de jeu.

Ancrages verifies dans le repo:

- `PROGRAM/Characters/French/init/Redmond.c` charge `Robert Christopher Silehard` avec `Robert Christopher Silehard_dialog.c` par defaut;
- `PROGRAM/QUESTS/quests_reaction.c`, evenement `PJ_end_MQ`, remplace ce dialogue par `Robert Christopher Silehard PJ_dialog.c`;
- `B1` doit donc s'appuyer sur `PROGRAM/DIALOGS/Robert Christopher Silehard PJ_dialog.c` et `PROGRAM/DIALOGS/French/Robert Christopher Silehard PJ_dialog.h`;
- `B1.1` commence apres la fin de la quete principale, dans la fenetre ou Silehard reste gouverneur exploitable politiquement.

## Ancrages historiques a reutiliser avec prudence

Le depot contient deja une vieille quete inca du jeu de base:

- header de journal `blaze_to_incas_collection`;
- texte de journal dans `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`;
- noeuds `incas_collection_complete_node` dans `Robert Christopher Silehard_dialog.c` et `Robert Christopher Silehard PJ_dialog.c`;
- item `icollection` dans `PROGRAM/ITEMS/initItems.c`;
- anciens fragments `STATUE1`, `STATUE2`, `STATUE3` commentes dans `PROGRAM/ITEMS/initItems.c`.

Ces elements sont utiles comme reference locale, mais `B1.1` ne doit pas simplement recopier `blaze_to_incas_collection`.

Ce qu'on peut reutiliser:

- la surface de dialogue de Silehard;
- le theme des objets incas;
- certains patterns de journal et de recompense;
- eventuellement des icones ou objets de quete existants.

Ce qu'il faut remplacer:

- la logique pirate de Douwesen;
- la structure de chasse a un capitaine pirate;
- le header de quete;
- la narration du jeu de base;
- les conclusions qui enchainent vers la storyline vanilla.

## Availability

Conditions cibles:

- quete principale terminee;
- evenement `PJ_end_MQ` deja passe;
- Silehard deja bascule sur `Robert Christopher Silehard PJ_dialog.c`;
- `B1.1` non commencee;
- `B1.2a` non disponible tant que `B1.1` n'est pas terminee.

Point d'entree joueur:

- parler a Silehard dans `Redmond_Residence`;
- branche de dialogue dediee `B1.1` dans le fichier `Robert Christopher Silehard PJ_dialog.c`.

## Core Loop

La boucle cible de `B1.1` est la suivante:

1. Silehard charge le joueur de lui reunir un premier groupe d'objets incas deja existants.
2. Le joueur rassemble ces objets et revient a Redmond.
3. Silehard recompense le joueur et devoile une deuxieme mission plus discrete.
4. Le joueur collecte successivement les pieds, le corps et les bras d'une statue via trois contacts anglais.
5. Deux des contacts sont en territoire ennemi et utilisent une couverture diplomatique douteuse.
6. Le dernier contact, en territoire allie, livre aussi l'indice menant a la tete enterree.
7. Le joueur trouve l'indice autochtone dans la jungle, creuse et recupere la tete.
8. Le joueur revient voir Silehard avec la statue complete.
9. Silehard se montre trop enthousiaste, puis se reprend et ouvre la suite de l'arc.

## State Machine

Etat global conseille pour `B1.1`:

```text
not_started
intro_offer
intro_collect_objects
intro_ready_to_report
statue_offer
muelle_pending
muelle_failed_wait
muelle_ready_ship
muelle_done
conceicao_pending
conceicao_failed_wait
conceicao_ready_ship
conceicao_done
douwesen_pending
douwesen_hint_open
jungle_hint_found
dig_ready
head_found
ready_final_report
completed
closed
```

Flux logique cible:

```text
Silehard available
   |
   v
Intro accepted
   |
   v
First inca objects collected
   |
   v
Second Silehard talk
   |
   v
Isla Muelle contact
   |
   +--> Talk to Spanish first --> wait 1 day --> retry
   |
   v
Feet obtained
   |
   v
Conceicao contact
   |
   +--> Talk to Portuguese first --> wait 1 day --> retry
   |
   v
Body obtained
   |
   v
Douwesen contact
   |
   v
Arms obtained + jungle clue
   |
   v
Hint found
   |
   v
Dig site used
   |
   v
Head obtained
   |
   v
Final Silehard talk
   |
   v
B1.1 completed
```

## Invariants

Les regles suivantes doivent rester vraies:

- `B1.1` ne doit exister qu'en une seule instance a la fois;
- Silehard reste le seul donneur d'ordre principal de `B1.1`;
- la vraie nature actuelle d'Inty ne doit jamais etre confirmee;
- le joueur ne doit jamais pouvoir perdre definitivement la quete pour avoir parle au mauvais garde sur Isla Muelle ou Conceicao;
- l'erreur sur Isla Muelle et Conceicao doit couter du temps, pas bloquer l'arc;
- le contact anglais de Douwesen ne doit pas fuir;
- les morceaux de statue ne doivent pas pouvoir etre obtenus deux fois;
- la recompense du premier groupe et la recompense finale ne doivent etre versees qu'une seule fois;
- la fin de `B1.1` doit poser explicitement la disponibilite de `B1.2a`.

## Suggested Flags

Noms indicatifs a stabiliser pendant l'implementation:

| Flag | Role |
|---|---|
| `pchar.quest_b1_status` | Etat global de l'arc `B1` |
| `pchar.quest.b1_subquest` | Sous-quete `B1` actuellement active, ou derniere sous-quete `B1` terminee |
| `pchar.quest.b1_step` | Etape transverse de la sous-quete `B1`, en reprenant les statuts techniques (`intro_collect`, `muelle_pending`, etc.) puis `completed` en fin de quete |
| `pchar.quest_b1_1_status` | Etat global de la sous-quete `B1.1` |
| `pchar.quest_b1_1_intro_reward_paid` | Premiere recompense deja versee |
| `pchar.quest_b1_1_final_reward_paid` | Recompense finale deja versee |
| `pchar.quest_b1_1_muelle_state` | Etat local de la scene Isla Muelle |
| `pchar.quest_b1_1_conceicao_state` | Etat local de la scene Conceicao |
| `pchar.quest_b1_1_douwesen_state` | Etat local de la scene Douwesen |
| `pchar.quest_b1_1_hint_found` | Indice autochtone trouve |
| `pchar.quest_b1_1_dig_done` | Fouille deja effectuee |
| `pchar.quest_b1_1_piece_feet` | Pieds obtenus |
| `pchar.quest_b1_1_piece_body` | Corps obtenu |
| `pchar.quest_b1_1_piece_arms` | Bras obtenus |
| `pchar.quest_b1_1_piece_head` | Tete obtenue |
| `pchar.quest_b1_1_intro_item_*` | Suivi des objets du premier groupe |
| `pchar.quest_b1_2a_available` | Deverrouillage de `B1.2a` |

## Quest Header

Header recommande pour le journal:

```text
PJ_B1_1
```

Motif:

- suit le style des ajouts PJ du depot;
- evite toute collision avec `blaze_to_incas_collection`;
- reste lisible pour un futur tri par sous-quetes `B1`.

## Runtime Surfaces

Fichiers cibles les plus probables:

- `PROGRAM/DIALOGS/Robert Christopher Silehard PJ_dialog.c`
- `PROGRAM/DIALOGS/French/Robert Christopher Silehard PJ_dialog.h`
- `PROGRAM/QUESTS/quests_reaction.c`
- `PROGRAM/Characters/French/init/TempQuestCharacters.c`
- `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`

Fichiers possibles selon l'implementation retenue:

- nouveaux couples de dialogue pour les contacts temporaires;
- `PROGRAM/ITEMS/initItems.c` si de nouveaux objets de quete sont finalement necessaires;
- `RESOURCE/INI/TEXTS/FRENCH/globals.txt` si des logs visibles au joueur sont ajoutes via `GlobalStringConvert()`.

## Dialogue File Strategy

Strategie recommandee:

- garder Silehard dans `Robert Christopher Silehard PJ_dialog.c`;
- utiliser un dialogue partage pour les contacts anglais de `B1.1`;
- utiliser un dialogue partage pour les gardes iberiques de `B1.1`;
- utiliser un dialogue partage pour le contact hollandais de `B1.1`.

Ainsi, le nombre de fichiers de dialogue reste borne.

Exemple de surface minimale:

- `PROGRAM/DIALOGS/PJ B1.1 English Contact_dialog.c`
- `PROGRAM/DIALOGS/French/PJ B1.1 English Contact_dialog.h`
- `PROGRAM/DIALOGS/PJ B1.1 Iberian Guard_dialog.c`
- `PROGRAM/DIALOGS/French/PJ B1.1 Iberian Guard_dialog.h`
- `PROGRAM/DIALOGS/PJ B1.1 Dutch Contact_dialog.c`
- `PROGRAM/DIALOGS/French/PJ B1.1 Dutch Contact_dialog.h`

## Temporary Characters

Le plus simple est de declarer les personnages de `B1.1` dans `TempQuestCharacters.c`.

Jeu minimum recommande:

- `PJ_B1_1_EnglishContact_Muelle`
- `PJ_B1_1_SpanishGuard_Muelle`
- `PJ_B1_1_EnglishContact_Conceicao`
- `PJ_B1_1_PortugueseGuard_Conceicao`
- `PJ_B1_1_EnglishContact_Douwesen`
- `PJ_B1_1_DutchContact_Douwesen`

Option utile:

- un identifiant de point de fouille, gere par quete plutot que comme PNJ.

## Location Plan

Ancrages verifies ou candidats:

| Usage narratif | Location candidate | Statut |
|---|---|---|
| Bureau de Silehard | `Redmond_Residence` | verrouille |
| Cote eloignee a Isla Muelle | `Muelle_shore` ou `Muelle_shore_02` | a verrouiller |
| Havre radieux a Conceicao | `Conceicao_shore_01` | verrouille |
| Plage aux palmiers a Douwesen | `Douwesen_shore_01` | verrouille |
| Jungle pour l'indice et la fouille | branche `Douwesen_Jungle_01/02/03` | a verrouiller |

Decision technique importante:

- `Conceicao_shore_01` colle deja au nom `Sunny Haven`, donc c'est un bon ancrage pour `Havre radieux`;
- `Douwesen_shore_01` colle deja au nom `Palm Beach`, donc c'est un bon ancrage pour `Plage aux palmiers`;
- Isla Muelle demande encore une verification de cadrage entre les deux plages deja presentes dans le repo.

## Ship Scene Strategy

Les deux premiers contacts disent vouloir parler sur leur navire.

Trois options techniques existent:

1. vraie scene sur un pont de navire;
2. scene de quete dans un lieu de navire deja disponible;
3. simplification narrative: le PNJ dit "sur mon navire", puis la remise se resout juste apres le dialogue.

Recommendation pour la premiere implementation:

- verrouiller d'abord la logique de progression et de journal;
- ne retenir une vraie scene sur navire que si elle reste simple;
- sinon garder la phrase de couverture dans le dialogue et simplifier la remise.

## Item Strategy

`B1.1` a deux familles d'objets:

### 1. Premier groupe d'objets incas

Objectif:

- reutiliser des objets deja existants ou deja plausibles dans le depot;
- eviter de creer des assets ou des definitions nouvelles si ce n'est pas necessaire.

Ancrages existants:

- `idol`
- `icollection`
- `artefact`
- fragments de statue commentes dans `initItems.c`

Decision de doc:

- le premier groupe doit reposer sur des objets incas deja presents ou sur un suivi abstrait par flags;
- la liste exacte des IDs doit etre verrouillee par un audit d'items avant le codage final.

### 2. Les quatre morceaux de statue

`B1.1` demande quatre morceaux:

- pieds;
- corps;
- bras;
- tete.

Constat repo:

- `STATUE1`, `STATUE2`, `STATUE3` existent seulement en bloc commente;
- il n'existe pas encore de quatrieme morceau evident;
- ces trois anciens fragments ne correspondent pas directement a la nouvelle division en quatre parties.

Decision de doc:

- ne pas supposer que les anciens `STATUE1..3` suffisent;
- prevoir soit quatre nouveaux objets de quete simples, soit un suivi par flags si l'inventaire n'apporte rien au gameplay.

## Reward Model

Recompenses cibles:

- apres le premier groupe: argent modere, faible XP eventuelle;
- apres la statue complete: argent raisonnable, XP moderee, confiance accrue de Silehard;
- aucune recompense exceptionnelle a `B1.1`.

La vraie recompense structurante est narrative:

- Silehard considere le joueur comme fiable;
- `B1.2a` devient disponible.

## Final State

En fin de `B1.1`, le runtime doit avoir etabli au minimum:

- `pchar.quest_b1_1_status = "completed"`
- `pchar.quest_b1_status = "b1_1_completed"` ou equivalent
- `pchar.quest_b1_2a_available = "yes"` ou equivalent
- journal `PJ_B1_1` ferme proprement
- aucun PNJ temporaire `B1.1` encore actif

## Anti-patterns

- Ne pas reouvrir ou etendre `blaze_to_incas_collection` comme si c'etait `B1.1`.
- Ne pas accrocher `B1.1` au vieux `Robert Christopher Silehard_dialog.c` si la quete commence bien apres `PJ_end_MQ`.
- Ne pas reveler dans `B1.1` que les Fils de l'Ombre d'Inty sont toujours actifs.
- Ne pas faire dependre la quete d'un seul mauvais clic irreversible sur Isla Muelle ou Conceicao.
- Ne pas multiplier les fichiers de dialogue si un partage simple par role suffit.
- Ne pas creer de nouvelle logique de quete dans un fichier archive ou non actif.
