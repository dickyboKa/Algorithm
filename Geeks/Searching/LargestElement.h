#include <vector>


/*
answer to: https://www.geeksforgeeks.org/find-the-largest-three-elements-in-an-array/
this should be: O(n)
*/
std::vector<int> findlargestElement(std::vector<int> &a)
{
	int first, second, third;
	first = second = third = std::numeric_limits<int>::min();

	for (auto it = a.cbegin(); it != a.cend(); ++it)
	{
		if (*it > first)
		{
			third = second;
			second = first;
			first = *it;
		}
		else if (*it > second)
		{
			third = second;
			second = *it;
		}
		else
			third = *it;
	}
	return std::vector<int>{first, second, third};
}