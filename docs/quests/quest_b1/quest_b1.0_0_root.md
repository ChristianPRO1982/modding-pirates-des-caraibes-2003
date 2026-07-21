# Shango

Le nom "Shango" et donc "B1 - Shango" est le nom technique de la quête.
Pour le joueur et la narration, les noms seront plus nébuleux pour ne pas donner d'indices prématurément.

Ce document sert de point d'entrée pour Codex afin d'expliquer les autres documents du dossier.

## Documentation générale

Ces documents servent de trame, histoire, pour le développement des quêtes.

> * Histoire = développeur = prétexte pour développer la quête
> * Narration = joueur = quête + dialogue + etc.

- `docs/quests/quest_b1/quest_b1.0_0_root.md` : point d'entrée et carte de lecture du dossier.
- `docs/quests/quest_b1/quest_b1.0_shango_history_1_abstract.md` : histoire complète servant de base à l'arc `B1 - Shango` et à ses variantes.
- `docs/quests/quest_b1/quest_b1.0_shango_history_2_gains.md` : liste exhaustive des gains par quête.
- `docs/quests/quest_b1/quest_b1.0_shango_history_3_characters.md` : liste des personnages par quête.
- `docs/quests/quest_b1/quest_b1.0_shango_history_4_questbook.md` : synthèse transverse du livre de quête pour l'arc.

## Documentation par quête

La documentation par quête permet d'avoir des éléments techniques pour le développement ainsi que la trame des quêtes et non la trame de l'histoire. Une quête peu avoir une trame déviante car elle sert à perdre un peu le joueur. La réalité du joueur n'est pas la réalité historique.

Chaque sous-quête est découpée, quand elle est documentée complètement, en quatre axes :

- `technique` : logique runtime et états cibles ;
- `pilotage` : ordre recommandé d'implémentation ;
- `questbook` : structure du journal ;
- `dialogues` : scènes et intentions de dialogue.

## B1.1 - Les Fils de l'Ombre d'Inty

- `docs/quests/quest_b1/quest_b1.1_1_Les_Fils_de_l_Ombre_d_Inty_technique.md`
- `docs/quests/quest_b1/quest_b1.1_2_Les_Fils_de_l_Ombre_d_Inty_pilotage.md`
- `docs/quests/quest_b1/quest_b1.1_3_Les_Fils_de_l_Ombre_d_Inty_questbook.md`
- `docs/quests/quest_b1/quest_b1.1_4_Les_Fils_de_l_Ombre_d_Inty_dialogues.md`

## B1.2 - La Lettre diplomatique et le lieu des rituels

Le bloc `B1.2` est maintenant documente en trois couches pour les dialogues:

- `quest_b1.2_4_..._dialogues.md` pour la synthese de `B1.2b`;
- `quest_b1.2_5_..._dialogues_b1_2a.md` pour le detail de `B1.2a`;
- `quest_b1.2_6_..._dialogues_b1_2b.md` pour le detail de `B1.2b`.

Liste des fichiers:

- `docs/quests/quest_b1/quest_b1.2_1_La_Lettre_diplomatique_et_le_lieu_des_rituels_technique.md`
- `docs/quests/quest_b1/quest_b1.2_2_La_Lettre_diplomatique_et_le_lieu_des_rituels_pilotage.md`
- `docs/quests/quest_b1/quest_b1.2_3_La_Lettre_diplomatique_et_le_lieu_des_rituels_questbook.md`
- `docs/quests/quest_b1/quest_b1.2_4_La_Lettre_diplomatique_et_le_lieu_des_rituels_dialogues.md`
- `docs/quests/quest_b1/quest_b1.2_5_La_Lettre_diplomatique_et_le_lieu_des_rituels_dialogues_b1_2a.md`
- `docs/quests/quest_b1/quest_b1.2_6_La_Lettre_diplomatique_et_le_lieu_des_rituels_dialogues_b1_2b.md`

## B1.3 - La Valse des Félons et Tourne-Casaques

- `docs/quests/quest_b1/quest_b1.3_1_La_Valse_des_Felons_et_Tourne_Casaques_technique.md`
- `docs/quests/quest_b1/quest_b1.3_2_La_Valse_des_Felons_et_Tourne_Casaques_pilotage.md`
- `docs/quests/quest_b1/quest_b1.3_3_La_Valse_des_Felons_et_Tourne_Casaques_questbook.md`
- `docs/quests/quest_b1/quest_b1.3_4_La_Valse_des_Felons_et_Tourne_Casaques_dialogues.md`

## B1.4 - Guerre dans les Caraïbes

- `docs/quests/quest_b1/quest_b1.4_1_Guerre_dans_les_Caraibes_technique.md`
- `docs/quests/quest_b1/quest_b1.4_2_Guerre_dans_les_Caraibes_pilotage.md`
- `docs/quests/quest_b1/quest_b1.4_3_Guerre_dans_les_Caraibes_questbook.md`
- `docs/quests/quest_b1/quest_b1.4_4_Guerre_dans_les_Caraibes_dialogues.md`
