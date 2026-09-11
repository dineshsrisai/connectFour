#include <bits/stdc++.h>
#include "board.h"
using namespace std;

char grid[ROWS][COLS];

void initBoard()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = '.';
        }
    }
}

void printBoard()
{
    cout << endl;
    for (int i = 0; i < ROWS; i++)
    {
        cout << "| ";
        for (int j = 0; j < COLS; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for (int j = 0; j < COLS; j++)
    {
        cout << j + 1 << " ";
    }
    cout << endl;
}

int dropPiece(int col, char p)
{
    if (col < 0 || col >= COLS)
    {
        return -1;
    }
    if (grid[0][col] != '.')
    {
        return -1;
    }

    for (int i = ROWS - 1; i >= 0; i--)
    {
        if (grid[i][col] == '.')
        {
            grid[i][col] = p;
            return i;
        }
    }

    return -1;
}

void undoMove(int r, int c)
{
    grid[r][c] = '.';
}

bool isDraw()
{
    for (int i = 0; i < COLS; i++)
    {
        if (grid[0][i] == '.')
        {
            return false;
        }
    }
    return true;
}

bool checkWin(int r, int c, char p)
{
    int count;
    count = 1;

    for (int i = c - 1; i >= 0 && grid[r][i] == p; i--)
    {
        count++;
    }
    for (int i = c + 1; i < COLS && grid[r][i] == p; i++)
    {
        count++;
    }
    if (count >= 4)
    {
        return true;
    }

    count = 1;
    for (int i = r - 1; i >= 0 && grid[i][c] == p; i--)
    {
        count++;
    }
    for (int i = r + 1; i < ROWS && grid[i][c] == p; i++)
    {
        count++;
    }
    if (count >= 4)
    {
        return true;
    }

    count = 1;
    for (int i = r - 1, j = c - 1; i >= 0 && j >= 0 && grid[i][j] == p; i--, j--)
    {
        count++;
    }
    for (int i = r + 1, j = c + 1; i < ROWS && j < COLS && grid[i][j] == p; i++, j++)
    {
        count++;
    }
    if (count >= 4)
    {
        return true;
    }

    count = 1;
    for (int i = r + 1, j = c - 1; i < ROWS && j >= 0 && grid[i][j] == p; i++, j--)
    {
        count++;
    }
    for (int i = r - 1, j = c + 1; i >= 0 && j < COLS && grid[i][j] == p; i--, j++)
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
    if (col < 0 || col >= COLS)
    {
        return false;
    }

    for (int i = ROWS - 1; i >= 0; i--)
    {
        if (grid[i][col] == '.')
        {
            grid[i][col] = p;
            bool won = checkWin(i, col, p);
            grid[i][col] = '.';
            return won;
        }
    }
    return false;
}