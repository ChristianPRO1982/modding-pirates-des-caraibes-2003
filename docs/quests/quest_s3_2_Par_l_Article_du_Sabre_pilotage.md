# S3 - Par l'Article du Sabre - Pilotage implementation

## Objectif

Ce document sert uniquement a cadrer l'ordre d'implementation de la quete `S3 - Par l'Article du Sabre : le Verbe et la Lame decident`.

Il ne remplace pas les fichiers de contexte technique du moteur deja presents dans le repo.
Il ne doit pas pousser a modifier plusieurs fichiers a la fois.

Regle principale: une seule modification de fichier a la fois, puis test en jeu.

## Principe de travail

- avancer par petites tranches,
- ne modifier qu'un fichier par etape,
- tester chaque etape avant de passer a la suivante,
- conserver des logs avec `Log_SetStringToLog("...")`,
- ne jamais creer de nouveau fichier sensible de quete,
- ne jamais melanger deux causes possibles dans le meme test.

## Decisions fermees

- `S3` est disponible des le debut de partie.
- `S3` est une quete courte de type `S`, meme si sa profondeur morale est plus forte qu'une petite quete classique.
- Le commanditaire apparait en sortie de ville.
- Le commanditaire inspire la mefiance mais reste credible.
- La cible est soit innocente, soit coupable.
- Le joueur peut interroger des habitants avant de trancher.
- Le pretre dit toujours la verite.
- Les autres informateurs peuvent donner une information vraie, fausse ou incertaine.
- La resolution normale tue soit la cible, soit le commanditaire.
- Une fois une resolution atteinte, la quete est terminee.

## Decisions ouvertes

Les points suivants doivent etre verrouilles avant integration complete:

- `S3` est-elle unique ou repetable ?
- Le delai de 2 jours est-il conserve ?
- Que se passe-t-il si le delai expire ?
- Quelles villes sont eligibles ?
- Le commanditaire doit-il apparaitre dans toutes les sorties de ville ou seulement certaines ?
- La cible est-elle placee des l'acceptation ou seulement apres une premiere enquete ?
- Les restrictions chez les marchands sont-elles implementees tout de suite ou seulement preparees par flag ?
- La recompense de la ville est-elle donnee par un habitant generique, par un officier ou directement via log/journal ?

## Ordre recommande d'implementation

### Etape 1 - Livre de quete

But: ajouter uniquement les textes `PJ_S3` dans le fichier de journal.

Test attendu:

- le jeu demarre,
- le fichier texte est lu correctement,
- aucun caractere invalide ne s'affiche,
- aucune regression sur les autres livres de quete.

### Etape 2 - Textes de dialogue statiques

But: ajouter les textes necessaires aux dialogues sans brancher encore toute la logique.

Test attendu:

- les fichiers de dialogue se chargent,
- aucune erreur de parsing,
- les apostrophes et caracteres CP1252 sont corrects.

### Etape 3 - PNJ temporaires

But: declarer le commanditaire et la cible comme PNJ temporaires.

Test attendu:

- le jeu demarre,
- les PNJ existent sans etre encore forcement visibles,
- les modeles choisis ne cassent pas le chargement.

### Etape 4 - Spawn du commanditaire

But: faire apparaitre le commanditaire en sortie de ville.

Test attendu:

- le commanditaire apparait au bon endroit,
- il n'apparait pas en double,
- il ne reapparait pas si la quete est deja active ou terminee.

### Etape 5 - Acceptation et refus

But: brancher le premier dialogue du commanditaire.

Test attendu:

- accepter initialise les flags de quete,
- refuser ferme proprement le dialogue,
- interrompre permet de reparler au commanditaire si c'est le comportement retenu.

### Etape 6 - Tirage de la cible et de sa verite

But: choisir une cible et determiner si elle est innocente ou coupable.

Test attendu:

- une seule cible est choisie,
- le genre de la cible est conserve,
- l'etat innocent/coupable est conserve apres sauvegarde/rechargement,
- le journal mentionne la bonne etape.

