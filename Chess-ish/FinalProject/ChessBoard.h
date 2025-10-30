// FinalProject.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include "ChessPiece.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "OverloadedFuncs.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ChessBoard
{
private:
	ChessPiece* board[8][8];
public:
	ChessBoard();
	void initialize();
	ChessPiece* getPiece(Position position);
	bool placePiece(Position oldPosition, Position newPosition);
	bool move(Position fromPosition, Position toPosition);
	vector<string> legalMoves(Position currentPos, Position newPos);
	void outputBoard();
};

/*
Outputs the chess board and its chess pieces to the user
*/
void ChessBoard::outputBoard()
{
	int whiteAndBlackWidth = 23;
	int colLetterWidth = 5;

	string temp = board[0][0]->toString();

	cout << setw(whiteAndBlackWidth) << "Black" << endl;
	
	int numbersDown = 1;
	for (int row = 1; row < 9; row++)
	{
		cout << setw(colLetterWidth) << "  -----------------------------------------" << endl;
		cout << numbersDown;
		cout << " | ";
		for (int col = 1; col < 9; col++)
		{
			string wP = "u2659", wR = "u2656", wB = "u2657", wN = "u2658", wQ = "u2655", wK = "u2654", bK = "u265A", bQ = "u265B", bR = "u265C", bB = "u265D", bN = "u265E", bP = "u265F";
			string comparison = board[row - 1][col - 1]->toString();
			if (comparison == "N/A")
			{
				cout << "  ";
			}
			else if (comparison == wP)
			{
				wcout << "WP";
			}
			else if (comparison == wR)
			{
				cout << "WR";
			}
			else if (comparison == wB)
			{
				cout << "WB";
			}
			else if (comparison == wN)
			{
				cout << "WN";
			}
			else if (comparison == wQ)
			{
				cout << "WQ";
			}
			else if (comparison == wK)
			{
				cout << "WK";
			}
			else if (comparison == bK)
			{
				cout << "BK";
			}
			else if (comparison == bQ)
			{
				cout << "BQ";
			}
			else if (comparison == bR)
			{
				cout << "BR";
			}
			else if (comparison == bB)
			{
				cout << "BB";
			}
			else if (comparison == bN)
			{
				cout << "BN";
			}
			else if (comparison == bP)
			{
				cout << "BP";
			}
			else
			{
				cout << "";
			}
			cout << " | ";
		}
		numbersDown++;
		cout << endl;
	}
	cout << setw(colLetterWidth) << "  -----------------------------------------" << endl;
	cout << setw(colLetterWidth) << setw(colLetterWidth) << 'a';
	cout << setw(colLetterWidth) << 'b';
	cout << setw(colLetterWidth) << 'c';
	cout << setw(colLetterWidth) << 'd';
	cout << setw(colLetterWidth) << 'e';
	cout << setw(colLetterWidth) << 'f';
	cout << setw(colLetterWidth) << 'g';
	cout << setw(colLetterWidth) << 'h' << endl;
	cout << setw(whiteAndBlackWidth) << "White" << endl;
}

/*
Initializes each chess board square to an empty place/space.
*/
ChessBoard::ChessBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = NULL;
		}
	}
}

/*
Initializes the chess board to the standard opening chess board
*/
void ChessBoard::initialize()
{
	Rook* bRook = new Rook("BLACK");
	board[0][0] = bRook;
	Knight* bKnight = new Knight("BLACK");
	board[0][1] = bKnight;
	Bishop* bBishop = new Bishop("BLACK");
	board[0][2] = bBishop;
	Queen* bQueen = new Queen("BLACK");
	board[0][3] = bQueen;
	King* bKing = new King("BLACK");
	board[0][4] = bKing;
	
	board[0][5] = bBishop;
	board[0][6] = bKnight;
	board[0][7] = bRook;

	Pawn* bPawn = new Pawn("BLACK");
	for (int line2 = 0; line2 < 8; line2++)
	{
		board[1][line2] = bPawn;
	}

	ChessPiece* emptySpace = new ChessPiece("EMPTY");
	for (int line3To6Row = 2; line3To6Row < 6; line3To6Row++)
	{
		for (int line3To6Col = 0; line3To6Col < 8; line3To6Col++)
		{
			board[line3To6Row][line3To6Col] = emptySpace;
		}
	}

	Pawn* wPawn = new Pawn("WHITE");
	for (int line7 = 0; line7 < 8; line7++)
	{
		board[6][line7] = wPawn;
	}

	Rook* wRook = new Rook("WHITE");
	board[7][0] = wRook;
	Knight* wKnight = new Knight("WHITE");
	board[7][1] = wKnight;
	Bishop* wBishop = new Bishop("WHITE");
	board[7][2] = wBishop;
	Queen* wQueen = new Queen("WHITE");
	board[7][3] = wQueen;
	King* wKing = new King("WHITE");
	board[7][4] = wKing;

	board[7][5] = wBishop;
	board[7][6] = wKnight;
	board[7][7] = wRook;

}

