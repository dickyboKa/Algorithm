#include <vector>


/*
Answer to: https://www.geeksforgeeks.org/search-an-element-in-an-array-where-difference-between-adjacent-elements-is-1/
The fact that difference between all adjacent elements is 1, make this solution worked, by calculating diff, 
we know we getting closer to the elemet to be search
*/
int searchElement(std::vector<int> &a, int x)
{
	int i = 0;
	while (i < a.size())
	{
		if (a[i] == x)
			return i; //index
		i = i + abs(a[i] - x);
	}

	return -1; //no element is present
}