### Etape 7 - Enquete aupres des PNJ

But: permettre d'interroger les informateurs.

Test attendu:

- le pretre donne toujours une information vraie,
- les autres PNJ suivent leur logique de fiabilite,
- les reponses ne bloquent pas la quete,
- interroger plusieurs PNJ ne duplique pas les flags critiques.

### Etape 8 - Dialogue avec la cible

But: permettre au joueur de poursuivre l'enquete, menacer la cible ou la laisser partir.

Test attendu:

- poursuivre l'enquete ne change pas la resolution,
- menacer peut mener au combat apres confirmation,
- liberer la cible pose le bon flag pour le retour au commanditaire.

### Etape 9 - Resolution cible tuee

But: finir la quete si le joueur tue la cible.

Test attendu:

- si la cible etait coupable: recompense positive,
- si la cible etait innocente: recompense mauvaise ou reputational penalty,
- le commanditaire paie selon le scenario,
- cleanup complet apres paiement.

### Etape 10 - Resolution cible liberee

But: faire revenir le joueur au commanditaire et declencher le duel.

Test attendu:

- le commanditaire reagit a la liberation,
- le duel se lance proprement,
- si la cible etait innocente: bonne resolution,
- si la cible etait coupable: mauvaise resolution,
- cleanup complet apres combat.

### Etape 11 - Recompenses, reputation et sanctions

But: appliquer les consequences finales.

Test attendu:

- argent donne une seule fois,
- experience donnee une seule fois,
- reputation montee ou baissee selon le bon cas,
- restrictions marchands appliquees seulement si la fonctionnalite est confirmee.

### Etape 12 - Nettoyage final

But: supprimer tout etat temporaire inutile.

Test attendu:

- plus aucun PNJ S3 temporaire actif,
- aucun dialogue S3 bloque sur des PNJ ordinaires,
- aucun item temporaire si un item est ajoute plus tard,
- aucun flag actif ne permet de relancer une etape terminee.

## Invariants

- Une seule quete `S3` peut etre active a la fois.
- Un seul commanditaire `S3` peut exister a la fois.
- Une seule cible `S3` peut exister a la fois.
- La verite de la cible ne change jamais apres tirage.
- Le pretre ne ment jamais.
- Le joueur ne doit jamais recevoir deux fois la meme recompense finale.
- Une resolution finale doit toujours appeler le cleanup.
- Une quete terminee ne doit pas redevenir active sans decision explicite de design.

## Logs recommandes

Utiliser des messages courts et distincts:

```c
Log_SetStringToLog("PJ S3: spawn commanditaire");
Log_SetStringToLog("PJ S3: contrat accepte");
Log_SetStringToLog("PJ S3: cible choisie");
Log_SetStringToLog("PJ S3: cible tuee");
Log_SetStringToLog("PJ S3: cible liberee");
Log_SetStringToLog("PJ S3: commanditaire tue");
Log_SetStringToLog("PJ S3: cleanup final");
```

## Pieges a eviter

- Ne pas utiliser de guillemets typographiques.
- Ne pas utiliser de caracteres hors CP1252.
- Ne pas inserer d'accents dans les identifiants.
- Ne pas creer de nouveaux fichiers `quests.c`, `quests_check.c` ou `quests_reaction.c`.
- Ne pas integrer toutes les branches d'un coup.
- Ne pas brancher les recompenses avant d'avoir valide les fins.
- Ne pas laisser un PNJ temporaire sans cleanup.
- Ne pas faire dependre la verite de la cible d'un dialogue rejoue.

## Definition de fini

La quete `S3` est consideree stable quand les quatre chemins principaux sont testes:

1. cible coupable tuee,
2. cible innocente tuee,
3. cible innocente liberee puis commanditaire tue,
4. cible coupable liberee puis commanditaire tue.

Chaque chemin doit verifier:

- journal correct,
- dialogue correct,
- combat correct si necessaire,
- recompense ou sanction correcte,
- cleanup complet,
- sauvegarde/rechargement sans casse.
