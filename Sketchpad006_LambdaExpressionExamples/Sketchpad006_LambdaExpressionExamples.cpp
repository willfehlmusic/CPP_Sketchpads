// LambdaExpressions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::cout << "Let's mess with lambda expressions!\n\n";
	// ----------------------------------------
	/*this is a basic lambda expression...*/
	[]() {
		std::cout << "this is a basic lambda expression...\n";
	}();

	/*this is the same basic lambda expression...*/
	[/*it captures nothing...*/](/*it takes no arguments...*/) {
		/*this is the lambda expression function body...*/
		std::cout << "this is a basic lambda expression...\n";
	}(/*I want to invoke the lambda expression...*/);
	std::cout << "\n";
	// ----------------------------------------
	/*another lambda expression...*/
	[](int inputValue) {
		std::cout << "my inputValue = " << inputValue << "\n";
	}(100);
	std::cout << "\n";
	// ----------------------------------------
	/*another lambda expression...*/
	auto myLambdaExpression = [](int inputValue) {
		std::cout << "my inputValue = " << inputValue << "\n";
		return inputValue / 2.12F;
	};
	/*assume some other code happened here...*/
	std::cout << "my outputValue = " << myLambdaExpression(100) << "\n";
	std::cout << "my outputValue = " << myLambdaExpression(12) << "\n";
	std::cout << "\n";
	// ----------------------------------------
	/*assume we have some internal variables to our main...*/
	std::string nameLongTown = "Llanfairpwllgwyngyllgogerychwyrndrobwllllantysiliogogogoch";
	int indexString = 0;
	/*another lambda expression...*/
	auto myLambdaExpressionByReference = [&nameLongTown, &indexString](int inputValue) {
		std::cout << "the current town is " << nameLongTown << " !\n";
		std::cout << "the " << indexString << " letter is " << nameLongTown.at(indexString) << " !\n";
		indexString += 2;
		std::cout << "the " << indexString << " letter is " << nameLongTown.at(indexString) << " !\n";
		std::cout << "remove letter " << inputValue << " !\n";
		nameLongTown[inputValue] = '_';
		std::cout << "the current town is now " << nameLongTown << " !\n\n";
	};
	myLambdaExpressionByReference(2);
	myLambdaExpressionByReference(15);
	// ----------------------------------------
	int a = 0;
	int b = 110.03;
	/*another lambda expression...*/
	auto myLambdaExpressionAll = [=](auto inputValue) {
		std::cout << a << " + " << b << " + " << inputValue << " = " << a+b+inputValue << "\n";
	};
	/*another lambda expression...*/
	auto myLambdaExpressionAllAgain = [=](auto inputValue) {
		std::cout << a << " + " << inputValue << " = " << a + inputValue << "\n";
	};
	myLambdaExpressionAll(33.33);
	myLambdaExpressionAllAgain(0.1);
	// ----------------------------------------
	auto MyVector = std::vector<int>{ 1,13,4,5,3,6,3,1,3,9,4 };
	/*another lambda expression*/
	auto isGreaterThan4 = [](int valueCandidate) {
		return valueCandidate > 4;
	};
	/*another lambda expression*/
	auto is4 = [](int valueCandidate) {
		return valueCandidate == 4;
	};

	auto above4Count = std::count_if(MyVector.begin(), MyVector.end(), isGreaterThan4);
	auto is4Count = std::count_if(MyVector.begin(), MyVector.end(), is4);
	std::cout << "above4Count " << above4Count << "\n";
	std::cout << "is4Count " << is4Count << "\n";
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
