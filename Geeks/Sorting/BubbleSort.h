#include <vector>

void bubbleSort(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	while (true)
	{
		bool swap = false;
		auto it_a = beg;
		auto it_b = it_a + 1;
		for (; it_b != end; ++it_b)
		{
			if (*it_b < *it_a)
			{
				swap = true;
				int temp = *it_a;
				*it_a = *it_b;
				*it_b = temp;
			}
			++it_a;
		}

		if (!swap)
			break;
	}
}