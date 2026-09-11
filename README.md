Connect Four (C++)

A terminal Connect Four game I built in C++ — play against a computer opponent that actually thinks ahead using minimax with alpha-beta pruning, not just random or greedy moves.

What it does
Standard Connect Four rules, played in the terminal
Discs drop with gravity, like the real game
Checks for wins in all four directions (horizontal, vertical, both diagonals)
Catches draws when the board fills up
How the AI works

I didn't want the computer to just grab the first winning-looking move, so it runs a minimax search (depth 6, alpha-beta pruned to keep it fast) over future board states.

Before it even bothers with the search though, it checks two things directly:

Can I win right now? If yes, take it.
Is the opponent one move from winning? If yes, block it.

Only after that does it fall back to scoring positions with a heuristic — basically scanning every possible 4-in-a-row "window" on the board and scoring it based on how many of my pieces vs. the opponent's are in it, plus a small bonus for center-column control since that opens up more winning lines.

Project layout
connect4/
├── CMakeLists.txt
├── include/
│   ├── board.h
│   └── ai.h
└── src/
    ├── main.cpp
    ├── board.cpp
    └── ai.cpp


Kept it split into three pieces:

board — the grid itself, dropping pieces, undoing moves, win/draw checks
ai — the minimax logic and evaluation function
main — the actual game loop tying it together
Building
cmake -B build
cmake --build build
./build/connect4

Playing
Connect Four
Enter column (1-7):


Just type a column number 1-7 and your disc drops to the lowest open spot. First to connect four in a row wins.

Things I'd still like to add
Adjustable difficulty (right now the search depth is hardcoded at 6)
Maybe a GUI at some point instead of terminal-only
Author

Dinesh