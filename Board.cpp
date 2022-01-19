#include <iostream>
using namespace std;

int main()
{
    char board[11][11];

    board[0][0] = ' ';
    char start = 'A';

    for(int i = 1; i<10; i++)
    {
        board[0][i] = start;
        board[i][0] = i + '0';
        start++;
    }

    for(int i = 1; i<11; i++)
    {
        for(int j = 1; j<11; j++)
        {
            board[i][j] = '*';
        }
    }

    for(int i = 0; i<11; i++)
    {
        for(int j = 0; j<11; j++)
        {
            cout << (board[i][j]);
        }
        cout << '\n';
    }
}
