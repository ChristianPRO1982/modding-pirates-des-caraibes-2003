# S3 - Par l'Article du Sabre : le Verbe et la Lame decident

## Role du fichier
Ce fichier regroupe les dialogues de la quete `S3`.

Il ne decrit pas la logique technique de la quete et ne remplace pas la specification technique principale. Il sert de reserve de scenes dialoguables pour les futures integrations dans les fichiers du jeu.

Contraintes d'ecriture retenues :

- encodage cible : Windows-1252 / CP1252 ;
- pas de guillemets typographiques ;
- utiliser "..." et non une ellipse typographique ;
- les dialogues commencent toujours par le PNJ ;
- `JOUEUR` indique les choix possibles du joueur ;
- `{TARGET_NAME}` designe le nom de la cible ;
- `{REWARD_GOLD}` designe la recompense calculee par le jeu.

## 1. Commanditaire - premiere rencontre

### Premiere rencontre - variante 1

```
COMMANDITAIRE
"Toi... Tu sembles avoir les mains plus habiles que la moyenne. J'aurais peut-etre un travail a te proposer... Si tu n'as pas peur de salir tes bottes."
JOUEUR
"Je t'ecoute."
"Je ne suis pas interesse par tes magouilles."
```

### Premiere rencontre - variante 2

```
COMMANDITAIRE
"T'as pas l'air d'un marin... ni d'un honnete homme. Ca tombe bien. Ce que j'ai a offrir n'est pas pour les ames sensibles."
JOUEUR
"Parle. Mais sois bref."
"Trouve-toi une autre poire."
```

## 2. Commanditaire - retour apres refus ou interruption

### Deja rencontre - variante 1

```
COMMANDITAIRE
"Ah, voila le heros... ou l'assassin rate. T'as change d'avis, ou tu viens finir le travail ?"
JOUEUR
"Dis-moi ce que tu as pour moi."
"Je n'ai rien a faire avec toi."
```

### Deja rencontre - variante 2

```
COMMANDITAIRE
"Alors ? Pret a ecouter cette fois, ou juste curieux de te salir un peu plus les mains ?"
JOUEUR
"Parle. Mais je garde un oeil sur toi."
"Tu perds ton temps."
```

## 3. Commanditaire - propositions de mission

Chaque proposition peut mener vers trois choix : accepter, demander plus d'informations, ou refuser.

### Proposition 1

```
COMMANDITAIRE
"Un homme du nom de {TARGET_NAME} a seme trop d'embrouilles ici. Il est temps de retablir un certain... equilibre."
JOUEUR
"Considere que c'est fait."
"Quel genre d'embrouilles, exactement ?"
"Je ne suis pas ton larbin."
```

### Proposition 2

```
COMMANDITAIRE
"Certains ici ont la langue trop bien pendue. {TARGET_NAME}, par exemple. On gagnerait a ne plus l'entendre."
JOUEUR
"Je m'en occupe."
"Parle-moi un peu plus de cette personne."
"Je ne tue pas pour des commerages."
```

### Proposition 3

```
COMMANDITAIRE
"Le monde se porterait mieux sans {TARGET_NAME}. Cette personne a trahi les mauvaises gens. Tu vois ou je veux en venir ?"
JOUEUR
"Je vois tres bien."
"Trahi comment, exactement ?"
"Je passe mon tour."
```

### Proposition 4

```
COMMANDITAIRE
"{TARGET_NAME}. Trop de monde lui fait confiance. Et ca, c'est dangereux pour les affaires."
JOUEUR
"Je m'en charge."
"Tu veux dire que cette personne gene tes combines ?"
"Je ne m'attaque pas a un innocent sur parole."
```

### Proposition 5

```
COMMANDITAIRE
"Ce chien de {TARGET_NAME} m'a vole ce qui me revenait. Le genre de dette qui se regle dans le sang."
JOUEUR
"Je vais lui faire payer."
"C'est quoi exactement cette dette ?"
"Je ne suis pas ton collecteur."
```

### Proposition 6

