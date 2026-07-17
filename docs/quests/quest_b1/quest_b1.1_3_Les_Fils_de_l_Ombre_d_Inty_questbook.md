# B1.1 - Les Fils de l'Ombre d'Inty - Livre de quete

## Destination

Ces textes sont destines a etre ajoutes dans:

```text
RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt
```

## Header recommande

```text
#QUEST    PJ_B1_1
```

## Ligne de titre

```text
Les Fils de l'Ombre d'Inty
```

## Texte recommande

```text
#QUEST    PJ_B1_1

Les Fils de l'Ombre d'Inty

#TEXT    1
Le gouverneur anglais de Redmond m'a demande de lui rapporter plusieurs objets incas. Il pretend vouloir les reunir pour une exposition ou pour enrichir sa collection.

#TEXT    2
Je dois maintenant rassembler les objets incas demandes par le gouverneur anglais.

#TEXT    3
J'ai reuni les objets demandes. Il ne me reste plus qu'a retourner a Redmond pour les remettre au gouverneur.

#TEXT    4
Le gouverneur m'a parle d'une ancienne secte nommee les Fils de l'Ombre d'Inty. Il pretend qu'une statue leur appartenait autrefois et que ses differentes parties sont encore dispersees entre plusieurs contacts.

Je dois me rendre sur la Cote eloignee d'Isla Muelle et ne parler qu'aux Anglais.

#TEXT    5
J'ai parle au soldat espagnol avant de m'adresser au contact anglais. L'Anglais a aussitot disparu. Je devrai revenir plus tard.

#TEXT    6
Le contact anglais d'Isla Muelle refuse de parler devant le soldat espagnol. Il m'a demande de poursuivre la conversation sur son navire.

#TEXT    7
J'ai obtenu les pieds de la statue. Le prochain contact m'attendrait au Havre radieux, a Conceicao, en compagnie d'un Portugais.

#TEXT    8
J'ai parle au Portugais avant de m'adresser au contact anglais. L'Anglais a disparu, comme a Isla Muelle. Je devrai revenir demain.

#TEXT    9
Le contact anglais de Conceicao refuse lui aussi de parler sur la plage. Il m'attend sur son navire.

#TEXT    10
J'ai obtenu le corps de la statue. Les bras se trouveraient sur la Plage aux palmiers de Douwesen, chez un autre contact anglais accompagne cette fois d'un Hollandais.

#TEXT    11
J'ai obtenu les bras de la statue. Le dernier morceau, la tete, n'est plus conserve par le reseau. Elle aurait ete enterree dans la jungle et un ancien indice autochtone permettrait de retrouver l'endroit exact.

#TEXT    12
J'ai trouve dans la jungle un ancien signe qui semble indiquer un endroit ou creuser.

#TEXT    13
J'ai retrouve la tete de la statue. Toutes les pieces sont maintenant reunies. Je dois retourner a Redmond pour remettre la statue au gouverneur anglais.

#TEXT    14
J'ai remis la statue au gouverneur anglais. Son enthousiasme et ses connaissances m'ont paru excessifs pour un simple amateur d'antiquites. Il pretend pourtant que cette statue rejoindra une grande exposition en Europe.

Le gouverneur estime que je l'ai bien servi et il pourrait me confier des missions plus importantes a l'avenir.
```

## Correspondance des etapes

| TEXT | Etat cible | Usage |
|---|---|---|
| 1 | Intro acceptee | Silehard a confie la premiere collecte. |
| 2 | Collecte du premier groupe | Le joueur cherche les objets incas. |
| 3 | Premier groupe complet | Retour a Redmond. |
| 4 | Deuxieme entretien avec Silehard | La mission statue commence. |
| 5 | Echec Isla Muelle | Le joueur a parle au mauvais interlocuteur. |
| 6 | Isla Muelle, suite anglaise | Transition vers la remise. |
| 7 | Pieds obtenus | Cap sur Conceicao. |
| 8 | Echec Conceicao | Le joueur a parle au mauvais interlocuteur. |
| 9 | Conceicao, suite anglaise | Transition vers la remise. |
| 10 | Corps obtenu | Cap sur Douwesen. |
| 11 | Bras obtenus | Debut de l'exploration jungle. |
| 12 | Indice trouve | Le joueur sait qu'il faut creuser. |
| 13 | Tete obtenue | Retour final vers Silehard. |
| 14 | Quete terminee | Fermeture de `B1.1` et ouverture de la suite. |

## Notes de contenu

- Le journal ne doit jamais nommer Shango.
- Le journal ne doit jamais confirmer qu'Inty est encore active.
- Le journal peut trouver Silehard etrange, mais pas le demasquer.
- Le joueur doit sentir que les "relations diplomatiques" sont douteuses sans recevoir d'explication definitive.

## Sequence de fermeture recommandee

Sequence cible a la fin:

```c
SetQuestHeader("PJ_B1_1");
AddQuestRecord("PJ_B1_1", "14");
CloseQuestHeader("PJ_B1_1");
```

Si le header est deja ouvert, ne pas le dupliquer inutilement.

## Points de vigilance

- Garder le header `PJ_B1_1` distinct du vieux `blaze_to_incas_collection`.
- Ne pas copier tel quel les anciens textes incas du jeu de base.
- Verifier les tabulations et espaces autour de `#QUEST` et `#TEXT`.
- Conserver l'encodage attendu par le fichier final si insertion dans `quests_texts.txt`.
