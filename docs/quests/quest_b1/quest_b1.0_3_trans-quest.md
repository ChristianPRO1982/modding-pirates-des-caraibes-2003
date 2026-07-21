# Shango - TRANS-QUEST

La quête principale B1 est découpée en plusieurs sous-quêtes quasi indépendantes.

Une couche commune existe permettant de gérer les aspects transverses des quêtes à l'intérieur de B1. Particulièrement, les PNJ comme Malcolm mais aussi tous les personnages du jeu ayant des interactions avec B1 doivent être mis en contexte selon l'avancement des quêtes.

## Variables commune

Ces variables doivent être porter par pchar avec le nom technique de la quête "b1", exemple : pchar.quest.b1_subquest

### sous-quête

Il faut une variable pour expliquer à quel sous-quête, le joueur est en cours d'action. Exemple : "B1.2b".

Il n'y a qu'une seule sous-quête en même temps.

### étape

Il faut une variable expliquant où l'on se n'est dans la sous-quête. Ceci permet de gérer les dialogues futurs.

## Personnages communs

Il y a plein de personnage commun mais les quêtes les gèrent très bien individuellement. Ici nous traiterons uniquement des personnages en lien avec B1 mais n'intervenant pas dans aucune des sous-quêtes.

### Malcolm

Ce bras droit du joueur n'intervient jamais. On le croise à terre dans les ports et permet de données au joueur des informations sur les quêtes customs. Particulièrement, si une des sous-quêtes B1 est en cours, alors il va donner des informations sur ce que le joueur doit faire.

> Les informations de B1 sont de plus en plus précises et divulgache ce que le joueur doit faire

Pendant `B1.2b`, Malcolm sert explicitement de PNJ de "triche".

Regle retenue:

- si `B1.2b` est ouverte et que la piste du Francais n'a pas encore ete identifiee, Malcolm donne une instruction courte, directe et spoilante;
- son aide reste active entre l'ouverture de `B1.2b` et la validation de l'enquete a `Douwesen`.

Replique de reference:

```text
Capt'aine, des expressions comme celles entendus, ca se trouve dans les rues des villes. Va parler aux habitants de chaque ville de ces maudites iles et reprenons la mer au plus vite.
```
