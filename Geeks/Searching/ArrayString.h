#include <string>
#include <vector>


int searchStrings(std::vector<std::string> &arr_string, int beg, int mid, int end, std::string key)
{
	if (end <= beg)
		return -1;

	if(arr_string[mid].empty())
	{
		int left = mid - 1;
		int right = mid + 2;
		while (true)
		{
			if (left < beg && right > end)
				return -1;
			if (right <= end && !arr_string[right].empty())
			{
				mid = right;
				break;
			}
			if (left >= beg && !arr_string[left].empty())
			{
				mid = left;
				break;
			}
			++right;
			--left;
		}
	}

	int compare = arr_string[mid].compare(key);
	if (compare == 0)
		return mid;
	else if (compare < 0)
		return searchStrings(arr_string, mid + 1, mid + (end - mid) / 2, end, key);
	else
		return searchStrings(arr_string, beg, beg + (mid - beg) / 2, mid - 1, key);
}

int searchStrings(std::vector<std::string> &arr_string, std::string key)
{
	return searchStrings(arr_string, 0, arr_string.size() / 2, arr_string.size() - 1, key);
}
