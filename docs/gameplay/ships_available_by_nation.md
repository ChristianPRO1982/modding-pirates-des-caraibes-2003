



Le fichier contient **168 entrées** : 160 variantes nationales, soit 32 par pays, et 8 entrées hors catalogue national. Les cinq pays disposent des mêmes catégories ; seules leurs caractéristiques changent. ?filecite?turn0file0?

> J?emploie ici « disponible » au sens de **type déclaré pour le pays dans `InitShips()`**. Ce fichier ne permet pas, à lui seul, de garantir que le navire est vendu dans tous les chantiers navals.

## 1. Catégories disponibles pour chaque pays

Les pays concernés sont : **France, Espagne, Angleterre, Hollande et Portugal**.

| Classe | Catégories présentes pour chacun des cinq pays | Variantes |
|---:|---|---|
| 6 | `Yacht`, `Barque`, `Lugger` ? lougre | Modèles 1 et 2 |
| 5 | `Galeoth` ? galiote, `Xebec` ? chébec, `Sloop` | Modèles 1 et 2 |
| 4 | `Schooner` ? goélette, `Caravel` ? caravelle, `Fleut` ? flûte | Modèles 1 et 2 |
| 3 | `Brig` ? brick, `Galeon` ? galion, `Pinnace` ? pinasse | Modèles 1 et 2 |
| 2 | `Frigate` ? frégate, `Corvette` | Modèles 1 et 2 |
| 1 | `Battleship` ? vaisseau de ligne, `Manowar` | Modèles 1 et 2 |

Cela représente, pour chaque pays :

- **16 familles de navires** ;
- **32 entrées**, car chaque famille possède deux modèles ;
- **160 entrées nationales** pour l?ensemble des cinq pays.

### Nature des variantes 1 et 2

Dans presque toutes les familles, les modèles `1` et `2` ont les mêmes caractéristiques principales. Ils correspondent essentiellement à des variantes de modèle ou de comportement physique.

L?exception importante est le galion :

| Variante | Interprétation |
|---|---|
| `Galeon1` | Galion normal |
| `Galeon2` | **Galion lourd**, plus résistant et plus capacitaire, mais plus lent |

Il existe aussi une incohérence mineure sur la pinasse espagnole : `Pinnace1` possède **4 300 PV**, tandis que `Pinnace2` en possède **4 200**.

## 2. Différences entre les pays

Les caractéristiques françaises servent manifestement de **valeurs de référence**. Les autres nations appliquent généralement des modificateurs proches de ±5 %.

| Pays | Poids | Capacité | Équipage max. | Équipage min. | Vitesse | Man?uvrabilité | Points de coque | Profil général |
|---|---:|---:|---:|---:|---:|---:|---:|---|
| **France** | Référence | Référence | Référence | Référence | Référence | Référence | Référence | Équilibré |
| **Espagne** | = | **+5 %** | **? +5 %** | = | **?5 %** | **? ?5 %** | **+5 %** | Plus capacitaire et solide, mais plus lent |
| **Angleterre** | = | **?10 %** généralement | **? ?5 %** | **? +5 %** | **+5 %** | **? +5 %** | = | Rapide et maniable, mais moins capacitaire |
| **Hollande** | **? ?5 %** | = | **? ?5 %** | Généralement = | **? +5 %** | = | **?5 %** | Plus léger et rapide, mais plus fragile |
| **Portugal** | **? +5 %** | = | **? +5 %** | = | = | **? +5 %** | **?5 %** | Plus lourd et bien doté en équipage, mais moins résistant |

Les éléments suivants restent identiques entre les nations pour une même catégorie :

- la classe ;
- le nombre de canons ;
- le calibre maximal ;
- le prix ;
- généralement les propriétés physiques secondaires.

### Principales exceptions au système de ±5 %

Le fichier comporte quelques valeurs particulières ou probablement saisies manuellement :

- les lougres sont déjà à `TurnRate = 60`, donc les bonus et malus nationaux de man?uvrabilité ne sont pas appliqués ;
- le lougre anglais possède `MaxCrew = 57`, contre 50 pour la France, alors que l?Angleterre a normalement moins d?équipage ;
- les flûtes anglaises perdent seulement 5 % de capacité, et non 10 % ;
- les galiotes hollandaises ne reçoivent pas le bonus de vitesse habituel ;
- le poids des sloops hollandais et portugais varie d?environ 2 %, au lieu de 5 % ;
- la première pinasse espagnole possède 4 300 PV, soit +7,5 %, alors que la seconde en possède 4 200, soit le +5 % attendu ;
- plusieurs valeurs entières d?équipage sont arrondies, d?où des pourcentages légèrement différents.

Enfin, les `Manowar1` et `Manowar2` existent bien pour les cinq pays, mais ils ont explicitement :

```c
refShip.CanEncounter = false;
```

Ils ne sont donc pas prévus pour apparaître comme rencontres aléatoires normales.

## 3. Entrées hors catalogue national

Ce tableau rassemble toutes les entrées qui ne possèdent pas de suffixe `_FRANCE`, `_SPAIN`, `_ENGLAND`, `_HOLLAND` ou `_PORTUGAL`.

| Entrée | Nature | Classe | Canons | Calibre max. | Vitesse | PV | Rencontre aléatoire |
|---|---|---:|---:|---:|---:|---:|---|
| `SHIP_BOAT` | Petite embarcation générique | 7 | 0 | 0 | 4 | 100 | Oui, valeur héritée |
| `SHIP_TARTANE` | Tartane générique | 7 | 0 | 0 | 7 | 100 | Oui, valeur héritée |
| `SHIP_TARTANE2` | Tartane spéciale | 7 | 0 | 0 | 7 | 100 | Non |
| `SHIP_FRIGATE_SAT` | Frégate spéciale « Satanist » | 2 | 44 | 24 | 15,4 | 6 500 | Non |
| `SHIP_MANOWAR_GUB` | Man?o?war spécial « Guber » | 1 | 100 | 24 | 13,65 | 15 000 | Non |
| `SHIP_BLACK_PEARL` | Black Pearl | 1 | 44 | 32 | 17,2 | **100 000** | Non |
| `SHIP_FEARLESS` | Fearless | 1 | 44 | 32 | 17,2 | 15 000 | Non |
| `SHIP_FORT` | Fort simulé comme un navire | 1 | 68 | 32 | 11,2 | 54 000 | Non |

### Remarques sur les modèles spéciaux

- Le **Black Pearl** et le **Fearless** ont presque les mêmes caractéristiques générales, mais le Black Pearl possède **100 000 PV**, contre 15 000 pour le Fearless.
- La `Frigate_sat` est plus rapide et plus résistante qu'une frégate française normale.
- Le `Manowar_gub` ressemble à un Man?o?war national légèrement modifié.
- `SHIP_FORT` est techniquement enregistré dans `ShipsTypes`, mais ce n'est pas un navire ordinaire.
- `Boat` et `Tartane1` ne sont pas véritablement des navires exceptionnels scénarisés : ce sont plutôt des **embarcations génériques communes à toutes les nations**.