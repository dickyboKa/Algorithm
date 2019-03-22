#include <vector>

void heapify(std::vector<int> &arr, int i, int n)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i) //heapify recrusifely for child of root
	{
		std::swap(arr[i], arr[largest]);
		heapify(arr, largest, n);
	}
}

std::vector<int> heapSort(std::vector<int> &arr)
{
	std::vector<int> temp = arr;
	for(int i = (temp.size() / 2) - 1; i >= 0; --i)
		heapify(temp, i, temp.size());

	for (int i = temp.size() - 1; i >= 0; --i)
	{
		std::swap(temp[0], temp[i]);
		heapify(temp, 0, i);
	}

	return temp;
}