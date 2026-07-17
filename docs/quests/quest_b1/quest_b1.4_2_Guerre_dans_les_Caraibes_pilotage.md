# B1.4 - Guerre dans les Caraibes - Pilotage

## Objectif

Ordonner l'implementation du bloc final a branches.

## Ordre recommande

### Etape 1 - Selecteur de branche

Calculer la sortie de `B1.3` et poser `pchar.quest_b1_4_branch`.

### Etape 2 - Journal `B1.4`

Ajouter les headers des branches.

### Etape 3 - `B1.4a`

Commencer par la mini-route neutre, la plus courte et la plus structurante.

### Etape 4 - Route commune de fin

Poser les flags et evenements de convergence:

- chute de Shango;
- confrontation Silehard;
- epilogue sosie.

### Etape 5 - `B1.4c`

Implementer ensuite la route hispano-portugaise seculiere.

### Etape 6 - `B1.4d`

Implementer la route francaise complete:

- revelation ecclesiale;
- fin d'Inty;
- infiltration de Shango;
- final naval et duel.

### Etape 7 - `B1.4b`

Traiter la route Shango, qui demandera le plus de ton specifique.

## Logs recommandes

```c
Log_SetStringToLog("PJ B1.4: branch selected");
Log_SetStringToLog("PJ B1.4a: neutral route started");
Log_SetStringToLog("PJ B1.4b: shango route started");
Log_SetStringToLog("PJ B1.4c: anti-shango route started");
Log_SetStringToLog("PJ B1.4d: church route started");
Log_SetStringToLog("PJ B1.4: silehard final started");
Log_SetStringToLog("PJ B1.4: sosie installed");
```

## Definition de fini

`B1.4` est stable quand:

1. la bonne branche est selectionnee apres `B1.3`;
2. la route neutre peut rebrancher proprement;
3. chaque branche atteint une forme de confrontation avec Shango;
4. la convergence finale vers Silehard fonctionne;
5. l'epilogue du sosie ferme l'arc proprement.
