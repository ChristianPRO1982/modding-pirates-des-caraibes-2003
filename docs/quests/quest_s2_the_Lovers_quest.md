# S2 The Lovers' Quest

## Overview
`S2` designe une famille de petites quetes urbaines autour de jeunes amoureux qui cherchent un cadeau de fiancailles. Le joueur rencontre un amoureux dans une ville civilisee, accepte de l'aider, trouve le bijou demande, puis le remet a la demoiselle concernee avant la fin du delai.

La famille contient 7 variantes au total: une par port civilise. Il n'y a pas de variante sur l'ile des pirates Quebradas Costillas.

Ce document decrit la version cible a viser pour la suite. `V3` sert ici de reference technique pour comprendre comment la famille etait branchee, pas de modele a recopier a l'identique.

## Availability
`S2` est disponible des le debut du jeu au niveau runtime: il n'y a pas de seuil de quete principale a attendre.

En revanche, l'amoureux ne fait confiance au joueur que si sa reputation est suffisante. La condition de confiance issue de `V3` est conservee:

```c
pchar.reputation > 64
```

Design attendu:

- les amoureux peuvent apparaitre des le debut de partie,
- un joueur de mauvaise reputation peut les rencontrer mais ne peut pas accepter leur demande,
- la condition de reputation appartient au dialogue de l'amoureux, pas au spawn,
- cette condition donne du sens au theme: les amoureux ne confient leur avenir qu'a un capitaine juge fiable.

## Quest Loop
La boucle standard `S2` doit rester simple et courte:

1. Un amoureux apparait aleatoirement dans une ville civilisee.
2. Il explique qu'il aime une demoiselle mais qu'il n'a pas les moyens de lui offrir le cadeau de fiancailles qu'elle attend.
3. Il precise qu'il ne reste qu'une semaine avant le retour d'Europe du pretendant le plus serieux.
4. Le joueur accepte ou refuse d'aider.
5. Si le joueur accepte, une variante `S2` devient active.
6. La demoiselle apparait dans la ville prevue pour cette variante.
7. Le joueur doit obtenir le bijou fixe attendu pour cette ville.
8. Si le joueur remet le bon bijou a temps, la mini-quete est reussie.
9. Si le delai expire, la mini-quete est perdue.
10. La variante concernee ne doit plus etre rejouable.

Une seule variante `S2` peut etre active a la fois.

## Timeout
Le delai cible est de 7 jours.

Il doit etre conserve comme parametre interne au code, afin d'eviter de disperser la valeur magique dans plusieurs endroits. Le nom exact peut etre adapte au style du code existant, mais l'intention doit rester claire:

```c
QUEST_S2_TIMEOUT_DAYS = 7
```

Le timer est arme quand le joueur accepte d'aider l'amoureux.

En cas de reussite, le timer doit etre neutralise proprement.

En cas d'expiration, la variante active est marquee comme terminee mais non reussie.

## Spawn Rules
Le spawn reprend l'esprit de `V3`:

- les PNJ `S2` sont retires des locators a chaque entree de lieu,
- si aucune variante n'est active, le jeu peut faire apparaitre un amoureux eligible,
- le choix est aleatoire par ville, avec un point d'apparition stable,
- si une variante est active, seule la demoiselle correspondante doit apparaitre,
- les amoureux et les demoiselles utilisent des locators de type `goto`,
- la logique principale de spawn reste dans `QuestsCheck_forLocEnter()`.

Le hasard choisit si la rencontre apparait. Il ne doit pas choisir un nouveau locator a chaque fois.

Le bloc debug de `V3`, qui forcait l'apparition des amoureux, peut rester utile comme reference historique mais ne doit pas etre conserve comme comportement normal.

## Cities And Fixed Jewels
Les bijoux restent fixes par ville. Ne pas remplacer ce fonctionnement par un tirage aleatoire.

| Variante | Ville | Amoureux | Demoiselle | Lieu amoureux | Lieu demoiselle | Bijou |
|---|---|---|---|---|---|---|
| 1 | Redmond | Llewellyn Brooker | Magdalen Spooner | `Redmond_town_04` | `Redmond_town_03` | `jewelry7` |
| 2 | Falaise de Fleur | Fabrisse De Lucien | Donatienne de La Fayette | `Falaise_De_Fleur_location_02` | `Falaise_De_Fleur_location_03` | `jewelry10` |
| 3 | Conceicao | Florencio Baiano | Violante Pinto | `Conceicao_town` | `Conceicao_town` | `jewelry14` |
| 4 | Isla Muelle | Cricorium Taffarel | Alejandrina Acosto | `Muelle_town_02` | `Muelle_town_04` | `jewelry13` |
| 5 | Douwesen | Ghijsbrecht Van Der Hagen | Tjaatje Meilink-Roelofsz | `Douwesen_town` | `Douwesen_town` | `jewelry6` |
| 6 | Greenford | Rawlin Feaver | Astrid Weather | `Greenford_town` | `Greenford_town` | `jewelry15` |
| 7 | Oxbay | Rys Scorer | Valeria Pride | `Oxbay_town` | `Oxbay_town` | `jewelry16` |

