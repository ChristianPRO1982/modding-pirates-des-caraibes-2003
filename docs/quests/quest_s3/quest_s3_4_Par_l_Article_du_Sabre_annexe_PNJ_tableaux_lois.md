# S3 - Par l'Article du Sabre : annexe PNJ, tableaux et lois

## Objet du fichier

Ce fichier complete la specification technique de `S3 - Par l'Article du Sabre : le Verbe et la Lame decident`.

Il regroupe uniquement les donnees de conception exploitables plus tard :

- noms possibles du commanditaire ;
- noms possibles des cibles ;
- roles des PNJ informateurs ;
- tableaux de probabilites ;
- tables de repliques par type de PNJ ;
- codex pirate cite en fin de conception.

Les dialogues complets de scene ne sont pas figes ici. Ils pourront etre repris dans une annexe dediee aux dialogues.

## Conventions

- Encodage cible : Windows-1252, sans BOM.
- Fins de ligne : CRLF.
- Pas de guillemets typographiques.
- Utiliser `...` et non les points de suspension typographiques.
- Les textes peuvent contenir des accents CP1252, mais les identifiants techniques doivent rester sans accents.
- Les noms dans ce fichier sont des reserves de contenu, pas encore des identifiants techniques definitifs.

---

# 1. PNJ principaux

## PNJ de quete

| Role | Description | Notes |
|---|---|---|
| Commanditaire | Homme louche croise en sortie de ville | Toujours le meme type de PNJ, avec nom possiblement variable |
| Cible | Personne accusee par le commanditaire | Homme ou femme, innocente ou coupable |
| Habitant temoin | PNJ generique venant remercier le joueur si le commanditaire etait une crapule | Peut etre remplace par un marchand, notable ou passant |
| Malchom | PNJ de tutoriel implicite | Peut expliquer au joueur qui interroger |

## PNJ informateurs

| PNJ | Role dans l'enquete | Particularite |
|---|---|---|
| Gouverneur | Information officielle, politique, parfois interessee | Fiable mais sensible aux notables |
| Marchand | Information commerciale, dettes, vols, reputation au marche | Peut parler par interet |
| Tavernier | Rumeurs, frequentations, habitudes sociales | Repond souvent, mais pas toujours fiable |
| Pretre | Information morale et confessionnelle | Dit toujours la verite dans cette quete |
| Marchand de bateaux | Information sur le port, les cales, les departs, les affaires maritimes | Pragmatique et interesse |
| Soldat | Information de rue, rondes, troubles, infractions mineures | Direct et mefiant |
| Soldat de prison | Information sur les anciens detenus ou visages vus dans les rues | Voit souvent les cibles sous leur plus mauvais jour |

---

# 2. Noms possibles du commanditaire

Ces noms doivent sonner legerement faux, suspects ou anachroniques, sans casser totalement l'ambiance.

| ID | Nom possible |
|---|---|
| CMD_01 | Max |
| CMD_02 | Chucko |
| CMD_03 | Ricky-la-Meche |
| CMD_04 | Dany Bonnes-Affaires |
| CMD_05 | Vince-le-Coin |
| CMD_06 | Fabio des Epices |
| CMD_07 | Barry Queue-de-Rhum |
| CMD_08 | Lucho le Flexible |
| CMD_09 | Mike le Beige |
| CMD_10 | Pedro McSomething |
| CMD_11 | Donny Quetonne |
| CMD_12 | Claude-PasClaude |
| CMD_13 | Philou le Brise-Deal |
| CMD_14 | Jean-Buck |
| CMD_15 | Hank de la Criee |
| CMD_16 | Gilbert Limace |
| CMD_17 | Marvin Tropique |
| CMD_18 | Roro Croco |
| CMD_19 | Gege du Bord |
| CMD_20 | Franco-le-Fade |

---

# 3. Noms possibles des cibles

## Cibles masculines

| ID | Nom possible |
|---|---|
| CIB_H_01 | Jean-Baptiste Lemoine |
| CIB_H_02 | Diego Montoya |
| CIB_H_03 | Edward Fletcher |
| CIB_H_04 | Hendrick Van Daalen |
| CIB_H_05 | Luis Herrera |
| CIB_H_06 | Thomas Leclair |
| CIB_H_07 | Martin Deveraux |
| CIB_H_08 | Isaac Gumbs |
| CIB_H_09 | Philippe Corbin |
| CIB_H_10 | Willem Vroom |
| CIB_H_11 | Jacques Laroque |
| CIB_H_12 | Rodrigo Benitez |
| CIB_H_13 | Elias Tremblay |
| CIB_H_14 | Pierre de La Rade |
| CIB_H_15 | Bartholomew Knox |
| CIB_H_16 | Andres Ramos |
| CIB_H_17 | Joseph Boucher |
| CIB_H_18 | John Tew |
| CIB_H_19 | Auguste Vallon |
| CIB_H_20 | Esteban Morales |
| CIB_H_21 | Cornelis De Groot |
| CIB_H_22 | Mathieu Leriche |
| CIB_H_23 | Alejandro Cruz |
| CIB_H_24 | Theodore Marceau |
| CIB_H_25 | Gilbert Dumas |
| CIB_H_26 | Nathaniel Cobb |
| CIB_H_27 | Miguel Serrano |
| CIB_H_28 | Daniel Rousse |
| CIB_H_29 | Henri Papin |
| CIB_H_30 | Sebastien Clouet |
| CIB_H_31 | Charles Dutertre |
| CIB_H_32 | Olivier Fontaine |
| CIB_H_33 | Marcus Perret |
| CIB_H_34 | Antoine Laviolette |
| CIB_H_35 | Roderick Hall |
| CIB_H_36 | Etienne Pradel |
| CIB_H_37 | Lucas Alvarado |
| CIB_H_38 | Jean-Noel Malet |
| CIB_H_39 | Baptiste Robillard |
| CIB_H_40 | Claude Dupuy |
| CIB_H_41 | Adrien Montfort |
| CIB_H_42 | Rafael de Vega |