```
COMMANDITAIRE
"J'ai des raisons de croire que {TARGET_NAME} a vendu des informations a ceux d'en face. Tu comprends pourquoi ca pose probleme ?"
JOUEUR
"Je comprends. La cible disparait."
"Quels genres d'informations ?"
"Je n'execute pas sans preuves."
```

### Proposition 7

```
COMMANDITAIRE
"{TARGET_NAME}... Trop de cadavres suivent cette personne. Il est temps d'ajouter le sien a la pile."
JOUEUR
"Avec plaisir."
"Tu l'as vu faire, ou tu te bases sur des rumeurs ?"
"Je refuse."
```

### Proposition 8

```
COMMANDITAIRE
"{TARGET_NAME} a un charme empoisonne. Des familles entieres ont ete detruites. C'est son tour maintenant."
JOUEUR
"Je vais retrouver cette personne."
"Tu parles d'un coeur brise ou d'un vrai crime ?"
"Je n'abats personne pour ton plaisir."
```

### Proposition 9

```
COMMANDITAIRE
"{TARGET_NAME} s'est mis sous la protection du gouverneur. Mais ca n'efface pas les peches passes."
JOUEUR
"Je m'en occupe discretement."
"Qu'est-ce que cette personne t'a fait, au juste ?"
"Trop risque pour moi."
```

### Proposition 10

```
COMMANDITAIRE
"On dit que {TARGET_NAME} trempe dans des affaires louches. Je n'ai pas de preuve, mais mon instinct me dit de faire disparaitre cette personne."
JOUEUR
"Je lui reglerai son compte."
"Ton instinct vaut-il une vie ?"
"Je ne marche pas la-dedans."
```

## 4. Commanditaire - propositions supplementaires pour cible masculine

Ces variantes sont prevues pour compenser le desequilibre naturel du jeu en PNJ masculins.

### Proposition homme 1

```
COMMANDITAIRE
"J'ai entendu dire que {TARGET_NAME} mene des affaires avec les mauvaises personnes. Le genre d'affaires qu'on ne laisse pas prosperer."
JOUEUR
"Je vais m'en occuper."
"Quels genres d'affaires, exactement ?"
"Je ne tue pas pour des rumeurs."
```

### Proposition homme 2

```
COMMANDITAIRE
"{TARGET_NAME} est un caid en ville. Il fait des choses dont meme l'enfer se detourne. Il est temps de l'envoyer la-bas."
JOUEUR
"C'est fait, il ne verra pas le jour se lever."
"C'est ce qu'on dit, mais ou sont les preuves ?"
"Trop risque pour moi."
```

### Proposition homme 3

```
COMMANDITAIRE
"L'ivrogne {TARGET_NAME} est un fardeau pour la ville. Il va trop loin. Une bonne purge s'impose."
JOUEUR
"Je vais lui rendre service."
"Il a faute comment ?"
"Je ne touche pas aux ivrognes."
```

### Proposition homme 4

```
COMMANDITAIRE
"Les rues sont pleines de types comme {TARGET_NAME}, des hommes qui croient que tout leur est du. Il faut le mettre hors d'etat de nuire."
JOUEUR
"Je vais m'en occuper."
"C'est quoi son plus grand crime ?"
"Je prefere laisser ca aux autorites."
```

### Proposition homme 5

```
COMMANDITAIRE
"{TARGET_NAME} joue double jeu. Il est a la fois homme de loi et traitre. Il va falloir regler son compte a ce genre de type."
JOUEUR
"Je vais lui faire une belle fin."
"Il a trahi qui, exactement ?"
"Ce n'est pas mon genre."
```

## 5. Commanditaire - demande de precisions

Ces repliques sont universelles. Elles doivent laisser planer le doute, sans rendre le commanditaire trop caricatural.

### Precision 1

```
COMMANDITAIRE
"Ah, tu veux savoir pourquoi. Bien. Mais tu sais, parfois on a peu de choses a offrir, excepte un bon prix et une promesse de succes. La verite, c'est qu'il y a eu des evenements... disons... suspects. Le genre d'affaire que les nobles ne veulent pas voir etaler dans la lumiere."
JOUEUR
"Je vais m'en occuper. Mais je ferai ca a ma maniere."
"Ca sent trop mauvais. Trouve un autre chien de chasse."
```

### Precision 2

