# Ajouter un item

Ce document d�crit la d�marche � suivre pour cr�er un item dans le jeu � partir de l'organisation actuellement visible dans `PROGRAM`.

## Vue d'ensemble

Dans ce code, "cr�er un item" peut vouloir dire trois choses diff�rentes :

1. d�clarer l'item dans la base statique `Items[]` ;
2. lui donner un comportement particulier si c'est un objet utilisable ;
3. le faire appara�tre en jeu, soit dans l'inventaire d'un personnage, soit pos� dans une location.

Le point important est le suivant :

- la d�finition de l'item est dans `PROGRAM/ITEMS/initItems.c`
- sa recherche par identifiant est faite par `Items_FindItem(...)`
- l'ajout � l'inventaire passe g�n�ralement par `GiveItem2Character(...)`

## 1. D�clarer l'item dans `PROGRAM/ITEMS/initItems.c`

Le registre principal des items est initialis� dans `InitItems()` dans `PROGRAM/ITEMS/initItems.c`.

Le tableau `Items[]` est dimensionn� par :

- `ITEMS_QUANTITY` dans `PROGRAM/ITEMS/items.h`

Chaque item est d�crit par un bloc du type :

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
  cl� de texte utilis�e pour le nom affich�
- `itm.describe`
  cl� de texte utilis�e pour la description affich�e
- `itm.model`
  mod�le 3D utilis� si l'objet doit exister physiquement dans une location
- `itm.picIndex`
  index de l'ic�ne dans l'atlas UI
- `itm.picTexture`
  atlas d'ic�nes utilis� dans l'inventaire et les interfaces
- `itm.price`
  prix de l'item

### Champs optionnels utiles

- `itm.groupID`
  groupe d'�quipement, utilis� notamment pour les armes, pistolets et longues-vues
- `itm.folder`
  dossier de chargement des mod�les si ce n'est pas le dossier par d�faut `items`
- `itm.startLocation`
  location o� l'objet est physiquement pos� au d�part
- `itm.startLocator`
  locator pr�cis o� l'objet appara�t dans la location
- `itm.useLocation`
  location o� l'objet peut �tre utilis�
- `itm.useLocator`
  locator pr�cis d'utilisation
- `itm.shown`
  drapeau de visibilit� pour les objets pos�s dans le monde

## 2. Comprendre la r�solution d'un item

Le moteur retrouve un item par son identifiant via `Items_FindItem(...)` dans `PROGRAM/ITEMS/itemLogic.c`.

La r�solution est directe :

- le code parcourt `Items[]`
- il compare `curItem.id == itemID`
- il retourne l'index ou `-1` si l'item n'existe pas

Cons�quence pratique :

- l'id doit �tre strictement unique ;
- toute faute de casse ou de frappe dans un `GiveItem2Character(...)` �choue ;
- si l'id n'existe pas, `TakeNItems(...)` trace un warning `not implemented`.

## 3. Donner l'item � un personnage

L'API d'usage normal est dans `PROGRAM/Characters/CharacterUtilite.c` :

```c
GiveItem2Character(ch, "my_item");
```

Cette fonction appelle en r�alit� :

```c
TakeNItems(_refCharacter, itemName, 1);
```

Pour retirer un item :

```c
TakeItemFromCharacter(ch, "my_item");
```

Pour v�rifier sa pr�sence :

```c
CheckCharacterItem(ch, "my_item");
```

### Usages typiques

- donner un objet de qu�te au joueur dans `PROGRAM/QUESTS/quests_reaction.c`
- �quiper un PNJ dans un fichier de `PROGRAM/Characters/.../init/*.c`
- donner une arme ou un pistolet pendant l'initialisation d'un personnage

## 4. Poser un item dans une location

Le code supporte aussi les items visibles et ramassables dans le monde.

La logique est dans `PROGRAM/ITEMS/itemLogic.c`.

### Apparition physique

Un item peut �tre pos� dans une location si on renseigne :

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

Si l'item doit �tre utilis� dans le d�cor, il faut aussi d�finir :

- `useLocation`
- `useLocator`

Alors `Item_OnUseItem()` :

- place visuellement l'objet sur le locator ;
- retire l'objet de l'inventaire ;
- d�clenche `CompleteQuestName("OnUse_"+Items[activeItem].id);`

Ce point est important : un item "utilisable dans le monde" peut servir de d�clencheur de qu�te via le nom `OnUse_<item_id>`.

## 5. Cr�er un item consommable ou � effet

Les effets d'usage standard sont g�r�s dans `PROGRAM/ITEMS/items_utilite.c`.

Exemples d�j� support�s :

