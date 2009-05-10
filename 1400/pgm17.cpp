//Name          :Thomas Cross
//Class         :1400009
//Program #     :pgm17
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

//Perfect Number

#include <iostream>
#include <cstring>
using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////
int perfTest (int testnum)
{
int i = 0;
int sum = 0;

while (i < (testnum - 1) )
{
i++;

if((testnum % i) == 0)
sum = sum + i;

}
if (sum == testnum)
sum = true;
else
sum = false;

return(sum);
}

////////////////////////////////////////////////////////////////////////////////////////////


int factorPrint (int inputnum)
{
int i = 1;
cout << inputnum << ":";
while (i < inputnum) {
if ( (inputnum % i) == 0)
{
cout << i << " ";
}
i++;
}
cout << endl;
return (0);
}

/////////////////////////////////////////////////////////////////////////////////////////////

int main ()
{
int amt_num=0;
int count = 0;
int counter = 0;
cout << "How many numbers would you like to test? ";
cin >> count;
while (counter < count)
{
cout << "Please enter a perfect number: ";
cin >> amt_num;

if (perfTest(amt_num) == 1)
(factorPrint(amt_num));


else if (perfTest(amt_num) == 0)
cout << amt_num << ":Not Perfect" << endl;
counter++;
}
return (0);
}
