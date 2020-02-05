//money_math.cpp - A program to calculate interests, taxes, and conversions.
//Justin Voo - 2/8/16
//CISP 360

//Preprocessors called so common libraries would be made available to the program
#include <iostream>
#include <iomanip>

using namespace std;

//Constant variables for conversion rates
const double toEuros = .9;
const double toPounds = .69;

//Prototypes created to foreshadow upcoming functions
void programGreeting();
double add(double amt1, double amt2);
double subtract(double amt1, double amt2);
double multiply(double amt1, double amt2);
double divide(double amt1, double amt2);
double compute(double amt, double amt2, double interest, double years);
void print_results(double amt1, double amt2, double added, double subtracted, double multiplied, double divided, double gains, double fedTaxed, double CATaxed, double ARTaxed);

int main()
{
    //Variables to be used for the storage of values
    double amt1;
    double amt2;
    double interest;
    double years;
    double gains;
    double added, subtracted, multiplied, divided;
    added = 0, subtracted = 0, multiplied = 0, divided = 0;
    const double fedTax = .32;
    double fedTaxed;
    const double CATax = .07;
    double CATaxed;
    const double ARTax = .06;
    double ARTaxed;

    //Input for future calculations
    programGreeting();
    cout << endl << "Please enter a whole number for your first dollar amount: ";
    cin >> amt1;
    amt1 = amt1 / 100.0;
    cout << "Please enter a whole number for your second dollar amount: ";
    cin >> amt2;
    amt2 = amt2 / 100.0;
    cout << "Please enter an interest rate without the percent symbol: ";
    cin >> interest;
    interest = interest / 100.0;
    cout << "Please enter the number of years to calculate the interest: ";
    cin >> years;

    //Transformations (Calculations)
    added = add(amt1, amt2);
    subtracted = subtract(amt1, amt2);
    multiplied = multiply(amt1, amt2);
    divided = divide(amt1, amt2);
    gains = compute(amt1, amt2, interest, years);
    fedTaxed = add(amt1, amt2) * fedTax;
    CATaxed = add(amt1, amt2) * CATax;
    ARTaxed = add(amt1, amt2) * ARTax;

    //Output to let the user know the results
    print_results(amt1, amt2, added, subtracted, multiplied, divided, gains, fedTaxed, CATaxed, ARTaxed);

    return 0;
}

//The greeting put into a function so the main function doesn't have clutter
void programGreeting()
{
    cout << endl << "Welcome to the MoneyMath program." << endl;
    cout << "We will calculate interest, taxes, and conversions." << endl;
    cout << "Enter dollar amounts like you normally would but omit the period." << endl;
    cout << "(Ex: 100.00 would be written as 10000)." << endl;
}

//A funtion to add the two given dollar amounts
double add(double amt1, double amt2)
{
    double x;
    x = amt1 + amt2;
    return x;
}

//A function to subtract the two given dollar amounts
double subtract(double amt1, double amt2)
{
    double x;
    x = amt1 - amt2;
    return x;
}

//A function to multiply the two given dollar amounts
double multiply(double amt1, double amt2)
{
    double x;
    x = amt1 * amt2;
    return x;
}

//A funtion to divide the two given dollar amounts
double divide(double amt1, double amt2)
{
    double x;
    x = amt1 / amt2;
    return x;
}

//A function to compute the interest gained from the given dollar amounts from the given amount of years 
double compute(double amt1, double amt2, double interest, double years)
{
    return (add(amt1, amt2) * years) * interest;
}

//A function to print the results so the main function doesn't have clutter
void print_results(double amt1, double amt2, double added, double subtracted, double multiplied, double divided, double gains, double fedTaxed, double CATaxed, double ARTaxed)
{
    cout << endl << "Displaying Math Operations" << endl;
    cout << "$" << setprecision(2) << fixed << amt1 << " + $" << amt2 << " = $" << added << endl;
    cout << "$" << setprecision(2) << fixed << amt1 << " - $" << amt2 << " = $" << subtracted << endl;
    cout << "$" << setprecision(2) << fixed << amt1 << " x $" << amt2 << " = $" << multiplied << endl;
    cout << "$" << setprecision(2) << fixed << amt1 << " / $" << amt2 << " = $" << divided << endl;
    cout << endl << "An investment with the parameters specified above will generate $" << setprecision(2) << fixed << gains << "." << endl;
    cout << endl << "Federal taxes: $" << setprecision(2) << fixed << fedTaxed;
    cout << endl << "CA taxes: $" << setprecision(2) << fixed << CATaxed;
    //Bonus - Tax for another state
    cout << endl << "AR taxes: $" << setprecision(2) << fixed << ARTaxed << endl;
    //Calculations converted to Euros
    //Bonus - Actual numbers printed when showing calculations of conversions
    cout << endl << "Dollar to Euro Conversion" << endl;
    cout << "$" << setprecision(2) << fixed << amt1 << " + $" << amt2 << " = €" << added * toEuros << endl;
    cout << "$" << setprecision(2) << fixed << amt1 << " - $" << amt2 << " = €" << subtracted * toEuros << endl;
    cout << "$" << setprecision(2) << fixed << amt1 << " x $" << amt2  << " = €" << multiplied * toEuros << endl;
    cout << "$" << setprecision(2) << fixed << amt1 << " / $" << amt2 << " = €" << divided * toEuros << endl;
    //Bonus - Calculations converted to Pounds
    cout << endl << "Dollar to Pound Conversion" << endl;
    cout << "$" << setprecision(2) << fixed << amt1 << " + $" << amt2 << " = £" << added * toPounds << endl;
    cout << "$" << setprecision(2) << fixed << amt1 << " - $" << amt2 << " = £" << subtracted * toPounds << endl;
    cout << "$" << setprecision(2) << fixed << amt1 << " x $" << amt2 << " = £" << multiplied * toPounds << endl;
    cout << "$" << setprecision(2) << fixed << amt1 << " / $" << amt2 << " = £" << divided * toPounds << endl;
}

//
// Peer Review Summary Form
// Complete and attach to the bottom of your source file and turn in to D2L.
//
// Reader: Kevin Mai
// Recorder: 
// Other: 
//
// Approx Time for this asignment: 2 Hours
// Use the following ranking for the following:
// 5 - Sophisticated, 4 - Highly Competent, 3 - Competent, 2 - Not Yet Competent, 1 - Unacceptable 
// Solution Fit with Client Needs: 5 
// User Friendliness: 5
// Comments and Documentation: 5
// Overall Score: 5

