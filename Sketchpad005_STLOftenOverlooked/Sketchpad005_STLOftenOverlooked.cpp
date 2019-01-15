// Sketchpad005_STLOftenOverlooked.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

void diplayVector(std::vector<int>& aVectorContainer)
{
	std::cout << "[ ";
	for (auto element : aVectorContainer)
	{
		std::cout << element << " ";
	}
	std::cout << "]\n";
}

int main()
{
	// let's use these containers :)
	std::vector<int> VectorContainer = { 1, 3, 10, -1, 13, 6, -3, 2, 3, 17, 9, 32, 2, 3, 3, 7, -1 };
	std::vector<int> anotherVectorContainer = { 12, 23, 10, -21, 13, 20 , 2, 23, 17, 29, 32, 22, 32, 32, 72, -21 };

	//std:: partial_sort
	/*std::cout << "\nstd::partial_sort...\n";
	std::cout << "Get 3 lowest elements...\n";
	std::cout << "Sort at beginning...\n";
	std::partial_sort(begin(VectorContainer), begin(VectorContainer) + 3, end(VectorContainer));
	std::cout << "VectorContainer = ";
	diplayVector(VectorContainer);
	// reset containers
	VectorContainer = { 1, 3, 10, -1, 13, 6, -3, 2, 3, 17, 9, 32, 2, 3, 3, 7, -1 };
	std::cout << "Sort at end...\n";
	std::partial_sort(rbegin(VectorContainer), rbegin(VectorContainer) + 3, rend(VectorContainer));
	std::cout << "VectorContainer = ";
	diplayVector(VectorContainer);*/
	
	// std::equal
	/*std::cout << "\nstd::equal...\n";
	std::cout << "are these strings palindromes?...\n";
	std::string AString = "yakay";
	std::string BString = "lowo";
	bool isPalindrome = std::equal(begin(AString), end(AString), rbegin(AString), rend(AString));
	std::cout << "is " << AString << " a palindrome ? " << isPalindrome << "\n";
	isPalindrome = std::equal(begin(BString), end(BString), rbegin(BString), rend(BString));
	std::cout << "is " << BString << " a palindrome ? " << isPalindrome << "\n";*/

	// std::transform
	/*std::cout << "\nstd::transform...\n";
	std::cout << "apply an operation to a set of values...\n";
	std::transform(
		begin(VectorContainer),
		end(VectorContainer),
		begin(VectorContainer),
		[](int element)
	{
		if (element % 2 == 0)
		{
			return element * 2;
		}
		else
		{
			return element + 1;
		}
	}
	);
	std::cout << "VectorContainer = ";
	diplayVector(VectorContainer);
	std::cout << "anotherVectorContainer = ";
	diplayVector(anotherVectorContainer);*/

	// std::swap
	/*std::cout << "\nstd::swap...\n";
	std::cout << "swap ownership of containers...\n";
	std::swap(VectorContainer, anotherVectorContainer);
	std::cout << "VectorContainer = ";
	diplayVector(VectorContainer);
	std::cout << "anotherVectorContainer = ";
	diplayVector(anotherVectorContainer);*/

	// std::swap_range
	/*std::cout << "\nstd::swap_ranges...\n";
	std::cout << "swap sets of values...\n";
	std::swap_ranges(begin(VectorContainer), end(VectorContainer) - 4, begin(anotherVectorContainer));
	std::cout << "VectorContainer = ";
	diplayVector(VectorContainer);
	std::cout << "anotherVectorContainer = ";
	diplayVector(anotherVectorContainer);*/

	// std::rotate
	/*std::cout << "\nstd::rotate...\n";
	std::cout << "rotate sets of values...\n";
	VectorContainer[0] = 5555;
	VectorContainer[5] = 9999;
	std::cout << "BEFORE ROTATION...\n";
	std::cout << "VectorContainer = ";
	diplayVector(VectorContainer);
	auto aVal = std::find(begin(VectorContainer), end(VectorContainer), 5555);
	auto bVal = std::find(begin(VectorContainer), end(VectorContainer), 9999);
	std::rotate(aVal, bVal, bVal+4);
	std::cout << "AFTER ROTATION...\n";
	std::cout << "VectorContainer = ";
	diplayVector(VectorContainer);*/

	// std::stable_partition
	/*std::cout << "\nstd::stable_partition...\n";
	std::cout << "separate evens from odds and keep the order...\n";
	std::stable_partition(VectorContainer.begin(), VectorContainer.end(), [](int n) {return n%2 == 0; });
	std::cout << "VectorContainer = ";
	diplayVector(VectorContainer);*/

   /// std::cout << "Hello World!\n"; 
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
