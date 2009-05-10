//Name          :Thomas Cross
//Class         :1400009
//Program #     :pgm20
//Due Date      :10.23.08
//
//Honor Pledge  On my honor as a student of the University of Nebraska at Omaha,
// I have neither given nor recieved unauthorized help on this homework
// assignment.
//
//Signed1: Thomas Cross
//Signed2: 1337
//Signed3: tom.bz2@gmail.com

//Partners  :List the full names, CIST 1400 section and e-mail addresses

//Magic Square


#include <iostream>
using namespace std;

bool checkRows (int theSquare[] [4], const int magicvalue = 34);
bool checkColumns (int theSquare[] [4],  const int magicvalue = 34);
bool checkDiagonals (int theSquare[] [4], const int magicvalue = 34);
bool checkRange (int theSquare[] [4]);

int main()
{
    int theSquare[4][4];
    int x = 0;
    int y = 0;

    while (y <= 3)
    {
        cout << "Please enter row " << y+1 << endl;
        while (x <= 3)
        {
            cin >> theSquare[y][x];
            x++;
        }
        y++;
        x = 0;
    }
    
    if (checkRows(theSquare))
    {
       cout << "Rows: Valid" << endl;    
    }
    else
    {
       cout << "Rows: Invalid" << endl;
    } 
    
    if (checkColumns(theSquare))
    {
        cout << "Cols: Valid" << endl;
    }    
    else   
    {
        cout << "Cols: Invalid" << endl;   
    }

    if (checkDiagonals(theSquare))
    {
        cout << "Diag: Valid" << endl;
    }
    else
    {
        cout << "Diag: Invalid" << endl;
    }

    if (checkRange(theSquare))
    {
        cout << "Rang: Valid" << endl;
    }
    else
    {
        cout << "Rang: Invalid" << endl;
    }
    if ((checkRows(theSquare)) && (checkColumns(theSquare)) && (checkDiagonals(theSquare)) && (checkRange(theSquare)))
    {
        cout << "Magic: YES" << endl;
    }
    else
    {
        cout << "Magic: NO" << endl;
    }

return 0;
}


bool checkRows(int theSquare[][4], const int magicvalue)
{

    int x = 0;
    int y = 0;
    int sum = 0;
    bool valid = true; 
    while (y <= 3)
    {   
        sum = 0;
        while (x <= 3)
        {   
            sum = sum + theSquare[y][x];
            x++;
        }
        if (sum != magicvalue)
        {
            valid = false;
            y = 4;
        }       
        y++;
        x = 0;
    }
    return valid;    
}

bool checkColumns(int theSquare[][4], const int magicvalue)
{
    int x = 0;
    int y = 0;
    int sum = 0;
    bool valid = true;
    while (x <= 3)
    {
        sum = 0;
        while (y <= 3)
        {      
            sum = sum + theSquare[y][x];
            y++;
        }
        if (sum != magicvalue)
        {
            valid = false;
            x = 4;
        }
        x++;
        y = 0;
   }
return valid;
}

bool checkDiagonals(int theSquare[][4], const int magicvalue)
{
    int x = 0;
    int y = 3;
    int sum = 0;
    bool valid = true;
    while (x <= 3)
    {
        sum = sum + theSquare[x][x];
        x++;
    }
        if (sum != magicvalue)
        {
              valid = false;
              y = -1;
        }
        else
        {
            x = 0;
        }

    sum = 0;

    while ((x <= 3) && (y >= 0))
    {
        sum = sum + theSquare[x][y];
        x++;
        y--;
    }
        if (sum != magicvalue)
        {   
           valid = false;
        }      
        else
        {
            valid = true;
        }
return valid;
}

bool checkRange(int theSquare[] [4])
{
     int x = 0;
     int y = 0;
     int z = 0;
     int i = 0;
     int j = 0;
     int liniarSquare[16];
     bool valid = true;
     while (y <= 3)
     {
        while (x <= 3)
        {
            liniarSquare [z] = theSquare[y][x];
            x++;
            z++;
        }
     y++;
     x = 0;
     }
     
     while ((i <= 16) && (valid == true))
     {
        while ((j <= 16) && (valid == true))
        {
            if (i == j)
            {
                j++;
            }
            if ((liniarSquare [i] == liniarSquare[j]) || (i < 0) || (j >
                        17))           
            {
                valid = false;
		j = 17;
		i = 17;
            }
            j++;
        }
     i++;
     j = 0;
     }
return valid;
}
