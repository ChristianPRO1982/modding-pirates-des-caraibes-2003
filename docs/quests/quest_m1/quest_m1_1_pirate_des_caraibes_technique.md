# M1 - Le Pirate des Caraïbes : fonctionnement technique historique

## Objet du document

Ce document reconstitue le fonctionnement de l'ancienne quête `M1`, retrouvée dans `OLD/` sous les tags `PJ_M1` et `quest_M1_*`.

La quête met en scène François l'Olonnais, qui propose au joueur de devenir le nouveau « Pirate des Caraïbes » en capturant les sept forts des îles principales. Elle se termine par la remise du titre, d'une récompense importante et la séquence de reddition de François.

Le document distingue volontairement :

- le fonctionnement voulu par les dialogues et le livre de quête ;
- le fonctionnement effectivement porté par le code historique ;
- les anomalies ou raccourcis de développement à ne pas reproduire tels quels.

## Sources historiques

Les fichiers `OLD/` sont des archives de référence et non des fichiers runtime à modifier.

| Fonction | Fichier historique |
|---|---|
| Initialisation de l'état M1 | `OLD/PROGRAM/Characters/French/characters_init.c` |
| Apparition de François et de Chui | `OLD/PROGRAM/QUESTS/quests.c` |
| Réactions, conditions et transitions | `OLD/PROGRAM/QUESTS/quests_reaction.c` |
| Vérification de `FORT_destroy` | `OLD/PROGRAM/QUESTS/quests_check.c` |
| PNJ temporaires et capitaines de flotte | `OLD/PROGRAM/Characters/French/init/TempQuestCharacters.c` |
| Dialogue de François | `OLD/PROGRAM/DIALOGS/PJ Quest M1 Francois l_Olonnais_dialog.c` |
| Textes du dialogue de François | `OLD/PROGRAM/DIALOGS/French/PJ Quest M1 Francois l_Olonnais_dialog.h` |
| Dialogue de Chui A-poo | `OLD/PROGRAM/DIALOGS/PJ Quest M1 Chui A-poo_dialog.c` |
| Textes du dialogue de Chui A-poo | `OLD/PROGRAM/DIALOGS/French/PJ Quest M1 Chui A-poo_dialog.h` |
| Journal de quête | `OLD/RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt` |
| Message de fin de capture | `OLD/RESOURCE/INI/TEXTS/FRENCH/globals.txt` |

Le système générique de réparation après capture se trouve dans le fichier actif `PROGRAM/INTERFACE/fortcapture.c`.

## Documentation complémentaire créée

Ce document reste la référence historique et technique de M1. Deux documents complémentaires ont été créés pour permettre une reprise plus directe, sans dupliquer les dialogues déjà présents dans `OLD/` :

| Document | Rôle |
|---|---|
| `docs/quests/quest_m3_2_pirate_des_caraibes_pilotage.md` | Décisions de reprise, architecture active, flags cibles, ordre d'implémentation et tests |
| `docs/quests/quest_m3_3_pirate_des_caraibes_questbook.md` | Correspondance des textes 1 à 17 et version cible du livre de quête |

Les fichiers de dialogue ne sont pas dupliqués dans `docs/` : leurs sources historiques sont déjà listées dans le tableau précédent et devront être repris avec vérification des noeuds et de l'encodage.

## 1. Déclenchement et état initial

### État stocké

Dans `characters_init.c`, l'état initial est :

```c
ch.quest_M1_step = -1;
```

La valeur `-1` signifie que la quête n'est pas encore ouverte.

### Ouverture historique

Dans `quests_reaction.c`, le handler `end_game` exécute :

```c
pchar.quest_M1_step = 0;
```

Ce handler arrive après la mort du boss final, la vidéo de fin et les crédits. La formulation « après la fin de la quête principale » est donc correcte au niveau du design, mais l'ancre technique historique est `end_game`, et non un test général sur `pchar.quest.main_line`.

