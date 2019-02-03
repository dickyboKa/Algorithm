#include <vector>
#include <algorithm>
#include <iostream>
/*
Solutiont to Geek Exercises: https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
This is binary search to found a valey, of a mountaig\n range of integer
*/
int findMinimumElementInRotatedArray(std::vector<int> &a, int beg, int mid, int end)
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

int findMinimumElementInRotatedArray(std::vector<int> &a)
{
	return findMinimumElementInRotatedArray(a, 0, a.size() / 2, a.size());
}


/*
Solutiont to Geek Exercises: https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
*/
int findIndexMinRotatedArray(std::vector<int> &a, int beg, int mid, int end)
{
	if (mid == 0)
		return 0; //array is not rotate at all
	if (beg == mid)
		return a.size() - 1; // array is descending
	if (a[mid] < a[mid - 1] && a[mid] < a[mid + 1]) // if this is valey than this is it
		return mid;
	else
	{
		if (a[mid + 1] > a[mid - 1]) //valey on the left
			return findIndexMinRotatedArray(a, beg, beg + ((mid - beg) / 2), mid);
		else // valey on the right
			return findIndexMinRotatedArray(a, mid, mid + ((end - mid) / 2), end);
	}
}

// for this case element is always ascending
// this should be n + logn
std::vector<std::pair<int, int>> findPairWithGivenSum(std::vector<int> &a, int sum)
{
	std::vector<std::pair<int, int>> sum_collections;
	int i = findIndexMinRotatedArray(a, 0, a.size() / 2, a.size());
	int l = i - 1;
	int r = i;
	//{ 11, 15, 6, 8, 9, 10 };
	while (l != r)
	{
		if ((a[l] + a[r]) == sum)
		{
			sum_collections.push_back(std::make_pair(a[l], a[r]));
			l = (a.size() + l - 1) % a.size();
			r = (r + 1) % a.size();
		}
		else if ((a[l] + a[r]) > sum)
			l = (a.size() + l - 1) % a.size();
		else
			r = (r + 1) % a.size();
	}

	return sum_collections;
}

// for this nlogn + n and extra space
std::vector<std::pair<int, int>> findPairWithGivenSumWithSorting(std::vector<int> a, int sum)
{
	std::vector<std::pair<int, int>> sum_collections;
	std::sort(a.begin(), a.end());
	auto l_it = a.begin();
	auto r_it = --a.end();
	while (l_it != r_it)
	{
		if ((*l_it + *r_it) == sum)
		{
			sum_collections.push_back(std::make_pair(*l_it, *r_it));
			--r_it;
			l_it++;
		}
		else if ((*l_it + *r_it) > sum)
			--r_it;
		else
			l_it++;
	}

	return sum_collections;
}

/*
Answer: https://www.geeksforgeeks.org/check-reversing-sub-array-make-array-sorted/
O(nlogn)
*/

bool checkReverse(std::vector<int> &arr)
{
	std::vector<int> temp(arr);

	std::sort(temp.begin(), temp.end());

	// finding first mismatch
	int front = 0;
	for (; front < arr.size(); ++front)
	{
		if (temp[front] != arr[front])
			break;
	}

	// finding last mismatch
	int back = 0;
	for (; back < arr.size(); ++back)
	{
		if (temp[back] != arr[back])
			break;
	}

	if (front > back) // array is sorted
		return true;

	while (front < back) //check if its the sub array really is decreasing in order
	{
		if (arr[front] < arr[front] + 1)
			return false;
		++front;
	}

	return true;
}