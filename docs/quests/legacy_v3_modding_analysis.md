# Analyse du modding historique `old_version/V3`

## Objectif
Cette note decrit la facon dont le modding `V3` a ete construit, pour aider Codex a:

- reconnaitre les conventions historiques,
- ne pas "corriger" a tort des patterns volontaires,
- reutiliser ce qui marche,
- eviter de reproduire les parties les plus fragiles.

Le dossier analyse est:

- `old_version/V3/PROGRAM/`
- `old_version/V3/RESOURCE/`

## 1. Signature generale du modding V3

Le modding `V3` suit une logique tres concrete:

- `PJ_` sert de prefixe personnel ou de marqueur de surcouche.
- `S1`, `S2`, `M1` servent de familles de quetes.
- `quest_...` sert souvent aux handlers runtime et aux transitions.

En pratique, on voit trois couches de nommage superposees:

- nom de journal ou texte visible: `PJ_S1`, `PJ_S2`, `PJ_M1`
- etat joueur: `pchar.quest_S1_*`, `pchar.quest_S2_*`, `pchar.quest_M1_*`
- handlers d'evenement: `quest_S1_*`, `quest_S2_*`, `quest_M1_*`

Ce n'est pas homogene, mais ce n'est pas arbitraire: la logique distingue en fait

- l'auteur ou l'outil (`PJ_`),
- la famille de quete (`S1/S2/M1`),
- le mecanisme runtime (`quest_*`).

## 2. Les trois grandes familles de quetes

### `S1`: chasse au tresor multi-iles
Le coeur est initialise dans:

- `old_version/V3/PROGRAM/QUESTS/quests_reaction.c`

Points structurants:

- `GenerateTreasureHunterQuests()` initialise le catalogue et les etats.
- `TreasureHunterNextStep()` branche les etapes et les `win_condition`.
- le journal est porte par `#QUEST PJ_S1` dans `old_version/V3/RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`.

Pattern dominant:

- un PNJ temporaire par ile,
- un dialogue quasi identique par ile,
- une progression par etapes,
- un final base sur une zone de coordonnees via `locator_PJ`.

### `S2`: quete des amoureux
Le coeur repose sur:

- PNJ temporaires dans `old_version/V3/PROGRAM/Characters/French/init/TempQuestCharacters.c`
- dialogues `PJ Quest S2 amant_dialog.c`, `PJ Quest S2 smjh_dialog.c`, `PJ Quest S2 Fabiola Rochefort_dialog.c`
- journal `#QUEST PJ_S2`

Pattern dominant:

- meme schema de quete rejoue sur plusieurs villes,
- meme duo "amant + future fiancee",
- meilleure mutualisation que `S1`, car une partie du dialogue se parametre par `pchar.location`.

`S2` montre la forme la plus factorisee de ton ancien modding.

### `M1`: quete moyenne scenario/conquete
Le coeur repose sur:

- `PJ Quest M1 Francois l_Olonnais_dialog.c`
- `PJ Quest M1 Chui A-poo_dialog.c`
- nombreuses transitions dans `old_version/V3/PROGRAM/QUESTS/quests_reaction.c`
- journal `#QUEST PJ_M1`

Pattern dominant:

- quete plus scriptée,
- plus de mise en scene,
- plus de conditions de capture de forts et d'arrivee dans les ports,
- logique plus proche d'une mini campagne que d'une quete ponctuelle.

## 3. Les fichiers vraiment centraux dans `V3`

### `old_version/V3/PROGRAM/QUESTS/quests.c`
C'est ici que tu as branche une grosse partie de la logique de presence des PNJ sur chargement de lieu.

Le point cle est `QuestsCheck_forLocEnter()`.

Ce que cette fonction fait dans `V3`:

- retire ou masque des PNJ temporaires,
- les replace selon `pchar.location`,
- applique des probabilites d'apparition,
- fait vivre `S1`, `S2` et `M1` au niveau global.

