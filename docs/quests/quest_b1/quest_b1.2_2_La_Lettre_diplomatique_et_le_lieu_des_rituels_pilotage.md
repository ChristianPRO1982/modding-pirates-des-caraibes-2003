# B1.2 - La Lettre diplomatique et le lieu des rituels - Pilotage

## Objectif

Ce document ordonne l'implementation de `B1.2a` puis `B1.2b`.

Regle principale:

- une seule modification de fichier a la fois;
- test entre chaque etape importante.

## Decisions fermees

- `B1.2` suit directement `B1.1`.
- `B1.2a` est une enquete politique.
- `B1.2b` ajoute une enquete urbaine, puis un assaut naval, puis une confrontation terrestre.
- `B1.2a` se ferme et `B1.2b` s'ouvre sur le meme trigger chez Silehard.
- `Malcolm` peut donner une aide de triche pendant `B1.2b`.
- l'enquete `B1.2b` passe par `Douwesen`, puis `Falaise de Fleur`, puis un retour a Silehard.
- `Silehard`, et non des soldats anglais, donne la localisation finale du rite.
- le debarquement narratif est `Cote eloignee`.
- le lieu des rituels est une grotte.
- la flotte defensive est composee de `1 fregate` et `1 corvette`.
- le choix du gouverneur rapporte seulement une fidelite differree.
- la guerre demarre quatorze jours apres `B1.2b`.

## Ordre recommande

### Etape 1 - Journal `B1.2`

Ajouter ou mettre a jour les textes `PJ_B1_2A` et `PJ_B1_2B`.

### Etape 2 - Entrees dialogue

Brancher:

- gouverneur portugais;
- Silehard `B1.2a` et `B1.2b`;
- Malcolm `B1.2b`;
- gouverneur francais;
- espion francais.

### Etape 3 - Flags globaux

Poser le squelette `B1.2a` / `B1.2b` et les transitions.

### Etape 4 - Scene de vol a Redmond

Implementer:

- condition de nuit;
- faux soldats;
- retrait des objets;
- memorisation du choix de rapport.

### Etape 5 - Cloture `B1.2a` et ouverture `B1.2b`

Fermer `B1.2a` au dernier dialogue de colere chez Silehard et ouvrir `B1.2b` sur le meme trigger.

### Etape 6 - Malcolm et enquete a Douwesen

Implementer:

- aide de Malcolm;
- trois temoignages minimum;
- usage des expressions hollandaises;
- renvoi vers le Francais.

### Etape 7 - Gouverneur francais et espion

Faire:

- presentation au gouverneur;
- renvoi vers l'espion dans la meme piece;
- briefing du Francais;
- retour chez Silehard.

### Etape 8 - Localisation finale par Silehard

Implementer:

- localisation `Cote eloignee`;
- annonce du rite en grotte;
- preparation du deplacement a `Isla Muelle`.

### Etape 9 - Phase navale

Faire apparaitre:

- `1 fregate` et `1 corvette`;
- condition de destruction totale;
- debarquement ensuite seulement.

### Etape 10 - Phase terrestre

Implementer:

- progression vers la grotte;
- interruption du rite;
- dialogue du `chef des pretres`;
- combat obligatoire.

### Etape 11 - Echec de recuperation

Verrouiller:

- aucun survivant;
- aucun objet retrouve;
- aucun indice supplementaire.

### Etape 12 - Retour final et timer de guerre

Fermer `B1.2b`, lancer le timer de quatorze jours et preparer `B1.3`.

## Logs recommandes

```c
Log_SetStringToLog("PJ B1.2a: mission accepted");
Log_SetStringToLog("PJ B1.2a: fake soldiers stole items");
Log_SetStringToLog("PJ B1.2a: report target memorized");
Log_SetStringToLog("PJ B1.2b: mission accepted");
Log_SetStringToLog("PJ B1.2b: malcolm hint given");
Log_SetStringToLog("PJ B1.2b: douwesen inquiry complete");
Log_SetStringToLog("PJ B1.2b: french spy briefed");
Log_SetStringToLog("PJ B1.2b: isla muelle location confirmed");
Log_SetStringToLog("PJ B1.2b: fleet destroyed");
Log_SetStringToLog("PJ B1.2b: priests dead");
Log_SetStringToLog("PJ B1.2b: war timer started");
```

## Definition de fini

`B1.2` est stable quand les cas suivants sont verifies:

1. rapport portugais puis transition normale vers `B1.2b`;
2. rapport anglais puis transition normale vers `B1.2b`;
3. Malcolm puis `Douwesen` puis espion francais puis retour Silehard;
4. flotte detruite puis grotte vide d'indices;
5. timer de quatorze jours qui ouvre bien `B1.3`.
