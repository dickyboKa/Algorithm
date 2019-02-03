#include <algorithm>
#include <cmath>
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

	//(a[l] == key) ? l = l - 1 : l = l;
	//(a[r] == key) ? r = r + 1 : r = r;

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

/*
asnwer to: https://www.geeksforgeeks.org/find-three-closest-elements-from-given-three-sorted-arrays/
O(n)
*/
std::vector<int> findThreeClosesElement(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c)
{
	int diff = std::numeric_limits<int>::max();
	int elem_a, elem_b, elem_c;

	std::vector<int>::const_iterator a_it = a.cbegin();
	std::vector<int>::const_iterator b_it = b.cbegin();
	std::vector<int>::const_iterator c_it = c.cbegin();

	while (a_it != a.cend() && b_it != b.cend() && c_it != c.cend())
	{
		int max = std::max(*a_it, std::max(*b_it, *c_it));
		int min = std::min(*a_it, std::min(*b_it, *c_it));

		if (max - min < diff)
		{
			diff = max - min;
			elem_a = *a_it; elem_b = *b_it; elem_c = *c_it;
		}

		if (diff == 0)
			break; 

		// to get closer to the smallest diff between element, up the smallest value
		if (*a_it == min)
			++a_it;
		else if (*b_it == min)
			++b_it;
		else
			++c_it;
	}

	return std::vector<int>{elem_a, elem_b, elem_c};
}

/*
Answer to geeks: https://www.geeksforgeeks.org/make-array-elements-equal-minimum-cost/
Change all the value on array to the same element x, which x is minimum 0..n - x.
*/
int computeCost(std::vector<int> &arr, int X)
{
	int cost = 0;
	for (auto it = arr.cbegin(); it != arr.cend(); ++it)
		cost += abs(*it - X);
	return cost;
}

int mininumCostToChange(std::vector<int> &arr)
{
	int low, high;
	low = high = arr[0];

	for (auto it = arr.cbegin(); it != arr.cend(); ++it)
	{
		if (*it < low)
			low = *it;
		if (*it > high)
			high = *it;
	}

	while ((high - low) > 2)
	{
		int mid1 = low + (high - low) / 3;
		int mid2 = high - (high - low) / 3;

		int cost1 = computeCost(arr, mid1);
		int cost2 = computeCost(arr, mid2);

		if (cost1 < cost2)
			high = mid2;
		else
			low = mid1;

	}
	//gets optimum cost by sending average of low and high as X 
	return computeCost(arr, (low + high) / 2);
}