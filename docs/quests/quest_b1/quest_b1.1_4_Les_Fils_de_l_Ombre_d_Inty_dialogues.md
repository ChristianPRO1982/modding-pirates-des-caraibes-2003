# B1.1 - Les Fils de l'Ombre d'Inty - Dialogues

## Role du fichier

Ce document rassemble les scenes de dialogue utiles a `B1.1`.

Il ne remplace pas la spec technique.
Il sert de reserve de scenes jouables pour:

- `PJ Quest B1 Robert Christopher Silehard_dialog.c/.h`;
- les contacts anglais de `B1.1`;
- les gardes iberiques de `B1.1`;
- le contact hollandais de `B1.1`.

Contraintes d'ecriture retenues:

- ne jamais reveler directement Shango;
- ne jamais confirmer qu'Inty est encore active;
- Silehard doit paraitre plausible, poli, utile, puis legerement inquietant;
- les Anglais du reseau doivent rester nerveux, prudents et un peu ridicules avec leur couverture diplomatique;
- le ton doit rester jouable dans PotC et non encyclopedique.

## 1. Silehard - premier entretien

### Fonction

- lancer `B1.1`;
- rester credible;
- presenter la collecte comme une affaire d'antiquites, pas comme un complot.

### Sous-texte

- Silehard teste le joueur;
- il cache son vrai niveau d'interet;
- il parle comme un collectionneur et non comme un fanatique.

### Trame conseillee

```text
SILEHARD
J'ai besoin d'un capitaine capable, discret, et moins sot que la moyenne.

JOUEUR
Vous attisez ma curiosite.

SILEHARD
Quelques objets incas circulent encore dans l'archipel. Je souhaite les reunir pour ma collection... et peut-etre pour une future exposition.

JOUEUR
Voila une passion bien erudite pour un gouverneur.

SILEHARD
Un homme d'Etat doit aussi savoir s'interesser a ce qui survivra a son temps.
```

### Ce que Silehard doit obtenir

- acceptation du joueur;
- lancement de la premiere collecte;
- impression de mission simple et bien payee.

## 2. Silehard - deuxieme entretien

### Fonction

- recompenser le premier groupe;
- basculer vers la statue;
- introduire les Fils de l'Ombre d'Inty.

### Sous-texte

- Silehard se detend trop vite;
- il en sait plus qu'un simple amateur;
- il invente un pretexte de couverture sans totalement y croire lui-meme.

### Trame conseillee

```text
SILEHARD
Excellent. Ces pieces etaient plus importantes que leur apparence ne le laissait croire.

JOUEUR
Vous semblez y tenir beaucoup.

SILEHARD
Disons qu'elles appartenaient autrefois a une tradition fort ancienne. Une secte inca, ou quelque chose d'approchant. Les Fils de l'Ombre d'Inty.

JOUEUR
Vous parlez de cela comme si vous les connaissiez.

SILEHARD
Seulement par des papiers, des fragments, des rumeurs de savants. Rien de plus.
```

### Consigne cle

```text
SILEHARD
Votre premier contact se trouve sur la Cote eloignee d'Isla Muelle. Et souvenez-vous d'une seule chose: ne parlez qu'aux Anglais.
```

## 3. Soldat espagnol - Isla Muelle

### Fonction

- offrir un mauvais premier choix;
- ne pas etre hostile gratuitement;
- faire comprendre ensuite que le contact anglais s'est volatilise.

### Trame conseillee

```text
SOLDAT ESPAGNOL
Vous semblez chercher quelqu'un, capitaine. Cette plage n'accueille pas souvent d'etrangers de votre genre.

JOUEUR
Je me renseignais, rien de plus.

SOLDAT ESPAGNOL
Alors renseignez-vous ailleurs. Les rencontres ici sont deja assez etranges.
```

### Effet technique

- le soldat n'apprend rien d'utile;
- l'Anglais disparait;
- le journal enregistre l'erreur.

## 4. Contact anglais - Isla Muelle

### Fonction

- jouer la couverture diplomatique absurde;
- refuser de parler devant l'Espagnol;
- donner les pieds de la statue ensuite.

### Trame conseillee sur la plage

```text
CONTACT ANGLAIS
Pas ici. Certainement pas sous les yeux de cet Espagnol.

JOUEUR
Je croyais pourtant que vous etiez entre amis.

CONTACT ANGLAIS
Naturellement. Une affaire de... relations diplomatiques. Mais certaines relations gagnent a rester tres discretes.
```

### Trame conseillee pour la remise

```text
CONTACT ANGLAIS
Voici ce que vous etes venu chercher. Les pieds seulement. Le reste a pris d'autres chemins.

JOUEUR
Tout cela pour un vieux morceau de pierre?

CONTACT ANGLAIS
On m'a appris a ne pas discuter ce que mon superieur juge precieux.
```

### Sortie de scene

- destination suivante: `Havre radieux`, `Conceicao`;
- mention d'un Portugais present;
- meme consigne implicite: parler au bon homme.

