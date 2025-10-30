
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ChessPiece.h"

using namespace std;

class Queen : public ChessPiece
{
public:
	Queen(string color)
	{
		this->color = color;
	}
	virtual string toString() override
	{
		if (color == "WHITE")
		{
			return "u2655";
		}
		else if (color == "BLACK")
		{
			return "u265B";
		}
		else
			return "ERROR: Invalid Input";
	}
};
