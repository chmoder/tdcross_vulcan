/* File dheap.h */
#ifndef DHEAP_H
#define DHEAP_H

#include <iostream>
using namespace std;

class dheap
{
    private:
        int heapSize;
        int * dheapArray;
        int arraySize;
        int d;
        int iLC( int );
        int iRC( int );
        int iParent( int );
        //void BuildHeap();
        int percolateUp( int );
        void percolateDown( int );

    public:
        dheap ( int );
        ~dheap ( void );
        void dSize( int );
        bool Empty( void ) const;
        bool Full( void ) const;
        const int FindMin( void ) const;
        void Insert( const int );
        void growHeap( void );
        void buildTree( int *, int);
        void deleteMin( void );
        //void MakeEmpty( void );

/******************************************************************************
* Method printTree access private variables so I just put it in here to       *
* print the tree.  Printing tree in accourdance to the assignment.            *
******************************************************************************/
        void printTree( void )
        {
            cout << "Output: Heap (d=" << d << "): ";
            for( int i = 1; i <= heapSize; ++i)
            {
                cout << dheapArray[i] << " ";
            }
            cout << endl;
        }
};
#endif
