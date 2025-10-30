// FinalProject.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ChessPiece.h"

using namespace std;

class Knight : public ChessPiece
{
public:
	Knight(string color)
	{
		this->color = color;
	}
	virtual string toString() override
	{
		if (color == "WHITE")
		{
			return "u2658";
		}
		else if (color == "BLACK")
		{
			return "u265E";
		}
		else
			return "ERROR: Invalid Input";
	}
};
