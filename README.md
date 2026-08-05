# Connect Four

A terminal-based implementation of the classic **Connect Four** game built using **C++**. The game supports both **Player vs Player** and **Player vs Computer** modes with a simple heuristic AI.

## Features

* Two game modes:

  * Player vs Player
  * Player vs Computer
* Gravity-based disc placement
* Win detection (horizontal, vertical, and diagonal)
* Draw detection
* Colored terminal interface
* AI that:

  * Plays winning moves
  * Blocks opponent's winning moves
  * Prefers center columns

## Technologies

* C++
* Standard Template Library (STL)

## Run

```bash
g++ connect_four.cpp -o connect_four
./connect_four
```
Gameplay
Connect Four
1) Two Players
2) Vs Computer
Choice:

Players choose a column (1–7), and the disc automatically falls to the lowest available position. The first player to connect four consecutive discs horizontally, vertically, or diagonally wins.

Author

Dinesh
