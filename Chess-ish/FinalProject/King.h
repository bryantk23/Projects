
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ChessPiece.h"

using namespace std;

class King : public ChessPiece
{
public:
	King(string color)
	{
		this->color = color;
	}
	virtual string toString() override
	{
		if (color == "WHITE")
		{
			return "u2654";
		}
		else if (color == "BLACK")
		{
			return "u265A";
		}
		else
			return "ERROR: Invalid Input";
	}
};
