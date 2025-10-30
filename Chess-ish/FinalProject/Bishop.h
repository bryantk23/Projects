

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ChessPiece.h"

using namespace std;

class Bishop : public ChessPiece
{
public:
	Bishop(string color)
	{
		this->color = color;
	}
	virtual string toString() override
	{
		if (color == "WHITE")
		{
			return "u2657";
		}
		else if (color == "BLACK")
		{
			return "u265D";
		}
		else
			return "ERROR: Invalid Input";
	}
};
