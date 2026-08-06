# Connect Four

A terminal-based implementation of the classic **Connect Four** game built using **C++** featuring both **Player vs Player** and **Player vs Computer** modes. The computer opponent uses the **Minimax algorithm** with a heuristic evaluation function to make strategic decisions.

## Features

- Two game modes:
  - Player vs Player
  - Player vs Computer

- Gravity-based disc placement

- Win detection in all directions:
  - Horizontal
  - Vertical
  - Diagonal

- Draw detection

- Colored terminal interface using ANSI escape codes

### AI Features

- **Minimax search** for move selection
- **Heuristic board evaluation** based on all possible 4-cell windows
- Detects and plays **immediate winning moves**
- Detects and blocks the opponent's **immediate winning moves**
- Prefers **center-column control** for stronger board positions
- Scores board states by evaluating:
  - Four-in-a-row
  - Three-in-a-row with an open space
  - Two-in-a-row with open spaces
  - Opponent threats

## AI Strategy

The computer chooses its move using the following priority:

1. Play an immediate winning move.
2. Block the opponent's immediate winning move.
3. Evaluate future board positions using the **Minimax algorithm**.
4. Score each board using a heuristic evaluation function and select the highest-scoring move.

## Technologies

- C++
- Standard Template Library (STL)

## Project Structure

```text
connect_four.cpp
```

### Main Components

- **Board Management**
  - Disc placement
  - Undo moves
  - Draw detection

- **Game Logic**
  - Win detection
  - Player turns
  - Input validation

- **Artificial Intelligence**
  - Minimax search
  - Heuristic evaluation
  - Immediate win/block detection
  - Center-column preference

## Build & Run

```bash
g++ connect_four.cpp -o connect_four
./connect_four
```

## Gameplay

```text
Connect Four

1. Two Players
2. Vs Computer
Choice:
```

Players choose a column (1–7). The disc automatically falls to the lowest available position due to gravity. The first player to connect four consecutive discs horizontally, vertically, or diagonally wins the game.

## Future Improvements

- Alpha-Beta Pruning

## Author

**Dinesh**