ChessPiece* ChessBoard::getPiece(Position position)
{
	return board[position.getRow()][position.getCol()];
}

/*
This function uses/takes position objects and places them at the new, desired position, if they meet certain 
criterias.
*/
bool ChessBoard::placePiece(Position oldPosition, Position newPosition)
{
	int startRow = oldPosition.getRealRow();
	int startCol = oldPosition.convertCol();

    ChessPiece* emptySpace = new ChessPiece("EMPTY");

	int changeInRow = newPosition.getRealRow();
	int changeInCol = newPosition.convertCol();
	if (board[startRow][startCol]->getColor() == "BLACK")
	{
		if (board[changeInRow][changeInCol]->getColor() == "EMPTY" || board[changeInRow][changeInCol]->getColor() == "WHITE")
		{
			board[changeInRow][changeInCol] = board[startRow][startCol];
			board[startRow][startCol] = emptySpace;
			
			return true;
		}
	}
	else if (board[startRow][startCol]->getColor() == "WHITE")
	{
		if (board[changeInRow][changeInCol]->getColor() == "EMPTY" || board[changeInRow][changeInCol]->getColor() == "BLACK")
		{
			board[changeInRow][changeInCol] = board[startRow][startCol];
			board[startRow][startCol] = emptySpace;
			
			return true;
		}
	}
}

/*
Function contains all of the legal move checking (that it finding the possible moves a chess piece has) for 
all of the different types of chess pieces, excluding the king, queen, and knight. It uses the position class
to access the array of chess pieces that is the chess board.
*/
bool ChessBoard::move(Position fromPosition, Position toPosition)
{
	int startRow = fromPosition.getRealRow();
	int startCol = fromPosition.convertCol();
	vector<string> legalSpaces = legalMoves(fromPosition, toPosition); 
	int timesToRepeat = legalSpaces.size();
	string newPos = toPosition.getPosition();
	string movingPos{ toPosition.getCol() };
	movingPos += to_string(toPosition.getRow());
	
	for (int i = 0; i < timesToRepeat; i++)
	{
		if (legalSpaces[i] == movingPos)
		{
			placePiece(fromPosition, toPosition);
			return true;
		}
	}
	return false;
}

