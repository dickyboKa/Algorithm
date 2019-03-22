#include <vector>

// Normal Binary Search (O)logn
int binarySearch(std::vector<int> &a, int beg, int mid, int end, int key)
{
	if (end <= beg)
		return  -1;
	else if (key == a[mid])
		return mid;
	else if (key < a[mid])
		return binarySearch(a, beg, beg + ((mid - beg) / 2), mid - 1, key);
	else
		return binarySearch(a, mid + 1, mid + ((end - mid) / 2), end, key);
}
int IntSearch(std::vector<int> &a, int key)
{
	return binarySearch(a, 0, a.size() / 2, a.size(), key);
}

// answer to: https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/
int infiniteSearch(std::vector<int> &a, int key)
{
	//assume the array is infinite, if its not then there would be index out of bound
	int low = 0; int hi = 1;
	while (true)
	{
		if (key < a[hi])
			break;
		low = hi;
		hi = hi * 2;
	}
	return binarySearch(a, low, (hi - low)/2, hi, key);
}
/*
Found the righ most value after key, with binary search so it should be: (O)logn,
*/
int Ceilling(std::vector<int> &a, int beg, int mid, int end, int key)
{
	if (key < a[0])
		return  -1;
	else if (end - beg == 1)
		return end;
	else if (key < a[mid])
		return Ceilling(a, beg, beg + ((mid - beg) / 2), mid, key);
	else
		return Ceilling(a, mid, mid + ((end - mid) / 2), end, key);
}
int Ceilling(std::vector<int> &a, int key)
{
	return Ceilling(a, 0, a.size() / 2, a.size() , key);
}
/*
Found the left most value after key, with binary search so it should be: (O)logn,
*/
int Floor(std::vector<int> &a, int beg, int mid, int end, int key)
{
	if (key < a[0])
		return  -1;
	else if (end - beg == 1)
		return beg;
	else if (key > a[mid])
		return Floor(a, mid, mid + ((end - mid) / 2), end, key);
	else
		return Floor(a, beg, beg + ((mid - beg) / 2), mid, key);
}

int Floor(std::vector<int> &a, int key)
{
	return Floor(a, 0, a.size() / 2, a.size(), key);
}