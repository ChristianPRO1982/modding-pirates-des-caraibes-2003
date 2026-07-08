# Cartographie des flat files utiles au modding

## Objectif
Cette note cartographie les fichiers plats utiles au modding dans ce depot, en restant dans le perimetre:

- `PROGRAM/`
- `RESOURCE/`

Le focus est `quetes d'abord`, mais la carte couvre aussi les autres couches gameplay qui influencent une quete: personnages, lieux, commerce, rencontres, monde, IA, textes.

## Legende
- `Actif`: charge par le runtime ou par les scripts actifs.
- `Secondaire`: helper, fichier de validation, doc interne, ou point d'appui utile mais pas le coeur de la logique.
- `Archive/reference`: sauvegarde, variante historique, test, ou fichier hors scope gameplay texte actif.

## Vue d'ensemble
Le point d'entree script principal est `PROGRAM/seadogs.c`. Ce fichier inclut les gros sous-systemes et fixe l'ordre d'initialisation: nations, rencontres, canons, navires, iles, meteo, interfaces, dialogues, quetes, lieux, personnages, etc.

En pratique, une quete narrative touche le plus souvent ce faisceau:

- `PROGRAM/QUESTS/*.c`
- `PROGRAM/DIALOGS/*.c`
- `PROGRAM/DIALOGS/French/*.h`
- `PROGRAM/Characters/French/init/*.c`
- `PROGRAM/Locations/init/*.c`
- `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`
- `RESOURCE/INI/TEXTS/FRENCH/globals.txt`

## 1. Bootstrap et runtime global

### Actif
- `PROGRAM/seadogs.c`
  Role: bootstrap global, inclusions des sous-systemes, ordre d'init, handlers globaux.
- `PROGRAM/dialog.c`
  Role: moteur de dialogue, chargement de `DIALOGS/*.c` et des headers de langue.
- `PROGRAM/Dialog_func.c`
  Role: helpers de dialogue et fonctions communes, conversion de textes globaux, utilitaires de quetes de dialogue.
- `PROGRAM/reload.c`
  Role: transitions et rechargements entre mer, ile, lieu.
- `PROGRAM/globals.c`
  Role: constantes globales et definitions utilisees partout.

### Secondaire
- `PROGRAM/CheckDlgLoad.c`
  Role: validation des couples `DIALOGS/*.c` + `DIALOGS/<lang>/*.h`.
- `PROGRAM/Events.h`, `PROGRAM/messages.h`
  Role: definitions et messages moteur.

### Archive/reference
- `PROGRAM/test.c`, `PROGRAM/test1.c`, `PROGRAM/test_seg1.c`, `PROGRAM/test_seg2.c`, `PROGRAM/memtest.c`
  Role: hors gameplay cible.

## 2. Quetes

### Actif
- `PROGRAM/QUESTS/quests.c`
  Role: noyau des quetes. Inclut les sous-fichiers de quete, enregistre les handlers, et dispatch les completions.
  Point cle: `quests.c` appelle `QuestComplete()` puis `BothQuestComplete()`.
- `PROGRAM/QUESTS/quests_check.c`
  Role: moteur des conditions (`location`, `locator`, `Timer`, `item`, `NPC_Death`, etc.) et declenchement des quetes.
- `PROGRAM/QUESTS/quests_reaction.c`
  Role: gros bloc de reactions de quetes et logique scenario principale.
- `PROGRAM/QUESTS/both_reaction.c`
  Role: reactions partagees ou transverses, souvent reutilisables par plusieurs situations.
- `PROGRAM/QUESTS/quests_movie.c`
  Role: sequences de quete avec fades, mise en scene, retour camera.
- `PROGRAM/QUESTS/quests_scenes.c`
  Role: gestion de scenes et d'enchainements scripts.
- `PROGRAM/QUESTS/characters_task.c`
  Role: orchestration de taches appliquees a des personnages.
- `PROGRAM/QUESTS/quests_abordage.c`
  Role: logique de quetes liee a l'abordage.