```
COMMANDITAIRE
"On parle d'une disparition sous des circonstances peu claires, ou peut-etre d'un accident... Mais en tout cas, la fortune a disparu avec le mort. Et puis, il y a eu des bruits sur les docks, la ou certains groupes de puissance s'agitent dans l'ombre."
JOUEUR
"Assez parle. Je prends le contrat."
"Des bruits, des ombres, pas de preuves. Je refuse."
```

### Precision 3

```
COMMANDITAIRE
"Je ne veux pas te faire perdre ton temps. Ce n'est pas juste un simple vol... C'est plus complique. Des gens influents veulent que cette personne disparaisse. Si ce n'est pas elle, c'est probablement un complice. Les nobles et les marchands qui se battent pour les docks s'en melent. Une guerre silencieuse."
JOUEUR
"Les guerres silencieuses paient bien. J'accepte."
"Je n'aime pas les guerres ou personne ne montre son pavillon. Je passe."
```

### Precision 4

```
COMMANDITAIRE
"Tu sais, j'ai entendu que la cible avait cause pas mal de degats aux nobles recemment. Un vol, ou peut-etre un assassinat... Personne ne veut vraiment en parler. Les rumeurs sont floues. Mais je t'assure, des gens influents veulent sa tete."
JOUEUR
"Je n'ai pas besoin de plus. Je m'en charge."
"Alors que ces gens influents sortent leur propre lame. Moi, je refuse."
```

### Precision 5

```
COMMANDITAIRE
"Parfois, c'est plus simple que ca en a l'air. Un riche marchand est tombe d'un balcon il y a quelques jours... accidentellement, bien sur. Mais plusieurs personnes croient qu'il a ete pousse. Et il avait de mauvaises relations avec des groupes plus sombres que de simples marins."
JOUEUR
"Je vais voir si la mer veut un cadavre de plus."
"Je ne tue pas sur une chute et trois chuchotements. Non."
```

### Precision 6

```
COMMANDITAIRE
"Il y a des gens qui ne veulent pas que certaines affaires ressortent dans la lumiere, et qui preferent que certains secrets restent enfouis. La cible a une histoire, mais qui n'en a pas dans ces iles ? Vols, assassinats, trahisons... C'est le quotidien ici."
JOUEUR
"Tres bien. Je prends le risque."
"Trop vague. Et trop commode. Je refuse."
```

### Precision 7

```
COMMANDITAIRE
"Je ne peux pas en dire trop, mais... imagine qu'un gros contrat ait ete rate. Une alliance entre nobles et pirates a mal tourne. C'est la que la cible entre en scene. Elle a peut-etre trahi des gens influents, ou seulement vu ce qu'il ne fallait pas voir."
JOUEUR
"Un temoin genant ou un traitre, je verrai bien. J'accepte."
"Non. Je ne suis pas la lame d'une histoire que tu refuses de raconter."
```

## 6. Commanditaire - acceptation ou refus apres precisions

### Reponses joueur - acceptation

```
JOUEUR
"Je vais m'en occuper. Les mauvaises herbes ne prosperent pas dans ce coin."
"Tant que la paye suit, je prends le contrat. Mais je veux toutes les informations necessaires."
"Tu sembles sur de ton affaire. Tres bien, je vais le faire."
"Qu'importe le pourquoi, je m'attaque a ce boulot. Mais je ferai mon travail a ma maniere."
"Ce genre de mission est mon quotidien. L'argent fait le reste."
```

### Reponses joueur - refus

```
JOUEUR
"Ce n'est pas mon genre de jouer dans ces eaux troubles. Trouve quelqu'un d'autre."
"C'est trop risque pour moi, surtout avec des gens aussi puissants dans l'affaire. Bonne chance."
"Je ne m'en mele pas. Trop de mysteres pour un simple contrat."
"Je prefere ne pas me salir les mains avec ce genre de travail. Reviens me voir quand tu auras une mission plus simple."
"Ca sent mauvais tout ca. Ce n'est pas pour moi."
```

## 7. Commanditaire - confirmation finale du contrat

Le commanditaire redonne le nom de la cible et annonce la somme calculee par le jeu.

### Confirmation 1

