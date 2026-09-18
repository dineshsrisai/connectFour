#ifndef AI_H
#define AI_H

#define SEARCH_DEPTH 6

extern long long nodeCount;
extern long long cutoffCount;

int evaluateWindow(char window[4]);
int evaluateBoard();
int minimax(int depth, int alpha, int beta, bool maximizing, bool useAlphaBeta);
int getBestMove(bool useAlphaBeta = true);
void resetCounters();
void runBenchmark(int maxDepth);

#endif