- potion de soin via `potion.health`
- antidote via `potion.antidote`
- son � jouer via `potion.sound`

La fonction `DoCharacterUsedItem(...)` :

- retire l'item ;
- applique son effet si les attributs attendus sont pr�sents.

Donc pour cr�er un consommable simple, il faut :

1. d�clarer l'item dans `initItems.c`
2. lui ajouter les attributs attendus, par exemple `itm.potion.health = 30.0;`
3. v�rifier qu'il entre bien dans les flux d'usage d�j� existants

Si l'effet d�sir� n'existe pas encore, il faut �tendre `DoCharacterUsedItem(...)`.

## 6. G�rer l'inventaire et l'interface

Les interfaces ouvrent le fichier de langue `ItemsDescribe.txt` pour afficher le nom et la description des items.

Le code le montre notamment dans :

- `PROGRAM/INTERFACE/items.c`
- `PROGRAM/INTERFACE/itemsbox.c`
- `PROGRAM/INTERFACE/itemstrade.c`
- `PROGRAM/ITEMS/itemLogic.c`

Les atlas d'ic�nes sont r�f�renc�s par `picTexture`, par exemple :

- `ITEMS_1`
- `ITEMS_2`
- `ITEMS_3`
- `ITEMS_4`
- `ITEMS_5`
- `ITEMS_6`

### Point critique : o� ajouter l'image de l'item

Il faut distinguer deux images diff�rentes :

- l'ic�ne d'inventaire ;
- le visuel 3D de l'objet pos� dans le monde.

#### Ic�ne d'inventaire

Pour l'inventaire, le code ne pointe pas vers un fichier image par item, mais vers un atlas via :

- `itm.picTexture`
- `itm.picIndex`

Exemple :

```c
itm.picIndex = 4;
itm.picTexture = "ITEMS_4";
```

### Point critique : `itm.name` et `itm.describe` sont des cles techniques

Les champs :

- `itm.name`
- `itm.describe`

ne contiennent pas directement le texte affiche au joueur. Ils pointent vers des identifiants techniques qui doivent exister dans :

- `RESOURCE/INI/TEXTS/FRENCH/ItemsDescribe.txt`

Exemple :

```c
makeref(itm,Items[n]);
itm.id = "PJ_B1_1_STATUE_ARMS";
itm.name = "PJ_B1_1_itmname_statue_arms";
itm.describe = "PJ_B1_1_itmdescr_statue_arms";
```

et dans `ItemsDescribe.txt` :

```txt
PJ_B1_1_itmname_statue_arms	{Bras de statue mystique inca}
PJ_B1_1_itmdescr_statue_arms
{
Les bras de la statue inca.
}
```

Convention recommandee :

- utiliser un prefixe stable lie a la quete ou au systeme, par exemple `PJ_B1_1_`
- garder la forme `...itmname...` pour le nom et `...itmdescr...` pour la description
- pour des objets de quete suivis individuellement dans l'inventaire, preferer des cles dediees a des cles generiques partagees

Consequence pratique :

- si la cle n'existe pas dans `ItemsDescribe.txt`, les interfaces ne peuvent pas afficher correctement le nom ou la description ;
- reutiliser une cle generique n'est correct que pour des objets reellement interchangeables, pas pour des fragments de quete que le joueur doit distinguer un par un.


Cela veut dire qu'en pratique l'image doit �tre ajout�e dans l'atlas correspondant � `ITEMS_1` � `ITEMS_6`, pas comme un fichier isol� d�clar� directement dans l'item.

Ce que le code permet d'affirmer :

- l'interface lit `picTexture` ;
- les autres textures UI du projet sont tr�s souvent r�f�renc�es en `.tga` ;
- il est donc tr�s probable que les atlas d'items r�els soient eux aussi des textures du m�me type.

Ce que je ne peux pas confirmer depuis ce d�p�t :

- l'emplacement exact des fichiers physiques `ITEMS_1` � `ITEMS_6` ;
- leur r�solution ;
- leur d�coupage pr�cis ;
- s'il existe une convention additionnelle `.tx` ou autre dans les assets absents de cette copie.

Conclusion prudente :

- si tu ajoutes une nouvelle ic�ne, il faut tr�s probablement modifier un atlas d'items existant c�t� ressources ;
- le format le plus vraisemblable est `.tga`, mais ce d�p�t ne permet pas de le prouver directement pour les atlas `ITEMS_*`.

#### Mod�le visible dans le monde

Si l'objet doit appara�tre physiquement dans une location, ce n'est pas une simple image d'interface. Le code charge un mod�le via :

- `itm.model`
- �ventuellement `itm.folder`

