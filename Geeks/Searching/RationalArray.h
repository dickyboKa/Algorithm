#include <vector>

int compare(std::pair<int, int> &fraction_A, std::pair<int, int> &fraction_B)
{
	if (fraction_A.first * fraction_B.second == fraction_B.first * fraction_A.second)
		return 0;
	else if (fraction_A.first * fraction_B.second > fraction_B.first * fraction_A.second)
		return 1;
	else
		return -1;
}

int searchRatNumber(std::vector<std::pair<int, int>> &a, int beg, int mid, int end, std::pair<int, int> key)
{
	if (end <= beg)
		return -1; // base case
	else if (compare(a[mid], key) == 0)
		return mid;
	else if ((compare(a[mid], key) > 0))
		return searchRatNumber(a, mid + 1, mid + ((end - mid) / 2), end, key);
	else
		return searchRatNumber(a, beg, beg + ((mid - beg) / 2), mid - 1, key);
}

int searchRatNumber(std::vector<std::pair<int, int>> &a, std::pair<int, int> key)
{
	return searchRatNumber(a, 0, a.size() / 2, a.size(), key);
}