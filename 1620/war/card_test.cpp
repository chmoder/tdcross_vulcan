
#include<iostream>
using namespace std;
#include"card.h"
#include"queue.h"

int main()
{
    Card a,b,c;
    Queue foo;
    

    for ( int i = 0; i < 41; ++i )
    {
    foo.Enqueue(i);
    }

    for ( int i = 0; i < 41; ++i )
    {
        cout << foo.Dequeue() << " ";
        if ( i == 10 || i == 20 || i == 30 || i == 30 || i == 40 )
            cout << endl;
    }
    cout << endl; 


    cout << a << endl;


    b = 1;
    cout << b << endl;

    //if ( a < b )
    if ( a.operator<(b) )
        cout << "good" << endl;
    else
        cout << "bad" << endl;

    




    return 0;
}
