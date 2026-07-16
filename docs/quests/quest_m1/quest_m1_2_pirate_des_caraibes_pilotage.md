# M1 - Le Pirate des Caraïbes : pilotage de la reprise

## Rôle du fichier

Le document technique principal reconstitue le fonctionnement historique de M1. Ce fichier fixe la manière de reprendre cette quête dans le dépôt actif, par petites étapes contrôlables.

Il ne remplace pas :

- le document technique `quest_m3_1_pirate_des_caraibes_technique.md` ;
- les fichiers de dialogue historiques dans `OLD/` ;
- le contenu du livre de quête regroupé dans `quest_m3_3_pirate_des_caraibes_questbook.md`.

## 1. Évaluation de complétude

Le document technique principal est suffisant pour :

- comprendre le scénario historique ;
- retrouver les fichiers et les identifiants M1 ;
- identifier les sept forts, les ports et les groupes navals ;
- comprendre la séquence de fin ;
- repérer les bugs historiques à ne pas recopier.

Il n'était pas suffisant, seul, pour refaire proprement la quête, car il ne fixait pas encore :

- la répartition exacte des responsabilités dans le dépôt actif ;
- les états cibles et les invariants à conserver ;
- l'ordre de réintégration ;
- les tests de non-régression ;
- la correspondance complète des textes du journal.

Les deux documents complémentaires créés avec cette reprise couvrent ces manques.

## 2. Décisions de reprise

Ces décisions reprennent l'intention historique tout en supprimant les raccourcis identifiés.

| Sujet | Décision cible |
|---|---|
| Disponibilité | Après la fin de la quête principale, au point `end_game` ou à son équivalent actif |
| Répétition | Une seule instance M1 par partie |
| Départ | François apparaît dans `QC_pirate_house_inside` |
| Objectif | Capturer les sept forts des six îles civiles |
| Ordre | Libre ; le joueur peut choisir l'île suivante |
| Validation | Une capture de fort doit être validée par le retour dans le port correspondant |
| Réparation | Utiliser la réparation générique de capture de fort de `fortcapture.c` |
| Base logistique | Quebradas Costillas reste le point de départ et de fin ; les ports civils ne deviennent pas des bases normales pendant la conquête |
| Relations | Sauvegarder les relations civiles avant de les rendre hostiles, puis les restaurer à la fin de la conquête |
| Final | Groupe naval `M1_QC`, Chui, reddition de François, récompense et fermeture du journal |
| Nouveaux assets | Aucun nouvel asset requis |

La ligne historique qui force `quest_M1_step = 9` après Douwesen est un raccourci de développement et est exclue.

## 3. Machine d'état cible

Les valeurs historiques de `quest_M1_step` peuvent être conservées comme compteur de compatibilité, mais la reprise doit aussi disposer d'un état explicite.

```text
locked
  -> available
  -> offered
  -> active
  -> conquering
  -> final_fleet
  -> waiting_for_chui
  -> francois_in_prison
  -> completed
```

Transitions principales :

| État | Déclencheur | État suivant |
|---|---|---|
| `locked` | Fin de la quête principale | `available` |
| `available` | Entrée dans `QC_pirate_house_inside` | `offered` |
| `offered` | Acceptation du dialogue de François | `active` |
| `active` | Conditions de conquête armées | `conquering` |
| `conquering` | Fort détruit puis port correspondant validé | `conquering` ou `final_fleet` |
| `final_fleet` | Retour à Quebradas Costillas et victoire de la flotte finale | `waiting_for_chui` |
| `waiting_for_chui` | Dialogue de Chui terminé | `francois_in_prison` |
| `francois_in_prison` | Dialogue final de François terminé | `completed` |

Refus ou sortie du premier dialogue ne ferme pas la quête. Le joueur doit pouvoir reparler à François tant que l'offre n'est pas acceptée.

## 4. Répartition dans le dépôt actif

Le dépôt actif assemble déjà des modules dans `PROGRAM/QUESTS/quests.c` et délègue S1, S2 et S3 depuis `QuestComplete()`.