## Cibles feminines

| ID | Nom possible |
|---|---|
| CIB_F_01 | Isabela Morel |
| CIB_F_02 | Anne Delacroix |
| CIB_F_03 | Maria Gomez |
| CIB_F_04 | Catherine Duval |
| CIB_F_05 | Helene Mercier |
| CIB_F_06 | Clara Salazar |
| CIB_F_07 | Judith Van Rysen |
| CIB_F_08 | Therese Landry |

---

# 4. Tableau de probabilites des informateurs

Cette table reprend l'intention de design initiale. Elle pourra etre ajustee au moment de l'implementation.

| PNJ | Chance de repondre | Fiabilite si reponse | Chance de demander un bakchich |
|---|---:|---:|---:|
| Pretre | 60% | 100% | 0% |
| Gouverneur | 80% | 75% | 90% |
| Tavernier | 100% | 60% | 70% |
| Marchand | 80% | 75% | 90% |
| Marchand de bateaux | 60% | 50% | 50% |
| Soldat | A definir | A definir | A definir |
| Soldat de prison | A definir | A definir | A definir |

Regle de conception :

- Le pretre dit toujours la verite quand il accepte de parler.
- Les autres PNJ peuvent se tromper, mentir, proteger leurs interets ou repeter une rumeur.
- Une reponse non fiable ne doit pas etre grotesque : elle doit rester plausible.
- Les repliques ne doivent jamais rendre le bon choix evident a elles seules.

---

# 5. Tables de repliques par PNJ

## 5.1 Tavernier

Ton : familier, prudent, nourri de rumeurs de comptoir.

### Innocenter la cible

| ID | Cible homme | Cible femme |
|---|---|---|
| TAV_INN_01 | Il me semble qu'il paye toujours sa tournee... c'est pas le genre a faire du mal, non ? | Elle me parait toujours polie et discrete. Pas vraiment le profil d'une criminelle. |
| TAV_INN_02 | Je l'ai jamais vu se battre, meme quand il avait une bonne raison. | Elle donne parfois des restes aux enfants. Une mauvaise personne ferait ca ? |
| TAV_INN_03 | Pas un bavard, mais poli. Les gens comme ca, c'est rarement des tueurs. | Elle chante parfois dans la taverne, pas tres fort. Moi je trouve ca apaisant. |
| TAV_INN_04 | Il aide parfois au port. C'est pas un boulot pour un criminel, si tu veux mon avis. | Les ragots vont vite ici, mais pour elle, j'ai jamais rien entendu de serieux. |
| TAV_INN_05 | Les rumeurs ? Y'en a toujours... Mais lui, je sais pas, ca colle pas. | Je la vois souvent passer, le regard baisse, tranquille. Rien d'inquietant. |
| TAV_INN_06 | Il passe ici souvent, jamais un mot plus haut que l'autre. | Elle parle peu, mais elle paye ce qu'elle doit. C'est deja plus que beaucoup. |
| TAV_INN_07 | Disons qu'il m'a jamais inspire la peur, tu vois ? | Elle evite les disputes. Une femme comme ca cherche plutot la paix. |
| TAV_INN_08 | Un type sans histoire, a ce qu'on dit. Mais tu sais, les gens cachent bien leur jeu. | Elle a aide une servante a ramasser ses paniers. C'est peu, mais ca dit quelque chose. |
| TAV_INN_09 | Il donne parfois aux gamins des restes a manger. C'est un detail, mais bon. | Elle ne traine pas avec les mauvais marins, pas que je sache. |
| TAV_INN_10 | Je le vois souvent prier avant de boire... S'il cache quelque chose, il est bon comedien. | Je l'ai vue pleurer un soir pour un matelot mort. Une comedienne pourrait faire ca, mais quand meme. |

### Accuser la cible

| ID | Cible homme | Cible femme |
|---|---|---|
| TAV_ACC_01 | Je dis pas que c'est lui, mais y'a eu des disparitions depuis qu'il est arrive. | Je dis pas que c'est elle, mais y'a eu des histoires depuis qu'elle est la. |
| TAV_ACC_02 | Il a un regard... un peu vide, comme si tout le reste l'interessait pas. | Elle pose trop de questions, comme si elle cherchait quelque chose. |
| TAV_ACC_03 | On l'a vu roder derriere les entrepots, tard. Trop tard. | Elle a souvent des mots durs, meme quand on l'a pas cherchee. |
| TAV_ACC_04 | Moi, je dis rien... mais je le laisserais pas seul avec une bourse pleine. | Une cliente m'a dit l'avoir vue glisser quelque chose dans une bourse... discretement. |
| TAV_ACC_05 | Y'a quelque chose chez lui... je saurais pas dire. Un malaise. | Elle a ce calme bizarre, tu vois ? Comme si elle calculait tout. |
| TAV_ACC_06 | Un client m'a jure l'avoir vu discuter avec des types louches. | Elle traine parfois pres des tables ou se murmurent les mauvaises affaires. |
| TAV_ACC_07 | Il change souvent de nom, parait-il. Ca c'est pas bon signe. | Elle sourit quand les autres baissent la voix. Ca me plait pas trop. |
| TAV_ACC_08 | Il est jamais vraiment ivre, mais il reste au comptoir a ecouter. Trop. | Elle boit peu, parle moins, et repart toujours avant les disputes. Trop prudent pour etre simple. |
| TAV_ACC_09 | Son accent ? Changeant. Comme s'il voulait pas qu'on sache d'ou il vient. | Son histoire change selon celui qui l'ecoute. C'est rarement bon signe. |
| TAV_ACC_10 | J'ai deja eu des problemes avec des gars comme lui. L'air gentil, mais faut pas creuser. | J'ai deja vu des femmes comme elle retourner une salle entiere avec trois mots. |

