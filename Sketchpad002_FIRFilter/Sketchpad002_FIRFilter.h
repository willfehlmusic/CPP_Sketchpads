#pragma once
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <memory>


std::vector<float> processFIRFilter(std::vector<float> &inputBuffer, std::vector<double> &coefficientsVector)
{
	/*this function takes our input
	and applies the coefficients via a discrete convolution.*/

	/*create an empty output vector, resize and initialize*/
	std::vector<float> outputBuffer;
	outputBuffer.resize(inputBuffer.size() + coefficientsVector.size() + 1);
	for (size_t i = 0; i < outputBuffer.size(); i++)
	{
		outputBuffer[i] = 0;
	}

	/*discrete convolution*/
	for (size_t i = 0; i < inputBuffer.size(); i++)
	{
		outputBuffer[i] = 0;
		for (size_t j = 0; j < coefficientsVector.size(); j++)
		{
			/*check index is in range*/
			int index = i - j;
			if (index >= 0)
			{
				outputBuffer[i] += inputBuffer[i - j] * coefficientsVector[j];
			}
		}
	}
	return outputBuffer;
}

void printSignals(std::vector<float> &inputBuffer, std::vector<float> &processedBuffer, std::vector<double> &coefficientsVector)
{
	/*this function simply prints out our signals*/
	std::cout << "INPUT SIGNAL : \t";
	for (size_t i = 0; i < inputBuffer.size(); i++)
	{
		std::cout << inputBuffer[i] << "  ";
	}
	std::cout << std::endl;

	std::cout << "FIR FILTER COEFFICIENTS : \t";
	for (size_t i = 0; i < coefficientsVector.size(); i++)
	{
		std::cout << coefficientsVector[i] << "  ";
	}
	std::cout << std::endl;

	std::cout << "PROCESSED SIGNAL : \t";
	for (size_t i = 0; i < processedBuffer.size(); i++)
	{
		std::cout << processedBuffer[i] << "  ";
	}
	std::cout << std::endl;
}