| Responsabilité | Fichier cible recommandé |
|---|---|
| Inclusion du module M1 | `PROGRAM/QUESTS/quests.c` |
| Apparition à l'entrée de lieu | `PROGRAM/QUESTS/quests.c`, ou helper M1 appelé depuis `QuestsCheck_forLocEnter()` |
| Réactions M1 et helpers | `PROGRAM/QUESTS/quests_reaction_m1.c` |
| Routage de `QuestComplete()` | `PROGRAM/QUESTS/quests_reaction.c` |
| Condition standard `Fort_destroy` | `PROGRAM/QUESTS/quests_check.c` |
| Initialisation de l'état joueur | `PROGRAM/Characters/French/characters_init.c` |
| PNJ et capitaines temporaires | `PROGRAM/Characters/French/init/TempQuestCharacters.c` |
| Logique du dialogue de François | `PROGRAM/DIALOGS/PJ Quest M1 Francois l_Olonnais_dialog.c` |
| Texte du dialogue de François | `PROGRAM/DIALOGS/French/PJ Quest M1 Francois l_Olonnais_dialog.h` |
| Logique du dialogue de Chui | `PROGRAM/DIALOGS/PJ Quest M1 Chui A-poo_dialog.c` |
| Texte du dialogue de Chui | `PROGRAM/DIALOGS/French/PJ Quest M1 Chui A-poo_dialog.h` |
| Journal M1 | `RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt` |
| Message global éventuel | `RESOURCE/INI/TEXTS/FRENCH/globals.txt` |
| Réparation après capture | `PROGRAM/INTERFACE/fortcapture.c`, déjà générique |

`OLD/` ne doit servir que de référence. Les fichiers `quests_reaction.c.v3`, `quests_reaction.old` et les autres variantes historiques ne doivent pas être branchés dans le runtime.

### Forme de routage recommandée

La forme attendue est celle déjà utilisée par S1 et S2 :

```c
bool QuestComplete_M1(string sQuestName)
{

	switch(sQuestName)
	{
		case "quest_M1_agreeded":
			// Initialiser M1.
			return true;
		break;
	}

	return false;
}
```

Puis, dans `QuestComplete()` :

```c
if (QuestComplete_S1(sQuestName)) return;
if (QuestComplete_S2(sQuestName)) return;
if (QuestComplete_M1(sQuestName)) return;
```

Les fonctions M1 longues doivent rester dans `quests_reaction_m1.c`. Le routeur central doit rester lisible.

## 5. Flags cibles

Le compteur historique reste utile pour les dialogues et le journal :

```text
pchar.quest_M1_step
```

La reprise devrait ajouter des marqueurs explicites par île. Les noms exacts pourront suivre les conventions du module au moment du codage.

| Flag cible | Rôle |
|---|---|
| `pchar.quest_M1_status` | État global de M1 |
| `pchar.quest_M1_started` | Acceptation du contrat |
| `pchar.quest_M1_fort_<key>_captured` | Fort de l'île détruit |
| `pchar.quest_M1_port_<key>_validated` | Retour validé dans le port correspondant |
| `pchar.quest_M1_relations_saved` | Relations originales déjà sauvegardées |
| `pchar.quest_M1_final_fleet_started` | Flotte de Quebradas Costillas déjà créée |
| `pchar.quest_M1_reward_given` | Récompense finale déjà versée |
| `pchar.quest_M1_completed` | Quête définitivement terminée |

Les valeurs de `<key>` doivent rester sans accents :

```text
redmond
falaise_de_fleur
conceicao
isla_muelle
douwesen
greenford
oxbay
```

Le compteur ne doit pas être la seule source de vérité. Un rechargement ou une condition appelée deux fois ne doit ni compter deux fois un port, ni verser deux fois la récompense.

## 6. Ordre de réalisation recommandé

Le moteur étant sensible, le travail doit être effectué par petites tranches, avec un seul fichier runtime modifié à chaque étape.

### Étape 0 - Préparer le dossier documentaire

- conserver le document technique principal ;
- conserver ce fichier de pilotage ;
- valider le document du livre de quête ;
- ne modifier aucun script pendant cette étape.

### Étape 1 - Brancher le module vide

Fichiers :

- `PROGRAM/QUESTS/quests.c` ;
- `PROGRAM/QUESTS/quests_reaction_m1.c` ;
- ajout minimal dans le routeur si nécessaire.

Vérifier que le jeu charge le module sans changement visible de gameplay.

