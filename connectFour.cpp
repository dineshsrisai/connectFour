#include <bits/stdc++.h>
using namespace std;

const int R = 6, C = 7;
const char EMPTY = '.', P1 = 'X', P2 = 'O';
char b[R][C];

void undo(int r, int c)
{
    b[r][c] = EMPTY;
}

bool draw()
{
    for (int i = 0; i < C; i++)
    {
        if (b[0][i] == EMPTY)
        {
            return false;
        }
    }
    return true;
}

int drop(int col, char p)
{
    if (col < 0 || col >= C || b[0][col] != EMPTY)
    {
        return -1;
    }
    for (int i = R - 1; i >= 0; i--)
    {
        if (b[i][col] == EMPTY)
        {
            b[i][col] = p;
            return i;
        }
    }
    return -1;
}

bool win(int r, int c, char p)
{
    int count;
    count = 1;

    for (int i = c - 1; i >= 0 && b[r][i] == p; i--)
    {
        count++;
    }
    for (int i = c + 1; i < C && b[r][i] == p; i++)
    {
        count++;
    }
    if (count >= 4)
    {
        return true;
    }

    count = 1;
    for (int i = r - 1; i >= 0 && b[i][c] == p; i--)
    {
        count++;
    }
    for (int i = r + 1; i < R && b[i][c] == p; i++)
    {
        count++;
    }
    if (count >= 4)
    {
        return true;
    }

    count = 1;
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0 && b[i][j] == p; i--, j--)
    {
        count++;
    }
    for (int i = r + 1, j = c + 1; i < R && j < C && b[i][j] == p; i++, j++)
    {
        count++;
    }
    if (count >= 4)
    {
        return true;
    }

    count = 1;
    for (int i = r + 1, j = c - 1; i < R && j >= 0 && b[i][j] == p; i++, j--)
    {
        count++;
    }
    for (int i = r - 1, j = c + 1; i >= 0 && j < C && b[i][j] == p; i--, j++)
    {
        count++;
    }
    if (count >= 4)
    {
        return true;
    }
    return false;
}

bool tryMove(int col, char p)
{
    if (col < 0 || col >= C)
    {
        return false;
    }
    for (int i = R - 1; i >= 0; i--)
    {
        if (b[i][col] == EMPTY)
        {
            b[i][col] = p;
            bool ok = win(i, col, p);
            b[i][col] = EMPTY;
            return ok;
        }
    }
    return false;
}

int evaluateWindow(char window[4])
{
    int ai = 0, player = 0, empty = 0;

    for (int i = 0; i < 4; i++)
    {
        if (window[i] == P2)
        {
            ai++;
        }
        else if (window[i] == P1)
        {
            player++;
        }
        else
        {
            empty++;
        }
    }

    if (ai == 4)
    {
        return 1000;
    }
    if (ai == 3 && empty == 1)
    {
        return 50;
    }
    if (ai == 2 && empty == 2)
    {
        return 10;
    }

    if (player == 4)
    {
        return -1000;
    }
    if (player == 3 && empty == 1)
    {
        return -80;
    }
    if (player == 2 && empty == 2)
    {
        return -10;
    }
    return 0;
}

int evaluate()
{
    int score = 0;
    char window[4];
    for (int r = 0; r < R; r++)
    {
        if (b[r][C / 2] == P2)
        {
            score += 6;
        }
        else if (b[r][C / 2] == P1)
        {
            score -= 6;
        }
    }
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c <= C - 4; c++)
        {
            for (int i = 0; i < 4; i++)
            {
                window[i] = b[r][c + i];
            }
            score += evaluateWindow(window);
        }
    }
    for (int c = 0; c < C; c++)
    {
        for (int r = 0; r <= R - 4; r++)
        {
            for (int i = 0; i < 4; i++)
            {
                window[i] = b[r + i][c];
            }
            score += evaluateWindow(window);
        }
    }
    for (int r = 0; r <= R - 4; r++)
    {
        for (int c = 0; c <= C - 4; c++)
        {
            for (int i = 0; i < 4; i++)
            {
                window[i] = b[r + i][c + i];
            }

            score += evaluateWindow(window);
        }
    }
    for (int r = 3; r < R; r++)
    {
        for (int c = 0; c <= C - 4; c++)
        {
            for (int i = 0; i < 4; i++)
            {
                window[i] = b[r - i][c + i];
            }
            score += evaluateWindow(window);
        }
    }
    return score;
}

int miniMax(int depth, bool maximizing_player)
{
    if (depth == 0 || draw())
    {
        return evaluate();
    }
    if (maximizing_player)
    {
        int maxEval = INT_MIN;
        for (int c = 0; c < C; c++)
        {
            int r = drop(c, P2);
            if (r == -1)
            {
                continue;
            }
            if (win(r, c, P2))
            {
                undo(r, c);
                return 100000 + depth;
            }
            int eval = miniMax(depth - 1, false);
            undo(r, c);
            maxEval = max(maxEval, eval);
        }
        return maxEval;
    }
    else
    {
        int minEval = INT_MAX;
        for (int c = 0; c < C; c++)
        {
            int r = drop(c, P1);
            if (r == -1)
            {
                continue;
            }
            if (win(r, c, P1))
            {
                undo(r, c);
                return -100000 - depth;
            }
            int eval = miniMax(depth - 1, true);
            undo(r, c);
            minEval = min(minEval, eval);
        }
        return minEval;
    }
}

int aiMove()
{
    for (int c = 0; c < C; c++)
    {
        if (tryMove(c, P2))
        {
            return c;
        }
    }
    for (int c = 0; c < C; c++)
    {
        if (tryMove(c, P1))
        {
            return c;
        }
    }

    int bestMove = -1;
    int bestScore = INT_MIN;

    for (int c = 0; c < C; c++)
    {
        int r = drop(c, P2);

        if (r == -1)
        {
            continue;
        }

        int score = miniMax(5, false);

        undo(r, c);

        if (score > bestScore)
        {
            bestScore = score;
            bestMove = c;
        }
    }
    return bestMove;
}

void printBoard()
{
    cout << "\n";
    for (int i = 0; i < R; i++)
    {
        cout << "| ";
        for (int j = 0; j < C; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "|\n";
    }
    cout << "  ";
    for (int j = 0; j < C; j++)
    {
        cout << j + 1 << " ";
    }
    cout << "\n\n";
}

int main()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            b[i][j] = EMPTY;
        }
    }

    cout << "Connect Four - You vs Computer\n";
    char p = P1;
    while (1)
    {
        printBoard();
        int c;
        if (p == P1)
        {
            cout << "Enter column (1-7): ";
            cin >> c;
            c--;
        }
        else
        {
            c = aiMove();
            cout << "Computer chose column " << c + 1 << endl;
        }

        int r = drop(c, p);
        if (r == -1)
        {
            cout << "Invalid move\n";
            continue;
        }
        if (win(r, c, p))
        {
            printBoard();
            if (p == P1)
            {
                cout << "You win!\n";
            }
            else
            {
                cout << "Computer wins!\n";
            }
            break;
        }
        if (draw())
        {
            printBoard();
            cout << "DRAW\n";
            break;
        }
        if (p == P1)
        {
            p = P2;
        }
        else
        {
            p = P1;
        }
    }
    return 0;
}