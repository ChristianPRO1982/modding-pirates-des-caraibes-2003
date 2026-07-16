# Ajouter une île

Ce document décrit la démarche à suivre pour ajouter une nouvelle île au jeu en réutilisant, si besoin, le design visuel d'une île existante. Il se base sur l'organisation actuellement visible dans `PROGRAM`.

## Objectif

Ajouter une île implique en pratique quatre chantiers distincts :

1. déclarer l'île et ses points d'entrée maritimes ;
2. la placer sur la world map ;
3. rattacher les locations terrestres accessibles depuis la mer ;
4. fournir ou réutiliser les assets visuels nécessaires.

Le plus important à comprendre est qu'une île n'est pas créée à un seul endroit. Le code répartit cette feature entre `PROGRAM/ISLANDS`, `PROGRAM/WorldMap` et `PROGRAM/Locations`.

## 1. Déclarer l'île dans `PROGRAM/ISLANDS/Islands_init.c`

Le point d'entrée principal est `InitIslands()` dans `PROGRAM/ISLANDS/Islands_init.c`.

Chaque île y possède un bloc dédié avec :

- un identifiant logique, par exemple `Islands[n].id = "KhaelRoa";`
- un modèle 3D principal, par exemple `Islands[n].model`
- un dossier de modèles, par exemple `Islands[n].filespath.models`
- un jeu de locators maritimes, par exemple `Islands[n].locators`
- un ou plusieurs points de débarquement `reload.l*`
- éventuellement un fort et des textures d'interface

Exemple utile : le bloc `KhaelRoa` dans `PROGRAM/ISLANDS/Islands_init.c`.

### Ce qu'il faut définir

Pour une nouvelle île, il faut au minimum :

- un nouvel `id` unique ;
- un `model` ;
- un `filespath.models` ;
- un `refl_model` ;
- un `locators` ;
- au moins un `reload.l1` pointant vers une location terrestre.

### Point d'attention

Le débarquement peut être bloqué explicitement par le code, indépendamment de la géométrie visible.

Exemple sur `KhaelRoa` :

- `reload.l1.enable = false;`
- `reload.l1.goto_enable = false;`

Autrement dit, si une île est visible mais impossible à aborder, il faut vérifier ces flags ainsi que les quêtes qui peuvent les modifier.

## 2. Placer l'île dans `PROGRAM/WorldMap/worldmap_init.c`

La présence d'une île dans `Islands_init.c` ne suffit pas. Il faut aussi la déclarer sur la carte du monde dans `PROGRAM/WorldMap/worldmap_init.c`.

Chaque entrée de world map définit :

- le nom logique `worldMap.islands.<id>.name`
- la position 3D de l'île sur la carte
- le rayon d'interaction `radius`
- le coefficient `kradius`
- le libellé affiché
- la position du point de ville ou du point d'intérêt visible sur la carte

Exemple : le bloc `worldMap.islands.KhaelRoa`.

### Ce qu'il faut adapter

Pour créer une nouvelle île "ailleurs sur la map", il faut surtout :

- choisir un nouvel identifiant cohérent avec celui de `Islands_init.c` ;
- modifier `position.x`, `position.y`, `position.z` ;
- ajuster `position.rx` et `position.rz` ;
- régler `radius` et `kradius` ;
- placer la `locations.city.position`.

### Recommandation

Le plus simple est de cloner un bloc existant, puis de ne changer que :

- le nom ;
- les coordonnées ;
- le texte du label ;
- les coordonnées du point de ville.

## 3. Définir les locations terrestres dans `PROGRAM/Locations/init/`

L'île doit ensuite être reliée à une ou plusieurs locations jouables sur terre.

Le schéma actuel est :

- inclure un fichier dédié dans `PROGRAM/Locations/locations_init.c`
- appeler une fonction `LocationInitNomDeLIle(int n)`
- enregistrer la plage de locations dans `Locations[0].IslandsList.<IslandId>`

Exemple visible :

- inclusion de `locations\init\KhaelRoa.c`
- appel à `LocationInitKhaelRoa(n)`
- enregistrement dans `Locations[0].IslandsList.KhaelRoa`

### Contenu du fichier de location

Un fichier comme `PROGRAM/Locations/init/KhaelRoa.c` définit :

- les identifiants de locations, par exemple `KhaelRoa_port`
- les modèles de décor de chaque location
- les images de chargement
- les types de location, par exemple `seashore`, `canyon`
- les `reload` entre mer, plage, temple, grotte, etc.