vector<string> ChessBoard::legalMoves(Position currentPos, Position newPos)
{
	vector<string> availableSpaces;
	int startRow = currentPos.getRealRow();
	int startCol = currentPos.convertCol();
	if (board[startRow][startCol]->toString() == "u2656" || board[startRow][startCol]->toString() == "u265C") //Rook
	{
		
		int validPosUp = 1;
		int validPosDown = 1;
		int validPosRight = 1;
		int validPosLeft = 1;

		if (board[startRow][startCol]->getColor() == "BLACK") 
		{
			
			for (int horizontalDown = startRow + 1; horizontalDown < 9; horizontalDown++)
			{
				if (horizontalDown < 8)
				{
					if (validPosDown == 1)
					{
						if (board[horizontalDown][startCol]->getColor() == "WHITE")
						{
							cout << horizontalDown << endl;
							availableSpaces.push_back(newPos.positionConvert(horizontalDown, startCol));
							validPosDown = 0;
						}
						else if (board[horizontalDown][startCol]->getColor() == "EMPTY")
						{
							availableSpaces.push_back(newPos.positionConvert(horizontalDown, startCol));
						}
						else
							validPosDown = 0;

					}
				}
			}
			for (int horizontalUp = startRow - 1; horizontalUp > -1; horizontalUp--)
			{
				if (validPosUp == 1)
				{
					if (board[horizontalUp][startCol]->getColor() == "WHITE")
					{
						availableSpaces.push_back(newPos.positionConvert(horizontalUp, startCol));
						validPosUp = 0;
					}
					else if (board[horizontalUp][startCol]->getColor() == "EMPTY")
					{
						availableSpaces.push_back(newPos.positionConvert(horizontalUp, startCol));
					}
					else if (board[horizontalUp][startCol]->getColor() == "BLACK")
					{
						validPosUp = 0;
					}

				}
			}
			for (int verticalRight = startCol + 1; verticalRight < 9; verticalRight++)
			{
				if (verticalRight < 8)
				{
					if (validPosRight == 1)
					{
						if (board[startRow][verticalRight]->getColor() == "WHITE")
						{
							availableSpaces.push_back(newPos.positionConvert(startRow, verticalRight));
							validPosRight = 0;
						}
						else if (board[startRow][verticalRight]->getColor() == "EMPTY")
						{
							availableSpaces.push_back(newPos.positionConvert(startRow, verticalRight));
						}
						else
							validPosRight = 0;

					}
				}
			}
			for (int verticalLeft = startCol - 1; verticalLeft > -1; verticalLeft--)
			{
				if (validPosLeft == 1)
				{
					if (board[startRow][verticalLeft]->getColor() == "WHITE")
					{
						availableSpaces.push_back(newPos.positionConvert(startRow, verticalLeft));
						validPosLeft = 0;
					}
					else if (board[startRow][verticalLeft]->getColor() == "EMPTY")
					{
						availableSpaces.push_back(newPos.positionConvert(startRow, verticalLeft));
					}
					else
						validPosLeft = 0;

				}
			}
			
		}
		else if (board[startRow][startCol]->getColor() == "WHITE") 
		{
			validPosUp = 1;
			validPosDown = 1;
			validPosRight = 1;
			validPosLeft = 1;

			for (int horizontalDown = startRow + 1; horizontalDown < 9; horizontalDown++)
			{
				if (horizontalDown < 8)
				{
					if (validPosDown == 1)
					{
						if (board[horizontalDown][startCol]->getColor() == "BLACK")
						{
							cout << horizontalDown << endl;
							availableSpaces.push_back(newPos.positionConvert(horizontalDown, startCol));
							validPosDown = 0;
						}
						else if (board[horizontalDown][startCol]->getColor() == "EMPTY")
						{
							availableSpaces.push_back(newPos.positionConvert(horizontalDown, startCol));
						}
						else
							validPosDown = 0;

					}
				}
			}
			for (int horizontalUp = startRow - 1; horizontalUp > -1; horizontalUp--)
			{
				if (validPosUp == 1)
				{
					if (board[horizontalUp][startCol]->getColor() == "BLACK")
					{
						availableSpaces.push_back(newPos.positionConvert(horizontalUp, startCol));
						validPosUp = 0;
					}
					else if (board[horizontalUp][startCol]->getColor() == "EMPTY")
					{
						availableSpaces.push_back(newPos.positionConvert(horizontalUp, startCol));
					}
					else if (board[horizontalUp][startCol]->getColor() == "WHITE")
					{
						validPosUp = 0;
					}

				}
			}
			for (int verticalRight = startCol + 1; verticalRight < 9; verticalRight++)
			{
				if (verticalRight < 8)
				{
					if (validPosRight == 1)
					{
						if (board[startRow][verticalRight]->getColor() == "BLACK")
						{
							availableSpaces.push_back(newPos.positionConvert(startRow, verticalRight));
							validPosRight = 0;
						}
						else if (board[startRow][verticalRight]->getColor() == "EMPTY")
						{
							availableSpaces.push_back(newPos.positionConvert(startRow, verticalRight));
						}
						else
							validPosRight = 0;

					}
				}
			}
			for (int verticalLeft = startCol - 1; verticalLeft > -1; verticalLeft--)
			{
				if (validPosLeft == 1)
				{
					if (board[startRow][verticalLeft]->getColor() == "BLACK")
					{
						availableSpaces.push_back(newPos.positionConvert(startRow, verticalLeft));
						validPosLeft = 0;
					}
					else if (board[startRow][verticalLeft]->getColor() == "EMPTY")
					{
						availableSpaces.push_back(newPos.positionConvert(startRow, verticalLeft));
					}
					else
						validPosLeft = 0;

				}
			}

		}
		else
			

		return availableSpaces;
	}

	else if (board[startRow][startCol]->toString() == "u2659" || board[startRow][startCol]->toString() == "u265F") // Pawn
	{
 		string currentColor = board[startRow][startCol]->getColor();

		if (currentColor == "WHITE")
		{
			if (startRow == 6)
			{
				if (board[startRow - 1][startCol]->getColor() == "EMPTY" && board[startRow - 2][startCol]->getColor() == "EMPTY")
				{
					availableSpaces.push_back(newPos.positionConvert(startRow - 2, startCol));
				}
			}
			if (startRow - 1 > -1)
			{
				if (board[startRow - 1][startCol]->getColor() == "EMPTY")
				{
					availableSpaces.push_back(newPos.positionConvert(startRow - 1, startCol));
				}
			}
			if (startRow - 1 > -1 && startCol - 1 > -1)
			{
				if (board[startRow - 1][startCol - 1]->getColor() == "BLACK")
				{
					availableSpaces.push_back(newPos.positionConvert(startRow - 1, startCol - 1));
				}

			}
			if (startRow - 1 > -1 && startCol + 1 < 8)
			{
				if (board[startRow - 1][startCol + 1]->getColor() == "BLACK")
				{
					availableSpaces.push_back(newPos.positionConvert(startRow - 1, startCol + 1));
				}
			}
			
		}
		else if (currentColor == "BLACK")
		{
			if (startRow == 1)
			{
				if (board[startRow + 1][startCol]->getColor() == "EMPTY" && board[startRow + 2][startCol]->getColor() == "EMPTY")
				{
					availableSpaces.push_back(newPos.positionConvert(startRow + 2, startCol));
				}
			}
			if (startRow + 1 < 8)
			{
				if (board[startRow + 1][startCol]->getColor() == "EMPTY")
				{
					
					availableSpaces.push_back(newPos.positionConvert(startRow + 1, startCol));
				}
			}
			if (startRow + 1 < 8 && startCol - 1 > -1)
			{
				if (board[startRow + 1][startCol - 1]->getColor() == "WHITE")
				{
					availableSpaces.push_back(newPos.positionConvert(startRow + 1, startCol - 1));
				}

			}
			if (startRow + 1 < 8 && startCol + 1 < 8)
			{
				if (board[startRow + 1][startCol + 1]->getColor() == "WHITE")
				{
					availableSpaces.push_back(newPos.positionConvert(startRow + 1, startCol + 1));
				}
			}
		}
		else
			cout << "ERROR: Invalid Input" << endl;

		return availableSpaces;

	}

	else if (board[startRow][startCol]->toString() == "u2657" || board[startRow][startCol]->toString() == "u265D") // Bishop
	{
		int incrementingRow = startRow;
		int incrementingCol = startCol;
		string currentColor = board[startRow][startCol]->getColor();

		bool validPosRightDown = true;
		bool validPosLeftDown = true;
		bool validPosRightUp = true;
		bool validPosLeftUp = true;

		if (currentColor == "BLACK")
		{
			int rightDownInc;
			if (startRow < startCol)
			{
				rightDownInc = startCol;
			}
			else if (startRow > startCol)
			{
				rightDownInc = startRow;
			}
			else
				rightDownInc = startCol;

			for (int rightDownDiagonally = rightDownInc; rightDownDiagonally < 7; rightDownDiagonally++)
			{
				incrementingRow++;
				incrementingCol++;

				if (incrementingCol < 8 && incrementingRow < 8)
				{
					if (validPosRightDown)
					{
						if (board[incrementingRow][incrementingCol]->getColor() == "WHITE")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
							validPosRightDown = false;
						}
						else if (board[incrementingRow][incrementingCol]->getColor() == "EMPTY")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
						}
						else
							validPosRightDown = false;
					}
				}


			}
			int leftDownInc;
			if (startRow > startCol)
			{
				leftDownInc = startRow;
			}
			else if (startRow < startCol)
			{
				leftDownInc = startCol;
			}
			else
				leftDownInc = startCol;

			incrementingRow = startRow;
			incrementingCol = startCol;

			for (int leftDownDiagonally = leftDownInc; leftDownDiagonally > 0; leftDownDiagonally--)
			{
				if (validPosLeftDown)
				{
					incrementingRow++;
					incrementingCol--;
					if (incrementingCol > -1 && incrementingRow < 8)
					{
						if (board[incrementingRow][incrementingCol]->getColor() == "WHITE")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
							validPosLeftDown = false;
						}
						else if (board[incrementingRow][incrementingCol]->getColor() == "EMPTY")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
						}
						else
							validPosLeftDown = false;
					}
				}

			}

			int rightUpInc;
			if (startRow > startCol)
			{
				rightUpInc = startCol;
			}
			else if (startRow < startCol)
			{
				rightUpInc = startRow;
			}
			else
				rightUpInc = startCol;

			incrementingRow = startRow;
			incrementingCol = startCol;

			for (int rightUpDiagonally = rightUpInc; rightUpDiagonally < 7; rightUpDiagonally++)
			{
				if (validPosRightUp)
				{
					incrementingCol++;
					incrementingRow--;
					if (incrementingCol < 8 && incrementingRow > -1)
					{
						if (board[incrementingRow][incrementingCol]->getColor() == "WHITE")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
							validPosRightUp = false;
						}
						else if (board[incrementingRow][incrementingCol]->getColor() == "EMPTY")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
						}
						else
							validPosRightUp = false;
					}
				}

			}

			incrementingRow = startRow;
			incrementingCol = startCol;

			int leftUpInc;
			if (startRow < startCol)
			{
				leftUpInc = startRow;
			}
			else if (startRow > startCol)
			{
				leftUpInc = startCol;
			}
			else
				leftUpInc = startCol;

			for (int leftUpDiagonally = leftUpInc; leftUpDiagonally > 0; leftUpDiagonally--)
			{
				if (validPosLeftUp)
				{
					incrementingCol--;
					incrementingRow--;
					if (incrementingCol > -1 && incrementingRow > -1)
					{
						if (board[incrementingRow][incrementingCol]->getColor() == "WHITE")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
							validPosLeftUp = false;
						}
						else if (board[incrementingRow][incrementingCol]->getColor() == "EMPTY")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
						}
						else
							validPosLeftUp = false;
					}
				}

			}
		}

		else if (currentColor == "WHITE")
		{
			validPosRightDown = true;
			validPosLeftDown = true;
			validPosRightUp = true;
			validPosLeftUp = true;
			int rightDownInc;
			if (startRow < startCol)
			{
				rightDownInc = startCol;
			}
			else if (startRow > startCol)
			{
				rightDownInc = startRow;
			}
			else
				rightDownInc = startCol;

			for (int rightDownDiagonally = rightDownInc; rightDownDiagonally < 7; rightDownDiagonally++)
			{
				incrementingRow++;
				incrementingCol++;

				if (incrementingCol < 8 && incrementingRow < 8)
				{
					if (validPosRightDown)
					{
						if (board[incrementingRow][incrementingCol]->getColor() == "BLACK")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
							validPosRightDown = false;
						}
						else if (board[incrementingRow][incrementingCol]->getColor() == "EMPTY")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
						}
						else
							validPosRightDown = false;
					}
				}


			}
			int leftDownInc;
			if (startRow > startCol)
			{
				leftDownInc = startRow;
			}
			else if (startRow < startCol)
			{
				leftDownInc = startCol;
			}
			else
				leftDownInc = startCol;

			incrementingRow = startRow;
			incrementingCol = startCol;

			for (int leftDownDiagonally = leftDownInc; leftDownDiagonally > 0; leftDownDiagonally--)
			{
				if (validPosLeftDown)
				{
					incrementingRow++;
					incrementingCol--;
					if (incrementingCol > -1 && incrementingRow < 8)
					{
						if (board[incrementingRow][incrementingCol]->getColor() == "BLACK")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
							validPosLeftDown = false;
						}
						else if (board[incrementingRow][incrementingCol]->getColor() == "EMPTY")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
						}
						else
							validPosLeftDown = false;
					}
				}

			}

			int rightUpInc;
			if (startRow > startCol)
			{
				rightUpInc = startCol;
			}
			else if (startRow < startCol)
			{
				rightUpInc = startRow;
			}
			else
				rightUpInc = startCol;

			incrementingRow = startRow;
			incrementingCol = startCol;

			for (int rightUpDiagonally = rightUpInc; rightUpDiagonally < 7; rightUpDiagonally++)
			{
				if (validPosRightUp)
				{
					incrementingCol++;
					incrementingRow--;
					if (incrementingCol < 8 && incrementingRow > -1)
					{
						if (board[incrementingRow][incrementingCol]->getColor() == "BLACK")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
							validPosRightUp = false;
						}
						else if (board[incrementingRow][incrementingCol]->getColor() == "EMPTY")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
						}
						else
							validPosRightUp = false;
					}
				}

			}

			incrementingRow = startRow;
			incrementingCol = startCol;

			int leftUpInc;
			if (startRow < startCol)
			{
				leftUpInc = startRow;
			}
			else if (startRow > startCol)
			{
				leftUpInc = startCol;
			}
			else
				leftUpInc = startCol;

			for (int leftUpDiagonally = leftUpInc; leftUpDiagonally > 0; leftUpDiagonally--)
			{
				if (validPosLeftUp)
				{
					incrementingCol--;
					incrementingRow--;
					if (incrementingCol > -1 && incrementingRow > -1)
					{
						if (board[incrementingRow][incrementingCol]->getColor() == "BLACK")
						{
							cout << "this " << incrementingCol << endl;
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
							validPosLeftUp = false;
						}
						else if (board[incrementingRow][incrementingCol]->getColor() == "EMPTY")
						{
							availableSpaces.push_back(newPos.positionConvert(incrementingRow, incrementingCol));
						}
						else
							validPosLeftUp = false;
					}
				}

			}
		}
	}
	return availableSpaces;
}


