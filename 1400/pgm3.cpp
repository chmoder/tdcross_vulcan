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

//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main () 

{


int a;
int b; 
int c;

int sum, difference, product, quotient, modulous;


cout << " Please enter your first integer." << endl;
cin >> a;

cout << " Please enter your second integer." << endl;
cin >> b;

cout << " Please enter your third integer." << endl;
cin >> c;


sum = (a + b + c);
cout << "+:" << sum << endl;
difference = (a - c);
cout << "-:" << difference << endl;
product =  (a * b * c);
cout << "*:" << product << endl;
quotient = (a / b);
cout << "/:" << quotient << endl;
modulous = (b % c);
cout << "%:" << modulous << endl;

return 0;
}
