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
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main () 

{

int a;
int b;
int c;
int d;

int mod1, mod2, mod3, mod4;
int mult9_1, mult9_2, mult9_3, mult9_4;
int mod_val, mult_val;

cout << "Please enter an integer greater than zero" << endl;
cin >> a;
cout << "Please enter an integer greater than zero" << endl;
cin >> b;
cout << "Please enter an integer greater than zero" << endl;
cin >> c;
cout << "Please enter an integer greater than zero" << endl;
cin >> d;

mod1 = (a%2);
mod2 = (b%2);
mod3 = (c%2);
mod4 = (d%2);

mult9_1 = (a%3);
mult9_2 = (b%3);
mult9_3 = (c%3);
mult9_4 = (d%3);

if (mod1 != 0)
{
mod_val = false;
}
else
{
mod_val = true;
}

if (mult9_1 != 0)
{
mult_val = false; 
}
else
{
mult_val = true;
}

if ((mod_val == true) && (mult_val == true))
{
cout << a << " is EVEN and a MULTIPLE of 9 " << endl;
}
else if ((mod_val == true) && (mult_val == false))
{
cout << a << " is EVEN and NOT a MULTIPLE of 9" << endl;
}
else if ((mod_val == false) && (mult_val == true))
{
cout << a << " is ODD and a MULTIPLE of 9" << endl;
}
else if ((mod_val == false) && (mult_val == false))
{
cout << a << " is ODD and NOT a MULTIPLE of 9" << endl;
}

return 0;
}
