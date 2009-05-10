//Thomas Cross
//University of Omaha NE
//Soundex MAIN

#include <iostream>
#include <string>

using namespace std;

char * soundex (char word []);

char * soundex (char word [])
{
    char beginingchar = word[0];
    static char newword[6];
    strcpy (newword, "Z0000");

    int j = 0;

    for (int i = 0; word[i] != '\0'; ++i)
    {
        switch(tolower(word[i]))
        {
            case 'b':
            case 'p':
            case 'f':
            case 'v':
                if (word[i-1] != '1')
                {
                    word[i] = '1';
                    newword[j] = '1';
                    ++j;
                    break;
                }
                else
                {
                    break;
                }
            case 'c': 
            case 's': 
            case 'k': 
            case 'g':
            case 'j':
            case 'q':
            case 'x':
            case 'z':
                if (word[i-1] != '2')
                {
                   word[i] = '2';
                   newword[j] = '2';
                   ++j;
                   break;
                }
                else
                {
                    break;
                }
            case 'd': 
            case 't':
                if (word[i-1] != '3')
                { 
                    word[i] = '3';
                    newword[j] = '3';
                    ++j;
                    break;
                }
                else
                {
                    break;
                }
            case 'l':
                if (word[i-1] != '4')
                {
                    word[i] = '4';
                    newword[j] = '4';
                    ++j;
                    break;
                }
                else
                {
                    break;
                }
            case 'm': 
            case 'n':
                if (word[i-1] != '5')
                {
                    word[i] = '5';
                    newword[j] = '5';
                    ++j;
                    break;
                }
                else
                {
                    break;
                }
            case 'r':
                if (word[i-1] != '6')
                {
                    word[i] = '6';
                    newword[j] = '6';
                    ++j;
                    break;
                }
                else
                {
                    break;
                }
            default:
                if (i == 0)
                {
                    ++j;
                    break;
                }
                else
                {
                    break;
                }
        }    
    }

if (int(beginingchar) >= 97 && int(beginingchar) <= 122 ||int(beginingchar) >= 65 && int(beginingchar <= 90))
{
    newword[0] = toupper(beginingchar);
}
newword[5] = '\0';
return (newword);
}

int main ()
{
    //cout << "Input ten words" << endl;
    //for(int count = 0; count < 10; ++count)
    //{
    //    char inputword [40];
    //    cin >> inputword;
    //    cout << "the code for " << inputword << " is "; 
    //    cout << soundex (inputword) << endl;
    //}


return 0;
}
