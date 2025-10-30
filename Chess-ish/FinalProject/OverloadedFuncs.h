
#pragma once
#include <string>
#include <iostream>
#include "Position.h"

/*
overloads the >> operator with the position class
*/
istream& operator>>(istream& cin, Position& position)
{
	bool nonValidCol = false;
	int row;
	char col;
	do
	{
		cout << "Enter the column: (a,h)" << endl;
		cin >> col;
		position.setCol(col);
		if (col == 'a')
		{
			nonValidCol = true;
		}
		else if (col == 'b')
		{
			nonValidCol = true;
		}
		else if (col == 'c')
		{
			nonValidCol = true;
		}
		else if (col == 'd')
		{
			nonValidCol = true;
		}
		else if (col == 'e')
		{
			nonValidCol = true;
		}
		else if (col == 'f')
		{
			nonValidCol = true;
		}
		else if (col == 'g')
		{
			nonValidCol = true;
		}
		else if (col == 'h')
		{
			nonValidCol = true;
		}
		else
		{
			nonValidCol = false;
		}
	} while (nonValidCol == false);
	do
	{
		cout << "Enter the row: (1,8)" << endl;
		cin >> row;
		position.setRow(row);
	} while (row < 0 && row > 9);
	return cin;
}

/*
returns the user's answer to a series of questions for a switch case for the menu
*/
int userInput()
{
	int userAnswer;
	cout << "What would you like to do?" << endl;
	cout << "1) Place a chess piece somewhere." << endl;
	cout << "2) Move a chess piece somewhere." << endl;
	cout << "3) End Program" << endl;
	cin >> userAnswer;
	return userAnswer;
}
