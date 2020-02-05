//candy_bar_crush.cpp - A program that displays candy.
//Justin Voo - 2/21/16
//CISP 360

//Preprocessors called so common libraries would be made available to the program
#include <iostream>
#include <string>

using namespace std;

//A structure - very similar to classes in Java
struct CandyBar
{
    string name;
    double weight;
    int calories;
} ;

int main()
{
    //Struct variable of the CandyBar type
    CandyBar snack = {"Mocha Munch", 2.3, 350};
    //Variables tied to user input
    int candyAddition = 0;
    int total = 3;
    int flag = 3;

    //Program Greeting
    cout << "Welcome to the CandyBar program." << endl;
    cout << "Here, we will show a list of the available candy bars." << endl << endl;
    cout << "Enter the number of candy bars you would like to add:";
    cin >> candyAddition;
    total += candyAddition;
    cout << endl;

    //Bonus (Mandatory) - Dynamically allocated array using new to hold CandyBar structures
    CandyBar* backpack = new CandyBar[total];
    backpack[0] = {"Choco Chalk", 5.1, 725};
    backpack[1] = {"Twisty String", 1.8, 300};
    backpack[2] = {"Gummy Nums", 4.4, 475};
    
    //Loop for user input
    while (flag < total)
    {
        string temp;
        cout << "Enter a two-word candy bar name at least 10 letters long:";
        cin >> backpack[flag].name;
        cin >> temp;
        backpack[flag].name = backpack[flag].name + " " + temp;
        cout << "Enter the weight (numbers only):";
        cin >> backpack[flag].weight;
        cout << "Enter the calories(whole numbers only):";
        cin >> backpack[flag].calories;
        cout << endl;
        flag++;
    }
    
    //List of candy bars and their details
    cout << "Name\t\tWeight\tCalories" << endl << endl;
    cout << snack.name << "\t" << snack.weight << "\t" << snack.calories << endl;
    //Bonus - For loop used to print array of CandyBar structures (Novel programmer defined feature)
    for (int x = 0; x < total; x++)
    {
        cout << backpack[x].name << "\t" << backpack[x].weight << "\t" << backpack[x].calories << endl;
    }
    
    delete[] backpack;
    
    return 0;
}

// Peer Review Summary Form
// Complete and attach to the bottom of your source file and turn in to D2L.
// Reader: // Recorder: // Other: // // Approx Time for this asignment:
// Use the following ranking for the following:
// 5 - Sophisticated, 4 - Highly Competent, 3 - Competent, 2 - Not Yet Competent, 1 - Unacceptable
// Solution Fit with Client Needs: 5 
// User Friendliness: 5
// Comments and Documentation: 5
// Overall Score: 5

