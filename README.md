# AsmGraphic

**AsmGraphic** est un projet visant à fournir des outils graphiques simples en assembleur, en utilisant **Xorg** ou **XWayland version 24**.

## Fonctionnalités

- Affichage de formes basiques (lignes, cercles, rectangles) personnalisables
- Gestion multi-fenêtre
- Gestion des événements
- Timer intégré

## Installation

1. Clonez le dépôt :
    ```bash
    git clone https://github.com/DimitriLaPoudre/AsmGraphic.git
    cd AsmGraphic
    ```

2. Compilez le projet avec la commande `make` :
    ```bash
    make -C ./lib
    ```

## Utilisation

Après compilation, vous obtenez une bibliothèque **AsmGlobal** dans le dossier `./lib`,  
qui contient les fonctions d’**AsmGraphic** (dépendant de **AsmLibrary**, une bibliothèque similaire à la LibC standard).

La bibliothèque **AsmGlobal** vous fournit une liste de fonctions disponibles dans les fichiers :
- `AsmGraphic.h`
- `AsmLibrary.h`

Ces fichiers sont à inclure dans votre code en **C** pour utiliser les fonctions.  
Une version en **.asm** est également disponible pour vos projets en **NASM**, mais la version C est plus lisible.

## Prérequis

- Assembleur **NASM** ou équivalent
- Système compatible (**Linux** recommandé)
- Outils de compilation : `make` ou `cmake`
