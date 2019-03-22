#include <vector>

std::vector<int> findCommonElement(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c)
{
	std::vector<int> r;

	std::vector<int>::const_iterator a_it = a.cbegin();
	std::vector<int>::const_iterator b_it = b.cbegin();
	std::vector<int>::const_iterator c_it = c.cbegin();

	while (a_it != a.cend() && b_it != b.cend() && c_it != c.cend())
	{
		if (*a_it == *b_it && *b_it == *c_it)
		{
			r.push_back(*a_it);
			++a_it; ++b_it; ++c_it;
		}
		else if (*a_it < *b_it)
			++a_it;
		else if (*b_it < *c_it)
			++b_it;
		else
			++c_it;
	}

	return r;
}
