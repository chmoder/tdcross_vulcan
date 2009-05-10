//Name          :Thomas Cross
//Class         :1400009
//Program #     :pgm13
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
#include <cmath>
using namespace std;

int binconvert ( int binNum );
long int input=0;
int converted=0;
int main ()
{

	cout <<"Please enter a binary number and I will convert it for you: "<<flush;
	cin >> input;
	cout << binconvert(converted) << ":" << input << endl;

return 0;
}

int binconvert ( int binNum )
{
double x=0;
int mod=0;

while (x<=10)
{
mod = input % 10;
if (mod == 1)
{
converted += (pow(2,x));
input /= 10;
}
else if (mod == 0)
{
input /=10;
}
x++;
}
return converted;
}

