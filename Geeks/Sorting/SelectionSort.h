#include <vector>
#include <iostream>

/*
Selection Sort: O(N^2);
*/
void selectionSort(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	for(auto it = beg; it != end; ++it)
	{
		auto temp_it = it;
		for (auto m_it = it + 1; m_it != end; ++m_it)
		{
			if (*m_it < *temp_it)
				temp_it = m_it;
		}

		//swap the smallest to front
		if (temp_it != it)
		{
			int temp = *it;
			*it = *temp_it;
			*temp_it = temp;
		}
	}
}
