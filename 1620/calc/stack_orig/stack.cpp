/* File stack.cpp */

#include <iostream>
using namespace std;
#include "tstack.h"

Stack::Stack(void)
{
    //:cap(5), arr(new int[cap]), top(-1)
    cap = 5;
    arr = new int [cap];
    top = -1;
}

Stack::~Stack(void)
{
    delete []arr;
}

bool Stack::Empty(void) const
{
    return top < 0;
}

void Stack::Push(const int foo)
{
    if (top + 1 >= cap )
    {
        int ncap = cap * 2;
        int * narr = new int [ncap];
        for ( int y = 0; y < cap; ++y )
        {
            narr [ y ] = arr [ y ];
        }
        delete [ ] arr;
        arr = narr;
        cap = ncap;

        arr [++top] = foo;
    }
    else
    {
        arr[++top] = foo;
    }
}

int Stack::Peek(void)const
{
    int rval = 0;
    if (!Empty())
    rval = arr[top];
    return rval;
}

int Stack::Pop(void)
{
    int rval = 0;
    if (!Empty())
    {
        rval = arr[top];
        --top;
    }
    return rval;
    //return peek();
}
