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
void Word::copy ( const char * satish_sucks )
{
    if (!satish_sucks)
        satish_sucks = "";
    int how_many = strlen( satish_sucks );
    ++how_many; // add one for the NULL
    array = new char [ how_many ];
    strcpy( array, satish_sucks );
}

//copy const char * to a
//"Word" needed due to overloading
const Word & Word::operator = ( const char * var ) 
{
    copy( var );
    return *this;
}

// used for copying word
//and overloading the "=" again but i with another "Word"
const Word & Word::operator = ( const Word & var ) 
{
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
ostream& operator<< (ostream & ost , const Word & w ) 
{
    ost << w.array;
    return ost;
}


// Overload "==" using strcasecmp and returning a bool
//for yes or no, as to equal or not. 
bool Word::operator == ( const Word & var) const
{
    bool rval = false;
    if(!strcasecmp(array, var.array))
    {
        rval = true;
    }
    return rval;
}

//if the word is not equal to the calling var.
//then return not.  if it is return yes.
bool Word::operator != ( const Word & var ) const
{
    return !(*this == var);
} 

//Use strcasecmp to compare the array to the array in 
//question.  Always false unless strcasecmp is less
//than 0.

bool Word::operator < ( const Word & var ) const
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
char & Word::operator [] ( const int var) 
{
        return array[var];
}

//const version of previous.  
const char & Word::operator[] ( const int var) const
{
       return array[var];
}



char * soundex ( const char word [])
{
    char realword [40];
    strcpy (realword, word );
    char beginingchar = realword[0];
    static char newword[6];
    strcpy (newword, "Z0000");

    int j = 0;
    for (int i = 0; word[i] != '\0'; ++i)
    {
        switch(tolower(realword[i]))
        {
            case 'b':
            case 'p':
            case 'f':
            case 'v':
                if (word[i-1] != '1')
                {
                    realword[i] = '1';
                    newword[j] = '1';
                    ++j;
                    break;
                }
                else
                {
                    break;
                }
            case 'c': 
            case 's': 
            case 'k': 
            case 'g':
            case 'j':
            case 'q':
            case 'x':
            case 'z':
                if (word[i-1] != '2')
                {
                   realword[i] = '2';
                   newword[j] = '2';
                   ++j;
                   break;
                }
                else
                {
                    break;
                }
            case 'd': 
            case 't':
                if (word[i-1] != '3')
                { 
                    realword[i] = '3';
                    newword[j] = '3';
                    ++j;
                    break;
                }
                else
                {
                    break;
                }
            case 'l':
                if (word[i-1] != '4')
                {
                    realword[i] = '4';
                    newword[j] = '4';
                    ++j;
                    break;
                }
                else
                {
                    break;
                }
            case 'm': 
            case 'n':
                if (word[i-1] != '5')
                {
                    realword[i] = '5';
                    newword[j] = '5';
                    ++j;
                    break;
                }
                else
                {
                    break;
                }
            case 'r':
                if (word[i-1] != '6')
                {
                    realword[i] = '6';
                    newword[j] = '6';
                    ++j;
                    break;
                }
                else
                {
                    break;
                }
            default:
                if (i == 0)
                {
                    ++j;
                    break;
                }
                else
                {
                    break;
                }
        }    
    }

if (int(beginingchar) >= 97 && int(beginingchar) <= 122 ||int(beginingchar) >= 65 && int(beginingchar <= 90))
{
    newword[0] = toupper(beginingchar);
}
newword[5] = '\0';
return (newword);
}


Word Word::Soundex ( void ) const
{
    return soundex ( array );
}
