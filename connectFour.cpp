#include <bits/stdc++.h>
using namespace std;

const string RED = "\033[1;31m";
const string YELLOW = "\033[1;33m";
const string BLUE = "\033[1;34m";
const string RESET = "\033[0m";

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

int aiMove()
{
    for (int c = 0; c < C; c++)
    {
        if (b[0][c] == EMPTY && tryMove(c, P2))
        {
            return c;
        }
    }
    for (int c = 0; c < C; c++)
    {
        if (b[0][c] == EMPTY && tryMove(c, P1))
        {
            return c;
        }
    }

    vector<int> prefCenter = {3, 2, 4, 1, 5, 0, 6};
    for (int c : prefCenter)
    {
        if (b[0][c] == EMPTY)
        {
            return c;
        }
    }
    return -1;
}

void printBoard()
{
    cout << "\n";
    for (int i = 0; i < R; i++)
    {
        cout << BLUE << "| " << RESET;
        for (int j = 0; j < C; j++)
        {
            if (b[i][j] == P1)
            {
                cout << RED << b[i][j] << RESET << " ";
            }
            else if (b[i][j] == P2)
            {
                cout << YELLOW << b[i][j] << RESET << " ";
            }
            else
            {
                cout << b[i][j] << " ";
            }
        }
        cout << BLUE << "|\n"
             << RESET;
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

    cout << "Connect Four\n1)Two Players\n2)Vs Computer\nChoice : ";
    int choice;
    cin >> choice;
    char p = P1;
    while (1)
    {
        printBoard();
        int c;
        if (choice == 1)
        {
            if (p == P1)
                cout << "Player 1, enter column (1-7): ";
            else
                cout << "Player 2, enter column (1-7): ";

            cin >> c;
            c--;
        }
        else
        {
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
            if (choice == 1)
            {
                if (p == P1)
                    cout << "Player 1 wins!\n";
                else
                    cout << "Player 2 wins!\n";
            }
            else
            {
                if (p == P1)
                    cout << "You win!\n";
                else
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