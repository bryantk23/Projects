/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: TheR3
 *
 * Created on November 18, 2023, 10:21 AM
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <ostream>
#include <fstream>
#include <time.h>

const int COLUMNS = 3;
const int ROWS = 3;

//typedef string string;

using namespace std;

int ticTacToeChoice();
void ticTacToeGameBoard(char [][COLUMNS], int rows);
void outputTicTacToeGameBoard(char a[][COLUMNS], int rows, int COLUMNS);
void inputUserSymbolForPlayerVsPlayer(char a[][COLUMNS], int rows, int COLUMNS, int player1);
int player1First();
void allTicTacToePlayerVsPlayerFunctionality();
void beginningInstructionsForTicTacToe();
int winDeterminer(char array[][COLUMNS], int rows);
int playerSwitcher(int currentPlayer);
void blockPossibleFork(char array[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate);
void possibleFork(char array[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate);
void firstAiMove(char array[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate);
void smartAiChecksForWinPossibility(char array[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate);
void outputTicTacToeGameBoardForSaving(char a [][COLUMNS], int rows, int COLUMNS, int currentResults);
void allFunctionallityForPlayerVsPerfectAI(double &gamesPlayedAgainstSmartAi, double &gamesWonAgainstSmartAi, double &totalGamesPlayed, double &totalGamesWon);
void inputSmartAiSymbol(char a[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate);
void randomInput(char a[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate);
void allFunctionallityForPlayerVsDumbAi(double &gamesPlayedWithDumbAi, double &playerWinsAgainstDumbAi, double &totalGamesPlayed, double &totalGamesWon);
void inputUserSymbolForPlayerVsDumbAi(char a[][COLUMNS], int rows, int COLMUNS);
void allFunctionallityForDumbAiVsDumbAi();
void createOrModifyFiles(double &totalGamesPlayed, double &totalGamesWon,
        double &playerWinsAgainstSmartAi, double &gamesPlayedWithSmartAi, 
            double &playerWinsAgainstDumbAi, double &gamesPlayedWithDumbAi);
void loadInFiles(double &totalGamesPlayed, double &totalGamesWon,
        double &playerWinsAgainstSmartAi, double &gamesPlayedWithSmartAi, 
            double &playerWinsAgainstDumbAi, double &gamesPlayedWithDumbAi);
void showStats(double &totalGamesPlayed, double &totalGamesWon,
        double &playerWinsAgainstSmartAi, double &gamesPlayedWithSmartAi, 
            double &playerWinsAgainstDumbAi, double &gamesPlayedWithDumbAi);

void allFunctionalityForStudyApp(vector<vector<string>>& allSets);
void addASet(vector<vector<string>>& allSets);
void outputSetNames(vector<vector<string>>& allSets);
void modifyASet(vector<vector<string>>& allSets);


void addToASet(vector<string>& v, int& numberOfQuestionSets);
void addSet(int& numberOfQuestionSets);
void studyASet();
void addAdditionalToSet(vector<string>& v);
void realLoadAndAddToVectors(int& numOfQuestions);
void outputVector(const vector<string>& v, int numberOfQuestionSets);
void deleteFromASet();
void deleteAWholeSet(const string& fileName);

int main(int argc, char** argv) {

    srand(time(0));
    
    double totalGamesPlayed = 0, totalGamesWon = 0;
    double playerWinsAgainstSmartAi = 0, gamesPlayedWithSmartAi = 0;
    double playerWinsAgainstDumbAi = 0, gamesPlayedWithDumbAi = 0;
    
    vector<vector<string>> allSets;
    
    string userWantsToCont;
    do
    {
        cout << "What application would you like to run?" << endl;
        cout << "1) Tic-Tac-Toe" << endl;
        cout << "2) FlashCards" << endl;
        int userGameChoice;
        
        cin >> userGameChoice;
        
        loadInFiles(totalGamesPlayed, totalGamesWon,
            playerWinsAgainstSmartAi, gamesPlayedWithSmartAi, 
                playerWinsAgainstDumbAi, gamesPlayedWithDumbAi);
        
        switch (userGameChoice)
        {
            case 1:
            {
                string userCont;
                do 
                {
                    switch (ticTacToeChoice())
                    {
                        case 1:
                        {
                            allTicTacToePlayerVsPlayerFunctionality();
                            break;
                        }
                        case 2:
                        {
                            allFunctionallityForPlayerVsPerfectAI(gamesPlayedWithSmartAi, playerWinsAgainstSmartAi, totalGamesPlayed, totalGamesWon);
                            break;
                        }
                        case 3:
                        {
                            allFunctionallityForPlayerVsDumbAi(gamesPlayedWithDumbAi, playerWinsAgainstDumbAi, totalGamesPlayed, totalGamesWon);
                            break;
                        }
                        case 4:
                        {
                            allFunctionallityForDumbAiVsDumbAi();
                            break;
                        }
                        case 5:
                        {
                            showStats(totalGamesPlayed, totalGamesWon,
                                playerWinsAgainstSmartAi, gamesPlayedWithSmartAi, 
                                    playerWinsAgainstDumbAi, gamesPlayedWithDumbAi);
                            break;
                        }
                        default:
                        {
                            cout << "Invalid Input" << endl;
                        }
                    }
                    createOrModifyFiles(totalGamesPlayed, totalGamesWon,
                        playerWinsAgainstSmartAi, gamesPlayedWithSmartAi, 
                            playerWinsAgainstDumbAi, gamesPlayedWithDumbAi);
                    cout << "Would you like to continue playing Tic-Tac-Toe?Y/N" << endl;
                    cin >> userCont;
                }
                while(tolower(userCont[0]) == 'y');
                break;
            }
            case 2:
            {
                allFunctionalityForStudyApp(allSets);
                break;
            }
            default:
                cout << "Invalid Input" << endl;
        }
        cout << "Would you still like to keep playing Tic-Tac-Toe" 
                << endl << "or the studying application?Y/N" << endl;
        cin >> userWantsToCont;
    }
    while(tolower(userWantsToCont[0])== 'y');
    
    return 0;
}
void allFunctionalityForStudyApp(vector<vector<string>>& allSets)
{
    int numOfQuestions = 0;
    int numberOfQuestionSets = 0;
    cout << "What would you like to do?" << endl;
    cout << "1) Add A Set" << endl;
    cout << "2) Add To A Set" << endl;
    cout << "3) Delete From A Set" << endl;
    cout << "4) Study A Set" << endl;
    cout << "5) Delete A Whole Set" << endl;
    int userInput;
    cin >> userInput;
    
    switch (userInput)
    {
        case 1:
        {
            addSet(numberOfQuestionSets);
            break;
        }
        case 2:
        {
            realLoadAndAddToVectors(numOfQuestions);
            break;
        }
        case 3:
        {
            deleteFromASet();
            break;
        }
        case 4:
        {
            studyASet();
            break;
        }
        case 5:
        {
            cout << "What is the name of the set you would like to delete?" << endl;
            string setBeingDeleted;
            ifstream file;
            cin >> setBeingDeleted;
            file.open(setBeingDeleted);
            if(file)
            {
                file.close();
                deleteAWholeSet(setBeingDeleted);
            }
            else
            {
                cout << "File doesn't exist" << endl;
            }
            break;
        }
    }
    
    
}
void deleteAWholeSet(const string& fileName)
{
    remove(fileName.c_str());
}
void outputVector(const vector<string>& v, int numberOfQuestionSets)
{
    for (int i = 0; i < numberOfQuestionSets; i++)
    {
        cout << v[i] << endl;
    }
}

void addSet(int& numberOfQuestionSets)
{
    cout << "What is the name of the study set you would like to create?" << endl;
    string setName;
    cin >> setName;
    vector<string> v;
    ofstream fout;
    ifstream file;
    file.open(setName);
    if (file)
    {
        cout << "The file already exists" << endl;
    }
    else
    {
        fout.open(setName);
        addToASet(v, numberOfQuestionSets);
        for (int i = 0; i < numberOfQuestionSets; i++)
        {
            fout << v[i] << endl;
        }
        fout.close();
    }
    fout.close();
    
}
void studyASet()
{
    bool fileExists = false;
    string setName;
    ifstream file;
    do
    {
        cout << "What set would you like to study?" << endl;
        cin >> setName;
        file.open(setName);
        if(file)
        {
            fileExists = true;
        }
        else
        {
            cout << "File doesn't exists, try again" << endl;
        }
    }
    while(fileExists != true);
    int numberOfQuestionSets = 0;
    int question = 0;
    int answer = 1;
    string tempForInputIntoVector;
    string rightOrWrongAnswer;
    vector<string> tempForStudy;
    fstream fin;
    fin.open(setName);
    cin.ignore();
    while(!fin.eof())
    {
        getline(fin, tempForInputIntoVector);
        tempForStudy.push_back(tempForInputIntoVector);
        numberOfQuestionSets++;
    }
 
    for (int i = 0; i < numberOfQuestionSets/2; i++)
    {
        cout << endl << tempForStudy[question] << endl;
        getline(cin, rightOrWrongAnswer);
        if (rightOrWrongAnswer == tempForStudy[answer])
        {
            cout << "Correct" << endl;
        }
        else 
        {
            cout << "Incorrect, answer is " << tempForStudy[answer] << endl;
        }
        question = question + 2;
        answer = answer + 2;
    }
}
void addToASet(vector<string>& v, int& numberOfQuestionSets)
{
    string userCont;
    do
    {
        string answer;
        string question;
        cin.ignore();
        cout << "Enter the question" << endl;
        getline(cin, question);
        numberOfQuestionSets++;
        cout << "Enter the answer" << endl;
        getline(cin, answer);
        numberOfQuestionSets++;
        v.push_back(question);
        v.push_back(answer);
        cout << "Would you like to continue adding questions/answers?Y/N" << endl;
        cin >> userCont;
        
    }
    while (tolower(userCont[0])== 'y');
}
void addASet(vector<vector<string>>& allSets)
{
    cout << "What is the name of the set you would like to add?" << endl;
    string nameOfSet;
    cin >> nameOfSet;
    allSets.push_back({nameOfSet});
}
void outputSetNames(vector<vector<string>>& allSets)
{
    for (int i = 0; i < allSets.size(); i++)
    {
        for (int j = 0; j < allSets[i].size(); j++)
        {
            cout << allSets[i][j] << ' ';
        }
        cout << endl;
    }
}

void inputMoreToASet()
{
    cout << "What is the name of set you would like to add to" << endl;
    string nameOfSet;
    vector<string> v;
    fstream fin;
    cin >> nameOfSet;
    fin.open(nameOfSet);
}

void realLoadAndAddToVectors(int& numOfQuestions)
{
    bool fileExists = false;
    string setName;
    ofstream fout;
    fstream fin;
    ifstream file;
    do
    {
        cout << "What is the name of set you would like to add to" << endl;
        cin >> setName;
        file.open(setName);
        if(file)
        {
            fileExists = true;
        }
        else
        {
            cout << "File doesn't exists, try again" << endl;
        }
    }
    while (fileExists != true);
    cin.ignore();
    string temp;
    string tempQuestion;
    string tempAnswer;
    string userCont;
    int tempNums;
    vector<string> changes;
    fin.open(setName);
    while(!fin.eof())
    {
        getline(fin, temp);
        if (temp != "")
        {
            changes.push_back(temp);
            numOfQuestions++;
        }
        
    }
    fin.close();
    do 
    {
        cout << "Enter the question" << endl;
        getline(cin, tempQuestion);
        
        //
        
        cout << "Enter the answer" << endl;
        getline(cin, tempAnswer);
        //
        
        changes.push_back(tempQuestion);
        changes.push_back(tempAnswer);
        tempQuestion = "";
        tempAnswer = "";
        numOfQuestions = numOfQuestions + 2;
        
        cout << "Would you like to continue adding elements?Y/N" << endl;
        getline(cin, userCont);
    }
    while(tolower(userCont[0])== 'y');
    //changes.pop_back();
    int loc;
    int timesNeededToPopBack = 0;
    int size = changes.size() - 1;
    for (int j = 0; j < size; j++)
    {
        if (changes[j] == "")
        {
            for(int k = loc; k < size - loc; k++)
            {
                changes[k] = changes[k + 1];
                
            }
            timesNeededToPopBack++;
        }
        loc++;
    }
    for (int l = 0; l > timesNeededToPopBack; l++)
    {
        changes.pop_back();
    }
    outputVector(changes, numOfQuestions);
    fout.open(setName);
    for (int i = 0; i < numOfQuestions; i++)
    {
        fout << changes[i] << endl;
    }
    //outputVectorToFile(changes, numOfQuestions);
    fout.close();
    
}
void deleteFromASet()
{
    bool fileExists = false;
    string setName;
    ifstream file;
    do
    {
        cout << "What is the name of set you would like to delete elements from" << endl;
        cin >> setName;
        file.open(setName);
        if(file)
        {
            fileExists = true;
        }
        else
        {
            cout << "File doesn't exists, try again" << endl;
        }
    }
    while (fileExists != true);
    cin.ignore();
    string temp;
    vector<string> set;
    string deleteQuestion;
    string userCont;
    int tempLoc = 0;
    int loc = -1;
    int tempNums = 0;
    int numOfQuestions = 0;
    ofstream fout;
    fstream fin;
    fin.open(setName);
    while(!fin.eof())
    {
        getline(fin, temp);
        if (temp != "")
        {
            set.push_back(temp);
            numOfQuestions++;
        }
    }
    cout << endl << "Questions: " << endl << endl;
    for (int i = 0; i < numOfQuestions/2; i++)
    {
        cout << set[tempNums] << endl;
        tempNums = tempNums + 2;
    }
    do
    {
        cout << endl << "Type in the question you would like to delete" << endl;
        getline(cin, deleteQuestion);
        for (int j = 0; j < numOfQuestions; j++)
        {
            if (set[j] == deleteQuestion)
            {
                loc = tempLoc;
            }
            tempLoc++;
        }
        if(loc == -1)
        {
            cout << "Try again, invalid input";
        }
    }
    while (loc == -1);
    numOfQuestions = numOfQuestions - 2;
    //loc = set.find(deleteQuestion);
    for (int k = loc; k < numOfQuestions; k++)
    {
        set[k + 1] = set[k + 2];
        set[k] = set[k + 1];
    }
    set.pop_back();
    fout.open(setName);
    for (int a = 0; a < numOfQuestions; a++)
    {
        fout << set[a] << endl;
    }
    fout.close();
}




void savingTicTacToeGame(char a[][COLUMNS], int rows)
{
    ofstream fout;
    fout.open("TICTACTOE");
    
}

void createOrModifyFiles(double &totalGamesPlayed, double &totalGamesWon,
        double &playerWinsAgainstSmartAi, double &gamesPlayedWithSmartAi, 
            double &playerWinsAgainstDumbAi, double &gamesPlayedWithDumbAi)
{
    ofstream fout;
    fout.open("stats.txt");
    fout << "Total Games Played: " << totalGamesPlayed << "." << endl;
    fout << "Total Games Won: " << totalGamesWon << "." << endl;
    fout << "Total Win Rate %: " << (totalGamesWon / totalGamesPlayed) * 100 << "." << endl << endl;
    fout << "Total Games Played vs Smart AI: " << gamesPlayedWithSmartAi << "." <<endl;
    fout << "Total Games Won vs Smart AI: " << playerWinsAgainstSmartAi << "." << endl;
    fout << "Win Rate % vs Smart AI: " << (playerWinsAgainstSmartAi / gamesPlayedWithSmartAi) * 100 << "." << endl << endl;
    fout << "Total Games Played vs Dumb AI: " << gamesPlayedWithDumbAi << "." << endl;
    fout << "Total Games Won vs Dumb AI: " << playerWinsAgainstDumbAi << "." << endl;
    fout << "Win Rate % vs Dumb AI: " << (playerWinsAgainstDumbAi / gamesPlayedWithDumbAi) * 100 << "." << endl << endl;
    fout.close();
}
void showStats(double &totalGamesPlayed, double &totalGamesWon,
        double &playerWinsAgainstSmartAi, double &gamesPlayedWithSmartAi, 
            double &playerWinsAgainstDumbAi, double &gamesPlayedWithDumbAi)
{
    cout << "Total Games Played: " << totalGamesPlayed << "." << endl;
    cout << "Total Games Won: " << totalGamesWon << "." << endl;
    cout << "Total Win Rate %: " << (totalGamesWon / totalGamesPlayed) * 100 << "." << endl << endl;
    cout << "Total Games Played vs Smart AI: " << gamesPlayedWithSmartAi << "." <<endl;
    cout << "Total Games Won vs Smart AI: " << playerWinsAgainstSmartAi << "." << endl;
    cout << "Win Rate % vs Smart AI: " << (playerWinsAgainstSmartAi / gamesPlayedWithSmartAi) * 100 << "." << endl << endl;
    cout << "Total Games Played vs Dumb AI: " << gamesPlayedWithDumbAi << "." << endl;
    cout << "Total Games Won vs Dumb AI: " << playerWinsAgainstDumbAi << "." << endl;
    cout << "Win Rate % vs Dumb AI: " << (playerWinsAgainstDumbAi / gamesPlayedWithDumbAi) * 100 << "." << endl << endl;
}
void loadInFiles(double &totalGamesPlayed, double &totalGamesWon,
        double &playerWinsAgainstSmartAi, double &gamesPlayedWithSmartAi, 
            double &playerWinsAgainstDumbAi, double &gamesPlayedWithDumbAi)
{
    fstream fin;
    string wholeLine;
    string tempConvertToInt;
    string trash;
    int gamesPlayedColonFinder = 0, gamesWonColonFinder = 0;
    int gamesPlayedEndFinder = 0, gamesWonEndFinder = 0;
    fin.open("stats.txt");
    //getline(fin, trash);
    
    //rowCoordinate = stoi(userPlacement.substr(0,1));
    //columnCoordinate = stoi(userPlacement.substr(two));

    //columnCoordinate = stoi(two);

    getline(fin, wholeLine);
    gamesPlayedColonFinder = wholeLine.find(':') + 2;
    gamesPlayedEndFinder = wholeLine.find('.');
    gamesPlayedEndFinder = gamesPlayedEndFinder - gamesPlayedColonFinder;
    //cout << gamesPlayedColonFinder << endl;
    //cout << gamesPlayedEndFinder << endl;
    tempConvertToInt = wholeLine.substr(gamesPlayedColonFinder,gamesPlayedEndFinder);
    //cout << tempConvertToInt << endl;
    //cout << totalGamesPlayed << endl;
    if (tempConvertToInt == "nan" || tempConvertToInt == "0")
    {
        totalGamesPlayed = totalGamesPlayed;
    }
    else
    {
        totalGamesPlayed = stoi(tempConvertToInt);
    }
    cout << totalGamesPlayed << endl;
    wholeLine = "";

    getline(fin, wholeLine);
    gamesPlayedColonFinder = wholeLine.find(':') + 2;
    //cout << gamesPlayedColonFinder << endl;
    gamesPlayedEndFinder = wholeLine.find('.');
    //cout << gamesPlayedEndFinder << endl;
    gamesPlayedEndFinder = gamesPlayedEndFinder - gamesPlayedColonFinder;
    //cout << gamesPlayedEndFinder << endl;
    tempConvertToInt = wholeLine.substr(gamesPlayedColonFinder,gamesPlayedEndFinder);
    //cout << tempConvertToInt << endl;
    if (tempConvertToInt == "nan" || tempConvertToInt == "0")
    {
        totalGamesWon = totalGamesWon;
    }
    else
    {
        totalGamesWon = stoi(tempConvertToInt);
    }
    //cout << totalGamesWon << endl;
    wholeLine = "";

    getline(fin, trash);

    getline(fin, trash);

    getline(fin, wholeLine);
    gamesPlayedColonFinder = wholeLine.find(':') + 2;
    gamesPlayedEndFinder = wholeLine.find('.');
    gamesPlayedEndFinder = gamesPlayedEndFinder - gamesPlayedColonFinder;
    //cout << gamesPlayedColonFinder << endl;
    //cout << gamesPlayedEndFinder << endl;
    tempConvertToInt = wholeLine.substr(gamesPlayedColonFinder,gamesPlayedEndFinder);
    //cout << tempConvertToInt << endl;
    if (tempConvertToInt == "nan" || tempConvertToInt == "0")
    {
        gamesPlayedWithSmartAi = gamesPlayedWithSmartAi;
    }
    else
    {
        gamesPlayedWithSmartAi = stoi(tempConvertToInt);
    }
    //cout << gamesPlayedWithSmartAi << endl;
    wholeLine = "";

    getline(fin, wholeLine);
    gamesPlayedColonFinder = wholeLine.find(':') + 2;
    //cout << gamesPlayedColonFinder << endl;
    gamesPlayedEndFinder = wholeLine.find('.');
    //cout << gamesPlayedEndFinder << endl;
    gamesPlayedEndFinder = gamesPlayedEndFinder - gamesPlayedColonFinder;
    //cout << gamesPlayedEndFinder << endl;
    tempConvertToInt = wholeLine.substr(gamesPlayedColonFinder,gamesPlayedEndFinder);
    //cout << tempConvertToInt << endl;
    if (tempConvertToInt == "nan" || tempConvertToInt == "0")
    {
        playerWinsAgainstSmartAi = playerWinsAgainstSmartAi;
    }
    else
    {
        playerWinsAgainstSmartAi = stoi(tempConvertToInt);
    }
    //cout << playerWinsAgainstSmartAi << endl;
    wholeLine = "";

    getline(fin, trash);

    getline(fin, trash);

    getline(fin, wholeLine);
    gamesPlayedColonFinder = wholeLine.find(':') + 2;
    gamesPlayedEndFinder = wholeLine.find('.');
    gamesPlayedEndFinder = gamesPlayedEndFinder - gamesPlayedColonFinder;
    //cout << gamesPlayedColonFinder << endl;
    //cout << gamesPlayedEndFinder << endl;
    tempConvertToInt = wholeLine.substr(gamesPlayedColonFinder,gamesPlayedEndFinder);
    //cout << tempConvertToInt << endl;
    if (tempConvertToInt == "nan" || tempConvertToInt == "0")
    {
        gamesPlayedWithDumbAi = gamesPlayedWithDumbAi;
    }
    else
    {
        gamesPlayedWithDumbAi = stoi(tempConvertToInt);
    }
    //cout << gamesPlayedWithDumbAi << endl;
    wholeLine = "";

    getline(fin, wholeLine);
    gamesPlayedColonFinder = wholeLine.find(':') + 2;
    //cout << gamesPlayedColonFinder << endl;
    gamesPlayedEndFinder = wholeLine.find('.');
    //cout << gamesPlayedEndFinder << endl;
    gamesPlayedEndFinder = gamesPlayedEndFinder - gamesPlayedColonFinder;
    //cout << gamesPlayedEndFinder << endl;
    tempConvertToInt = wholeLine.substr(gamesPlayedColonFinder,gamesPlayedEndFinder);
    //cout << tempConvertToInt << endl;
    if (tempConvertToInt == "nan" || tempConvertToInt == "0")
    {
        playerWinsAgainstDumbAi = playerWinsAgainstDumbAi;
    }
    else
    {
        playerWinsAgainstDumbAi = stoi(tempConvertToInt);
    }
    //cout << playerWinsAgainstDumbAi << endl;
    wholeLine = "";

    getline(cin, trash);
    
    fin.close();
}

int ticTacToeChoice()
{
    cout << "What would you like to do?" << endl;
    cout << "1) Player vs. Player" << endl;
    cout << "2) Player vs. Perfect AI" << endl;
    cout << "3) Player vs. Dumb AI" << endl;
    cout << "4) Dumb AI vs. Dumb AI" << endl;
    cout << "5) See Stats" << endl;
    int userTicTacToeChoice;
    cin >> userTicTacToeChoice;
    
    return userTicTacToeChoice;
}
void ticTacToeGameBoard(char a[][COLUMNS], int rows)
{
    //int rows = 3, columns = 3;
    //char a[rows][COLUMNS];
    int temp = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            a[i][j] = ' ';
        }
    }
}
void playerToPlayerTurn(int currentPlayer)
{
    if (currentPlayer == 1)
    {
        cout << "Player 1's turn" << endl;
    }
    else
    {
        cout << "Player 2's turn" << endl;
    }
}
void playerToAiTurn(int currentPlayer)
{
    if (currentPlayer == 1)
    {
        cout << "Player 1's turn" << endl;
    }
    else
    {
        cout << "AI's turn" << endl;
    }
}
void outputTicTacToeGameBoard(char a[][COLUMNS], int rows, int COLUMNS)
{
    for (int i = 0; i < rows; i++)
    {
        cout << "-------------" << endl;
        cout << "| ";
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << a[i][j] << " | ";
        }
        cout << endl;
    }
    cout << "-------------" << endl;
        
}
void outputTicTacToeGameBoardForSaving(char a [][COLUMNS], int rows, int COLUMNS, int currentResults)
{
    ofstream fout;
    fout.open("TICTACTOE");
    fout << "TICTACTOE" << endl;
    for (int i = 0; i < rows; i++)
    {
        fout << "-------------" << endl;
        fout << "| ";
        for (int j = 0; j < COLUMNS; j++)
        {
            fout << a[i][j] << " | ";
        }
        fout << endl;
    }
    fout << "-------------" << endl;
    if (currentResults == 1)
    {
        fout << "Player 1 Wins" << endl;
    }
    else if (currentResults == 2)
    {
        fout << "Player 1 Loses" << endl;
    }
    else 
    {
        fout << "Draw" << endl;
    }
    fout.close();
}
void inputUserSymbolForPlayerVsDumbAi(char a[][COLUMNS], int rows, int COLMUNS)
{
    bool spaceUnoccupied = true;
    string two = "2";
    int rowCoordinate, columnCoordinate;
    do
    {
        cout << "Enter a coordinate point" << endl;
        string userPlacement;
        cin >> userPlacement;
        int coordinateFinder = userPlacement.find(',');
        rowCoordinate = stoi(userPlacement.substr(0,1));
        columnCoordinate = stoi(userPlacement.substr(2));
        if(a[rowCoordinate][columnCoordinate] == 'X' || a[rowCoordinate][columnCoordinate] == 'O')
        {
            cout << "Place is already occupied," << endl << "or the input is invaild" << endl;
            spaceUnoccupied = false;
        }
        else
        {
            spaceUnoccupied = true;
        }
    }
    while (spaceUnoccupied == false);
    a[rowCoordinate][columnCoordinate] = 'X';
}
void inputUserSymbolForPlayerVsPlayer(char a[][COLUMNS], int rows, int COLMUNS, int player1)
{
    bool spaceUnoccupied = true;
    int rowCoordinate, columnCoordinate;
    do
    {
        cout << "Enter a coordinate point" << endl;
        string userPlacement;
        cin >> userPlacement;
        int coordinateFinder = userPlacement.find(',');
        rowCoordinate = stoi(userPlacement.substr(0,1));
        columnCoordinate = stoi(userPlacement.substr(2));
        if(a[rowCoordinate][columnCoordinate] == 'X' || a[rowCoordinate][columnCoordinate] == 'O')
        {
            cout << "Place is already occupied," << endl << "or the input is invaild" << endl;
            spaceUnoccupied = false;
        }
        else
        {
            spaceUnoccupied = true;
        }
    }
    while(spaceUnoccupied == false);
    if (player1 == 1)
    {
        a[rowCoordinate][columnCoordinate] = 'X';
    }
    else
    {
        a[rowCoordinate][columnCoordinate] = 'O';
    }
    
}

string userPlacement()
{
    cout << "Enter the coordinate you would like to occupy" << endl;
    string userPlacement;
    cin >> userPlacement;
    return userPlacement;
}
int player1First()
{
    int firstPlayer;
    int decider = (rand() % 2) + 1;
    if (decider == 1)
    {
        firstPlayer = 1;
    }
    else 
    {
        firstPlayer = 2;
    }
    return firstPlayer;
}
int playerSwitcher(int currentPlayer)
{
    if(currentPlayer == 1)
    {
        currentPlayer = 2;
    }
    else 
    {
        currentPlayer = 1;
    }
    return currentPlayer;
}
void beginningInstructionsForTicTacToe()
{
    cout << "To enter your symbol at a coordinate " << endl <<
            "point you must do it in the following  "
                << endl << "format, with the left-top " << endl <<
                    "most one being 0,0." << endl;
}
void allTicTacToePlayerVsPlayerFunctionality()
{
    int rows = 3, spacesLeft = 9, currentResults = 0;
    char a[rows][COLUMNS];
    int currentPlayer = player1First();
    playerToPlayerTurn(currentPlayer);
    ticTacToeGameBoard(a, rows);
    beginningInstructionsForTicTacToe();
    //cout << currentPlayer << " goes first" << endl;
    while(spacesLeft > 0)
    {
        currentResults = winDeterminer(a, rows);
        if(currentResults == 1)
        {
            cout << "Player 1 wins" << endl;
            outputTicTacToeGameBoard(a, rows, COLUMNS);
            spacesLeft = 0;
        }
        else if(currentResults == 2)
        {
            cout << "Player 2 wins" << endl;
            outputTicTacToeGameBoard(a, rows, COLUMNS);
            spacesLeft = 0;
        }
        else if(spacesLeft == 0)
        {
            cout << "Draw" << endl;
            outputTicTacToeGameBoard(a, rows, COLUMNS);
        }
        else 
        {
            playerSwitcher(currentPlayer);
            outputTicTacToeGameBoard(a, rows, COLUMNS);
            inputUserSymbolForPlayerVsPlayer(a, rows, COLUMNS, currentPlayer);
            
            if(currentPlayer == 1)
                {
                    currentPlayer = 2;
                }
            else
                {
                    currentPlayer = 1;
                }
            spacesLeft--;
        }
    }
    string userWantsToSave;
    cout << "Do you want to save this game?Y/N" << endl;
    cin >> userWantsToSave;
    if (tolower(userWantsToSave[0])== 'y')
    {
        outputTicTacToeGameBoardForSaving(a, rows, COLUMNS, currentResults);
    }
}
int winDeterminer(char array[][COLUMNS], int rows)
{
    int player1Won = 0, player2Won = 0;
    for (int a = 0; a < rows; a++)
    {
        if (array[a][0] == 'X' && array[a][1] == 'X' && array[a][2] == 'X')
        {
            player1Won = 1;
        }
        else if (array[a][0] == 'O' && array[a][1] == 'O' && array[a][2] == 'O')
        {
            player2Won = 2;
        }
    }
    for (int c = 0; c < COLUMNS; c++)
    {
        if (array[0][c] == 'X' && array[1][c] == 'X' && array[2][c] == 'X')
        {
            player1Won = 1;
        }
        else if (array[0][c] == 'O' && array[1][c] == 'O' && array[2][c] == 'O')
        {
            player2Won = 2;
        }
    }
    for (int d = 0; d < rows; d++)
    {
        if (array[0][0] == 'X' && array[1][1] == 'X' && array[2][2] == 'X')
        {
            player1Won = 1;
        }
        else if (array[0][0] == 'O' && array[1][1] == 'O' && array[2][2] == 'O')
        {
            player2Won = 2;
        }
    }
    for (int g = 0; g < rows; g++)
    {
        if (array[0][2] == 'X' && array[1][1] == 'X' && array[2][0] == 'X')
        {
            player1Won = 1;
        }
        else if (array[0][2] == 'O' && array[1][1] == 'O' && array[2][0] == 'O')
        {
            player2Won = 2;
        }
    }
    if (player1Won == 1)
    {
        return player1Won;
    }
    if (player2Won == 2)
    {
        return player2Won;
    }
    return 0;
}
void allFunctionallityForPlayerVsPerfectAI(double &gamesPlayedAgainstSmartAi, double &gamesWonAgainstSmartAi, double &totalGamesPlayed, double &totalGamesWon)
{
    int rows = 3, spacesLeft = 9, spacesLeftForDraw = 9, currentResults = 0;
    int rowCoordinate = 0, columnCoordinate = 0;
    char array[rows][COLUMNS];
    int currentPlayer = player1First();
    ticTacToeGameBoard(array, rows);
    beginningInstructionsForTicTacToe();
    outputTicTacToeGameBoard(array, rows, COLUMNS);
    while(spacesLeft > 0)
    {
        currentResults = winDeterminer(array, rows);
        if(currentResults == 1)
        {
            cout << "Player 1 wins" << endl;
            outputTicTacToeGameBoard(array, rows, COLUMNS);
            gamesWonAgainstSmartAi++;
            totalGamesWon = totalGamesWon + 1;
            spacesLeft = 0;
        }
        else if(currentResults == 2)
        {
            cout << "AI wins" << endl;
            outputTicTacToeGameBoard(array, rows, COLUMNS);
            spacesLeft = 0;
        }
        else if(currentPlayer == 2 && spacesLeft == 1)
        {
            randomInput(array, rows, rowCoordinate, columnCoordinate);
            array[rowCoordinate][columnCoordinate] = 'O';
            outputTicTacToeGameBoard(array, rows, COLUMNS);
        }
        else if(currentPlayer == 2)
        {
            //playerSwitcher(currentPlayer);
            inputSmartAiSymbol(array, rows, rowCoordinate, columnCoordinate);
            array[rowCoordinate][columnCoordinate] = 'O';
            outputTicTacToeGameBoard(array, rows, COLUMNS);
        }
        else
        {
            inputUserSymbolForPlayerVsPlayer(array, rows, COLUMNS, currentPlayer);
            outputTicTacToeGameBoard(array, rows, COLUMNS);
        }
        currentPlayer = playerSwitcher(currentPlayer);
        spacesLeft--;
        spacesLeftForDraw--;
    }
    if (spacesLeftForDraw == 0)
    {
        cout << "Draw" << endl;
        outputTicTacToeGameBoard(array, rows, COLUMNS);
    }
    string userWantsToSave;
    cout << "Do you want to save this game?Y/N" << endl;
    cin >> userWantsToSave;
    if (tolower(userWantsToSave[0])== 'y')
    {
        outputTicTacToeGameBoardForSaving(array, rows, COLUMNS, currentResults);
    }

    gamesPlayedAgainstSmartAi++;
    totalGamesPlayed = totalGamesPlayed + 1;
}
int playerToSmartAi(int currentPlayer)
{
    if (currentPlayer == 1)
    {
        cout << "Player 1's turn" << endl;
    }
    else
    {
        cout << "AI's turn" << endl;
    }
}
void smartAiChecksForLossPossibility(char array[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate)
{
    //row check for loss
    for (int r = 0; r < 3; r++)
    {
        if (array[r][0] == 'X')
        {
            if (array[r][1] == 'X' && array[r][2] == ' ')
            {
                rowCoordinate = r;
                columnCoordinate = 2;
            }
            else if (array[r][2] == 'X' && array[r][1] == ' ')
            {
                rowCoordinate = r;
                columnCoordinate = 1;
            }
            else
            {
                rowCoordinate = rowCoordinate;
                columnCoordinate = columnCoordinate;
            }
        }
        else if(array[r][1] == 'X')
        {
            if (array[r][2] == 'X' && array[r][0] == ' ')
            {
                rowCoordinate = r;
                columnCoordinate = 0;
            }
            else if (array[r][0] == 'X' && array[r][2] == ' ')
            {
                rowCoordinate = r;
                columnCoordinate = 2;
            }
            else
            {
                rowCoordinate = rowCoordinate;
                columnCoordinate = columnCoordinate;
            }
        }
        else if(array[r][2] == 'X')
        {
            if (array[r][1] == 'X' && array[r][0] == ' ')
            {
                rowCoordinate = r;
                columnCoordinate = 0;
            }
            else if (array[r][0] == 'X' && array[r][1] == ' ')
            {
                rowCoordinate = r;
                columnCoordinate = 1;
            }
            else
            {
                rowCoordinate = rowCoordinate;
                columnCoordinate = columnCoordinate;
            }
        }
    }
    //Column check for loss 
    for (int c = 0; c < 3; c++)
    {
        if (array[0][c] == 'X')
        {
            if (array[1][c] == 'X' && array[2][c] == ' ')
            {
                rowCoordinate = 2;
                columnCoordinate = c;
            }
            else if (array[2][c] == 'X' && array[1][c] == ' ')
            {
                rowCoordinate = 1;
                columnCoordinate = c;
            }
            else
            {
                rowCoordinate = rowCoordinate;
                columnCoordinate = columnCoordinate;
            }
        }
        else if(array[1][c] == 'X')
        {
            if (array[2][c] == 'X' && array[0][c] == ' ')
            {
                rowCoordinate = 0;
                columnCoordinate = c;
            }
            else if (array[0][c] == 'X' && array[2][c] == ' ')
            {
                rowCoordinate = 2;
                columnCoordinate = c;
            }
            else
            {
                rowCoordinate = rowCoordinate;
                columnCoordinate = columnCoordinate;
            }
        }
        else if(array[2][c] == 'X')
        {
            if (array[1][c] == 'X' && array[0][c] == ' ')
            {
                rowCoordinate = 0;
                columnCoordinate = c;
            }
            else if (array[0][c] == 'X' && array[1][c] == ' ')
            {
                rowCoordinate = 1;
                columnCoordinate = c;
            }
            else
            {
                rowCoordinate = rowCoordinate;
                columnCoordinate = columnCoordinate;
            }
        }
    }
    
    //Left to right diagonal check for loss
    if (array[0][0] == 'X')
    {
        if (array[1][1] == 'X' && array[2][2] == ' ')
        {
            rowCoordinate = 2;
            columnCoordinate = 2;
        }
        else if (array[2][2] == 'X' && array[1][1] == ' ')
        {
            rowCoordinate = 1;
            columnCoordinate = 1;
        }
        else
        {
            rowCoordinate = rowCoordinate;
            columnCoordinate = columnCoordinate;
        }
    }
    else if(array[1][1] == 'X')
    {
        if (array[2][2] == 'X' && array[0][0] == ' ')
        {
            rowCoordinate = 0;
            columnCoordinate = 0;
        }
        else if (array[0][0] == 'X' && array[2][2] == ' ')
        {
            rowCoordinate = 2;
            columnCoordinate = 2;
        }
        else
        {
            rowCoordinate = rowCoordinate;
            columnCoordinate = columnCoordinate;
        }
    }
    else if(array[2][2] == 'X')
    {
        if (array[1][1] == 'X' && array[0][0] == ' ')
        {
            rowCoordinate = 0;
            columnCoordinate = 0;
        }
        else if (array[0][0] == 'X' && array[1][1] == ' ')
        {
            rowCoordinate = 1;
            columnCoordinate = 1;
        }
        else
        {
            rowCoordinate = rowCoordinate;
            columnCoordinate = columnCoordinate;
        }
    }
    //Right to left diagonal check for loss
    if (array[0][2] == 'X')
    {
        if (array[1][1] == 'X' && array[2][0] == ' ')
        {
            rowCoordinate = 2;
            columnCoordinate = 0;
        }
        else if (array[2][0] == 'X' && array[1][1] == ' ')
        {
            rowCoordinate = 1;
            columnCoordinate = 1;
        }
        else
        {
            rowCoordinate = rowCoordinate;
            columnCoordinate = columnCoordinate;
        }
    }
    else if(array[1][1] == 'X')
    {
        if (array[2][0] == 'X' && array[0][2] == ' ')
        {
            rowCoordinate = 0;
            columnCoordinate = 2;
        }
        else if (array[0][2] == 'X' && array[2][0] == ' ')
        {
            rowCoordinate = 2;
            columnCoordinate = 0;
        }
        else
        {
            rowCoordinate = rowCoordinate;
            columnCoordinate = columnCoordinate;
        }
    }
    else if(array[2][0] == 'X')
    {
        if (array[1][1] == 'X' && array[0][2] == ' ')
        {
            rowCoordinate = 0;
            columnCoordinate = 2;
        }
        else if (array[0][2] == 'X' && array[1][1] == ' ')
        {
            rowCoordinate = 1;
            columnCoordinate = 1;
        }
        else
        {
            rowCoordinate = rowCoordinate;
            columnCoordinate = columnCoordinate;
        }
    }
}
void smartAiChecksForWinPossibility(char array[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate)
{
    //row check for win
    for (int r = 0; r < 3; r++)
    {
        if (array[r][0] == 'O')
        {
            if (array[r][1] == 'O' && array[r][2] == ' ')
            {
                rowCoordinate = r;
                columnCoordinate = 2;
            }
            else if (array[r][2] == 'O' && array[r][1] == ' ')
            {
                rowCoordinate = r;
                columnCoordinate = 1;
            }
            else
            {
                rowCoordinate = rowCoordinate;
                columnCoordinate = columnCoordinate;
            }
        }
        else if(array[r][1] == 'O')
        {
            if (array[r][2] == 'O' && array[r][0] == ' ')
            {
                rowCoordinate = r;
                columnCoordinate = 0;
            }
            else if (array[r][0] == 'O' && array[r][2] == ' ')
            {
                rowCoordinate = r;
                columnCoordinate = 2;
            }
            else
            {
                rowCoordinate = rowCoordinate;
                columnCoordinate = columnCoordinate;
            }
        }
        else if(array[r][2] == 'O')
        {
            if (array[r][1] == 'O' && array[r][0] == ' ')
            {
                rowCoordinate = r;
                columnCoordinate = 0;
            }
            else if (array[r][0] == 'O' && array[r][1] == ' ')
            {
                rowCoordinate = r;
                columnCoordinate = 1;
            }
            else
            {
                rowCoordinate = rowCoordinate;
                columnCoordinate = columnCoordinate;
            }
        }
    }
    //Column check for win 
    for (int c = 0; c < 3; c++)
    {
        if (array[0][c] == 'O')
        {
            if (array[1][c] == 'O' && array[2][c] == ' ')
            {
                rowCoordinate = 2;
                columnCoordinate = c;
            }
            else if (array[2][c] == 'O' && array[1][c] == ' ')
            {
                rowCoordinate = 1;
                columnCoordinate = c;
            }
            else
            {
                rowCoordinate = rowCoordinate;
                columnCoordinate = columnCoordinate;
            }
        }
        else if(array[1][c] == 'O')
        {
            if (array[2][c] == 'O' && array[0][c] == ' ')
            {
                rowCoordinate = 0;
                columnCoordinate = c;
            }
            else if (array[0][c] == 'O' && array[2][c] == ' ')
            {
                rowCoordinate = 2;
                columnCoordinate = c;
            }
            else
            {
                rowCoordinate = rowCoordinate;
                columnCoordinate = columnCoordinate;
            }
        }
        else if(array[2][c] == 'O')
        {
            if (array[1][c] == 'O' && array[0][c] == ' ')
            {
                rowCoordinate = 0;
                columnCoordinate = c;
            }
            else if (array[0][c] == 'O' && array[1][c] == ' ')
            {
                rowCoordinate = 1;
                columnCoordinate = c;
            }
            else
            {
                rowCoordinate = rowCoordinate;
                columnCoordinate = columnCoordinate;
            }
        }
    }
    //Left to right diagonal check for win
    if (array[0][0] == 'O')
    {
        if (array[1][1] == 'O' && array[2][2] == ' ')
        {
            rowCoordinate = 2;
            columnCoordinate = 2;
        }
        else if (array[2][2] == 'O' && array[1][1] == ' ')
        {
            rowCoordinate = 1;
            columnCoordinate = 1;
        }
        else
        {
            rowCoordinate = rowCoordinate;
            columnCoordinate = columnCoordinate;
        }
    }
    else if(array[1][1] == 'O')
    {
        if (array[2][2] == 'O' && array[0][0] == ' ')
        {
            rowCoordinate = 0;
            columnCoordinate = 0;
        }
        else if (array[0][0] == 'O' && array[2][2] == ' ')
        {
            rowCoordinate = 2;
            columnCoordinate = 2;
        }
        else
        {
            rowCoordinate = rowCoordinate;
            columnCoordinate = columnCoordinate;
        }
    }
    else if(array[2][2] == 'O')
    {
        if (array[1][1] == 'O' && array[0][0] == ' ')
        {
            rowCoordinate = 0;
            columnCoordinate = 0;
        }
        else if (array[0][0] == 'O' && array[1][1] == ' ')
        {
            rowCoordinate = 1;
            columnCoordinate = 1;
        }
        else
        {
            rowCoordinate = rowCoordinate;
            columnCoordinate = columnCoordinate;
        }
    }
    //Right to left diagonal check for win
    if (array[0][2] == 'O')
    {
        if (array[1][1] == 'O' && array[2][0] == ' ')
        {
            rowCoordinate = 2;
            columnCoordinate = 0;
        }
        else if (array[2][0] == 'O' && array[1][1] == ' ')
        {
            rowCoordinate = 1;
            columnCoordinate = 1;
        }
        else
        {
            rowCoordinate = rowCoordinate;
            columnCoordinate = columnCoordinate;
        }
    }
    else if(array[1][1] == 'O')
    {
        if (array[2][0] == 'O' && array[0][2] == ' ')
        {
            rowCoordinate = 0;
            columnCoordinate = 2;
        }
        else if (array[0][2] == 'O' && array[2][0] == ' ')
        {
            rowCoordinate = 2;
            columnCoordinate = 0;
        }
        else
        {
            rowCoordinate = rowCoordinate;
            columnCoordinate = columnCoordinate;
        }
    }
    else if(array[2][0] == 'O')
    {
        if (array[1][1] == 'O' && array[0][2] == ' ')
        {
            rowCoordinate = 0;
            columnCoordinate = 2;
        }
        else if (array[0][2] == 'O' && array[1][1] == ' ')
        {
            rowCoordinate = 1;
            columnCoordinate = 1;
        }
        else
        {
            rowCoordinate = rowCoordinate;
            columnCoordinate = columnCoordinate;
        }
    }
}
void firstAiMove(char array[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate)
{
    if (array[1][1] == ' ')
    {
        rowCoordinate = 1;
        columnCoordinate = 1;
    }
    else if(array[0][0] != 'O' && array[0][0] != 'X')
    {
        rowCoordinate = 0;
        columnCoordinate = 0;
    }
    else if (array[2][2] == ' ')
    {
        rowCoordinate = 2;
        columnCoordinate = 2;
    }
    else 
    {
        rowCoordinate = rowCoordinate;
        columnCoordinate = columnCoordinate;
    }
}
void possibleFork(char array[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate)
{
    if (array[0][0] == 'O' && array[2][2] == ' ')
    {
        rowCoordinate = 2;
        columnCoordinate = 2;
    }
    else if (array[2][2] == 'O' && array[0][0] == ' ')
    {
        rowCoordinate = 0;
        columnCoordinate = 0;
    }
    else
    {
        rowCoordinate = rowCoordinate;
        columnCoordinate = columnCoordinate;
    }
}
void blockPossibleFork(char array[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate)
{
    if (array[0][0] == 'X' && array[2][2] == ' ')
    {
        rowCoordinate = 2;
        columnCoordinate = 2;
    }
    else if (array[2][2] == 'X' && array[0][0] == ' ')
    {
        rowCoordinate = 0;
        columnCoordinate = 0;
    }
    else if (array[0][2] == 'X' && array[2][0] == ' ')
    {
        rowCoordinate = 2;
        columnCoordinate = 0;
    }
    else if (array[2][0] == 'X' && array[0][2] == ' ')
    {
        rowCoordinate = 0;
        columnCoordinate = 2;
    }
    
}
void randomInput(char a[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate)
{
    do
    {
        rowCoordinate = (rand() % 3);
        columnCoordinate = (rand() % 3);
    }
    while(a[rowCoordinate][columnCoordinate] != ' ');
}
void inputSmartAiSymbol(char a[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate)
{
    randomInput(a, rows, rowCoordinate, columnCoordinate);
    possibleFork(a, rows, rowCoordinate, columnCoordinate);
    blockPossibleFork(a, rows, rowCoordinate, columnCoordinate);
    firstAiMove(a, rows, rowCoordinate, columnCoordinate);
    smartAiChecksForLossPossibility(a, rows, rowCoordinate, columnCoordinate);
    smartAiChecksForWinPossibility(a, rows, rowCoordinate, columnCoordinate);
}
void allFunctionallityForPlayerVsDumbAi(double &gamesPlayedAgainstDumbAi, double &gamesWonAgainstDumbAi, double &totalGamesPlayed, double &totalGamesWon)
{
    gamesPlayedAgainstDumbAi++;
    totalGamesPlayed = totalGamesPlayed + 1;
    int rows = 3, spacesLeft = 9, spacesLeftForDraw = 9, currentResults = 0;
    int rowCoordinate = 0, columnCoordinate = 0;
    char array[rows][COLUMNS];
    int currentPlayer = player1First();
    ticTacToeGameBoard(array, rows);
    beginningInstructionsForTicTacToe();
    outputTicTacToeGameBoard(array, rows, COLUMNS);
    while(spacesLeft > 0)
    {
        currentResults = winDeterminer(array, rows);
        if(currentResults == 1)
        {
            cout << "Player 1 wins" << endl;
            outputTicTacToeGameBoard(array, rows, COLUMNS);
            spacesLeft = 0;
        }
        else if(currentResults == 2)
        {
            cout << "AI wins" << endl;
            outputTicTacToeGameBoard(array, rows, COLUMNS);
            spacesLeft = 0;
        }
        else if(currentPlayer == 2)
        {
            //playerSwitcher(currentPlayer);
            randomInput(array, rows, rowCoordinate, columnCoordinate);
            array[rowCoordinate][columnCoordinate] = 'O';
            outputTicTacToeGameBoard(array, rows, COLUMNS);
        }
        else
        {
            inputUserSymbolForPlayerVsDumbAi(array, rows, COLUMNS);
            outputTicTacToeGameBoard(array, rows, COLUMNS);
        }
        currentPlayer = playerSwitcher(currentPlayer);
        spacesLeft--;
        spacesLeftForDraw--;
    }
    
    currentResults = winDeterminer(array, rows);
    if(currentResults == 1)
    {
        cout << "You Win!" << endl;
        gamesWonAgainstDumbAi++;
        totalGamesWon = totalGamesWon + 1;
    }
    else if(currentResults == 2)
    {
        cout << "You Lose!" << endl;
    }
    else if (spacesLeftForDraw == 0 && currentResults != 1 && currentResults != 2)
    {
        cout << "Draw" << endl;
        outputTicTacToeGameBoard(array, rows, COLUMNS);
    }
    string userWantsToSave;
    cout << "Do you want to save this game?Y/N" << endl;
    cin >> userWantsToSave;
    if (tolower(userWantsToSave[0])== 'y')
    {
        outputTicTacToeGameBoardForSaving(array, rows, COLUMNS, currentResults);
    }
}
void allFunctionallityForDumbAiVsDumbAi()
{
    int rows = 3, spacesLeft = 9, spacesLeftForDraw = 9, currentResults = 0;
    int rowCoordinate = 0, columnCoordinate = 0;
    char array[rows][COLUMNS];
    int currentPlayer = player1First();
    ticTacToeGameBoard(array, rows);
    beginningInstructionsForTicTacToe();
    outputTicTacToeGameBoard(array, rows, COLUMNS);
    while(spacesLeft > 0)
    {
        currentResults = winDeterminer(array, rows);
        if(currentResults == 1)
        {
            cout << "AI 1 wins" << endl;
            outputTicTacToeGameBoard(array, rows, COLUMNS);
            spacesLeft = 0;
        }
        else if(currentResults == 2)
        {
            cout << "AI 2 wins" << endl;
            outputTicTacToeGameBoard(array, rows, COLUMNS);
            spacesLeft = 0;
        }
        else if(currentPlayer == 2)
        {
            //playerSwitcher(currentPlayer);
            randomInput(array, rows, rowCoordinate, columnCoordinate);
            array[rowCoordinate][columnCoordinate] = 'O';
            outputTicTacToeGameBoard(array, rows, COLUMNS);
        }
        else
        {
            randomInput(array, rows, rowCoordinate, columnCoordinate);
            array[rowCoordinate][columnCoordinate] = 'X';
            outputTicTacToeGameBoard(array, rows, COLUMNS);
        }
        currentPlayer = playerSwitcher(currentPlayer);
        spacesLeft--;
        spacesLeftForDraw--;
    }
    currentResults = winDeterminer(array, rows);
    if(currentResults == 1)
    {
        cout << "AI Number 1 Wins!" << endl;
    }
    else if(currentResults == 2)
    {
        cout << "AI Number 2 Wins!" << endl;
    }
    else if (spacesLeftForDraw == 0 && currentResults != 1 && currentResults != 2)
    {
        cout << "Draw" << endl;
        outputTicTacToeGameBoard(array, rows, COLUMNS);
    }
    string userWantsToSave;
    cout << "Do you want to save this game?Y/N" << endl;
    cin >> userWantsToSave;
    if (tolower(userWantsToSave[0])== 'y')
    {
        outputTicTacToeGameBoardForSaving(array, rows, COLUMNS, currentResults);
    }
}