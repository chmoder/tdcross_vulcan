/* File calc.cpp */

#include<iostream>
using namespace std;
#include "tstack.h"
#include "math.h"


//calculate is defined here and the driver portion is written on the 
//bottom of the program as is customary.  
float calculate(float right, float left, char ch);

int main()
{
    //create a Stack called stack1 of type float
    Stack<float> stack1;
    

    //ch is used to hold operators and left will be for the left 
    //side of the equation and right will be for the right side 
    //of the equation.  Num will hold numbers.  all numbers are
    //of type float for floating point equations.
    char ch;
    float left;
    float right;
    float num;

    //while input is active make it a char.  if that char is a 
    //digit then put it back and re-read it in as a float called
    //num.  THEN push that num into a FLOAT stack.  if it is not 
    //a number pop/assign the first number off the stack to 
    //right, the second number on the stack to left.
    //Then calculate passing right left and the opertaor (ch).
    //This will get pushed onto the stack for use in later
    //operations.  When there is no more data to be processed 
    //pop and cout the answer to the question.
    while( cin >> ch )
    {
        if ( isdigit( ch ) )
        {
            cin.putback( ch );
            cin >> num;
            stack1.Push( num );
        }
        else
        { 
            right = stack1.Pop();
            left = stack1.Pop();
            stack1.Push( calculate( right, left, ch ) );
        }
    }
    cout << stack1.Pop() << endl;


    return 0;
}

//code for calculate.  passing two values in question and an operator.
//if the operator matches one that should exist perform the calculation.
//assigning it to rval.  In this function i also check for a devide 
//by zero error.  If it exists then I output the error and exit(1).
//If the operator is not of the defind variables I
//output a clear error message and exit with the code of 2.
//Return rval of type float for the answer of the calculation.
float calculate(float right, float left, char ch)
{
    float rval = 0;
    switch(ch)
    {
        case '^':
            rval = powf(left, right);
            break;
        case '*':
            rval = left * right;
            break;
        case '/':
            {
                if ( right  == 0 )
                {
                    printf("Divide by zero error \n");
                    exit(1);
                }
                else
                rval = left / right;
            }
            break;
        case '+':
            rval = left + right;
            break;
        case '-':
            rval = left - right;
            break;
        default:
            cerr << "UNKNOWN OPERATOR!  HOW DID THIS HAPPEN?" << endl;
            exit(2);
    }

    return rval;
}     
