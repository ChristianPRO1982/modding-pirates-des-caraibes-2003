# Workflow de creation d'une quete sans nouvel asset

## Objectif
Ce workflow sert a creer une nouvelle quete en reutilisant uniquement les fichiers plats du depot. Il ne suppose ni nouvelle ile, ni nouveau model, ni nouveau son, ni nouvelle video.

Contrainte pratique a garder en tete des le debut:

- les fichiers plats historiques du runtime, surtout sous `PROGRAM/` et `RESOURCE/`, sont a preserver en `ISO-8859-1`,
- il faut eviter les sauvegardes automatiques en `UTF-8` qui peuvent corrompre ou reformater silencieusement ces fichiers.

Le cas cible est:

- un lieu existant,
- un PNJ existant ou temporaire,
- un enchainement de dialogues,
- une progression geree par `PChar.quest.*`,
- un journal de quete dans `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`.

## 1. Chaine complete d'une quete

Une quete propre passe en general par cette chaine:

1. Choisir un lieu et des locators existants.
2. Choisir ou creer le PNJ de quete.
3. Donner au PNJ un fichier de dialogue.
4. Poser un etat initial de quete.
5. Declarer une ou plusieurs conditions de progression.
6. Traiter la progression dans les handlers de quete.
7. Mettre a jour le journal et les messages visibles.
8. Nettoyer les conditions, scenes et etats temporaires.

## 2. Families de fichiers a modifier

### Runtime principal
- `PROGRAM/QUESTS/*.c`
- `PROGRAM/DIALOGS/*.c`
- `PROGRAM/DIALOGS/French/*.h`
- `PROGRAM/Characters/<lang>/init/*.c`
- `PROGRAM/Locations/init/*.c`

### Textes joueur
- `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`
- `RESOURCE/INI/TEXTS/FRENCH/globals.txt`

Note d'encodage:

- pour ces fichiers historiques, conserver `ISO-8859-1`,
- verifier l'encodage avant une grosse serie d'edits ou apres un copier-coller externe.

### Dans ce depot, la branche de travail la plus concrete est
- `PROGRAM/Characters/French/init/*.c`
- `PROGRAM/DIALOGS/French/*.h`

## 3. Etape 1: choisir un lieu existant

Verifier les vrais IDs dans:

- `PROGRAM/Locations/init/*.c`
- `PROGRAM/Locations/init/QuestLocations.c`
- `PROGRAM/Locations/location_init.txt`

Ce qu'il faut fixer des le debut:

- `location id`
- `locator group`
- `locator name`
- chemins de sortie/reload si la scene change de lieu

Si un lieu temporaire suffit et qu'il existe deja dans `QuestLocations.c`, le reutiliser plutot que creer une nouvelle geometrie.

## 4. Etape 2: choisir ou creer le PNJ

### Reutiliser un PNJ existant
Le plus economique est souvent de reutiliser:

- un tavernier,
- un gouverneur,
- un marchand,
- un PNJ de quete deja scenario-compatible.

Dans ce cas, on modifie surtout:

- son dialogue,
- son `Dialog.CurrentNode`,
- son etat `NPChar.quest.*`,
- eventuellement quelques reactions dans `QUESTS/*.c`.

### Creer un PNJ temporaire
Si besoin, le definir dans un fichier d'init adapte, par exemple:

- `PROGRAM/Characters/French/init/StoryCharacters.c`
- `PROGRAM/Characters/French/init/TempQuestCharacters.c`
- `PROGRAM/Characters/French/init/TempQuestEnemy.c`

Champs a verifier au minimum:

- `ch.id`
- `ch.name` / `ch.lastname`
- `ch.model`
- `ch.sex`
- `ch.location`
- `ch.location.group`
- `ch.location.locator`
- `ch.Dialog.Filename`
- `ch.greeting`
- type IA via `LAi_*`

## 5. Etape 3: brancher le dialogue

Creer ou modifier le couple:

- `PROGRAM/DIALOGS/<nom>_dialog.c`
- `PROGRAM/DIALOGS/French/<nom>_dialog.h`

Le `.c` doit:

- lire l'etat de la quete,
- offrir les branches utiles,
- poser ou avancer les flags de quete,
- declencher un event ou une condition si necessaire.

Le `.h` doit:

- contenir toutes les lignes `DLG_TEXT[]`,
- rester dans le meme ordre que la logique du `.c`.

Bon reflexe:

- faire partir la quete depuis un noeud de dialogue explicite,
- eviter les branches magiques diffuses dans tout le script.

## 6. Etape 4: poser l'etat initial de quete

L'etat peut etre lance:

- depuis un dialogue,
- depuis l'init d'un personnage,
- depuis un handler de quete precedent.

Exemples courants:

```c
PChar.quest.MyQuest = "begin";
PChar.quest.MyQuestStage = "talked_to_tavernkeeper";
```

Si la quete doit apparaitre dans le journal:

```c
SetQuestHeader("MyQuest");
AddQuestRecord("MyQuest", "1");
```

Les textes correspondants doivent exister dans:

- `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`

## 7. Etape 5: declarer la progression

Les conditions sont verifiees par `PROGRAM/QUESTS/quests_check.c`.

Conditions typiques:

- `location`
- `locator`
- `Timer`
- `NPC_Death`
- `item`
- `Goods`
- `MapEnter`
- `ExitFromLocation`

