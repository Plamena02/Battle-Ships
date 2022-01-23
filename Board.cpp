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
        if(Point::isHorizontal(arr[i])) // horizontal ships
        {
            if(((arr[index-1].second.x >= arr[i].first.x-1 && arr[index-1].second.x <= arr[i].first.x+1) ||
                (arr[index-1].first.x >= arr[i].first.x-1 && arr[index-1].first.x <= arr[i].first.x+1))
                && arr[index-1].second.y >= arr[i].first.y-1 && arr[index-1].first.y <= arr[i].second.y-1)
                    return false;
        }
        else // vertical ships
        {
            if(((arr[index-1].second.y >= arr[i].first.y-1 && arr[index-1].second.y <= arr[i].first.y+1)
                || (arr[index-1].first.y <= arr[i].second.y-1 && arr[index-1].first.y >= arr[i].second.y+1))
               && arr[index-1].second.x >= arr[i].first.x-1 && arr[index-1].second.x <= arr[i].first.x+1)
                return false;
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
        if(Point::isHorizontal(coordinates[i]))
            for(int j = coordinates[i].first.x; j < coordinates[i].second.x; j++)
                this->board[coordinates[i].first.y][j] = this->shipSymbol;
        else
            for(int j = coordinates[i].first.y; j < coordinates[i].second.y; j++)
                this->board[j][coordinates[i].first.x] = this->shipSymbol;

}

bool Board::hitOrMiss(Point point)
{
    if(this->board[point.y][point.x] == this->shipSymbol)
    {
        return true;
    }
    return false;
}

void Board::placeOnBoard(Point point)
{

    if(this->hitOrMiss(point))
    {
        this->board[point.y][point.x] = this->hitSymbol;
    }
    else
    {
        this->board[point.y][point.x] = this->missSymbol;
    }

    return;
}


