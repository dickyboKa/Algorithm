#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Sorting/CountSort.h"


int main()
{
	
	std::vector<int> arr = { 1, 4, 1, 2, 7, 5, 2 };
	countSort(arr);
	std::copy(arr.cbegin(), arr.cend(), std::ostream_iterator<int>(std::cout, ", "));
	return 0;
}


