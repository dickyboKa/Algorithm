#include <vector>
#include <iostream>
#include <iterator>

// for simplicity only number 0 to 9; :)
void countSort(std::vector<int> &arr, int exponent = 1)
{
	// initialize table of 0 to 9, with count 0
	std::vector<int> count_table(10, 0);

	// count the number of occurance between number 0 to 9 in array
	for (auto it = arr.cbegin(); it != arr.cend(); ++it)
		++count_table[(*it / exponent) % 10];

	// add count in current index, with previous count;
	auto it_prev = count_table.begin();
	auto it_current = it_prev + 1;
	while (it_current != count_table.end())
	{
		*it_current += *it_prev;
		++it_prev;
		++it_current;
	}

	// put arr number in order by looking at count table
	std::vector<int> output(arr.size(), 0);
	for (auto it = arr.crbegin(); it != arr.crend(); ++it)
	{
		output[count_table[(*it / exponent) % 10] - 1] = *it;
		--count_table[(*it / exponent) % 10];

	}

	arr = output;
}
