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


/*
answer to geeks: https://www.geeksforgeeks.org/print-possible-sums-consecutive-numbers-sum-n/
this would run on 0(n)
this different than above sollutions, in term of combinations it made. The boundary of this problem, is on the need to found
the numbers in consecutive manners (adjacent to one another with diff 1);
*/
void consecutiveNumbersSum(int N)
{
	int start, end, sum;
	start = end = sum = 1;

	while (start <= N / 2) // why n/2: because n/2 + (n/2 + 1), would always bigger than n;
	{
		if (sum < N)
		{
			end += 1;
			sum += end;
		}
		else if (sum > N)
		{
			// found starting number that would fit in;
			sum -= start;
			start += 1;
		}
		else if (sum == N)
		{
			for (int i = start; i <= end; ++i)
				std::cout << i << " ";
			std::cout << std::endl;
			sum -= start;
			start += 1; // look for another combination
		}
	}

}

