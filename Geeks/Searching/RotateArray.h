#include <vector>

/*
Solutiont to Geek Exercises: https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
This is binary search to found a valey, of a mountaig range of integer
*/
int findMinimumElementInRotatedArray(std::vector<int> a, int beg, int mid, int end)
{
	if (mid == 0)
		return a[0]; //array is not rotate at all
	if (beg == mid)
		return a[a.size() - 1]; // array is descending
	if (a[mid] < a[mid - 1] && a[mid] < a[mid + 1]) // if this is valey than this is it
		return a[mid];
	else
	{
		if (a[mid + 1] > a[mid - 1]) //valey on the left
			return findMinimumElementInRotatedArray(a, beg, beg + ((mid - beg) / 2), mid);
		else // valey on the right
			return findMinimumElementInRotatedArray(a, mid, mid + ((end - mid) / 2), end);
	}
}