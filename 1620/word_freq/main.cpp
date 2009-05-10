/*File main.cpp */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "word.h"
#include "list.h"


//Main is very small but includes many new usefull features that I have
//not included in my earlier programs.  First main takes an int argc
//and a charecter pointer to argv array.  argc is the number of places
//after the program is executed.  Ex.  if ./wfc is executed it will
//out via cerr what to do.  (include a file)  the file must be the 
//first arg.  (the first thing after the space from ./wfc <textfile>).
//so int argc is just the "argument count".  It holds the number of 
//arguments passed to main in the argument vector argv.  arg c is always
//one greater then the nuber of cli args entered by the user.
//then argb is the "argument vector".  a pointer to an array of string
//pointers passed to the main function.  I think they just pass the 
//pointers to what the user typed in identifyable by there argc.
//Now for the main program.........................................
//First I create a list called List1 to hold all the data elements of 
//our input file.  then i make a Word to hold all the words to place 
//into a Node.  I know its overkill but if a user presents to
//few or many I print out a message to let them know what to do
//and exit.  Then I use ifstream to pass all that is in argv location
//1 to inputfile.  then i make a char array called line with a sizeof
//the argument passed.  After that I make an array full of delimiters to 
//be used to define how long a word is and what to not include in a
//word.  spaces, ", stuff like that.  Then while getline puts a line 
//into my "line" array from the inputfile, I make put whatever the 
//strtok finds till it finds a delimiter.  Tokenizes it and puts it in
//ptr.  Finally while ptr has data I insert ptr into the List and have 
//strtok cleared by NULL; prep for next go arround.  
//this will recur till getline reaches no more lines.  After that
//list1 is printed using my inline overloaded "<<" operator.  
int main( int argc, char * argv[] )
{
    List list1;
    Word word;


    //if ( argc < 2 || argc > 2  )
    if ( argc != 2 )
    {
        cerr << "wfc: You must include an input file. \n"
            << "Try `wfc filename.filetype" << endl;
        exit(1);
    }
    ifstream inputfile ( argv[1] );
    char line[sizeof(inputfile)];
    char * delim = " \\\"/+!?.,|";
    //printf("\n");
    while ( inputfile.getline( line, sizeof( inputfile ) ) )
    {
        char * ptr = strtok ( line, delim );
        while( ptr )
        {
            list1.insert ( ptr );
            ptr = strtok( NULL, delim );
        }
    }
    //printf("\n");
    
    cout << list1;

    return 0;
}