Dans la version active actuelle, `end_game` réinitialise seulement certains dialogues et ne contient plus cette affectation M1. La reprise devra donc prévoir explicitement le point de raccordement après la fin de la quête principale.

### Apparition de François

À chaque entrée de lieu, `QuestsCheck_forLocEnter()` commence par mémoriser le lieu du joueur, puis exécute la logique M1 :

```c
if (makeint(pchar.quest_M1_step) == 0 &&
    pchar.location == "QC_pirate_house_inside")
{
    PlaceCharacter(characterFromID("Francois_l_Olonnais"), "goto", homelocation);
}
```

François apparaît donc dans la maison des pirates de Quebradas Costillas (`QC_pirate_house_inside`), au prochain chargement de ce lieu après l'ouverture de la quête.

Il n'y a pas de tirage aléatoire et pas de condition de réputation dans ce spawn.

## 2. Première rencontre et acceptation

Le PNJ `Francois_l_Olonnais` utilise le dialogue :

```text
PJ Quest M1 Francois l_Olonnais_dialog.c
```

Le dialogue suit une longue chaîne `Continue_01` à `Continue_15`. François explique :

1. son identité et sa survie ;
2. sa retraite et sa maladie ;
3. son ancien titre de « Pirate des Caraïbes » ;
4. la capture des sept forts ;
5. l'hostilité temporaire de toutes les nations ;
6. la trêve avec les pirates ;
7. les réparations gratuites liées aux captures ;
8. la reddition de François une fois le titre transmis.

Le joueur peut quitter le dialogue avant d'accepter. L'acceptation passe par le noeud `agreeded`, qui appelle :

```c
AddDialogExitQuest("quest_M1_agreeded");
```

Le noeud d'attente après refus est `Waiting`. La quête n'est pas fermée par un refus : François peut être reparlé tant que `quest_M1_step` vaut `0`.

## 3. Initialisation de la conquête

Le handler `quest_M1_agreeded` réalise toutes les opérations de démarrage.

### Journal et compagnon

Il recrée l'en-tête du journal et ajoute le texte 1 :

```c
DeleteQuestHeader("PJ_M1");
SetQuestHeader("PJ_M1");
AddQuestRecord("PJ_M1", 1);
```

François est placé comme officier avec :

```c
SetOfficersIndex(Pchar, -1, GetCharacterIndex("Francois_l_Olonnais"));
```

Puis l'étape est initialisée à `2` :

```c
Pchar.quest_M1_step = 2;
```

La valeur `2` est importante : après la capture d'un fort et le retour au port, l'étape est incrémentée. Le premier retour produit donc `3`, et la fin de la septième conquête produit `9`.

### Relations avec les nations

Avant de modifier les relations, le script mémorise les relations du joueur avec :

- `ENGLAND` ;
- `FRANCE` ;
- `SPAIN` ;
- `PORTUGAL` ;
- `HOLLAND`.

Ces valeurs sont stockées dans :

```text
pchar.quest_M1_NationRelation_ENGLAND
pchar.quest_M1_NationRelation_FRANCE
pchar.quest_M1_NationRelation_SPAIN
pchar.quest_M1_NationRelation_PORTUGAL
pchar.quest_M1_NationRelation_HOLLAND
```

Ensuite, les cinq nations deviennent ennemies et les pirates deviennent amis :

```c
SetNationRelation2MainCharacter(ENGLAND, RELATION_ENEMY);
SetNationRelation2MainCharacter(FRANCE, RELATION_ENEMY);
SetNationRelation2MainCharacter(SPAIN, RELATION_ENEMY);
SetNationRelation2MainCharacter(PORTUGAL, RELATION_ENEMY);
SetNationRelation2MainCharacter(HOLLAND, RELATION_ENEMY);
SetNationRelation2MainCharacter(PIRATE, RELATION_FRIEND);
```

### Blocage des reloads d'îles

Le script appelle également :

