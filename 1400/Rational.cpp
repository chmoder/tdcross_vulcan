// FILL THIS OUT FILL THIS OUT FILL THIS OUT FILL THIS OUT FILL THIS OUT!
// FILL THIS OUT FILL THIS OUT FILL THIS OUT FILL THIS OUT FILL THIS OUT!
// FILL THIS OUT FILL THIS OUT FILL THIS OUT FILL THIS OUT FILL THIS OUT!
// FILL THIS OUT FILL THIS OUT FILL THIS OUT FILL THIS OUT FILL THIS OUT!

// Name         : Thomas Cross
// Class        : 1400-???
// Program #    : 21
// Due Date     : ??
//
// Honor Pledge:  On my honor as a student of the University
//                of Nebraska at Omaha, I have neither given nor
//                received unauthorized help on this homework assignment.
//
// Signed1:  (FULL_NAME)
// Signed2:  (NU ID)
// Signed3:  (COMPLETE, CORRECT E-MAIL)

// Discussion:   (NAME & EMAIL, "NONE" IF NONE)

// Put a brief program description here outlining what the
// program does before your actual program code begins.

#include <iostream>
using namespace std;
#include "Rational.h"



void Rational::setNumerator (int numer)
{
 	numeratorValue = numer;
}

void Rational::setDenominator (int denom) 
{
 	if (denom != 0)
 	{
 	   denominatorValue = denom;
 	}
 	else 
 	{
 	   cerr << "Illegal denominator; using 1 instead\n";
 	   denominatorValue = 1;
 	   // could have used exit (0); to just abort instead
 	}
 	return;
}

Rational::Rational (int numer, int denom) 
{
 	setNumerator(numer);
 	setDenominator(denom);
    reduce();
}

int Rational::getNumerator() const 
{
 	return numeratorValue;
}

int Rational::getDenominator() const 
{
 	return denominatorValue;
}

void Rational::insert (ostream &streamout) const
{
 	streamout << getNumerator() << "/" << getDenominator();
 	return;
}

void Rational::extract (istream &streamin) 
{
 	int numer;
 	int denom;
 	char slash;
 	streamin >> numer >> slash >> denom;
 	setNumerator(numer);
 	setDenominator(denom);
 	reduce();
    return;
    
}

Rational Rational::add (const Rational &right) const
{
 	int a = getNumerator();
 	int b = getDenominator();
 	int c = right.getNumerator();
 	int d = right.getDenominator();

 	Rational result(a*d + b*c, b*d);
 	return result;
}

Rational Rational::multiply (const Rational &right) const
{
 	int a = getNumerator();
 	int b = getDenominator();
 	int c = right.getNumerator();
 	int d = right.getDenominator();

 	Rational result (a*c, b*d);
 	return result;
}

Rational operator+ (const Rational &left, const Rational &right)
{
	return left.add(right);
}

Rational operator* (const Rational &left, const Rational &right)
{
	return left.multiply(right);
}

ostream& operator<< (ostream &output, const Rational &rat)
{
	rat.insert(output);
	return output;
}

istream& operator>> (istream &input, Rational &rat)
{
	rat.extract(input);
	return input;
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//// PUT YOUR OWN CODE BELOW.  DOCUMENT ALL FUNCTIONS YOU WRITE
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////



Rational Rational::subtract (const Rational &right) const
{
        int a = getNumerator();
        int b = getDenominator();
        int c = right.getNumerator();
        int d = right.getDenominator();
        Rational result(a*d - b*c, b*d);
        return result;
}

Rational operator- (const Rational &left, const Rational &right)
{
        return left.subtract(right);
}


Rational Rational::divide (const Rational &right) const
{
        int a = getNumerator();
        int b = getDenominator();
        int c = right.getNumerator();
        int d = right.getDenominator();
        Rational result (a*d, b*c);
        return result;
}

Rational operator/ (const Rational &left, const Rational &right)
{
        return left.divide(right);
}


bool Rational::lessThan (const Rational &right) const
{
int a = getNumerator();
int b = getDenominator();
int c = right.getNumerator();
int d = right.getDenominator();
//cout << "!!!!  "  << y << "!!!!! " << z << "!!!!!";
if ((a*d) < (b*c))
return true;
else
return false;
       
}


bool operator<  (const Rational &left, const Rational &right)
{
    if ( left.lessThan(right))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Rational::lessThanEqual (const Rational &right) const
{
    int a = getNumerator();
    int b = getDenominator();
    int c = right.getNumerator();
    int d = right.getDenominator();
    if ((a/b) <= (c/d))
        return true;
    else
        return false;
}


bool operator<=  (const Rational &left, const Rational &right)
{
    if ( left.lessThanEqual(right))
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Rational::greaterThan (const Rational &right) const
{
    int a = getNumerator();
    int b = getDenominator();
    int c = right.getNumerator();
    int d = right.getDenominator();
    if ((a/b) > (c/d))
        return true;
    else
        return false;
}


bool operator>  (const Rational &left, const Rational &right)
{
    if ( left.greaterThan(right))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Rational::greaterThanEqual (const Rational &right) const
{
    int a = getNumerator();
    int b = getDenominator();
    int c = right.getNumerator();
    int d = right.getDenominator();
    if ((a*d) >= (b*c))
        return true;
    else
        return false;
}


bool operator>=  (const Rational &left, const Rational &right)
{
if ( left.greaterThanEqual(right))
{
    return true;
}
else
{
    return false;
}
}

bool Rational::equalTo (const Rational &right) const
{
        int a = getNumerator();
        int b = getDenominator();
        int c = right.getNumerator();
        int d = right.getDenominator();
        if ((a*d) == (b*c))
            return true;
        else
            return false;
}


bool operator==  (const Rational &left, const Rational &right)
{
    if ( left.equalTo(right))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Rational::notEqualTo (const Rational &right) const
{
    int a = getNumerator();
    int b = getDenominator();               
    int c = right.getNumerator();
    int d = right.getDenominator();
    if ((a*d) != (b*c))
        return true;
    else
        return false;
}


bool operator!=  (const Rational &left, const Rational &right)
{
    if ( left.notEqualTo(right))
    {
        return true;
    }
    else
    {    
        return false;
    }
}

void Rational::reduce()
{

   int a = getNumerator();
   int b = getDenominator();
           
int x = 2;   
while (x<a)
{
    if ((a % x == 0) && (b % x == 0))
    {
        a = a / x;
        b = b / x;
        x = 2;
    }
    else
    x++;
    
}
setNumerator(a);
setDenominator(b);



}

