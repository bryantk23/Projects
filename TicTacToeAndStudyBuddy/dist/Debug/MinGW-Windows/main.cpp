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
bool errorCheckingForTicTacToe(string userCoordinate, char array[][COLUMNS], int rows);

void allFunctionalityForStudyApp(vector<vector<string>>& allSets);
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
/**
 * This function contains all functions and logic, including a switch case of
 * all possible things (programs), to do within the FlashCard application. This 
 * function also takes an empty 2D vector that will be manipulated
 * @param allSets This is an empty 2D vector that will be manipulated to accomplish
 * various goals (adding to, deleting from, etc)
 */
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
/**
 * This function takes the name of a file, and then deletes the entire file
 * using the remove() member operator/function
 * @param fileName This is the name of the file
 */
void deleteAWholeSet(const string& fileName)
{
    remove(fileName.c_str());
}
/**
 * This function outputs the questions that may be inside any vector provided, 
 * assuming they follow the format
 * @param v This is the vector that will be outputted
 * @param numberOfQuestionSets This is the number of questions that will be
 * outputted. In other words, its the number of times the for-loop for
 * outputting will be run
 */
void outputVector(const vector<string>& v, int numberOfQuestionSets)
{
    for (int i = 0; i < numberOfQuestionSets; i++)
    {
        cout << v[i] << endl;
    }
}
/**
 * This function takes and changes the number of questions within a specific
 * study set by creating a new study set with an initial question and answer,
 * that will be provided by the user.
 * @param numberOfQuestionSets This is the number of questions that are within
 * each study set
 */
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
/**
 * This function reads in a file, that has questions and answers, given by the
 * user. Then this function outputs the questions back to the user, and compares
 * the answer they input to the actual answer that was read in from the file.
 */
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
/**
 * This function adds new questions and answers to a vector (study set), while 
 * also changing the number of questions variable of the study set
 * @param v This is the study set that is being added to
 * @param numberOfQuestionSets This is the number of questions within a specific set
 */
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
/**
 * This function outputs all of the elements within a vector
 * @param allSets This is the vector that is to be outputted
 */
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
/**
 * This function takes the name of the file that is to be added to. Then
 * the file is read into a vector, to be changed later
 */
void inputMoreToASet()
{
    cout << "What is the name of set you would like to add to" << endl;
    string nameOfSet;
    vector<string> v;
    fstream fin;
    cin >> nameOfSet;
    fin.open(nameOfSet);
}
/**
 * This function takes the name of the set to be changed, checks to see if
 * the file/set exists. Then, at least, a question and answer are provided 
 * by the user. Finally the set is outputted/saved to a file
 * @param numOfQuestions This is the number of questions that the set has, and
 * changes according to how many questions are added
 */
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
        
        cout << "Enter the answer" << endl;
        getline(cin, tempAnswer);
        
        changes.push_back(tempQuestion);
        changes.push_back(tempAnswer);
        tempQuestion = "";
        tempAnswer = "";
        numOfQuestions = numOfQuestions + 2;
        
        cout << "Would you like to continue adding elements?Y/N" << endl;
        getline(cin, userCont);
    }
    while(tolower(userCont[0])== 'y');
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
    fout.close();
}
/**
 * This function asks the user for a file name to be changed, then error checks it.
 * Then it outputs the possible questions to be deleted, and asks the user for what
 * they want to delete. If the question to be deleted is not valid, the user is prompted
 * to enter another question to be deleted.
 */
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
/**
 * This function error checks the coordinate inputted by user during a TicTacToe
 * game. Returns whether or not the user has inputted in the proper format
 * @param userCoordinate This is the coordinate that the user wants to occupy
 * @param array This is the TicTacToe game/array that is to be checked for a valid
 * location
 * @param rows This is the number of rows or array size in the initial array
 * @return Returns true if the correct bounds and format for a coordinate 
 * has been inputted
 */
