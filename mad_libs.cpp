//mad_libs.cpp - A fun program to play Mad Libs.
//Justin Voo - 2/28/16
//CISP 360

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//Bonus - All input variables are held in a struct (Novel Programmer Defined Feature)
struct input
{
    string time_span;
    string noun_one;
    string noun_two;
    string noun_three;
    string noun_four;
    string noun_five;
    string noun_six;
    string noun_seven;
    string noun_eight;
    string verb_one;
    string verb_two;
    string verb_three;
    string verb_four;
    string verb_five;
    string verb_six;
    string occupation;
    string celebrity;
    string adjective_one;
    string adjective_two;
    string preposition;
    int integer;
    double float_one;
    string letter;
} game;

//prototypes used to foreshadow functions
void greeting();
void user_input();
void output();
string repeat();

int main()
{
    //flag variable for the while loop
    string flag = "";
    
    //while loop used to repeat program if the user wants to do so
    while (flag != "done")
    {
        greeting();
        user_input();
        output();
        flag = repeat();
    }
    
    return 0;
}

//function used to welcome the user
void greeting()
{
    cout << endl << "Welcome to Mad Libs. Enter one item with no spaces unless directed to." << endl;
}

//function used to gather all user input
void user_input()
{
    int flag = 0;
    string temp1 = "";
    int temp2 = 0;
    cout << endl << "Please enter a time of the day (Ex: Morning):";
    cin >> game.time_span;
    cout << endl << "Please enter a noun:";
    cin >> game.noun_one;
    cout << endl << "Please enter a verb:";
    cin >> game.verb_one;
    cout << endl << "Please enter another verb:";
    cin >> game.verb_two;
    cout << endl << "Please enter a noun:";
    cin >> game.noun_two;
    cout << endl << "Please enter another noun:";
    cin >> game.noun_three;
    cout << endl << "Please enter a verb ending in -ing:";
    cin >> game.verb_three;
    cout << endl << "Please enter a two-word occupation with a space in between:";
    cin >> game.occupation;
    cin >> temp1;
    game.occupation += " " + temp1;
    cout << endl << "Please enter a noun:";
    cin >> game.noun_four;
    cout << endl << "Please enter another noun:";
    cin >> game.noun_five;
    cout << endl << "Please enter the first name of a celebrity:";
    cin >> game.celebrity;
    cout << endl << "Please enter an adjective:";
    cin >> game.adjective_one;
    cout << endl << "Please enter a verb:";
    cin >> game.verb_four;
    cout << endl << "Please enter a noun:";
    cin >> game.noun_six;
    cout << endl << "Please enter a plural noun:";
    cin >> game.noun_seven;
    cout << endl << "Please enter an adjective:";
    cin >> game.adjective_two;
    cout << endl << "Please enter a noun:";
    cin >> game.noun_eight;
    cout << endl << "Please enter a verb:";
    cin >> game.verb_five;
    cout << endl << "Please enter a preposition:";
    cin >> game.preposition;
    //while loop used to make sure the entered integer is valid
    while (flag == 0)
    {
        cout << endl << "Please enter an integer between one and twelve:";
        cin >> temp2;
        if (temp2 >= 1 && temp2 <= 12)
        {
            game.integer = temp2;
            flag = 1;
        }
        else
        {
            cout << endl << "That is not an integer between one and twelve;";
        }   
    }
    cout << endl << "Please enter a verb:";
    cin >> game.verb_six;
    cout << endl << "Please enter a decimal:";
    cin >> game.float_one;
    cout << endl << "Please enter a letter:";
    cin >> game.letter;
    cout << endl;
}

//function used to display the output
void output()
{
    //Bonus - Clear the screen before displaying output
    system("CLS");
    cout << "A Day in the Life of a College Student" << endl << endl;
    cout << "Every " << game.time_span << ", I wake up and get off my " << game.noun_one << ". I don't" << endl;
    cout << "always have time to " << game.verb_one << " a shower, but I always make sure to" << endl;
    cout << game.verb_two << " my hair. Once that's done I get some " << game.noun_two << "," << endl;
    cout << "and then it's off to my first " << game.noun_three << ". I often get" << endl;
    cout << "caught " << game.verb_three << " in class. No one like it when" << endl;
    cout << "the " << game.occupation << " gives a surprise " << game.noun_four << ". My second class" << endl;
    cout << "is " << game.noun_five << " Theory. Dr. " << game.celebrity << " is incredibly " << game.adjective_one << "," << endl;
    cout << "but I never " << game.verb_four << " her because of her thick " << game.noun_six << ". Her" << endl;
    cout << game.noun_seven << ", however, are really " << game.adjective_two << ". After lunch," << endl;
    cout << "I have no more " << game.noun_eight << " and I'm free to " << game.verb_five << " " << game.preposition << endl;
    cout << "my friends. This is right around " << game.integer << " O'clock. Before" << endl;
    cout << "I go to bed I " << game.verb_six << " a little bit, in my room, " << game.float_one << " " << game.letter << "." << endl << endl;
}

//function used to ask if the user wishes to play again
string repeat()
{
    string temp;
    cout << "Would you like to play again? Type 'done' to exit:";
    cin >> temp;
    return temp;
}