### Ne sait pas

| ID | Cible homme | Cible femme |
|---|---|---|
| TAV_UNK_01 | Ce nom me dit rien, desole. Peut-etre un de passage ? | Ce nom me dit rien, desole. Peut-etre une passagere ? |
| TAV_UNK_02 | Je vois beaucoup de visages, je peux pas tous les retenir. | Je vois beaucoup de visages, je peux pas tous les retenir. |
| TAV_UNK_03 | S'il vient ici, c'est pas souvent. Ou alors il paye pas. | Si elle vient ici, c'est pas souvent. Ou alors elle paye trop discretement. |
| TAV_UNK_04 | On m'a peut-etre parle de lui... ou alors je confonds. | On m'a peut-etre parle d'elle... ou alors je confonds. |
| TAV_UNK_05 | Tu ferais mieux de demander au vieux pretre, lui il connait tout le monde. | Tu ferais mieux de demander au vieux pretre, lui il connait toutes les ames troublees. |

---

## 5.2 Gouverneur

Ton : officiel, prudent, politique. Le gouverneur donne une information utile, mais il peut proteger les apparences.

### Innocenter la cible

| ID | Cible homme | Cible femme |
|---|---|---|
| GOV_INN_01 | Il a toujours respecte les ordonnances de la ville, du moins a ma connaissance. | Elle s'est toujours presentee avec correction devant l'administration. |
| GOV_INN_02 | Son nom figure dans quelques registres, mais pas dans ceux des criminels. | Son nom m'est connu, sans qu'il soit associe a quelque scandale serieux. |
| GOV_INN_03 | C'est un homme reserve. La discretion n'est pas un crime. | C'est une femme reservee. La discretion n'est pas une preuve de faute. |
| GOV_INN_04 | Il a deja rendu service a la garnison lors d'un debarquement difficile. | Elle a apporte son aide lors d'une disette, et sans reclame. |
| GOV_INN_05 | Je ne l'appellerais pas un saint, mais encore moins un assassin. | Je ne l'appellerais pas une sainte, mais rien ne justifie une accusation grave. |
| GOV_INN_06 | Les plaintes contre lui sont minces et souvent interessees. | Les plaintes contre elle viennent surtout de gens contraries. |
| GOV_INN_07 | Les notables aiment salir ceux qui leur resistent. Gardez cela en tete. | Une femme qui refuse de plier devant les notables se fait vite des ennemis. |
| GOV_INN_08 | Il a paye ses taxes et respecte les convocations. Ce n'est pas le comportement d'un fugitif. | Elle s'est toujours presentee quand on l'appelait. Les coupables evitent souvent cela. |
| GOV_INN_09 | Je n'ai rien qui me permette de le faire arreter. | Je n'ai rien qui me permette de la faire arreter. |
| GOV_INN_10 | Si vous cherchez une preuve contre lui, il vous faudra mieux qu'une rumeur. | Si vous cherchez une preuve contre elle, il vous faudra mieux qu'un murmure de salon. |

### Accuser la cible

| ID | Cible homme | Cible femme |
|---|---|---|
| GOV_ACC_01 | Il frequente des hommes que je prefererais voir quitter cette colonie. | Elle frequente des gens dont les affaires ne supportent pas la lumiere. |
| GOV_ACC_02 | Son nom revient dans plusieurs affaires, jamais assez pour condamner, toujours assez pour inquieter. | Son nom revient trop souvent dans des dossiers que mes greffiers referment vite. |
| GOV_ACC_03 | Il se trouve souvent proche des ennuis, ce qui finit par ressembler a une methode. | Elle se trouve souvent proche des ennuis, et rarement par hasard. |
| GOV_ACC_04 | Il connait trop bien les rivalites du port pour un homme si discret. | Elle connait trop bien les rivalites du port pour une simple passante. |
| GOV_ACC_05 | Des temoins se sont retractes apres l'avoir nomme. Cela m'interroge. | Des temoins se sont retractes apres l'avoir nommee. Cela m'interroge. |
| GOV_ACC_06 | Il a des amis chez les marchands et les coupe-jarrets. Mauvais melange. | Elle sait parler aux nobles comme aux coupe-bourses. Mauvais talent. |
| GOV_ACC_07 | J'ai vu des hommes plus innocents que lui finir au gibet. | J'ai vu des femmes plus innocentes qu'elle finir bannies. |
| GOV_ACC_08 | Il a refuse de repondre a certaines questions. Un droit, certes, mais un signe. | Elle a refuse de repondre a certaines questions. Un droit, certes, mais un signe. |
| GOV_ACC_09 | Sa fortune a grandi plus vite que son travail ne l'explique. | Ses protections ont grandi plus vite que sa reputation ne l'explique. |
| GOV_ACC_10 | Je ne puis rien affirmer, mais je ne mettrais pas ma signature pour le defendre. | Je ne puis rien affirmer, mais je ne mettrais pas mon sceau pour la defendre. |

### Ne sait pas

| ID | Cible homme | Cible femme |
|---|---|---|
| GOV_UNK_01 | Je ne peux pas dire que je le connaisse bien. Il passe sous les radars de l'administration. | Je ne peux pas dire que je la connaisse bien. Elle ne laisse que peu de traces. |
| GOV_UNK_02 | Ce nom ne m'est pas familier, ou pas assez pour juger. | Ce nom ne m'est pas familier, ou pas assez pour juger. |
| GOV_UNK_03 | Beaucoup de gens passent par cette ile. Tous ne viennent pas jusqu'a mon bureau. | Beaucoup de gens passent par cette ile. Toutes ne viennent pas jusqu'a mon bureau. |
| GOV_UNK_04 | Je ne fonderai pas un jugement sur une impression. | Je ne fonderai pas un jugement sur une impression. |
| GOV_UNK_05 | Interrogez ceux qui vivent pres du port. Ils voient ce que mes murs ne voient pas. | Interrogez ceux qui vivent pres du port. Ils voient ce que mes murs ne voient pas. |

