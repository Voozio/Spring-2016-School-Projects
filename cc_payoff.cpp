//cc_payoff.cpp - A program to determine how long it will take to pay off a credit card.
//Justin Voo - 2/1/16
//CISP 360

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double formula(double balance, double apr, double moPay);
int print_months(string name, double months, int counter);

int main()
{
    string name;
    double balance;
    double apr;
    double moPay;
    double months;
    int flag = 0;
    int counter = 1;
    
    cout << "Welcome. In this program, we will calculate the months it will take to pay off your credit card(s)." << endl;
    cout << endl << "Enter your name: ";
    //Bonus - Input client's name to be used and printed
    getline(cin, name);
    
    //Bonus - Option for multiple credit cards (Novel programmer defined feature)
    while (flag == 0)
    {
        cout << endl << "What is your balance? ";
        cin >> balance;
        cout << "What is the APR on the card you can make (Must be under 100)? ";
        cin >> apr;
        cout << "What is the monthly payment you can make? ";
        cin >> moPay;
        
        apr = apr/100.0;
        months = formula(balance, apr, moPay);
        flag = print_months(name, months, counter);
        if (flag == 0)
        {
            counter++;
        }
    }
}

//Bonus - Month Calculation Formula
double formula(double balance, double apr, double moPay)
{
    double months;
    double dailyRate;
    
    dailyRate = apr/(365.0);
    months = 1.0 + dailyRate;
    months = pow(months, 30.0);
    months = 1.0 - months;
    months = (balance/moPay) * months;
    months = 1.0 + months;
    months = log(months);
    months = months / log(1.0 + dailyRate);
    months = (-1.0/30.0) * months;
    return months;
}

int print_months(string name, double months, int counter)
{
    int flag = 0;
    
    cout << endl << name <<". It will take you " << ceil(months) << " months to pay off credit card #" << counter << "." << endl;
    cout << endl << "Would you like to calculate another credit card? If yes, type 0. If not, type any other number: ";
    cin >> flag;
    
    if (flag == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
