#include <bits/stdc++.h>
using namespace std;

const string RED = "\033[1;31m";
const string YELLOW = "\033[1;33m";
const string BLUE = "\033[1;34m";
const string RESET = "\033[0m";

const int R = 6, C = 7;
const char EMPTY = '.', P1 = 'X', P2 = 'O';
char b[R][C];

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
    cout << BLUE << "+";
    for (int j = 0; j < C * 2 + 1; j++)
    {
        cout << '-';
    }
    cout << "+\n"
         << RESET << " ";
    for (int j = 0; j < C; j++)
    {
        cout << j + 1 << " ";
    }
    cout << "\n\n";
}
int main()
{
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            b[i][j] = EMPTY;

    printBoard();
    return 0;
}