#pragma once
#include <iostream>
#include <vector>
#include<limits>

class Production
{
public:
	std::vector<int> takeInput();
	void has6Elements(std::vector<int> numbers);
	void onlyNumbers(std::vector<int> numbers);
	void isInRange(std::vector<int> numbers);
	void isRepeated(std::vector<int> numbers);
};