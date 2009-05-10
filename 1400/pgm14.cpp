//Name          :Thomas Cross
//Class         :1400009
//Program #     :pgm14
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

//Classfull sudokuchecker

#include <iostream>
using namespace std;
#include "SudokuChecker.h"

int main ()
{
SudokuChecker foo;
foo.readGrid();
foo.checkGrid();

return 0;
}
