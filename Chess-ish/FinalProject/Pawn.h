// FinalProject.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ChessPiece.h"

using namespace std;

class Pawn : public ChessPiece
{
public:
	Pawn(string color)
	{
		this->color = color;
	}
	virtual string toString() override
	{
		if (getColor() == static_cast<string>("WHITE"))
		{
			return "u2659";
		}
		else if (getColor() == static_cast<string>("BLACK"))
		{
			return "u265F";
		}
		else
			return "ERROR: Invalid Input";
	}
};
