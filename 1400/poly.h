Poly.h:

#include"term.h"

class Poly
{
    private:
        Poly ( const Poly & );
        const Poly & operator = ( const Poly & );
        class Node
        {
            public:
                Term data;
                Node * next;
                Node ( Node * n = NULL )
                    :next(n) {;;;}
        };
        Node * head;
        Node * trav ( const Term, Node * & ) const;
    public:
        Poly ( void )
            :head ( NULL ) {;;;}
        bool empty ( void ) const
        {
            return !head;
        }
        void insert ( const Term );
        void remove ( const Term );
        bool find ( const Term ) const;

};
