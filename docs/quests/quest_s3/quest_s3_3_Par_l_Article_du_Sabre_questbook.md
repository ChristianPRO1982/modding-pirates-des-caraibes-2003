# S3 - Par l'Article du Sabre - Livre de quete

## Destination

Ces textes sont destines a etre ajoutes dans:

```text
RESOURCE/INI/TEXTS/FRENCH/QUESTBOOK/quests_texts.txt
```

## Note sur les variables

Les marqueurs `{TARGET_NAME}`, `{REWARD_GOLD}` et `{TOWN_NAME}` sont des placeholders de documentation.

Avant integration, verifier si le moteur peut remplacer dynamiquement ces valeurs dans le livre de quete.
Si ce n'est pas le cas, utiliser la version generique sans placeholder.

## Version avec placeholders

```text
#QUEST    PJ_S3

Par l'Article du Sabre : le Verbe et la Lame decident

#TEXT    1
Un homme peu frequentable m'a propose un contrat en dehors de la ville. Il veut que j'elimine {TARGET_NAME}. Ses explications sont troubles. Avant de lever la main, je ferais mieux d'interroger les habitants.

#TEXT    2
{TARGET_NAME} est mort. Reste a savoir si j'ai rendu justice ou si je me suis laisse acheter par un menteur. Le commanditaire m'attend pour regler le contrat.

#TEXT    3
J'ai choisi de laisser partir {TARGET_NAME}. Si mes soupcons sont justes, le vrai danger se trouve peut-etre du cote du commanditaire.

#TEXT    4
Le commanditaire m'a paye comme promis : {REWARD_GOLD} pieces d'or. L'affaire est close, mais l'or pese parfois plus lourd que le sang.

#TEXT    5
Le commanditaire a tire l'acier quand il a compris que je ne suivrais pas son jeu. Il est mort par la lame qu'il voulait acheter.

#TEXT    6
La ville de {TOWN_NAME} sait maintenant que j'ai elimine une crapule. Certains habitants me remercient a demi-mot. Dans ces iles, c'est deja beaucoup.
```

## Version generique sans placeholders

```text
#QUEST    PJ_S3

Par l'Article du Sabre : le Verbe et la Lame decident

#TEXT    1
Un homme peu frequentable m'a propose un contrat en dehors de la ville. Il veut que j'elimine une personne de l'ile. Ses explications sont troubles. Avant de lever la main, je ferais mieux d'interroger les habitants.

#TEXT    2
La cible est morte. Reste a savoir si j'ai rendu justice ou si je me suis laisse acheter par un menteur. Le commanditaire m'attend pour regler le contrat.

#TEXT    3
J'ai choisi de laisser partir la cible. Si mes soupcons sont justes, le vrai danger se trouve peut-etre du cote du commanditaire.

#TEXT    4
Le commanditaire m'a paye comme promis. L'affaire est close, mais l'or pese parfois plus lourd que le sang.

#TEXT    5
Le commanditaire a tire l'acier quand il a compris que je ne suivrais pas son jeu. Il est mort par la lame qu'il voulait acheter.

#TEXT    6
La ville sait maintenant que j'ai elimine une crapule. Certains habitants me remercient a demi-mot. Dans ces iles, c'est deja beaucoup.
```

## Correspondance des etapes

| TEXT | Etat de quete | Usage |
|---|---|---|
| 1 | Contrat accepte | La cible est designee et l'enquete commence. |
| 2 | Cible tuee | Le joueur doit retourner voir le commanditaire. |
| 3 | Cible liberee | Le joueur doit confronter le commanditaire. |
| 4 | Commanditaire paie | Fin apres assassinat de la cible. |
| 5 | Commanditaire tue | Fin apres liberation de la cible puis duel. |
| 6 | Ville reconnaissante | Message de cloture si le commanditaire etait une crapule. |

## Points de vigilance

- Le format final attendu par le jeu doit rester simple.
- Ne pas garder les triples backticks lors de l'insertion dans `quests_texts.txt`.
- Verifier les tabulations ou espaces attendus autour de `#QUEST` et `#TEXT` selon les fichiers existants.
- Conserver l'encodage CP1252 sans BOM et les fins de ligne CRLF.
- Remplacer ou supprimer les placeholders si le moteur ne les gere pas.
