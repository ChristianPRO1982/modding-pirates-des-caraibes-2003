# Ajouter un item

Ce document décrit la démarche à suivre pour créer un item dans le jeu à partir de l'organisation actuellement visible dans `PROGRAM`.

## Vue d'ensemble

Dans ce code, "créer un item" peut vouloir dire trois choses différentes :

1. déclarer l'item dans la base statique `Items[]` ;
2. lui donner un comportement particulier si c'est un objet utilisable ;
3. le faire apparaître en jeu, soit dans l'inventaire d'un personnage, soit posé dans une location.

Le point important est le suivant :

- la définition de l'item est dans `PROGRAM/ITEMS/initItems.c`
- sa recherche par identifiant est faite par `Items_FindItem(...)`
- l'ajout à l'inventaire passe généralement par `GiveItem2Character(...)`

## 1. Déclarer l'item dans `PROGRAM/ITEMS/initItems.c`

Le registre principal des items est initialisé dans `InitItems()` dans `PROGRAM/ITEMS/initItems.c`.

Le tableau `Items[]` est dimensionné par :

- `ITEMS_QUANTITY` dans `PROGRAM/ITEMS/items.h`

Chaque item est décrit par un bloc du type :

```c
makeref(itm,Items[n]);
itm.id = "my_item";
itm.name = "itmname_my_item";
itm.describe = "itmdescr_my_item";
itm.model = "my_model";
itm.picIndex = 1;
itm.picTexture = "ITEMS_4";
itm.price = 0;
n++;
```

### Champs les plus importants

- `itm.id`
  identifiant technique unique de l'item
- `itm.name`
  clé de texte utilisée pour le nom affiché
- `itm.describe`
  clé de texte utilisée pour la description affichée
- `itm.model`
  modèle 3D utilisé si l'objet doit exister physiquement dans une location
- `itm.picIndex`
  index de l'icône dans l'atlas UI
- `itm.picTexture`
  atlas d'icônes utilisé dans l'inventaire et les interfaces
- `itm.price`
  prix de l'item

### Champs optionnels utiles

- `itm.groupID`
  groupe d'équipement, utilisé notamment pour les armes, pistolets et longues-vues
- `itm.folder`
  dossier de chargement des modèles si ce n'est pas le dossier par défaut `items`
- `itm.startLocation`
  location où l'objet est physiquement posé au départ
- `itm.startLocator`
  locator précis où l'objet apparaît dans la location
- `itm.useLocation`
  location où l'objet peut être utilisé
- `itm.useLocator`
  locator précis d'utilisation
- `itm.shown`
  drapeau de visibilité pour les objets posés dans le monde

## 2. Comprendre la résolution d'un item

Le moteur retrouve un item par son identifiant via `Items_FindItem(...)` dans `PROGRAM/ITEMS/itemLogic.c`.

La résolution est directe :

- le code parcourt `Items[]`
- il compare `curItem.id == itemID`
- il retourne l'index ou `-1` si l'item n'existe pas

Conséquence pratique :

- l'id doit être strictement unique ;
- toute faute de casse ou de frappe dans un `GiveItem2Character(...)` échoue ;
- si l'id n'existe pas, `TakeNItems(...)` trace un warning `not implemented`.

## 3. Donner l'item à un personnage

L'API d'usage normal est dans `PROGRAM/Characters/CharacterUtilite.c` :

```c
GiveItem2Character(ch, "my_item");
```

Cette fonction appelle en réalité :

```c
TakeNItems(_refCharacter, itemName, 1);
```

Pour retirer un item :

```c
TakeItemFromCharacter(ch, "my_item");
```

Pour vérifier sa présence :

```c
CheckCharacterItem(ch, "my_item");
```

### Usages typiques

- donner un objet de quête au joueur dans `PROGRAM/QUESTS/quests_reaction.c`
- équiper un PNJ dans un fichier de `PROGRAM/Characters/.../init/*.c`
- donner une arme ou un pistolet pendant l'initialisation d'un personnage

## 4. Poser un item dans une location

Le code supporte aussi les items visibles et ramassables dans le monde.

La logique est dans `PROGRAM/ITEMS/itemLogic.c`.

### Apparition physique

Un item peut être posé dans une location si on renseigne :