---

## 5.3 Marchand

Ton : commercant prudent, interesse, attentif aux dettes, vols, cargaisons et habitudes du marche.

### Innocenter la cible

| ID | Cible homme | Cible femme |
|---|---|---|
| MAR_INN_01 | Il m'a toujours paye rubis sur l'ongle. Pas un voleur, j'vous le dis. | Toujours polie, jamais un sou en retard. On dirait pas une criminelle. |
| MAR_INN_02 | Il m'a vendu du tabac, et du bon. Les bandits coupent leur marchandise. | Elle vient acheter des epices chaque semaine. Une femme de routine, pas de scandale. |
| MAR_INN_03 | Je l'ai vu donner un pain a un mendiant. Les salauds font rarement ca. | Elle a aide une vieille a porter ses sacs l'autre jour. Pas une ame mauvaise. |
| MAR_INN_04 | Il m'a averti d'un vol sur le port. Un vrai citoyen. | Elle m'a conseille sur une cargaison douteuse. Pas le genre a tremper la-dedans. |
| MAR_INN_05 | Jamais entendu une plainte sur lui. Et Dieu sait que les gens causent. | Elle vit discretement, mais tout le monde l'apprecie. |
| MAR_INN_06 | Il defend les honnetes gens, meme un peu trop. | Elle a le coeur sur la main, croyez-moi. Elle ferait pas de mal a une mouche. |
| MAR_INN_07 | Il a refuse une affaire louche, meme avec de l'or a la clef. | Elle m'a rendu une bourse qu'elle avait trouvee. Qui ferait ca sinon une bonne ame ? |
| MAR_INN_08 | Il frequente le chapelain et les notables, pas des racailles. | Toujours bien habillee, respectueuse. C'est pas une voleuse de grand chemin. |
| MAR_INN_09 | Il s'est fache quand un marin a brutalise un gamin. Un bon fond, j'vous dis. | Elle m'a prevenu qu'un client volait. Elle protege les honnetes gens. |
| MAR_INN_10 | Il commerce, il prie, il boit peu. Trop net pour etre un criminel. | Elle est un pilier du marche. Impossible qu'elle soit melee a ca, ou alors je ne comprends plus rien. |

### Accuser la cible

| ID | Cible homme | Cible femme |
|---|---|---|
| MAR_ACC_01 | Il m'a refile du rhum coupe. Depuis, je compte mes bouteilles. | J'ai retrouve une bourse vide apres son passage. Peut-etre rien, mais quand meme. |
| MAR_ACC_02 | Il m'a vendu de la camelote pour de l'or. Escroc comme il y en a peu. | Elle m'a promis du tissu de soie. C'etait du coton delave, rien de plus. |
| MAR_ACC_03 | Je l'ai vu roder autour de mes caisses de nuit. Il preparait un sale coup, peut-etre. | Elle a le sourire trop large et les mains trop lestes. Mefiez-vous. |
| MAR_ACC_04 | Il a des amis pas nets, des types a sabre court et coeur noir. | Elle traine souvent avec des marins pas tres saints. Ca sent le trafic. |
| MAR_ACC_05 | Il voulait me vendre une cargaison volee. J'ai refuse. Il n'a pas aime. | Elle a tente de me soudoyer pour fermer les yeux sur une affaire louche. |
| MAR_ACC_06 | Il m'a menace pour une dette ridicule. J'ai cru qu'il allait me planter. | Elle a menti sur son nom, deux fois. Une femme qui change d'identite, c'est louche. |
| MAR_ACC_07 | Les gardes l'ont deja attrape, j'vous jure. Il paie pour s'en sortir. | Elle a le chic pour disparaitre quand on la cherche. Comme une anguille. |
| MAR_ACC_08 | Il a la rage dans les yeux, surtout quand on parle d'argent. | Elle me regarde comme si j'etais du gibier. Ce n'est pas naturel. |
| MAR_ACC_09 | Il a vendu un bijou vole d'un noble espagnol. Je l'ai su trop tard. | Elle est venue vendre une bague gravee... que j'ai reconnue. D'un vol recent. |
| MAR_ACC_10 | On parle de lui dans les arriere-boutiques. Les rumeurs ont du vrai, souvent. | Des clients m'ont dit qu'elle avait trempe dans une affaire de contrebande. |

### Ne sait pas

| ID | Cible homme | Cible femme |
|---|---|---|
| MAR_UNK_01 | Je le connais de vue, mais je pourrais pas dire s'il est blanc comme neige ou pas. | Elle passe parfois, mais pas assez pour que je me fasse une idee. |
| MAR_UNK_02 | Je fais pas d'affaires avec lui. Trop discret, ou trop malin. | Elle dit peu de mots. Impossible a lire, cette femme-la. |
| MAR_UNK_03 | Il me paie comptant, mais parle jamais. Un mystere. | Elle entre, achete, sort. Jamais un mot de trop. Rien a dire. |
| MAR_UNK_04 | J'ai jamais eu de probleme avec lui, ni de raison de me mefier. Voila tout. | Elle ne fait pas de vagues. Peut-etre trop, allez savoir. |
| MAR_UNK_05 | Je prefere pas meler mes affaires a ce genre d'histoires, voyez ? | Les rumeurs, ca ruine un commerce. J'ecoute pas ce genre de choses. |

---

## 5.4 Pretre

Ton : sobre, moral, prudent. Dans cette quete, le pretre dit toujours la verite s'il accepte de parler.

### Innocenter la cible

