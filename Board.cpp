#include "Board.h"

Board::Board(){

    this->board = new string*[this->boardDimensions];
    for(int i = 0; i < this->boardDimensions; i++)
        this->board[i] = new string[this->boardDimensions];

    this->board[0][0] = "   ";
    this->board[this->boardDimensions - 1][0] = "10";
    this->board[0][this->boardDimensions - 1] = "J";
    char start = 'A';

    for(int i = 1; i<this->boardDimensions - 1; i++)
    {
        this->board[i][0] = i + '0';
        this->board[i][0] += " ";
        this->board[0][i] = (start + i-1);
        this->board[0][i] += " ";
    }

    for(int i = 1; i<this->boardDimensions; i++)
    {
        for(int j = 1; j<this->boardDimensions; j++)
        {
            this->board[i][j] = "  ";
        }
    }

}

bool Board::checkIfShipFits(pair<Point,Point> arr[], int index)
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
                // for(int j = arr[index-1].first.x; j)
            }
        }
        else
        {

        }
    }

    return true;
}

bool Board::moveIsValid(Point coordinates){

    if(coordinates.x < 1 ||
        coordinates.x > 10 ||
        coordinates.y < 1 ||
        coordinates.y > 10 ||
        this->board[coordinates.y][coordinates.x] != "  ")
        return false;
    return true;

}

void Board::placeShips(pair<Point, Point> coordinates[]){

    for(int i = 0; i < Constants::totalShipCount; i++)
        if(Point::areHorizontal(coordinates[i].first, coordinates[i].second))
            for(int j = coordinates[i].first.x; j < coordinates[i].second.x; j++)
                board[coordinates[i].first.y][j] = this->shipSymbol;
        else
            for(int j = coordinates[i].first.y; j < coordinates[i].second.y; j++)
                board[j][coordinates[i].first.x] = this->shipSymbol;

}

// int main()
// {
//     HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //color changer
//     string board[11][11];

//     createEmptyBoard(board);

//     print(board, h);
//     cout << '\n';

//     board[1][1] = " @";
//     board[2][1] = " @";
//     board[3][1] = " @";
//     board[4][1] = " @";
//     board[4][8] = " *";
//     board[4][7] = " *";
//     board[1][6] = " X";

//     print(board, h);
// }
