#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>

void sortByFrequencey(std::vector<int> &a)
{
	std::map<int, int> m;
	for (auto it = a.cbegin(); it != a.cend(); ++it)
	{
		auto m_it = m.insert(std::make_pair(*it, 1));
		if (m_it.second == false)
			m_it.first->second++; // if the value aready present up the count;
	}
	std::vector<std::pair<int, int>> temp;
	for (auto it = m.cbegin(); it != m.cend(); ++it)
	{
		temp.push_back(std::make_pair(it->first, it->second));
	}

	std::sort(temp.begin(), temp.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
		return a.second > b.second;
	});
	a.clear();
	for (auto it = temp.cbegin(); it != temp.cend(); ++it)
		for (int i = it->second; i > 0; --i)
			a.push_back(it->first);
}

// return index of unsorted array, left to righ
std::pair<int, int> foundUnsortedArray(std::vector<int> &a)
{
	std::vector<int> temp = a;
	std::sort(temp.begin(), temp.end());

	int i = 0;
	int j = a.size() - 1;
	int left_index = i;
	int right_index = j;
	bool foundi = false;
	bool foundj = false;
	while (i < j)
	{	 
		if (temp[i] != a[i] && !foundi)
		{
			left_index = i;
			foundi = true;
		}
		
		if (temp[j] != a[j] && !foundj)
		{
			right_index = j;
			foundj = true;
		}
		++i;
		--j;
	}

	return std::make_pair(left_index, right_index);
}

// check if array b is a subset of array a
bool subsetArray(std::vector<int> a, std::vector<int> b)
{
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	auto jt = b.cbegin();
	bool subset = false;
	for (auto it = a.cbegin(); it != a.cend(); ++it)
	{
		if (jt == b.cend())
		{
			subset = true;
			break;
		}

		if (*it == *jt)
			++jt;
	}
	return subset;
}