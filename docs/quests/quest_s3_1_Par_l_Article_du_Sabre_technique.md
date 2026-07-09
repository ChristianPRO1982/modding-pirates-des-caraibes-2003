# S3 - Par l'Article du Sabre : le Verbe et la Lame decident

## Overview

`S3` designe une quete moyenne de jugement moral autour d'un contrat d'assassinat. Un commanditaire peu frequentable approche le joueur a la sortie d'une ville et lui demande d'eliminer une cible locale. La cible peut etre coupable ou innocente. Le joueur doit donc interroger plusieurs habitants avant de choisir entre executer la cible ou la laisser partir puis affronter le commanditaire.

Cette spec decrit uniquement la partie technique cible. Les PNJ, noms, dialogues, textes detailles et variantes narratives sont documentes dans des annexes separees.

En cas de conflit entre les documents, ce fichier technique fait autorite pour la logique de quete. Les autres fichiers servent de support de contenu, de pilotage ou de reference narrative.

## Documentations

`S3` possede plusieurs documents de cadrage :

- `docs/quests/quest_s3_1_Par_l_Article_du_Sabre_technique.md` : document d'entree et reference principale pour la logique technique.
- `docs/quests/quest_s3_2_Par_l_Article_du_Sabre_pilotage.md` : ordre de travail recommande, sans doublonner le contexte technique du repo.
- `docs/quests/quest_s3_3_Par_l_Article_du_Sabre_questbook.md` : textes du livre de quete, avec une version a placeholders et une version generique sans placeholders.
- `docs/quests/quest_s3_4_Par_l_Article_du_Sabre_annexe_PNJ_tableaux_lois.md` : reserve exploitable pour les noms, tableaux d'indices, dialogues-types et codex pirate.
- `docs/quests/quest_s3_5_Par_l_Article_du_Sabre_dialogues.md` : dialogues jouables de `S3`, incluant le commanditaire, la cible, les confirmations et les fins.

## Scope
`S3` doit rester compatible avec du modding simple par fichiers plats uniquement.

Contraintes de scope:

- aucun fichier binaire modifie;
- aucun nouvel asset 3D ou graphique obligatoire;
- aucun nouveau lieu obligatoire;
- pas de nouveau fichier sensible de type `quests.c`, `quests_check.c` ou `quests_reaction.c`;
- modifications a faire uniquement dans les fichiers plats existants;
- encodage cible: Windows-1252, sans BOM, fins de ligne CRLF;
- pas de guillemets typographiques ni de caracteres hors CP1252.

Note de convention: l'identifiant demande est `S3`. La quete est de taille moyenne par sa mecanique, mais conserve l'identifiant `S3` pour rester coherente avec la nomenclature de PJ.

## Availability
`S3` est disponible des le debut du jeu.

Condition cible:

- aucune progression de quete principale requise;
- aucun prerequis de reputation requis;
- la quete ne doit pas bloquer les premieres quetes principales;
- le spawn doit rester discret et facultatif.

## Core Loop
La boucle technique cible est la suivante:

1. Un commanditaire apparait a la sortie d'une ville eligible.
2. Le joueur peut ignorer le commanditaire ou accepter le contrat.
3. Si le contrat est accepte, une cible est choisie et marquee comme innocente ou coupable.
4. Le joueur peut interroger plusieurs PNJ de la ville pour obtenir des indices.
5. Le joueur rencontre la cible.
6. Le joueur choisit entre:
   - assassiner la cible;
   - innocenter la cible et la laisser partir.
7. Si la cible est assassinee, le joueur retourne voir le commanditaire.
8. Si la cible est innocentee, le joueur retourne voir le commanditaire, qui declenche un duel.
9. La quete se termine selon la verite reelle et le choix du joueur.

## State Machine
Etat cible de la quete:

```text
Locked / Not started
   |
   v
Spawner eligible
   |
   v
Commanditaire spawned
   |
   v
Contract offered
   |
   +--> Refused permanently --> Closed
   |
   v
Contract accepted
   |
   v
Investigation open
   |
   +--> Target killed -------> Return to commanditaire
   |
   +--> Target released -----> Return to commanditaire for duel
                               |
                               v
                          Commanditaire killed
```