### Secondaire
- `PROGRAM/QUESTS/Quest_Messages.h`
  Role: reference historique de messages de quete. Les textes visibles dans ce depot passent surtout par `globals.txt`.

### Archive/reference
- `PROGRAM/QUESTS/quests_reaction.old`
- `PROGRAM/QUESTS/both_reaction.old`
- `PROGRAM/QUESTS/quests_reaction.c.v3`
  Role: references historiques. A ne pas modifier pour le runtime courant.

## 3. Dialogues

### Actif
- `PROGRAM/DIALOGS/*.c`
  Role: logique des dialogues PNJ, souvent point d'entree ou de progression de quete.
- `PROGRAM/DIALOGS/French/*.h`
  Role: tableaux `DLG_TEXT[]` lies a chaque script de dialogue.

### Comment lire le couplage
- Le script `PROGRAM/DIALOGS/blaze_dialog.c` pilote la logique.
- Le header `PROGRAM/DIALOGS/French/blaze_dialog.h` porte les lignes de texte.
- `PROGRAM/dialog.c` charge les deux couches ensemble.

### Secondaire
- `PROGRAM/DIALOGS/Quest_Generation_Functions.c`
  Role: utilitaires ponctuels pour generation/quetes.
- `PROGRAM/CheckDlgLoad.c`
  Role: verifie la coherence du parc de dialogues.

### Archive/reference
- Fichiers de copie ou de brouillon visibles dans `DIALOGS`, par exemple `Copy of ...`
  Role: a traiter avec prudence.

## 4. Personnages

### Actif
- `PROGRAM/Characters/characters.c`
  Role: charge les segments de personnages par langue et cree le cast.
- `PROGRAM/Characters/characters_init.c`
  Role: donne l'etat initial du personnage principal et de variables de demarrage.
- `PROGRAM/Characters/characters.h`
  Role: structures et constantes liees aux personnages.
- `PROGRAM/Characters/CharacterUtilite.c`
  Role: utilitaires sur les personnages.
- `PROGRAM/Characters/characters_ai.c`
  Role: ponts entre perso et IA.
- `PROGRAM/Characters/characters_events.c`
  Role: events lies aux personnages.
- `PROGRAM/Characters/characters_login.c`
  Role: login/logout et presence en lieu.

### Actif, tres important pour les quetes
- `PROGRAM/Characters/French/init/*.c`
  Role: definitions concretes des PNJ dans la version/langue suivie par le depot.
  Fichiers clefs:
  - `StoryCharacters.c`
  - `TempQuestCharacters.c`
  - `TempQuestEnemy.c`
  - `Other.c`
  - fichiers par ile ou categorie (`Oxbay.c`, `Redmond.c`, `Officers.c`, `Item Traders.c`, etc.)

### Secondaire
- `PROGRAM/Characters/French/Characters_names.c`
  Role: noms et couches de presentation.
- `PROGRAM/Characters/Spanish/*`, `PROGRAM/Characters/German/*`
  Role: utile pour comprendre la structure multilingue, mais secondaire si le mod cible la branche francaise du depot.

## 5. Lieux, iles et carte du monde

### Actif
- `PROGRAM/Locations/locations.c`
  Role: init globale des lieux et utilitaires runtime.
- `PROGRAM/Locations/locations_init.c`
  Role: initialise les lieux et enchaine les fichiers par ile.
- `PROGRAM/Locations/init/*.c`
  Role: definitions concretes des lieux, IDs, reloads, locators, types, transitions.
  Fichiers clefs:
  - `Oxbay.c`
  - `Redmond.c`
  - `FalaiseDeFleur.c`
  - `Conceicao.c`
  - `IslaMuelle.c`
  - `Douwesen.c`
  - `QuebradasCostillas.c`
  - `KhaelRoa.c`
  - `QuestLocations.c`
  - `boarding.c`
- `PROGRAM/ISLANDS/islands.c`
  Role: helpers sur les iles et reloads d'ile.
- `PROGRAM/ISLANDS/Islands_init.c`
  Role: commerce par ile, points de debarquement, labels de ports/rivages, liaisons mer/terre.
