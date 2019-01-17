#include <algorithm>
#include "BinarySearch.h"

// copy an element from array, point by left and right index
void getSurroundElement(int l, int r, int k, int key, std::vector<int> i, std::vector<int> &o)
{
	int count = 0;
	while (count < k)
	{
		if (l != -1 && r != i.size())
		{
			if (key - i[l] < i[r] - key)
				o.push_back(i[l--]);
			else
				o.push_back(i[r++]);
		}
		else if (l == -1)
		{
			o.push_back(i[r++]);
		}
		else
		{
			o.push_back(i[l--]);
		}
		++count;

	}
}

/*
answer to geek exercises: https://www.geeksforgeeks.org/find-k-closest-elements-given-value/
*/
std::vector<int> findClosestElementOf(std::vector<int> a, int key, int howMany)
{
	std::vector<int> temp;
	if (a.size() < howMany)
		return temp; //array is less than values wanted just no way
	int l = Floor(a, key);
	int r = Ceilling(a, key);

	(a[l] == key) ? l = l - 1 : l = l;
	(a[r] == key) ? r = r + 1 : r = r;

	getSurroundElement(l, r, howMany, key, a, temp);
	return temp;
}

/*
answer to geek exercises: https://www.geeksforgeeks.org/find-k-closest-elements-given-value/
But using std lower bound and upper bound
*/
std::vector<int> findCloesestElementOfUsingStd(std::vector<int> a, int key, int howMany)
{
	std::vector<int> temp;
	if (a.size() < howMany)
		return temp; //array is less than values wanted just no way
	std::vector<int>::iterator low, up;
	low = std::lower_bound(a.begin(), a.end(), key);
	up = std::upper_bound(a.begin(), a.end(), key);
	int l, r;
	(*low == key) ? l = low - a.begin() - 1 : l = low - a.begin();
	r = up - a.begin();

	getSurroundElement(l, r, howMany, key, a, temp);
	return temp;
}