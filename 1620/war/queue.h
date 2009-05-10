/* File queue.h */

#ifndef QUEUE_H
#define QUEUE_H


class Queue
{
    private:
        int * hand ; // array for holding players cards
        int cap; // size of number of items in the queue
        int front; // first element of the queue
        int back;  // last element of the queue
    public:
        Queue ( void );
        ~Queue ( void );
        bool Empty ( void ) const; // Check for empty set
        void Enqueue ( int ); // pushes card into back of hand
        int Dequeue ( void ); // pops card off front of deck
        int Count ( void ); // returns # of elments of deck
};
#endif
