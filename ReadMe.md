# MPIA - Artificial Intelligence in Games: Lab Project 1

## Lien du Google drive

[cliquez ici](https://drive.google.com/drive/folders/1qLOS4fmYUd-EfaoaE3n3brSwwo5OTjpA?usp=sharing)

ou

https://drive.google.com/drive/folders/1qLOS4fmYUd-EfaoaE3n3brSwwo5OTjpA?usp=sharing

## Description

Ce projet est une implémentation d'une bibliothèque de "Steering Behaviors" sur Unreal Engine 5. Il permet de visualiser les comportements de déplacement programmés pour une intelligence artificielle (IA) représentée par un cône. L'objectif est de simuler différents comportements inspirés des travaux de Craig Reynolds.

## Auteure

- **Hana DELCOURT**

## Fonctionnalités

Le projet se présente sous la forme d'une vue top-down avec une caméra fixe filmant le sol. L'IA est représentée par un cône qui cherche à se déplacer vers une cible représentée par un cube blanc. Par défaut, la cible est positionnée en (0,0).

### Contrôles

- **Clic gauche** : Fait apparaître une nouvelle cible (cube blanc) et fait disparaître la précédente.
- **Clic droit** : Change l'état de la cible actuelle et des futures cibles.
- **Espace** : Change l'état du cône (l'IA).

### Affichage

Deux textes sont affichés à l'écran :

- **"Pawn state"** : Indique l'état du cône.
- **"Target state"** : Indique l'état de la cible.

## Comportements implémentés

### États du cône (IA)

- **SEEK** : Se déplace vers la cible et tourne autour en boucle.
- **FLEE** : Fuit à l'opposé de la cible.
- **PURSUIT** : Anticipe la trajectoire de la cible en utilisant sa vitesse et se dirige vers un point devant elle.
- **ARRIVAL** : Se déplace vers la cible et s'arrête progressivement lorsqu'il est proche et à faible vitesse.
- **FOLLOW_PATH** : Suit un chemin défini lors de l'activation de cet état. Le spawn de nouvelles cibles n'affecte pas la trajectoire.
- **ONE_WAY** : Suit un chemin jusqu'à un point final et s'arrête.
- **TWO_WAYS** : Suit un chemin jusqu'à un point final, puis fait demi-tour pour revenir à son point de départ, et ainsi de suite.

### États de la cible

- **Idle** : La cible reste immobile.
- **Go on** : La cible se déplace de gauche à droite avec de légères variations.
- **Evade** : La cible tente d'échapper au cône (poursuivant).

## Exécution

### Instructions (2 possibilités)

1. **Récupérer le projet**
   - Téléchargez le projet depuis le [lien](https://drive.google.com/drive/folders/1qLOS4fmYUd-EfaoaE3n3brSwwo5OTjpA?usp=sharing) fourni (Google Drive).
   - Extrayez les fichiers dans un dossier local.
   - Assurez-vous que le projet contient les fichiers sources et le build.

2. **Lancer le projet**
   - Pour exécuter directement le build, ouvrez le dossier `Build/` et lancez l'exécutable `Build/ProjectMPIA1.exe`.
   - Pour ouvrir le projet sur Unreal Engine 5, assurez-vous d'installer Unreal Engine 5 puis ouvrez le fichier `ProjectMPIA1/ProjectMPIA1.uproject`.
   - Cliquez sur **Play** dans l'éditeur d'Unreal Engine.

## Historique Git

Le projet inclut un dossier .git, permettant d'accéder à l'historique des modifications.