Commentaires de prix a garder pres du mapping technique:

```c
// jewelry6 : bague en argent et saphir = 769
// jewelry7 : bague en or et emeraude = 961
// jewelry10 : bague en or et saphir = 1538
// jewelry13 : broche en argent = 1538
// jewelry14 : broche en or = 769
// jewelry15 : pendetif emeraude = 769
// jewelry16 : collier en pierres precieuses = 384
```

Note de nettoyage: dans `V3`, l'id de `Alejandrina Acosto` semble contenir une tabulation dans certains appels. La cible doit utiliser un identifiant propre et stable, sans tabulation parasite.

## Dialog Design
Les dialogues existants de `V3` doivent etre conserves dans leur logique generale:

- l'amoureux aborde le joueur,
- il presente son amour et son manque d'argent,
- il explique le delai d'une semaine,
- le joueur peut accepter ou refuser,
- si la reputation est trop faible, l'amoureux refuse de se confier,
- la demoiselle reagit au nom de l'amoureux,
- elle refuse une demande pauvre ou trop simple,
- elle accepte si le joueur apporte le bon bijou,
- elle remercie ensuite le joueur.

Ne pas transformer `S2` en quete marchande pure. Le coeur de la quete est le petit theatre romantique: confiance, cadeau, orgueil social, urgence et recompense morale.

## Success Outcome
La reussite se produit quand le joueur remet a la demoiselle le bijou fixe attendu par la variante active.

Comportement attendu:

1. verifier que le joueur possede le bon bijou,
2. retirer ce bijou de l'inventaire,
3. ajouter l'entree de journal de reussite,
4. donner les gains de mini-quete,
5. marquer la variante comme terminee,
6. marquer la variante comme reussie,
7. fermer proprement le timer,
8. fermer le journal de quete si aucune suite immediate n'est a afficher.

Gains de mini-quete a conserver depuis `V3`:

```c
ChangeCharacterReputation(pchar, 7);
AddPartyExp(pchar, 1000 * makeint(pchar.rank));
```

Il n'y a pas de gain d'argent direct dans une mini-quete `S2`.

## Failure Outcome
L'echec se produit quand le timer expire.

Comportement attendu:

1. afficher le log d'echec,
2. ajouter l'entree de journal d'echec,
3. marquer la variante active comme terminee,
4. ne pas la marquer comme reussie,
5. remettre `pchar.quest_S2_started` a `0`,
6. fermer proprement le timer,
7. empecher cette variante de reapparaitre.

Correction importante par rapport a `V3`:

- ne pas deduire la variante terminee depuis `pchar.location`,
- utiliser la variante active stockee avant remise a zero,
- par exemple `pchar.quest_S2_started`, ou une variable equivalente comme `pchar.quest_S2_current_city`.

Cette correction evite qu'un echec en mer, dans une taverne, dans une jungle ou dans une autre ville ferme la mauvaise variante ou ne ferme aucune variante.

## State Model
La cible doit distinguer clairement deux notions:

- `done`: la variante est terminee et ne peut plus etre rejouee,
- `success`: la variante a ete reussie.

Nommage recommande, a adapter au style exact du depot actif:

```c
pchar.quest_S2_Redmond_done
pchar.quest_S2_Redmond_success
pchar.quest_S2_FalaiseDeFleur_done
pchar.quest_S2_FalaiseDeFleur_success
pchar.quest_S2_Conceicao_done
pchar.quest_S2_Conceicao_success
pchar.quest_S2_IslaMuelle_done
pchar.quest_S2_IslaMuelle_success
pchar.quest_S2_Douwesen_done
pchar.quest_S2_Douwesen_success
pchar.quest_S2_Greenford_done
pchar.quest_S2_Greenford_success
pchar.quest_S2_Oxbay_done
pchar.quest_S2_Oxbay_success
```

`pchar.quest_S2_started` peut rester l'indicateur de variante active:

```c
0 = aucune variante active
1 = Redmond
2 = Falaise de Fleur
3 = Conceicao
4 = Isla Muelle
5 = Douwesen
6 = Greenford
7 = Oxbay
```

Le code doit eviter de remettre `pchar.quest_S2_started` a `0` avant d'avoir utilise sa valeur pour fermer la bonne variante.

## Final Encounter
Quand les 7 variantes ont ete reussies, Fabiola Rochefort apparait et force une discussion avec le joueur.

La logique de rencontre finale de `V3` est bonne dans l'esprit:

- apparition dans la location courante,
- passage en actor type,
- Fabiola suit le joueur,
- le dialogue se lance obligatoirement,
- le joueur reprend ensuite le controle.

Condition cible:

```c
all 7 success flags == true
```

Ne pas declencher la Ligue des Fleurs Bleues si les 7 variantes sont seulement `done` mais pas toutes `success`.

La Ligue remercie le joueur pour les couples effectivement aides, pas pour les echecs.