### Flux minimum

Pour une nouvelle île simple, une seule location terrestre peut suffire :

- une plage ou un port ;
- un `reload` mer -> terre ;
- un `reload` terre -> mer.

Pour une île plus riche, il faut ajouter autant de locations que nécessaire, avec leurs liens internes.

## 4. Réutiliser le design d'une île existante

Réutiliser le design d'une île existante peut vouloir dire deux choses très différentes :

- réutiliser seulement l'idée visuelle ;
- réutiliser exactement les mêmes modèles, textures et locators.

### Cas A : clonage logique et réemploi direct des assets

C'est l'option la plus rapide. Elle consiste à :

- reprendre les mêmes chemins `filespath.models` côté île ;
- reprendre les mêmes chemins de modèles côté locations ;
- reprendre les mêmes images de chargement ;
- changer uniquement les ids, les labels et les coordonnées map.

Cette approche est adaptée si l'on veut une "copie" fonctionnelle d'une île existante ailleurs sur la carte.

### Cas B : variante indépendante

Si l'on veut pouvoir faire évoluer la nouvelle île sans casser l'originale, il faut :

- dupliquer les assets ;
- pointer le nouveau code vers les nouveaux noms de modèles ;
- conserver des ids et chemins séparés.

Cette approche est plus robuste pour un mod long terme.

## 5. Vérifier les dépendances hors déclaration statique

Ajouter l'île ne suffit pas toujours. Certaines îles sont pilotées ou restreintes par du code de quête.

Exemple : `KhaelRoa` est aussi manipulée dans `PROGRAM/QUESTS/quests_reaction.c`, qui active ou désactive le débarquement selon l'avancement du scénario.

Il faut donc rechercher l'identifiant de l'île dans `PROGRAM` pour vérifier :

- les activations ou désactivations de `reload`
- les changements de modèle à chaud
- les apparitions de groupes en mer
- les conditions de quête ou de scène

Commande utile :

```text
rg -n "NomDeLIle" PROGRAM
```

## 6. Procédure conseillée

### Variante la plus simple

Pour créer une nouvelle île en reprenant une île existante :

1. choisir une île source simple ;
2. cloner son bloc dans `PROGRAM/ISLANDS/Islands_init.c` avec un nouvel id ;
3. cloner ou créer son entrée dans `PROGRAM/WorldMap/worldmap_init.c` ;
4. créer un nouveau fichier `PROGRAM/Locations/init/<NouvelleIle>.c` en reprenant la structure de l'île source ;
5. inclure ce fichier dans `PROGRAM/Locations/locations_init.c` ;
6. enregistrer la plage `Locations[0].IslandsList.<NouvelleIle>` ;
7. vérifier que les `reload.l*` de l'île pointent vers des `Locations[n].id` existants ;
8. rechercher dans `PROGRAM` si l'île est manipulée par une quête ;
9. tester l'apparition sur la world map et le débarquement réel.

## 7. Checklist de validation

- l'île possède un `id` unique ;
- l'entrée `worldMap.islands.<id>` existe ;
- les coordonnées world map sont valides ;
- au moins une location terrestre existe ;
- les `reload` mer -> terre et terre -> mer correspondent ;
- les chemins de modèles et locators pointent vers des assets présents ;
- aucun script de quête ne désactive involontairement l'accès ;
- le débarquement est possible en jeu, pas seulement l'approche visuelle.

## 8. Fichiers à modifier en pratique

Dans le cas général, l'ajout d'une île touche au minimum :

- `PROGRAM/ISLANDS/Islands_init.c`
- `PROGRAM/WorldMap/worldmap_init.c`
- `PROGRAM/Locations/locations_init.c`
- `PROGRAM/Locations/init/<NouvelleIle>.c`

Et potentiellement :

- des assets de modèles et textures ;
- des textes de traduction ;
- des scripts de quête si l'île doit être scénarisée.

## 9. Limite constatée dans ce dépôt

Le dépôt actuellement inspecté expose clairement la structure `PROGRAM`, mais ne montre pas ici tous les assets 3D et textures réellement consommés par le jeu pour les îles et les locations.

Conclusion pratique :

- la démarche code pour ajouter une île est claire ;
- la réussite complète de la feature dépend aussi de la disponibilité effective des modèles, locators, textures et images de chargement correspondants.
