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

using namespace std;

/*int perfTest ( int i )
{
i = i % 2;
return (i);
}
*/

int main( int b )
{
int my_array[50];
int i = 1;
cin >> b;
while (i < b) {
if ( (b % i) == 0)
//my_array[i]=i;
//cout << my_array[i] << endl;
//cout << i << " + ";

i++;
}
return 0;
//return (my_array[i]);
}


//int main ()
//{
//int x;

//cin >> x;
//cout << factorPrint(x) << " + ";

//return 0;
//}

/*int factorPrint( int b )
{
int i = 1;

while (i < b) {
if ( (b % i) == 0)
//cout << i << " + " <<; 
return i;
i++;
}
}
*/
