# B1.1 - Les Fils de l'Ombre d'Inty - Pilotage

## Objectif

Ce document cadre l'ordre recommande pour implementer `B1.1`.

Il ne remplace pas la specification technique principale.
Il sert uniquement a maintenir un rythme de travail propre, incremental et facilement testable.

Regle principale:

- une seule modification de fichier a la fois;
- test en jeu entre chaque etape importante.

## Principes de travail

- avancer par tranches courtes;
- verrouiller d'abord la progression de quete, ensuite le confort narratif;
- reutiliser les surfaces deja actives autour de Silehard;
- garder des logs simples et distincts;
- ne pas brancher plusieurs scenes a la fois si elles partagent les memes causes d'erreur.

## Decisions fermees

- `B1.1` commence apres la fin de la quete principale.
- Silehard doit etre pilote via `PJ Quest B1 Robert Christopher Silehard_dialog.c`.
- `B1.1` remplace la vieille fonction narrative de la quete inca vanilla au lieu de la recopier.
- Le journal doit utiliser un nouveau header dedie, distinct de `blaze_to_incas_collection`.
- `Conceicao_shore_01` est le meilleur candidat courant pour `Havre radieux`.
- `Douwesen_shore_01` est le meilleur candidat courant pour `Plage aux palmiers`.
- Les deux erreurs "parler d'abord au mauvais garde" doivent couter du temps, pas bloquer la quete.

## Decisions encore ouvertes

- quelle plage d'Isla Muelle correspond le mieux a la `Cote eloignee`;
- si les scenes "sur son navire" deviennent de vraies scenes jouables ou une simplification narrative;
- si les quatre morceaux de statue existent comme vrais objets d'inventaire ou seulement comme flags;
- quels IDs exacts formeront le premier groupe d'objets incas;
- quel bras de jungle de Douwesen portera l'indice et le point de fouille.

## Ordre recommande d'implementation

### Etape 1 - Journal `B1.1`

But:

- ajouter d'abord le header `PJ_B1_1` et ses textes dans `quests_texts.txt`.

Test attendu:

- le jeu charge le journal sans erreur;
- aucun texte existant n'est casse;
- le nouveau header est distinct de `blaze_to_incas_collection`.

### Etape 2 - Branche d'entree chez Silehard

But:

- ajouter uniquement la branche de depart de `B1.1` dans `PJ Quest B1 Robert Christopher Silehard_dialog.c/.h`.

Test attendu:

- le dialogue se charge;
- la branche `B1.1` apparait seulement apres `PJ_end_MQ`;
- l'acceptation pose le bon etat de quete;
- aucun ancien dialogue de Silehard n'est regresse.

### Etape 3 - Flags globaux et verrouillage de progression

But:

- definir les flags `B1.1` et le squelette de progression.

Fichier cible probable:

- `PROGRAM/QUESTS/quests_reaction.c`

Test attendu:

- la quete ne peut pas etre demarree deux fois;
- le statut de `B1.1` reste stable apres sauvegarde/rechargement;
- `B1.2a` reste fermee.

### Etape 4 - Premier groupe d'objets

But:

- choisir la logique du premier groupe d'objets incas;
- verifier comment le jeu saura qu'ils sont reunis.

Test attendu:

- la condition de retour vers Silehard est claire;
- le joueur ne peut pas toucher deux fois la recompense du premier groupe;
- le journal bascule sur l'etape suivante.

### Etape 5 - Deuxieme entretien avec Silehard

But:

- faire passer la quete de la collecte simple a la mission clandestine;
- lancer la route Isla Muelle.

Test attendu:

- le nom des Fils de l'Ombre d'Inty est introduit;
- la consigne "ne parler qu'aux Anglais" est explicite;
- la premiere recompense est versee une seule fois.

### Etape 6 - PNJ temporaires de `B1.1`

But:

- declarer les six PNJ minimaux de `B1.1` dans `TempQuestCharacters.c`.

Test attendu:

- le jeu demarre;
- les PNJ existent sans forcement etre encore visibles;
- les modeles retenus ne cassent pas le chargement.

### Etape 7 - Isla Muelle

But:

