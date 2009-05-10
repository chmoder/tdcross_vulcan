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
#include <iomanip>
using namespace std;

long double whichfib (register int i) {
register long double x, y, sum;
  
x = 1;
y = 0;

while (i > 0) {
sum = x + y;
y = x;
x = sum;
i = i-1;
}
return(y);
}

int main () {
register int fibnum;
cout << "Which Fibonacci number would you like? ";
cin >> fibnum;
while (fibnum < 0) {
cout << "Which Fibonacci number would you like? ";
cin >> fibnum;
}
cout << "fibonacci #" << fibnum << " is " << fixed << setprecision(0) << whichfib(fibnum) << endl;
return 0;
}

