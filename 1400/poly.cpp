#include<iostream>
#include"poly.h"
using namespace std;

Poly::Node * Poly::trav ( const Term foo, Node * & prev ) const
{
    Node * curr = head;
    prev = NULL;
    while ( curr && curr->data < foo )
    {
        prev = curr;
        curr = curr->next;
    }
    return curr;
}

bool Poly::find ( const Term foo ) const
{
    Node * prev = NULL;
    Node * curr = trav ( foo, prev);
    return ( curr && curr-> data == foo);
}

void Poly::insert ( const Term foo)
{
    Node * prev = NULL;
    Node * curr = trav( foo, prev );
    Node * tmp = new Node ( foo, curr );
}

void Poly::copy ( const Node * src )
{
    if ( src )
    {
        copy ( src->next );
        insert ( src->data );
    }
}
/*
   void Poly::print ( ostream & ost ) const
   {

   }
   */