```
COMMANDITAIRE
"La cible s'appelle {TARGET_NAME}. Pour cela, tu recevras {REWARD_GOLD} pieces d'or a la fin de ta mission."
JOUEUR
"{REWARD_GOLD} pieces d'or ? C'est suffisant pour me convaincre. J'accepte."
"Ca ne m'interesse pas. Je prefere ne pas m'impliquer."
```

### Confirmation 2

```
COMMANDITAIRE
"La personne que tu dois eliminer, c'est {TARGET_NAME}. Pour le travail, tu obtiendras {REWARD_GOLD} pieces d'or."
JOUEUR
"Tres bien. Je vais m'en charger."
"Trop de complications pour moi, je prefere passer mon tour."
```

### Confirmation 3

```
COMMANDITAIRE
"Tu devras eliminer {TARGET_NAME}. La recompense sera de {REWARD_GOLD} pieces d'or."
JOUEUR
"{TARGET_NAME}... J'accepte. {REWARD_GOLD} pieces d'or valent bien le risque."
"Je ne fais pas dans ce genre de travail. Retrouve un autre tueur."
```

### Confirmation 4

```
COMMANDITAIRE
"Ta cible s'appelle {TARGET_NAME}. L'argent a la clef ? {REWARD_GOLD} pieces d'or."
JOUEUR
"{REWARD_GOLD} pieces, ca me va. Je vais la trouver."
"Non merci. Je prefere ne pas me meler de ca."
```

### Confirmation 5

```
COMMANDITAIRE
"C'est une personne du nom de {TARGET_NAME}. La somme ? {REWARD_GOLD} pieces d'or a la fin."
JOUEUR
"{REWARD_GOLD} pieces d'or ? L'offre me plait. Je m'en occupe."
"Trop risque, trop d'inconnues. Je passe mon chemin."
```

### Confirmation 6

```
COMMANDITAIRE
"Ta mission : tuer {TARGET_NAME}. En echange, tu recevras {REWARD_GOLD} pieces d'or."
JOUEUR
"{REWARD_GOLD} pieces d'or sont plus que suffisantes. Je vais m'en charger."
"Non, ce n'est pas pour moi. Je refuse cette mission."
```

### Confirmation 7

```
COMMANDITAIRE
"La cible est nommee {TARGET_NAME}. Pour cela, tu auras {REWARD_GOLD} pieces d'or."
JOUEUR
"{REWARD_GOLD} pieces d'or ? C'est acceptable. Je vais le faire."
"Je ne me sens pas pret pour cette mission. Trouve quelqu'un d'autre."
```

### Confirmation 8

```
COMMANDITAIRE
"Il s'agit de {TARGET_NAME}. Le paiement est de {REWARD_GOLD} pieces d'or."
JOUEUR
"{REWARD_GOLD} pieces d'or ? C'est plus qu'acceptable. Je vais m'en occuper."
"Je n'accepte pas ce contrat. Il y a trop de zones d'ombre."
```

### Confirmation 9

```
COMMANDITAIRE
"Il te faut eliminer {TARGET_NAME}. La recompense ? {REWARD_GOLD} pieces d'or."
JOUEUR
"{REWARD_GOLD} pieces d'or, c'est tentant. Je prends le contrat."
"Non, ca ne me va pas. Je prefere chercher une autre mission."
```

### Confirmation 10

```
COMMANDITAIRE
"C'est un denomme {TARGET_NAME}. A la fin du travail, tu auras {REWARD_GOLD} pieces d'or."
JOUEUR
"{REWARD_GOLD} pieces d'or, c'est largement suffisant. Je vais m'en charger."
"Trop de risques pour moi. Je refuse cette mission."
```

## 8. Cible masculine - premier echange

Chaque scene propose trois reponses joueur : poursuivre l'enquete, mettre en garde, ou liberer la cible.

### Cible masculine 1

```
CIBLE_HOMME
"T'as l'air du genre a croire tout ce qu'on raconte dans les tavernes... Je te conseille de passer ton chemin."
JOUEUR
"Je crois ce que je vois. Et je vais creuser un peu plus."
"Si tu me caches quelque chose, tu ferais mieux de parler maintenant."
"T'as peut-etre raison. On t'a sali pour rien. Tu peux partir."
```

