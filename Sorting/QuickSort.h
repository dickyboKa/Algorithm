#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>


/*
Analysis of quiksort: average is nlogn
*/
template <class ForwardIter>
ForwardIter partition(ForwardIter low, ForwardIter high)
{
	auto pivot = *high;
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

template <class ForwardIter>
void quickSort(ForwardIter low, ForwardIter high)
{
	--high; // high is cend() at the beginning;
	if (low < high)
	{
		auto pivot = partition(low, high);

		quickSort(low, pivot - 1);
		quickSort(pivot + 1, high);
	}
}