```c
Island_SetReloadEnableGlobal("Redmond", false);
Island_SetReloadEnableGlobal("FalaiseDeFleur", false);
Island_SetReloadEnableGlobal("Conceicao", false);
Island_SetReloadEnableGlobal("IslaMuelle", false);
Island_SetReloadEnableGlobal("Douwesen", false);
Island_SetReloadEnableGlobal("Oxbay", false);
```

Le commentaire historique parle de désactivation de la capacité de débarquement. Ce verrouillage fait partie de la contrainte de la campagne : le joueur ne doit pas utiliser normalement les îles civiles comme base de ravitaillement pendant la conquête.

Les reloads sont tous réactivés dans `quest_M1_GotoRedmondPrison`, après la fin de la conquête et le déclenchement de la séquence de prison.

## 4. Conditions de progression

Les sept conditions de forts et les sept conditions de ports sont armées simultanément dans `quest_M1_agreeded`.

### Conditions des forts

Chaque fort utilise la forme :

```c
Pchar.quest.<id>.win_condition.l1 = "FORT_destroy";
Pchar.quest.<id>.win_condition.l1.character = "<Commander ID>";
Pchar.quest.<id>.win_condition = "<handler>";
```

| Fort / colonie | Commandant surveillé | Condition | Réaction immédiate |
|---|---|---|---|
| Redmond | `Redmond Commander` | `quest_M1_CaptureRedmondFort` | François est remis comme officier |
| Falaise de Fleur | `FalaiseDeFleur Commander` | `quest_M1_CaptureFalaiseDeFleurFort` | François est remis comme officier |
| Conceicao | `Conceicao Commander` | `quest_M1_CaptureConceicaoFort` | François est remis comme officier |
| Isla Muelle | `IslaMuelle Commander` | `quest_M1_CaptureIslaMuelleFort` | François est remis comme officier |
| Douwesen | `Douwesen Commander` | `quest_M1_CaptureDouwesenFort` | François est remis comme officier |
| Greenford | `Greenford Commander` | `quest_M1_CaptureGreenfordFort` | François est remis comme officier |
| Oxbay | `Oxbay Commander` | `quest_M1_CaptureOxbayFort` | François est remis comme officier |

Le nom de condition est écrit `FORT_destroy` lors de sa déclaration, tandis que `quests_check.c` traite le cas `Fort_destroy`. Cette différence de casse est un point de fragilité historique à harmoniser dans une reprise.

Le test de condition repose sur l'attribut `FortDestroy` du commandant. L'événement global `FORT_DESTROYED` est reçu par `QuestFortDestroyed()`, qui pose :

```c
chref.FortDestroy = "1";
```

Puis il relance `QuestsCheck()`.

### Conditions d'arrivée dans les ports

Une fois la capture lancée, sept conditions de localisation sont également armées :

| Port contrôlé | Condition | Texte de capture |
|---|---|---:|
| `Redmond_port` | `quest_M1_FightingInRedmondPort` | `PJ_M1`, texte 2 |
| `FalaiseDeFleur_port` | `quest_M1_FightingInFalaiseDeFleurPort` | `PJ_M1`, texte 3 |
| `Conceicao_port` | `quest_M1_FightingInConceicaoPort` | `PJ_M1`, texte 4 |
| `IslaMuelle_port` | `quest_M1_FightingInIslaMuellePort` | `PJ_M1`, texte 5 |
| `Douwesen_port` | `quest_M1_FightingInDouwesenPort` | `PJ_M1`, texte 6 |
| `Greenford_port` | `quest_M1_FightingInGreenfordPort` | `PJ_M1`, texte 7 |
| `Oxbay_port` | `quest_M1_FightingInOxbayPort` | `PJ_M1`, texte 8 |

Le handler de chaque port :

1. ajoute le texte de journal correspondant ;
2. incrémente `pchar.quest_M1_step` ;
3. appelle `M1_EndQuest()` ;
4. si l'étape est encore inférieure à `9`, met François en scène et ouvre son commentaire de victoire.

