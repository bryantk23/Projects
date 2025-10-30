/*
There aren't any inputs that the user could enter to cause any bugs or errors, because
there are several error checking functions, specifically within the overloaded >> function
and is used with the position class.
*/
#include "ChessBoard.h"
#include "OverloadedFuncs.h"

using namespace std;

int main()
{
	char userCont;
	ChessBoard* board = new ChessBoard();
	board->initialize();
	board->outputBoard();
	
	do 
	{
		int input = userInput();
		userCont = 'N';
		switch (input)
		{
		case 1:
			{
			Position posFrom;
			cout << "Enter the position of the chess piece you would like to get." << endl;
			cin >> posFrom;
			Position posTo;
			cout << "Enter the position of where you would like to place this chess piece." << endl;
			cin >> posTo;
			board->placePiece(posFrom, posTo);
			board->outputBoard();
			cout << "Would you like to continue using this application? Y/N" << endl;
			cin >> userCont;
			break;
			}
		case 2:
			{
			Position posFrom;
			cout << "Enter the position of the chess piece you would like to move." << endl;
			cin >> posFrom;
			Position posTo;
			cout << "Enter the position of where you would like to move this chess piece." << endl;
			cin >> posTo;
			board->move(posFrom, posTo);
			board->outputBoard();
			cout << "Would you like to continue using this application? Y/N" << endl;
			cin >> userCont;
			break;
			}
		case 3:
			{
			cout << "Ending Program . . ." << endl;
			break;
			}
		default:
			{

			break;
			}
			
		
		}
	} while (toupper(userCont) == 'Y');
	return 0;
}
