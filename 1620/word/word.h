/* File word.h */
#ifndef WORD_H
#define WORD_H


class Word
{
    private:
        char * array; //The array used to store all the input  in our class
        void copy ( const char * ); //Prototype for cp func
    public:
        ~Word( void ); // destructor
        Word ( const char * = "" ); // const char * construction
        Word ( const Word & ); // copy constructor
        friend ostream & operator<< (ostream &, const Word &); // overloaded
        //"<<" for type "Word"
        const Word & operator = ( const char * ); // input const char *
        // and used the copy f(x) to convert to Word
        const Word & operator = ( const Word & ); // input reference to a
        //"Word" and use the copy 
        bool operator == ( const Word & ); //Overload "=="
        bool operator != ( const Word & ); //Overload "!="
        bool operator < ( const Word & ); //Overlaod "<"
        bool operator > ( const Word & ); //Overload ">"
        bool operator <= ( const Word & );//Overload "<="
        bool operator >= ( const Word & );//Overlaod ">="
        char & operator [] ( const int); //Overload "[]"
        const char & operator [] ( const int) const; // const charreturn
};
#endif