La liaison fort -> port n'est pas portée par une variable dédiée. Les conditions sont déclarées en parallèle. Il faut donc traiter cette indépendance comme une faiblesse de l'ancien design lors de la reprise : la version cible devra vérifier qu'une entrée de port ne valide pas une étape sans la capture correspondante.

## 5. Flottes navales M1

Quand le joueur entre sur une île, la condition de localisation du groupe correspondant appelle un handler `quest_M1_*Boats`.

Chaque handler suit le même schéma :

```c
Group_CreateGroup("M1_<île>");
Group_AddCharacter("M1_<île>", "Captain <île> 1");
Group_SetGroupCommander("M1_<île>", "Captain <île> 1");
Group_AddCharacter("M1_<île>", "Captain <île> 2");
Group_AddCharacter("M1_<île>", "Captain <île> 3");
Group_SetPursuitGroup("M1_<île>", PLAYER_GROUP);
Group_SetTaskAttack("M1_<île>", PLAYER_GROUP);
Group_SetAddress("M1_<île>", Characters[GetMainCharacterIndex()].location, "", "");
Group_LockTask("M1_<île>");
```

Les six groupes civils sont :

```text
M1_Redmond
M1_FalaiseDeFleur
M1_Conceicao
M1_IslaMuelle
M1_Douwesen
M1_Oxbay
```

Ils comportent chacun trois capitaines, soit dix-huit navires au total sur la campagne.

Les capitaines sont définis dans `TempQuestCharacters.c`, avec `location = "none"`, `Ship.Stopped = true` et des navires lourds adaptés à leur nation. Leur attribut `nation` historique vaut souvent `ENGLAND`, même lorsque leur navire ou leur modèle est français, espagnol, portugais ou hollandais : il ne faut pas déduire la nation de combat uniquement du nom du groupe.

### Groupe final de Quebradas Costillas

Quand `quest_M1_step` atteint `9`, `M1_EndQuest()` :

1. affiche le message global `PJ_M1_AllPorts` ;
2. restaure les relations nationales mémorisées ;
3. remet les pirates en relation ennemie ;
4. retire François de la scène et des passagers ;
5. arme la condition `quest_M1_QCBoats` sur `QuebradasCostillas`.

Le handler `quest_M1_QCBoats` crée le groupe `M1_QC` avec `Captain QC 1` à `Captain QC 9`, puis le fait poursuivre et attaquer le joueur. Il s'agit d'une dernière flotte de neuf navires pirates, déclenchée au retour sur l'île aux pirates.

## 6. Réparation automatique après une capture de fort

La réparation n'est pas un effet codé dans `M1_EndQuest()` et ne dépend pas du dialogue de François.

Le mécanisme est générique à l'interface de capture de fort :

```text
PROGRAM/INTERFACE/fortcapture.c
  CalculateData()
    -> i_RepairAllShips()
```

`CalculateData()` verse d'abord l'expérience et le butin de capture, puis appelle `i_RepairAllShips()`.

Cette fonction parcourt les quatre emplacements de compagnons du joueur. Pour chaque navire présent, elle :

```c
chref.ship.hp = GetCharacterShipHP(chref);
chref.ship.sp = GetCharacterShipSP(chref);
DeleteAttribute(chref, "ship.sails");
DeleteAttribute(chref, "ship.masts");
```

Conséquence : après une capture de fort validée par l'interface, le navire du joueur et ses navires compagnons sont ramenés à leur coque et à leurs voiles maximales. Cela explique le souvenir d'une réparation automatique après les batailles, sans ajouter une logique spéciale à M1.

La portée exacte est « après capture de fort », et non « après n'importe quelle victoire navale ». Cette distinction doit être conservée dans une reprise technique.

## 7. Progression et scènes de François