- `PROGRAM/WorldMap/worldmap_init.c`
  Role: configuration de la carte monde et labels.
- `PROGRAM/WorldMap/worldmap.c`, `worldmap_events.c`, `worldmap_encgen.c`, `worldmap_reload.c`
  Role: runtime carte monde et rencontres associees.

### Secondaire
- `PROGRAM/Locations/location_init.txt`
  Role: doc interne precieuse sur les champs d'une location.
- `PROGRAM/Locations/locations_loader.c`
- `PROGRAM/Locations/locations_camera.c`
- `PROGRAM/Locations/locators_test.c`
  Role: helpers de support.

## 6. Economie, objets, navires, nations

### Actif
- `PROGRAM/STORE/initStore.c`
  Role: init globale des magasins.
- `PROGRAM/STORE/store_init.c`
  Role: associe les magasins aux iles/groupes.
- `PROGRAM/STORE/initGoods.c`
  Role: catalogue et stats des marchandises.
- `PROGRAM/STORE/store.h`, `goods.h`, `StoreUtilite.c`
  Role: definitions et support commerce.
- `PROGRAM/ITEMS/initItems.c`
  Role: catalogue des objets.
- `PROGRAM/ITEMS/itemLogic.c`
  Role: logique d'usage des objets.
- `PROGRAM/ITEMS/items_utilite.c`, `items.h`
  Role: support inventaire.
- `PROGRAM/Ships/Ships_init.c`
  Role: stats des navires, equipage, capacite, combat, prix.
- `PROGRAM/CANNONS/Cannons_init.c`
  Role: canons disponibles.
- `PROGRAM/NATIONS/nations_init.c`
  Role: nations, modeles, identites, groupes ennemis/amis de base.

### Usage quete
Ces fichiers comptent quand une quete modifie la recompense, la cargaison, le navire cible, le type d'escorte, ou les relations commerciales.

## 7. IA, rencontres et combat

### Actif
- `PROGRAM/Loc_ai/LAi_init.c`
  Role: noyau IA de lieu.
- `PROGRAM/Loc_ai/*.c`
  Role: groupes, login, sons, equipements, evenements, utilitaires.
- `PROGRAM/Loc_ai/types/*.c`
  Role: types IA (`citizen`, `guardian`, `merchant`, `actor`, etc.).
- `PROGRAM/Loc_ai/templates/*.c`
  Role: comportements templates (`goto`, `follow`, `fight`, `dialog`, etc.).
- `PROGRAM/Encounters/Encounters_init.c`
  Role: rencontres maritimes dynamiques.
- `PROGRAM/LandEncounters/LandEnc_init.c`
  Role: rencontres terrestres selon type de lieu.
- `PROGRAM/SEA_AI/*.c`
  Role: combat naval, flotte, tirs, abordage, taches IA mer.
- `PROGRAM/BATTLE_INTERFACE/*.c`
  Role: interface et feedback de combat.

### Secondaire
- `PROGRAM/Loc_ai/doc/functions.txt`
- `PROGRAM/Loc_ai/doc/character_type.txt`
- `PROGRAM/Loc_ai/doc/tavern_locators.txt`
- `PROGRAM/Loc_ai/doc/sounds.txt`
- `PROGRAM/Loc_ai/doc/new_animation.txt`
- `PROGRAM/Loc_ai/doc/bugs.txt`
- `PROGRAM/Loc_ai/doc/todo.txt`
  Role: documentation moteur interne tres utile pour coder proprement les scenes de quete.

## 8. Meteo, ambiance, temporalite

### Actif
- `PROGRAM/Weather/*.c`
- `PROGRAM/Weather/Init/*.c`
  Role: meteo, pluie, ciel, mer, soleil, variantes jour/nuit/tempete.
- `PROGRAM/calendar.c`
  Role: date et progression du temps.

### Usage quete
Important si une quete depend de la nuit, d'un delai, d'un trajet carte monde, ou d'une mise en scene d'ambiance.

## 9. Textes dans RESOURCE

### Actif et dans le perimetre actuel
- `RESOURCE/INI/TEXTS/FRENCH/common.ini`
  Role: textes UI et noms visibles generaux.
