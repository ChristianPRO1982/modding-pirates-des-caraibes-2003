# B1.2 - La Lettre diplomatique et le lieu des rituels - Pilotage

## Objectif

Ce document ordonne l'implementation de `B1.2a` puis `B1.2b`.

Regle principale:

- une seule modification de fichier a la fois;
- test entre chaque etape importante.

## Decisions fermees

- `B1.2` suit directement `B1.1`.
- `B1.2a` est une enquete politique.
- `B1.2b` ajoute un assaut naval puis terrestre.
- le choix du gouverneur rapporte seulement une fidelite differree;
- la guerre demarre quatorze jours apres `B1.2b`;
- `Redmond_Shore_01` est un bon ancrage pour `Gorge du Diable`.

## Decisions encore ouvertes

- ancrage exact de la scene nocturne de Redmond;
- lieu exact des cabanes de `B1.2a`;
- choix des temoins a Douwesen;
- emplacement technique du lieu des rituels a Isla Muelle;
- si la note des voleurs existe comme vrai item ou simple information de quete.

## Ordre recommande

### Etape 1 - Journal `B1.2`

Ajouter les textes `PJ_B1_2A` et `PJ_B1_2B`.

### Etape 2 - Entrees dialogue

Brancher:

- gouverneur portugais;
- Silehard `B1.2b`;
- espion francais.

### Etape 3 - Flags globaux

Poser le squelette `B1.2a` / `B1.2b` et les transitions.

### Etape 4 - Scene de vol a Redmond

Implementer:

- condition de nuit;
- faux soldats;
- retrait des objets;
- apparition de l'espion.

### Etape 5 - Enquete a Douwesen

Implementer:

- trois temoignages minimum;
- confirmation hollandaise;
- ouverture du choix de rapport.

### Etape 6 - Rapport et bonus differe

Memoriser:

- `portugal` ou `england`;
- sans brancher encore l'effet final de `B1.3`.

### Etape 7 - Cabane et note

Faire:

- recherche;
- fouille;
- sortie;
- rendez-vous a Falaise de Fleur.

### Etape 8 - Fin `B1.2a`

Fermer proprement `B1.2a` et ouvrir `B1.2b`.

### Etape 9 - Relance par Silehard

Implementer:

- ordre de poursuite;
- envoi a `Gorge du Diable`;
- soldats anglais.

### Etape 10 - Phase navale

Faire apparaitre:

- flotte ennemie;
- condition de destruction totale;
- debarquement ensuite seulement.

### Etape 11 - Phase terrestre

Implementer:

- progression;
- site rituel;
- dialogue des dissidents;
- combat obligatoire.

### Etape 12 - Echec de recuperation

Verrouiller:

- aucun survivant;
- aucun objet retrouve;
- aucun indice supplementaire.

### Etape 13 - Retour final et timer de guerre

Fermer `B1.2b`, lancer le timer de quatorze jours et preparer `B1.3`.

## Logs recommandes

```c
Log_SetStringToLog("PJ B1.2a: mission accepted");
Log_SetStringToLog("PJ B1.2a: fake soldiers stole items");
Log_SetStringToLog("PJ B1.2a: douwesen inquiry complete");
Log_SetStringToLog("PJ B1.2a: report target memorized");
Log_SetStringToLog("PJ B1.2a: ritual note found");
Log_SetStringToLog("PJ B1.2b: mission accepted");
Log_SetStringToLog("PJ B1.2b: devil throat soldiers reached");
Log_SetStringToLog("PJ B1.2b: fleet destroyed");
Log_SetStringToLog("PJ B1.2b: dissidents dead");
Log_SetStringToLog("PJ B1.2b: war timer started");
```

## Definition de fini

`B1.2` est stable quand les cas suivants sont verifies:

1. rapport portugais puis fin normale;
2. rapport anglais puis fin normale;
3. flotte detruite puis site vide d'indices;
4. timer de quatorze jours qui ouvre bien `B1.3`.
