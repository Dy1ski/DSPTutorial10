
// COS30008, Tutorial 10, 2018

#include "SimpleString.h"

#if TEST >= 6

#include "HandleImpl.h"

#endif

#include <iostream>

using namespace std;

// Test harnesses

#if TEST == 0 || TEST == 1

void testCC()
{
	// ad that start string length is 0 therfore char works
	SimpleString s1;
	s1 + 'A';
	SimpleString s2 = s1;
	s2 + 'B';

	cout << "S1: " << *s1 << endl;
	cout << "S2: " << *s2 << endl;
}

#endif

#if TEST == 2 || TEST == 3

void testAO()
{
	SimpleString s1;
	s1 + 'A';
// constructor is called with a null in it
	// appent the + operator
	// adds the a to the string
	SimpleString s2 = s1;
	// calling the simplestring s2 means adding a length which is called
	// in simplestirng.cpp
// assign s 2 to s1 using the equal operator
	// this will not work without the = operator
	//  a shallow copy occurs as a result
	s2 + 'B';
	// make a break point below and see how the copy constructor works
	// string s2 knows to call the copy constructor becasue
	//when a variable is int then asssigned the compiler knows

	// ps1->clone() will make a copy 
	// need to be careful in term of shallow and deep copies
	s1 = s2;

	cout << "S1: " << *s1 << endl;
	cout << "S2: " << *s2 << endl;
	//s1.~SimpleString();
	//s2.~SimpleString();
	// deconstructor call

}

#endif

#if TEST == 4

void testPA()
{
	SimpleString* ps1 = new SimpleString();
	(*ps1) + 'A';
	SimpleString* ps2 = ps1;
	(*ps2) + 'B';

	cout << "S1: " << **ps1 << endl;
	cout << "S2: " << **ps2 << endl;
	// what was done in the lab 
	// this is a deep copy
	// use watch1 to monitor variables
	delete ps1;
	delete ps2;
}

#endif

#if TEST == 5

void testClone()
{
	SimpleString* ps1 = new SimpleString();
	(*ps1) + 'A';
	SimpleString* ps2 = ps1->clone();
	(*ps2) + 'B';

	cout << "S1: " << **ps1 << endl;
	cout << "S2: " << **ps2 << endl;

	delete ps1;
	delete ps2;
}

#endif

#if TEST == 6

void testHandle()
{
	Handle<SimpleString> hs1(new SimpleString());
	*hs1 + 'A';
	Handle<SimpleString> hs2(hs1->clone());
	*hs2 + 'B';
	Handle<SimpleString> hs3 = hs1;

	cout << "HS1: " << **hs1 << endl;
	cout << "HS2: " << **hs2 << endl;
	cout << "HS3: " << **hs3 << endl;
}

#endif

int main()
{
#if TEST == 0

	cout << "Testing default behavior..." << endl;
	testCC();

#endif

#if TEST == 1

	cout << "Testing deep-copy copy constructor..." << endl;
	testCC();

#endif

#if TEST == 2

	cout << "Testing default assignment operator..." << endl;
	testAO();

#endif

#if TEST == 3

	cout << "Testing deep-copy assignment operator..." << endl;
	testAO();

#endif

#if TEST == 4

	cout << "Testing pointer aliases..." << endl;
	testPA();

#endif

#if TEST == 5

	cout << "Testing clone..." << endl;
	testClone();

#endif

#if TEST == 6

	cout << "Testing handles..." << endl;
	testHandle();

#endif

	return 0;
}