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

2. Compilez les bibliothèques avec la commande `make` :
    ```bash
    make -C ./lib/AsmLibrary
    make -C ./lib/AsmGraphic
    ```

## Utilisation

Après compilation, vous obtiendrez deux bibliothèques : **AsmLibrary** (fonctions de base) et **AsmGraphic** (moteur graphique), situées dans le dossier `./lib`.

Le module **AsmGraphic** dépend de **AsmLibrary**, vous devez donc lier les deux lors de la compilation de votre projet.

Les fonctions disponibles sont déclarées dans :
- `AsmGraphic.h`
- `AsmLibrary.h`

Ces fichiers sont à inclure dans votre code en **C**.

Une version en **.asm** est également disponible pour vos projets en **NASM**, mais la version C est plus lisible et plus pratique pour débuter.

## Prérequis

- Assembleur **NASM** ou équivalent  
- Système compatible (**Linux** recommandé)  
- Outils de compilation : `make` ou `cmake`
