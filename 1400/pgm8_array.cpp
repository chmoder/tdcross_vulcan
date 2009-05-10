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

int main ()
{

using std::cout;
using std::cin;
using std::endl;

int x;
int y;
int sudoku [4][4]; //sudoku two dimentional array, 16 blocks total
int sumR1;
int sumR2;
int sumR3;
int sumR4;
int sumC1;
int sumC2;
int sumC3;
int sumC4;
int sumQ1;
int sumQ2;
int sumQ3;
int sumQ4;

x = 0;  //initialize variable
y = 0;  // initialize variable


//Input 16 user variables.
do 
{
while (y < 4)
{
cin >> sudoku [x][y];;
y++;
}
x++;
y = 0; //reset y to 0
}
while (x < 4); //when x = 4 all 16 slots have filled

x = 0;

sumR1 = sudoku [0][0] + sudoku [0][1] + sudoku [0][2] + sudoku [0][3];
sumR2 = sudoku [1][0] + sudoku [1][1] + sudoku [1][2] + sudoku [1][3];
sumR3 = sudoku [2][0] + sudoku [2][1] + sudoku [2][2] + sudoku [2][3];
sumR4 = sudoku [3][0] + sudoku [3][1] + sudoku [3][2] + sudoku [3][3];
sumC1 = sudoku [0][0] + sudoku [1][0] + sudoku [2][0] + sudoku [3][0];
sumC2 = sudoku [0][1] + sudoku [1][1] + sudoku [2][1] + sudoku [3][1];
sumC3 = sudoku [0][2] + sudoku [1][2] + sudoku [2][2] + sudoku [3][2];
sumC4 = sudoku [0][3] + sudoku [1][3] + sudoku [2][3] + sudoku [3][3];
sumQ1 = sudoku [0][0] + sudoku [0][1] + sudoku [1][0] + sudoku [1][1];
sumQ2 = sudoku [0][2] + sudoku [0][3] + sudoku [1][2] + sudoku [1][3];
sumQ3 = sudoku [2][0] + sudoku [2][1] + sudoku [3][0] + sudoku [3][1];
sumQ4 = sudoku [2][2] + sudoku [2][3] + sudoku [3][2] + sudoku [3][3];

cout << sumR1;
if (sumR1 == 10)
cout << "ROW1:GOOD\n";
else
cout << "ROW1:BAD\n";

if (sumR2 == 10)
cout << "ROW2:GOOD\n";
else
cout << "ROW2:BAD\n";
if (sumR3 == 10)
cout << "ROW3:GOOD\n";
else
cout << "ROW3:BAD\n";
if (sumR4 == 10)
cout << "ROW4:GOOD\n";
else
cout << "ROW4:BAD\n";

if (sumC1 == 10)
cout << "COL1:GOOD\n";
else
cout << "COL1:BAD\n";
if (sumC2 == 10)
cout << "COL2:GOOD\n";
else
cout << "COL2:BAD\n";
if (sumC3 == 10)
cout << "COL3:GOOD\n";
else
cout << "COL3:BAD\n";
if (sumC4 == 10)
cout << "COL4:GOOD\n";
else
cout << "COL4:BAD\n";

if (sumQ1 == 10)
cout << "REG1:GOOD\n";
else
cout << "REG1:BAD\n";
if (sumQ2 == 10)
cout << "REG2:GOOD\n";
else
cout << "REG2:BAD\n";
if (sumQ3 == 10)
cout << "REG3:GOOD\n";
else
cout << "REG3:BAD\n";
if (sumQ4 == 10)
cout << "REG4:GOOD\n";
else 
cout << "REG4:BAD\n";

return 0;
}
