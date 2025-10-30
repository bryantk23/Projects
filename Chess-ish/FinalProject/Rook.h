
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ChessPiece.h"

using namespace std;

class Rook : public ChessPiece
{
protected:

public:
	Rook(string color)
	{
		this->color = color;
	}
	virtual string toString() override
	{
		if (getColor() == "WHITE")
		{
			string returningPiece = "u2656";
			return returningPiece;
		}
		else if (getColor() == "BLACK")
		{
			string returningPiece = "u265C";
			return returningPiece;
		}
		else
			return "ERROR: Invalid Input";
	}
};
