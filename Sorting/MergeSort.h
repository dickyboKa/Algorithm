#include <vector>
#include <iostream>

void merge(std::vector<int> &arr, int l, int m, int r)
{
	int i, j, k;
	std::vector<int> temp((r - l + 1), 0);
	i = l;
	k = 0;
	j = m + 1;

	// Merge the two parts into temp[].
	while (i <= m && j <= r)
	{
		if (arr[i] < arr[j])
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}


	// Insert all the remaining values from i to mid into temp[].
	while (i <= m)
	{
		temp[k] = arr[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= r)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}

	// Assign sorted data stored in temp[] to a[].
	for (i = l; i <= r; i++)
	{
		arr[i] = temp[i - l];
	}
	
}

void mergeSort(std::vector<int> &arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}