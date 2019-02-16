#include <vector>
#include <cmath>
#include "InsertionSort.h"
#include "MergeSort.h"
const int RUN = 32;

void timSort(std::vector<int> &arr)
{
	int N = arr.size();
	//first do insertion sort for small element up to RUN (32)
	for (auto it_left = arr.begin(); it_left != arr.end(); it_left += RUN)
	{
		int RANGE = arr.end() - it_left;
		auto it_right = it_left;
		RANGE <= RUN ? it_right += RANGE : it_right += RUN;
		insertionSort<std::vector<int>::iterator>(it_left, it_right);
		if (RANGE <= RUN)
			break;
	}

	int size;
	for (size = RUN; size < N; size = 2 * size)
	{
		for (int left = 0; left < N; left += 2 * size)
		{
			int right = std::min((left + 2 * size - 1), (N - 1));
			int mid = left + (right - left) / 2;

			merge(arr, left, mid, right);
		}
	}

	// merge last part that not unifromly distributed
	size /= 2;
	merge(arr, 0, size, N - 1);


}