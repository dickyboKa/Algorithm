#include <vector>
#include <algorithm>

/* this O(nlogn) 
answer to: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
*/
int findTheSmallestElementRankAt(std::vector<int> v, int kth)
{
	std::sort(v.begin(), v.end());
	return v[kth - 1];
}