Etats de resolution:

```text
Target guilty + target killed
   => success by execution

Target innocent + target released + commanditaire killed
   => success by discernment

Target innocent + target killed
   => failure by murder

Target guilty + target released + commanditaire killed
   => failure by misplaced mercy
```

## Invariants
Les regles suivantes doivent toujours rester vraies:

- une seule instance `S3` peut etre active a la fois;
- un seul commanditaire `S3` peut exister a la fois;
- une seule cible `S3` peut exister a la fois;
- la verite de la cible est tiree une seule fois a l'acceptation du contrat;
- les indices des habitants ne doivent jamais modifier la verite reelle;
- la mort de la cible bloque definitivement l'option de liberation;
- la liberation de la cible bloque definitivement l'option de meurtre de la cible;
- la quete se termine apres paiement du commanditaire ou mort du commanditaire;
- tous les PNJ temporaires doivent etre nettoyes a la fin;
- aucun objet de quete ne doit rester dans l'inventaire si une version future en ajoute.

## Suggested Flags
Noms indicatifs a stabiliser pendant l'implementation:

| Flag | Role |
|---|---|
| `pchar.quest_S3_status` | Etat global de la quete |
| `pchar.quest_S3_city` | Ville ou la quete a ete lancee |
| `pchar.quest_S3_commanditaire_id` | Identifiant du commanditaire temporaire |
| `pchar.quest_S3_target_id` | Identifiant de la cible temporaire |
| `pchar.quest_S3_target_name` | Nom affiche de la cible |
| `pchar.quest_S3_target_gender` | Genre de la cible: `male` ou `female` |
| `pchar.quest_S3_target_truth` | Verite reelle: `innocent` ou `guilty` |
| `pchar.quest_S3_reward_gold` | Somme promise par le commanditaire |
| `pchar.quest_S3_city_reward_gold` | Somme versee par la ville si le commanditaire etait la vraie menace |
| `pchar.quest_S3_target_killed` | Marqueur cible tuee |
| `pchar.quest_S3_target_released` | Marqueur cible relachee |
| `pchar.quest_S3_commanditaire_killed` | Marqueur commanditaire tue |
| `pchar.quest_S3_resolution` | Issue finale: `good_kill`, `good_release`, `bad_kill`, `bad_release` |
| `pchar.quest_S3_informant_*` | Memoire des PNJ deja interroges |

Valeurs conseillees pour `pchar.quest_S3_status`:

```text
not_started
spawned
offered
accepted
investigation
candidate_target_kill
candidate_target_release
target_killed
target_released
commanditaire_paid
commanditaire_duel
completed
closed
failed
```

## Spawn Rules
Le commanditaire apparait a une sortie de ville, pas au centre de la ville.

Regles cible:

- le spawn est possible des le debut de jeu;
- le spawn doit etre aleatoire mais rare;
- le spawn ne doit pas avoir lieu si `S3` est deja active;
- le spawn ne doit pas avoir lieu dans une ville hostile ou inaccessible;
- le commanditaire doit rester dans une zone de sortie logique: porte, sortie de jungle, sortie de port ou zone exterieure proche;
- le commanditaire doit disparaitre si la quete est refusee definitivement ou terminee.

Approche recommandee:

- choisir une ville eligible;
- choisir le point de sortie associe a cette ville;
- placer le commanditaire via un helper de placement existant;
- conserver la ville dans `pchar.quest_S3_city` pour borner l'enquete.

## Target Selection
Au moment ou le joueur accepte la mission:

1. choisir une cible temporaire;
2. choisir son genre;
3. choisir son nom affiche;
4. choisir sa verite reelle: `innocent` ou `guilty`;
5. choisir ou placer la cible dans la ville ou dans une zone proche;
6. calculer la recompense du commanditaire.

Probabilite cible recommandee pour la premiere version:

```text
50% innocent
50% guilty
```

Desequilibre de genre recommande, pour correspondre au jeu de base:

