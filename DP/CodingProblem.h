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
