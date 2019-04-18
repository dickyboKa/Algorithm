#pragma once
#include <vector>

//(Top Down)
std::vector<int> lookup(100, 0);
int fibMemoization(int n)
{
	if (lookup[n] == 0)
	{
		if (n <= 1)
			lookup[n] = n;
		else
			lookup[n] = fibMemoization(n - 1) + fibMemoization(n - 2);
	}
	return lookup[n];
}


//(Bottom Up)
int fibTabulation(int n)
{
	std::vector<int> result(n + 1);
	result[0] = 0; result[1] = 1;
	
	// build result bottom up
	for (int i = 2; i <= n; ++i)
	{
		result[i] = result[i - 1] + result[i - 2];
	}
	return result[n];
}