Après chaque retour au port, si `quest_M1_step < 9`, le script enchaîne une petite scène :

```c
LAi_SetActorType(characterFromID("Francois_l_Olonnais"));
LAi_SetActorType(pchar);
LAi_ActorFollow(pchar, characterFromID("Francois_l_Olonnais"), "", 2.0);
LAi_ActorFollow(characterFromID("Francois_l_Olonnais"), pchar,
    "quest_M1_<port>_continue", 2.0);
```

Le handler `quest_M1_<port>_continue` fait dialoguer François avec le joueur et positionne son noeud `FightingIn<Fort>_won`. Le dialogue affiche un commentaire différent pour chaque fort, puis revient au noeud `Waiting`.

La progression normale voulue est donc :

```text
step -1  -> quête verrouillée
step  0  -> quête ouverte, François apparaît à QC
step  2  -> contrat accepté, sept conquêtes armées
step  3  -> premier retour au port
...
step  8  -> sixième retour au port
step  9  -> septième retour, tous les forts capturés
```

## 8. Fin de la campagne de conquête

La fin de la conquête ne ferme pas immédiatement le journal.

Lorsque `M1_EndQuest()` voit `quest_M1_step == 9`, il restaure les relations civiles et prépare l'embuscade navale de Quebradas Costillas. François est retiré du groupe du joueur, puis le joueur doit revenir à la maison des pirates.

À l'entrée de `QC_pirate_house_inside`, la condition suivante fait apparaître Chui :

```c
if (makeint(pchar.quest_M1_step) == 9 &&
    pchar.location == "QC_pirate_house_inside")
{
    PlaceCharacter(characterFromID("Chui A-poo"), "goto", homelocation);
}
```

### Dialogue de Chui A-poo

Chui utilise le fichier `PJ Quest M1 Chui A-poo_dialog.c`. Lors du premier noeud de réponse, le dialogue :

1. incrémente `pchar.quest_M1_step`, de `9` à `10` ;
2. informe le joueur que François s'est rendu ;
3. appelle `quest_M1_GotoRedmondPrison` en quittant le dialogue.

Le passage à `10` sert implicitement à empêcher la réapparition de Chui et de François dans la maison des pirates.

### Réactivation des îles et prison

`quest_M1_GotoRedmondPrison` ajoute le texte de journal 16 et réactive les six îles :

```c
Island_SetReloadEnableGlobal("Redmond", true);
Island_SetReloadEnableGlobal("FalaiseDeFleur", true);
Island_SetReloadEnableGlobal("Conceicao", true);
Island_SetReloadEnableGlobal("IslaMuelle", true);
Island_SetReloadEnableGlobal("Douwesen", true);
Island_SetReloadEnableGlobal("Oxbay", true);
```

Il lance ensuite une transition avec fondu vers `quest_M1_RedmondPrison`, qui place François dans `Fake_Greenford_prison` et recharge le joueur dans cette prison.

## 9. Récompense finale et fermeture

Le dialogue de François en prison utilise les noeuds `PrisonDialog`, `Continue_23` et `Continue_24`. La sortie appelle `quest_M1_END_1`, qui enchaîne :

```text
quest_M1_END_1
  -> fondu
quest_M1_END_2
  -> reload de QC_pirate_house_inside
quest_M1_END_3
```

Dans `quest_M1_END_3`, le script donne :

- `200` exemplaires de `jewelry2` : diamants ;
- `150` exemplaires de `jewelry5` : pépites d'or.

Puis il ajoute le texte 17 au journal et ferme l'en-tête :

```c
AddQuestRecord("PJ_M1", 17);
CloseQuestHeader("PJ_M1");
```

## 10. Anomalies et points à corriger dans une reprise

### Saut forcé au moment de Douwesen

Dans le handler historique `quest_M1_FightingInDouwesenPort`, on trouve :

```c
Pchar.quest_M1_step++;
Pchar.quest_M1_step = 9; // PJ a supprimer
```

