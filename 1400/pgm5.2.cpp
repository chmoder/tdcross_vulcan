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

//Output highest and lowest number

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main () 
{

int x;
int input;
int greatest;
int leastest;
x = 0;

cin >> greatest;
leastest = greatest;


while (x < 4)
{
cin >> input;

if (input > greatest)
{
greatest = input;
}

if (input < leastest)
{
leastest = input;
}

x++;
}
cout << endl;
cout << "The greatest was " << greatest << " and the leastest was " << leastest << " " << endl;

return 0;
}
