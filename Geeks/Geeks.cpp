#include <iostream>
#include <vector>
#include "Searching/RationalArray.h"

using namespace std;


int main()
{
	vector<std::pair<int, int>> a = { 
		make_pair(1,5),
		make_pair(2,3),
		make_pair(3,2),
		make_pair(13,2),
	};

	std::cout << searchRatNumber(a, make_pair(3,2)) << endl;
	return 0;
}