La seconde ligne force la fin de la quête après le retour à Douwesen, même si Greenford et Oxbay n'ont pas été capturés. Elle est explicitement marquée comme temporaire par l'auteur.

Pour respecter le design annoncé par les dialogues et le journal, cette affectation ne doit pas être conservée.

### Conditions indépendantes

Les sept conditions `FORT_destroy` et les sept conditions de port sont toutes créées à l'acceptation. Le vieux code ne conserve pas de flag explicite « fort X capturé puis port X validé ». La reprise devra choisir entre :

- armer le port correspondant seulement après la destruction de son fort ;
- ou ajouter un état/flag par île et vérifier ce couplage dans le handler.

### Fermeture tardive du journal

`PJ_M1` reste ouvert après la capture du dernier fort et pendant la séquence Chui -> prison -> retour à QC. C'est cohérent avec le contenu du journal, mais il ne faut pas fermer le header au moment où `step` atteint `9`.

### Noeud de dialogue de prison

Le callback `quest_M1_RedmondPrisonDialog` positionne historiquement le dialogue de François sur `FightingInOxbayFort_won`, alors que le fichier de dialogue définit aussi un noeud `PrisonDialog`. Cette référence semble être un reliquat ou une erreur de branchement. Elle doit être vérifiée avant intégration.

### Nettoyage incomplet

La fin historique retire François de la scène lors du passage à `step == 9`, mais le nettoyage final n'est pas centralisé. Chui disparaît surtout parce que `step` passe à `10` et que le spawn dépend de `step == 9`. Une reprise robuste devra traiter explicitement les PNJ, groupes et conditions M1 terminés.

### Récompense non protégée par un flag de paiement

La récompense est donnée dans `quest_M1_END_3` sans flag dédié « récompense déjà versée ». Une reprise doit éviter qu'un reload ou un appel répété du handler donne plusieurs fois les 200 diamants et 150 pépites.

## 11. Chaîne technique de référence

La chaîne historique complète peut se résumer ainsi :

```text
fin principale / end_game
  -> pchar.quest_M1_step = 0
  -> spawn François à QC_pirate_house_inside
  -> dialogue François
  -> quest_M1_agreeded
  -> step = 2, relations hostiles, conditions M1 armées
  -> entrée d'une île
  -> groupe naval M1_<île>
  -> destruction du fort
  -> FORT_DESTROYED -> FortDestroy = 1
  -> retour au port
  -> step++, journal, scène François
  -> après sept retours : step = 9
  -> restauration des relations + groupe M1_QC
  -> retour à la maison pirate
  -> spawn Chui A-poo
  -> quest_M1_GotoRedmondPrison
  -> prison de Redmond / François se rend
  -> retour à QC
  -> 200 diamants + 150 pépites d'or
  -> journal 17 et fermeture de PJ_M1
```

## 12. Orientation pour la reprise dans le dépôt actif

Le dépôt actif a déjà évolué vers une organisation par modules (`quests_reaction_s1.c`, `quests_reaction_s2.c`, `quests_reaction_s3.c`). La documentation de modularisation recommande donc, pour M1, un fichier dédié de type :

```text
PROGRAM/QUESTS/quests_reaction_m1.c
```

Le point d'entrée central resterait `QuestComplete()`, appelé depuis `quests.c`. La reprise devrait conserver les contrats moteur suivants :

- l'événement global `FORT_DESTROYED` ;
- la condition `Fort_destroy` dans `quests_check.c` ;
- les handlers `quest_M1_*` ;
- le couple dialogue `.c` / header français `.h` ;
- le journal `PJ_M1` dans `quests_texts.txt` ;
- le mécanisme générique de réparation de `fortcapture.c`.

La première version à viser devrait rétablir la chaîne de jeu et les sept captures sans réintroduire les raccourcis de développement, puis traiter séparément les relations, les transitions de prison, la récompense protégée et le nettoyage final.
