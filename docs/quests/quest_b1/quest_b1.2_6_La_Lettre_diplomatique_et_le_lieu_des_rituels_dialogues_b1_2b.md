# B1.2b - La Lettre derobee - Dialogues detailles

## Role du fichier

Ce document est une annexe de conception dediee a `B1.2b`.

Il complete `docs/quests/quest_b1/quest_b1.2_4_La_Lettre_diplomatique_et_le_lieu_des_rituels_dialogues.md`, qui doit etre lu comme la synthese de `B1.2b`.

Le but ici n'est pas d'ecrire un script final exhaustif, mais de verrouiller scene par scene:

- les objectifs narratifs;
- le ton;
- le sous-texte;
- le deroule;
- des propositions de repliques reutilisables plus tard.

## 1. Ouverture immediate apres B1.2a

### Objectifs

- fermer `B1.2a` et ouvrir `B1.2b` dans le meme mouvement;
- faire sentir que l'echec diplomatique laisse place a une enquete active;
- eviter tout temps mort entre les deux sous-quetes.

### Ton

- tendu;
- direct;
- sans ceremonie.

### Sous-texte

- la colere de Silehard ferme l'etape diplomatique;
- l'enquete devient aussitot prioritaire.

### Deroule

1. Le dernier dialogue de `B1.2a` fait comprendre que la lettre et le cadeau sont perdus.
2. Silehard ordonne immediatement de retrouver la piste des voleurs.
3. `PJ_B1_2A` se ferme et `PJ_B1_2B` s'ouvre sur le meme trigger.

## 2. Silehard - Relance d'enquete

### Objectifs

- donner a `B1.2b` son premier cap clair;
- envoyer le joueur sur une piste de pays, pas encore de lieu exact;
- maintenir l'ambiguite politique de Silehard.

### Ton

- plus froid que furieux;
- sec;
- autoritaire;
- controle.

### Sous-texte

- Silehard sait deja qu'il cherche des adversaires plus structures qu'une simple bande de voleurs;
- il ne donne pas encore `Isla Muelle`;
- il veut que le joueur se comporte comme un chasseur de traces.

### Deroule

1. Silehard ordonne une enquete discrete et rapide.
2. Il explique que la premiere cle est l'origine nationale des faux soldats.
3. Il invite le joueur a flairer les iles comme un limier.

### Propositions de repliques

**Silehard:**
"Les objets sont perdus, soit. Leur piste, elle, ne l'est pas encore."

**Silehard:**
"Je ne te demande pas de courir au hasard. Je te demande de flairer ces iles comme un limier."

**Joueur:**
"Vous voulez le pays avant les hommes."

**Silehard:**
"Exactement. Retrouve d'abord d'ou ils viennent. Le reste suivra."

**Reponses du joueur possibles:**
- "Je vais leur trouver un accent, puis un port."
- "Je suivrai la piste. Mais si vous me cachez encore quelque chose, cela me coutera du temps."

## 3. Malcolm

### Objectifs

- fournir une aide de secours explicite;
- orienter clairement le joueur vers les habitants des villes;
- respecter le role de PNJ de triche.

### Ton

- rapide;
- pirate;
- concret;
- sans mystere.

### Sous-texte

- Malcolm ne cherche pas a preserver le flou narratif;
- il dit directement ce qu'il faut faire.

### Propositions de repliques

**Malcolm:**
"Capt'aine, des expressions comme celles entendus, ca se trouve dans les rues des villes. Va parler aux habitants de chaque ville de ces maudites iles et reprenons la mer au plus vite."

**Reponses du joueur possibles:**
- "Pour une fois, tu vas droit au but."
- "Alors cap sur les rues, pas sur les forts."

## 4. Habitants de Douwesen

### Objectifs

- faire de `Douwesen` le coeur de l'enquete linguistique;
- confirmer l'origine hollandaise des faux soldats;
- renvoyer vers le Francais mal habille comme seul vrai indice exploitable.

### Ton

- quotidien;
- local;
- parfois moqueur;
- jamais savant.

### Sous-texte

- les habitants ne comprennent pas l'affaire politique;
- ils reconnaissent simplement une tournure, un accent ou une expression.

### Mecanique retenue

Chaque temoin utilise aleatoirement une des trois expressions suivantes:

- "participer pour du lard et des haricots"
- "porter de l'eau a la mer"
- "Le singe est sorti de la manche"

Le flux de dialogue type doit etre:

1. le PNJ emploie l'une de ces expressions;
2. le joueur peut repondre a cote ou demander ce qu'elle veut dire;
3. le PNJ explique rapidement;
4. le joueur peut partir ou poser la vraie question sur les soldats anglais parlant trop bien hollandais;
5. le PNJ confirme avoir vu de tels soldats;
6. le PNJ ajoute qu'un Francais mal habille les observait et posait des questions.

