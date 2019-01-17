#include <vector>
#include <cmath>

/*
answer to geek exercises: https://www.geeksforgeeks.org/given-sorted-array-number-x-find-pair-array-whose-sum-closest-x/
*/
std::pair<int, int> findThePairByTheSum(std::vector<int> &A, int x)
{
	int  a, b, diff;
	diff = std::numeric_limits<int>::max();
	std::vector<int>::const_iterator l_it = A.cbegin();
	std::vector<int>::const_iterator r_it = --A.cend();

	while (l_it != r_it)
	{
		if (abs(*l_it + *r_it - x) < diff)
		{
			a = *l_it;
			b = *r_it;
			diff = abs(*l_it + *r_it - x);
		}
		else if ((*l_it + *r_it) < x)
			++l_it;
		else
			--r_it;
	}
	return std::pair<int, int>(a, b);
}