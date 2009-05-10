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
#include <cstring>
using namespace std;

int main()
{
char array[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char flda = '2';
char fldb = '3';
int x = 0;
while (x < 10)
{
cout << "SOMETHING" << endl
<< array[x];

if (flda == array[x])
cout << x << endl; 

if (fldb == array[x])
cout << x << endl; 
x++; 
}

return 0;
}

