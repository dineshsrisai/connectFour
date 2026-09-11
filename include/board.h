#ifndef BOARD_H
#define BOARD_H

#define ROWS 6
#define COLS 7

extern char grid[ROWS][COLS];

void initBoard();
void printBoard();
int dropPiece(int col, char p);
void undoMove(int r, int c);
bool isDraw();
bool checkWin(int r, int c, char p);
bool tryMove(int col, char p);

#endif