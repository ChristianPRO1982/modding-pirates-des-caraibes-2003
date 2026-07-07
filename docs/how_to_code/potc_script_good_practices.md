# Bonnes pratiques pour coder les scripts POTC / Sea Dogs

## Objectif
Ce depot modde uniquement des fichiers plats dans `PROGRAM/` et `RESOURCE/`. Le langage ressemble a du C, mais ce n'est pas du C standard: c'est une couche script du moteur Sea Dogs, avec chargement de segments, attributs dynamiques et handlers moteur.

Le bon reflexe est:

- modifier peu,
- rester dans les conventions existantes,
- reutiliser lieux, locators et PNJ existants,
- garder une quete lisible de bout en bout.

## 1. Ce que ce "C" est vraiment

### `ref` et `aref`
- `ref` designe une reference vers un objet script.
- `aref` designe souvent une reference vers une branche d'attributs.

Exemples vus dans le depot:

```c
ref ch;
aref Link, NextDiag;
makeref(ch, Characters[n]);
makearef(Link, Dialog.Links);
```

Implication pratique:

- on manipule surtout des arbres d'attributs,
- pas des structs C strictes,
- beaucoup de champs existent seulement si le script les cree.

### Attributs dynamiques
Le moteur stocke beaucoup d'etat sous forme de chemins d'attributs:

```c
PChar.quest.MyQuest.win_condition.l1 = "location";
PChar.quest.MyQuest.win_condition.l1.location = "Oxbay_town";
NPChar.quest.meeting = "1";
Dialog.CurrentNode = "First time";
```

Bon reflexe:

- verifier l'existence d'un champ avant de s'appuyer dessus,
- etre coherent dans les noms,
- nettoyer les branches devenues inutiles.

### Chargement de segments
Le moteur charge des fichiers par morceaux avec `LoadSegment()` et les relache avec `UnloadSegment()`.

Exemples importants:

- `PROGRAM/seadogs.c`
- `PROGRAM/dialog.c`
- `PROGRAM/Characters/characters.c`
- `PROGRAM/Locations/locations.c`

Implication pratique:

- un fichier peut etre execute parce qu'il est inclus ou charge par segment,
- un fichier de reference qui "ressemble au bon" n'est pas forcement actif.

## 2. Mecanismes coeur a respecter

### Handlers d'evenements
Le moteur combine:

- `#event_handler(...)`
- `SetEventHandler(...)`
- `PostEvent(...)`
- `Event(...)`

Une quete propre s'appuie sur ce mecanisme plutot que sur des contournements.

### Etats de quete
Les etats vivent souvent sous:

- `PChar.quest.*`
- `NPChar.quest.*`
- `PChar.QuestInfo.*`

Les conditions se definissent via `win_condition`, `fail_condition`, timers, lieux, locators, morts de PNJ, items, cargaison, etc.

### Dialogues
Le couple a respecter est:

- `PROGRAM/DIALOGS/<nom>_dialog.c`
- `PROGRAM/DIALOGS/French/<nom>_dialog.h`

Le `.c` porte la logique.
Le `.h` porte `DLG_TEXT[]`.

Ne jamais modifier seulement un cote si l'autre doit rester coherent.

### IA de lieu
Les scenes de quete vivent beaucoup a travers `LAi_*`:

- `LAi_SetActorType`
- `LAi_ActorDialog`
- `LAi_ActorFollow`
- `LAi_group_MoveCharacter`
- `LAi_SetStayType`
- `LAi_SetGuardianType`

Avant d'utiliser une fonction IA en aveugle, relire:

- `PROGRAM/Loc_ai/doc/functions.txt`
- `PROGRAM/Loc_ai/doc/character_type.txt`

## 3. Regles de travail dans ce depot

### Scope strict
On reste dans:

- `PROGRAM/`
- `RESOURCE/INI/TEXTS/FRENCH/`
- `docs/`

Pas de nouveaux assets binaires.
Pas de nouvelles iles, models, skins, sons ou videos dans ce workflow.

### Diffs minimaux
Faire le plus petit changement qui atteint l'objectif.

Cela veut dire:

- reutiliser un PNJ existant si possible,
- reutiliser un lieu existant si possible,
- ajouter une branche de dialogue plutot que dupliquer un gros script,
- ajouter un handler cible plutot que disperser la logique partout.
- pour un indice papier simple, reutiliser un objet de quete deja defini avec icone d'inventaire existante plutot que creer un nouvel asset.

Exemple utile pour ce depot:

- `S1_TREASURE_MAP` dans `PROGRAM/ITEMS/items.h` reutilise `legend_copy` comme support leger de "carte" ou d'indice papier.
- dans cette approche, l'icone d'inventaire sert de repere visuel et les vraies explications restent dans le livre de quete.

### Workflow incremental
Le bon rythme sur ce moteur est de coder `par touches`:

- une petite condition,
- un petit dialogue,
- un seul handler,
- une seule recompense,
- puis test immediat.

