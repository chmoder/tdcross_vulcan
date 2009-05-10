/* File stack.h */

#ifndef TSTACK_H
#define TSTACK_H

#include <iostream>
using namespace std;


//The objective of this header file was to Template a class and 
//create a reusable stack that works for multiple data types

//Below I have templated the pointed array type, the value we are 
//pushing into the array, and the return type for Pop and Peek.
//This enables dynamic "STACK" types, and input types.

template <class T>
class Stack
{
    public:
        Stack(void);
        ~Stack(void);
        bool Empty(void) const;
        void Push(const T);
        T Pop(void);
        T Peek(void) const;
    private:
        int cap;
        T * arr;
        int top;
};
#endif

//Starting here we are putting the implementation in the header file
//because the compiler can not wrap the template in an implementation
//file.  ***NOTICE*** the "template <class T>" above all
//the member function implemations and definitions.

//Below, I assign the begining capacity of the stack, and starting
//location of the stack.  I make a new array of size cap and type T.

template <class T>
Stack<T>::Stack(void)
{
    //:cap(5), arr(new int[cap]), top(-1) {;;;}
    cap = 5;
    arr = new T [cap];
    top = -1;
}

//this deletes the constructor defined above.
template <class T>
Stack<T>::~Stack(void)
{
    delete []arr;
}

//Below function returns true if top is less than 0
//therefore stack would be empty.
template <class T>
bool Stack<T>::Empty(void) const
{
    return top < 0;
}

//Below I have made a if statement check to make sure that if
//the next top is greater than or equal to the capacity 
//of the array to grow.  I grow the array by creating a var called
//ncap and making it twice as big as the original capacity, a new
//array called narr of type T and size ncap.  then i copy the data
//from the old array to the new array with a for loop.  Then i delete 
//the old array and point new array to the old array name and the new
//capacity with the old capacity.  and then of course push the data into
//the array by incrementing the location of top and assigning foo 
//(the imputed data).  If the array is not going to be expanded then it
//just assignes the value to the next element in the array.  Input type 
//T is good because now you can store and retrieve data of the same
//type.  HENCE TEMPLATE
template <class T>
void Stack<T>::Push(const T foo)
{
    if (top + 1 >= cap )
    {
        int ncap = cap * 2;
        T * narr = new T [ncap];
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

//This member function makes a return value of type T.
//This is good because if you dont make your return type of T
//the compile will output a conversion error.  ex. char to float.
//then if the stack is not empty it assignes the top of the array
//to rval and retuns it to the calling function.
template <class T>
T Stack<T>::Peek(void)const
{
    T rval = 0;
    if (!Empty())
    rval = arr[top];
    return rval;
}

//same as previous except after assigning the value to rval 
//I decrement the top so that the item "pops" off the array.
template <class T>
T Stack<T>::Pop(void)
{
    T rval = 0;
    if (!Empty())
    {
        rval = arr[top];
        --top;
    }
    return rval;
    //return peek();
}

