#ifndef AI_H
#define AI_H

#define SEARCH_DEPTH 6

int evaluateWindow(char window[4]);
int evaluateBoard();
int minimax(int depth, int alpha, int beta, bool maximizing);
int getBestMove();

#endif