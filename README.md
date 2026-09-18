# Connect-Four-with-AI-Bot

A Connect Four game with an AI bot using Minimax with Alpha-Beta Pruning, built in C++ with Qt.

## How to Run

### Requirements

- C++
- CMake
- Qt 6.11
- MinGW

### Build

```bash
cmake -B build -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:/Qt/6.11.2/mingw_64"
cmake --build build
```

### Test

```
.\build\benchmark.exe
```

### Run

```
.\build\connectFour.exe
```
