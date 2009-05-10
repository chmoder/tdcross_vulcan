/* File word.cpp */

#include<iostream>
using namespace std;
#include "word.h"

//the point of this file is to make a data type called a Word in which
//we can do all normal operations such as assinment, output, etc.
//The bulk of the program uses cp to move arround data in a char
//array.

// vital piece of program.
//This function is used to convert a const * char and return a "Word"
//for use in pgm 
void Word::copy ( const char * satish_sucks ){
    if (!satish_sucks)
        satish_sucks = "";
    int how_many = strlen( satish_sucks );
    ++how_many; // add one for the NULL
    array = new char [ how_many ];
    strcpy( array, satish_sucks );
}

//copy const char * to a
//"Word" needed due to overloading
const Word & Word::operator = ( const char * var ) {
    copy( var );
    return *this;
}

// used for copying word
//and overloading the "=" again but i with another "Word"
const Word & Word::operator = ( const Word & var ) {
    copy( var.array );
    return *this;
}
//call delte to delete array.
Word::~Word( void ) 
{
    delete [] array;
}

//call copy to construct a word from a char array
Word::Word ( const char * cp )  
{
    copy( cp );
}

//call copy to copy construct a word from a Word
Word::Word ( const Word & w ) 
{
    copy( w.array );
}

// overload " << " for successfull cout of a "Word"
//passes a word to the ostream and returns it as an ost
ostream& operator<< (ostream & ost , const Word & w ) {
    ost << w.array;
    return ost;
}


// Overload "==" using strcasecmp and returning a bool
//for yes or no, as to equal or not. 
bool Word::operator == ( const Word & var) {
    bool rval = false;
    if(!strcasecmp(array, var.array))
    {
        rval = true;
    }
    return rval;
}

//if the word is not equal to the calling var.
//then return not.  if it is return yes.
bool Word::operator != ( const Word & var )
{
    return !(*this == var);
} 

//Use strcasecmp to compare the array to the array in 
//question.  Always false unless strcasecmp is less
//than 0.
bool Word::operator < ( const Word & var )
{
    bool rval = false;
    if( strcasecmp( array, var.array ) < 0 )
        rval = true;
    return rval;    
}

//if calling var is = to var or calling var is less than 
//var rval is false else true.
bool Word::operator > ( const Word & var )
{
   bool rval = true;
   if (*this == var || *this < var )
        rval = false;
        return rval;
}

//opposite of above and includes equality.
bool Word::operator <= ( const Word & var )
{
    bool rval = false;
    if ( *this == var || *this < var )
        rval = true;
        return rval;
}

//after prototyping the <= we can use it for checking
//by simply applying the converse.  
bool Word::operator >= ( const Word & var ) 
{
    return !(*this < var);
}

// Overload "[]" for storage and
//selection of variable.  Given int return char in the array.  No
//further work is needed du to the fact that the "=" / assignment var was
//allready overloaded. 
//pass it a location in the word.  return array[location].
char & Word::operator [] ( const int var) {
        return array[var];
}

//const version of previous.  
const char & Word::operator[] ( const int var) const
{
       return array[var];
}
