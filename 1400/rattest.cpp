#include <iostream>
using namespace std;

#include "Rational.h"





void printHeader (const Rational &r, const Rational &l, const char * op);

int main ()
{

	Rational  first(1,4);
	Rational second(1,3);

	/*************************************************************************
	 *************************************************************************/

	printHeader(first,second,"<");

	if ((first < second))
	{
		cout << "This is true.  This test was correct." << endl;
	}
	else
	{
		cout << "This test failed." << endl;
	}

	/*************************************************************************
	 *************************************************************************/

	printHeader(first,second,"<=");

	if (first <= second)
	{
		cout << "This is true.  This test was correct." << endl;
	}
	else
	{
		cout << "This test failed." << endl;
	}

	/*************************************************************************
	 *************************************************************************/

	printHeader(first,second,">");

	if (first > second)
	{
		cout << "This test failed." << endl;
	}
	else
	{
		cout << "This is false.  This test was correct." << endl;
	}

	/*************************************************************************
	 *************************************************************************/

	printHeader(first,second,">=");

	if (first >= second)
	{
		cout << "This test failed." << endl;
	}
	else
	{
		cout << "This is false.  This test was correct." << endl;
	}

	/*************************************************************************
	 *************************************************************************/

	printHeader(first,second,"==");

	if (first == second)
	{
		cout << "This test failed." << endl;
	}
	else
	{
		cout << "This is false.  This test was correct." << endl;
	}

	/*************************************************************************
	 *************************************************************************/

	printHeader(first,second,"!=");

	if (first != second)
	{
		cout << "This is true.  This test was correct." << endl;
	}
	else
	{
		cout << "This test failed." << endl;
	}

	/*************************************************************************
	 *************************************************************************/

	printHeader(first,second,"+");
	cout << "\tnote: result should be 7/12" << endl;
	cout << "\tYour result: " << first + second << endl << endl;

	/*************************************************************************
	 *************************************************************************/

	printHeader(first,second,"-");
	cout << "\tnote: result should be -1/12" << endl;
	cout << "\tYour result: " << first - second << endl << endl;

/*************************************************************************
	 *************************************************************************/

	printHeader(first,second,"*");
	cout << "\tnote: result should be 1/12" << endl;
	cout << "\tYour result: " << first * second << endl << endl;

	/*************************************************************************
	 *************************************************************************/

	printHeader(first,second,"/");
	cout << "\tnote: result should be 3/4" << endl;
	cout << "\tYour result: " << first / second << endl << endl;

	/*************************************************************************
	 *************************************************************************/

	Rational testReduce (65,165);

	cout << endl << "=============================================================================" << endl << endl;
	cout << "Now testing reduction of 65/165.  Should be 13/33." << endl;

	cout << endl << "\tYour result: " << testReduce << endl;
	cout << endl;

	/*************************************************************************
	 *************************************************************************/

	Rational testReduce2 (165,65);

	cout << endl << "=============================================================================" << endl << endl;
	cout << "Now testing reduction of 165/65.  Should be 33/13." << endl;

	cout << endl << "\tYour result: " << testReduce2 << endl;
	cout << endl;

	/*************************************************************************
	 *************************************************************************/

	Rational testReduce3 (17,17);

	cout << endl << "=============================================================================" << endl << endl;
	cout << "Now testing reduction of 17/17.  Should be 1/1." << endl;

	cout << endl << "\tYour result: " << testReduce3 << endl;
	cout << endl;

	/*************************************************************************
	 *************************************************************************/

	Rational tester4;

	cout << endl << "=============================================================================" << endl << endl;
	cout << "Now testing input.  Enter 8/6 when prompted." << endl;
	cout << endl << "Enter 8/6 now: " << flush;
	cin >> tester4;
	cout << endl << "\tYour Rational number is: " << tester4 << endl;
	cout << endl << "\tThe output should be 4/3 since it should reduce.";

	cout << endl << endl;
	cout << endl << "NOTE: If that scrolled by too quickly, you will want to scroll up to see if all of your functions work correctly.\n\n";
	return 0;
}


/****************************************************************************
 ****************************************************************************/

void printHeader (const Rational &r, const Rational &l, const char * op)
{
	cout << endl << "=============================================================================" << endl << endl;
	cout << "Now testing the " << op << " operator:" << endl << endl;
	cout << "\tTesting " << r << " " << op << " " << l << endl << endl;
}
