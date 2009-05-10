/* File list.cpp */

#include <iostream>
using namespace std;
#include "list.h"
#include "word.h"  

    //List constructor sets the pointers of head to the address of
    //itself.
    List::List (void)
    {
        head.next = head.prev = &head;
    }

    //The destructor creates a node pointed to head's next and a temp
    //node called prev.  then while the current node is not the head 
    //node advance current and assign the old current as prev.  then 
    //delete prev.  OH!  And the comented output lines let you see
    //theaddr of what your deleting for debugging purposes.  Prints
    //out the "Word" and next to it the addr of the next node to 
    //be delted.  ...friggin cool.
    List::~List(void)
    {
        Node * curr =  head.next;
        //cout << curr->data << "  " << curr->next << endl;

        Node * prev;
        while ( curr != &head )   
        {
        //cout << curr->data << "  " << curr->next << endl;
            curr = curr->next;
            prev = curr->prev;
            delete prev;
        }
    }

    //Traverse returns a Node pointer and takes a word called foo to
    //search for.  Travers operates by creating a node pointing to
    //the node after head and assigning curr location to the next
    // Node untill currents data is either addr of head or curr
    //node's data is < foo. This comparision of the word in the Node 
    //and the passed word works because of the word class added to 
    //this file.  curr->data must be less than foo... ( alphabetical )
    // or foo must be greater than all the words as it went tall the way
    // to head. 
    List::Node * List::trav ( const Word foo )
    {
        Node * curr = head.next;
        while ( curr != &head && curr->data < foo )
        {
            curr = curr->next;
        }
        return curr;
    }
    
    //Insert is the next funcion I wrote because whats the point of a
    //List without anything in it?  first we pass a Word to insert 
    //from main. Then we traverse to find the word.  If it is found 
    //then we increment curr counter because curr is the Node pointer
    //returned by traverse ( the position returned  must be == to the
    //foo in question or greater than.  If greater then make a new node
    //and assign the new nodes location to the pointer of currents prev
    //and the next to curr.  Then assign temps next prev and temp prev
    //next to temp.
    void List::insert( const Word foo )
    {
        Node * curr = trav( foo );
        
        if ( curr->data == foo )
         ++curr->count;
        else
        {
        Node * temp = new Node ( curr->prev, foo, 1, curr );
        temp->next->prev = temp->prev->next = temp;
        }
    }

    //To remove a Node from the List again, traverse for foo.  If
    //currents data  (returned from trav) is == to foo then assign 
    //currents prevous's next to currents next.  then currs next prev
    //is equal to currents previous.  Then delete curr.  
    //(point the node you are about to delete's, previous Node to
    //curr's next node.  then point the next nodes previous pointer to
    //curr's previous.)  because you want to join the previous node to
    //the node after the current node.  
    void List::remove ( const Word foo )
    {
        Node * curr = trav( foo );
        if ( curr != &head && curr->data == foo )
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }    
    
    //This is the print function that is called in the overloaded "<<" 
    //list.h file for easy ostream printing.  this works like most 
    //printing we have done this year.  send and ostream reference to 
    //here and kind of like traverse make a node pointed to the location
    //after head.  then while that node is not at head print the data 
    //inside the node with a space inbetween the current nodes count.
    //advanding currs location in the list till curr == &head.  
    void List::print ( ostream & ost ) const
    {
        Node * curr = head.next;
	    while ( curr != &head )
	    {
	        cout << curr->data << " " << curr->count << endl;
	        curr = curr->next;
	    }
    }


    //The following functions i did not find usefull for this program.  so
    //I wrote them out but decided not to use them.  Weather they work or
    //not i am not 100% sure.  
    /*
    bool List::find ( const Word foo )
    {
        Node * curr = trav( foo );
        return( curr != &head && curr->data == foo );
    }


    List::copy( const List & arg )
    {
         node * source = arg.head.prev;
         while ( sourc != &(arg.head) )
         insert (sourc->data );
         src = 
    }
   
    list & List::operator = ( List &arg)
    {
         if (this = &arg)
         clear ();
         copy(arg.head.next);
         return *this;
    }

    bool find ( const Word )
    {
    }
    */

