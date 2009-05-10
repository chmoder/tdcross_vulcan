/* File card.h */

#ifndef CARD_H
#define CARD_H


class Card
{
    private:
        int val; //card value
        int suit; //card suit
    public:
        //type card
        Card ( int = 0 ); // Constructs type card
        const Card & operator = ( int ); // overload = for assignment
        friend ostream & operator << ( ostream & , const Card &); //overload << for output
        //output for type card
        bool operator < ( const Card & ) const; //compair card values for <
        bool operator > ( const Card & ) const; //compair card values for >
};
#endif
