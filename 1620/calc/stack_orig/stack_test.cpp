/* File test.cpp */

#include <iostream>
using namespace std;
#include "tstack.h"

int main ()
{
    
    Stack<char> stack1;

    for(int i = 0; i < 100; ++i)
    {
        stack1.Push('a');
        cout << stack1.Peek() << " ";
    }
    printf("\n");
    for(int i = 0; i < 100; ++i)
    {
        printf("%c ",stack1.Pop());
    }
    printf("\n");
    

}

