# Shango - PERSONNAGES

Ce documents traites seulement des personnages liés aux quêtes. Cela permet de savoir quels personnages sont à modifier et quels personnages sont à créer.

## Personnages par quête

### Rappel des quêtes

1. **B1.1 - Les Fils de l'Ombre d'Inty**
2. **B1.2a - La Lettre de cachet et le cadeau diplomatique**
3. **B1.2b - La Lettre dérobée**
4. **B1.3 - La Valse des Félons et Tourne-Casaques**
5. **B1.3a - Kidnaping de la fille du gouverneur français**
6. **B1.4a - Guerre dans les Caraïbes**
7. **B1.4b - Guerre dans les Caraïbes - "La Confrérie de Shango : Rénovation et Punissement"**
8. **B1.4c - Guerre dans les Caraïbes - destruction de "La Confrérie de Shango : Rénovation et Punissement"**
9. **B1.4d - Guerre dans les Caraïbes - "L'Eglise contre la Confrérie de Shango : Rénovation et Punissement"**

### Tableau des personnages

La colonne "Joueur" correspond aux personnages pouvant être nommé officier en second du joueur

>* en *italique* les personnages déjà existant
>* en **gras** les personnages à créer et apparaissant la première dans cette quête

|     Quête | Près du joueur | Anglo-hollandais | Hispano-portugais | France |
| --------- | -------------- | ---------------- | ----------------- | ------ |
| **B1.1**  | - | *Silehard* ; 1x **civil hollandais** | 1x **civil espagnol** ; 1x **civil portugais** | - |
| **B1.2a** | - | *Silehard* ; 3x **gardes hollandais** | *gouverneur portugais* | **Espion Français** |
| **B1.2b** | - | *Silehard* ; *barmen* ; 3x *gardes hollandais* | *gouverneur portugais* ; *barmen* | *Espion Français* |
| **B1.3** - personnages communs | 1x **pirate sur le port** | *Silehard* / *gouverneur de Dowesen* | *gouverneur de Isla Muelle* / *gouverneur de Concecia* | *gouvereur de Falaise de Fleurs* |
| **B1.3a** - étape 1 : pour les anglo-hollandais : sabotage | 1x **bretteur** | - | 4x **gardes espagnoles** | - |
| **B1.3a** - étape 2 : pour les hispano-portugais : couler un navire de poudre | - | 1x **capitaine + bateau hollandais imprenable** | - | - |
| **B1.3a** - étape 3: pour les hispano-portugais : couler un navire de nouvelles armes puissantes | 1x **cannonier** | 1x **capitaine + bateau anglais imprenable** | - | - |
| **B1.3a** - étape 4 : pour les anglo-hollandais : escorte d'un navire à bon port | 1x **capitaine + bateau hollandais imprenable** | - | - | - |
| **B1.3a** - étape 5 : pour les hispano-portugais : action navale limitee, destruction d'une flotille légère de transport de troupe | 1x **charpentier** ; 1x **navigateur** |  |  | - |
| **B1.3a** - étape 6 : pour les anglo-hollandais : arraisonner un bateau enemi pour connaitre les plans de bataille | - | - | 1x **capitaine + bateau espagnol** | - |
| **B1.3a** - étape 7 : pour les anglo-hollandais : couler le navire d'un amiral | - | - | 1x **capitaines + bateaux portugais imprenables** | - |
| **B1.3a** - étape 8 : pour les anglo-hollandais : détruire une flotille de guerre | - | - | 2x **capitaines + bateaux portugais imprenables** ; 2x **capitaines + bateaux espagnols imprenables** | - |
| **B1.3a** - étape 9 : pour les hispano-portugais : sabotage | 1x **bretteur** |  |  | - |
| **B1.3a** -étape 10 : pour les hispano-portugais : prendre part à une bataille ouverte où les deux camps sont à forces égales. | - | 4x **capitaines + bateaux portugais imprenables** ; 2x **capitaines + bateaux espagnols imprenables** | 4x **capitaines + bateaux portugais imprenables** ; 2x **capitaines + bateaux espagnols imprenables** | - |
| **B1.3a** | **neuveu du gouverneur** | **prisonnier à Greenford** ; 4x **gardes retenant la fille dans un bateau** | - | *gouverneur de Falaise de Fleurs* ; **fille du gouverneur** |
| **B1.4a** | - | *Silehard* ; *gouverneur de Dowesen* ; 1x **capitaine hollandais** | *gouverneur de Isla Muelle* ; *gouverneur de Concecia* ; 1x **capitaine portugais** | *gouvereur de Falaise de Fleurs* |
| **B1.4b** | - | *Silehard* ; 8x **prêtres de Shango fanatisés** ; 4x **capitaine et son bateau de guerre** | *gouverneur d'Isla Muelle* ; 4x **prêtes convertis Inty** ; 4x **partisans Inty** ; 4x **capitaine et son bateau de guerre** | - |
| **B1.4c** | - | *Silehard*, 1x **sosie de Silehard** ; 8x **prêtres de Shango fanatisés** ; 4x **capitaine et son bateau de guerre** | *gouverneur d'Isla Muelle* ; 4x **prêtes convertis Inty** ; 4x **partisans Inty** ; 4x **capitaine et son bateau de guerre** | - |
| **B1.4d** | *Danielle Greene* ; *Malcolm* | *Silehard*, 1x *sosie de Silehard* ; *gouverneur de Dowesen* ; 8x **prêtres de Shango fanatisés** ; 4x **capitaine et son bateau de guerre** | *gouverneur d'Isla Muelle* ; *gouverneur de Conceicao* ; 4x **prêtes convertis Inty** ; 4x **partisans Inty** ; 4x **capitaine et son bateau de guerre** | *gouvereur de Falaise de Fleurs* ; **autorité ecclésiastique française** |

## Nouveau dialogue de Silehard

A partir de la fin de la quête principale, le dialogue de Silehard est modifié pour simplifier la maintenance de fichier. L'original est lourd et donc remplacé par un nouveau d'autant que c'est un personnage central :
* PROGRAM\DIALOGS\Robert Christopher Silehard PJ_dialog.c
* PROGRAM\DIALOGS\French\Robert Christopher Silehard PJ_dialog.h