//Name          :Thomas Cross
//Class         :1400009
//Program #     :pgm12
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
#include <iomanip>
using namespace std;

int main ()
{

auto double input = 0;
auto int sigfig = 0;


cout << "Please enter a number: ";
cin >> input;
cout << "How many digits of precision in our output? ";
cin >> sigfig;
cout << setprecision(sigfig) << fixed << showpoint << "ceil(" << input << ") = " << ceil(input) << endl;
cout << setprecision(sigfig) << fixed << showpoint << "fabs(" << input << ") = " << fabs(input) << endl;
cout << setprecision(sigfig) << fixed << showpoint << "floor(" << input << ") = " << floor(input) << endl;
cout << setprecision(sigfig) << fixed << showpoint << "log(" << input << ") = " << log(input) << endl;
cout << setprecision(sigfig) << fixed << showpoint << "log10(" << input << ") = " << log10(input) << endl;
cout << setprecision(sigfig) << fixed << showpoint << "pow(" << input << "," << input << ") = " << pow(input,input) << endl;
cout << setprecision(sigfig) << fixed << showpoint << "sqrt(" << input << ") = " << sqrt(input) << endl;

return 0;
}
