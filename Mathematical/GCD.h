#pragma once
#include <vector>

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int gcd(std::vector<int> &numbers)
{
	int result = numbers[0];
	for (int i = 1; i < numbers.size(); ++i)
	{
		result = gcd(numbers[i], result);
	}
	return result;
}

