/******************************************************************************
* Program Title: Spin-Out Puzzle                                              *
* Author: Thomas Cross                                                        *
* Class: CSCI3320, Fall 2009                                                  *
* Assignment #1                                                               *
******************************************************************************/

#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;


unsigned int calcSpins( int );
unsigned int recurSpin( unsigned int, int );
void print( unsigned int, int );


/******************************************************************************
* Method calcSpins is used to calculate the number of spins needed to         *
* solve the spin out puzzle.  It does this by utilizing recurrence            *
* relation recurring while number of spins is not one and saving the          *
* previous number of spins and adding on the next relation which is           *
* 2(spins) unless your next disk is even then 2(spins) + 1 please see my      *
* report for a better explenation.                                            *
* INPUT PARAMETERS : nSpinners is the number of spinners entered by the       *
* user from main.                                                             *
* OUTPUT : Returnes an unsinged int ( the number of spins ) unsigned          *
* becuase of the bitwise operations in recurSpin.                             *
******************************************************************************/
unsigned int calcSpins( int nSpinners )
{
    static int spins = 1;
    static int nSpinners2 = nSpinners;

    if( nSpinners == 1 )
    {
        recurSpin( spins, nSpinners2 );
        return (spins);
    }
    else
    {
        if( spins % 2 == 1 )          
            spins = (2 * spins);
        else if( spins % 2 == 0 )
            spins = (2 * spins) + 1;
    }
            calcSpins(--nSpinners);
            return (spins);
}


/******************************************************************************
* FUNCTION recurSpin is used to recursively push bits arround to produce      *
* the desired output by passing the the number of spins XOR the bit           *
* shift of one reference this: http://www.aip.de/~ast/EvolCompFAQ/Q21.htm     *
* the function recures till we pass 0 so we print down to 0.                  *
* INPUTS PARAMATERS : spins.  spins is the number of spins passed from        *
* calcSpins.                                                                  *
* OUTPUT : Returnes spins -1 to itself to send to my print function to        *
* print out the base 2 representation vs the base 10.                         *
******************************************************************************/
unsigned int recurSpin( unsigned int spins, int nSpinners )
{
    static int temp = spins;
    
    if( temp < 0 )
        cout << endl;
    else
    {
        print( (spins ^ ( spins >> 1 ) ), nSpinners );
        --temp;
        return recurSpin(--spins, nSpinners);
    }
    return 0;  //to satisfy compile warning
   

}
/******************************************************************************
* FUNCTION print is used to convert a base 10 number to base 2 and print      *
* it to the screen.                                                           *
* INPUT PARAMATERS : n.  n is the kth number of spin.  I convert base 10      *
* to base 2 by anding each bit in the number with one.  If result == 1        *
* then it prints a one If result == 0 then it prints a 0.                     *
* OUTPUT : outputs the ith bit in the kth graycode. has no return as it is    * 
* void.                                                                       *
******************************************************************************/
void print( unsigned int n, int nSpinners )
{
    for (int i=(nSpinners-1); i>=0; i--) // go from MSB to LSB
    {
        int bit = (( n >> i) & 1); //and ith bit with 1 
        cout << bit; //print ith bit to screen
    }
    cout << " ";
    static int count = 0;
    if( count % 3 == 0)
        cout << endl;
    ++count;
}

/******************************************************************************
* int main is the main function  that askes user for number of spinners       *
* till the user enters a number between 1 and 20 inclusive. Then passes       *
* the number to calcSpins to calculate the number of spins requiered to       *
* solve the puzzle.  Returnes zero if completes.                              *
******************************************************************************/
int main()
//int main( int argc, char ** argv[] )
{
    int nSpinners = 0;
    clock_t start, end;
    double elapsed;

    start = clock();
    /*
    if ( argc != 2 )
    {
        cerr << "Spin-Out: You must specify a number of disks(up to 20). \n"
            << "Try `spin-out 7" << endl;
        exit(1);
    }
    */
    
    do
    {
        cout << "Please input the number of spinners (max 20): ";
        cin >> nSpinners;
    }
    while( nSpinners < 1 || nSpinners > 20 );

    calcSpins( nSpinners );
    cout << "Total number of moves: " << calcSpins(1) << endl;
    

    end = clock();
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;

    //cout << start << endl;
    //cout << end << endl;
    cout << "Processor time in seconds (not I/O)= " << elapsed << endl;

    return 0;
}
