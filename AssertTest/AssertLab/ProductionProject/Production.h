#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <string>

class Production
{
public:
	std::pair<bool,std::vector<int>> takeInput();
	bool has6Elements(std::vector<int> numbers);
	bool isInRange(std::vector<int> numbers);
	bool hasUniqueNums(std::vector<int> numbers);
};