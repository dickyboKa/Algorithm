#include <iostream>
#include <vector>
#include <iterator>
#include "Geomethric/Lines.h"


int main()
{
	std::vector<std::pair<int, int>> segments;
	segments.push_back(std::make_pair(3, 15));
	segments.push_back(std::make_pair(2, 5));
	segments.push_back(std::make_pair(4, 8));
	segments.push_back(std::make_pair(9, 12));
	std::cout << segmentUnionLength(segments) << std::endl;
	return 0;
}


