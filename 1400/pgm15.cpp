//Name          :Thomas Cross
//Class         :1400009
//Program #     :pgm15
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

//Crate a program that will take a birthday and convert it to one number and generate a numerology report

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;


int numcheck (char parm)
{
int inx = 0;
char search_array[11] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-' };
char birthday [10];


//cout << "Please enter your birtday month,day,year.  ex 01-31-1964: ";
//cin >> birthday;
cout << "FIRST ONE" << endl;
while (inx <= 11)
{
cout << "INN loop" << endl;
//cout << birthday[x] << "     "  << search_array[x];
if (parm == search_array[inx])
//cout << parm << endl;
cout << inx << "    "  <<  parm << endl;
inx++;
}
cout << "out of loop" << endl;
return inx;
}

int main ()
{

int rtnnum;
char input;
cin >> input;
rtnnum = numcheck(input);
cout << rtnnum;
return 0;
}
