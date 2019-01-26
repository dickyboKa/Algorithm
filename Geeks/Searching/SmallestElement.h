#include <vector>
#include <algorithm>
#include <string>

/* this O(nlogn) 
answer to: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
*/
int findTheSmallestElementRankAt(std::vector<int> v, int kth)
{
	std::sort(v.begin(), v.end());
	return v[kth - 1];
}

/*
answer to: https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/
This should be O(n)
and it suspiciouly look like incomplete insertion sort :P
*/
std::vector<std::string> prevSmallesElement(std::vector<int> &a)
{
	std::vector<std::string> result{ "_" }; // first element have no smaller element obvi
	//1, 6, 4, 10, 2, 5
	std::vector<int>::const_iterator it = a.cbegin() + 1;
	for (; it != a.cend(); ++it)
	{
		std::vector<int>::const_reverse_iterator r_it = std::make_reverse_iterator(it);
		for (; r_it != a.crend(); ++r_it)
		{
			if (*r_it < *it)
			{
				result.push_back(std::to_string(*r_it));
				break;
			}
		}
		
		if (r_it == a.crend())
			result.push_back("_");
	}
	return result;
}