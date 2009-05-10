#include <iostream>
using namespace std;
#include <iomanip>
#include "Time.h"

Time::Time( int h, int m, int s ) 
{
 	setTime ( h, m, s );
}

void Time::setTime(int h, int m, int s)
{
 	if ( h >= 0 && h < 24 )
 	  hour = h;
 	else
 	  hour = 0;
 	if ( m >= 0 && m < 60 )
 	  minute = m;
 	else
 	  minute = 0;
 	if ( s >= 0 && s < 60 )
 	  second = s;
 	else
 	  second = 0;
}

void Time::getTime( int &h, int &m, int &s )
{
 	h = hour;
 	m = minute;
 	s = second;
}

void Time::printUniversal()
{
 	cout << setfill ('0');
 	cout << setw(2) << hour << ":";
 	cout << setw(2) << minute << ":";
 	cout << setw(2) << second;
 	cout << setfill (' ');
}

void Time::printStandard()
{
 	cout << setfill ('0');
	if (hour % 12 == 0)
 	   cout << "12:";
 	else
 	   cout << hour % 12 << ":";

 	cout << setw(2) << minute << ":";
 	cout << setw(2) << second;

    if (hour < 12)
 	   cout << " AM";
    else
       cout << " PM";

 	cout << setfill (' ');
}

