# S1 Treasure Hunter

## Overview
`S1` designe une famille de petites quetes repetables de chasse au tresor. Le schema general reste simple: un capitaine cherche un navire pour transporter son equipe, promet un partage du butin, mene le joueur jusqu'a une ile, puis revient regler le partage une fois l'exploration terminee. La famille se termine par une derniere resolution speciale sur l'ile des pirates.

Ce document decrit la version cible a viser pour la suite. `V3` sert ici de reference technique pour comprendre comment la famille etait branchee, pas de modele a recopier a l'identique.

## Trigger
`S1` ne doit pas etre disponible au debut de partie. La cible est d'ouvrir cette famille seulement quand la quete principale atteint un seuil suffisant.

Concretement, il faut un point de bascule clair dans les fichiers plats du runtime:

- la quete principale valide un etat ou un flag d'ouverture,
- les apparitions `S1` ne deviennent eligibles qu'apres cette ouverture,
- avant ce seuil, aucun capitaine `S1` ne doit apparaitre.

Seuil retenu dans le depot actif: ouvrir `S1` a `blaze_from_prison_to_residence_complete`.

Ce choix correspond au moment ou la trame principale sort de la prison et relance la circulation vers la residence de Silehard. Dans le runtime actuel, c'est ce basculement qui arme effectivement les quetes PJ secondaires.

Point de repere utile pour ne pas confondre les deux moments:

- `Story_WeMadeThem` retablit techniquement la navigation et les reloads d'Oxbay,
- `blaze_from_prison_to_residence_complete` est le seuil runtime actuellement utilise pour debloquer `S1`.

Note historique: une cible plus tardive autour de `blaze_talk_with_silehard_complete` avait ete envisagee. Le depot actif est maintenant aligne sur le seuil runtime plus totif `blaze_from_prison_to_residence_complete`.

## Quest Loop
La boucle standard `S1` doit rester lisible et repetable:

1. Un capitaine/chasseur de tresor apparait aleatoirement dans une ville.
2. Il propose un contrat clair: il cherche un bateau pour son equipe et le butin sera partage.
3. Le joueur navigue jusqu'a l'ile cible, puis poursuit la progression a pied.
4. Une fois la phase terrestre terminee, le capitaine reapparait pour regler le partage.
5. Le joueur accepte le partage ou le refuse.

L'objectif de conception est de garder un cycle court, comprehensible et facile a debugger par etapes.

## Spawn Rules
Le spawn doit etre pense par ville, avec un point d'apparition stable du point de vue design:

- la ville eligible depend du tirage aleatoire,
- dans une ville donnee, le PNJ apparait toujours sur le point prevu pour cette variante,
- le hasard choisit la rencontre, pas un nouveau locator a chaque fois.

Note technique `V3`: le placement reel passait par un helper de type `PlaceCharacter(..., "goto", location)` depuis `quests.c`, plutot que par un locator code en dur dans la logique principale de progression.

## Minimal Inventory Clue
Pour une premiere implementation simple, `S1` peut utiliser une fausse "carte" tres legere dans l'inventaire sans nouvel asset graphique:

- reutiliser `S1_TREASURE_MAP` dans `PROGRAM/ITEMS/items.h`,
- cet alias pointe vers `legend_copy`, deja defini comme objet papier de quete,
- l'icone sert seulement de repere visuel dans l'inventaire,
- le vrai guidage reste detaille dans `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`.

Cycle recommande pour cette version simple:

1. donner l'objet au moment ou le contrat est accepte,
2. laisser le journal porter les indications de route,
3. retirer l'objet a la resolution normale, a la rupture par combat, ou a la fermeture finale de la famille.

## Outcomes
Trois sorties principales doivent etre prevues:

### Reussite normale
Le joueur accepte le partage. Le butin est partage comme promis et la famille `S1` peut continuer avec d'autres variantes tant que la boucle globale n'est pas terminee.

### Echec de recherche
Le joueur termine la route sans trouver le tresor attendu. Le capitaine repart avec l'affaire telle quelle et la famille peut reapparaitre plus tard via une autre variation.

### Refus du partage
Si le joueur refuse le partage, la resolution devient un combat. Dans `V3`, cela correspondait a `4` adversaires au total: le chef et `3` excellents bretteurs. Si le joueur gagne, il conserve tout le butin, mais la famille `S1` s'arrete alors definitivement.

## Repeatability And Completion
Une variation individuelle `S1` peut reapparaitre selon le hasard tant que toutes les variations normales n'ont pas ete jouees au moins une fois.

La bascule finale doit etre explicite:

- apres que toutes les quetes normales ont ete vues au moins une fois, il n'y a plus de carte au tresor standard,
- un dernier indice oriente vers l'ile des pirates,
- la derniere quete boucle sur cette destination speciale,
- apres cette derniere resolution, `S1` est totalement terminee.

Autrement dit, `S1` peut etre repetable pendant sa phase normale, mais sa conclusion globale doit etre definitive.

## Technical Anchors
Points de reference utiles dans le depot historique `V3`:

- logique de famille: `old_version/V3/PROGRAM/QUESTS/quests_reaction.c`
- apparitions et placements des PNJ: `old_version/V3/PROGRAM/QUESTS/quests.c`
- condition speciale de fouille: `old_version/V3/PROGRAM/QUESTS/quests_check.c`
- PNJ temporaires: `old_version/V3/PROGRAM/Characters/French/init/TempQuestCharacters.c`
- textes de journal `PJ_S1`: `old_version/V3/RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`

Ancres de lecture utiles:

- `GenerateTreasureHunterQuests()`
- `TreasureHunterNextStep()`
- `QuestsCheck_forLocEnter()`
- `locator_PJ`
- `#QUEST PJ_S1`

Seuil de reference dans le depot actif:

- `PROGRAM/QUESTS/quests_reaction.c`: `Story_WeMadeThem` pour la reouverture technique d'Oxbay
- `PROGRAM/QUESTS/quests_reaction.c`: `pchar.quest.main_line = "blaze_talk_with_silehard"` avant l'entretien avec Silehard
- `PROGRAM/QUESTS/quests_reaction.c`: `blaze_from_prison_to_residence_complete` comme seuil runtime retenu pour debloquer `S1`

## Notes from V3
Ecarts historiques a garder en tete sans les reproduire automatiquement:

- l'initialisation `S1` arrivait plus tot que la cible retenue ici,
- les dialogues etaient fortement dupliques selon les iles,
- l'ensemble etait tres sensible aux flags `pchar.quest_S1_*`.

## Scope
Cette spec reste volontairement courte:

- elle resume `S1` comme mecanique et famille de quetes,
- elle ne liste pas les vingt routes ou indices un par un,
- elle ne cree ni nouvel asset, ni nouveau lieu, ni nouveau systeme hors fichiers plats.

Les details fins de routes, coordonnees ou textes de journal peuvent etre documentes plus tard dans une annexe dediee si necessaire.