Exemple de structure:

```c
PChar.quest.MyQuestStep.win_condition.l1 = "location";
PChar.quest.MyQuestStep.win_condition.l1.location = "Oxbay_town";
PChar.quest.MyQuestStep.win_condition = "MyQuestStepComplete";
PChar.quest.MyQuestStep.fail_condition = "MyQuestFailed";
```

## 8. Etape 6: comprendre le dispatcher de quete

Le point cle du depot est dans `PROGRAM/QUESTS/quests.c`.

### Ce qui se passe
- `quests.c` enregistre les handlers et inclut les sous-fichiers de quete.
- Quand une completion est declenchee, `quests.c` appelle `QuestComplete()` puis `BothQuestComplete()`.
- `PROGRAM/QUESTS/quests_check.c` peut aussi appeler les deux quand une `win_condition` ou `fail_condition` se resout.

### Lecture pratique
- `PROGRAM/QUESTS/quests_reaction.c`
  A utiliser pour la logique principale de la quete.
- `PROGRAM/QUESTS/both_reaction.c`
  A utiliser pour les reactions partagees, les scenes transverses, ou les patterns deja factorises.
- `PROGRAM/QUESTS/quests_movie.c`
  A utiliser si la progression demande une mise en scene.
- `PROGRAM/QUESTS/quests_scenes.c`
  A utiliser si la progression est portee par une scene script plus structuree.

## 9. Etape 7: mettre en scene les personnages

Pour les scenes de quete, on reutilise surtout:

- `ChangeCharacterAddressGroup()`
- `LAi_SetActorType()`
- `LAi_ActorDialog()`
- `LAi_ActorFollow()`
- `LAi_ActorRunToLocation()`
- `LAi_SetStayType()`
- `LAi_group_MoveCharacter()`

Regle importante:

- le PNJ doit etre dans le bon lieu et charge au bon moment,
- le locator doit exister,
- le type IA doit correspondre a l'action attendue.

Avant de bricoler, relire:

- `PROGRAM/Loc_ai/doc/functions.txt`
- `PROGRAM/Loc_ai/doc/character_type.txt`

## 10. Etape 8: journal et messages

### Journal de quete
Ajouter la quete et ses paragraphes dans:

- `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`

Structure attendue:

- `#QUEST <id>`
- titre de quete
- `#TEXT <n>`
- texte de l'etape

### Messages globaux
Si la quete utilise `Log_SetStringToLog(GlobalStringConvert(...))`, ajouter les cles dans:

- `RESOURCE/INI/TEXTS/FRENCH/globals.txt`

Ne pas confondre:

- journal de quete -> `quests_texts.txt`
- message bref / rumeur / forme d'adresse / texte global -> `globals.txt`

## 11. Etape 9: fermer proprement la quete

Checklist de fin de quete:

- `SetQuestHeader(...)` si la quete doit apparaitre au journal
- `AddQuestRecord(...)` pour chaque etape importante
- `CloseQuestHeader(...)` si la quete est terminee
- `win_condition` correctes
- `fail_condition` correctes
- conditions one-shot marquees `.over = "yes"` si necessaire
- PNJ temporaires retires ou remis dans un etat stable
- dialogues temporaires rendus a leur fichier/noeud normal si necessaire

Exemples de nettoyage frequents:

```c
PChar.quest.MyQuestStep.over = "yes";
Characters[GetCharacterIndex("MyNPC")].Dialog.Filename = "old_dialog.c";
Characters[GetCharacterIndex("MyNPC")].Dialog.CurrentNode = "First time";
CloseQuestHeader("MyQuest");
```

## 12. Workflow minimal recommande

### Cas standard "nouvelle quete sur lieu existant"
1. Choisir un port, une taverne ou un lieu de ville existant.
2. Reutiliser un PNJ ou en declarer un temporaire.
3. Ajouter une branche de dialogue qui lance la quete.
4. Poser `SetQuestHeader()` et `AddQuestRecord("...","1")`.
5. Ajouter une `win_condition` simple: lieu, locator, timer, ou mort de PNJ.
6. Gerer cette completion dans `quests_reaction.c`.
7. Ajouter le texte de l'etape suivante dans `quests_texts.txt`.
8. Fermer les conditions inutiles et nettoyer les PNJ.

## 13. Pieges frequents

- Modifier `quests_reaction.old` au lieu de `quests_reaction.c`.
- Oublier le header `PROGRAM/DIALOGS/French/*.h`.
- Utiliser un mauvais `location id` en se fiant au nom affiche au lieu de l'ID runtime.
- Lancer une scene sur un locator inexistant.
- Poser une `win_condition` sans la desactiver ensuite.
- Ajouter un texte de journal sans l'appeler via `AddQuestRecord()`.
- Ajouter un `GlobalStringConvert()` sans la cle dans `globals.txt`.
- Sauvegarder un fichier historique en `UTF-8` alors que le depot attend ici du `ISO-8859-1`.

## 14. Definition de fini
Une quete est "propre" dans ce depot quand un lecteur peut suivre sans deviner:

`init PNJ -> dialogue de depart -> etat PChar.quest -> condition -> handler de completion -> journal -> nettoyage`

Si une de ces etapes manque ou est implicite, il faut resserrer le design avant d'ajouter davantage de logique.
