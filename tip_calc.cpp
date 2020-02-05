//tip_calc.cpp - A tip calculator.
//Justin Voo - 1/27/16
//CISP 360

#include <iostream>
#include <cmath>
using namespace std;

double receive_bill();
double calc_10(double bill);
double calc_15(double bill);
double calc_20(double bill);
void print_tips(double bill, double tenPerc, double fifteenPerc, double twentyPerc, double taxRate);

int main()
{
    double bill;
    double taxRate = .08;
    double tenPerc;
    double fifteenPerc;
    double twentyPerc;

    bill = receive_bill();
    
    tenPerc = calc_10(bill);
    fifteenPerc = calc_15(bill);
    twentyPerc = calc_20(bill);
    //Bonus - Tax rate
    bill = bill * (1.0 + taxRate);
    print_tips(bill, tenPerc, fifteenPerc, twentyPerc, taxRate);
    return 0;
}

//Bonus - Input within it's own function
double receive_bill()
{
    double bill;
    cout << "Welcome to the simple tip calculator." << endl;
    cout << endl << "Enter the amount of the bill:";
    cin >> bill;
    return bill;
}

double calc_10(double bill)
{
    double tip;
    tip = bill * 0.10;
    return tip;
}

double calc_15(double bill)
{
    double tip;
    tip = bill * 0.15;
    return tip;
}

double calc_20(double bill)
{
    double tip;
    tip = bill * 0.20;
    return tip;
}

void print_tips(double bill, double tenPerc, double fifteenPerc, double twentyPerc, double taxRate)
{
    cout << endl << "The current tax rate is " << (taxRate * 100.0) << "%." << endl;
    //Bonus - Rounds all totals to the next whole dollar (Novel programmer defined feature)
    cout << endl << "After tax, the bill with a 10% tip is $" << ceil(bill + tenPerc) << "." << endl;
    cout << "After tax, the bill with a 15% tip is $" << ceil(bill + fifteenPerc) << "." << endl;
    cout << "After tax, the bill with a 20% tip is $" << ceil(bill + twentyPerc) << "." << endl;
}
