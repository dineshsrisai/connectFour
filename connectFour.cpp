#include <bits/stdc++.h>
using namespace std;

const string RED = "\033[1;31m";
const string YELLOW = "\033[1;33m";
const string BLUE = "\033[1;34m";
const string RESET = "\033[0m";

const int R = 6, C = 7;
char b[R][C];

void printBoard()
{
    cout << "\n";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    printBoard();
    return 0;
}