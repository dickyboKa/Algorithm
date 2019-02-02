#include <vector>
#include <iostream>


/*
Answer to geeks: https://www.geeksforgeeks.org/find-all-combinations-that-adds-upto-given-number-2/
This is backtracking so it very worse in term of time complexity, probably O(n!)
*/

void findCombinationsSum(std::vector<int> &arr, int index,
	int num, int reducedNum)
{
	if (reducedNum < 0)
	{
		return;
	}
	if (reducedNum == 0)
	{
		for (int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
		return;
	}

	int prev = (index == 0) ? 1 : arr[index - 1] + 1;

	for (int k = prev; k <= num; k++)
	{
		arr.push_back(k);

		findCombinationsSum(arr, index + 1, num,
			reducedNum - k);
		arr.pop_back();
	}
}


void findCombinationsSum(int n)
{
	std::vector<int> arr;
	findCombinationsSum(arr, 0, n, n);
}