- `startLocation`
- `startLocator`
- `shown = true` ou `shown = 1`
- `model`

Lors du chargement d'une location, `Item_OnLoadLocation(...)` parcourt `Items[]` et affiche les items dont :

- `startLocation == currentLocation`
- `shown == 1`

### Ramassage

Quand le joueur interagit avec le locator, `Item_OnPickItem()` :

- masque l'objet du monde ;
- appelle `GiveItem2Character(GetMainCharacter(), Items[activeItem].id);`
- affiche le message de gain.

### Usage d'un item sur un locator

Si l'item doit être utilisé dans le décor, il faut aussi définir :

- `useLocation`
- `useLocator`

Alors `Item_OnUseItem()` :

- place visuellement l'objet sur le locator ;
- retire l'objet de l'inventaire ;
- déclenche `CompleteQuestName("OnUse_"+Items[activeItem].id);`

Ce point est important : un item "utilisable dans le monde" peut servir de déclencheur de quête via le nom `OnUse_<item_id>`.

## 5. Créer un item consommable ou à effet

Les effets d'usage standard sont gérés dans `PROGRAM/ITEMS/items_utilite.c`.

Exemples déjà supportés :

- potion de soin via `potion.health`
- antidote via `potion.antidote`
- son à jouer via `potion.sound`

La fonction `DoCharacterUsedItem(...)` :

- retire l'item ;
- applique son effet si les attributs attendus sont présents.

Donc pour créer un consommable simple, il faut :

1. déclarer l'item dans `initItems.c`
2. lui ajouter les attributs attendus, par exemple `itm.potion.health = 30.0;`
3. vérifier qu'il entre bien dans les flux d'usage déjà existants

Si l'effet désiré n'existe pas encore, il faut étendre `DoCharacterUsedItem(...)`.

## 6. Gérer l'inventaire et l'interface

Les interfaces ouvrent le fichier de langue `ItemsDescribe.txt` pour afficher le nom et la description des items.

Le code le montre notamment dans :

- `PROGRAM/INTERFACE/items.c`
- `PROGRAM/INTERFACE/itemsbox.c`
- `PROGRAM/INTERFACE/itemstrade.c`
- `PROGRAM/ITEMS/itemLogic.c`

Les atlas d'icônes sont référencés par `picTexture`, par exemple :

- `ITEMS_1`
- `ITEMS_2`
- `ITEMS_3`
- `ITEMS_4`
- `ITEMS_5`
- `ITEMS_6`

### Point critique : où ajouter l'image de l'item

Il faut distinguer deux images différentes :

- l'icône d'inventaire ;
- le visuel 3D de l'objet posé dans le monde.

#### Icône d'inventaire

Pour l'inventaire, le code ne pointe pas vers un fichier image par item, mais vers un atlas via :

- `itm.picTexture`
- `itm.picIndex`

Exemple :

```c
itm.picIndex = 4;
itm.picTexture = "ITEMS_4";
```

Cela veut dire qu'en pratique l'image doit être ajoutée dans l'atlas correspondant à `ITEMS_1` à `ITEMS_6`, pas comme un fichier isolé déclaré directement dans l'item.

Ce que le code permet d'affirmer :

- l'interface lit `picTexture` ;
- les autres textures UI du projet sont très souvent référencées en `.tga` ;
- il est donc très probable que les atlas d'items réels soient eux aussi des textures du même type.

Ce que je ne peux pas confirmer depuis ce dépôt :

- l'emplacement exact des fichiers physiques `ITEMS_1` à `ITEMS_6` ;
- leur résolution ;
- leur découpage précis ;
- s'il existe une convention additionnelle `.tx` ou autre dans les assets absents de cette copie.

Conclusion prudente :

- si tu ajoutes une nouvelle icône, il faut très probablement modifier un atlas d'items existant côté ressources ;
- le format le plus vraisemblable est `.tga`, mais ce dépôt ne permet pas de le prouver directement pour les atlas `ITEMS_*`.

#### Modèle visible dans le monde

Si l'objet doit apparaître physiquement dans une location, ce n'est pas une simple image d'interface. Le code charge un modèle via :

- `itm.model`
- éventuellement `itm.folder`

Le chargement est fait dans `PROGRAM/ITEMS/itemLogic.c` :

