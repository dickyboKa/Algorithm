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
/*
Found the righ most value after key, with binary search so it should be: (O)logn,
e.g:
array: 1,2,3,4,5; key: 3
return:      ^     [4]

Work like std::upper_bound;
*/
int Ceilling(std::vector<int> &a, int beg, int mid, int end, int key)
{
	if (key < a[0])
		return  -1;
	else if (end - beg == 1)
		return mid;
	else if (key < a[mid])
		return Ceilling(a, beg, beg + ((mid - beg) / 2), mid, key);
	else
		return Ceilling(a, mid, mid + ((end - mid) / 2), end, key);
}
int Ceilling(std::vector<int> &a, int key)
{
	return Ceilling(a, 0, a.size() / 2, a.size(), key);
}
/*
Found the left most value after key, with binary search so it should be: (O)logn,
e.g:
array: 1,2,3,4,5; key: 3
return:  ^	  [2]

Work like std::lower_bound;
*/
int Floor(std::vector<int> &a, int beg, int mid, int end, int key)
{
	if (key < a[0])
		return  -1;
	else if (end - beg == 1)
		return mid;
	else if (key > a[mid])
		return Floor(a, mid, mid + ((end - mid) / 2), end, key);
	else
		return Floor(a, beg, beg + ((mid - beg) / 2), mid, key);
}
int FLoor(std::vector<int> &a, int key)
{
	return Floor(a, 0, a.size() / 2, a.size(), key);
}