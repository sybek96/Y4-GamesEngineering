#include "Test.h"
#include <iostream>
#include <vector>
#include<limits>


/// <summary>
/// Verify has 6 elements
/// </summary>
/// <param name="numbers"></param>
void has6Elements(std::vector<int> numbers)
{
	int counter = 0;
	for (auto& number : numbers)
	{
		counter++;
	}
	if (counter != 6)
	{
		std::cout << "Number of parameters is not 6!" << std::endl;
		std::cout << "-- Amount of numbers " << counter << std::endl;
	}
}

/// <summary>
/// Verify all elements are integers
/// </summary>
/// <param name="numbers"></param>
void onlyNumbers(std::vector<int> numbers)
{
	for (auto& number : numbers)
	{
		if (number != floor(number))
		{
			std::cout << "Input element is not a number, please use only numbers" << std::endl;
			std::cout << "-- Input element causing error is " << number << std::endl;
		}
	}
}

/// <summary>
/// checks if number is between 1 and 46
/// </summary>
/// <param name="numbers"></param>
void isInRange(std::vector<int> numbers)
{
	for (auto& number : numbers)
	{
		if (number < 0 || number > 47)
		{
			std::cout << "Number not within valid range, please use numbers from 1 to 47" << std::endl;
			std::cout << "-- number out of range is " << number << std::endl;
		}
	}
}

/// <summary>
/// Check if the number is repeated
/// </summary>
/// <param name="numbers"></param>
void isRepeated(std::vector<int> numbers)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			if (numbers[i] == numbers[j])
			{
				std::cout << "You have repeated the same number! Numbers may not repeat." << std::endl;
				std::cout << "-- number repeated "  << numbers[j] << std::endl;
			}
		}
	}
}

int main()
{
	std::vector<int> numbers;
	int counter = 0;
	while (counter != 6)
	{
		int num;
		if (!(std::cin >> num))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, please use only numbers" << std::endl;
			break;
		}
		else
		{
			numbers.push_back(num);
		}
		counter++;
	}
	for (auto& number : numbers)
	{
		std::cout << number << std::endl;
	}

	/////////////////////////////////////
	/////   USING IF STATEMENTS
	/////////////////////////////////////
	has6Elements(numbers);
	isInRange(numbers);
	isRepeated(numbers);
	onlyNumbers(numbers);


	/////////////////////////////////////
	/////   USING TEST FRAMEWORK
	/////////////////////////////////////  
	Test testFramework = Test();
	testFramework.has6Elements(numbers);
	testFramework.isInRange(numbers);
	testFramework.isRepeated(numbers);
	testFramework.onlyNumbers(numbers);
	system("PAUSE");
	return 0;
}