### Étape 2 - Restaurer l'état et le déclencheur

Fichiers :

- `PROGRAM/Characters/French/characters_init.c` ;
- point de fin de quête principale dans `quests_reaction.c` ou module M1.

Vérifier :

- `locked` avant la fin principale ;
- `available` après la fin principale ;
- absence de double initialisation après sauvegarde/rechargement.

### Étape 3 - Restaurer François

Fichiers :

- `TempQuestCharacters.c` ;
- dialogue `.c` ;
- header français `.h`.

Vérifier le spawn, la conversation, le refus et l'acceptation avant de brancher les combats.

### Étape 4 - Restaurer une seule île de test

Commencer avec Redmond :

- groupe naval ;
- condition de fort ;
- validation du fort ;
- retour au port ;
- texte de journal ;
- scène de François.

Ne pas brancher les six autres îles tant que cette boucle n'est pas stable.

### Étape 5 - Étendre aux six autres îles

Ajouter les îles une par une dans l'ordre suivant, choisi uniquement pour faciliter le suivi :

```text
Falaise de Fleur
Conceicao
Isla Muelle
Douwesen
Greenford
Oxbay
```

À chaque ajout, vérifier le couple fort/port et le flag de validation correspondant.

### Étape 6 - Restaurer les relations et la logistique

Brancher :

- sauvegarde des relations ;
- hostilité des cinq nations ;
- amitié temporaire avec les pirates ;
- blocage des reloads ;
- réactivation après la conquête.

Vérifier un cas d'interruption ou de chargement d'une sauvegarde pendant la conquête.

### Étape 7 - Restaurer le final

Brancher dans cet ordre :

1. `M1_EndQuest()` lorsque les sept validations sont vraies ;
2. la flotte `M1_QC` ;
3. le spawn de Chui ;
4. la transition vers la prison ;
5. le dialogue final de François ;
6. la récompense protégée par `quest_M1_reward_given` ;
7. le nettoyage et `CloseQuestHeader()`.

## 7. Tests fonctionnels minimaux

| Test | Résultat attendu |
|---|---|
| Nouvelle partie avant la fin principale | Aucun François M1 |
| Après la fin principale | François apparaît une seule fois à QC |
| Refus du contrat | François reste reparlable |
| Acceptation du contrat | Journal 1, relations et conditions initialisées |
| Capture d'un fort | Son flag de capture passe à vrai |
| Entrée dans le mauvais port | Aucun progrès pour le fort non validé |
| Retour dans le bon port | Un seul progrès et un seul texte de journal |
| Capture dans un ordre différent | La quête reste fonctionnelle |
| Sept validations | Relations restaurées et flotte M1_QC créée une seule fois |
| Retour à QC | Chui apparaît, François n'apparaît plus |
| Rechargement pendant le final | Pas de double flotte, dialogue ou récompense |
| Récompense finale | 200 diamants et 150 pépites une seule fois |
| Fin de quête | Journal fermé, PNJ et conditions nettoyés |

## 8. Points qui doivent rester explicites dans le code

- le texte `FORT_destroy` doit être harmonisé avec le nom traité par `quests_check.c` ;
- le port validé doit être celui du fort capturé ;
- la ligne de saut forcé Douwesen ne doit pas être réintroduite ;
- les conditions one-shot doivent être désactivées après résolution ;
- la réparation doit rester celle de `fortcapture.c`, sans la dupliquer dans chaque handler M1 ;
- les relations originales ne doivent être sauvegardées qu'une seule fois ;
- la récompense doit être protégée par un flag ;
- aucun appel de fin ne doit dépendre uniquement du compteur `quest_M1_step`.

## 9. Définition de fini

La reprise M1 sera considérée comme fonctionnellement complète lorsque :

- elle est disponible seulement après la fin principale ;
- les sept forts peuvent être capturés dans n'importe quel ordre ;
- chaque capture est couplée au bon retour dans son port ;
- les réparations de capture fonctionnent sans code M1 dupliqué ;
- les relations et les reloads sont restaurés ;
- la flotte finale et la séquence de prison fonctionnent ;
- le journal suit les textes 1 à 17 ;
- la récompense ne peut être donnée qu'une fois ;
- sauvegarde, rechargement et sortie de quête ne laissent pas d'état M1 incohérent.

