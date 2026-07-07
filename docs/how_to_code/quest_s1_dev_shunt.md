# Quest S1 dev shunt

Fichier: `PROGRAM/QUESTS/quests_reaction_s1.c`

But:
- accelerer les tests de la fin Youyi
- garder un shunt simple directement dans le module S1

Booleen:
- `S1_DEV_COMPLETE_ALL_QUESTS_ON_WIN`

Comportement:
- valeur par defaut: `false`
- si `true`, quand une quete S1 normale est gagnee puis fermee, le module marque toutes les quetes S1 comme gagnees
- le flag `pchar.quest_S1_allQuestsCompleted` passe a `true`
- Youyi peut alors apparaitre a `QC_town` pour lancer la derniere quete

Notes:
- ce shunt ne doit pas s'activer sur un echec de quete
- la finale Youyi reste gouvernee par `pchar.quest_S1_final_enabled`
- pour revenir au comportement normal, remettre `S1_DEV_COMPLETE_ALL_QUESTS_ON_WIN = false;`