```text
5 cibles masculines pour 1 cible feminine environ
```

## Investigation System
Le joueur peut demander des informations a plusieurs types de PNJ de la ville. Chaque PNJ peut:

- repondre;
- refuser de repondre;
- demander un bakchich;
- donner une information vraie;
- donner une information fausse;
- dire qu'il ne connait pas la cible.

La verite reelle reste stockee dans `pchar.quest_S3_target_truth`. Les reponses des PNJ ne sont que des indices.

Table de probabilites issue de la conception precedente:

| Informateur | Chance de repondre | Fiabilite si reponse | Chance de bakchich | Note |
|---|---:|---:|---:|---|
| Pretre | 60% | 100% | 0% | Dit toujours la verite quand il repond |
| Gouverneur / maire | 80% | 75% | 90% | Information influencee par politique locale |
| Tavernier | 100% | 60% | 70% | Beaucoup de rumeurs, faible fiabilite |
| Marchand | 80% | 75% | 90% | Information interessee |
| Marchand de bateaux | 60% | 50% | 50% | Information portuaire, souvent indirecte |
| Soldat | TBD | TBD | TBD | A stabiliser selon faisabilite technique |
| Soldat de prison | TBD | TBD | TBD | A stabiliser selon acces au PNJ prison |

Regle importante:

- le pretre ne doit jamais donner une fausse accusation ou une fausse defense;
- les autres PNJ peuvent se tromper;
- un meme PNJ ne devrait pas donner plusieurs indices contradictoires dans la meme instance de quete.

## Informant Memory
Pour eviter l'abus ou les contradictions, chaque informateur interroge doit etre marque.

Exemples de memoire:

| Flag | Role |
|---|---|
| `pchar.quest_S3_informant_tavernier` | Tavernier deja interroge |
| `pchar.quest_S3_informant_priest` | Pretre deja interroge |
| `pchar.quest_S3_informant_governor` | Gouverneur deja interroge |
| `pchar.quest_S3_informant_merchant` | Marchand deja interroge |
| `pchar.quest_S3_informant_shipyard` | Marchand de bateaux deja interroge |
| `pchar.quest_S3_informant_soldier` | Soldat deja interroge |
| `pchar.quest_S3_informant_prison_guard` | Soldat de prison deja interroge |

Option simple:

- un PNJ donne au maximum une reponse par quete;
- apres reponse, il renvoie une phrase courte du type: il a deja dit ce qu'il savait.

## Bribe System
Le bakchich doit rester simple.

Approche cible:

1. Le PNJ est selectionne comme susceptible de demander un bakchich.
2. Le joueur peut payer ou refuser.
3. Si le joueur refuse, aucun indice n'est donne.
4. Si le joueur paie, le PNJ donne son indice.

Montants indicatifs:

```text
Bakchich faible  : 50 + player_level * 5
Bakchich moyen   : 100 + player_level * 10
Bakchich eleve   : 200 + player_level * 20
```

A stabiliser selon l'economie du jeu.

## Target Interaction
Quand le joueur parle a la cible, il doit pouvoir confirmer une intention mais aussi revenir a l'enquete.

Choix principaux:

- continuer l'enquete;
- mettre la cible en garde;
- declarer la cible innocentee;
- declencher le combat contre la cible.

Regle de securite:

- avant de declencher le combat ou la liberation, proposer une confirmation dialogue;
- la seconde option de confirmation doit permettre d'annuler et de revenir a l'etat `investigation`.

Etats utiles:

```text
candidate_target_kill
candidate_target_release
```

Ces etats evitent de faire avancer la quete trop vite sur une mauvaise ligne de dialogue.

## Commanditaire Return
Deux retours possibles vers le commanditaire:

### Cible assassinee
Le commanditaire valide le contrat et paie le joueur.

Issue reelle:

- si la cible etait coupable: bonne resolution;
- si la cible etait innocente: mauvaise resolution.

### Cible liberee
Le commanditaire comprend que le joueur a refuse le contrat. Il declenche un duel.

Issue reelle:

