#include <iostream>
#include <vector>
#include "Greedy/CodingProblem.h"

int main()
{
	std::vector<int> s = { 1, 3, 0, 5, 8, 5 };
	std::vector<int> f = { 2, 4, 6, 7, 9, 9 };
	printMaxActivites(s, f);
	return 0;
}


