#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Sorting/HeapSort.h"


int main()
{
	
	std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
	auto r = heapSort(arr);
	std::copy(r.cbegin(), r.cend(), std::ostream_iterator<int>(std::cout, ", "));
	return 0;
}


