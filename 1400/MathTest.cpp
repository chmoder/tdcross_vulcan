#include <iostream>
#include "MathTest.h"
using namespace std;

MathTest::MathTest()
{
cout <<"Welcome to the MathTest Object!" << endl;
}

void MathTest::inputNumber ()
{
cout << " Please input a non-negitive (>=0) integer:";
cin >> number;

}

void MathTest::testEven ()
{
int even = number % 2;
if (even == 0)
cout << number <<":EVEN\n";
else
cout << number << ":ODD\n";
}

void MathTest::testMultiple ()
{
int mult = number % 3;
if (mult == 0)
cout << number << ":YES\n";
else 
cout << number << ":NO\n";
}

