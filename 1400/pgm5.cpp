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
int a, b, c, d;
int input;

cin >> input;
a = input;

cin >> input;
if (input >= a)
{
b = input;
}
else
{
b = a;
a = input;
}

cin >> input;
if (input >= b)
{
c = input;
}
else if (input >= a) 
{
c = b;
b = input;
}
else if (input <= b)
{
c = b;
b = a;
a = input;
}

cin >> input;
if (input >= c)
{
d = input;
}
else if (input <= c)
{
d = c;
c = input;
}
else if (input <= b)
{
d = c;
c = b;
b = input;
}
else if (input <= a)
{
d = c;
c = b;
b = a;
a = input;
}

cout << a << endl;
cout << b << endl;
cout << c << endl;
cout << d << endl;


return 0;
}