| ID | Cible homme | Cible femme |
|---|---|---|
| PRE_INN_01 | Il a confesse des fautes, certes, mais rien qui merite la corde. | Elle vient souvent prier. Son coeur est droit, j'en suis temoin. |
| PRE_INN_02 | C'est un homme pieux. Il donne aux pauvres et aide a l'office. | Elle apporte du pain aux pauvres. Une ame douce, sans vice grave. |
| PRE_INN_03 | Je l'ai vu consoler une veuve. Dieu reconnait les siens. | Elle veille sur sa vieille mere. Une femme de foi. |
| PRE_INN_04 | Il n'a jamais refuse de se confesser. C'est signe d'un esprit clair. | Elle chante dans la nef tous les dimanches. Une voix droite ne prouve pas tout, mais elle ne ment pas souvent. |
| PRE_INN_05 | Il m'a aide a reparer la chapelle apres la tempete. Sans rien demander. | Elle est droite et humble. Pas une menteuse, ca non. |
| PRE_INN_06 | Il parle peu, agit bien. Ce sont la les meilleurs temoignages. | Elle se tient eloignee des querelles. C'est un bon signe. |
| PRE_INN_07 | Il s'est repenti d'anciennes fautes. Et l'homme repentant n'est pas celui qu'on decrit. | Elle ne ment pas. J'ai entendu ses prieres, et elles sont sinceres. |
| PRE_INN_08 | Il a refuse l'or d'un capitaine vereux. Cela vaut plus que mille psaumes. | Elle m'a confie ses doutes, mais pas de haine dans son ame. |
| PRE_INN_09 | Il m'a demande de prier pour un ennemi. Quelqu'un de mauvais ferait-il cela ? | Elle a soigne une enfant fievreuse alors que d'autres fuyaient. |
| PRE_INN_10 | Je sens dans son regard plus de fatigue que de malice. Il n'est pas de ceux qu'on doit frapper. | Elle vient chercher la paix ici, pas le pardon d'un grand crime. Cela veut dire beaucoup. |

### Accuser la cible

| ID | Cible homme | Cible femme |
|---|---|---|
| PRE_ACC_01 | Je l'ai vu refuser la penitence. Un homme qui fuit la verite. | Elle n'a plus mis les pieds ici depuis longtemps. L'ame qui s'eloigne cache souvent quelque chose. |
| PRE_ACC_02 | Il ment meme lorsqu'il devrait trembler. C'est rare, mais cela arrive. | Elle cache sa colere sous un voile de douceur. Je l'ai sentie. |
| PRE_ACC_03 | Il parle de Dieu mais ne Le craint pas. C'est un signe que je ne peux ignorer. | Elle manipule les mots, meme devant l'autel. C'est une mauvaise graine. |
| PRE_ACC_04 | J'ai entendu des aveux indirects, et je ne crois pas aux coincidences. | Elle a trahi une amie proche. Le mensonge est dans ses gestes. |
| PRE_ACC_05 | Il a blaspheme un soir d'ivresse, puis n'a pas voulu s'en excuser. | Elle m'a regarde droit dans les yeux, mais j'ai vu l'ombre en elle. |
| PRE_ACC_06 | Il donne a l'Eglise, mais c'est de l'argent sale. Je le sais. | Elle ne prie que quand cela l'arrange. Une foi selective est une foi morte. |
| PRE_ACC_07 | Il fuit l'aube. Il n'est jamais la quand les fideles se rassemblent. | Elle ment a son entourage. Je le sais, car ils m'en parlent en secret. |
| PRE_ACC_08 | Il garde une rancune qu'il ne veut pas abandonner. Elle le ronge. | Elle utilise la foi pour se donner bonne image. Mais son coeur est ailleurs. |
| PRE_ACC_09 | Je ne peux pas l'absoudre, pas tant qu'il garde cette haine en lui. | Elle a frappe une servante, et n'a pas demande pardon. |
| PRE_ACC_10 | Il marche dans l'ombre. J'ai peur qu'il y reste. | Elle a vendu quelque chose de sacre. Une croix... perdue, soi-disant. |

### Ne sait pas

| ID | Cible homme | Cible femme |
|---|---|---|
| PRE_UNK_01 | Je l'ai apercu a l'eglise, mais je ne le connais pas plus que cela. | Elle est venue une fois, peut-etre deux, sans dire un mot. |
| PRE_UNK_02 | Il est discret. Ni prieres ferventes, ni fautes visibles. Difficile a dire. | Elle passe parfois, assise au fond. Une ame que je n'ai pas encore percee. |
| PRE_UNK_03 | Il ecoute les sermons, mais ne parle jamais. C'est peut-etre un signe... ou rien. | Elle evite le confessionnal. Mais cela ne fait pas d'elle une criminelle. |
| PRE_UNK_04 | Je n'ai rien a redire, ni a louer. Que Dieu seul juge. | Elle ne trouble personne, mais ne brille pas non plus. Une enigme. |
| PRE_UNK_05 | Je prefere ne pas juger sans savoir. Meme les saints peuvent faillir. | Je ne connais pas son coeur, et je ne peux me fier qu'a ce que je vois. |

---

## 5.5 Marchand de bateaux

Ton : portuaire, pragmatique, interesse par les cales, les departs, les reparations et les cargaisons.

### Innocenter la cible

