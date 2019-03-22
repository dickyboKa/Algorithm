#include <vector>
#include <algorithm>

/*
Answer to: https://www.geeksforgeeks.org/search-an-element-in-an-array-where-difference-between-adjacent-elements-is-1/
The fact that difference between all adjacent elements is 1, make this solution worked, by calculating diff, 
we know we getting closer to the elemet to be search
*/
int searchElement(std::vector<int> &a, int x)
{
	int i = 0;
	while (i < a.size())
	{
		if (a[i] == x)
			return i; //index
		i = i + abs(a[i] - x);
	}

	return -1; //no element is present
}

/*
Answer to: https://www.geeksforgeeks.org/find-the-element-before-which-all-the-elements-are-smaller-than-it-and-after-which-all-are-greater-than-it/
O(n) or O(3n) + 2n extra space;
The idea is you populate two array, let called it left and right,
left array would consist of the biggest value prior to arr[i],
and right array would consist of the smaller value succeding arr[i]
then you travese the arr, and if arr[i] is bigger then left[i] and smaller than right[i] you found it
*/

int partitionElement(std::vector<int> &arr)
{
	std::vector<int> left_max(arr.size(), std::numeric_limits<int>::min());
	std::vector<int> right_min(arr.size(), std::numeric_limits<int>::max());

	// look up table for the max value before arr[i]
	for (int i = 1; i < arr.size(); ++i)
		left_max[i] = std::max(left_max[i - 1], arr[i - 1]);

	// look up table for the min value after arr[i]
	for (int i = arr.size() - 2; i >= 0; --i)
		right_min[i] = std::min(right_min[i + 1], arr[i + 1]);

	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] > left_max[i] && arr[i] < right_min[i])
			return i;
	}

	return -1;
}