bool errorCheckingForTicTacToe(string userCoordinate, char array[][COLUMNS], int rows)
{
    bool isValid = false;
    string coordinate;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            coordinate = to_string(i) + "," + to_string(j);
            if (coordinate == userCoordinate)
            {
                isValid = true;
            }
        }
    }
    return isValid;
}
/**
 * This function saves a TicTacToe game results to a file
 * @param a This is the TicTacToe game/array to be saved to a file
 * @param rows This is the size of the inner/row arrays
 */
void savingTicTacToeGame(char a[][COLUMNS], int rows)
{
    ofstream fout;
    fout.open("TICTACTOE");
    
}
/**
 * This function modifies and saves the stats of the user's TicTacToe games that have
 * been played by outputting to a file.
 * @param totalGamesPlayed This is the total amount of games the user played
 * @param totalGamesWon This is the total amount of games won by the user
 * @param playerWinsAgainstSmartAi This is the total amount of games won against the smart AI
 * @param gamesPlayedWithSmartAi This is the total amount of games played against smart AI
 * @param playerWinsAgainstDumbAi This is the total amount of games won against the dumb AI
 * @param gamesPlayedWithDumbAi This is the total amount of games played against dumb AI
 */
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
/**
 * This function outputs the user's stats concerning the games that the user has played
 * to the console.
 * @param totalGamesPlayed This is the total amount of games the user played
 * @param totalGamesWon This is the total amount of games won by the user
 * @param playerWinsAgainstSmartAi This is the total amount of games won against the smart AI
 * @param gamesPlayedWithSmartAi This is the total amount of games played against smart AI
 * @param playerWinsAgainstDumbAi This is the total amount of games won against the dumb AI
 * @param gamesPlayedWithDumbAi This is the total amount of games played against dumb AI
 */
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
/**
 * This function loads in the stats of the user's TicTacToe games that have
 * played into various variables.
 * @param totalGamesPlayed This is the total amount of games the user played
 * @param totalGamesWon This is the total amount of games won by the user
 * @param playerWinsAgainstSmartAi This is the total amount of games won against the smart AI
 * @param gamesPlayedWithSmartAi This is the total amount of games played against smart AI
 * @param playerWinsAgainstDumbAi This is the total amount of games won against the dumb AI
 * @param gamesPlayedWithDumbAi This is the total amount of games played against dumb AI
 */
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
    getline(fin, wholeLine);
    gamesPlayedColonFinder = wholeLine.find(':') + 2;
    gamesPlayedEndFinder = wholeLine.find('.');
    gamesPlayedEndFinder = gamesPlayedEndFinder - gamesPlayedColonFinder;
    tempConvertToInt = wholeLine.substr(gamesPlayedColonFinder,gamesPlayedEndFinder);
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
    gamesPlayedEndFinder = wholeLine.find('.');
    gamesPlayedEndFinder = gamesPlayedEndFinder - gamesPlayedColonFinder;
    tempConvertToInt = wholeLine.substr(gamesPlayedColonFinder,gamesPlayedEndFinder);
    if (tempConvertToInt == "nan" || tempConvertToInt == "0")
    {
        totalGamesWon = totalGamesWon;
    }
    else
    {
        totalGamesWon = stoi(tempConvertToInt);
    }
    wholeLine = "";

    getline(fin, trash);

    getline(fin, trash);

    getline(fin, wholeLine);
    gamesPlayedColonFinder = wholeLine.find(':') + 2;
    gamesPlayedEndFinder = wholeLine.find('.');
    gamesPlayedEndFinder = gamesPlayedEndFinder - gamesPlayedColonFinder;
    tempConvertToInt = wholeLine.substr(gamesPlayedColonFinder,gamesPlayedEndFinder);
    if (tempConvertToInt == "nan" || tempConvertToInt == "0")
    {
        gamesPlayedWithSmartAi = gamesPlayedWithSmartAi;
    }
    else
    {
        gamesPlayedWithSmartAi = stoi(tempConvertToInt);
    }
    wholeLine = "";

    getline(fin, wholeLine);
    gamesPlayedColonFinder = wholeLine.find(':') + 2;
    gamesPlayedEndFinder = wholeLine.find('.');
    gamesPlayedEndFinder = gamesPlayedEndFinder - gamesPlayedColonFinder;
    tempConvertToInt = wholeLine.substr(gamesPlayedColonFinder,gamesPlayedEndFinder);
    if (tempConvertToInt == "nan" || tempConvertToInt == "0")
    {
        playerWinsAgainstSmartAi = playerWinsAgainstSmartAi;
    }
    else
    {
        playerWinsAgainstSmartAi = stoi(tempConvertToInt);
    }

    wholeLine = "";

    getline(fin, trash);

    getline(fin, trash);

    getline(fin, wholeLine);
    gamesPlayedColonFinder = wholeLine.find(':') + 2;
    gamesPlayedEndFinder = wholeLine.find('.');
    gamesPlayedEndFinder = gamesPlayedEndFinder - gamesPlayedColonFinder;
    tempConvertToInt = wholeLine.substr(gamesPlayedColonFinder,gamesPlayedEndFinder);
    if (tempConvertToInt == "nan" || tempConvertToInt == "0")
    {
        gamesPlayedWithDumbAi = gamesPlayedWithDumbAi;
    }
    else
    {
        gamesPlayedWithDumbAi = stoi(tempConvertToInt);
    }
    wholeLine = "";

    getline(fin, wholeLine);
    gamesPlayedColonFinder = wholeLine.find(':') + 2;
    gamesPlayedEndFinder = wholeLine.find('.');
    gamesPlayedEndFinder = gamesPlayedEndFinder - gamesPlayedColonFinder;
    tempConvertToInt = wholeLine.substr(gamesPlayedColonFinder,gamesPlayedEndFinder);
    if (tempConvertToInt == "nan" || tempConvertToInt == "0")
    {
        playerWinsAgainstDumbAi = playerWinsAgainstDumbAi;
    }
    else
    {
        playerWinsAgainstDumbAi = stoi(tempConvertToInt);
    }
    wholeLine = "";

    getline(cin, trash);
    
    fin.close();
}
/**
 * This function contains the switch case of choices that the user has when they
 * choose to play TicTacToe.
 * @return Returns the number choice that the user wants to play. For ex 5 to see
 * their stats
 */
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
/**
 * This function outputs the two dimensional array containing the TicTacToe
 * board game
 * @param a This is the two dimensional array being outputted, specifically this
 * is the TicTacToe board game elements
 * @param rows This is the size of the inner arrays within the initial array
 */
