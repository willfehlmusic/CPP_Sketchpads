// Sketchpad002_FIRFilter.cpp : Defines the entry point for the console application.
/* 
	This project is intended as a sketchpad for understanding FIR filters and FIR filter impulse responses.
	The corresponding .h file contains all function definitions used in this .cpp file.
	Feel free to use this to draft out network architectures.
	Please note this function does not take into account real-time applications.
	This is simply a basic learning tool for DSP.
	This code is incredibly ineffficient and has many variables kept on the stack.
	This is so that you can look at the variables and check them at every step for learning purposes.
	*/


#include "stdafx.h"
#include "Sketchpad002_FIRFilter.h"


int main()
{
	/*define a vector as our input signal buffer.
	for this example it will be 20 samples long*/ 
	std::vector<float> kroneckerDeltaVector = { 1,	0,	0,	0,	0,
												0,	0,	0,	0,	0,
												0,	0,	0,	0,	0,
												0,	0,	0,	0,	0 };
	std::vector<float> otherSignalVector	= { 1.0, -0.5, 0.25, -0.125, 0.0625,
												0,  0,	0,	0,	0,
												0,	0,	0,	0,	0,
												0,	0,	0,	0,	0 };
	/*use this to choose your input signal from the two above.
	auto simply matches to the type which in this case is a std::vector<float>*/
	auto inputSignal = kroneckerDeltaVector;

	/*use a vector to define coefficients.
	this vector is 6 coefficients in length.*/
	std::vector<double> coefficientsVector = { 0.5, -0.25, 0.71, 0.00, -0.32, 0.17 };

	/*create an empty buffer of type float.*/
	std::vector<float> processedBuffer;
	/*process the input signal with the FIR Filter*/
	processedBuffer = processFIRFilter(inputSignal, coefficientsVector);
	/*print out the input signal, the FIR coefficients and the processed signal*/
	printSignals(inputSignal, processedBuffer, coefficientsVector);

	std::cout << "Press anykey to exit...";
	std::cin.ignore();
	std::cin.get();

    return 0;
}

