//complex.cpp - A problem used to process complex numbers.
//Justin Voo - 4/4/16
//CISP 360

#include <iostream>

using namespace std;

//A struct to hold each complex number
struct ComplexNumber
{
    double number[2];
} ;

//Prototypes to foreshadow all functions besides main
void greeting();
ComplexNumber input(ComplexNumber a);
void add(ComplexNumber a, ComplexNumber b);
void triple(ComplexNumber a, ComplexNumber b);
void subtract(ComplexNumber a, ComplexNumber b);
void multiply(ComplexNumber a, ComplexNumber b);

int main()
{
    //Variables used in this program
    ComplexNumber first;
    ComplexNumber second;
    int temp;

    greeting();
    cout << "For your first complex number, you will enter decimal numbers for two parts.\n";
    first = input(first);
    cout << "Now for your second complex number, you will do the same.\n";
    second = input(second);
    cout << "Now we will perform calculations on your complex numbers.\n";
    //All calculations performed on the inputed complex numbers
    add(first, second);
    triple(first, second);
    subtract(first, second);
    multiply(first, second);
}

//A function used to greet the user
void greeting()
{
    cout << "Welcome to the Complex program!\n";
    cout << "Here, we will perform actions on two complex numbers.\n\n";
}

//A function used to gather input for each complex number
ComplexNumber input(ComplexNumber a)
{
    cout << "Enter your first number for the real part: ";
    cin >> a.number[0];
    cout << "Enter your second number for the imaginary part: ";
    cin >> a.number[1];
    cout << endl;
    
    return a;
}

//A function used to add the complex numbers
void add(ComplexNumber a, ComplexNumber b)
{
    double tempReal = a.number[0] + b.number[0];
    double tempImaginary = a.number[1] + b.number[1];
    cout << "\nWhen we add (" << a.number[0] << ", " << a.number[1] << ") "
        << "and (" << b.number[0] << ", " << b.number[1] << "), we get "
        << "(" << tempReal << ", " << tempImaginary << ").";
}

//Bonus - Extra Calculation (Novel Programmer Defined Feauture)
//A function used to add the complex numbers and triple the result
void triple(ComplexNumber a, ComplexNumber b)
{
    double tempReal = (a.number[0] + b.number[0]) * 3;
    double tempImaginary = (a.number[1] + b.number[1]) * 3;
    cout << "\nWhen we add & triple (" << a.number[0] << ", " << a.number[1] << ") "
        << "and (" << b.number[0] << ", " << b.number[1] << "), we get "
        << "(" << tempReal << ", " << tempImaginary << ").";
}

//A function used to subtract the complex numbers
void subtract(ComplexNumber a, ComplexNumber b)
{
    double tempReal = a.number[0] - b.number[0];
    double tempImaginary = a.number[1] - b.number[1];
    cout << "\nWhen we subtract (" << a.number[0] << ", " << a.number[1] << ") "
        << "and (" << b.number[0] << ", " << b.number[1] << "), we get "
        << "(" << tempReal << ", " << tempImaginary << ").";
}

//Bonus - Extra Calculation
//A function used to multiply the complex numbers (using the FOIL method)
void multiply(ComplexNumber a, ComplexNumber b)
{
    double tempReal = a.number[0] * b.number[0];
    double tempImaginary = a.number[1] * b.number[1];
    double tempImaginary2 = (a.number[0] * b.number[1]) + (b.number[0] * a.number[1]);
    cout << "\nWhen we multiply (" << a.number[0] << ", " << a.number[1] << ") "
        << "and (" << b.number[0] << ", " << b.number[1] << "), we get "
        << "(" << tempReal << ", " << tempImaginary2 << "i, " << tempImaginary << ").";
}
