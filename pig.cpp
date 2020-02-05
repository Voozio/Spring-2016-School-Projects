//pig.cpp - A Simple Game.
//Justin Voo - 5/9/16
//CISP 360

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//Prototypes used to foreshadow upcoming functions
string greeting();
int playerTurn();
int ComputerTurn(int mode);

int main()
{
    //Variables used to hold input or temporary data
    int player = 0;
    int computer = 0;
    int mode;
    string modeSelected;
    int turnCount = 0;
    int temp = 0;

    //Bonus - Option for hard mode (Novel Programmer Defined Feature)
    //More difficult AI doesn't mean more sophisticated
    modeSelected = greeting();
    if (modeSelected == "0")
    {
        cout << "Mode selected: Easy\n\n";
        mode = 3;
    }
    else
    {
        cout << "Mode selected: Hard\n\n";
        mode = 1;
    }
    while (temp < 100)
    {
        //Bonus - A counter to keep track of the number of turns
        turnCount++;
        player += playerTurn();
        cout << "You're total score is " << player << ".\n\n";
        if (player < 100)
        {
            computer += ComputerTurn(mode);
            cout << "The computer's total score is " << computer << ".\n\n";
        }
        if (player > computer)
            temp = player;
        else
            temp = computer;
    }
    if (player >= 100)
        cout << "It took " << turnCount << " turns to win! You're so smart ;)";
    if (computer >= 100)
        cout << "The computer has won after " << turnCount << " turns. This game must be rigged.";
    return 0;
}

//A function to welcome the user
//The mode is also chosen here
string greeting()
{
    string temp;
    bool flag = false;

    cout << "Welcome to Pig ~ A simple coding game!\n";
    cout << "You and the computer will take turns racing to 100 by rolling a die.\n";
    cout << "If you roll a number at or between two and six, it will be added to your turn total.\n";
    cout << "If you roll a one, you lose your turn total and your turn.\n";
    cout << "You have the option to leave with your current turn total after every roll.\n\n";
    cout << "First, choose a mode. Enter '0' for easy or '1' for hard: ";
    while (flag == false)
    {
        getline(cin, temp);
        if (temp == "0" || temp == "1")
        {
            cout << "Great choice. And it looks like you'll be going first.\n";
            return temp;
        }
        else
            cout << "\nThat is not an option. Please enter '0' or anything else: ";
    }
    return "";
}

//A function for the player's turn
//Includes error checking for false input
int playerTurn()
{
    bool flag = false;
    string decision;
    int turnTotal = 0;
    int diceRoll;
    srand(time(NULL));

    cout << "It's your turn.\n\n";
    while (flag == false)
    {
        cout << "To hold, enter '0'. To roll, enter '1': ";
        getline(cin, decision);
        if (decision == "0")
            return turnTotal;
        else if (decision == "1")
        {
            diceRoll = rand() % 6 + 1;
            if (diceRoll == 1)
            {
                cout << "\nYou rolled a one. You're done, son.\n\n";
                return 0;
            }
            else
            {
                cout << "You rolled a " << diceRoll << ".\n";
                turnTotal += diceRoll;
                cout << "You're current turn total is " << turnTotal << ".\n\n";
            }
        }
        else
            cout << "\nThat is not an option.\n\n";
    }
    return 0;
}

//A function for the computer's turn
//The mode is the chance of the computer deciding to hold
//The easy mode has a higher chance than the hard mode
int ComputerTurn(int mode)
{
    bool flag = false;
    int turnTotal = 0;
    int diceRoll;
    srand(time(NULL));

    cout << "It's the computer's turn.\n\n";
    while (flag == false)
    {
        diceRoll = rand() % 6 + 1;
        if (diceRoll <= mode || turnTotal >=11)
        {
            cout << "The computer decides to hold. GG.\n\n";
            return turnTotal;
        }
        else
        {
            diceRoll = rand() % 6 + 1;
            if (diceRoll == 1)
            {
                cout << "The computer rolled a one. Ha.\n\n";
                return 0;
            }
            else
            {
                cout << "The computer rolled a " << diceRoll << ".\n\n";
                turnTotal += diceRoll;
            }
        }
    }
    return 0;
}


