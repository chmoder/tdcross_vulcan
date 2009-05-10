//Name          :Thomas Cross
//Class         :1400009
//Program #     :pgm18
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

//find largest and smallest integer

#include <iostream>

using namespace std;


void lgsm ( int &smallest, int &largest );

int main ()
{
	int small, large;
		
		lgsm ( small, large );
		if (small <= 0)
		{
		cout << "NOTHING TO PROCESS" << endl;
		goto kill;
		}
		cout << "Your results: " << endl;
		cout << small << ":" << large << endl;
		kill:
	return 0;
}





void lgsm ( int &smallest, int &largest )
{
int input;

cout << "Please enter a number (negitive value to end): ";
cin >> input;

smallest = input;
largest = input;


while (input >= 0)
{

cout << "Please enter a number (negitive value to end): ";
cin >> input;

if  (input > largest)
largest = input;

if (input < 0)
cout << "Ending Program." << endl;
else if (input < smallest)
smallest = input;
}
}