### Cible masculine 2

```
CIBLE_HOMME
"Encore un qui vient m'accuser sans savoir. Tu veux mon avis ? T'es qu'un pion."
JOUEUR
"Je me fais mon propre avis. Je reviendrai s'il faut."
"Mefie-toi. Tu pourrais vite devenir plus qu'un suspect."
"Tu n'as rien d'un criminel. Oublie que je suis passe."
```

### Cible masculine 3

```
CIBLE_HOMME
"Les gens parlent trop. Si j'etais vraiment dangereux, tu serais deja mort."
JOUEUR
"Interessant. Mais je veux voir ce que les autres en pensent."
"Fais attention a ce genre de menace. Je garde l'oeil ouvert."
"Tu veux juste vivre tranquille... Je comprends. Tu es libre."
```

### Cible masculine 4

```
CIBLE_HOMME
"Tu me suis comme un chien errant. T'as pas mieux a faire ?"
JOUEUR
"Je dois m'assurer que tu es net."
"Continue comme ca, et c'est toi qu'on trouvera au fond du port."
"T'as rien a te reprocher, j'en suis sur. Va."
```

### Cible masculine 5

```
CIBLE_HOMME
"On m'accuse pour tout et n'importe quoi dans cette ville. J'ai arrete de me defendre."
JOUEUR
"Je veux entendre toutes les versions avant de juger."
"Ton silence pourrait te couter cher."
"T'es fatigue de te battre. Je te crois. File."
```

### Cible masculine 6

```
CIBLE_HOMME
"J'ai toujours fait mon boulot. Si ca derange certains, c'est pas mon probleme."
JOUEUR
"Je vais verifier si c'est vrai."
"Ton boulot pourrait bien etre ce qui te mene a la corde."
"Je vois un homme droit. Je ne suis pas ton ennemi."
```

### Cible masculine 7

```
CIBLE_HOMME
"Tu veux la verite ? Je suis pas un saint, mais je suis pas l'homme qu'on te decrit."
JOUEUR
"Justement. J'ai besoin d'en savoir plus."
"On verra si tu continues a dire ca quand on t'aura coince."
"Tu n'as rien fait de ce qu'on m'a raconte. Je te laisse."
```

### Cible masculine 8

```
CIBLE_HOMME
"T'as ete paye pour me tuer, hein ? Ben va falloir t'acheter un autre contrat."
JOUEUR
"Pas encore decide. Je veux savoir si tu merites ca."
"Continue a jouer au dur... ca finit souvent mal."
"Tu ne seras pas ma cible aujourd'hui. Bonne chance."
```

### Cible masculine 9

```
CIBLE_HOMME
"La derniere fois qu'on m'a accuse, j'ai fini en cellule. J'en suis sorti sans preuve."
JOUEUR
"Je verifierai tes dires. Patiente."
"Tu veux pas y retourner, si ?"
"Pas de preuve, pas de crime. Tu peux partir."
```

### Cible masculine 10

```
CIBLE_HOMME
"Je suis peut-etre louche, mais y a plus pourri que moi sur cette ile. Crois-moi."
JOUEUR
"Justement, je veux savoir si tu fais partie des pires."
"Si tu mens, c'est pas a moi que ca portera malheur."
"T'as pas l'air pire qu'un autre. Va-t'en."
```

## 9. Cible feminine - premier echange

### Cible feminine 1

```
CIBLE_FEMME
"Les gens aiment inventer des histoires, surtout quand une femme prend sa place."
JOUEUR
"Je veux connaitre ton histoire, pas celle des autres."
"Raconte-la vite, ou d'autres la raconteront pour toi."
"T'as rien a cacher, je le vois. Tu es libre."
```

### Cible feminine 2

```
CIBLE_FEMME
"Tu crois que j'ai le temps pour tes questions ? T'as rien d'autre a faire ?"
JOUEUR
"J'ai besoin de comprendre. Juste quelques reponses."
"Ton arrogance pourrait bien te trahir."
"T'es juste mefiante. Je respecte ca. Va."
```

### Cible feminine 3

