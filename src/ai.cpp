#include <bits/stdc++.h>
#include "ai.h"
#include "board.h"
using namespace std;

int evaluateWindow(char window[4])
{
    int aiCount = 0;
    int playerCount = 0;
    int emptyCount = 0;

    for (int i = 0; i < 4; i++)
    {
        if (window[i] == 'O')
        {
            aiCount++;
        }
        else if (window[i] == 'X')
        {
            playerCount++;
        }
        else
        {
            emptyCount++;
        }
    }

    if (aiCount == 4)
    {
        return 1000;
    }
    if (aiCount == 3 && emptyCount == 1)
    {
        return 50;
    }
    if (aiCount == 2 && emptyCount == 2)
    {
        return 10;
    }

    if (playerCount == 4)
    {
        return -1000;
    }
    if (playerCount == 3 && emptyCount == 1)
    {
        return -80;
    }
    if (playerCount == 2 && emptyCount == 2)
    {
        return -10;
    }

    return 0;
}

int evaluateBoard()
{
    int score = 0;
    char window[4];

    for (int r = 0; r < ROWS; r++)
    {
        if (grid[r][COLS / 2] == 'O')
        {
            score = score + 6;
        }
        else if (grid[r][COLS / 2] == 'X')
        {
            score = score - 6;
        }
    }

    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c <= COLS - 4; c++)
        {
            for (int i = 0; i < 4; i++)
            {
                window[i] = grid[r][c + i];
            }
            score = score + evaluateWindow(window);
        }
    }

    for (int c = 0; c < COLS; c++)
    {
        for (int r = 0; r <= ROWS - 4; r++)
        {
            for (int i = 0; i < 4; i++)
            {
                window[i] = grid[r + i][c];
            }
            score = score + evaluateWindow(window);
        }
    }

    for (int r = 0; r <= ROWS - 4; r++)
    {
        for (int c = 0; c <= COLS - 4; c++)
        {
            for (int i = 0; i < 4; i++)
            {
                window[i] = grid[r + i][c + i];
            }
            score = score + evaluateWindow(window);
        }
    }

    for (int r = 3; r < ROWS; r++)
    {
        for (int c = 0; c <= COLS - 4; c++)
        {
            for (int i = 0; i < 4; i++)
            {
                window[i] = grid[r - i][c + i];
            }
            score = score + evaluateWindow(window);
        }
    }

    return score;
}

int minimax(int depth, int alpha, int beta, bool maximizing)
{
    if (depth == 0 || isDraw())
    {
        return evaluateBoard();
    }

    if (maximizing)
    {
        int best = INT_MIN;

        for (int c = 0; c < COLS; c++)
        {
            int r = dropPiece(c, 'O');
            if (r == -1)
            {
                continue;
            }

            if (checkWin(r, c, 'O'))
            {
                undoMove(r, c);
                return 100000 + depth;
            }

            int score = minimax(depth - 1, alpha, beta, false);
            undoMove(r, c);

            if (score > best)
            {
                best = score;
            }
            if (score > alpha)
            {
                alpha = score;
            }
            if (beta <= alpha)
            {
                break;
            }
        }

        return best;
    }
    else
    {
        int best = INT_MAX;

        for (int c = 0; c < COLS; c++)
        {
            int r = dropPiece(c, 'X');
            if (r == -1)
            {
                continue;
            }

            if (checkWin(r, c, 'X'))
            {
                undoMove(r, c);
                return -100000 - depth;
            }

            int score = minimax(depth - 1, alpha, beta, true);
            undoMove(r, c);

            if (score < best)
            {
                best = score;
            }
            if (score < beta)
            {
                beta = score;
            }
            if (beta <= alpha)
            {
                break;
            }
        }

        return best;
    }
}

int getBestMove()
{
    for (int c = 0; c < COLS; c++)
    {
        if (tryMove(c, 'O'))
        {
            return c;
        }
    }

    for (int c = 0; c < COLS; c++)
    {
        if (tryMove(c, 'X'))
        {
            return c;
        }
    }

    int bestMove = -1;
    int bestScore = INT_MIN;
    int alpha = INT_MIN;
    int beta = INT_MAX;

    for (int c = 0; c < COLS; c++)
    {
        int r = dropPiece(c, 'O');
        if (r == -1)
        {
            continue;
        }

        int score = minimax(SEARCH_DEPTH, alpha, beta, false);
        undoMove(r, c);

        if (score > bestScore)
        {
            bestScore = score;
            bestMove = c;
        }
        if (bestScore > alpha)
        {
            alpha = bestScore;
        }
    }

    return bestMove;
}