Le chargement est fait dans `PROGRAM/ITEMS/itemLogic.c` :

```c
string itemFolder = "items";
SendMessage(&_itemModel, "ls", MSG_MODEL_SET_DIRPATH, itemFolder+"\\");
SendMessage(&_itemModel, "ls", MSG_MODEL_LOAD_GEO, itemFolder + "\\" + _item.model);
```

Cela montre que :

- l'objet monde doit exister dans un dossier d'assets de type `items\...` ;
- il faut un mod�le g�om�trique compatible avec `MSG_MODEL_LOAD_GEO` ;
- ce n'est pas le m�me asset que l'ic�ne d'inventaire.

Point de limite important dans ce d�p�t :

- le code r�f�rence bien `ItemsDescribe.txt`
- mais les fichiers de langue et certains assets UI ne sont pas pr�sents ici

Il faut donc �viter d'inventer leur contenu depuis cette seule copie du d�p�t.

## 7. D�finir un alias dans `PROGRAM/ITEMS/items.h`

Si l'item doit �tre utilis� souvent dans les scripts, il peut �tre utile d'ajouter une constante dans `PROGRAM/ITEMS/items.h`, par exemple :

```c
#define MY_SPECIAL_ITEM "my_item"
```

Cela permet d'�viter la r�p�tition de cha�nes litt�rales dans les qu�tes.

Le d�p�t montre d�j� ce pattern pour plusieurs objets de qu�te, par exemple :

- `INCAS_IDOL`
- `INCAS_COLLECTION`
- `RHEIMS_JOURNAL`
- `COMPRAMAT_TO_DOMIGUES`

## 8. Proc�dure conseill�e

### Cas simple : item d'inventaire sans comportement sp�cial

1. ajouter un bloc dans `PROGRAM/ITEMS/initItems.c`
2. choisir un `id` unique
3. renseigner `name`, `describe`, `picIndex`, `picTexture`, `price`
4. ajouter si besoin une constante dans `PROGRAM/ITEMS/items.h`
5. donner l'objet via `GiveItem2Character(...)`

### Cas interm�diaire : objet pos� dans le monde

1. cr�er l'item dans `initItems.c`
2. renseigner `model`
3. d�finir `startLocation`, `startLocator`, `shown`
4. tester son affichage � l'entr�e dans la location
5. v�rifier que le ramassage ajoute bien l'objet � l'inventaire

### Cas avanc� : objet utilisable dans le d�cor

1. cr�er l'item dans `initItems.c`
2. d�finir `useLocation` et `useLocator`
3. v�rifier que le locator d'usage existe dans la location
4. brancher une qu�te ou une logique sur `OnUse_<item_id>` si n�cessaire

### Cas avanc� : objet consommable

1. cr�er l'item dans `initItems.c`
2. lui ajouter les attributs attendus par `items_utilite.c`
3. compl�ter `DoCharacterUsedItem(...)` si l'effet n'existe pas encore

## 9. Checklist de validation

- l'id de l'item est unique ;
- `Items_FindItem(...)` le retrouve ;
- les cl�s `itmname_*` et `itmdescr_*` existent bien c�t� ressources r�elles du jeu ;
- l'ic�ne `picTexture` / `picIndex` pointe vers quelque chose de valide ;
- le `model` existe si l'objet doit �tre visible dans une location ;
- `GiveItem2Character(...)` fonctionne sans warning ;
- le comportement d'usage est coh�rent avec `items_utilite.c` ou la qu�te associ�e ;
- l'item appara�t bien dans l'inventaire et dans l'interface.

## 10. Fichiers concern�s en pratique

Dans le cas g�n�ral, la cr�ation d'un item touche au minimum :

- `PROGRAM/ITEMS/initItems.c`

Souvent aussi :

- `PROGRAM/ITEMS/items.h`
- `PROGRAM/ITEMS/items_utilite.c`
- `PROGRAM/QUESTS/quests_reaction.c`
- `PROGRAM/Characters/...`
- des fichiers de ressources texte et d'ic�nes hors de `PROGRAM`

## 11. R�sum� op�rationnel

La vraie "cr�ation" d'un item se fait d'abord dans `PROGRAM/ITEMS/initItems.c`.

Ensuite :

- pour le donner � quelqu'un, on utilise `GiveItem2Character(...)`
- pour le retirer, `TakeItemFromCharacter(...)`
- pour le poser dans le monde, on utilise `startLocation` / `startLocator`
- pour lui donner un effet, on passe par `items_utilite.c` ou par une qu�te

Autrement dit, cr�er un item n'est pas une seule feature isol�e : c'est une combinaison entre d�finition statique, logique d'usage, et point d'apparition.
