#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;

class Rational
{
	// Here, we prototype the overloaded operators.  All but the last four are new
	// and must be implemented.  The operator<->member function relationship should
	// be obvious (i.e., operator<= should be implemented to call the lessThanEqual
	// member function).

	friend Rational operator- (const Rational &left, const Rational &right);
	friend Rational operator/ (const Rational &left, const Rational &right);
	friend bool operator<  (const Rational &left, const Rational &right);
	friend bool operator<= (const Rational &left, const Rational &right);
	friend bool operator>  (const Rational &left, const Rational &right);
	friend bool operator>= (const Rational &left, const Rational &right);
	friend bool operator== (const Rational &left, const Rational &right);
	friend bool operator!= (const Rational &left, const Rational &right);
	
	friend Rational operator+ (const Rational &left, const Rational &right);
	friend Rational operator* (const Rational &left, const Rational &right);
	friend ostream& operator<< (ostream &streamout, const Rational &s);
	friend istream& operator>> (istream &streamin, Rational &r);

    public:

        Rational (int num = 0, int den = 1);
        Rational add (const Rational &r) const;
        Rational multiply (const Rational &r) const;
        void insert (ostream &output) const;
        void extract (istream &input);

        // These are new and must be implemented
        Rational subtract (const Rational &r) const;
        Rational divide (const Rational &r) const;
        bool lessThan (const Rational &r) const;
        bool lessThanEqual (const Rational &r) const;
        bool greaterThan (const Rational &r) const;
        bool greaterThanEqual (const Rational &r) const;
        bool equalTo (const Rational &r) const;
        bool notEqualTo (const Rational &r) const;

    private:

        int getNumerator() const;
        int getDenominator() const;
        void setNumerator (int numer);
        void setDenominator (int denom);

        // Reduce is new and must be implemented
        void reduce();

        int numeratorValue;
        int denominatorValue;
};

#endif
