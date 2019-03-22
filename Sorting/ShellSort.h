#include <vector>

void shellSort(std::vector<int> &a)
{
	int N = a.size();
	int gap = 1;
	// build a gap
	while (gap < N / 3) gap = 3 * gap + 1;
	// insertion sort with a gap
	while (gap >= 1)
	{
		for (int i = gap; i < N; ++i)
		{
			int temp = a[i];
			int j;
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
				a[j] = a[j - gap];

			a[j] = temp;
		}
		gap = gap / 3;
	}
}