## Final Reward
La recompense finale doit etre fixe.

Ne pas conserver la recompense variable de `V3` basee sur:

```c
rand(makeint(pchar.skill.Sneak)) + makeint(pchar.rank)
```

Cette formule est historique mais peu lisible et sans lien fort avec le theme romantique de la quete.

Recompense cible:

- 10 x `jewelry6`,
- 10 x `jewelry7`,
- 10 x `jewelry10`,
- 10 x `jewelry13`,
- 10 x `jewelry14`,
- 10 x `jewelry15`,
- 10 x `jewelry16`.

Il ne faut pas ajouter de grosse recompense finale en argent, ni de gros bonus final d'XP. Les mini-quetes donnent deja XP et reputation. Le final sert surtout a rentabiliser les depenses par un coffre de bijoux.

## Repeatability And Completion
Chaque variante `S2` est jouable une seule fois.

La famille n'est pas repetable au sens strict:

- un amoureux deja aide ou echoue ne reapparait plus,
- une ville terminee sort du tirage,
- une variante echouee ne peut pas etre retentee,
- la rencontre finale est unique,
- apres la rencontre finale, `S2` est totalement terminee.

Si certaines variantes sont echouees, la famille peut tout de meme cesser de proposer ces villes, mais la rencontre finale de Fabiola ne doit pas se declencher tant que les 7 variantes ne sont pas reussies.

## Questbook
Le journal de quete reste `PJ_S2`.

Les entrees `V3` servent de reference de structure:

- entrees de route par ville,
- entree de contexte amoureux,
- entree de reussite,
- entree d'echec,
- entree finale avec Fabiola Rochefort.

Format obligatoire du livre de quete:

```text
TEXT    1
Texte de quete.
TEXT    2
Autre texte.
```

Ne pas utiliser de guillemets typographiques, de points de suspension typographiques ou de caracteres hors CP1252.

## Technical Anchors
Points de reference utiles dans le depot historique `V3`:

- logique de spawn: `old_version/V3/PROGRAM/QUESTS/quests.c`
- reactions et timers: `old_version/V3/PROGRAM/QUESTS/quests_reaction.c`
- PNJ temporaires: `old_version/V3/PROGRAM/Characters/French/init/TempQuestCharacters.c`
- dialogue amoureux: `old_version/V3/PROGRAM/DIALOGS/PJ Quest S2 amant_dialog.c`
- textes amoureux: `old_version/V3/PROGRAM/DIALOGS/PJ Quest S2 amant_dialog.h`
- dialogue demoiselle: `old_version/V3/PROGRAM/DIALOGS/PJ Quest S2 smjh_dialog.c`
- textes demoiselle: `old_version/V3/PROGRAM/DIALOGS/PJ Quest S2 smjh_dialog.h`
- dialogue final: `old_version/V3/PROGRAM/DIALOGS/PJ Quest S2 Fabiola Rochefort_dialog.c`
- textes final: `old_version/V3/PROGRAM/DIALOGS/PJ Quest S2 Fabiola Rochefort_dialog.h`
- journal `PJ_S2`: `old_version/V3/RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt`

Ancres de lecture utiles:

- `//quest S2`
- `pchar.quest_S2_started`
- `quest_S2_agreeded`
- `quest_S2_timeOut`
- `quest_S2_closed_1`
- `quest_S2_closed_2`
- `quest_S2_lastQuest`
- `quest_S2_lastQuest_closed`
- `PJ_S2`
- `Fabiola Rochefort`

## Notes from V3
Elements de `V3` a conserver dans l'esprit:

- famille de 7 quetes urbaines,
- une seule variante active a la fois,
- amoureux places aleatoirement dans les villes,
- demoiselle placee quand la variante est active,
- condition de confiance `pchar.reputation > 64`,
- bijoux fixes par ville,
- gains de mini-quete: reputation `+7` et XP `1000 * rank`,
- rencontre finale forcee par Fabiola Rochefort.

Ecarts historiques a corriger:

- `quest_S2_closed_2` ne doit plus utiliser `pchar.location` pour savoir quelle variante fermer,
- le final ne doit plus se declencher sur les seuls flags `done`,
- il faut distinguer les variantes terminees des variantes reussies,
- la recompense finale ne doit plus dependre de `rank + Sneak`,
- l'id de `Alejandrina Acosto` ne doit pas contenir de tabulation parasite.

## Scope
Cette spec reste volontairement courte:

- elle resume `S2` comme mecanique et famille de quetes,
- elle reprend la mecanique generale de `V3`,
- elle fixe les corrections de robustesse attendues,
- elle ne cree pas de nouveau fichier de quete sensible,
- elle ne demande pas de nouvel asset graphique,
- elle ne cree pas de nouveau lieu,
- elle ne transforme pas `S2` en systeme economique ou marchand.

Les details fins de reecriture des dialogues, des textes de journal ou des locators exacts peuvent etre documentes plus tard dans une annexe dediee si necessaire.
