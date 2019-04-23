#pragma once
#include <vector>
#include "GCD.h"

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int lcm(std::vector<int> &numbers)
{
	int result = numbers[0];

	for (int i = 1; i < numbers.size(); ++i)
	{
		int currentGCD = gcd(numbers[i], result);
		result = (numbers[i] * result) / currentGCD;
	}

	return result;
}