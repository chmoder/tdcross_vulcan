//Name          :Thomas Cross
//Class         :1400009
//Program #     :pgm1
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

//Convert number to binary

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int x; //user input 
int y = 2048; //highest bit used to end while loop and determine 1 or 0 for binary number

int main () 
{
cout << "Please enter a number greater than 0 and less than 4095" << endl;

cin >> x;
while ((x > 4095) || (x < 0))
{
if ((x > 4095) || (x < 0))
{
cout << "Integer too high or low please try again" << endl;
cin >> x;
}
else
{
}
}

cout << "Your Number " << x << " is ";
while (y >= 1)
{
if ( x >= y )
{
cout << "1";
x = ( x - y );
}
else
{
cout << "0"; 
}
y = (y / 2);
}
cout << " In Binary";
cout << endl;

return 0;
}
