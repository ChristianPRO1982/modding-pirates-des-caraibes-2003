# B1.3 - La Valse des Felons et Tourne-Casaques - Pilotage

## Objectif

Ordonner l'implementation d'une campagne modulaire de guerre, pas d'une seule scene.

## Ordre recommande

### Etape 1 - Journal de campagne

Ajouter `PJ_B1_3` et `PJ_B1_3A`.

### Etape 2 - Flags de campagne

Poser:

- mission courante;
- scores de camp;
- compteurs de trahison;
- etat francais;
- sortie `B1.4`.

### Etape 3 - Debut de guerre

Implementer le declenchement automatique apres `B1.2b`.

### Etape 4 - Squelette mission 01 a 10

Creer la boucle mission/debrief sans encore finaliser chaque contenu.

### Etape 5 - Scoring et resolutions intermediaires

Verifier qu'une mission change bien les scores et que la campagne peut avancer.

### Etape 6 - `B1.3a`

Brancher le kidnaping francais apres six victoires hispano-portugaises.

### Etape 7 - Resolution finale

Calculer les sept issues et poser `pchar.quest_b1_4_branch`.

## Logs recommandes

```c
Log_SetStringToLog("PJ B1.3: war declared");
Log_SetStringToLog("PJ B1.3: mission assigned");
Log_SetStringToLog("PJ B1.3: mission resolved");
Log_SetStringToLog("PJ B1.3: score updated");
Log_SetStringToLog("PJ B1.3a: daughter kidnapped");
Log_SetStringToLog("PJ B1.3a: daughter rescued alive");
Log_SetStringToLog("PJ B1.3: branch to B1.4 decided");
```

## Definition de fini

`B1.3` est stable quand:

1. la guerre se declenche automatiquement;
2. une boucle de dix missions peut s'executer sans casser les scores;
3. `B1.3a` peut s'ouvrir et se fermer;
4. l'une des sept sorties est correctement calculee;
5. la bonne branche `B1.4` est armee.
