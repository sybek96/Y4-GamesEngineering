#include "Test.h"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> numbers;
	while (numbers.size() != 6)
	{
		int num;
		std::cin >> num;
		numbers.push_back(num);
	}
	for (auto& number : numbers)
	{
		std::cout << number << std::endl;
	}

	Test testFramework = Test();
	testFramework.has6Elements(numbers);
	testFramework.isInRange(numbers);
	testFramework.isRepeated(numbers);
	testFramework.onlyNumbers(numbers);
	system("PAUSE");
	return 0;
}