#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Sorting/BubbleSort.h"


int main()
{
	
	std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
	bubbleSort(arr.begin(), arr.end());
	std::copy(arr.cbegin(), arr.cend(), std::ostream_iterator<int>(std::cout, ", "));
	return 0;
}


