/* File word.h */

#include<iostream>
using namespace std;
#ifndef WORD_H
#define WORD_H

//These are the prototypes for the code in the driver. 
//please see word.cpp for more information.  
//Basically the array and copy are private for protective
//purposes.  there are two constructors accpting either a 
//Word reference or a character array; default assign to "".
//After that we have the "<<" and "=" overloaded.  The "="
//allows a var pointer  or a Word reference.  the rest of the
//operators overloaded accept only Word references.  except for
//the "[]" because you need an in to find the location in the array.
class Word
{
    private:
        char * array; 
        void copy ( const char * ); 
    public:
        ~Word( void ); 
        Word ( const char * = "" ); 
        Word ( const Word & ); 
        friend ostream & operator<< (ostream &, const Word &);
        const Word & operator = ( const char * ); 
        const Word & operator = ( const Word & ); 
        bool operator == ( const Word & ); 
        bool operator != ( const Word & ); 
        bool operator < ( const Word & ); 
        bool operator > ( const Word & ); 
        bool operator <= ( const Word & );
        bool operator >= ( const Word & );
        char & operator [] ( const int); 
        const char & operator [] ( const int) const;
};
#endif
