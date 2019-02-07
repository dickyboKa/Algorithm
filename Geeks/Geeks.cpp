#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Sorting/MergeSort.h"


int main()
{
	
	std::vector<int> arr = { 12, 11, 13, 5 };
	mergeSort(arr, 0, arr.size() - 1);
	std::copy(arr.cbegin(), arr.cend(), std::ostream_iterator<int>(std::cout, ", "));
	return 0;
}