| ID | Cible homme | Cible femme |
|---|---|---|
| MDB_INN_01 | Je l'ai croise sur le port. Un homme travailleur. Rien a redire. | Je l'ai vue au port. Une femme de metier, pas de scandale. |
| MDB_INN_02 | C'est un marin comme les autres, rien de plus, rien de moins. | Elle vend, elle achete, elle ne cause pas de tracas. |
| MDB_INN_03 | Je l'ai vu reparer son propre bateau. Ce genre d'homme n'a pas de temps pour des betises. | Elle connait ses affaires. Pas de place pour le vice quand les comptes sont propres. |
| MDB_INN_04 | Il me demande toujours des pieces de bois pour son vaisseau. Un client fidele. | Elle a paye son du, tout comme il faut. Rien d'anormal. |
| MDB_INN_05 | Il garde son nez propre. Pas un homme que je suspecterais. | Elle passe souvent ici, elle ne fait pas de vagues. |
| MDB_INN_06 | Il ne se mele pas aux autres marins. C'est etrange, mais pas suspect. | Elle ne parle pas beaucoup, mais elle est respectee. Aucune rumeur solide sur elle. |
| MDB_INN_07 | Je l'ai vu revenir d'un voyage sans accroc. Les gens comme lui font leur travail. | Elle n'est jamais en retard pour ses livraisons. Je n'ai rien a dire contre elle. |
| MDB_INN_08 | Il n'a pas l'air d'un homme qui a quelque chose a cacher. Juste un marin ordinaire. | Elle est simple dans ses affaires. Je n'ai jamais vu de mauvaise conduite chez elle. |
| MDB_INN_09 | Il m'a achete du materiel plusieurs fois. C'est un client serieux. | Elle ne fait pas de bruit, elle paye toujours son du. Pas de quoi la suspecter. |
| MDB_INN_10 | Je n'ai rien a reprocher a cet homme. Il a l'air honnete dans ce qu'il fait. | Elle est respectee dans le marche du port. Je n'ai rien contre elle. |

### Accuser la cible

| ID | Cible homme | Cible femme |
|---|---|---|
| MDB_ACC_01 | Il a mauvaise reputation chez certains armateurs. Pas assez pour l'arreter, assez pour se mefier. | Elle a des liens avec des types peu recommandables. J'ai vu des choses. |
| MDB_ACC_02 | Je l'ai vu transporter des choses qu'il ne voulait pas montrer. C'est louche. | Elle a achete des provisions en grosse quantite. Pas normal pour sa situation. |
| MDB_ACC_03 | Il m'a parle d'affaires de contrebande en croyant que je buvais trop pour retenir. | Elle a l'air respectable, mais les secrets voyagent aussi en robe propre. |
| MDB_ACC_04 | Il fait souvent partir des barques la nuit. Je ne lui fais pas confiance. | Elle m'a demande des routes peu frequentees. Pourquoi faire ? |
| MDB_ACC_05 | Il passe pour un marin, mais je l'ai vu discuter avec des pirates une fois. | Elle cache des informations, je l'ai entendu dans des murmures. |
| MDB_ACC_06 | Ses devis sont trop bas. Trop bas, ca veut dire cargaison sale. | Elle a disparu quelques jours, puis elle est revenue changee. |
| MDB_ACC_07 | Il a un air de predateur, toujours sur le qui-vive. Je n'aime pas ca. | Elle a menti pour obtenir un prix plus bas. Mauvais signe. |
| MDB_ACC_08 | Ce n'est pas un marin comme les autres. Il ne parle jamais de ses voyages. | J'ai vu des hommes l'accompagner sur un bateau, et ils avaient l'air louches. |
| MDB_ACC_09 | Il m'a demande un prix tres bas pour des marchandises de qualite. Cela sentait mauvais. | Elle a quitte la ville une nuit, sans bagage, puis est revenue avec trop de calme. |
| MDB_ACC_10 | Il cherche a cacher des choses. Je n'aime pas sa facon de se comporter. | Elle echange des regards discrets avec des inconnus. Cela me semble suspect. |

### Ne sait pas

| ID | Cible homme | Cible femme |
|---|---|---|
| MDB_UNK_01 | Je crois l'avoir croise une fois, mais je ne le connais pas vraiment. | Je ne l'ai jamais vue ici avant. Peut-etre une cliente occasionnelle. |
| MDB_UNK_02 | Il me semble un peu trop distrait pour etre contrebandier, mais qui sait. | Je n'ai jamais eu affaire a elle. Son visage ne me dit rien. |
| MDB_UNK_03 | Il ne m'a pas donne de raison de m'inquieter, mais je ne sais pas ce qu'il cache. | Elle n'est pas du genre a frequenter ce port. Je ne peux rien vous dire. |
| MDB_UNK_04 | Je ne l'ai jamais vu avec des cargaisons douteuses, mais il garde ses distances. | Elle est peut-etre nouvelle ici. Je ne sais pas grand-chose d'elle. |
| MDB_UNK_05 | Il semble tranquille, mais je n'ai pas eu l'occasion de vraiment le connaitre. | Je ne peux pas vous dire grand-chose. Elle est juste passee par la. |

---

## 5.6 Soldat

Ton : direct, mefiant, oriente securite, rondes et troubles de rue.

### Innocenter la cible

| ID | Cible homme | Cible femme |
|---|---|---|
| SOL_INN_01 | Je l'ai vu en ville, il n'a rien d'un criminel. Juste un marin. | Une commercante comme les autres. Je ne vois rien de suspect chez elle. |
| SOL_INN_02 | Il ne se fait jamais remarquer. Ce genre de type, on n'en parle pas. | Elle n'est pas du genre a causer des ennuis. Elle reste tranquille. |
| SOL_INN_03 | Je l'ai vu se rendre au marche. Il n'avait pas l'air d'avoir des choses a cacher. | Elle fait ses affaires, mais je ne l'ai jamais vue faire quoi que ce soit d'illegal. |
| SOL_INN_04 | Il passe inapercu. Pas un type que je suspecterais. | Elle ne traine jamais en ville la nuit. Une femme prudente, je dirais. |
| SOL_INN_05 | J'ai entendu parler de lui. Rien de bien grave, un homme qui gagne sa vie. | Elle m'a demande des informations pour traverser les iles, rien d'inquietant. |
| SOL_INN_06 | Il travaille dur pour sa vie de marin. Pas de place pour des vices. | Je l'ai vue souvent ici, toujours en train de vendre ou d'acheter. Rien d'anormal. |
| SOL_INN_07 | Je ne l'ai jamais vu faire des affaires sombres. Pas un pirate, pas a mes yeux. | Elle garde la tete basse, tranquille. Rien qui justifie une accusation. |
| SOL_INN_08 | Je le connais de vue. Un homme serieux, pas de temps pour des histoires. | Je la vois de temps en temps, mais elle reste dans ses affaires. |
| SOL_INN_09 | Il a toujours l'air fatigue par son travail, pas d'un coupable en fuite. | Elle me parait serieuse. Rien qui pourrait la lier a un crime. |
| SOL_INN_10 | Je l'ai vu revenir de mer une fois. Il n'avait pas l'air de cacher un massacre. | Elle est tranquille, respectee. Je n'ai rien a redire. |

