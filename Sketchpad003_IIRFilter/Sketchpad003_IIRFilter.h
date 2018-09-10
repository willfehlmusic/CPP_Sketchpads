#pragma once

#include <iostream>
#include <vector>
#include <numeric>


std::vector<float> processIIRFilter(std::vector<float> &inputBuffer, float &gain)
{
	/*this function takes our input and applies the coefficients via a difference equation.*/

	/*make an output buffer using a vector*/
	std::vector<float> outputBuffer = inputBuffer;
	/*initialize state*/
	float outputPrev = 0;
	/*enforce stability conditions*/
	if (gain >= 1)
	{
		gain = 0.999;
	}
	else if (gain <= -1) {
		gain = -0.999;
	}

	/*loop through samples.
	this implementation would be more efficient if it used iterators.
	but, i think the math is clearer this way.*/
	for (size_t n = 0; n < inputBuffer.size(); n++)
	{
		/*function y[n] = x[n] + (g*y[n-1])*/
		outputBuffer[n] = inputBuffer[n] + (gain*outputPrev);
		/*reset y[n-1]*/
		outputPrev = outputBuffer[n];
	}
	return outputBuffer;
}


void printSignals(std::vector<float> &inputBuffer, std::vector<float> &processedBuffer)
{
	/*this function simply prints out our signals*/

	puts("INPUT SIGNAL : \n");
	/*using iterators, loop through the vector and print out the
	value that the iterator points to*/
	for (auto i = inputBuffer.begin(); i != inputBuffer.end(); i++)
	{
		std::cout<<"\t"<< *i;
	}
	std::cout<<"\n";

	puts("PROCESSED SIGNAL : \n");
	/*using iterators, loop through the vector and print out the
	value that the iterator points to*/
	for (auto i = processedBuffer.begin(); i != processedBuffer.end(); i++)
	{
		std::cout <<"\t" << *i;
	}
	std::cout << "\n";
}
