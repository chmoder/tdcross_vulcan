#include<iostream>
using namespace std;
#include"word.h"


int main()
{
    Word foo1 = "Antidisestablishmentarianism"; // const char * construction
    cout << " foo1 = " << foo1 << endl;

    Word foo2(foo1);            // copy constructor
    cout << " foo2 = " << foo2 << endl;

    Word foo3("construction");  // explicit constructor for const char *
    cout << " foo3 = " << foo3 << endl;

    Word foo4;
    foo4 = "xyz";               // assignment for const char *
    cout << " foo4 = " << foo4 << endl;

    Word foo5;
    foo5 = foo4;                // homogeneous assignment
    cout << " foo5 = " << foo5 << endl;
    foo5 = "XYZ";
    cout << " foo5 = " << foo5 << endl;

    // test construction and assignment with a NULL pointer
    Word base = NULL;   // construction
    base = NULL;        // assignment
    base = "past the NULL construction and assignment";
    cout << base << endl;

    // test the comparisions
    int fail = 0;           // counter for failures
    if ( foo1 == foo2 )
    {
        cout << "'" << foo1 << "' == '" << foo2 << "'" << endl;
    }
    else
    {
        cout << "failed test 1 "<< endl;
        ++fail;
    }

    if ( foo1 != foo3 )
    {
        cout << "'" << foo1 << "' != '" << foo3 << "'" << endl;
    }
    else
    {
        cout << "failed test 2 "<< endl;
        ++fail;
    }

    if ( foo3 < foo4 )
    {
        cout << "'" << foo3 << "' < '" << foo4 << "'" << endl;
    }
    else
    {
        cout << "failed test 3 "<< endl;
        ++fail;
    }

    if ( foo4 > foo3 )
    {
        cout << "'" << foo4 << "' > '" << foo3 << "'" << endl;
    }
    else
    {
        cout << "failed test 4 "<< endl;
        ++fail;
    }

    if ( foo3 <= foo3 )
    {
        cout << "'" << foo3 << "' <= '" << foo3 << "'" << endl;
    }
    else
    {
        cout << "failed test 5 "<< endl;
        ++fail;
    }

    if ( foo4 >= foo4 )
    {
        cout << "'" << foo4 << "' >= '" << foo4 << "'" << endl;
    }
    else
    {
        cout << "failed test 6 "<< endl;
        ++fail;
    }

    if ( foo3 <= foo4 )
    {
        cout << "'" << foo3 << "' <= '" << foo4 << "'" << endl;
    }
    else
    {
        cout << "failed test 7 "<< endl;
        ++fail;
    }

    if ( foo4 >= foo3 )
    {
        cout << "'" << foo4 << "' >= '" << foo3 << "'" << endl;
    }
    else
    {
        cout << "failed test 8 "<< endl;
        ++fail;
    }

    if ( foo4 == foo5 )
    {
        cout << "'" << foo4 << "' == '" << foo5 << "'" << endl;
    }
    else
    {
        cout << "failed test 9 "<< endl;
        ++fail;
    }

    // disposative test with equivalence
    Word t1= "foo";
    Word t2= "foo";
    
    if ( t1 == t2 )
    {
        cout << "ok" << endl;
    }
    if ( t1 != t2 )
    {
        cout << "failed test 10 a" << endl;
        ++fail;
    }
    if ( t1 < t2 )
    {
        cout << "failed test 10 b" << endl;
        ++fail;
    }
    if ( t1 > t2 )
    {
        cout << "failed test 10 c" << endl;
        ++fail;
    }

    // test the [] operators
    char brackets[] = "pneumonoultramicroscopicsilicovolcanoconiosis";
    base = brackets;
    for ( int i = 0 ; brackets[i] ; ++i )
    {
        // read values with the []
        if ( base[i] != brackets[i] )
        {
            cout << "failed test 11" << endl;
            ++fail;
        }
    }

    
    // assign a value with the []
    base[0] = 'P';
    if ( base[0] != 'P' )
    {
        cout << "failed test 11" << endl;
        ++fail;
    }
    
    cout << "base = " << base << endl;

    cout << " this program failed " << fail << " test"
		<< ( fail == 1 ? "" : "s" )<< endl;


    return 0;
}



