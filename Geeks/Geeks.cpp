#include <iostream>
#include <vector>
#include <iterator>
#include "Sorting/CodingProblems.h"


int main()
{
	std::vector<int> a = { 10, 20, 15, 12, 11, 50 };
	std::cout << "before sort: " << std::endl;
	std::copy(a.cbegin(), a.cend(), std::ostream_iterator<int>(std::cout, ", "));
	collectionsInReduceForm(a);
	return 0;
}


