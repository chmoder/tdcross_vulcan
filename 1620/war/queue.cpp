/* File queue.cpp */

#include<iostream>
using namespace std;
#include "queue.h"


//Queue constructor containing
//cap is capacity of array
//hand = new integer array of
//size cap
//back is the current location of the 
//last element in the array
//I dont need it but wanted 
//a front to display the front of the arry
//as zero
Queue::Queue( void ) 
{
    cap = 13;
    hand = new int [ cap ];
    back = 0;
    front = 0;
}


//queue destructor
//used to delete an array made by
//the construcotr
Queue::~Queue ( void ) 
{
    delete [] hand;
}

// Test if queue is empty
//if back is not 0 then Empty is
//not true
bool Queue::Empty ( void ) const 
{
    return (!back);
}

//enqueue cards
//when back is greater than or
//equal to cap we need to grow the
//array.  to grow we create a new array
//coppy the old stuff into the new array.
//the capacity will be 2x the orriginal
//and the old array is deleted when done.
//no matter what the value is adde to the 
//array after a grow or not.
void Queue::Enqueue ( int x ) // enqueue cards
{
    if ( back >= cap )
    {
        int ncap = cap * 2;
        int * newhand = new int [ncap];
        for ( int y = front; y < cap; ++y )
        {
            newhand [ y ] = hand [ y ];
        }
        delete [ ] hand;
        hand = newhand;
        cap = ncap;

        hand [back++] = x;
    }

    else
    {
        hand [back++] = x;
    }

}

//Dequeue Array
//This works by simply copying the front
//of the arary and shifting the variables
//down one.  copy arry[i+1] into array[i].
int Queue::Dequeue ( void )
{
    int rval = 0;
    rval = hand [ front ];
    for ( int i = 0; i < back; ++i ) 
    {
        hand[i] = hand [i + 1];
    }
    --back;

    return rval;
}

//This function just returns the number of
//cards in a deck.  The way we know the number
//of cards in the deck is becasue the back
//is the last card.  ALSO since we are using classes
//we use this "back" varaiable and it will return 
//to me the back of the object i have in the main!
int Queue::Count ( void ) 
{
    return back;
}



