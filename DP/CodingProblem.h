#pragma once

// number arrangement of sum N from 1, 3, 5 (allowing repetitions)
int numberArrangmentOf(int n)
{
	// base case 
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;

	return numberArrangmentOf(n - 1) + numberArrangmentOf(n - 3) + numberArrangmentOf(n - 5);
}
