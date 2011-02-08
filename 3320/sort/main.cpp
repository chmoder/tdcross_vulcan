/******************************************************************************
* Program Title: sort                                                         *
* Author: Thomas Cross                                                        *
* Class: CSCI3320, Fall 2009                                                  *
* Assignment #3                                                               *
******************************************************************************/
#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <cctype>

using namespace std;

inline void swap( int [], int, int );
void quickSort(int [], int, int, int, int);
void insertionSort( int [], int );
void findk( int [], int, int );
void findkn(int [], int, int, int);
int randomNumber( int );

//TODO Multithread this program!
//structs were an attempt to multithread.
/*
struct upper_struct
{
		int *array;
        int j;
        int end;
        int k;
};   
struct lower_struct
{
		int *array;
        int j;
        int start;
        int k;
};
*/

/******************************************************************************
* The numeric limit of int seems to be a limit of my program.  So far I have  *
* tested sorting over 2.1 billion elements in avg. > 16 minutes.  Most of main*
* appears to be command line arguments which really seems to hide my main     *
* methods.  Basicly if you type                                               *
* ./sort -n [num elements] -q [quicksort] -i [inertion sort] -k [k value]     *
* you will find your k after sorting it.  for help type ./sort -h             *
* I spent many hours 20 <> 30 on this program and found it quite interesting. *
******************************************************************************/
int main (int argc, char * const argv[]) 
{
    clock_t start, end;
    double elapsed;
    int max = 20000;        //default maxsize for array
    int kflag = 0;          //used to flag whether or not to find k
    int iflag = 0;
    int qflag = 0;
    int foundk = 0;
    int k;                  //used for sum of 2 n.
    int c;
    
    if (argc < 4)
    {
        cerr << "Usage: " << argv[0] << " [-nkiqh] [-n number of elements] [-k find two n that equal k]" << endl; 
        cerr << "Usage: " << argv[0] << " [-i insertion sort] [-q quicksort] [-h help]" << endl;
        cerr << "-n and -i or -q is required.  ex: " << argv[0] << " -n 1000 -q -k 6" << endl;
        exit(1);
    }       
    while ((c = getopt (argc, argv, "n:k:i::q::h::")) != -1)
        switch (c)
        {
        case 'n':
            {
                if(isdigit(*optarg))
                {
                    max = atoi(optarg);
                    ++max;
                }
                else
                {
                    cerr << "Option -n must have the number of elements to sort." << endl; 
                    exit(1);
                }
            break;
            }
        case 'k':
            if(isdigit(*optarg))
            {
                k = atoi(optarg);
                kflag = 1;
            }
            break;
        case 'i':
            iflag = 1;
            break;
        case 'q':
            qflag = 1;
            break;
        case 'h':
            cerr << "Usage: " << argv[0] << " [-nkh] [-n number of elements] [-k find two n that equal k] [-h help]" << endl;
            cerr << argv[0] << ": Required option -n must have the number of elements to sort." << endl; 
            cerr << argv[0] << ": Required option -i or -q to define insertion or quicksort" << endl; 
            cerr << argv[0] << ": Optional option -k will do a O(n^2) search for two elements that = k" << endl; 
            cerr << argv[0] << ": Type quicksort -h to see this menu." << endl; 
            exit(1);
        case '?':
            if (optopt == 'c')
            {
                fprintf (stderr, "Option -%c requires an argument.\n",
                        optopt);
            }
            else if (isprint (optopt))
                fprintf (stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf (stderr,"Unknown option character `\\x%x'.\n",optopt);
            return 1;
        default:
            abort ();
        }
    
        if( iflag == 0 && qflag == 0)
        {
            cerr << argv[0] << ": Required option -i or -q to define insertion or quicksort" << endl; 
            abort();
        }
            
        //cout << "Now checking for K, the sum of two numbers in this array" << endl;
        //cout << "Please input a value of k for me to find: ";
        //cin >> k;

    start = clock();

    //DEFINE MAX FOR SEARCH   
	//int max = numeric_limits<int>::max(); 
    //max = 200000;

    //cout << "**Maximum long value: " << numeric_limits<long>::max() << endl;
    //cout << "**Maximum int value: " << numeric_limits<int>::max() << endl;

    cout << "Making random array of ints sizeof " << max-1 << endl;
    int *array = new int[max];
    
    for( int i = 0; i < max; ++i )
    {
        array[i] = randomNumber(max);
    }
    cout << "Finished writing random values to the array" << endl;
    
    
    //sorting methods
    if(iflag != 0)
    {
        cout << endl << "Now sorting " << max-1 << " elements using insertion sort..." << endl;
        insertionSort(array,max - 1);
    }
    if(qflag != 0)
    {
        time_t startQuick, endQuick;
        time(&startQuick);
        
        cout << endl << "Now sorting " << max-1 << " elements using quicksort..." << endl;
        quickSort(array, 0, max - 1, k, kflag );

        time(&endQuick);
        cout << "    Processor time in seconds for QuickSort (not I/O)= " << difftime(endQuick, startQuick) << endl;

    }
    
    //Print First and last four segments of aray
    /*
    cout << "Printing first and last four elements in the array: " << endl;
    for( int i = 0; i < 4; ++i)
        cout << array[i] << " ";
    cout << "| ";
    for( int i = max - 5; i < max; ++i)
        cout << array[i] << " ";
    cout << endl;
    */

    //Search for k using both methods
    if( kflag == 1 )
    {  
        cout << endl << "Finding k using O(n) method... "<< endl;
        findkn( array, 0, max - 1, k); //for O(n)
        cout << endl << "Finding k using O(n^2) method... "<< endl;
        findk( array, k, max - 1 );  //for O(n^2)
    }

    delete[] array;
    cout << endl << "Deleted Array, program closing." << endl;
    
    end = clock();
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << "    Total Processor time in seconds (not I/O)= " << elapsed << endl;
   
    return 0;
}

/******************************************************************************
* Method to make random numbers for my array.                                 *
******************************************************************************/
int randomNumber(int hi)  
{
    const float scale = rand()/float(RAND_MAX);
    return int(scale*hi + 0.5); 
}

/******************************************************************************
* i = index left-to-right, j = index right-to-left if more than two elements  *
* to sort then sort pivot is the first element in the partition while i has   *
* not passed j in the scan increment i and stop when an element is greater    *
* than the pivot decrement j till find and element < pivot if the left_index <* 
* right_index, swap after i and j have crossed swap pivot and j recursively   *
* quicksort left then right partion once the array has reached 1 element      *
* return uncomment the first block to see the first fifty elements.  Unblock  *
* the second two one liners to enable quick sort completion wich really slows *
* down this algarithim Also sadly due to the requirements of the problem from *
* the book I am required to add some functionality to find two elements that  *
* equal k which is done inline On the bottom I wrote an O(n^2) function to do *
* it.  This is  done later in two different functions.                        *
******************************************************************************/
void quickSort(int array[], int start, int end, int k, int kflag)
{
    /*
    for(int i = 0; i < 50; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
	*/

    int i = start;                          
	int  j = end;                           
    static int tf = 0;
	
    if (end - start >= 1)                   
	//if(start + 10 <= end)                   
	{
		int pivot = array[start];       
		
		while (j > i)                   
		{
			while (array[i] <= pivot && i <= end && j > i)  
            {
                /*
                if (kflag == 1)
                {
                    if(array[i] + array[j] == k)
                    {
                        cout << endl << "array[" << i <<"] + array[" << j << "] = " << k << endl;
                        cout << array[i] << " + " <<  array[j] << " = " << k << endl << endl;
                        tf = 1;
                    }   
                }   
                */
                i++;    
            }
			while (array[j] > pivot && j >= start && j >= i) 
            {
                /*
                if (kflag == 1)
                {
                    if(array[i] + array[j] == k)
                    {
                        cout << endl << "array[" << i <<"] + array[" << j << "] = " << k << endl;
                        cout << array[i] << " + " <<  array[j] << " = " << k << endl << endl;
                        tf = 1;
                    }
                }
                */
				j--; 
            }
			    if (j > i)                                    
                    swap(array, i, j);                      
        }
		
        swap(array, start, j);          
        quickSort(array, start, j - 1, k, kflag); 
		quickSort(array, j + 1, end, k, kflag);   
    }
    else    
	{
        //if( tf == 0 && j + 2 == end)
            //cout << j << " Could not find two numbers with a sum of " << k << endl;
        //insertionSort( array, end );
            return;
	}
}


/******************************************************************************
* O(n^2) Start at begining.  Till you reach the end of the array take the     *
* next element and check to see if the previous element is bigger than the    *
* current one.  If yes move down.  Repeat.                                    *
******************************************************************************/
void insertionSort( int array[], int end )
{
    clock_t startInsert, endInsert;
    double elapsedInsert;
    startInsert = clock();
    
    int i, j, index;

    for( i = 1; i <= end; ++i )
    {
        index = array[i];
        j = i;
        while((j > 0) && (array[j-1] > index))
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = index;
    }
    
    endInsert = clock();
    elapsedInsert = ((double) (endInsert - startInsert)) / CLOCKS_PER_SEC;
    cout << "    Processor time in seconds for Insertion Sort (not I/O)= " << elapsedInsert << endl;
}

/******************************************************************************
* Made the swap inline to allow faster swapping.                              *
* ...Probably a compiler optimization but just in case.                       *
******************************************************************************/
inline void swap(int array[], int index1, int index2) 
{
	int temp = array[index1];           // store the first value in as temp
	array[index1] = array[index2];      // copy the value of the second into the first
	array[index2] = temp;               // copy the value of the temp into the second
}


/******************************************************************************
* findk is a simple algarithim after thinking about it.  Sorting the array is *
* not required.  Just two pointers at the begining then increment one till    *
* the end; the other when the other reaches the end.                          *
******************************************************************************/
void findk( int array[] , int k, int end )
{
    clock_t startFindk, endFindk;
    double elapsedFindk;
    int jk = 0;
    int i, j;
    
    startFindk = clock();
    
    for( int i = 0; i <= end; i++ )
    {
        for( int j = 0; j <= end; j++ )
        {
        //cout << i << "  " << j << "  ";
        //cout << array[i] << "  "<< array[j] << endl;
            if( array[i] + array[j] == k)
            {
                //cout << "array[" << i <<"] + array[" << j << "] = " << k << endl;
                //cout << array[i] << " + " <<  array[j] << " = " << k << endl;
                jk = 1;
            }            
            
            if(i == end && j == end || jk == 1)
            {
                if(jk == 1)
                {
                    cout << "  K found using O(n^2) method!" << endl;

                    endFindk = clock();
                    elapsedFindk = ((double) (endFindk - startFindk)) / CLOCKS_PER_SEC;
                    cout << "    Processor time in seconds for findk O(n^2) (not I/O)= " << elapsedFindk << endl;
                }
                else
                {
                    cout << "  K not found using O(n^2) method!" << endl;

                    endFindk = clock();
                    elapsedFindk = ((double) (endFindk - startFindk)) / CLOCKS_PER_SEC;
                    cout << "    Processor time in seconds for findk O(n^2) (not I/O)= " << elapsedFindk << endl;
                }
                return;
            }
        }

    }
    
}

/******************************************************************************
* findkn is a simple algarithim after thinking about it.  First sort the      *
* array, now that we know it's sorted just start at the begining and the end  *
******************************************************************************/
void findkn(int array[], int start, int end, int k)
{  
    clock_t startFindkn, endFindkn;
    double elapsedFindkn;
    int i = start;
    int j = end;
    bool foundk = false;
    bool done = false;


    startFindkn = clock();

    while(!done)
    {
        //cout << i << "  " << j << "  ";
        //cout << array[i] << "  "<< array[j] << endl;
        if( i == j || array[i] + array[j] == k )
        {   
            if( array[i] + array[j] == k )
            {
                foundk = true;
            }
            done = true;
        }
        else if( array[i] + array[j] > k )
            j--;
        else if( array[i] + array[j] < k )
            i++;
    }
    if(foundk)
        cout << "  K found using O(n) method!" << endl;
    else
        cout << "  K not found using O(n) method!" << endl;
    
    endFindkn = clock();
    elapsedFindkn = ((double) (endFindkn - startFindkn)) / CLOCKS_PER_SEC;
    cout << "    Processor time in seconds for findk O(n) (not I/O)= " << elapsedFindkn << endl;
}
