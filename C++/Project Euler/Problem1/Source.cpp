#include <iostream>
#include <vector>

struct Range
{
	int begin;
	int end;
};

bool isMultiple(int number, int baseNumber)
{
	return number % baseNumber == 0;
}

bool isMultiple(int number, const std::vector<int>& baseNumbers)
{
	for (int baseNumber : baseNumbers)
	{
		if (isMultiple(number, baseNumber))
		{
			return true;
		}
	}
	return false;
}

void getMultiples(const Range& range, const std::vector<int>& baseNumbers, std::vector<int>& multiples)
{
	for (int i = range.begin; i < range.end; i++)
	{
		if (isMultiple(i, baseNumbers))
		{
			multiples.push_back(i);
		}
	}
}

int sumMultiples(const Range& range, const std::vector<int>& baseNumbers)
{
	std::vector<int> multiples;
	getMultiples(range, baseNumbers, multiples);
	int sumOfMultiples = 0;
	for (int multiple : multiples)
	{
		sumOfMultiples += multiple;
	}
	return sumOfMultiples;
}

int main()
{
	Range range;
	range.begin = 1;
	range.end = 1000;
	std::vector<int> baseNumbers = {3, 5};

	std::wcout << L"The solution is: " << sumMultiples(range, baseNumbers) << std::endl;
	return 0;
}
