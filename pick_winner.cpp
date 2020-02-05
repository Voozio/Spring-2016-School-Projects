//pick_winner.cpp - A lottery program.
//Justin Voo - 3/6/16
//CISP 360

//Libraries required for the program
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Structure used to hold input values
struct list
{
    int control;
    string tempNames[20];
} pool;

//Prototypes used to foreshadow functions
void greeting();
int input();
void listSize();

int main()
{
    //Variables for selecting a winner
    string winner;
    int random;

    //Function calls
    greeting();
    input();
    listSize();
    //Declaration of the final array
    string names[pool.control];
    //A loop to insert the names into the final array
    for(int x = 0; x < pool.control; x++)
    {
        names[x] = pool.tempNames[x];
    }
    //Selecting a winner by random
    srand(time(NULL));
    random = rand()%pool.control;
    winner = names[random];
    cout << endl << "The winner is " << winner << "." << endl << endl;
}

//A function to welcome the user
void greeting()
{
    cout << "Welcome to the Pick a Winner program." << endl;
    cout << "Enter names and press enter after each one." << endl;
    cout << "Press enter when nothing is typed to stop entering names into the pool." << endl;
    cout << "The limit is 20 names." << endl << endl;
}

//A function to gather all the names
int input()
{
    for(int x = 0; x < 20; x++)
    {
        pool.tempNames[x] = "";
    }
    int x = 0;
    string test = "blank";
    while (test != "" && x != 19)
    {
        cout << "Enter a name: ";
        getline(cin, test);
        if (test != "")
        {
            pool.tempNames[x] = test;
        }
        else
        {
            pool.tempNames[x] = test;
            return 0;
        }
        x++;
    }
    return 0;
}

//A function to determine the size of the array needed to hold just the names
void listSize()
{
    pool.control = 0;
    int x = 0;
    int temp = 0;
    string flag = "blank";
    while(flag != "")
    {
        flag = pool.tempNames[temp];
        if (flag != "")
        {
            x++;
        }
        temp++;
    }
    pool.control = x;
}