- `RESOURCE/INI/TEXTS/FRENCH/globals.txt`
  Role: messages generiques, logs, rumeurs, formes d'adresse, noms globaux convertis par `GlobalStringConvert()`.
- `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`
  Role: titres et paragraphes du journal de quete, via `SetQuestHeader()` et `AddQuestRecord()`.

### Hors gameplay texte cible
- `RESOURCE/VIDEOS/French/Invasion.wmv`
  Role: video, pas un flat file de gameplay texte.

### Note importante
Le code ouvre aussi d'autres fichiers de langue comme `LocLables.txt`, `ItemsDescribe.txt`, `GoodsDescribe.txt`, etc., mais ils ne sont pas presents dans ce depot sous `RESOURCE`. Ne pas les inventer dans la cartographie courante.

## 10. Tableau rapide: objectif -> fichiers a toucher

| Objectif de modding | Fichiers a toucher en premier |
| --- | --- |
| Ajouter une quete narrative | `PROGRAM/QUESTS/quests_reaction.c`, `PROGRAM/QUESTS/both_reaction.c`, `PROGRAM/DIALOGS/*.c`, `PROGRAM/DIALOGS/French/*.h`, `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt` |
| Ajouter un nouveau PNJ de quete | `PROGRAM/Characters/French/init/StoryCharacters.c` ou `TempQuestCharacters.c`, puis `PROGRAM/DIALOGS/*.c` et `PROGRAM/DIALOGS/French/*.h` |
| Reutiliser un PNJ existant | `PROGRAM/DIALOGS/*.c`, eventuellement `PROGRAM/Characters/French/init/*.c`, puis `PROGRAM/QUESTS/*.c` |
| Reutiliser un lieu existant pour une scene | `PROGRAM/Locations/init/*.c` pour verifier IDs/reloads/locators, puis `PROGRAM/QUESTS/*.c` et `PROGRAM/Characters/French/init/*.c` |
| Ajouter un lieu de quete temporaire sans nouvel asset | `PROGRAM/Locations/init/QuestLocations.c`, puis `PROGRAM/QUESTS/*.c` |
| Modifier le journal de quete | `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt` |
| Ajouter un message de log ou texte global | `RESOURCE/INI/TEXTS/FRENCH/globals.txt` |
| Changer un dialogue | `PROGRAM/DIALOGS/<nom>_dialog.c` + `PROGRAM/DIALOGS/French/<nom>_dialog.h` |
| Changer le commerce d'une ile | `PROGRAM/ISLANDS/Islands_init.c`, eventuellement `PROGRAM/STORE/initStore.c` |
| Changer les stats de marchandises | `PROGRAM/STORE/initGoods.c` |
| Changer les objets de quete | `PROGRAM/ITEMS/initItems.c`, `PROGRAM/ITEMS/itemLogic.c` |
| Changer un navire cible ou une recompense navale | `PROGRAM/Ships/Ships_init.c`, `PROGRAM/CANNONS/Cannons_init.c`, `PROGRAM/QUESTS/*.c` |
| Changer les rencontres mer | `PROGRAM/Encounters/Encounters_init.c`, `PROGRAM/WorldMap/*.c`, `PROGRAM/SEA_AI/*.c` |
| Changer les rencontres terre | `PROGRAM/LandEncounters/LandEnc_init.c`, `PROGRAM/Loc_ai/*.c` |
| Changer le comportement IA d'une scene | `PROGRAM/Loc_ai/*.c`, `PROGRAM/Loc_ai/types/*.c`, `PROGRAM/Loc_ai/templates/*.c`, `PROGRAM/QUESTS/*.c` |

## 11. Regle pratique pour ne pas se tromper
- Commencer par les fichiers `Actif`.
- N'ouvrir les fichiers `Secondaire` que pour comprendre le contrat ou verifier des locators/types IA.
- Ne jamais brancher une nouvelle logique sur les fichiers `Archive/reference`.
- Ne pas partir de la video ni d'assets binaires: le scope ici est le texte scriptable.