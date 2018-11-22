#include "Production.h"


/// <summary>
/// Verify has 6 elements
/// </summary>
/// <param name="numbers"></param>
bool Production::has6Elements(std::vector<int> numbers)
{
		bool result = true;
		int counter = 0;
		for (auto& number : numbers)
		{
			counter++;
		}
		if (counter != 6)
		{
			result = false;

		}
		return result;
}

/// <summary>
/// checks if number is between 1 and 46
/// </summary>
/// <param name="numbers"></param>
bool Production::isInRange(std::vector<int> numbers)
{
		bool result = true;
		for (auto& number : numbers)
		{
			if (number < 0 || number > 47)
			{
				result = false;
			}
		}
		return result;
}

/// <summary>
/// Check if the number is repeated
/// </summary>
/// <param name="numbers"></param>
bool Production::hasUniqueNums(std::vector<int> numbers)
{
		bool result = true;
		for (int i = 0; i < numbers.size(); i++)
		{
			for (int j = i + 1; j < numbers.size(); j++)
			{
				if (numbers[i] == numbers[j])
				{
					result = false;
				}
			}
		}
		return result;
}

std::pair<bool, std::vector<int>> Production::takeInput()
{
		std::vector<int> numbers;
		bool result = true;
		int counter = 0;
		while (counter != 6)
		{
			int num;
			if (!(std::cin >> num))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				result = false;
				break;
			}
			else
			{
				numbers.push_back(num);
			}
			counter++;
		}
		return std::make_pair(result,numbers);

}
