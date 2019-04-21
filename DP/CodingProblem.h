#pragma once
#include <vector>

std::vector<int> memoizationLookup(100, -1);
// number arrangement of sum N from 1, 3, 5 (allowing repetitions)
int numberArrangmentOf(int n)
{
	// base case 
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;

	if (memoizationLookup[n] != -1)
		return memoizationLookup[n];

	return memoizationLookup[n] = numberArrangmentOf(n - 1) + numberArrangmentOf(n - 3) + numberArrangmentOf(n - 5);
}

int numberArragmentOfWithTabulation(int n)
{
	std::vector<int> result(n + 1);
	result[0] = 1;

	// build result bottom up
	for (int i = 1; i <= n; ++i)
	{
		result[i] = result[i - 1];
		if (i - 3 > -1)
			result[i] += result[i - 3];
		if (i - 5 > -1)
			result[i] += result[i - 5];
	}
	return result[n];
}