```
CIBLE_FEMME
"Un autre venu pour me juger ? J'en ai vu d'autres, mon gars."
JOUEUR
"Je ne juge pas. J'enquete."
"Ce n'est pas une menace, mais ca pourrait le devenir."
"Pas besoin de te defendre, t'es hors de cause."
```

### Cible feminine 4

```
CIBLE_FEMME
"J'ai croise des types comme toi. L'or leur embrouille la tete."
JOUEUR
"Je ne suis pas la pour l'or. Juste pour la verite."
"Meprise-moi encore, et tu verras ou ca mene."
"T'as pas tort. Ce contrat pue. Je te laisse."
```

### Cible feminine 5

```
CIBLE_FEMME
"Les notables m'en veulent, mais j'ai rien fait. Sauf leur dire leurs quatre verites."
JOUEUR
"Je vais creuser, voir si c'est qu'un reglement de comptes."
"Rien fait ? On verra ce qu'en disent les autres."
"Ce n'est pas un crime d'avoir une grande gueule. T'es libre."
```

## 10. Cible - confirmation du combat

### Combat - cible masculine

```
CIBLE_HOMME
"Je te laisserai pas me faire sauter la tete comme un vulgaire pirate. Viens te frotter a moi, si t'oses."
JOUEUR
"Je ne suis pas venu pour discuter tricot. Garde ton souffle pour prier."
"Minute... Je ne suis pas encore certain de ce que je sais. Je reviendrai."
```

### Combat - cible feminine

```
CIBLE_FEMME
"Tu crois pouvoir me tomber dessus comme une mouche sur un fruit ? Je vais t'arracher les yeux."
JOUEUR
"Essaie, et tu verras qu'un fruit peut mordre."
"Du calme. Je me suis peut-etre emballe. Je vais reflechir encore."
```

## 11. Cible - confirmation de liberation

### Liberation - cible masculine

```
CIBLE_HOMME
"Enfin quelqu'un avec un peu de jugeote... J'ai cru que j'y passerais, honnetement."
JOUEUR
"Les innocents n'ont rien a craindre... avec moi."
"Ne t'emballe pas. Je ne te laisse pas filer, pas encore. Pas avant d'etre sur."
```

### Liberation - cible feminine

```
CIBLE_FEMME
"C'est rare qu'un homme ecoute au lieu de tirer. Merci de ne pas m'avoir envoyee au fond de la mer."
JOUEUR
"Ce monde manque de justice... aujourd'hui, j'ai tente d'y remedier."
"Je ne t'ai pas encore blanchie. Je dois revoir deux ou trois choses."
```

## 12. Commanditaire - retour si la cible a ete assassinee

Le joueur n'a qu'une seule reponse. Le dialogue clot le paiement par le commanditaire.

### Paiement 1

```
COMMANDITAIRE
"Bien. Un nom de moins a inscrire sur la liste... Voici ta recompense, matelot."
JOUEUR
"Marche conclu. Je ne vais pas trainer dans le coin."
```

### Paiement 2

```
COMMANDITAIRE
"Je savais que t'etais pas du genre a poser trop de questions. Tiens, prends ton du."
JOUEUR
"Marche conclu. Je ne vais pas trainer dans le coin."
```

### Paiement 3

```
COMMANDITAIRE
"Le silence d'un homme vaut parfois bien plus que son cri. Voila de quoi te satisfaire."
JOUEUR
"Marche conclu. Je ne vais pas trainer dans le coin."
```

### Paiement 4

```
COMMANDITAIRE
"Un probleme en moins... et une bourse plus lourde pour toi."
JOUEUR
"Marche conclu. Je ne vais pas trainer dans le coin."
```

### Paiement 5

```
COMMANDITAIRE
"T'as pas tremble, c'est tout ce qui compte. Prends ton or."
JOUEUR
"Marche conclu. Je ne vais pas trainer dans le coin."
```

### Paiement 6

```
COMMANDITAIRE
"L'ocean se chargera de laver ses peches... Toi, tu gagnes ce que tu merites."
JOUEUR
"Marche conclu. Je ne vais pas trainer dans le coin."
```

### Paiement 7

