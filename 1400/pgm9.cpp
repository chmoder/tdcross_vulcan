//Name          :Thomas Cross
//Class         :1400009
//Program #     :pgm1
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

//Shipping program

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main ()
{
int dist = 0; //distance of package travel
int mass = 0; //mass of package 
int distcharge = 0;  //used to determine the amount to chagre based on distnce
float shipping_rate = 0;  //used to determine shipping rate
float charge = 0;  //final total charge of shipment

//input distance with param
while (dist < 1)
{
cout << "Please enter a distance >= 1 mile.\n";
cin >> dist;
}

//input mass of pckage with param
while ((mass > 60) || (mass < 1))
{
cout << "Please enter the mass of the package that is greater than 1 and less than 60lbs.\n";
cin >> mass;
}
cout << "Your distance was: " << dist << " Miles." << endl;
cout << "Your mass of the package was: " << mass << ".0 Pounds." << endl << endl;

//if statement to determine shipping rate
if ((mass >= 1) && (mass <= 5))
shipping_rate = 2.53;
else if ((mass >=6) && (mass <=9))
shipping_rate = 4.51;
else if ((mass >=10) && (mass <=20))
shipping_rate = 5.56;
else if ((mass >=21) && (mass <= 40))
shipping_rate= 6.27;
else if ((mass >= 41) && (mass <= 60))
shipping_rate = 7.08;
else
cout << "something bad must have happend cause u didnt enter a number you were supposed to XD!\n";

//while loop to determine ammount to charge by distance
while (dist > 0) 
{
dist = dist - 40;
distcharge = distcharge + 1;
}

//final math to determine and output shipping rate
charge = shipping_rate * distcharge;
cout << "Your Shipping Cost Will Be: $" << charge << endl;


return 0;
}
