//Name          :Thomas Cross
//Class         :1400009
//Program #     :pgm15
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

//Horroscope

#include <iostream>

using namespace std;

int main ()
{
int month;
int day;
int year;
char hyphen;
char hyphen2;
int sentinal = 1;
int leap;

//cout << "Please enter a date between 1875 and 2199.  month-day-year.  ex 04-10-1988." << endl;

//cin >> month >> hyphen >> day >> hyphen2 >> year;
 
//cout << month << hyphen << day << hyphen2 << year << endl;
//cout << year << endl;

while (sentinal > 0)
{
cout << "Enter a birthdate between 1875 and 2199.  month-day-year.  ex 04-10-1988." << endl;

cin >> month >> hyphen >> day >> hyphen2 >> year;


if ((year < 1875) || (year > 2199)) 
{
cout << "Bad Year" << endl;
sentinal = 1;
continue;
}
else 
sentinal = 0;


if ((year % 4 == 0) && (year % 100 != 0)  || (year % 400 == 0))
leap = true; 
else
leap = false;



if ((month <= 12) && (month > 0))
sentinal = 0;
else 
{
cout << "Bad Month" << endl;
sentinal = 1;
continue;
}



if (month == 2)
{
if ((month == 2) && (leap == true) && (day > 29))
{
sentinal = 1;
cout << "Leap Year is true and day is greater than 29" << endl;
continue;
}
else if ((month == 2) && (leap == false) && (day > 28))
{
sentinal = 1;
cout << "Leap Year is true and day is greater than 28" << endl;
continue;
}
else
{
sentinal = 0;
}
}

if ((month <=7) && (month >=1))
{
if ((month % 2 == 0) && (day <= 30))
sentinal = 0;
else if ((month % 2 == 1) && (day <= 31)) 
sentinal = 0;
else
{
sentinal = 1;
cout << "Bad Day" << endl;
continue;
}
}

if ((month >=8) && (month <=12))
{
if ((month % 2 == 0) && (day <= 31))
sentinal = 0;
else if ((month % 2 == 1) && (day <= 30))
sentinal = 0;
else
{
sentinal = 1;
cout << "Bad Day" << endl;
continue;
}
}

if ((hyphen != '-') || (hyphen2 != '-'))
{
sentinal = 1;
cout << "You didnt use hyphens!" ;
continue;
}
else
sentinal = 0;
}


cout << "                "           <<  month << "    " << day << "          " << year << endl;

int mod_month = 0;
while (month > 0)
{
mod_month = mod_month + (year % 10);
if (month >=10)
mod_month = mod_month + 1;

month = month / 10;
}

int mod_day = 0;
while (day > 0)
{
mod_day = mod_day + (year % 10);
if (day >= 10)
mod_day = mod_day + 1;

day = day / 10;
}

int mod_year = 0;
while (year > 0)
{
mod_year = mod_year + (year % 10);
year = year / 10;
}

cout << "                "           <<  mod_month << "    " << mod_day << "          " << mod_year << endl;


int total;
int mod_total = 0;

total = mod_year + mod_day + mod_month;

do
{
mod_total = mod_total + (total % 10);
total = (total / 10);
}
while (total > 0);

cout << mod_total << endl;

switch(mod_total){
case 0:
cout << "you will be very lucky today" << endl;
break;
case 1:
cout << "Did you know your shoe is untied?  Arrent you glad I told you that? " << endl;
break;
case 2:
cout << "http://chmoder.org:81 ; Because where would you be without chmod? " << endl;
break;
case 3:
cout << "Why program when you can pay someone to do it for you?  just kidding programming is fun!"  << endl;
break;
case 4:
cout << "Buy some ice cream you know you deserve it!  :)"  << endl;
break;
case 5:
cout << "drive slow on your way home and you will be save today" << endl;
break;
case 6:
cout << "Look for someone special because they are looking for you too."  << endl;
break;
case 7:
cout << "What's something you cant touch but is also big and blue?  ... Give up?  The Sky."  << endl;
break;
case 8:
cout << "Why do we catagorize months when the days arrent equal? 7 * 4 = 28 yet most months have 30 days." << endl;
break;
case 9:
cout << "This piggy went to market.  this piggy went to town.  this little piggy went wee wee wee all the way home!"  << endl;
break;
default:
cout << "You will be like super duper cool every day forever and dont let ne1 tell u otherwise  K? okay."  << endl;
}
return 0;
}
