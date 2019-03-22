#include <vector>

/*
Simillar to Bubble Sort but it use GAP.
*/

int getNextGap(int gap)
{
	gap = (gap * 10) / 13;

	if (gap < 1)
		return 1;
	return gap;
}

void combSort(std::vector<int> &arr)
{
	int arr_size = arr.size();
	int gap = arr_size;

	while (gap != 1)
	{
		gap = getNextGap(gap);
		bool swapped = false;

		for (int i = 0; i < arr_size - gap; i++)
		{
			if (arr[i] > arr[i + gap])
			{
				std::swap(arr[i], arr[i + gap]);
				swapped = true;
			}
		}

		//if (swapped)
			//break;
	}

}