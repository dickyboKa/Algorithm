#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
#include <iostream>
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


/*
answer to: https://www.geeksforgeeks.org/kth-largest-element-in-a-stream/
This should be O(logn) for inseert, erase, because std set use RBT data structure
*/
template<typename T>
class LimMinSet 
{
public:
	LimMinSet(int e) : m_max_size(e){}

	LimMinSet(int e, std::vector<T> &a) : m_max_size(e)
	{
		for (auto it = a.cbegin(); it != a.cend(); ++it)
		{
			insert(*it);
		}
	}

	auto cbegin()
	{
		return m_min_set.cbegin();
	}

	auto cend()
	{
		return m_min_set.cend();
	}

	void insert(T t)
	{
		if (m_min_set.size() == m_max_size)
		{
			if (t > *m_min_set.cbegin())
			{
				m_min_set.erase(m_min_set.begin());
				m_min_set.insert(t);
			}
		}
		else
			m_min_set.insert(t);
	}

	void printLargestElement()
	{
		if (m_min_set.size() < m_max_size)
			return;
		std::cout << m_max_size << "'th largest element is " << *m_min_set.cbegin() << std::endl;
	}

private:
	int m_max_size;
	std::set<T> m_min_set;
};