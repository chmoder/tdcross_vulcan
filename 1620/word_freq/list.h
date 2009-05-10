/* File list.h */


//This is a Doubly-Linked List.  I chose to do doubly linked list to 
//avoid spetial case conditions and for a more efficiant code design.
//Below is a nested class with the List being the top of the class with
//Node class being inside the List class.  The Node class is private 
//with public members so that we cannot access the nodes directly but 
//instead throught the List.  "LIST OF NODES".  I define what a Node is 
//and initialize the default val of members of the node in in class
//Node.  Each node has 2 Node pointers that point to NULL, a word with 
//"default" as the default word, and a int count set to 1 for repeats.
//Here i create a Node called head at runtime so that i can base the
//rest of my List algorithim off of that head.  As usual we define our
//functions as public so that we can access them in the main pgm.
//I found the List constructor and destructor usefull as well as insert
//remove traverse and print.  Inline gives me the ability to overload
//the "<<" operator for the print function.  this exact code is place
//wherever it is called in my program( inline ).  The overload takes
//a list and of course the ostream passed by reference passing it to my
//print function which I will explain later.  

#include <iostream>
#include "word.h"
#ifndef LIST_H
#define LIST_H


class List
{
    private:
        class Node 
        {
            public:
                Node * prev;
                Word data;
                int count;
                Node * next;
                Node ( Node * p = NULL, Word d = "default",
                        int c = 1, Node * n = NULL )
                    : prev(p), data(d), count(c), next(n) {;;;}
        };

        Node head;

    public:
        List(void);
        ~List(void);
        void insert( const Word );
        void remove ( const Word );
        Node * trav ( const Word ); 
        void print ( ostream & ) const;
        //bool find ( const Word );

};

inline ostream & operator << ( ostream & ost, const List & l )
{
    l.print( ost );
    return ost;
}

#endif
