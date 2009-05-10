//Name          :Thomas Cross
//Class         :1400009
//Program #     :pgm19
//Due Date      :10.23.08
//
//Honor Pledge  On my honor as a student of the University of Nebraska at Omaha,
// I have neither given nor recieved unauthorized help on this homework
// assignment.
//
//Signed1: Thomas Cross
//Signed2: 1337
//Signed3: tom.bz2@gmail.com

//Partners  :List the full names, CIST 1400 section and e-mail addresses

//Sieve of eratosthenes

#include <iostream>
#include <cmath>		// for square root function
#include <iomanip>		// included in case you use formatting for output
using namespace std;

void makeSieve ( bool sieve[], const int sieveSize );
void workSieve ( bool sieve[], const int sieveSize );
void findBoundaries ( int &lower, int &upper, const int sieveSize );
void showTwins ( const bool sieve[], const int lower, const int upper );

int main()
{
    const int SIZE = 250001;
    bool sieve[SIZE];
    int low, high;

    makeSieve ( sieve, SIZE );
    workSieve ( sieve, SIZE );
    findBoundaries ( low, high, SIZE );
    showTwins ( sieve, low, high );

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void makeSieve ( bool sieve[], const int sieveSize )
{
const int SIZE = 250001;
        for (int i = 0; i <= SIZE; i++)
{
        sieve[i] = 1;
}
        sieve[0] = 0;
        sieve[1] = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void workSieve ( bool sieve[], const int sieveSize )
{
int x;
for ( int i = 3; i <= 250000; i++ )
{
x = 2;
while (x < i)
{
if (i % x == 0)
{
sieve[i] = 0;
break;
}
else if (i % x >= 1)
sieve[i] = 1;
x++;
}
}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////

void findBoundaries (int &lower, int &upper, const int sieveSize )
{
lower = 0;
upper = 250001;
while ((upper < 1) || (upper > 250000) || (lower < 1) || (lower > 250000) || (upper < lower)){
cout << "Please enter your upper boundary (Between 1 and 250000: ";
cin >> upper;
cout << "Please enter your lower boundary (Between 1 and 250000: ";
cin >> lower;
if (upper < lower)
cout << "Your upper boundary cannot be smaller than your lower boundary." << endl;
}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void showTwins ( const bool sieve[], const int lower, const int upper )
{
int num1 = 0;
int num2 = 0;
int x = lower;
cout << endl << "Here are all the twin prime pairs in the range of " << lower << " to " << upper << ", one pair per line:" << endl << endl;

x++;

while ( x <= upper)
{
num1 = 0;
num2 = 0;

while ((num1 == 0) || (x < upper))
{
if (sieve[x] == 1)
{
num1 = x;
break;
}
else
x++;
}
x++;
while ((num2 == 0) || (x < upper))
{
if (sieve[x] == 1)
{
num2 = x;
break;
}
else
x++;
}
if (num2 - num1 == 2)
cout << num1 << " and " << num2 << endl;
}
}

