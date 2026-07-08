# modding

Voici mon repo pour le modding de Pirates des Caraïbes 2003

# pour jouer sous Win11

RivaTuner

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