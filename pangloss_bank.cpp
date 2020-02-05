//pangloss_bank.cpp - A Bank Program.
//Justin Voo - 4/27/16
//CISP 360

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool flag = true;

//A structure for a basic bank account
struct Regular
{
    string name;
    string accNum;
    string balance;
} ;

//A structure for a plus bank account
struct Plus
{
    string name;
    string accNum;
    string balance;
    string interest;
    string overdraft;
} ;

//A template class to accept different types of ‘User'
template <class T>
T accSetup(T user)
{
    cout << "\nEnter a name: ";
    getline(cin, user.name);
    cout << "Enter an account number: ";
    getline(cin, user.accNum);
    cout << "Enter a starting account balance: ";
    getline(cin, user.balance);

    return user;
}

//Prototypes used to foreshadow upcoming functions
void greeting();
int createAcc();
Regular display(Regular user);
Plus display1(Plus user);
Regular withdraw(Regular user);
Plus withdraw1(Plus user);
Regular deposit(Regular user);
Plus deposit1(Plus user);

int main()
{
    int accType;
    
    greeting();
    accType = createAcc();
    if (accType == 0)
    {
        Regular user;
        user = accSetup(user);
        //Loops bank interactions until user decides to quit
        while (flag == true)
        {
            user = display(user);
        }
    }
    else
    {
        Plus user;
        user = accSetup(user);
        //Variables declared to default amount of 0
        user.interest = "0";
        user.overdraft = "0";
        //Loops bank interactions until user decides to quit
        while (flag == true)
        {
            user = display1(user);
        }
    }
}

//A function used to greet the user
void greeting()
{
    cout << "Welcome to Pangloss Bank where we only make whole dollar transactions.\n";
    cout << "This program allows you to create an account and interact with it.\n\n";
}

//A function to create an account
//The number returned decides the account type
int createAcc()
{
    string temp;
    cout << "To create a regular account, enter '0'.\nTo create a plus account, enter anything else: ";
    getline(cin, temp);
    if (temp == "0")
        return 0;
    else
        return 1;
}

//A function to display a Regular Account
Regular display(Regular user)
{
    string temp;
    cout << "\nName: " << user.name << endl;
    cout << "Account Number: " << user.accNum << endl;
    cout << "Account Balance: $" << user.balance << "\n\n";
    cout << "Enter '0' to withdraw or '1' to deposit.\nOtherwise, enter anything else to quit: ";
    getline(cin, temp);
    if (temp == "0")
        return withdraw(user);
    else if (temp == "1")
        return deposit(user);
    else
    {
        flag = false;
        return user;
    }
}

//A function to display a Plus Account
Plus display1(Plus user)
{
    string temp;
    cout << "\nName: " << user.name << endl;
    cout << "Account Number: " << user.accNum << endl;
    cout << "Account Balance: $" << user.balance << endl;
    cout << "Interest Accumulated on Loans: $" << user.interest << endl;
    cout << "Outstanding Loan Amount: $" << user.overdraft << "\n\n";
    cout << "Enter '0' to withdraw or '1' to deposit.\nOtherwise, enter anything else to quit: ";
    getline(cin, temp);
    if (temp == "0")
        return withdraw1(user);
    else if (temp == "1")
        return deposit1(user);
    else
    {
        flag = false;
        return user;
    }
}

//A function to withdraw money from a Regular Account
//Overdraft is not provided with a Regular Account
//The balance cannot fall below 0 so loans are not allowed
Regular withdraw(Regular user)
{
    //temporary variables
    string temp;
    int a, b, c;

    istringstream one(user.balance);
    one >> a;
    if (a > 0)
    {
        cout << "\nEnter an amount to withdraw: ";
        getline(cin, temp);
        istringstream two(temp);
        two >> b;
        if (b <= a)
        {
            c = a - b;
            ostringstream three;
            three << c;
            user.balance = three.str();
            return user;
        }
        cout << "\nYou do not have sufficient funds to withdraw that amount.\n";
        return user;
    }
    else
    {
        cout << "\nYou do not have sufficient funds to withdraw any money.\n";
        return user;
    }
}

//A function to withdraw money from a Plus Account
//Any negative amount will be converted to an overdraft fee
//Interest will be charged for any overdraft fees
Plus withdraw1(Plus user)
{
    //temporary variables
    string temp;
    double a, b, c, d, e, f, g;

    istringstream three(user.overdraft);
    three >> d;
    if (d < 5000)
    {
        cout << "\nEnter an amount to withdraw: ";
        getline(cin, temp);
        istringstream one(user.balance);
        one >> a;
        istringstream two(temp);
        two >> b;
        g = d + b;
        if (g > 5000)
        {
            cout << "\nYou cannot withdraw an amount that will exceed your overdraft limit.\n";
            return user;
        }
        c = a - b;
        if (c < 0)
        {
            e = d + (0 - c);
            istringstream three(user.interest);
            three >> f;
            f = e * 0.1;
            ostringstream four;
            four << f;
            user.interest = four.str();
            ostringstream five;
            five << e;
            user.overdraft = five.str();
            c = 0;
        }
        ostringstream six;
        six << c;
        user.balance = six.str();
    }
    else
        cout << "\nYou have reached your overdraft limit and cannot withdraw anymore.\n";
    return user;
}

//A function to deposit money into a Regular Account
Regular deposit(Regular user)
{
    //temporary variables
    string temp;
    int a, b, c;
    
    cout << "\nEnter an amount to deposit: ";
    getline(cin, temp);
    istringstream one(user.balance);
    one >> a;
    istringstream two(temp);
    two >> b;
    c = a + b;
    ostringstream three;
    three << c;
    user.balance = three.str();
    return user;
}

//A function to deposit money into a Plus Account
//Money is first deposited into interest, then overdraft, and then the account balance
Plus deposit1(Plus user)
{
    //temporary variables
    string temp;
    int a, b, c, d, e, f, g;
    
    cout << "\nEnter an amount to deposit: ";
    getline(cin, temp);
    istringstream one(user.balance);
    one >> a;
    istringstream two(temp);
    two >> b;
    istringstream three(user.interest);
    three >> c;
    istringstream four(user.overdraft);
    four >> d;
    e = c - b;
    f = d + e;
    g = a - f;
    if (f <= 0)
        f = 0;
    else
        g = 0;
    if (e <= 0)
        e = 0;
    else
        g = 0;
    ostringstream five;
    five << g;
    user.balance = five.str();
    ostringstream six;
    six << e;
    user.interest = six.str();
    ostringstream seven;
    seven << f;
    user.overdraft = seven.str();
    return user;
}