- si la cible etait innocente: bonne resolution apres mort du commanditaire;
- si la cible etait coupable: mauvaise resolution apres mort du commanditaire.

## Outcomes
### Good Kill
Condition:

```text
pchar.quest_S3_target_truth = "guilty"
pchar.quest_S3_target_killed = true
```

Effets:

- paiement par le commanditaire;
- gain d'experience important;
- hausse moderee de reputation;
- nettoyage des PNJ temporaires;
- fin de quete.

### Bad Kill
Condition:

```text
pchar.quest_S3_target_truth = "innocent"
pchar.quest_S3_target_killed = true
```

Effets:

- paiement par le commanditaire;
- gain d'experience faible;
- forte baisse de reputation;
- consequences commerciales possibles dans la ville;
- nettoyage des PNJ temporaires;
- fin de quete.

### Good Release
Condition:

```text
pchar.quest_S3_target_truth = "innocent"
pchar.quest_S3_target_released = true
pchar.quest_S3_commanditaire_killed = true
```

Effets:

- petite recompense de la ville;
- gain d'experience important;
- hausse importante de reputation;
- nettoyage des PNJ temporaires;
- fin de quete.

### Bad Release
Condition:

```text
pchar.quest_S3_target_truth = "guilty"
pchar.quest_S3_target_released = true
pchar.quest_S3_commanditaire_killed = true
```

Effets:

- pas de paiement du commanditaire;
- gain d'experience faible ou nul;
- baisse de reputation apres resolution;
- possibilite d'un message indiquant que la cible a continue ses mefaits;
- nettoyage des PNJ temporaires;
- fin de quete.

## Rewards
Recompenses indicatives:

| Issue | Or | Experience | Reputation |
|---|---:|---:|---|
| Good Kill | `pchar.quest_S3_reward_gold` | Forte | + modere |
| Bad Kill | `pchar.quest_S3_reward_gold` | Faible | -- fort |
| Good Release | `pchar.quest_S3_city_reward_gold` | Forte | ++ fort |
| Bad Release | 0 | Faible ou 0 | - modere |

Formule indicative:

```text
pchar.quest_S3_reward_gold = 500 + player_level * 100
pchar.quest_S3_city_reward_gold = 250 + player_level * 50
```

Ces montants sont a ajuster selon l'economie du depot actif.

## Reputation And Merchant Restrictions
En cas de mauvaise resolution, la reputation du joueur baisse.

Cas concernes:

- tuer une cible innocente;
- liberer une cible coupable et tuer le commanditaire qui cherchait reellement justice.

Consequence commerciale optionnelle:

- les marchands de la ville deviennent plus froids;
- certains objets peuvent etre caches;
- les prix peuvent augmenter;
- la restriction peut etre temporaire ou definitive selon faisabilite.

Pour une premiere implementation, recommander une consequence simple:

```text
pchar.quest_S3_city_bad_reputation = true
```

Puis brancher les restrictions marchandes plus tard si le systeme marchand le permet proprement.

## Questbook Entries
Le livre de quete doit contenir les etapes techniques suivantes.

Format cible:

```text
TEXT    1
Un individu peu frequentable m'a propose un contrat d'assassinat. La cible designee est [TARGET_NAME]. Avant de tirer ma lame, je devrais interroger les habitants de la ville.

TEXT    2
J'ai tue [TARGET_NAME]. Il me reste a retourner voir le commanditaire pour recevoir mon paiement.

TEXT    3
J'ai choisi de laisser partir [TARGET_NAME]. Si mes soupcons sont justes, le vrai danger est le commanditaire.

TEXT    4
Le commanditaire m'a paye pour le travail accompli. L'affaire est close, meme si le doute reste accroche a ma lame.

TEXT    5
Le commanditaire a tente de me faire payer ma clemence. Il est mort par le sabre qu'il voulait acheter.

TEXT    6
La ville semble reconnaissante. En eliminant cette crapule, j'ai peut-etre rendu plus de justice qu'un tribunal endormi.

TEXT    7
J'ai fait tuer un innocent. L'or pese lourd, mais pas autant que la honte.

TEXT    8
J'ai laisse filer une vraie menace. Les habitants risquent de se souvenir longtemps de mon erreur.
```

