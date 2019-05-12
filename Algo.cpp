#include <iostream>
#include <vector>
#include "Graph/GraphMatrix.h"
#include "Graph/CodingProblem.h"

int main()
{
	GraphMatrix gm(2, { {3, 3},
					   {1, 1} });

	gm.printMinimalSources();
}

