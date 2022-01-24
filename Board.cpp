/**
*
* Solution to course project #8
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Plamena Nikolova
* @idnumber 1MI0600031
* @compiler gcc
*
* <functions for board>
*
*/

#include "Board.h"

Board::Board()
{

    this->board = new string *[this->boardDimensions];
    for (int i = 0; i < this->boardDimensions; i++)
        this->board[i] = new string[this->boardDimensions];

    this->board[0][0] = "   ";
    this->board[this->boardDimensions - 1][0] = "10";
    this->board[0][this->boardDimensions - 1] = "J";
    char start = 'A';

    for (int i = 1; i < this->boardDimensions - 1; i++)
    {
        this->board[i][0] = i + '0';
        this->board[i][0] += " ";
        this->board[0][i] = (start + i - 1);
        this->board[0][i] += " ";
    }

    for (int i = 1; i < this->boardDimensions; i++)
    {
        for (int j = 1; j < this->boardDimensions; j++)
        {
            this->board[i][j] = "  ";
        }
    }
}

bool Board::isInsideBoard(Point coordinates)
{

    if (coordinates.x < 1 ||
        coordinates.x > 10 ||
        coordinates.y < 1 ||
        coordinates.y > 10)
        return false;
    return true;
}

// да се подава кораба отделно
bool Board::checkIfShipFits(pair<Point, Point> arr[], int index, pair<Point, Point> ship)
{
    if (!isInsideBoard(ship.first) || !isInsideBoard(ship.second))
        return false;

    for (int i = index - 1; i >= 0; i--)
    {
        if (Point::isHorizontal(arr[i])) // horizontal ships
        {
            if (((ship.second.x >= arr[i].first.x - 1 && ship.second.x <= arr[i].first.x + 1) ||
                 (ship.first.x >= arr[i].first.x - 1 && ship.first.x <= arr[i].first.x + 1)) &&
                ship.second.y >= arr[i].first.y - 1 && ship.first.y <= arr[i].second.y - 1)
                return false;
        }
        else // vertical ships
        {
            if (((ship.second.y >= arr[i].first.y - 1 && ship.second.y <= arr[i].second.y + 1) || (ship.first.y <= arr[i].second.y - 1 && ship.first.y >= arr[i].second.y + 1)) && ship.second.x >= arr[i].first.x - 1 && ship.second.x <= arr[i].first.x + 1)
                return false;
        }
    }

    return true;
}

void Board::placeShips(pair<Point, Point> coordinates[], const int index)
{

    for (int i = 0; i < index; i++)
        if (Point::isHorizontal(coordinates[i]))
        {
            for (int j = coordinates[i].first.x; j <= coordinates[i].second.x; j++)
                this->board[coordinates[i].first.y][j] = this->shipSymbol;
        }
        else
            for (int j = coordinates[i].first.y; j <= coordinates[i].second.y; j++)
                this->board[j][coordinates[i].first.x] = this->shipSymbol;
}

bool Board::hitOrMiss(Point point)
{
    if (this->board[point.y][point.x] == this->shipSymbol)
    {
        this->board[point.y][point.x] = this->hitSymbol;
        return true;
    }
    this->board[point.y][point.x] = this->missSymbol;
    return false;
}

void Board::placeOnBoard(Point point, const bool hit)
{
    if (hit)
    {
        this->board[point.y][point.x] = this->hitSymbol;
    }
    else
    {
        this->board[point.y][point.x] = this->missSymbol;
    }

    return;
}

bool Board::shipHasSunk(Point point)
{

    int x = point.x, y = point.y;
    while (this->board[y][x] != "  " && this->board[y][x] != this->missSymbol)
    {

        if (board[y][x] == this->shipSymbol)
            return false;
        x++;
        if (x > 10)
            break;
    }

    x = point.x, y = point.y;
    while (this->board[y][x] != "  " && this->board[y][x] != this->missSymbol)
    {

        if (board[y][x] == this->shipSymbol)
            return false;
        x--;
        if (x < 1)
            break;
    }

    x = point.x, y = point.y;
    while (this->board[y][x] != "  " && this->board[y][x] != this->missSymbol)
    {

        if (board[y][x] == this->shipSymbol)
            return false;
        y++;
        if (y > 10)
            break;
    }

    x = point.x, y = point.y;
    while (this->board[y][x] != "  " && this->board[y][x] != this->missSymbol)
    {

        if (board[y][x] == this->shipSymbol)
            return false;
        y--;
        if (y < 1)
            break;
    }

    return true;
}

bool Board::moveIsValid(Point point)
{

    if (!isInsideBoard(point))
        return false;
    if (this->board[point.y][point.x] != "  ")
        return false;
    return true;
}

void Board::printBoard()
{

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h, 63);

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (this->board[i][j] == this->missSymbol) // miss
            {
                SetConsoleTextAttribute(h, 48); // blue and black
                cout << this->board[i][j];
                SetConsoleTextAttribute(h, 63); // blue and white
                continue;
            }

            if (this->board[i][j] == this->hitSymbol) //hit
            {
                SetConsoleTextAttribute(h, 60); // blue and red
                cout << this->board[i][j];
                SetConsoleTextAttribute(h, 63); // blue and white
                continue;
            }

            if (this->board[i][j] == this->shipSymbol) //ship
            {
                SetConsoleTextAttribute(h, 56); // blue and grey
                cout << this->board[i][j];
                SetConsoleTextAttribute(h, 63); // blue and white
                continue;
            }

            cout << this->board[i][j];
        }
        cout << '\n';
    }

    SetConsoleTextAttribute(h, 15);
}
