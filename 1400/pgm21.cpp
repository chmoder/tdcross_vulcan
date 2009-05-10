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

//Timer + Clock

#include <iostream>
#include "Time.h"

using namespace std;

    void display ( Time object,  char format );
    void addMinute (Time object, Time object2, int minutes, char foramt);

int main ()
{    
    Time clock, alarm;
    int hr,mn;
    char colon;
    int minutes;
    char format;
    
    cout << "Please enter the clock time in the format HH:MM > " << flush;
    cin >> hr >> colon >> mn;
    clock.setTime (hr,mn, 0);
 
     cout << "Please enter the alarm time in the format HH:MM > " <<
     flush;
     cin >> hr >> colon >> mn;
     alarm.setTime (hr,mn, 0);
    
    cout << "Maximum minutes the clock should run? ";
    cin >> minutes;
       
    cout << "Display results in 'u'niversal or 's'tandard format? ";
    cin >> format;
    
    display( clock , format );
    addMinute (clock, alarm, minutes, format);        
    
return 0;
}

void display ( Time object, char format )
{
    if (format == 'u')
    {
        cout << endl << "The clocks current time is: ";
       object.printUniversal ();
        cout << endl;
    }
   else if (format == 's')
   {
       cout << "The clocks current time is: ";
       object.printStandard ();
       cout << endl;
   }    
   else
       cout << "bad input" << endl;
}

void addMinute (Time object, Time object2, int minutes, char format )
{
  if (format == 'u')
          {
              cout << "The clocks current time is: ";
              object2.printUniversal ();
              cout << endl;
          }
     else if (format == 's')
            {
            cout << "The clocks current time is: ";
            object2.printStandard ();  
            cout << endl; 
            }
        else
                   cout << "bad input" << endl;

cout << endl << "Watching the clock ... " << endl << endl;        

/*
int j = 0;
while ( j < minutes)
{
    if (y == 60)
    {
        y = 0
        x++
    }
object(x, y, 0) = object + 1;
x++;
}

*/
}
