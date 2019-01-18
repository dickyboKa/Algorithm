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

/*
answer to geek exercises: https://www.geeksforgeeks.org/given-sorted-array-number-x-find-pair-array-whose-sum-closest-x/
*/
std::pair<int, int> findThePairByTheSumMerge(std::vector<int> &a, std::vector<int> &b, int x)
{
	std::vector<std::pair<int, int>> A;
	for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it)
	{
		A.push_back(std::pair<int, int>(*it, 1)); // to indicate this came from first array we give value 1;
	}

	for (std::vector<int>::iterator it = b.begin(); it != b.end(); ++it)
	{
		A.push_back(std::pair<int, int>(*it, 2)); // to indicate this came from second array we give value 2;
	}

	int  m, n, diff;
	diff = std::numeric_limits<int>::max();
	std::vector<std::pair<int,int>>::const_iterator l_it = A.cbegin();
	std::vector<std::pair<int, int>>::const_iterator r_it = --A.cend();

	while (true)
	{
		if (l_it->second == r_it->second)
			break;
		if (abs(l_it->first + r_it->first - x) < diff)
		{
			m = l_it->first;
			n = r_it->first;
			diff = abs(l_it->first + r_it->first - x);
		}
		else if ((l_it->first + r_it->first) < x)
			++l_it;
		else
			--r_it;
	}

	return std::pair<int, int>(m,n);
}

// much more simple solution no extra space, 
std::pair<int, int> findThePairByTheSum(std::vector<int> &A, std::vector<int> &B, int x)
{
	int  a, b, diff;
	diff = std::numeric_limits<int>::max();
	std::vector<int>::const_iterator l_it = A.cbegin();
	std::vector<int>::const_reverse_iterator r_it = B.crbegin();

	while (l_it != A.cend() && r_it != B.crend())
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
			++r_it;
	}
	return std::pair<int, int>(a, b);
}