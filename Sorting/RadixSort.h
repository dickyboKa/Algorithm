#pragma once
#include <vector>
#include "CountSort.h"

int getMax(std::vector<int> &arr)
{
	int min = std::numeric_limits<int>::min();
	for (auto it = arr.cbegin(); it != arr.cend(); ++it)
		if (min < *it)
			min = *it;

	return min;
}

void radixSort(std::vector<int> &arr)
{
	int m = getMax(arr);

	//count short from least significant digits, to the moest significant digits
	for (int i = 1; m / i > 0; i *= 10)
		countSort(arr, i);
}
