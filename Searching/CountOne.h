#include <vector>
#include <algorithm>

int howManyOneInThisArray(std::vector<int> &a)
{
	std::sort(a.begin(), a.end());
	std::vector<int>::iterator low_it = std::lower_bound(a.begin(), a.end(), 1);
	std::vector<int>::iterator upper_it = std::upper_bound(a.begin(), a.end(), 1);
	if (low_it != a.end())
		return upper_it - low_it;;

	return 0;
}