```c
string itemFolder = "items";
SendMessage(&_itemModel, "ls", MSG_MODEL_SET_DIRPATH, itemFolder+"\\");
SendMessage(&_itemModel, "ls", MSG_MODEL_LOAD_GEO, itemFolder + "\\" + _item.model);
```

Cela montre que :

- l'objet monde doit exister dans un dossier d'assets de type `items\...` ;
- il faut un modèle géométrique compatible avec `MSG_MODEL_LOAD_GEO` ;
- ce n'est pas le même asset que l'icône d'inventaire.

Point de limite important dans ce dépôt :

- le code référence bien `ItemsDescribe.txt`
- mais les fichiers de langue et certains assets UI ne sont pas présents ici

Il faut donc éviter d'inventer leur contenu depuis cette seule copie du dépôt.

## 7. Définir un alias dans `PROGRAM/ITEMS/items.h`

Si l'item doit être utilisé souvent dans les scripts, il peut être utile d'ajouter une constante dans `PROGRAM/ITEMS/items.h`, par exemple :

```c
#define MY_SPECIAL_ITEM "my_item"
```

Cela permet d'éviter la répétition de chaînes littérales dans les quêtes.

Le dépôt montre déjà ce pattern pour plusieurs objets de quête, par exemple :

- `INCAS_IDOL`
- `INCAS_COLLECTION`
- `RHEIMS_JOURNAL`
- `COMPRAMAT_TO_DOMIGUES`

## 8. Procédure conseillée

### Cas simple : item d'inventaire sans comportement spécial

1. ajouter un bloc dans `PROGRAM/ITEMS/initItems.c`
2. choisir un `id` unique
3. renseigner `name`, `describe`, `picIndex`, `picTexture`, `price`
4. ajouter si besoin une constante dans `PROGRAM/ITEMS/items.h`
5. donner l'objet via `GiveItem2Character(...)`

### Cas intermédiaire : objet posé dans le monde

1. créer l'item dans `initItems.c`
2. renseigner `model`
3. définir `startLocation`, `startLocator`, `shown`
4. tester son affichage à l'entrée dans la location
5. vérifier que le ramassage ajoute bien l'objet à l'inventaire

### Cas avancé : objet utilisable dans le décor

1. créer l'item dans `initItems.c`
2. définir `useLocation` et `useLocator`
3. vérifier que le locator d'usage existe dans la location
4. brancher une quête ou une logique sur `OnUse_<item_id>` si nécessaire

### Cas avancé : objet consommable

1. créer l'item dans `initItems.c`
2. lui ajouter les attributs attendus par `items_utilite.c`
3. compléter `DoCharacterUsedItem(...)` si l'effet n'existe pas encore

## 9. Checklist de validation

- l'id de l'item est unique ;
- `Items_FindItem(...)` le retrouve ;
- les clés `itmname_*` et `itmdescr_*` existent bien côté ressources réelles du jeu ;
- l'icône `picTexture` / `picIndex` pointe vers quelque chose de valide ;
- le `model` existe si l'objet doit être visible dans une location ;
- `GiveItem2Character(...)` fonctionne sans warning ;
- le comportement d'usage est cohérent avec `items_utilite.c` ou la quête associée ;
- l'item apparaît bien dans l'inventaire et dans l'interface.

## 10. Fichiers concernés en pratique

Dans le cas général, la création d'un item touche au minimum :

- `PROGRAM/ITEMS/initItems.c`

Souvent aussi :

- `PROGRAM/ITEMS/items.h`
- `PROGRAM/ITEMS/items_utilite.c`
- `PROGRAM/QUESTS/quests_reaction.c`
- `PROGRAM/Characters/...`
- des fichiers de ressources texte et d'icônes hors de `PROGRAM`

## 11. Résumé opérationnel

La vraie "création" d'un item se fait d'abord dans `PROGRAM/ITEMS/initItems.c`.

Ensuite :

- pour le donner à quelqu'un, on utilise `GiveItem2Character(...)`
- pour le retirer, `TakeItemFromCharacter(...)`
- pour le poser dans le monde, on utilise `startLocation` / `startLocator`
- pour lui donner un effet, on passe par `items_utilite.c` ou par une quête

Autrement dit, créer un item n'est pas une seule feature isolée : c'est une combinaison entre définition statique, logique d'usage, et point d'apparition.
