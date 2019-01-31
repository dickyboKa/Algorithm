#include "BinarySearch.h"
#include <algorithm>

/*
Answer to: https://www.geeksforgeeks.org/queries-greater-not-less/
*/
int CeillingWithQuerries(std::vector<int> &arr, int q, int x)
{
	int idx = Ceilling(arr, x);
	if (idx < arr.size() && idx != -1)
	{
		/*
		There are two condition:
		0: we looking for greater than equal,
		1: we looking for greater only
		*/
		if (q == 0)
			return (arr[idx - 1] == x) ? arr.size() - (idx - 1) : arr.size() - idx;
		else
			return arr.size() - idx;
	}
	else
		return 0;

}

std::vector<int> getQuerries(std::vector<int> &arr, std::vector<std::pair<int, int>> &Q)
{
	std::vector<int> output;
	std::sort(arr.begin(), arr.end()); // no guarante that the input is sorted
	for (auto it = Q.cbegin(); it != Q.cend(); ++it)
	{
		output.push_back(CeillingWithQuerries(arr, it->first, it->second));
	}
	return output;
}
