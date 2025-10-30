
#pragma once
#include "ChessPiece.h"
#include <iostream>

using namespace std;

class Position
{
private:
	int row;
	char col;
public:
	Position(int row, char col);
	Position(int row, int col);
	Position();
	string getPosition();
	int getRealRow();
	int getRow();
	char getCol();
	int convertCol();
	void setRow(int row);
	void setCol(char col);
	string positionConvert(int row, int col);
};

/*
sets the column char
*/
void Position::setCol(char col)
{
	this->col = col;
}

/*
sets the row number
*/
void Position::setRow(int row)
{
	this->row = row;
}

/*
converts the char column to the integer version of itself, and returns it
*/
int Position::convertCol()
{
	if (col == 'a')
	{
		return 0;
	}
	else if (col == 'b')
	{
		return 1;
	}
	else if (col == 'c')
	{
		return 2;
	}
	else if (col == 'd')
	{
		return 3;
	}
	else if (col == 'e')
	{
		return 4;
	}
	else if (col == 'f')
	{
		return 5;
	}
	else if (col == 'g')
	{
		return 6;
	}
	else if (col == 'h')
	{
		return 7;
	}
}

/*
returns the "real" array number of a position's row
*/
int Position::getRealRow()
{
	if (row == 1)
	{
		return 0;
	}
	else if (row == 2)
	{
		return 1;
	}
	else if (row == 3)
	{
		return 2;
	}
	else if (row == 4)
	{
		return 3;
	}
	else if (row == 5)
	{
		return 4;
	}
	else if (row == 6)
	{
		return 5;
	}
	else if (row == 7)
	{
		return 6;
	}
	else if (row == 8)
	{
		return 7;
	}
	else
		return -1;
}

/*
returns the row of a position
*/
int Position::getRow()
{
	return row;
}

/*
returns the char of a column
*/
char Position::getCol()
{
	return col;
}

/*
initializes a position with given int row and char column 
*/
Position::Position(int row, char col)
{
	this->row = row;
	this->col = col;
}

/*
initializes a position with given int row and int column
*/
Position::Position(int row, int colNum)
{
	this->row = row + 1;
	if (colNum == 0)
	{
		col = 'a';
	}
	else if (colNum == 1)
	{
		col = 'b';
	}
	else if (colNum == 2)
	{
		col = 'c';
	}
	else if (colNum == 3)
	{
		col = 'd';
	}
	else if (colNum == 4)
	{
		col = 'e';
	}
	else if (colNum == 5)
	{
		col = 'f';
	}
	else if (colNum == 6)
	{
		col = 'g';
	}
	else if (colNum == 7)
	{
		col = 'h';
	}
}

/*
initializes a position to values that are out of typical bounds on the chess board
*/
Position::Position()
{
	row = -1;
	col = 'z';
}

/*
returns a position, ex (a,4), in the form of a string
*/
string Position::getPosition()
{
	string pos;
	pos = col + row;
	return pos;
}

/*
returns the converted version of a position object from two ints, ex (a, 4)
*/
string Position::positionConvert(int row, int col)
{

	string position;
	string pos;
	if (col == 0)
	{
		position = 'a';
	}
	else if (col == 1)
	{
		position = 'b';
	}
	else if (col == 2)
	{
		position = 'c';
	}
	else if (col == 3)
	{
		position = 'd';
	}
	else if (col == 4)
	{
		position = 'e';
	}
	else if (col == 5)
	{
		position = 'f';
	}
	else if (col == 6)
	{
		position = 'g';
	}
	else if (col == 7)
	{
		position = 'h';
	}


	if (row == 0)
	{
		pos = "1";
	}
	else if (row == 1)
	{
		pos = "2";
	}
	else if (row == 2)
	{
		pos = "3";
	}
	else if (row == 3)
	{
		pos = "4";
	}
	else if (row == 4)
	{
		pos = "5";
	}
	else if (row == 5)
	{
		pos = "6";
	}
	else if (row == 6)
	{
		pos = "7";
	}
	else if (row == 7)
	{
		pos = "8";
	}
	return position + pos;
}