#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

void processChar(const char& c, bool& foundFirstDigit, int& firstDigit, int& lastDigit)
{
	if (!isdigit(c))
	{
		return;
	}

	std::string charString;
	charString = c;
	if (!foundFirstDigit)
	{
		foundFirstDigit = true;
		firstDigit = std::stoi(charString);
	}
	lastDigit = std::stoi(charString);
}

bool processLine(const std::string& line, int& number)
{
	bool foundFirstDigit = false;
	int firstDigit = 0;
	int lastDigit = 0;
	for (const char& c : line)
	{
		processChar(c, foundFirstDigit, firstDigit, lastDigit);
	}
	number = (firstDigit * 10 + lastDigit);
	return foundFirstDigit;
}

int main()
{
	std::string filename = "Input.txt";
	std::ifstream fileStream(filename);
	if (!fileStream.is_open())
	{
		std::cout << "FAIL: Could not open filename " << filename <<  std::endl;
		return 1;
	}

	int sum = 0;
	std::string line;
	while (fileStream)
	{
		std::getline(fileStream, line);
		int numberFound = 0;
		if (processLine(line, numberFound))
		{
			std::cout << "Found number: " << numberFound << std::endl;
			sum += numberFound;
		}
	}
	std::cout << "The solution is: " << sum << std::endl;
	return 0;
}
