// FinalProject.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ChessBoard.h"
#include "Position.h"


using namespace std;

class ChessPiece
{
protected:
	string color;
public:
	ChessPiece();
	string getColor();
	ChessPiece(string color);
	virtual string toString();
	int positionRowConvert(string pos);
	int positionColConvert(string pos);
};

/*
Returns the array column version of the column held within a string version of a position
*/
int ChessPiece::positionColConvert(string pos)
{
	if (pos[1] == 1)
	{
		return 0;
	}
	else if (pos[1] == 2)
	{
		return 1;
	}
	else if (pos[1] == 3)
	{
		return 2;
	}
	else if (pos[1] == 4)
	{
		return 3;
	}
	else if (pos[1] == 5)
	{
		return 4;
	}
	else if (pos[1] == 6)
	{
		return 5;
	}
	else if (pos[1] == 7)
	{
		return 6;
	}
	else if (pos[1] == 8)
	{
		return 7;
	}
	else
		return -1;
}

/*
Returns the array row version of the row held within a string version of a position
*/
int ChessPiece::positionRowConvert(string pos)
{
	if (pos[0] == 'a')
	{
		return 0;
	}
	else if (pos[0] == 'b')
	{
		return 1;
	}
	else if (pos[0] == 'c')
	{
		return 2;
	}
	else if (pos[0] == 'd')
	{
		return 3;
	}
	else if (pos[0] == 'e')
	{
		return 4;
	}
	else if (pos[0] == 'f')
	{
		return 5;
	}
	else if (pos[0] == 'g')
	{
		return 6;
	}
	else if (pos[0] == 'h')
	{
		return 7;
	}
	else
		return -1;
}

/*
sets an empty/non-value initialized chess piece to an empty chess board space
*/
ChessPiece::ChessPiece()
{
	color = "EMPTY";
}

/*
initializes a chess piece to a given color 
*/
ChessPiece::ChessPiece(string color)
{
	this->color = color;
}

/*
returns the color of a chess piece
*/
string ChessPiece::getColor()
{
	return color;
}

/*
returns the unicode string of a chess piece
*/
string ChessPiece::toString()
{
	return "N/A";
}

