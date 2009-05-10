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

//Program uses iostream

#include <iostream>

using std::cout;     //pgm uses cout
using std::cin;      //pgm uses cin
using std::endl;     //pgm uses enl

//function main begins program execution
int main()
{
    int number1; //first int to compair
    int number2; //second int to compare

    cout << "Enter two integers to compare: ";  //promt user for data
    cin >> number1 >> number2;  //read two int from user


    if ( number1 == number2 )
       cout << number1 << " == " << number2 << endl;

    if ( number1 != number2 )
       cout << number1  << " != " << number2 << endl;

    if ( number1 < number2 )
       cout << number1 << " < " << number2 << endl;
 
    if ( number1 > number2 )
       cout << number1 << " > " << number2 << endl;

    if ( number1 <= number2 )
       cout << number1 << " <= " << number2 << endl;

    if ( number1 >= number2 )
       cout << number1 << " >= " << number2 << endl;

    return 0;  // indicate program ended successfully

}  //end function main