### Accuser la cible

| ID | Cible homme | Cible femme |
|---|---|---|
| SOL_ACC_01 | Il a un regard trop furtif pour etre honnete. Il cache quelque chose. | Elle a l'air trop calme pour etre une simple marchande. |
| SOL_ACC_02 | Il n'a pas l'air d'etre un marin ordinaire. Ses allees et venues sont etranges. | Elle ne parle jamais de ses affaires. Toujours dans son coin. C'est louche. |
| SOL_ACC_03 | Je l'ai vu discuter avec des types en dehors de la ville. | Elle a ete vue avec un groupe de pirates une fois. C'est suspect. |
| SOL_ACC_04 | Il m'a demande des informations sur des routes peu frequentees. Pourquoi ? | Elle a disparu quelques jours, puis est revenue avec un air bizarre. |
| SOL_ACC_05 | Il traine avec des gens de mauvaise reputation. | Elle n'est jamais seule. Il y a toujours des gens inconnus autour d'elle. |
| SOL_ACC_06 | Je l'ai vu parler a des contrebandiers. | Elle s'absente souvent en plein jour. Pourquoi disparaitre ainsi ? |
| SOL_ACC_07 | Il fuit les regards. Il doit avoir quelque chose a cacher. | Je l'ai vue entrer dans un bateau qui n'etait pas le sien. |
| SOL_ACC_08 | Il a l'air de ceux qui ont du sang sur les mains. | Elle se balade avec une bourse pleine d'or, mais personne ne sait d'ou elle vient. |
| SOL_ACC_09 | Il se cache souvent sous une cape. Pourquoi, s'il n'a rien a cacher ? | Elle m'a demande des produits rares, des choses qu'on ne trouve pas ici. |
| SOL_ACC_10 | Il a des contacts avec des malfrats. Je le vois souvent discuter dans l'ombre. | Elle traine a la taverne avec des gens pas frequentables. |

### Ne sait pas

| ID | Cible homme | Cible femme |
|---|---|---|
| SOL_UNK_01 | Je crois l'avoir vu passer, mais je ne sais pas grand-chose a son sujet. | Je n'ai jamais croise cette femme, ni entendu son nom ici. |
| SOL_UNK_02 | J'ai bien vu son visage quelque part, mais je ne suis pas sur de savoir qui il est. | Je n'ai aucune idee de qui elle est. |
| SOL_UNK_03 | Je crois que c'est un marin de passage. Il n'a rien de suspect a mes yeux. | Je ne l'ai pas vue assez souvent pour en savoir plus. |
| SOL_UNK_04 | Il passe parfois par ici, mais je ne sais pas exactement ce qu'il fait. | Elle est peut-etre une nouvelle arrivante. |
| SOL_UNK_05 | Je n'ai pas assez d'informations pour me faire une opinion. | Elle ne me dit rien. Une etrangere, je suppose. |

---

## 5.7 Soldat de prison

Ton : rude, cynique, marque par les cellules. Il parle souvent de personnes deja vues derriere les barreaux.

### Cible masculine

| ID | Type | Replique |
|---|---|---|
| SDP_H_INN_01 | Innocenter | Je l'ai vu enferme une fois, pour une bagarre dans un tripot. C'etait pas glorieux, mais pas un crime de sang non plus. |
| SDP_H_INN_02 | Innocenter | Il a purge une peine courte ici, vol mineur. Depuis, plus rien a signaler. |
| SDP_H_INN_03 | Innocenter | Il a ete dans nos geoles, oui, mais pour une histoire de dettes. Pas de quoi le traiter comme un tueur. |
| SDP_H_INN_04 | Innocenter | Ce type a fait un sejour ici, mais c'etait plus un pauvre bougre qu'un vrai criminel. |
| SDP_H_INN_05 | Innocenter | Il a eu des demeles avec la loi, certes, mais il n'a jamais leve la main sur personne. |
| SDP_H_ACC_01 | Accuser | Lui ? Il a dormi dans mes cellules plus d'une fois. Et pas pour des broutilles. |
| SDP_H_ACC_02 | Accuser | Il trainait avec une sale bande. La derniere fois, on l'a arrete pour agression. |
| SDP_H_ACC_03 | Accuser | Je n'ai jamais vu un homme mentir aussi bien a l'interrogatoire. Il cache quelque chose, c'est sur. |
| SDP_H_ACC_04 | Accuser | Ce n'est pas un inconnu pour nous. Et chaque fois qu'il sort, il y a des ennuis qui suivent. |
| SDP_H_ACC_05 | Accuser | Il a deja tente de corrompre un garde. Il n'est pas net, croyez-moi. |
| SDP_H_UNK_01 | Ne sait pas | Cet homme-la ? Jamais vu dans ma prison. Peut-etre un etranger de passage. |
| SDP_H_UNK_02 | Ne sait pas | S'il a fait des betises, ce n'etait pas ici. Son nom ne me dit rien. |

### Cible feminine

