# PNJ TROP FORT
Basé sur Vanilla, cette branche est un point de départ neutre avec seulement le personnage principal modifié et 2 PNJ de triche pour tester le modding :
1. PNJ trop fort (seulement à Oxbay) : il permet de faire évoluer le personnage principal en notoriété, expérience et argent.
2. PNJ stargate : permet de se téléporté de ville en ville mais sans son bateau ! Utile pour les quête sur terre.

# modding-pirates-des-caraibes-2003
Modding du jeu pirates des Caraïbes de Bethesda de 2003. Ce modding ne modifie que les fichiers plats. Objectifs : nouvelles quêtes sur la base du jeu original, pas de nouvelles îles, items, bateaux, skin de personnages, etc.

## Où sont les modifications ?
Dans les fichiers plats .c et .h .
> Retrouve les traces en commentaire avec mon pseudo "PJ"

# codes utiles

## sync.ps1
```bash
# Synchronize modding folders into the game directory using robocopy

# Source repo root
$repoRoot = "C:\Users\...\modding-pirates-des-caraibes-2003"

# Game installation root
$gameRoot = "C:\Program Files (x86)\Bethesda Softworks\Pirates of the Caribbean"

# Sync PROGRAM
robocopy "$repoRoot\PROGRAM" "$gameRoot\PROGRAM" /E /XO /FFT /R:1 /W:1

# Sync RESOURCE\INI\TEXTS\FRENCH
robocopy "$repoRoot\RESOURCE\INI\TEXTS\FRENCH" "$gameRoot\RESOURCE\INI\TEXTS\FRENCH" /E /XO /FFT /R:1 /W:1

```