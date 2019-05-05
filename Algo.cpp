#include <iostream>
#include <vector>
#include "Greedy/JobSequencing.h"

int main()
{
	std::vector<int> V{ -1, 3, 5, 4, 1, 2, 7, 6, 8, 9, 10 };
	double decay = 0.10;

	optimumSequenceJob(V, decay);
}

