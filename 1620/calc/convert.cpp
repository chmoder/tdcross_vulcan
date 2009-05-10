/* File convert.cpp */

#include <iostream>
using namespace std;
#include "tstack.h"


//The below function is used to compare operator precidence
//for order of operations.
bool Operator_Cmp( char, char);

int main ()
{

    //Make a stack called stack1 of type char
    Stack<char> stack1;
    //push a perenthesis onto the stack
    stack1.Push('(');

    //the ch is used to hold all non numbers
    //filtering of non operator values occures in Operator_Cmp
    //num holds all the numbers while they are pushed onto the
    //screen.  isdigit checks to see if the char is a number 0-9.
    //if it is a digit the cin.putback function puts the function
    //back onto istream so I can assign it to num AS AN INT and 
    //print it to the screen.  Continuing the algorythm I check to make
    //sure that if there is a "(" i push it to the stack and when the
    //")" appears i pop the operators that occured inside the paren.
    //Finally the operators are evaluated using the Operator_Cmp
    //function.  passing the ch and the peek of whats inside the array.
    //how the operators are evaluated will be described in the 
    //actual function.  ANYWAY, if the operator is higher order or equal 
    //it is the array is popped to the screen and the opertor in ch 
    //is pushed onto the array.  if the operator is less it is simply
    //pushed onto the stack.  After all of the input stream has been
    //sent through the filter I pop the stack to the screen till the 
    //the computer finds the first "(" and stack is not empty.  
    //If durring that time the computer finds a "(" it pops it too.
    //then print a new line for clean ness.
    char ch;
    int num;
    while( cin >> ch )
    {
        if ( isdigit( ch ) )
        {
            cin.putback( ch );
            cin >> num;
            cout << num << " "; 
        }
        else if ( ch == '(' )
        {
            stack1.Push( ch );
        }
        else if ( ch == ')' )
        {
            while( stack1.Peek() != '(' )
            {
                cout << stack1.Pop() << " ";
            }
                stack1.Pop();
        }
        else if (stack1.Peek() == '(' )
        {
            stack1.Push( ch );
        }
        else if ( Operator_Cmp( ch, stack1.Peek() ) )
        {
            while ( Operator_Cmp( ch, stack1.Peek() ) == true )
            {
                cout << stack1.Pop() << " ";
            }
            stack1.Push( ch );
        }
        else if ( !Operator_Cmp( ch, stack1.Peek() ) )
            stack1.Push( ch );
    }
    while( stack1.Peek() != '(' && !stack1.Empty() )
            {
                cout << stack1.Pop() << " ";
                if ( stack1.Peek() == '(' || stack1.Peek() == ')' )
                {
                    stack1.Pop();
                }
            }

        printf("\n");
/*
        while (!stack1.Empty())
            cout << stack1.Pop() << " ";
        printf("\n");
`*/
        return (0);
}

   //The below function is used to evaluate priority of the top 
   //value in the stack and the operator you want to compare it
   //with.  According to order of operations I assign the 
   //operators accordingly.  If the value of the stack var is 
   //greater than or equal to the operator in question the func
   //returns true.  else false.  if it is not a legal operator it
   //always fails to be greater than a real opertor on the stack.
   bool Operator_Cmp( char foo, char bar)
   {
        int valf;
        int valb;

        switch(foo)
        {
        case '^':
            valf = 3;
            break;
        case '*':
        case '/':
            valf = 2;
            break;
        case '+':
        case '-':
            valf = 1;
            break;
        default:
            valf = 0;
        }
        switch(bar)
        {
        case '^':
                valb = 3;
                break;
        case '*':
        case '/':
                valb = 2;
                break;
        case '+':
        case '-':
                valb = 1;
                break;
        default:
                valb = 0;
        }

                return (valb >= valf);
    }