### Propositions de repliques

**Habitant:**
"Bah, tout ca, c'est participer pour du lard et des haricots."

**Reponses du joueur possibles:**
- "Tu parles toujours comme ca aux inconnus ?"
- "Qu'est-ce que cela veut dire, exactement ?"

**Habitant:**
"Que certains se fatiguent pour pas grand-chose. C'est une facon de parler, rien de plus."

**Joueur:**
"Justement. J'ai croise des soldats anglais qui parlaient d'une facon etrange. Tu en aurais vu de ce genre ?"

**Habitant:**
"Des soldats anglais qui parlaient trop bien hollandais ? Oui. Ils etaient presses, nerveux, et pas du coin."

**Habitant:**
"Un Francais mal habille trainait pres d'eux. Lui aussi posait des questions. Etrange, non ?"

### Contraintes

- aucun habitant ne doit connaitre `Isla Muelle`;
- aucun habitant ne doit parler de grotte ou de rite;
- tous convergent seulement vers la piste du Francais.

## 5. Retour a Falaise de Fleur - Gouverneur francais

### Objectifs

- confirmer que le pouvoir francais est deja informe;
- deleguer proprement la suite a l'espion;
- garder la France observatrice, pas encore actrice.

### Ton

- digne;
- bref;
- maitrise;
- diplomatique.

### Sous-texte

- le gouverneur francais en sait assez pour ne pas etre surpris;
- il prefere que son espion parle.

### Propositions de repliques

**Gouverneur francais:**
"Oui, je suis au courant de cette affaire. Et non, ce n'est pas moi qui vais vous en dire davantage."

**Joueur:**
"Vous avez donc deja fait travailler vos gens."

**Gouverneur francais:**
"Parlez a mon espion. Il est dans cette piece. Il a vu plus que moi, et sans doute trop."

## 6. Espion francais

### Objectifs

- faire du Francais la vraie cle de transition entre `Douwesen` et `Isla Muelle`;
- jouer sur la reconnaissance du personnage sans ses haillons;
- donner une piste maritime incomplete mais solide.

### Ton

- sec;
- ironique;
- plus raffine que lors de la premiere rencontre;
- prudent.

### Sous-texte

- le joueur ne le reconnait pas tout de suite;
- l'espion sait des choses, mais moins que Silehard sur la destination finale;
- il connait le danger de la secte.

### Deroule

1. Le joueur se presente correctement.
2. Il remarque qu'il ne reconnait pas tout de suite l'homme sans ses haillons.
3. L'espion s'amuse brievement de cela.
4. Il explique que les Hollandais ont pris la mer vers une ile separee a `Isla Muelle`.
5. Il ajoute qu'un rite de la secte de Shango doit s'y tenir.
6. Il ne donne ni nom de plage ni nom de grotte.

### Propositions de repliques

**Joueur:**
"Nous nous sommes deja croises, et pourtant je vous reconnais a peine."

**Espion francais:**
"Les haillons servent parfois mieux la France qu'un uniforme bien brosse."

**Espion francais:**
"Je n'ai pas pu les suivre jusqu'au bout. Ils ont pris la mer vers une ile separee, du cote de `Isla Muelle`."

**Joueur:**
"Et vous ignorez ou ils ont debarque."

**Espion francais:**
"J'ignore la plage. J'ignore leur dernier abri. Mais j'ai entendu parler d'un rite, et d'une secte dangereuse. Shango."

**Reponses du joueur possibles:**
- "C'est peu, mais c'est deja assez pour relancer la piste."
- "Alors il faut que quelqu'un d'autre sache ou ils comptent frapper."

## 7. Retour a Silehard

### Objectifs

- faire de Silehard la source de la localisation finale;
- lancer concretement le voyage vers `Isla Muelle`;
- montrer qu'il sait plus de choses qu'il n'en avoue.

### Ton

- maitrise;
- precis;
- autoritaire;
- moins colerique qu'en ouverture.

### Sous-texte

- Silehard possede un niveau d'information superieur a celui de l'espion francais;
- il ne revele pas comment il sait.

### Propositions de repliques

**Silehard:**
"`Isla Muelle` ne me surprend pas."

**Joueur:**
"Le Francais n'a pu me donner ni plage, ni cache."

**Silehard:**
"Alors je vous donne ce qui manque. Ils debarqueront ou ils ont debarque a la `Cote eloignee`."

**Silehard:**
"Le rite se tient dans une grotte. Vous n'y allez pas pour parlementer, mais pour interrompre."

**Reponses du joueur possibles:**
- "Cette fois, j'ai une destination."
- "Vous en savez beaucoup pour un homme qui pretend attendre mes rapports."

