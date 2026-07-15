# M1 - Le Pirate des Caraïbes : livre de quête

## Rôle du fichier

Ce fichier regroupe les textes du journal `PJ_M1` et leur correspondance avec les étapes techniques de la quête.

Les textes ci-dessous reprennent le contenu historique en corrigeant les fautes manifestes de langue. Les identifiants `PJ_M1` et les numéros `#TEXT` doivent rester inchangés lors de l'intégration dans `quests_texts.txt`.

Le fichier runtime de référence est :

```text
RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt
```

## 1. Correspondance des textes

| Texte | Moment d'ajout | Fonction |
|---:|---|---|
| 1 | Acceptation de la proposition de François | Présentation de l'objectif |
| 2 | Retour après Redmond | Première capture |
| 3 | Retour après Falaise de Fleur | Deuxième capture |
| 4 | Retour après Conceicao | Troisième capture |
| 5 | Retour après Isla Muelle | Quatrième capture |
| 6 | Retour après Douwesen | Cinquième capture |
| 7 | Retour après Greenford | Sixième capture |
| 8 | Retour après Oxbay | Septième capture / texte spécifique |
| 9 | Après le premier retour validé | Six forts restants |
| 10 | Après le deuxième retour validé | Cinq forts restants |
| 11 | Après le troisième retour validé | Quatre forts restants |
| 12 | Après le quatrième retour validé | Trois forts restants |
| 13 | Après le cinquième retour validé | Deux forts restants |
| 14 | Après le sixième retour validé | Un fort restant |
| 15 | Après les sept validations | Titre et retour vers Quebradas Costillas |
| 16 | Après le dialogue de Chui | Reddition de François et prison |
| 17 | Après le dialogue final de François | Récompense et fermeture |

Le code historique ajoute le texte de capture 2 à 8 selon le port, puis ajoute le texte 9 à 15 selon la valeur de `quest_M1_step`. Le texte 15 n'est donc ajouté qu'au passage à l'étape finale.

## 2. Version cible du livre de quête

```text
#QUEST PJ_M1
François l'Olonnais et le nouveau 'Pirate des Caraïbes'

#TEXT 1
J'ai rencontré François l'Olonnais et il m'a raconté son histoire. Il est très malade et veut me donner son fabuleux trésor ainsi que son titre de 'Pirate des Caraïbes'. Pour cela, je dois affronter toutes les nations en prenant les forts des îles des Caraïbes. Rien que ça ! La tâche va être rude, mais je peux compter sur le soutien de Quebradas Costillas pour refaire mon armement.

#TEXT 2
Redmond a été capturé. C'est l'une des îles les mieux défendues, mais ses défenseurs ont compris à qui ils avaient affaire.

#TEXT 3
Falaise de Fleur a été capturée. Cela n'a pas été simple : les défenseurs se sont bien battus. Mais leur courage n'a pas suffi face à ma détermination.

#TEXT 4
Conceicao est tombée. Elle était peut-être moins défendue que les autres, mais la prise du fort n'a pas été simple.

#TEXT 5
Isla Muelle n'a pas tenu. Je m'attendais à une armada invincible, mais il faut croire que leurs navires de guerre sont importants ailleurs.

#TEXT 6
Douwesen ! Encore une fois, son gouverneur ne brille pas lorsqu'il s'agit de défendre militairement son île.

#TEXT 7
Greenford est tombé. Encore une fois !

#TEXT 8
Oxbay a été capturé. Je m'attendais à une promenade de santé, mais leur fort est plus solide qu'il n'y paraît.

#TEXT 9
Encore six forts à capturer.

#TEXT 10
Encore cinq forts à capturer.

#TEXT 11
Encore quatre forts à capturer.

#TEXT 12
Encore trois forts à capturer.

#TEXT 13
Encore deux forts à capturer.

#TEXT 14
Un dernier fort reste encore à prendre.

#TEXT 15
C'est fait ! Tous les forts des Caraïbes sont tombés sous mes canons. Je suis le nouveau 'Pirate des Caraïbes'. Mais où est François l'Olonnais ? Peut-être est-il retourné sur Quebradas Costillas...

#TEXT 16
François l'Olonnais s'est rendu aux armées qui le cherchaient depuis tant d'années. Il se trouve à la prison de Redmond.

#TEXT 17
Cette fois, c'est terminé. François l'Olonnais s'est rendu aux armées qui le cherchaient. Son procès fut bref, pour ne pas dire qu'il n'y en eut pas ! Je suis parti avant qu'on ne le pende ; je n'avais pas le coeur à assister à ce spectacle. Avant de le voir partir, François m'a adressé un regard qui restera gravé dans ma mémoire : c'était comme s'il m'adoubait comme le nouveau 'PIRATE DES CARAÏBES'. C'est un honneur pour moi. Adieu, François. Cependant, ses dernières paroles me laissent croire qu'il y a autre chose. En tout cas, le trésor de François est fabuleux : 200 diamants et 150 pépites d'or. Je suis très riche.
```

## 3. Règles d'intégration

- conserver `#QUEST PJ_M1` ;
- conserver les numéros de texte de 1 à 17 ;
- ne pas insérer les triples backticks dans `quests_texts.txt` ;
- garder l'encodage ISO-8859-1 attendu par les fichiers historiques du dépôt ;
- éviter les guillemets typographiques dans les fichiers runtime si le parseur local les supporte mal ;
- vérifier l'affichage de `Caraïbes`, `François`, `récompense`, `pépites` et `coeur` après insertion ;
- ne fermer `PJ_M1` qu'après l'ajout du texte 17.

## 4. Points de synchronisation code / journal

| Appel code | Texte attendu |
|---|---:|
| `AddQuestRecord("PJ_M1", 1)` | 1 |
| `AddQuestRecord("PJ_M1", 2)` à `AddQuestRecord("PJ_M1", 8)` | Capture du port correspondant |
| `M1_EndQuest()` aux étapes 3 à 8 | 9 à 14 |
| `M1_EndQuest()` à l'étape 9 | 15 |
| `quest_M1_GotoRedmondPrison` | 16 |
| `quest_M1_END_3` | 17 |

Une version corrigée du texte ne doit pas modifier les appels numériques du code. Si le design final change l'ordre libre des forts, les textes 2 à 8 doivent rester liés à la colonie réellement capturée, tandis que les textes 9 à 14 doivent rester liés au nombre de validations déjà effectuées.

## 5. Validation avant intégration

- relire le bloc dans le contexte de `quests_texts.txt` ;
- vérifier qu'aucun `#TEXT` existant n'est écrasé ;
- vérifier que `PJ_M1` n'existe qu'une seule fois ;
- charger le livre en jeu avec une sauvegarde avant M1 ;
- vérifier le texte 1 après acceptation ;
- vérifier les textes 2 à 15 dans un ordre de capture non linéaire ;
- vérifier les textes 16 et 17 après la séquence de prison ;
- vérifier les caractères accentués et l'absence de mojibake.
