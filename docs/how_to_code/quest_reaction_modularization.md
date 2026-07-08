# Modulariser `quests_reaction.c`

## Objectif
Ce memo fixe une direction simple pour faire grossir les quetes sans continuer a entasser toute la logique dans `PROGRAM/QUESTS/quests_reaction.c`.

La recommandation generale est:

- oui, il est opportun de creer des fichiers `.c` dedies par famille de quetes,
- non, il ne faut pas casser le point d'entree central du moteur,
- le bon modele est un `dispatcher central + sous-modules de famille`.

Pour une famille comme `S1`, un fichier du type `quests_reaction_s1.c` est donc une bonne idee.

## 1. Pourquoi c'est opportun

## Constat actuel
Le depot assemble deja plusieurs modules dans `PROGRAM/QUESTS/quests.c` via des `#include`:

- `quests_abordage.c`
- `quests_check.c`
- `quests_movie.c`
- `characters_task.c`
- `quests_scenes.c`
- `both_reaction.c`
- `quests_reaction.c`

Ce point est important:

- le moteur n'impose pas un unique gros fichier de quetes,
- il accepte deja un assemblage en plusieurs fichiers plats,
- le vrai point sensible est le `dispatcher`, pas le nombre de fichiers.

## Benefices attendus
Decouper par famille de quete apporte:

- une lecture plus simple,
- moins de collisions de noms et de flags,
- un debug plus local,
- une meilleure reprise par Codex ou par un humain,
- des diffs plus petits.

Pour un moteur ancien et sensible au nommage, ce gain de lisibilite vaut beaucoup.

## 2. Ce qu'il ne faut pas faire

### Ne pas supprimer le point d'entree central
`quests.c` continue d'appeler:

- `QuestComplete()`
- `BothQuestComplete()`

Le moteur et les `win_condition` restent donc branches sur ce contrat.

Il ne faut pas remplacer ce schema par:

- plusieurs points d'entree concurrents,
- des handlers de completion disperses sans routeur central,
- une logique qui saute directement d'un dialogue a dix helpers sans dispatcher clair.

### Ne pas tout deplacer d'un coup
Il ne faut pas essayer de refactorer tout `quests_reaction.c` en une seule passe.

La bonne methode reste:

- sortir une famille coherente,
- tester,
- puis sortir la suivante si besoin.

### Ne pas mettre toute la quete dans un seul nouveau fichier
Une famille comme `S1` ne vivra jamais uniquement dans `quests_reaction_s1.c`.

Elle touchera aussi, selon les cas:

- `PROGRAM/QUESTS/quests.c`
- `PROGRAM/QUESTS/quests_check.c`
- `PROGRAM/DIALOGS/*.c`
- `PROGRAM/DIALOGS/French/*.h`
- `PROGRAM/Characters/French/init/*.c`
- `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`

Le nouveau fichier doit porter le coeur des reactions, pas pretendre absorber tout le gameplay.

## 3. Structure recommandee

### Garder `QuestComplete()` comme routeur principal
Le plus propre est de garder dans `quests_reaction.c` un point d'entree unique:

```c
void QuestComplete(string sQuestName)
{
	if (QuestComplete_S1(sQuestName)) return;
	if (QuestComplete_S2(sQuestName)) return;
	if (QuestComplete_M1(sQuestName)) return;

	switch(sQuestName)
	{
		// quetes historiques ou logique transversale restante
	}
}
```

### Chaque famille renvoie `true` si elle a traite la quete
Exemple de forme pour `S1`:

```c
bool QuestComplete_S1(string sQuestName)
{
	switch(sQuestName)
	{
		case "quest_S1_agreeded":
			// logique S1
			return true;

		case "quest_S1_closed":
			// logique S1
			return true;
	}

	return false;
}
```

Ce pattern est adapte a ce depot parce qu'il:

- garde une entree unique,
- localise les `case` de la famille,
- evite un `switch` geant encore plus gros.

## 4. Emplacement conseille

### Fichiers recommandes
Pour une modularisation progressive, la famille de fichiers suivante est saine:

- `PROGRAM/QUESTS/quests_reaction_s1.c`
- `PROGRAM/QUESTS/quests_reaction_s2.c`
- `PROGRAM/QUESTS/quests_reaction_m1.c`

Eventuellement plus tard:

- `PROGRAM/QUESTS/quests_reaction_misc.c`

si quelques cas transverses restent sans vraie famille.

### Inclusion
Le nouveau fichier doit etre inclus par `PROGRAM/QUESTS/quests.c` avec les autres modules.

Le plus simple est de le placer avant `quests_reaction.c`, afin que ses fonctions soient deja connues lorsque `QuestComplete()` les appelle.

## 5. Repartition des responsabilites

### `quests.c`
A garder pour:

- les `#include`,
- les handlers globaux,
- le dispatch general du moteur,
- les hooks de type `EVENT_LOCATION_LOAD`.

Si une famille de quete a un systeme global d'apparition en ville, il est normal qu'une petite partie reste ici ou soit appelee depuis ici.

### `quests_reaction_s1.c`
A garder pour:

- les `case "quest_S1_*"` de progression,
- les helpers purement `S1`,
- les nettoyages et fermetures de la famille,
- les recompenses et bascules d'etat `S1`.

### `quests_check.c`
A toucher seulement si la famille a besoin d'une vraie nouvelle condition moteur.

Exemple:

- un test special de locator,
- une condition custom comme l'ancien `locator_PJ`.

Sinon, mieux vaut rester sur les conditions standard deja disponibles.

### `both_reaction.c`
A reserver aux reactions partagees ou vraiment transverses.

Ne pas y deplacer une famille complete uniquement pour "faire de la place".

## 6. Strategie de migration conseillee

### Etape 1
Creer `quests_reaction_s1.c` avec seulement:

- `QuestComplete_S1(string sQuestName)`
- quelques helpers `S1_*`

### Etape 2
Deplacer uniquement les `case` `S1` les plus identifies:

- acceptation,
- progression,
- cloture,
- final pirate.

### Etape 3
Laisser provisoirement:

- l'apparition globale,
- les conditions speciales,
- certains helpers anciens

dans leur fichier actuel si cela evite une grosse casse.

### Etape 4
Quand la famille tourne proprement, seulement ensuite:

- sortir les helpers restants,
- nettoyer les flags,
- harmoniser le nommage.

## 7. Convention pratique recommandee

### Nommage de fonctions
Pour une famille `S1`, preferer:

- `bool QuestComplete_S1(string sQuestName)`
- `void S1_StartQuest(...)`
- `void S1_SetNextStep(...)`
- `void S1_CloseQuest(...)`

plutot que des helpers generiques au nom flou.

### Nommage des handlers
Garder les noms historiques si le code les utilise deja:

- `quest_S1_*`
- `pchar.quest_S1_*`
- `PJ_S1`

mais eviter d'introduire de nouvelles variantes concurrentes.

## 8. Decision recommandee
Pour ce depot, la decision pratique est:

- oui a `quests_reaction_s1.c`,
- oui a une modularisation par famille,
- non a une refonte totale immediate,
- oui a un `QuestComplete()` central qui delegue.

En bref:

`un gros routeur stable + des sous-fichiers lisibles`

est la meilleure forme pour ce moteur et pour ce projet.