```
COMMANDITAIRE
"C'est bien. Discret, rapide, efficace. Comme j'aime."
JOUEUR
"Marche conclu. Je ne vais pas trainer dans le coin."
```

### Paiement 8

```
COMMANDITAIRE
"T'as fait ce qu'il fallait. Certains doivent tomber, c'est la loi du port."
JOUEUR
"Marche conclu. Je ne vais pas trainer dans le coin."
```

### Paiement 9

```
COMMANDITAIRE
"Une epine en moins dans le pied des puissants. Voila ton paiement."
JOUEUR
"Marche conclu. Je ne vais pas trainer dans le coin."
```

### Paiement 10

```
COMMANDITAIRE
"On dit que l'or ne ment pas... Le voila. A ta prochaine mission, peut-etre."
JOUEUR
"Marche conclu. Je ne vais pas trainer dans le coin."
```

## 13. Commanditaire - retour si la cible a ete liberee

Le commanditaire declenche le duel. Le joueur repond par une joute verbale, puis le combat commence.

### Duel commanditaire 1

```
COMMANDITAIRE
"Tu te fous de moi ?! Ce rat respire encore ?!"
JOUEUR
"Un homme comme toi paie des tueurs parce qu'il ne peut pas se salir lui-meme. Dommage pour toi, je ne suis pas a vendre."
```

### Duel commanditaire 2

```
COMMANDITAIRE
"T'as laisse filer la cible ?! Qu'est-ce que t'as dans le crane ?!"
JOUEUR
"Assez de cervelle pour reconnaitre un mensonge quand il pue plus fort que la cale d'un negrier."
```

### Duel commanditaire 3

```
COMMANDITAIRE
"T'as desobei a l'ordre. Ca va te couter plus que de l'or."
JOUEUR
"Ton ordre ne vaut rien. Voyons maintenant si ta lame vaut davantage."
```

### Duel commanditaire 4

```
COMMANDITAIRE
"Alors c'est ca... t'as cru bon de jouer les justiciers, hein ?"
JOUEUR
"Non. Aujourd'hui je joue seulement l'homme qui t'empeche de tuer par procuration."
```

### Duel commanditaire 5

```
COMMANDITAIRE
"T'as trahi le contrat, et moi, je ne tolere pas la trahison."
JOUEUR
"Un contrat signe avec la peur n'engage que les laches. Tire ton fer."
```

### Duel commanditaire 6

```
COMMANDITAIRE
"Tu penses pouvoir me defier ? Ici, dans MON port ?"
JOUEUR
"Ton port ? Je ne vois qu'un coin de boue ou un menteur va perdre ses dents."
```

### Duel commanditaire 7

```
COMMANDITAIRE
"On ne donne pas la main a un traitre, on la tranche."
JOUEUR
"Approche donc. Je vais t'apprendre la difference entre une main tendue et une lame levee."
```

### Duel commanditaire 8

```
COMMANDITAIRE
"T'avais un choix simple. Et t'as choisi la mort."
JOUEUR
"La mort etait deja dans ton contrat. Je ne fais que changer le nom au bas de la page."
```

### Duel commanditaire 9

```
COMMANDITAIRE
"C'est pas lui qui va crever aujourd'hui, c'est toi."
JOUEUR
"Tu parles beaucoup pour quelqu'un qui voulait rester dans l'ombre. Viens finir ta phrase."
```

### Duel commanditaire 10

```
COMMANDITAIRE
"Ton honneur ne va pas te sauver de ma lame."
JOUEUR
"Peut-etre. Mais mon honneur survivra plus longtemps que toi."
```

## 14. Notes d'integration futures

Points a traiter lors de l'integration technique :

- remplacer `{TARGET_NAME}` par le nom choisi au lancement de la quete ;
- remplacer `{REWARD_GOLD}` par la somme calculee par le script ;
- separer les variantes par contexte de dialogue selon les fichiers `DIALOGS` existants ;
- garder les choix d'annulation sur la cible pour permettre au joueur de continuer l'enquete ;
- ne pas ajouter ici les repliques des PNJ informateurs si elles sont deja gerees dans l'annexe de tableaux ;
- verifier chaque apostrophe et chaque caractere avant integration dans les fichiers du jeu.
