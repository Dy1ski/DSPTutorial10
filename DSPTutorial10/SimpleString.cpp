
// COS30008, Tutorial 10, 2018

#include "SimpleString.h"

#include <cstring>

using namespace std;

SimpleString::SimpleString()
{
	// sets the length of the string which is called in main
	// assigns it null 
	fCharacters = new char[1];
	// the [] can be what ever you want
	*fCharacters = '\0';
}

SimpleString::~SimpleString()
{
	delete fCharacters;
}

// overloads the operator
// takes in any a character

SimpleString& SimpleString::operator+(const char aCharacter)
{
	char *Temp = new char[strlen(fCharacters) + 2];
	// creates a new character pointer array
	// with a new length of two
	//length was zero then it is changed to 2
	unsigned int i = 0;

	for (; i < strlen(fCharacters); i++)
		Temp[i] = fCharacters[i];

	Temp[i++] = aCharacter; // assigns the character to a index
	Temp[i] = '\0';

	delete fCharacters; // fCharacters is deleted
	fCharacters = Temp; // fcharacters is now equal to temp address
	return *this;
}

const char* SimpleString::operator*() const
{
	return fCharacters;
}

#if TEST >= 1
// The overload operator 
// This is the copy constructor
SimpleString::SimpleString(const SimpleString& aOtherString)
{
	unsigned long lLength = strlen(aOtherString.fCharacters) + 1;
	fCharacters = new char[lLength];

	for (unsigned int i = 0; i < lLength; i++)
		fCharacters[i] = aOtherString.fCharacters[i];
}

#endif

#if TEST >= 3

SimpleString& SimpleString::operator=(const SimpleString& aOtherString)
{
	if (&aOtherString != this)
		// checks if the string is equal to that current instance
		// if it is not then it will continue with its job

	{
		delete fCharacters;

		unsigned long lLength = strlen(aOtherString.fCharacters) + 1;
		fCharacters = new char[lLength];

		for (unsigned int i = 0; i < lLength; i++)
			fCharacters[i] = aOtherString.fCharacters[i];
	}

	return *this;
}

#endif

#if TEST >= 5

SimpleString* SimpleString::clone()
{
	return new SimpleString(*this);
	// copies a pointer to a point
}

#endif