void ticTacToeGameBoard(char a[][COLUMNS], int rows)
{
    int temp = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            a[i][j] = ' ';
        }
    }
}
/**
 * This function outputs the player's turn, between player 1 and 2 based
 * on who the current player is
 * @param currentPlayer This is the player who is currently playing. Specifically,
 * the number 1 is for player 1, while number 2 is for the second player (whether
 * that be AI or another player)
 */
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
/**
 * This function outputs the player's turn between player 1, and the AI opponent
 * @param currentPlayer This is who is currently playing
 */
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
/**
 * This function outputs the game format of the TicTacToe game (being the dashed lines
 * and vertical dashes) and the elements within the TicTacToe 2D array
 * @param a This is the TicTacToe array that holds all moves (elements)
 * @param rows This is the size of each inner array
 * @param COLUMNS This is the size of the initial column
 */
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
/**
 * This function outputs the TicTacToe game board after the game is finished, to 
 * a file that gets rewritten whenever another game gets saved
 * @param a This is the TicTacToe array, that holds the game's moves (elements)
 * @param rows This is the size of the horizontal elements within the array
 * @param COLUMNS This is the size of the vertical elements within the array
 * @param currentResults This represents whether or not a player has won
 */
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
/**
 * This function asks the user for a place to occupy, and uses error checking to 
 * determine if the location is valid. If so, then their symbol gets inserted into
 * the array. This function is also used when the player goes against the dumb AI
 * @param a This is the TicTacToe game array that's being modified
 * @param rows This is the size of the horizontal elements within the array
 * @param COLMUNS This is the size of the vertical elements within the array
 */
