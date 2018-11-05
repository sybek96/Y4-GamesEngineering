#include "Test.h"

/// <summary>
/// Verify has 6 elements
/// </summary>
/// <param name="numbers"></param>
void Test::has6Elements(std::vector<int> numbers)
{
	int counter = 0;
	for (auto& number : numbers)
	{
		counter++;
	}
	assert(counter == 6);
}

/// <summary>
/// Verify all elements are integers
/// </summary>
/// <param name="numbers"></param>
void Test::onlyNumbers(std::vector<int> numbers)
{
	for (auto& number : numbers)
	{
		assert(number == floor(number));
	}
}

/// <summary>
/// checks if number is between 1 and 46
/// </summary>
/// <param name="numbers"></param>
void Test::isInRange(std::vector<int> numbers)
{
	for (auto& number : numbers)
	{
		assert(number > 0 && number < 47);
	}
}

/// <summary>
/// Check if the number is repeated
/// </summary>
/// <param name="numbers"></param>
void Test::isRepeated(std::vector<int> numbers)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = i+1; j < numbers.size(); j++)
		{
			assert(numbers[i] != numbers[j]);
		}
	}
}
