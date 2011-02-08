/*File main.cpp */
#include<iostream>
#include "dheap.h"
#include <cmath>
using namespace std;

/******************************************************************************
* Method main is the driver of my dheap class.  First it makes a large array  *
* to prevent growing.  Then it reads the input using a custom built function  *
* that dumps all data but +- numbers.  It uses an older cin.get method because*
* its the only way I found to get the integers without converting from char   *
* to int which should be not nessesary.                                       *
* Next I loop till the user presses 4 repeating the choices insert, delete    *
* quit.  The user is shoudl pic one to use the heap.                          *
******************************************************************************/
int main()
{
    char input;
    int dsize = 2;
    int num;
    int temp [1000000]; 
    
    dheap heap(1000000);
    
    int count = 0;
    cout << "Enter heap elements: ";
    while( input = cin.get() )
    {
        if( input == '\n' && count != 0 )
        {
            break;
        }

        if ( isdigit( input ) || input == '-' )
        {
            cin.putback( input );
            cin >> num;
            temp[count] = num;
            ++count;
            //heap.Insert( num );
            //heap.printTree();
        }
            
    }
    
    cout << endl << "Enter d: ";
    cin >> dsize;
    heap.dSize( dsize );

    heap.buildTree( temp, count );    
    heap.printTree();

    cin.clear();
    int choice = 0;
    int val = 0;
    while ( choice != 4 )
    {
        cout << "Press 1) for insert, 2) for deleteMin, 4) quit" << endl << "Enter choice: ";
        cin >> choice;
        if( choice == 1 )
        {
            cout << "Enter element to insert: ";
            cin >> val;
            heap.Insert(val);
            heap.printTree();
        }
        else if( choice == 2 )
        {
            heap.deleteMin();
            heap.printTree();
        }
        /*
        else if(choice == 3 )
        {
            cout << "Enter d: ";
            cin >> val;
            heap.dSize(val);
            dheap heap2(10000);
            for( int x = 0; x <= heap.heapSize; ++x )
            {
                heap2.dheapArray[x] = heap.dheapArray[x];
            }
            heap.buildTree(heap2.dheapArray, heap.heapSize);
        }
        */
    }

        return 0;
}