## 5. Soldat portugais - Conceicao

### Fonction

- rejouer le piege sans lourdeur;
- rappeler la discipline du reseau anglais.

### Trame conseillee

```text
SOLDAT PORTUGAIS
Vous regardez beaucoup autour de vous, capitaine. Vous attendez quelqu'un?

JOUEUR
A vrai dire, je cherchais surtout un peu de calme.

SOLDAT PORTUGAIS
Alors vous avez choisi une bien mauvaise plage.
```

### Effet technique

- meme punition temporelle qu'a Isla Muelle;
- pas de combat;
- pas de branche alternative majeure.

## 6. Contact anglais - Conceicao

### Fonction

- confirmer que la couverture est systematique;
- donner le corps de la statue;
- envoyer a Douwesen.

### Trame conseillee

```text
CONTACT ANGLAIS
Ne me dites pas un mot ici. Le Portugais croit servir un echange de courtoisie entre gens civilises.

JOUEUR
Et ce n'est pas le cas?

CONTACT ANGLAIS
Disons que la courtoisie change parfois de forme selon les besoins de la Couronne.
```

### Remise conseillee

```text
CONTACT ANGLAIS
Prenez ceci. Le corps de la statue. Les bras vous attendent a Douwesen, cette fois chez des amis plus naturels.

JOUEUR
Des amis?

CONTACT ANGLAIS
Des Hollandais. Pour une fois, vous ne risquez pas de troubler une ceremonie diplomatique imaginaire.
```

## 7. Contact hollandais - Douwesen

### Fonction

- rompre le pattern des deux premieres iles;
- montrer la complicite anglo-hollandaise;
- renvoyer calmement vers l'Anglais.

### Trame conseillee

```text
CONTACT HOLLANDAIS
Ah. Vous etes celui de Redmond. Oui, je vois tres bien.

JOUEUR
Vous ne paraissez pas surpris.

CONTACT HOLLANDAIS
Ici, nous faisons moins semblant qu'a Isla Muelle ou Conceicao. L'Anglais vous attend. Inutile de jouer au plus malin.
```

### Effet technique

- aucun echec si le joueur lui parle d'abord;
- simple redirection;
- le joueur peut ensuite parler a l'Anglais.

## 8. Contact anglais - Douwesen

### Fonction

- remettre les bras;
- envoyer vers l'exploration jungle;
- faire sentir que le reseau ne controle plus totalement le quatrieme morceau.

### Trame conseillee

```text
CONTACT ANGLAIS
Voici les bras. Pour la tete, c'est une autre histoire.

JOUEUR
Ne me dites pas qu'elle a disparu.

CONTACT ANGLAIS
Pas disparue. Cachee. Ou enterree. Un signe ancien dans la jungle devrait vous mener au bon endroit.
```

### Information cle

- la tete n'est plus dans le circuit humain du reseau;
- l'exploration jungle doit sembler ancienne et autochtone, pas "quete technique".

## 9. Indice jungle

### Fonction

- court moment d'exploration;
- rappeler l'anciennete inca;
- rester sobre.

### Texte de decouverte possible

```text
JOUEUR
Ce signe ne ressemble pas a une marque de pirate. Trop vieux... et trop soigneusement place. Si je le lis bien, il faut creuser non loin d'ici.
```

## 10. Silehard - entretien final

### Fonction

- conclure `B1.1`;
- rendre Silehard franchement suspect sans preuve;
- ouvrir `B1.2a`.

### Sous-texte

- Silehard se laisse emporter;
- il reconnait presque trop bien la statue;
- il se reprend des qu'il sent le danger.

### Trame conseillee

```text
SILEHARD
Enfin... Oui... enfin. Vous ignorez a quel point cette statue est remarquable.

JOUEUR
Vous la connaissez donc mieux que vous ne le disiez.

SILEHARD
Mieux? Non. Disons que j'en ai lu davantage que la plupart des hommes de gouvernement.

JOUEUR
Vous paraissiez pourtant presque emu.

SILEHARD
L'erudition prend parfois des formes que les marins jugent theatrales. N'y voyez rien de plus.
```

### Fermeture conseillee

```text
SILEHARD
Vous m'avez bien servi. Je saurai me souvenir de votre efficacite. Des affaires plus importantes pourraient bientot requerir un homme de votre trempe.
```

## 11. Lignes a proscrire

- toute confirmation directe que Shango existe;
- toute phrase disant qu'Inty agit encore aujourd'hui;
- toute confession trop nette de Silehard;
- toute ligne transformant le gag diplomatique en farce ouverte;
- toute explication archeologique trop longue.

## 12. Rappel de ton

- Silehard: poli, maitrise, cultive et inquietant.
- Contacts anglais: nerveux, professionnels, toujours un peu raides.
- Soldats iberiques: plausibles, pas idiots, pas caricaturaux.
- Hollandais de Douwesen: complice, sec, plus detendu que les Anglais.
- Joueur: curieux, parfois ironique, jamais deja omniscient.
