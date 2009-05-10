/* File card.cpp */

#include<iostream>
using namespace std;
#include "card.h"

//card constructor with mod to 
//turn number into a value we can
//use to compare for war
//deviing is used to create a suit
    Card::Card ( int numb )
    {
        val = numb % 13; 
        suit = numb / 13;

    }

//Assignment for card
// return calling variable *this
    const Card & Card::operator = ( int numb )
    {
        val = numb % 13;
        suit = numb / 13;
        return *this; 
    }

    //the following overloaded operators
    //are used to overload the comparrators
    //so that we can compare cards and 
    //return a bool
    bool Card::operator < ( const Card & arg ) const // overload less than to compare cards
    {
        return val < arg.val;
    }
    bool Card::operator > ( const Card & arg ) const // overload greater than to compare cards
    {
        return val > arg.val;
    }
    
    //linked lists are used to find a 
    //and suit using the "val" and 
    //"suit" variables discussed 
    //earlier
    ostream & operator << ( ostream & ost , const Card & c) // overload << to output cards in there real name
    {
        static const char * faces[] =
        {
            "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
            "Ten", "Jack", "Queen", "King", "Ace" 
        };
    static const char * suits[] =
        {
            "Diamonds", "Hearts", "Spades", "Clubs" 
        };
        ost << faces[c.val] << " of " <<  suits[c.suit];
        return ost;
    }


