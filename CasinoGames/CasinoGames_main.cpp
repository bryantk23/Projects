/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: TheR3
 *
 * Created on September 23, 2023, 11:22 AM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int cardChooser(int cardNum);
int cardOrganizer (int actualCardNum, int totalCardNums);
int dealerChoice(int dealerTotalCardNums, int cardDealerNum);
int slotRandomSystem(int percent);
string slotSymbolAssignment(string symbol);
void slotsFormat(int slotsBet);
void slotResults(string symbol1, string symbol2, string symbol3, int& slotsBet);
static double chips = 100;
/*
 * 
 */
int main(int argc, char** argv) {

    srand(time(0));
    string userWantsToContinue;
    do
    {
        int userSwitchInput = 0;
        cout << "What would you like to play?" << endl;
        cout << "1) BlackJack" << endl;
        cout << "2) Slots" << endl;
        cout << "You have " << chips << " chips to play with" << endl;
        cin >> userSwitchInput;
        switch (userSwitchInput)
        {

            case 1:
            {
                string userWantsToContinueBlackJack;
                do
                {
                    cout << endl << endl << endl << endl << endl << endl << endl << endl;
                    int cardDealerNum1, cardDealerNum2, cardDealerNum3, cardDealerNum4, cardDealerNum5;
                    int userCardNum1, userCardNum2, userCardNum3, userCardNum4, userCardNum5;
                    int dealerTotalCardNums = 0, userTotalCardNums = 0;
                    userCardNum1 = cardOrganizer(userCardNum1, userTotalCardNums);
                    userTotalCardNums += userCardNum1;
                    userCardNum2 = cardOrganizer(userCardNum2, userTotalCardNums);
                    userTotalCardNums += userCardNum2;
                    cout << "You have " << chips << " chips to bet." << endl;
                    cout << "How much would you like to bet?" << endl;
                    int bet = 0;
                    cin >> bet;
                    while (bet > chips)
                    {
                        cout << "You don't have enough, enter another bet." << endl;
                        cin >> bet;
                    }
                    cout << "You got a " << userCardNum1 << " and a " 
                        << userCardNum2 << endl << "For a total of " << userTotalCardNums << endl;
                    
                    cardDealerNum1 = cardOrganizer(cardDealerNum1, dealerTotalCardNums);
                    dealerTotalCardNums += cardDealerNum1;
                    cardDealerNum2 = cardOrganizer(cardDealerNum2, dealerTotalCardNums);
                    dealerTotalCardNums += cardDealerNum2;
                    
                    cout << "The Dealer got a " << cardDealerNum1 << " and a " 
                        << cardDealerNum2 << endl << "For a total of " << dealerTotalCardNums << endl;
                    
                    cout << "Would you like to hit or stay? H/S" << endl;
                    string wantsToCont;
                    cin >> wantsToCont;
                    while (tolower(wantsToCont[0]) == 'h')
                    {
                        userCardNum3 = cardOrganizer(userCardNum3, userTotalCardNums);
                        userTotalCardNums += userCardNum3;
                        cout << "You got a " << userCardNum3 << endl << "For a total of " 
                            << userTotalCardNums << endl;
                        cout << "Would you like to hit or stay? H/S" << endl;
                        cin >> wantsToCont;
                    }

                    dealerTotalCardNums = dealerChoice(dealerTotalCardNums, cardDealerNum3);
                    cout << "The Dealer's hand is " << dealerTotalCardNums << endl;

                    if (dealerTotalCardNums > 21 && userTotalCardNums > 21)
                    {
                        cout << "You and the Dealer bust" << endl;
                        cout << "TIE" << endl;
                        chips = chips;
                    }
                    else if (dealerTotalCardNums > 21)
                    {
                        cout << "The Dealer busted" << endl << "YOU WIN" << endl;

                        chips += bet;
                    }
                    else if (userTotalCardNums > 21)
                    {
                        cout << "You busted, YOU LOSE" << endl;
                        chips -= bet;
                    }
                    else 
                    {
                        if (dealerTotalCardNums < userTotalCardNums) 
                        {
                            cout << "YOU WIN" << endl;
                            chips += bet;
                        }
                        else if (dealerTotalCardNums > userTotalCardNums)
                        {
                            cout << "YOU LOSE" << endl;
                            chips -= bet;
                        }
                        else 
                        {
                            cout << "TIE" << endl;
                            chips = chips;
                        }

                    }
                    cout << "Your total is " << chips << " chips" << endl;
                    cout << "Do you want to continue playing BlackJack? Y/N" << endl;
                    cin >> userWantsToContinueBlackJack;
                }
                while(tolower(userWantsToContinueBlackJack[0]) == 'y');

                break;
            }
            case 2:
            {
                string userWantsToContinueSlots;
                
                do
                {
                cout << endl << endl << endl << endl << endl << endl << endl << endl;
                cout << "You have " << chips << " chips to bet." << endl;
                cout << "How much would you like to bet?" << endl;
                int slotsBet = 0;
                cin >> slotsBet;
                while (slotsBet > chips)
                {
                    cout << "You don't have enough, enter another bet." << endl;
                    cin >> slotsBet;
                }
                slotsFormat(slotsBet);
                cout << "Would you like to continue playing Slots? Y/N\n";
                cin >> userWantsToContinueSlots;
                }
                while (tolower(userWantsToContinueSlots[0]) == 'y');
                
                break;
            }
            default:
                cout << "Invalid Input" << endl;
        }
        cout << "Would you like to continue playing games? Y/N" << endl;
        
        cin >> userWantsToContinue;
    }
    while (tolower(userWantsToContinue[0]) == 'y');
    
    return 0;
}
/**
 * This function gets a random number between 1 and 14, then 
 * assigns it to cardNum
 * @param cardNum Placeholder for the random number between 1 and 14
 * @return Returns the a random number between 1 and 14 in the form of 
 * variable cardNum
 */
