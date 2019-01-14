// Sketchpad004_BasicCustomArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <assert.h>
#include <ostream>

/*Lets assume we do not want to use std::vector.
But what if we needed to emulate those characteristics?*/

class IndexOutOfBoundsException
{
};

class SafeArray
{
private:
	// implementation details....................................................
	int * elementPtr = nullptr;	// pointer to block
	int arraySize = 0;			// size of array
	bool isValid(int inIndex) const;
	friend void Swap(SafeArray& a, SafeArray& b) noexcept; // a friend function can access private members
public:
	// interface details.........................................................
	SafeArray() = default;		// creates and empty array with nullptr
	explicit SafeArray(int inArraySize);	// takes size, we do not want implicit conversion so we use explicit
	SafeArray(SafeArray& source);	// copy constructor
	SafeArray& operator=(SafeArray source);	// copy assignment operator
	SafeArray(SafeArray&& source);	// move constructor with r value reference
	~SafeArray();		// destructor

	// marked const because they do not change anything...
	// return array size...
	int getSize() const { return arraySize; }
	// is the array empty?
	bool isEmpty() const { return (arraySize == 0); }
	// use overload for accessing data of array
	int& operator[](int inIndex);
	// read only access
	int operator[](int inIndex) const;
};

bool SafeArray::isValid(int inIndex) const
{
	// check that value is within array bounds
	return ((inIndex >= 0) && (inIndex < arraySize));
}

SafeArray::SafeArray(int inArraySize)
{
	if (inArraySize != 0)
	{
		// set size
		arraySize = inArraySize;
		// allocate block of memory from the heap to store the array elements
		elementPtr = new int[inArraySize] {}; // safe initialization to 0
	}
}

SafeArray::SafeArray(SafeArray & source)
{
	if (!source.isEmpty())
	{
		// copy size
		arraySize = source.arraySize;
		// allocate memory to store array elements
		elementPtr = new int[source.arraySize]{}; // safe initialization to 0
		// copy elements
		for (size_t i = 0; i < arraySize; i++)
		{
			elementPtr[i] = source.elementPtr[i];
		}
	}
}

SafeArray & SafeArray::operator=(SafeArray source)
{
	// do not copy itself because it is copied/passed by value
	Swap(*this, source);
	return *this;
}

SafeArray::SafeArray(SafeArray && source)
{
	// source is a temporary object that we can safely take the data from
	// transfer ownership
	elementPtr = source.elementPtr;
	arraySize = source.arraySize;
	// clear source
	source.elementPtr = nullptr;
	source.arraySize = 0;
}

SafeArray::~SafeArray()
{
	// we need to properly release memory as we have used keyword 'new'...
	delete[] elementPtr;
}

int& SafeArray::operator[](int inIndex)
{
	if (!isValid(inIndex))
	{
		// throw an exception
		throw IndexOutOfBoundsException{};
	}
	// return value of corresponding value by reference for write access
	return elementPtr[inIndex];
}

int SafeArray::operator[](int inIndex) const
{
	if (!isValid(inIndex))
	{
		// throw an exception
		throw IndexOutOfBoundsException{};
	}
	return elementPtr[inIndex];
}

// overload << to print array
std::ostream & operator<<(std::ostream & os, const SafeArray & a)
{
	os << "[ ";
	for (size_t i = 0; i < a.getSize(); i++)
	{
		os << a[i] << ' ';
	}
	os << "]";
	return os;
}



/*--------------------------------------------------------------------------------*/

int main()
{
	try
	{
		std::cout << "Create Array...\n";
		SafeArray aSA{};
		std::cout << "aSA.getSize() " << aSA.getSize() << "\n";
		std::cout << "aSA.isEmpty() " << aSA.isEmpty() << "\n";
		//assert(aSA.isEmpty()); // check condition at run time

		SafeArray bSA{ 10 };
		std::cout << "bSA.getSize() " << bSA.getSize() << "\n";
		std::cout << "bSA.isEmpty() " << bSA.isEmpty() << "\n";
		bSA[2] = 10;
		std::cout << "bSA[2] =  " << bSA[2] << "\n";
		std::cout << "Array Elements =  " << bSA << "\n";
		//assert(bSA.isEmpty()); // check condition at run time
	}
	catch (const IndexOutOfBoundsException& e)
	{
		std::cout << "ERROR: Invalid Array Index! \n";
	}
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

void Swap(SafeArray & a, SafeArray & b) noexcept
{
	std::swap(a.elementPtr, b.elementPtr);
	std::swap(a.arraySize, b.arraySize);
}
