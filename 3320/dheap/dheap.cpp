/* File dheap.cpp */
/******************************************************************************
* Program Title: D-Heap                                                       *
* Author: Thomas Cross                                                        *
* Class: CSCI3320, Fall 2009                                                  *
* Assignment #2                                                               *
******************************************************************************/


#include<iostream>
#include "dheap.h"
#include <cmath>
using namespace std;



/******************************************************************************
* Method dheap is the constructor used to make a heap.                        *
******************************************************************************/
dheap::dheap( int cap )
{
    heapSize = 0;
    dheapArray = new int [ cap + 1 ];
    arraySize = cap + 1;
}
/******************************************************************************
* Method ~dheap is the constructor used to destroy a heap.                    *
******************************************************************************/
//dheap destructor
dheap::~dheap( void )
{
    delete [] dheapArray;
}

/******************************************************************************
* Method dSize only job is to set the number of children for the "d"heap      *
******************************************************************************/
void dheap::dSize( int nchildren )
{
    d = nchildren;
}

/******************************************************************************
* Method iParent returns the location of the parent based on a calculation I  *
* observed.  Crucial part of insert method.                                   *
******************************************************************************/
int dheap::iParent( int i )
{
    if( floor((i + (d-2))/d) == 0)
        return 1;
    else
        return int(floor((i + (d-2))/d));
}

/******************************************************************************
* Method returns true if heapSize == 0.  "Empty Heap"                         *
******************************************************************************/
bool dheap::Empty ( void ) const
{
    return heapSize == 0;
}

/******************************************************************************
* Method Full ruturns true if the heapsize is 1 minus full.  used in grow     *
* and insert function.                                                        *
******************************************************************************/
bool dheap::Full( ) const
{
    return heapSize == arraySize - 1;
}

/******************************************************************************
* Method Percolate up is used to insert an item into the heap.  Uses the      *
Parent location a bunch for swapping in the case that the child of the temp   *
parent is less than the new parent.                                           *
******************************************************************************/
int dheap::percolateUp( int x )
{
    int place = ++heapSize;
    //cout << "place = " << place << " parent location = " << iParent(place) << endl << "x = " << x << " parent = " << dheapArray[ iParent(place) ] << endl;
    while ( place > 1 && x < dheapArray[ iParent(place) ] )
    {
        dheapArray[ place ] = dheapArray[ iParent(place)];
        place = iParent(place);
    }
        return place;
    /*
        for( ; place > 1 && x < dheapArray[ iParent(place) ]; place /= d )
    {
        //cout << "x =" << x << "  " << "parent = " << dheapArray[
        //    iParent(place) ] << "  " << endl;
        dheapArray[ place ] = dheapArray[ iParent(place)];
    }

    //dheapArray[ hole ] = x;
    return place;
    */
}

/******************************************************************************
* Method Insert checks to see if the array is full if yes grow array then     *
*insert else just insert.                                                     *
******************************************************************************/
void dheap::Insert ( const int x )
{
if(Full())
    growHeap();
dheapArray[ percolateUp( x ) ] = x;
}

/******************************************************************************
* Method growHeap is just what you think.  It makes a new array 2X as big as  *
* before and copys the heap exactly into the new one.                         *
******************************************************************************/
void dheap::growHeap( void )
{
    int * temparray;
    temparray = new int [ arraySize *= 2 + 1 ];
    for( int i = 0; i <= heapSize; ++i )
    {
        temparray[i] = dheapArray[i];
    }
dheapArray = temparray;

}

/******************************************************************************
* Method percoalteDown is used when doing a delete min because you need to    *
* ensure that your new min swaps with the elements to maintain heap order     *
* I made some calculations to check all of the children and swap with the     *
* Smallest.                                                                   *
******************************************************************************/
void dheap::percolateDown( int i  )
{
        if(Empty())
        {
            cerr << "Heap Empty no min to delete" << endl;
            printTree();
        }

    int changed = 0;
    do
    {
        changed = 0;
        int max = ( ( i * d ) + 1 );
        int min = ( max - ( d - 1 ) );
    
        int smallest = dheapArray[ min ];
        int smallestchild = min;

        
        if( max >= heapSize )
        {
            max = heapSize;
        }
        for( int x = min ; x <= max; ++x )
        {
            if( dheapArray[ x ] < smallest && dheapArray[ x ] < dheapArray[ i ] )
            {
                smallest = dheapArray[ x ];
                smallestchild = x;
            }
        }

      //cout << "min = " << min << " max = " << max << "  " << dheapArray[ smallestchild ] << "   " << dheapArray[ i ] << endl;
        if( dheapArray[ smallestchild ] < dheapArray[ i ] && dheapArray[ smallestchild ] <
                dheapArray[ i ])
        {
            int temp = dheapArray[ smallestchild ];
            dheapArray[ smallestchild ] = dheapArray [ i ];
            dheapArray[ i ] = temp;
            changed = 1;
        }
        
   //     printTree();
    i = smallestchild;
    }
    while( changed == 1 && i * d <= heapSize );

        
    /*
    int child;
    int tmp = dheapArray[ hole ];

    for( ; hole * 2 <= heapSize; hole = child )
    {
        child = hole * 2;
        if( child != heapSize && dheapArray[ child + 1 ]
                < dheapArray[ child ] )
            child++;
        if( dheapArray[ child ] < tmp )
            dheapArray[ hole ] = dheapArray[ child ];
        else
            break;
    }
    dheapArray[ hole ] = tmp;
    */
}

/******************************************************************************
* Method deleteMin checks to see if the heap is empty if not there is         *
* something to delete and hence does using the percolatedown method           *
******************************************************************************/
void dheap::deleteMin( void )
{
    if (Empty())
        cerr << "Heap Empty!  Nothing to delete! " << endl;
    else
    {
        dheapArray[ 1 ] = dheapArray[ heapSize-- ];
        percolateDown( 1 );
    }
}
/******************************************************************************
* build Tree is used to build a tree when the user inputs the initial data    *
******************************************************************************/
void dheap::buildTree( int * temp, int count )
{
    for( int x = 0; x < count; ++x )
    {
        //   cout << temp[x] << " ";
        Insert( temp[x] );
        //dheapArray[ percolateUp( temp[x] ) ];
    }
}
