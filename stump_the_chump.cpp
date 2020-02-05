//stump_the_chump.cpp
//Justin Voo
//CISP 360

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string a;
    string b;
    string c;
    string d;
    string temp = "";
    string abc[16];
    int card[16];
    string hello;

    cout << "Enter the first four digits of your credit card #:";
    cin >> a;
    cout << "Enter the next four digits of your credit card #:";
    cin >> b;
    cout << "Enter the next four digits of your credit card #:";
    cin >> c;
    cout << "Enter the next four digits of your credit card #:";
    cin >> d;

    for(int x = 3; x > -1; x--)
    {
        temp += d[x];
    }
    
    for(int x = 3; x > -1; x--)
    {
        temp += c[x];
    }
    
    for(int x = 3; x > -1; x--)
    {
        temp += b[x];
    }
    
    for(int x = 3; x > -1; x--)
    {
        temp += a[x];
    }
    
    for( int i = 0; i < 16; ++i)
    {
        abc[i] = temp.at(i);
        hello = abc[i];
        card[i] = atoi(hello.c_str());
    }

    for( int w : card)
    {
        cout << card[w];
    }
}



