#include"Point.h"
#include<iostream>
#include<utility>
#include<windows.h>
using namespace std;

void print(string board[11][11], HANDLE h)
{
    SetConsoleTextAttribute(h,63);

    for(int i = 0; i<11; i++)
    {
        for(int j = 0; j<11; j++)
        {
            if(board[i][j] == " *")// miss
            {
                SetConsoleTextAttribute(h,48); // blue and black
                cout << board[i][j];
                SetConsoleTextAttribute(h,63); // blue and white
                continue;
            }

            if(board[i][j] == " X") //hit
            {
                SetConsoleTextAttribute(h,60); // blue and red
                cout << board[i][j];
                SetConsoleTextAttribute(h,63); // blue and white
                continue;
            }

            if(board[i][j] == " @") //ship
            {
                SetConsoleTextAttribute(h,56); // blue and grey
                cout << board[i][j];
                SetConsoleTextAttribute(h,63); // blue and white
                continue;
            }

            cout << board[i][j];

        }
        cout << '\n';
    }

    SetConsoleTextAttribute(h,15);
}

void createEmptyBoard(string board[11][11])
{
    board[0][0] = "   ";
    board[10][0] = "10";
    board[0][10] = "J";
    char start = 'A';

    for(int i = 1; i<10; i++)
    {
        board[i][0] = i + '0';
        board[i][0] += " ";
        board[0][i] = (start + i-1);
        board[0][i] += " ";
    }

    for(int i = 1; i<11; i++)
    {
        for(int j = 1; j<11; j++)
        {
            board[i][j] = "  ";
        }
    }
}



bool checkIfShipFits(pair<Point,string> arr[], int index)
{
    if(arr[index-1].first.x>10 || arr[index-1].first.x<0 || arr[index-1].first.y>10 || arr[index-1].first.y<0)
    {
        return false;
    }

    for(int i = index-2; i>=0; i--)
    {
        if(arr[i].first.x == arr[i].second.x)
        {
            for(int k = arr[i].first.y-1; k<= arr[i].second.y+1; k++)
            {
                for(int j = arr[index-1].first.x; j)
            }
        }
        else
        {

        }
    }

    return true;
}

int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //color changer
    string board[11][11];

    createEmptyBoard(board);

    print(board, h);
    cout << '\n';

    board[1][1] = " @";
    board[2][1] = " @";
    board[3][1] = " @";
    board[4][1] = " @";
    board[4][8] = " *";
    board[4][7] = " *";
    board[1][6] = " X";

    print(board, h);
}