Ce moteur est vieux, permissif sur certains attributs, mais tres sensible aux fautes de nommage et aux effets de bord. Une grosse salve de modifications simultanees est beaucoup plus dure a deboguer qu'une suite de petites tranches valides.

Exception pratique:

- un dialogue complet peut etre ecrit d'un coup si son squelette est deja clair,
- parce qu'il reste plus localise et plus facile a relire qu'une logique eparpillee entre `QUESTS`, `Characters` et `RESOURCE`.

### Priorite a l'existant
Avant de creer:

- verifier si le lieu existe deja dans `PROGRAM/Locations/init/*.c`,
- verifier si un PNJ temporaire existe deja dans `PROGRAM/Characters/French/init/*.c`,
- verifier si une quete proche existe deja dans `PROGRAM/QUESTS/*.c`,
- verifier si un dialogue proche existe deja dans `PROGRAM/DIALOGS/*.c`.

### Reutiliser les locators existants
Les bugs de scene viennent souvent d'un mauvais `location`, `group`, `locator`.

Bonnes sources:

- `PROGRAM/Locations/init/*.c`
- `PROGRAM/Locations/location_init.txt`
- `PROGRAM/Loc_ai/doc/tavern_locators.txt`

### Respecter la branche francaise du depot
Le depot suit explicitement le texte francais pour:

- `PROGRAM/DIALOGS/French/*.h`
- `RESOURCE/INI/TEXTS/FRENCH/*`
- `PROGRAM/Characters/French/init/*.c`

Si le mod cible ce depot, la branche francaise est la reference de travail.

## 4. Structure recommandee d'une modif de quete

1. Identifier un point d'entree dialogue.
2. Poser ou mettre a jour un etat sous `PChar.quest.*`.
3. Declarer une condition de progression claire.
4. Gerer la reaction dans `QuestComplete()` ou `BothQuestComplete()`.
5. Ajouter les textes du journal dans `quests_texts.txt`.
6. Ajouter un message global dans `globals.txt` seulement si necessaire.
7. Fermer proprement les branches de quete.

## 5. Nettoyage obligatoire

Ne pas laisser une quete "ouverte partout".

Verifier a la fin:

- les conditions one-shot sont marquees `.over = "yes"` quand il faut,
- les PNJ temporaires sont retires ou remis a un etat stable,
- les dialogues temporaires sont remis au bon fichier/noeud si necessaire,
- le journal de quete est complete ou ferme,
- les groupes IA n'ont pas ete laisses dans un etat incoherent.

## 6. Anti-patterns a eviter

- Modifier `*.old` ou `quests_reaction.c.v3` en croyant toucher le runtime.
- Ecrire du texte de dialogue dans le `.c` au lieu du header `French/*.h`.
- Reutiliser un `location id` sans verifier le vrai nom dans `Locations/init/*.c`.
- Lancer un `LAi_Actor*` sur un PNJ non charge dans la location.
- Oublier de desactiver une condition apres usage.
- Multiplier les flags `PChar.quest.*` mal nommes et non nettoyes.
- Dupliquer un PNJ entierement quand une simple branche de dialogue suffit.

## 7. Routine de verification avant commit

- Le fichier dialogue `.c` a bien son header `.h`.
- Les noms de quete sont identiques partout, sans variante de casse involontaire.
- Les `win_condition` et `fail_condition` pointent sur des handlers reels.
- Les textes de journal existent dans `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`.
- Les messages globaux existent dans `RESOURCE/INI/TEXTS/FRENCH/globals.txt` si appeles par `GlobalStringConvert()`.
- Les lieux, groupes et locators existent vraiment.
- Aucun changement n'a ete fait dans `PROGRAM` de reference historique par erreur.

## 8. Sources internes a consulter avant de coder

### Documentation moteur deja presente
- `PROGRAM/Locations/location_init.txt`
- `PROGRAM/Loc_ai/doc/functions.txt`
- `PROGRAM/Loc_ai/doc/character_type.txt`
- `PROGRAM/Loc_ai/doc/tavern_locators.txt`
- `PROGRAM/Loc_ai/doc/sounds.txt`
- `docs/how_to_code/quest_reaction_modularization.md`

### Fichiers de verite gameplay
- `PROGRAM/seadogs.c`
- `PROGRAM/dialog.c`
- `PROGRAM/QUESTS/quests.c`
- `PROGRAM/QUESTS/quests_check.c`
- `PROGRAM/QUESTS/quests_reaction.c`
- `PROGRAM/QUESTS/both_reaction.c`
- `PROGRAM/Characters/characters.c`
- `PROGRAM/Locations/locations.c`

## 9. Regle simple a retenir
Si une modification n'est pas facile a relire comme une chaine:

`PNJ -> dialogue -> etat de quete -> condition -> reaction -> journal -> nettoyage`

alors elle est probablement trop dispersee ou trop implicite.