## 8. Phase navale

### Objectifs

- verrouiller l'acces a la baie;
- donner un vrai prealable militaire;
- annoncer que le rite est protege.

### Ton

- martial;
- sobre;
- efficace.

### Parametres retenus

- defense minimale: `1 fregate` et `1 corvette`;
- aucune entree terrestre avant destruction complete;
- la baie mene a `Cote eloignee`.

## 9. Grotte du rite

### Objectifs

- changer le registre de l'enquete vers le rituel;
- reveler les faux soldats sous leur nouvelle apparence;
- installer le `chef des pretres`.

### Ton

- occulte;
- malsain;
- theatral sans tomber dans la caricature.

### Sous-texte

- les faux soldats etaient deja engages dans quelque chose de plus profond qu'un simple vol;
- ils ont change de role, pas d'obeissance.

### Deroule

1. Le joueur entre dans la grotte.
2. Le rite est interrompu.
3. Les faux soldats sont maintenant vetus comme des pretres de Shango.
4. Le `chef des pretres` prend la parole.

## 10. Explications des pretres

### Objectifs

- donner une parole finale aux voleurs;
- lier le vol et le rite sans localiser les objets;
- distinguer ces hommes comme dissidents.

### Ton

- fanatique;
- hostile;
- sur de soi;
- condamne.

### Sous-texte

- ils ne parleront pas assez pour sauver la piste diplomatique;
- ils admettent le basculement rituel;
- ils restent des dissidents, pas la totalite du reseau.

### Propositions de repliques

**Chef des pretres:**
"Tu arrives tard, capitaine. Les soldats que tu as vus sont morts depuis longtemps. Il ne reste ici que des serviteurs de Shango."

**Joueur:**
"Serviteurs ou voleurs, cela revient au meme tant que vous gardez ce qui ne vous appartient pas."

**Chef des pretres:**
"Nous avons pris ce qu'il fallait prendre. Le reste ne te regarde plus."

**Chef des pretres:**
"Le rite nous eleve. Les objets ne te seront pas rendus, pas plus que leur destination."

**Reponses du joueur possibles:**
- "Alors tu mourras sans autre aveu."
- "Vous avez vole pour trahir les votres autant que nous."

## 11. Combat final

### Objectifs

- rendre la conclusion irreversible;
- supprimer toute possibilite d'interroger un survivant;
- clore la piste locale sur un vide.

### Regles retenues

- combat obligatoire a l'epee;
- tous les pretres meurent;
- aucun ne revele l'emplacement des objets.

## 12. Retour chez Silehard

### Objectifs

- montrer une colere plus froide que dans `B1.2a`;
- faire le compte des morts;
- expliquer que seuls les dissidents sont tombes;
- montrer que Silehard estime avoir deja repris la main politiquement;
- lancer l'attente avant la guerre.

### Ton

- controle;
- satisfait en partie;
- opaque;
- presque rassurant a la fin.

### Sous-texte

- Silehard obtient au moins l'elimination des dissidents;
- la perte des objets n'est plus centrale selon lui;
- il manigance deja la suite sans tout dire.

### Deroule

1. Le joueur rapporte la destruction des pretres.
2. Silehard compte les morts et y voit exactement les dissidents attendus.
3. Il affirme s'etre renseigne de son cote.
4. Il juge que la perte des objets diplomatiques ne devrait plus etre un probleme majeur.
5. Il demande de patienter quelques semaines.
6. En runtime, un timer de `14 jours` prepare `B1.3`.

### Propositions de repliques

**Silehard:**
"Combien etaient-ils ?"

**Joueur:**
"Assez pour remplir cette grotte de cadavres. Pas assez pour sauver leur secret."

**Silehard:**
"Alors le compte est bon. Ce nombre correspond a celui des dissidents que je cherchais a faire tomber."

**Silehard:**
"Je me suis renseigne de mon cote. La perte des objets diplomatiques ne devrait plus etre un probleme."

**Joueur:**
"Vous parlez comme si la guerre etait deja en marche."

**Silehard:**
"Disons plutot que j'ai encore quelques braises a souffler contre cet accord nauseabond."

**Silehard:**
"Malgre cet echec, vous avez bien servi. Soyez patient quelques semaines. Cela ne devrait plus tarder."

**Reponses du joueur possibles:**
- "J'attendrai. Mais je prefere toujours les mers aux salons."
- "Je saurai patienter, si la suite vaut vraiment ce detour."

## Sortie de quete

La fin de `B1.2b` doit laisser l'impression suivante:

- le joueur a elimine les dissidents sans retrouver les objets;
- Silehard n'est plus desarme politiquement;
- la guerre se prepare deja en coulisse;
- le joueur recupere quelques semaines de liberte apparente avant `B1.3`.
