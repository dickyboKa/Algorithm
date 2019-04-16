#include <iostream>
#include <vector>
#include <iterator>
#include "Geomethric/Lines.h"


int main()
{
	Lines line_1 = { {1, 1}, {10, 1} };
	Lines line_2 = { {1, 2}, {10, 2} };
	doIntersect(line_1, line_2) ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;

	line_1 = { {10, 0}, {0, 10} };
	line_2 = { {0, 0}, {10, 10} };
	doIntersect(line_1, line_2) ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;

	line_1 = { {-5, -5}, {0, 0} };
	line_2 = { {1, 1}, {10, 10} };

	doIntersect(line_1, line_2) ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;
	return 0;
}


