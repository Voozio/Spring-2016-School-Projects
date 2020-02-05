//ac_decision_tree.cpp - A program used to troubleshoot engine failure.
//Justin Voo - 4/18/16
//CISP 360

#include <iostream>
#include <string>

using namespace std;

void greeting();
void airborneQ();
void electricalQ();
void engineQ();
void outsideQ();
void mountainQ();
void nightQ();
void waterQ();
void windowQ();
void dreamQ();
void sureQ();

int main()
{
    bool quit = false;

    greeting();
    while (quit == false)
    {
        string answer;

        airborneQ();
        cout << "\n\nWould you like to quit? ";
        getline(cin, answer);
        if (answer == "1")
        {
            quit = true;
        }
        else
        {
            //Bonus - Fake-clears the screen (Novel Defined Feature)
            cout << string(100, '\n');
        }
    }
    return 0;
}

void greeting()
{
    cout << "Welcome to the Decision Tree program.\n";
    cout << "Here, you can troubleshoot for possible engine failure.\n";
    cout << "You must enter '1' for yes and '0' for no.\n\n";
}

void airborneQ()
{
    bool flag = true;
    string answer;

    while (flag == true)
    {
        answer = "";
        cout << "Are you airborne? ";
        getline(cin, answer);
        if (answer == "1")
        {
            electricalQ();
            flag = false;
        }
        else if (answer == "0")
        {
            cout << "\nHave a drink and call a mechanic.";
            flag = false;
        }
        if (answer != "0" && answer != "1")
        {
            cout << "\nThe answer you entered is invalid. Please enter '0' or '1'.\n\n";
        }
    }
}

void electricalQ()
{
    bool flag = true;
    string answer;

    while (flag == true)
    {
        answer = "";
        cout << "Is the electrical system working? ";
        getline(cin, answer);
        if (answer == "1")
        {
            engineQ();
            flag = false;
        }
        else if (answer == "0")
        {
            cout << "\nTurn on the Master Switch.";
            flag = false;
        }
        if (answer != "0" && answer != "1")
        {
            cout << "\nThe answer you entered is invalid. Please enter '0' or '1'.\n\n";
        }
    }
}

void engineQ()
{
    bool flag = true;
    string answer;

    while (flag == true)
    {
        answer = "";
        cout << "Has the engine stopped running? ";
        getline(cin, answer);
        if (answer == "1")
        {
            mountainQ();
            flag = false;
        }
        else if (answer == "0")
        {
            outsideQ();
            flag = false;
        }
        if (answer != "0" && answer != "1")
        {
            cout << "\nThe answer you entered is invalid. Please enter '0' or '1'.\n\n";
        }
    }
}

void outsideQ()
{
    bool flag = true;
    string answer;

    while (flag == true)
    {
        answer = "";
        cout << "Is the outside air temperature <32 degrees? ";
        getline(cin, answer);
        if (answer == "1")
        {
            cout << "\nTurn on the Carburator Heat.";
            flag = false;
        }
        else if (answer == "0")
        {
            cout << "\nSwitch to the other fuel tank.";
            flag = false;
        }
        if (answer != "0" && answer != "1")
        {
            cout << "\nThe answer you entered is invalid. Please enter '0' or '1'.\n\n";
        }
    }
}

void mountainQ()
{
    bool flag = true;
    string answer;
    
    while (flag == true)
    {
        answer = "";
        cout << "Are you over the mountains? ";
        getline(cin, answer);
        if (answer == "1")
        {
            nightQ();
            flag = false;
        }
        else if (answer == "0")
        {
            waterQ();
            flag = false;
        }
        if (answer != "0" && answer != "1")
        {
            cout << "\nThe answer you entered is invalid. Please enter '0' or '1'.\n\n";
        }
    }
}

void nightQ()
{
    bool flag = true;
    string answer;
    
    while (flag == true)
    {
        answer = "";
        cout << "Are you flying at night? ";
        getline(cin, answer);
        if (answer == "1")
        {
            windowQ();
            flag = false;
        }
        else if (answer == "0")
        {
            cout << "\nMake an emergency landing.";
            flag = false;
        }
        if (answer != "0" && answer != "1")
        {
            cout << "\nThe answer you entered is invalid. Please enter '0' or '1'.\n\n";
        }
    }
}

void waterQ()
{
    bool flag = true;
    string answer;
    
    while (flag == true)
    {
        answer = "";
        cout << "Are you flying over water? ";
        getline(cin, answer);
        if (answer == "1")
        {
            cout << "\nInflate you life vest and make an emergency landing.";
            flag = false;
        }
        else if (answer == "0")
        {
            cout << "\nMake an emergency landing on a road.";
            flag = false;
        }
        if (answer != "0" && answer != "1")
        {
            cout << "\nThe answer you entered is invalid. Please enter '0' or '1'.\n\n";
        }
    }
}

void windowQ()
{
    bool flag = true;
    string answer;
    
    while (flag == true)
    {
        answer = "";
        cout << "Turn on the landing light and look out the window.\n";
        cout << "Do you like what you see? ";
        getline(cin, answer);
        if (answer == "1")
        {
            dreamQ();
            flag = false;
        }
        else if (answer == "0")
        {
            cout << "\nTurn off the Landing light.";
            flag = false;
        }
        if (answer != "0" && answer != "1")
        {
            cout << "\nThe answer you entered is invalid. Please enter '0' or '1'.\n\n";
        }
    }
}

//Bonus - Next two functions are two more branches to the decision tree
void dreamQ()
{
    bool flag = true;
    string answer;
    
    while (flag == true)
    {
        answer = "";
        cout << "Are you dreaming? ";
        getline(cin, answer);
        if (answer == "1")
        {
            sureQ();
            flag = false;
        }
        else if (answer == "0")
        {
            cout << "\nMake an emergency landing or you're screwed.";
            flag = false;
        }
        if (answer != "0" && answer != "1")
        {
            cout << "\nThe answer you entered is invalid. Please enter '0' or '1'.\n\n";
        }
    }
}

void sureQ()
{
    bool flag = true;
    string answer;
    
    while (flag == true)
    {
        answer = "";
        cout << "Are you sure? ";
        getline(cin, answer);
        if (answer == "1")
        {
            cout << "\nThen dream up some hotties and have some fun.";
            flag = false;
        }
        else if (answer == "0")
        {
            cout << "\nTurn off the Landing light just in case.";
            flag = false;
        }
        if (answer != "0" && answer != "1")
        {
            cout << "\nThe answer you entered is invalid. Please enter '0' or '1'.\n\n";
        }
    }
}