| ID | Type | Replique |
|---|---|---|
| SDP_F_ACC_PRISON_01 | Accuser - vue en prison | Elle a fait un sejour ici pour escroquerie. Une vraie vipere sous des airs doux. |
| SDP_F_ACC_PRISON_02 | Accuser - vue en prison | Je me souviens d'elle. Belle allure, mais elle a vole un marchand au port. |
| SDP_F_ACC_RUE_01 | Accuser - vue en ville | Je l'ai croisee plusieurs fois rodant autour des entrepots. Toujours la nuit. |
| SDP_F_ACC_RUE_02 | Accuser - vue en ville | Elle pose des questions a trop de gens, surtout des marins. Pas net, tout ca. |
| SDP_F_INN_RUE_01 | Innocenter - vue en ville | Je la vois souvent aider une vieille dame au marche. Pas vraiment le profil d'une criminelle. |
| SDP_F_INN_RUE_02 | Innocenter - vue en ville | Elle vit pres de la chapelle, discrete. Aucun bruit serieux a son sujet. |
| SDP_F_INN_RUE_03 | Innocenter - vue en ville | Elle vend du poisson au port, tout ce qu'il y a de plus banal. |
| SDP_F_UNK_01 | Ne sait pas | Non, jamais vue. Si elle a trempe dans quelque chose, c'est ailleurs. |
| SDP_F_UNK_02 | Ne sait pas | Son visage ne me dit rien, et je retiens toujours les visages de mes pensionnaires. |

---

# 6. Table de fausses pistes neutres

Ces phrases peuvent servir a introduire des reponses fausses mais plausibles. Ne pas utiliser pour le pretre.

| ID | Type | Genre | Replique |
|---|---|---|---|
| DUB_001 | Accusation fausse | Homme | Il traine souvent seul... Ce genre de solitude cache rarement de bonnes intentions. |
| DUB_002 | Accusation fausse | Homme | On m'a dit qu'il avait leve la voix contre un garde. Ce n'est pas normal, ca, non ? |
| DUB_003 | Accusation fausse | Femme | Elle porte toujours cette cape noire. Ca inspire peu confiance. |
| DUB_004 | Accusation fausse | Femme | J'ai vu son regard un jour... glacial. On se trompe parfois avec ce genre de choses. |
| DUB_005 | Defense fausse | Homme | Il m'a offert un verre une fois. Quelqu'un de genereux comme ca ne peut pas etre si mauvais. |
| DUB_006 | Defense fausse | Homme | Il s'occupe de son jardin chaque matin. Vous croyez qu'un tueur prend soin de ses plantes ? |
| DUB_007 | Defense fausse | Femme | Elle chantait a l'eglise le dimanche. Une voix comme ca ne peut pas cacher le vice, non ? |
| DUB_008 | Defense fausse | Femme | Toujours bien habillee, polie, un mot gentil pour chacun. Ce n'est pas le portrait d'une criminelle. |

---

# 7. Codex des Freres de l'Horizon

## Introduction

Tel que consigne sous le regard des vents et scelle par l'ecume des mers.

"Nul n'est au-dessus du Code, pas meme celui qui l'a ecrit avec son sang."

- Prologue du Codex, manuscrit de feu le Capitaine Gregoire "Crochet d'Azur"

## Article I - Le Code au-dessus de tout

Qu'un pirate jure fidelite a son pavillon, a son equipage ou a son or, nul serment ne surpasse celui prete au Code.

Tout contrevenant sera juge par la Lame ou abandonne a la merci des requins et des corbeaux de mer.

## Article II - Par l'Article du Sabre

Quand la justice des hommes echoue ou dort trop profondement, alors s'applique l'Article du Sabre.

Le Verbe accuse, la Lame tranche. Le sang parle la ou les juges se taisent.

## Article III - De la Confrerie Interdite

Aucun pirate n'a droit d'entrer ou de pactiser avec toute societe secrete, ordre occulte, ou culte sans nom.

Celui qu'on surprend a preter allegeance dans l'ombre verra sa langue clouee a la grand-voile.

## Article IV - Des Ordres a Abattre

Toute loge, secte, ou societe cachee, usant d'influence contre les lois du large, devra etre traquee sans merci.

La mer n'a point de place pour les chaines de l'esprit ou les jeux de pouvoir masques.

## Article V - Du Rhum, Nectar des Braves

Toute interdiction, taxation abusive ou dilution du rhum constitue un crime contre la piraterie.

Le rhum appartient a tous, sauf aux gouverneurs qui le boivent comme du vinaigre.

## Article VI - De l'Interdiction Sacree des Bananes Effigies

Nul pirate ne portera de banane sculptee, peinte ou portee comme symbole personnel.

Depuis l'Incident de Port-Gerard, les bananes sont tolerees uniquement en bouche, jamais en banniere. Les recidivistes seront condamnes a jongler publiquement avec trois poulpes endormis.

## Article VII - Du Partage Juste du Butin

Tout butin trouve ou pris en mer devra etre partage equitablement selon les parts jurees.

Les tricheurs auront les poches cousues et les doigts comptes a la dague.

## Article VIII - Du Droit au Duel

Lorsqu'un litige eclate entre pirates, le duel a l'epee ou au pistolet peut etre invoque.

Le duel doit etre public, loyal, et les temoins doivent etre sobres au minimum de l'oeil gauche.

## Article IX - De l'Hospitalite Obligee

Tout navire pirate doit offrir refuge a un frere ou une soeur du Code traque par les autorites, sauf si ladite personne a trahi l'Article I.

Le refus d'accueil est vu comme une tentative de collaboration terrestre.

## Article X - Des Mots Interdits en Mer

Certains mots attirent la malchance et les tempetes. Le mot "retraite" est formellement proscrit en mer.

Celui qui le prononce devra affronter une bouteille a la mer contenant... un message d'amour de sa mere.

---

# 8. Points a reprendre plus tard

- Choisir si les noms sont tires aleatoirement ou associes a des variantes fixes.
- Definir les probabilites des PNJ `Soldat` et `Soldat de prison`.
- Decider si le Codex est seulement une saveur narrative ou un vrai objet consultable.
- Verifier tous les textes dans le jeu apres encodage CP1252.
- Transformer les repliques retenues en fichiers de dialogue au format du jeu.