Interpretation:

- tu as transforme un hook moteur tres central en "routeur d'apparition de quetes".
- c'est efficace pour iterer vite.
- c'est puissant, mais fragile parce que global.

### `old_version/V3/PROGRAM/QUESTS/quests_reaction.c`
C'est le veritable cerveau du modding `V3`.

Il contient:

- l'initialisation de `S1`,
- les handlers `quest_S1_*`, `quest_S2_*`, `quest_M1_*`,
- le teleport de dev `PJ_QR_teleportation_1`,
- la majorite des transitions gameplay.

Interpretation:

- la logique de haut niveau est concentree au bon endroit pour ce moteur,
- mais le fichier devient tres gros,
- ce qui augmente fortement le risque d'erreur de nommage ou de collision d'etat.

### `old_version/V3/PROGRAM/QUESTS/quests_check.c`
Tu y as ajoute un vrai prolongement moteur avec `locator_PJ`.

Ce point est important:

- tu n'as pas seulement "consomme" les conditions existantes,
- tu as etendu le mini langage des conditions de quete pour tes besoins.

Interpretation:

- tres bon exemple des limites du moteur d'origine,
- mais aussi de l'endroit ou le code devient le plus sensible.

Comme `quests_check.c` est transversal, toute modification ici a des effets potentiels sur tout le jeu.

### `old_version/V3/PROGRAM/Characters/French/init/TempQuestCharacters.c`
Ce fichier joue le role d'usine a PNJ de quete.

On y voit:

- un bloc `S1`,
- un bloc `S2`,
- un bloc `M1`,
- des variantes de PNJ civils,
- des PNJ de combat,
- des PNJ utilitaires.

Interpretation:

- tu as bien identifie que les quetes vivent aussi dans les personnages,
- mais tout etant centralise dans un seul gros fichier, la maintenance devient lourde.

### `old_version/V3/PROGRAM/DIALOGS/*.c`
Les dialogues sont une couche majeure de ton workflow.

Constat:

- `S1` duplique une meme structure de dialogue par ile,
- `S2` mutualise mieux,
- `M1` est beaucoup plus scenarise,
- tu relies tres souvent la fin d'un noeud a `AddDialogExitQuest(...)`.

Interpretation:

- tes dialogues ne sont pas seulement du texte,
- ce sont de vrais points d'entree de la machine a etats.

## 4. Ce que ton modding fait bien

### 1. Il respecte les limites du moteur
Tu travailles avec les mecanismes vraiment disponibles:

- `PChar.quest.*`
- `AddDialogExitQuest(...)`
- `win_condition`
- repositionnement de PNJ
- quetes a etapes
- journal de quete

Tu ne luttes pas contre le moteur, tu le pousses juste jusqu'a sa limite.

### 2. Il est pense pour iterer vite
Les PNJ utilitaires de dev confirment une methode pragmatique:

- `PJ PNJ voyage.c` pour teleport/se replacer vite,
- `PJ PNJ Trop Fort.c` pour argent, XP, reputation.

Ca colle exactement a ta remarque:

- faire par touches,
- valider une petite tranche,
- deboguer vite,
- garder les gros dialogues possibles en une fois parce qu'ils sont plus auto-portes.

### 3. Le journal de quete est vraiement exploite
Les textes de `PJ_S1`, `PJ_S2`, `PJ_M1` ne sont pas cosmetiques.

Ils servent a:

- guider le joueur,
- compenser la faiblesse de l'UI,
- documenter des parcours parfois complexes,
- rendre jouables des quetes a locators et a positions implicites.

### 4. `S2` montre une bonne mutualisation
`S2` prouve que tu as deja commence a factoriser:

- un meme schema narratif,
- peu de scripts de dialogue,
- des variantes injectees par lieu.

Pour les futurs travaux, `S2` est un meilleur modele que `S1`.

## 5. Les limites et fragilites observees

### 1. Le nommage est lisible localement, mais pas globalement
Exemples de coexistence:

- `PJ_S1`
- `quest_S1_agreeded`
- `quest_S1_completed_1`
- `pchar.quest_S1_gain_jewelry16`
- `pchar.quest.quest_S1_completed_1.win_condition...`

Probleme:

- on comprend l'intention a la lecture,
- mais la predictibilite globale reste faible,
- surtout pour un agent ou un humain qui reprend le code plus tard.

### 2. `S1` explose en etat
Le nombre de flags `pchar.quest_S1_*` est tres grand:

- progression,
- recompenses,
- visibilite,
- echec,
- localisation,
- compteurs,
- variantes de bijoux.

Probleme:

- la quete marche,
- mais le risque de faute de frappe ou d'etat oublie augmente enormement.

### 3. Beaucoup de duplication dans les dialogues `S1`
Les dialogues `PJ Quest S1 *` repetent presque le meme squelette:

- intro,
- acceptation,
- attente,
- validation,
- partage du tresor,
- combat eventuel.

Probleme:

- une correction doit etre dupliquee partout,
- toute divergence devient vite involontaire,
- le debug devient plus long.

### 4. Le moteur est etendu de maniere tres ciblée
Le `locator_PJ` dans `quests_check.c` est puissant, mais ultra lie a `S1`.

Probleme:

- la surcouche n'est pas generique,
- elle embarque de la logique de gameplay dans une couche moteur,
- elle devient difficile a reutiliser proprement pour autre chose.

### 5. `quests.c` devient une zone a tres fort couplage
Le reroutage de PNJ dans `QuestsCheck_forLocEnter()` est pratique, mais dangereux.

Probleme:

- beaucoup d'effets de bord,
- dependance forte au lieu courant,
- sensibles aux reloads,
- sensibles aux IDs exacts de locations.

## 6. Lecture de ta methode de developpement

Ton modding raconte une methode claire:

### Tu prototypais par boucle courte
- ajouter un PNJ ou une condition,
- tester tout de suite,
- te teleporter si besoin,
- te donner des ressources si besoin,
- corriger la tranche avant de continuer.

### Tu gardais les dialogues comme "blocs coherents"
Les dialogues peuvent etre ecrits en une fois parce que:

- ils ont une frontiere claire,
- ils sont faciles a relire seuls,
- leur branchement sur le runtime est visible via `AddDialogExitQuest(...)`.

### Tu acceptais le code transitoire de debug
On voit des marqueurs du style:

- `PJ DEBUG TEST`
- `1 == 1`
- `a supprimer`
- commentaires de creation de quete

Ce n'est pas "propre", mais ca montre un processus de dev concret et efficace pour un moteur aussi vieux.

## 7. Ce qu'il faut retenir pour les futurs travaux

### A conserver
- le travail par petites touches,
- les PNJ/outils de dev hors logique principale,
- le journal de quete riche,
- les quetes ancrees dans des lieux existants,
- la mutualisation partielle a la `S2`.

### A ameliorer
- un schema de nommage plus stable,
- moins de duplication de dialogues,
- moins de logique quest-specific dans `quests_check.c`,
- moins d'apparitions gerees a la main dans `quests.c`,
- plus de helpers reutilisables pour les recompenses et les transitions.

## 8. Convention pratique pour la reprise

Quand Codex croisera un identifiant `V3`, il devra le lire ainsi:

- `PJ_*`: marqueur historique perso ou utilitaire
- `PJ_S1`, `PJ_S2`, `PJ_M1`: familles de quete visibles/journal
- `quest_S1_*`, `quest_S2_*`, `quest_M1_*`: handlers runtime
- `pchar.quest_S1_*`, `pchar.quest_S2_*`, `pchar.quest_M1_*`: etat de progression

Autrement dit:

- le nommage n'est pas proprement normalise,
- mais il est suffisamment structure pour etre exploitable,
- a condition de le lire comme une convention historique et non comme un schema moderne.