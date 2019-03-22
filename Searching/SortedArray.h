#include <vector>
/*
answer to: https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/
this should be O(logn) but only for a value that cannot be appear more than twice in a sorted array
*/
int findElementThatAppearOnce(std::vector<int> &a, int beg, int end)
{
	if(beg > end)
		return -1; // no value is repeated;

	if (beg == end)
		return a[beg]; // element is found

	int mid = (beg + end) / 2;

	if (mid % 2 == 0)
	{
		if (a[mid] == a[mid + 1])
			findElementThatAppearOnce(a, mid + 2, end);
		else
			findElementThatAppearOnce(a, beg, mid);
	}
	else
	{
		if (a[mid] == a[mid - 1])
			findElementThatAppearOnce(a, mid + 1, end);
		else
			findElementThatAppearOnce(a, beg, mid -1);
	}
	
}

int findElementThatAppearOnce(std::vector<int> &a)
{
	return findElementThatAppearOnce(a, 0, a.size() - 1);
}