Les variables `[TARGET_NAME]` devront etre remplacees ou contournees selon les capacites reelles du systeme de journal.

## Logging
Ajouter des traces pour faciliter le debug.

Jalons recommandes:

```text
S3 spawned
S3 contract accepted
S3 target generated
S3 informant answered
S3 target killed
S3 target released
S3 commanditaire paid
S3 commanditaire killed
S3 completed good_kill
S3 completed bad_kill
S3 completed good_release
S3 completed bad_release
```

Convention:

```c
Log_SetStringToLog("S3 ...");
```

## Cleanup
A la fin de la quete, nettoyer:

- commanditaire temporaire;
- cible temporaire;
- flags de combat temporaire;
- eventuels locators ou groupes ennemis;
- flags d'interaction actifs;
- timer si une limite de temps est ajoutee plus tard.

Les flags d'historique peuvent rester si utiles:

- `pchar.quest_S3_completed`;
- `pchar.quest_S3_resolution`;
- eventuel flag de reputation locale.

## Time Limit
La version precedente evoquait un delai de deux jours. Pour la version cible actuelle, le delai est optionnel.

Recommandation:

- phase 1: pas de limite de temps, pour reduire les risques techniques;
- phase 2: ajouter un delai de deux jours si la boucle est stable.

Si le delai est ajoute:

- il commence a l'acceptation du contrat;
- il expire uniquement tant que la cible n'est ni tuee ni liberee;
- a expiration, la cible ou le commanditaire peut disparaitre;
- la quete doit alors se fermer proprement.

## Technical Anchors To Prepare
Fichiers probables a inspecter lors de l'implementation:

- `PROGRAM/QUESTS/quests_reaction.c`
- `PROGRAM/QUESTS/quests.c`
- `PROGRAM/QUESTS/quests_check.c`
- `PROGRAM/Characters/*/init/TempQuestCharacters.c`
- `PROGRAM/DIALOGS/*`
- `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`

Important:

- ne pas creer de nouveaux fichiers `quests.c`, `quests_check.c` ou `quests_reaction.c`;
- travailler par ajouts marques;
- isoler les modifications avec `// ajout PJ` et `// fin ajout PJ` lors de l'implementation.

## Non Goals
Cette spec ne couvre pas encore:

- les dialogues complets du commanditaire;
- les dialogues complets de la cible;
- les dialogues complets des informateurs;
- la liste finale des noms de cibles;
- la liste finale des noms du commanditaire;
- les textes definitifs du livre de quete;
- l'equilibrage final des recompenses;
- l'implementation des restrictions marchandes;
- la repetition ou non de `S3` apres completion.

## Open Decisions
Points a trancher avant implementation:

1. `S3` est-elle unique ou repetable par ville ?
2. Le delai de deux jours est-il conserve en phase 1 ou repousse ?
3. Les soldats et soldats de prison sont-ils inclus dans la premiere version de l'enquete ?
4. Les restrictions marchandes sont-elles techniques en phase 1 ou seulement preparees par flag ?
5. La cible doit-elle etre placee dans la ville, dans une maison, dans la taverne, ou dans une zone exterieure ?
6. Le commanditaire reapparait-il au meme point apres acceptation ou reste-t-il sur place ?
7. Faut-il une variante par ville ou une seule implementation generique ?

## Recommended Phase 1
Pour reduire les risques, la premiere implementation devrait viser:

- quete unique;
- disponible des le debut;
- un commanditaire temporaire;
- une cible temporaire;
- verite tiree a 50/50;
- enquete limitee a 5 informateurs: pretre, gouverneur, tavernier, marchand, marchand de bateaux;
- pas de timer;
- pas encore de restriction marchande reelle;
- reputation et recompenses branchees;
- nettoyage propre en fin de quete.

Une fois cette boucle stable, ajouter:

- soldat;
- soldat de prison;
- delai de deux jours;
- consequences marchandes;
- variantes par ville;
- rejouabilite eventuelle.