int cardChooser(int cardNum)
{
    cardNum = rand() % 14 + 1;
    return cardNum;
}
/**
 * This function takes a random number between 1 and 14, then returns 
 * a number (numerical card value) based on what the random number was
 * @param actualCardNum Placeholder for the numerical card value to be returned
 * @param totalNumOfCards Takes the total number of numerical card values of a player
 * @return Returns the numerical card value for a certain card
 */
int cardOrganizer(int actualCardNum, int totalNumOfCards)
{
    
    actualCardNum = cardChooser(0);
    if (actualCardNum <= 10)
    {
        
        return actualCardNum;
      
    }
    else if (actualCardNum == 11)
    {
        actualCardNum = 10;
        return actualCardNum ;
        
    }
    else if (actualCardNum == 12)
    {
        
        actualCardNum = 10;
        return actualCardNum;
       
    }
    else if (actualCardNum == 13)
    {
        
        actualCardNum = 10;
        return actualCardNum;
        
    }
    else if (actualCardNum == 14 && totalNumOfCards <= 10)
    {
        
        actualCardNum = 1;
        return actualCardNum;
        
    }
    else 
    {
        actualCardNum = 11;
        return actualCardNum;
        
    }
}
/**
 * This function determines whether or not the dealer needs to 
 * hit or stay. It also displays the card number the dealer got
 * @param dealerTotalCardNums Takes the dealer's total number of cards 
 * (numerical value)
 * @param cardDealerNum Placeholder for the randomly chosen card
 * @return Returns the total number of cards the dealer has 
 * (numerically, including the recently received ones)
 */
int dealerChoice(int dealerTotalCardNums, int cardDealerNum)
{
    while (dealerTotalCardNums <= 17)
    {
        cardDealerNum = cardOrganizer(cardDealerNum, dealerTotalCardNums);
        dealerTotalCardNums += cardDealerNum;
        cout << "Dealer Hits, and got a  " << cardDealerNum << endl;
    }
    return dealerTotalCardNums;
}
/**
 * This function gets a random number from 1 to 11, then stores this in
 * a variable.
 * @param percent Percent stores the random value, placeholder
 * @return Returns the variable that has the random value
 */
int slotRandomSystem(int percent)
{
    percent = 0;
    percent = (rand() % 11) + 1;
    return percent;
}
/**
 * This function takes the random number between 1 and 11, then runs it
 * through conditions to return certain symbols based on their conditions.
 * @param symbol Placeholder for the symbol to be returned
 * @return Returns a randomly chosen symbol
 */
string slotSymbolAssignment(string symbol)
{
    int percent = slotRandomSystem(percent);
    if (percent == 1 || percent == 2)
    {
        symbol = 'X';
    }
    else if (percent == 3 || percent == 4)
    {
        symbol = 'O';
    }
    else if (percent == 5 || percent == 6)
    {
        symbol = 'Z';
    }
    else if (percent == 7 || percent == 8)
    {
        symbol = 'Q';
    }
    else if (percent == 9 || percent == 10)
    {
        symbol = 'A';
    
    }
    else 
    {
        symbol = '$';
    }
    return symbol;
}
/**
 * This function formats most of the program, including the title, 
 * symbols, and dashes that organize the game.
 * @param slotsBet Takes the bet that the user made in the beginning of the
 * program
 */
void slotsFormat(int slotsBet)
{
    string symbol, symbol1, symbol2, symbol3;
    symbol1 = slotSymbolAssignment(symbol);
    symbol2 = slotSymbolAssignment(symbol);
    symbol3 = slotSymbolAssignment(symbol);
    cout << "Bryant's Totally Legit Slots Game " << endl;
    cout << "--------------" << endl;
    cout << left << setw(3) << slotSymbolAssignment(symbol) 
        << setw(3) << slotSymbolAssignment(symbol)
            << setw(3) << slotSymbolAssignment(symbol) << endl;
    cout << left << setw(3) << symbol1 << setw(3) << symbol2 << setw(3) << symbol3 << endl;
    cout << left << setw(3) << slotSymbolAssignment(symbol) 
        << setw(3) << slotSymbolAssignment(symbol)
            << setw(3) << slotSymbolAssignment(symbol) << endl;
    cout << "--------------" << endl;
    slotResults(symbol1, symbol2, symbol3, slotsBet);
}
/**
 * This function outputs the result of the game, as well as the 
 * chips left from whether or not they won
 * @param symbol1 Takes a randomly chosen symbol
 * @param symbol2 Takes another randomly chosen symbol
 * @param symbol3 Takes a final randomly chosen symbol
 * @param slotsBet Takes the user's initial bet
 */
void slotResults(string symbol1, string symbol2, string symbol3, int& slotsBet)
{
    string totalSymbols = symbol1 + symbol2 + symbol3;
    int cherryMultiplier = 1;
    int win = 0;
    for (int i = 0; i < totalSymbols.length(); i++)
    {
        if (totalSymbols[i] == 'X' || totalSymbols[i] == '$' || totalSymbols[i] == 'Z')
        {
            if (totalSymbols[i] == '$')
            {
                cherryMultiplier = cherryMultiplier + 2 ;
                win = 0;
            }
        }
        else 
        {
            win = 1;
        }
    }
    if (win == 0 || cherryMultiplier > 1)
    {
        chips = chips + slotsBet * cherryMultiplier;
        cout << "WIN " << chips << endl;
        cout << "You have " << chips << " credits left over" << endl;
    }
    else
    {
        chips = chips - slotsBet;
        cout << "LOSE " << chips << endl;
        cout << "You have " << chips << " credits left over" << endl;
    }
    
}