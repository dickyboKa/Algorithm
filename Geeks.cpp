#include <iostream>
#include <vector>
#include "Bit/CodingProblem.h"


int main()
{
	int x = 100;
	int y = -100;

	if (oppositeSign(x, y))
		std::cout << "Sign are opposite";
	else
		std::cout << "Sign are not opposite";
	return 0;
}


