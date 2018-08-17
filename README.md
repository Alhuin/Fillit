# Fillit - Le 101 (école 42)

## Objectifs
Fillit est un projet algorithmique qui a pour but d'agencer un ensemble donné de Tetriminos pour les faire tenir dans le plus petit carré possible sans rotation.

#### Exemple
Voici un exemple de Tetriminos valides (au maximum 26 pièces) 

```
....
.##.
.##.
....

...#
...#
...#
...#

....
..##
.##.
....

....
..#.
.##.
.#..

.###
...#
....
....

##..
.#..
.#..
....

....
..##
.##.
....

.#..
.##.
..#.
....

....
###.
.#..
....
```

#### Solution
```
AAB.CCD
AABCCDD
FFB..D.
.FBEEE.
HF.GGE.
HHGGIII
.H...I.
```
## Installation:
```
git clone https://github.com/Alhuin/Fillit.git ~/Fillit
cd ~/Fillit
make
```
## Exécution
```
./Fillit [tetriminos_file]
```
## Licence
Ce projet a été produit sous licence MIT - voir le fichier LICENSE.md pour plus d'informations.
