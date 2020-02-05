//input_val.cpp - A program used to validate user input.
//Justin Voo - 4/4/16
//CISP 360

#include <iostream>
#include <string>

using namespace std;

//Struct used to hold user input
struct UserInfo
{
    string first_name;
    string last_name;
    int zip_code;
    string empID;
} ;

//Prototypes used to foreshadow upcoming functions
void greeting();
UserInfo input(UserInfo a);
void validateInput(UserInfo x);
bool validateFName(UserInfo a);
bool validateLName(UserInfo a);
bool validateZip(UserInfo a);
bool validateID(UserInfo a);

int main()
{
    //Struct declaration
    UserInfo employee;

    greeting();
    employee = input(employee);
    validateInput(employee);
}

//Function used to greet the user
void greeting()
{
    cout << "Welcome to the Input Validator program.\n";
    cout << "Here, we will validate your input.\n";
}

//Function used to gather user input
UserInfo input(UserInfo a)
{
    cout << "What is your first name? It must be at least two characters long: ";
    getline(cin, a.first_name);
    cout << "What is your last name? It must be at least two characters long: ";
    getline(cin, a.last_name);
    cout << "What is your zipcode? It must be five digits long: ";
    cin >> a.zip_code;
    cout << "What is your employee ID? The format is two letters and four numbers: ";
    cin.ignore();
    getline(cin, a.empID);
    return a;
}

//Function used to validate user input
//Functions being called within a function
void validateInput(UserInfo x)
{
    string one, two, three, four;
    if (validateFName(x) == true)
        one = "correct";
    else
        one = "incorrect";
    if (validateLName(x) == true)
        two = "correct";
    else
        two = "incorrect";
    if (validateZip(x) == true)
        three = "correct";
    else
        three = "incorrect";
    if (validateID(x) == true)
        four = "correct";
    else
        four = "incorrect";

    cout << "\nYour first name is " << one << ", your last name is " << two << ", your zip code is " << three << " and your ID is " << four << ".";
}

//Function used to determine if the first name is 2 characters long
bool validateFName(UserInfo a)
{
    if (a.first_name.size() >= 2)
        return true;
    return false;
}

//Function used to determine if the last name is 2 characters long
bool validateLName(UserInfo a)
{
    if (a.last_name.size() >= 2)
        return true;
    return false;
}

//Bonus- Function used to validate zip code
bool validateZip(UserInfo a)
{
    if (a.zip_code > 9999 && a.zip_code < 100000)
        return true;
    return false;
}

//Function used to validate user ID
bool validateID(UserInfo a)
{
    if (a.empID.size() == 6)
    {
        if (isalpha(a.empID.at(0)))
        {
            if (isalpha(a.empID.at(1)))
            {   
                if (isdigit(a.empID.at(2)))
                {
                    if (isdigit(a.empID.at(3)))
                    {
                        if (isdigit(a.empID.at(4)))
                        {
                            if (isdigit(a.empID.at(5)))
                                return true;
                        }
                    }
                }
            }
        }
    }
    else
    {
        return false;
    }
}