void inputUserSymbolForPlayerVsDumbAi(char a[][COLUMNS], int rows, int COLMUNS)
{
    bool isValid = false;
    bool spaceUnoccupied = true;
    int rowCoordinate, columnCoordinate;
    string userPlacement;
    do
    {
        do
        {
            cout << "Enter a coordinate point" << endl;
            cin >> userPlacement;
            isValid = errorCheckingForTicTacToe(userPlacement, a, rows);
        }
        while (!isValid);
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
/**
 * This function asks the user for a place to occupy, and uses error checking to 
 * determine if the location is valid. If so, then their symbol gets inserted into
 * the array. This function is also used when the player goes against another player
 * @param a This is the TicTacToe array game being modified
 * @param rows This is the size of the horizontal elements within the array
 * @param COLUMNS This is the size of the vertical elements within the array
 * @param player1 This represents who is currently playing
 */
void inputUserSymbolForPlayerVsPlayer(char a[][COLUMNS], int rows, int COLUMNS, int player1)
{
    bool isValid;
    string userPlacement;
    bool spaceUnoccupied = true;
    int rowCoordinate, columnCoordinate;
    do
    {
        do
        {
            cout << "Enter a coordinate point" << endl;
            cin >> userPlacement;
            isValid = errorCheckingForTicTacToe(userPlacement, a, rows);
        }
        while (!isValid);
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
/**
 * This function asks the user for a coordinate to occupy, and then it returns 
 * it back to the user
 * @return Returns the Coordinate point.
 */
string userPlacement()
{
    cout << "Enter the coordinate you would like to occupy" << endl;
    string userPlacement;
    cin >> userPlacement;
    return userPlacement;
}
/**
 * This function determines who the first player is. If the decider is 
 * number 1, then the first player goes. 
 * @return Returns which player will go first
 */
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
/**
 * This function switches who the current player is. If the current player is 1,
 * then after the function is run, the new current player is player 2. This is 
 * also true vice versa.
 * @param currentPlayer This is who is currently the player
 * @return Returns the changes made to the current player
 */
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
/**
 * This function prints out the instructions for TicTacToe
 */
void beginningInstructionsForTicTacToe()
{
    cout << "To enter your symbol at a coordinate " << endl <<
            "point you must do it in the following  "
                << endl << "format, with the left-top " << endl <<
                    "most one being 0,0." << endl;
}
/**
 * This function contains all functionality for the player vs player version of
 * the TicTacToe entire program. Initially, the results (whether or not someone
 * has won) are checked. Then the player is switched, and the user or AI enters
 * a place to occupy. After all of the spaces are occupied the user is prompted 
 * to save the game.
 */
void allTicTacToePlayerVsPlayerFunctionality()
{
    int rows = 3, spacesLeft = 9, currentResults = 0;
    char a[rows][COLUMNS];
    int currentPlayer = player1First();
    playerToPlayerTurn(currentPlayer);
    ticTacToeGameBoard(a, rows);
    beginningInstructionsForTicTacToe();
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
/**
 * This function checks the entire TicTacToe game array to determine if any of
 * the players have won. If a player has won, their results are keep track of and 
 * returned at the end of the program
 * @param array This is the TicTacToe game array that has all occupied spaces
 * @param rows This is the size of the horizontal elements within the array
 * @return Returns the results of who, if anyone has won
 */
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
/**
 * This function contains all functionality for the player vs perfect AI game mode.
 * Initially, the results (whether or not someone has won) are checked. Then the 
 * player is switched, and the user or AI enters a place to occupy. After all of 
 * the spaces are occupied the user is prompted to save the game.
 * @param gamesPlayedAgainstSmartAi This is the total games played againts smart AI
 * @param gamesWonAgainstSmartAi This is the total amount of games won against smart AI
 * @param totalGamesPlayed This is the total games played
 * @param totalGamesWon This is the total games won
 */
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
/**
 * This function checks the TicTacToe game board to determine if the smart AI 
 * has a possibility for a loss. If so the coordinate to prevent said loss is saved
 * to the referenced row and column coordinate.
 * @param array This is the TicTacToe game array 
 * @param rows This is the size of the horizontal elements within the array
 * @param rowCoordinate This is the horizontal Coordinate to be entered later
 * @param columnCoordinate This is the vertical Coordinate to be entered later
 */
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
/**
 * This function checks to determine if there is a configuration on the TicTacToe 
 * board/array where if an addition symbol was added, they would win. If this is the
 * case, the row and column reference coordinate of said point is changed to that location
 * @param array This is the TicTacToe game elements
 * @param rows This is the size of the horizontal elements within the array
 * @param rowCoordinate This is the horizontal Coordinate to be entered later
 * @param columnCoordinate This is the vertical Coordinate to be entered later
 */
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
/**
 * This function determines where the AI will make it's first move, depending 
 * on which spaces are open. The referenced row and column coordinates are changed
 * @param array This is the TicTacToe game elements
 * @param rows This is the size of the horizontal elements within the array
 * @param rowCoordinate This is the horizontal Coordinate to be entered later
 * @param columnCoordinate This is the vertical Coordinate to be entered later
 */
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
/**
 * This function determines whether or not there is a possible fork to be made.
 * If so, the AI saves said coordinate to rowCoordinate and columnCoordinate
 * @param array This is the TicTacToe game elements
 * @param rows This is the size of the horizontal elements within the array
 * @param rowCoordinate This is the horizontal Coordinate to be entered later
 * @param columnCoordinate This is the vertical Coordinate to be entered later
 */
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
/**
 * This function determines whether or not there is a possible block fork to be made.
 * If so, the AI saves said coordinate to rowCoordinate and columnCoordinate to block
 * the fork by the other person.
 * @param array This is the TicTacToe game elements
 * @param rows This is the size of the horizontal elements within the array
 * @param rowCoordinate This is the horizontal Coordinate to be entered later
 * @param columnCoordinate This is the vertical Coordinate to be entered later
 */
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
/**
 * This function is used in the dumb AI vs player and dumb AI vs dumb AI to allow
 * for computer input. This function chooses random locations within the array to
 * occupy, and if they aren't already occupied, then they get that spot
 * @param a This is the TicTacToe game elements
 * @param rows This is the size of the horizontal elements within the array
 * @param rowCoordinate This is the horizontal Coordinate to be entered later
 * @param columnCoordinate This is the vertical Coordinate to be entered later
 */
void randomInput(char a[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate)
{
    do
    {
        rowCoordinate = (rand() % 3);
        columnCoordinate = (rand() % 3);
    }
    while(a[rowCoordinate][columnCoordinate] != ' ');
}
/**
 * This function contains all logic for the Smart AI when it is determining where
 * to make it's next move.
 * @param a This is the TicTacToe game elements
 * @param rows This is the size of the horizontal elements within the array
 * @param rowCoordinate This is the horizontal Coordinate to be entered later
 * @param columnCoordinate This is the vertical Coordinate to be entered later
 */
void inputSmartAiSymbol(char a[][COLUMNS], int rows, int &rowCoordinate, int &columnCoordinate)
{
    randomInput(a, rows, rowCoordinate, columnCoordinate);
    possibleFork(a, rows, rowCoordinate, columnCoordinate);
    blockPossibleFork(a, rows, rowCoordinate, columnCoordinate);
    firstAiMove(a, rows, rowCoordinate, columnCoordinate);
    smartAiChecksForLossPossibility(a, rows, rowCoordinate, columnCoordinate);
    smartAiChecksForWinPossibility(a, rows, rowCoordinate, columnCoordinate);
}
/**
 * This function contains all functionality for the player 
 * vs dumb AI. Initially, the results (whether or not someone
 * has won) are checked. Then the player is switched, and the user or AI enters
 * a place to occupy. After all of the spaces are occupied the user is prompted 
 * to save the game.
 * @param gamesPlayedAgainstDumbAi This is the total games played against the dumb AI
 * @param gamesWonAgainstDumbAi This is the total games won against the dumb AI
 * @param totalGamesPlayed This is the total amount of games played
 * @param totalGamesWon This is the total amount of games won
 */
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
/**
 * This function contains all functionality for the dumb AI 
 * vs dumb AI. Initially, the results (whether or not someone
 * has won) are checked. Then the player is switched, and the AI enters
 * a place to occupy. After all of the spaces are occupied the user is prompted 
 * to save the game.
 */
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