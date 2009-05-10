//Thomas Cross
//University of Omaha NE
//Soundex MAIN

/*This program converts 10 words into a soundex code.  There are two
* issues with it.  Issue one: This program does not input default values
* into the array unless I close out and redo it.  In other words when in
* loop the values are saved.  strcpy sounds like a dirty way to fix it.
* Problem two: the "l" works only most of the time and I can't find the
* bug right now.  ...Doesn't seem logical.  BUT!  Last night at 11:30 
* I woke up and found a new way to do the conversion, 0 check, previous 
* letter check and return all in one step.  I feel so dumb for not 
* figuring this out earlier.  It has been a year since i programed 
* anything but i am excited to get the new pgm implemented.  
* So here is this one for now.
*/


#include <iostream>
#include <string>

using namespace std;

char * soundex (char word []);

char * soundex (char word [])
{
    static char newword2 [40] = {'Z','0','0','0','0'};
    static char newword [40];
    int j = 0;

    //switch statement to format the word into its correct code value
    for (int i = 0; word[i] != '\0'; ++i)
    {
        switch(tolower(word[i])) //lowercase all input data
        {
            case 'b':
            case 'p':
            case 'f':
            case 'v':
                newword[i] = '1';
                break;
            case 'c': 
            case 's': 
            case 'k': 
            case 'g':
            case 'j':
            case 'q':
            case 'x':
            case 'z':
                newword[i] = '2';
                break;
            case 'd': 
            case 't':
                newword[i] = '3';
                break;
            case 'l':
                newword[i] = '4';
                break;
            case 'm': 
            case 'n':
                newword[i] = '5';
                break;
            case 'r':
                newword[i] = '6';
                break;
            default:             
                newword[i] = '0';
        }    
    }
    //duplicate and "0" checker
        int y = 0;
        for (int x = 0; newword[x] != '\0'; ++x)
        {
            ++y;//y == x + 1 and chk is x the same as next char or '0'
            if (newword[x] != newword[y] && newword[x] != '0')
            {
                newword2[j] = newword[x];
                ++j;//only move index if array2 is edited
            }
        }

//ascii validation of first letter lowercase && caps       
if (int(word[0]) >= 97 && int(word[0]) <= 122 || int(word[0]) >= 65 && int(word[0]) <= 90 )
{ 
    newword2[0] = toupper(word[0]);
}
else //if not ascii then make arr[o] = z
{
    newword2[0] = 'Z';
}
    newword2[5] = '\0';
    return (newword2); //return fully functional word
}

int main ()
{
    char inputword [40]; //input from user
    cout << "Input ten words" << endl;
   
    for (int x = 0; x < 10; ++x) //loop to request 10 words in a row
    {
        cin >> inputword;
        cout << "the code for " << inputword << " is " << soundex (inputword) << endl; //output
    }

return 0;
}
