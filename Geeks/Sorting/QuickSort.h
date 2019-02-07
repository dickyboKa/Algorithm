#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>


/*
Analysis of quiksort: average is nlogn
*/
std::vector<int>::iterator partition(std::vector<int>::iterator low, std::vector<int>::iterator high)
{
	int pivot = *high;
	auto i = low;
	for (auto j = low; j <= high - 1; ++j)
	{
		if (*j <= pivot)
		{
			std::iter_swap(i, j);
			++i;
		}
	}

	std::iter_swap(i, high);
	return i + 1;
}

void quickSort(std::vector<int>::iterator low, std::vector<int>::iterator high)
{
	--high; // high is cend() at the beginning;
	if (low < high)
	{
		auto pivot = partition(low, high);

		quickSort(low, pivot - 1);
		quickSort(pivot + 1, high);
	}
}