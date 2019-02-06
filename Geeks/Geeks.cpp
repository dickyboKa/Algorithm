#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Sorting/InsertionSort.h"


int main()
{
	
	std::vector<int> arr = { 12, 11, 13, 5, 6 };
	insertionSort(arr);
	std::copy(arr.cbegin(), arr.cend(), std::ostream_iterator<int>(std::cout, ", "));
	return 0;
}