- faire apparaitre le contact anglais et le soldat espagnol;
- gerer le mauvais premier interlocuteur et le retour apres un jour.

Test attendu:

- parler a l'Espagnol fait fuir le contact;
- revenir trop tot ne le fait pas revenir;
- revenir apres un jour relance correctement la scene;
- parler d'abord a l'Anglais ouvre la suite.

### Etape 8 - Remise des pieds

But:

- finaliser la premiere remise de morceau et envoyer le joueur a Conceicao.

Test attendu:

- les pieds ne sont donnes qu'une seule fois;
- l'etat `muelle_done` est stable;
- le journal pointe vers `Conceicao`.

### Etape 9 - Conceicao

But:

- reproduire le pattern Isla Muelle avec le garde portugais;
- rester strictement coherent avec la consigne de Silehard.

Test attendu:

- la punition est identique a Isla Muelle;
- le contact revient apres un jour;
- la remise du corps n'est pas duplicable.

### Etape 10 - Douwesen

But:

- casser la repetition;
- laisser le Hollandais rediriger vers l'Anglais sans echec;
- remettre les bras et l'indice de jungle.

Test attendu:

- aucune fuite a Douwesen;
- parler au Hollandais ou a l'Anglais permet d'avancer;
- le journal passe bien a la phase exploration.

### Etape 11 - Indice et fouille

But:

- placer l'indice autochtone;
- gerer la fouille et l'obtention de la tete.

Test attendu:

- l'indice n'est pas trouvable avant l'etape Douwesen;
- la fouille ne peut pas etre rejouee a l'infini;
- la tete est obtenue une seule fois;
- le retour a Redmond devient disponible.

### Etape 12 - Entretien final avec Silehard

But:

- remettre la statue complete;
- payer la recompense finale;
- poser le doute sur Silehard;
- deverrouiller `B1.2a`.

Test attendu:

- la statue complete est bien verifiee;
- Silehard reste ambigu;
- la recompense finale n'est donnee qu'une seule fois;
- le journal se ferme;
- `B1.2a` devient disponible.

### Etape 13 - Cleanup final

But:

- retirer les PNJ temporaires;
- neutraliser les conditions de temps et de scene;
- laisser l'arc dans un etat propre pour `B1.2a`.

Test attendu:

- aucun contact `B1.1` encore present;
- aucun timer `B1.1` encore arme;
- le joueur ne peut pas reparler aux PNJ pour reobtenir un morceau.

## Logs recommandes

Utiliser des messages simples:

```c
Log_SetStringToLog("PJ B1.1: intro accepted");
Log_SetStringToLog("PJ B1.1: intro objects complete");
Log_SetStringToLog("PJ B1.1: muelle failed by spanish guard");
Log_SetStringToLog("PJ B1.1: muelle piece obtained");
Log_SetStringToLog("PJ B1.1: conceicao failed by portuguese guard");
Log_SetStringToLog("PJ B1.1: conceicao piece obtained");
Log_SetStringToLog("PJ B1.1: douwesen clue obtained");
Log_SetStringToLog("PJ B1.1: dig completed");
Log_SetStringToLog("PJ B1.1: final report complete");
```

## Pieges a eviter

- Demarrer `B1.1` dans le vieux dialogue de Silehard.
- Reutiliser le header `blaze_to_incas_collection`.
- Vouloir coder les trois plages en une seule salve.
- Brancher les recompenses avant d'avoir valide les etats.
- Ajouter trop tot les details d'inventaire des quatre morceaux si la progression simple n'est pas encore stable.
- Oublier les retours apres un jour sur Isla Muelle et Conceicao.
- Fermer `B1.1` sans poser explicitement l'ouverture de `B1.2a`.

## Definition de fini

`B1.1` est consideree stable quand les chemins suivants sont verifies:

1. parcours normal sans erreur sur les trois iles;
2. erreur Isla Muelle puis correction apres un jour;
3. erreur Conceicao puis correction apres un jour;
4. entree via le Hollandais a Douwesen;
5. entree directe via l'Anglais a Douwesen;
6. retour final a Silehard avec fermeture propre du journal et ouverture de `B1.2a`.
