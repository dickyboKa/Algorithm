#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <array>
#include <regex>
#include <unordered_map>

void sortByFrequencey(std::vector<int> &a)
{
	std::map<int, int> m;
	for (auto it = a.cbegin(); it != a.cend(); ++it)
	{
		auto m_it = m.insert(std::make_pair(*it, 1));
		if (m_it.second == false)
			m_it.first->second++; // if the value aready present up the count;
	}
	std::vector<std::pair<int, int>> temp;
	for (auto it = m.cbegin(); it != m.cend(); ++it)
	{
		temp.push_back(std::make_pair(it->first, it->second));
	}

	std::sort(temp.begin(), temp.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
		return a.second > b.second;
	});
	a.clear();
	for (auto it = temp.cbegin(); it != temp.cend(); ++it)
		for (int i = it->second; i > 0; --i)
			a.push_back(it->first);
}

// return index of unsorted array, left to righ
std::pair<int, int> foundUnsortedArray(std::vector<int> &a)
{
	std::vector<int> temp = a;
	std::sort(temp.begin(), temp.end());

	int i = 0;
	int j = a.size() - 1;
	int left_index = i;
	int right_index = j;
	bool foundi = false;
	bool foundj = false;
	while (i < j)
	{	 
		if (temp[i] != a[i] && !foundi)
		{
			left_index = i;
			foundi = true;
		}
		
		if (temp[j] != a[j] && !foundj)
		{
			right_index = j;
			foundj = true;
		}
		++i;
		--j;
	}

	return std::make_pair(left_index, right_index);
}

// check if array b is a subset of array a
bool subsetArray(std::vector<int> a, std::vector<int> b)
{
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	auto jt = b.cbegin();
	bool subset = false;
	for (auto it = a.cbegin(); it != a.cend(); ++it)
	{
		if (jt == b.cend())
		{
			subset = true;
			break;
		}

		if (*it == *jt)
			++jt;
	}
	return subset;
}

// sort number with min heap
void sortPriorityQueue(std::vector<int> &arr)
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	for (auto it = arr.cbegin(); it != arr.cend(); ++it)
		pq.push(*it);

	arr.clear();
	while (!pq.empty())
	{
		arr.push_back(pq.top());
		pq.pop();
	}

}

// found number pair which have this rule x^y > y^x (x taken from array A, y taken from array B)
void foundNumberPair(std::vector<int> a, std::vector<int> b)
{
	std::vector<std::pair<int, int>> result;
	//if y > x then x^y > y^x with some exception;
	std::array<std::array <int, 5>, 5> tableException =
	{ {
		{0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0},
		{1, 1, 0, 0, 0},
		{1, 1, 1, 0, 1},
		{1, 1, 0, 0, 0},
	} };

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	std::vector<std::pair<int, int>> indexOfResult;
	for (int i = 0; i < a.size(); ++i)
	{
		auto it = std::upper_bound(b.begin(), b.end(), a[i]);
		int index = it - b.begin();
		if (!((a[i] < 5 && *it < 5) && !tableException[a[i]][*it]))
			indexOfResult.push_back(std::make_pair(a[i], index));
	}

	for (auto it = indexOfResult.begin(); it != indexOfResult.end(); ++it)
	{
		for (int i = it->second; i < b.size(); ++i)
			result.push_back(std::make_pair(it->first, b[i]));
	}

	for (auto it = result.begin(); it != result.end(); ++it)
		std::cout << it->first << " " << it->second << std::endl;

}

int countPairWithSumEqualTo(std::vector<int> &a, int k)
{
	std::set<int> mySet;
	int count = 0;
	for (auto it = a.cbegin(); it != a.cend(); ++it)
	{
		int check = (*it < k) ? (*it + k) : (*it - k);
		auto found = mySet.find(check);
		if (found != mySet.end())
			++count;
		mySet.insert(*it);
	}
	return count;
}

/*
Sorting an array according to specific order from other array
*/
void sortSpecificOrder(std::vector<int> &tobeSorted, std::vector<int> &order)
{
	/*
	first make a array that would count the value of ordered in tobeSorted
	resize it to have at most biggest value on tobeSorted
	*/
	int max = 0;
	for (auto it = tobeSorted.cbegin(); it != tobeSorted.cend(); ++it) // O(N);
	{
		if (*it > max)
			max = *it;
	}
	std::vector<int> count(max + 1);

	// populate the count
	for (auto it = tobeSorted.cbegin(); it != tobeSorted.cend(); ++it) // O(N);
		++count[*it];

	tobeSorted.clear();

	//tobeSorted according to order
	for (auto it = order.cbegin(); it != order.cend(); ++it) // O(K)
	{
		// count is not 0 value available
		while(count[*it] > 0) //O (M)
		{
			tobeSorted.push_back(*it);
			--count[*it];
		}
	} // K * M

	//put the rest that not on order, skip 0
	for (int i = 1; i < count.size(); ++i) //N
	{
		if (count[i] > 0)
		{
			tobeSorted.push_back(i);
			--count[i];
		}
	}
	// total: O(3N + K*M) or lets just said O(N) with extra Space for count;
}

void sortInWave(std::vector<int> &a)
{
	int N = a.size();
	for (int i = 0; i < N; i+=2)
	{
		if (i > 0 && a[i] < a[i - 1])
			std::swap(a[i], a[i - 1]);

		if (i < N - 1 && a[i] < a[i + 1])
			std::swap(a[i], a[i + 1]);
	}
}

// finding an interval value that overlap
void findOverlapInterval(std::vector<std::pair<int, int>> &set)
{
	std::vector<std::pair<int, int>> overlaps;
	std::sort(set.begin(), set.end()); // O(nlogn)
	
	auto it = set.cbegin();
	auto jt = it + 1;
	while (jt != set.cend()) // O (N/2)
	{
		if (it->second > jt->first)
		{
			overlaps.push_back(std::make_pair(it->first, it->second));
			overlaps.push_back(std::make_pair(jt->first, jt->second));
		}
		++it;
		++jt;
	}

	if (!overlaps.empty())
	{
		for (auto it = overlaps.cbegin(); it != overlaps.cend(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
	}
	else
		std::cout << "No pair of interval overlap" << std::endl;
}


void almostSort(std::vector<int> &arr)
{
	int i = 0;
	int j = 1;
	int m = arr.size() - 1;
	int k = m - 1;
	int a = 0;
	int b = 0;


	while (i < m)
	{
		if (arr[i] > arr[j])
			a = (a == 0) ? i : a;

		if (arr[m] < arr[k])
			b = (b == 0) ? m : b;
		++i; ++j;
		--k, --m;
	}

	if (a != 0 && b != 0)
		std::swap(arr[a], arr[b]);
}


void findMaxGuestInParty(std::vector<int> &arival, std::vector<int> &departure)
{
	// sort the arival and departure
	std::sort(arival.begin(), arival.end());
	std::sort(departure.begin(), departure.end());

	int guest = 0;
	int max_guest = 0;
	int i = 0;
	int j = 0;
	int time = arival[0];

	// we loop on both array, take a note what even is occure, either people come in or people going
	while (i < arival.size() & j < departure.size())
	{
		if (arival[i] <= departure[j]) //people come in
		{
			++guest;
			if (guest > max_guest)
			{
				max_guest = guest;
				time = arival[i]; //update time when max even occured
			}
			++i; // increment even
		}
		else // people going
		{
			--guest;
			++j; // incremenet even
		}
	}

	std::cout << "The maximum guest in party is: " << max_guest << " at time: " << time;
}

class myDate
{
public:
	myDate(int d, int m, int y) : day(d), month(m), year(y) 
	{
		// this is totally flaw, but my goal is learn regrex, so ?
		int yearToDay = y * 365;
		int monthToDay = m * 30;
		totalTimeInDay = yearToDay + monthToDay + day;
 	}
	int day;
	int month;
	int year;
	int totalTimeInDay;
};

void sortDate(std::vector<std::string> &dates)
{
	std::vector<myDate> myDates;
	for (auto it = dates.cbegin(); it != dates.cend(); ++it)
	{
		std::regex e("(^\\d{1,2})-(\\d{1,2})-(\\d{4})");
		std::smatch sm;
		std::regex_match(*it, sm, e);
		int day = std::stoi(sm[1]);
		int month = std::stoi(sm[2]);
		int year = std::stoi(sm[3]);
		myDates.push_back(myDate(day, month, year));
	}
	
	std::sort(myDates.begin(), myDates.end(), [](myDate a, myDate b) {
		return a.totalTimeInDay < b.totalTimeInDay;
	});

	for (auto it = myDates.cbegin(); it != myDates.cend(); ++it)
	{
		std::cout << it->day << "-" << it->month << "-" << it->year << std::endl;
	}
}

void maximumProductOfTriplet(std::vector<int> &arr)
{
	if (arr.size() < 3)
		return; // can do if array is not 3 or more.
	// first we sorted:
	std::sort(arr.begin(), arr.end());

	// then we consider some options base on is there a negative value or not
	int n = arr.size() - 1;
	int first_product = arr[n] * arr[n - 1] * arr[n - 2];
	int second_product = arr[0] * arr[1] * arr[n];
	int max_product = (first_product > second_product) ? first_product : second_product;
	std::cout << max_product << std::endl;
}

//find missing element on array from low to high given as parameter
void findMissingElement(std::vector<int> &arr, int low, int high)
{

	std::sort(arr.begin(), arr.end());
	std::vector<int>::iterator it = std::lower_bound(arr.begin(), arr.end(), low);
	while(low < high && it != arr.end())
	{
		if (low != *it)
			std::cout << low << " ";
		else
			++it;

		++low;
	}

	// print the rest of it if any ?
	while (low < high)
	{
		std::cout << low << " ";
		++low;
	}
}


/*
Find Minimum Sum formed from all number on array
*/
void minimumSumArray(std::vector<int> &arr)
{
	std::sort(arr.begin(), arr.end(), std::greater<int>());
	int a = 0;
	int b = 0;
	bool fill_a, fill_b;
	fill_a = true;
	int delim = 1;
	// fill the lest significant digit 
	for (auto it = arr.cbegin(); it != arr.cend(); ++it)
	{
		if (fill_a)
		{
			a = a + ((*it) * delim);
			fill_a = false;
			fill_b = true;
		}
		else if (fill_b)
		{
			b = b + ((*it) * delim);
			fill_b = false;
			fill_a = true;
		}

		if(fill_a)
			delim = delim * 10;
	}

	std::cout << a << " " << b << std::endl;
	std::cout << "minimum sum: " << a + b << std::endl;

}



void findMinimumDiff(std::vector<int> &arr)
{
	std::sort(arr.begin(), arr.end());
	int diff = std::numeric_limits<int>::max();

	for (int i = 0; i < arr.size() - 1; ++i)
	{
		if ((arr[i + 1] - arr[i]) < diff)
			diff = arr[i + 1] = arr[i];
	}

	std::cout << diff;
}

void collectionsInReduceForm(std::vector<int> &collections)
{
	std::vector<int> collectionsSorted(collections);
	std::sort(collectionsSorted.begin(), collectionsSorted.end());

	// this will concise of original value pair with reduce form value e.g: 10 with 0;
	std::unordered_map<int, int> pairOriginalReduce;

	int reduceValue = 0;
	for (auto it = collectionsSorted.cbegin(); it != collectionsSorted.cend(); ++it)
		pairOriginalReduce[*it] = reduceValue++;

	// change the original collections to reduce form
	for (auto it = collections.begin(); it != collections.end(); ++it)
		*it = pairOriginalReduce[*it];

	// print the collections
	for (auto it = collections.cbegin(); it != collections.cend(); ++it)
		std::cout << *it << " ";
}

int _merge(std::vector<int> &collection, std::vector<int> &temp, int leftIndex, int midIndex, 
	int rightIndex, std::unordered_map<int, int> &inversions)
{
	int leftSubarrayIndex = leftIndex;
	int rightSubarrayIndex = midIndex;
	int populateIndex = leftIndex;
	int inverseCount = 0;
	int inverse = 0;

	while ((leftSubarrayIndex <= midIndex - 1) && (rightSubarrayIndex <= rightIndex))
	{
		if (collection[leftSubarrayIndex] <= collection[rightSubarrayIndex])
		{
			inversions[collection[leftSubarrayIndex]] += inverse;
			temp[populateIndex++] = collection[leftSubarrayIndex++];
		}
		else
		{
			temp[populateIndex++] = collection[rightSubarrayIndex++];
			inverseCount = inverseCount + (midIndex - leftSubarrayIndex);
			++inverse;
		}
	}

	//populate the rest
	/* Copy the remaining elements of left subarray
	   (if there are any) to temp*/
	while (leftSubarrayIndex <= midIndex - 1)
	{
		inversions[collection[leftSubarrayIndex]] += inverse;
		temp[populateIndex++] = collection[leftSubarrayIndex++];
	}
	/* Copy the remaining elements of right subarray
   (if there are any) to temp*/
	while (rightSubarrayIndex <= rightIndex)
		temp[populateIndex++] = collection[rightSubarrayIndex++];

	/*Copy back the merged elements to original array*/
	for (leftSubarrayIndex = leftIndex; leftSubarrayIndex <= rightIndex; leftSubarrayIndex++)
		collection[leftSubarrayIndex] = temp[leftSubarrayIndex];

	return inverseCount;
}

int mergeSort(std::vector<int> &collection, std::vector<int> &temp, int leftIndex, 
	int rightIndex, std::unordered_map<int, int> &inversions)
{
	int midIndex = 0;
	int inverseCount = 0;

	if (rightIndex > leftIndex)
	{
		midIndex = (rightIndex + leftIndex) / 2;

		// divide and found the smallest array to conquer with recrusion
		inverseCount = mergeSort(collection, temp, leftIndex, midIndex, inversions);
		inverseCount += mergeSort(collection, temp, midIndex + 1, rightIndex, inversions);

		//now merge the two part array recrusively
		inverseCount += _merge(collection, temp, leftIndex, midIndex + 1, rightIndex, inversions);
	}

	return inverseCount;
}

int countInversion(std::vector<int> &collections)
{
	std::unordered_map<int, int> inversions;
	std::vector<int> copyCollections(collections);
	std::vector<int> temp(collections.size());
	return mergeSort(copyCollections, temp, 0, copyCollections.size() - 1, inversions);
}


std::vector<int> surpasserCount(std::vector<int> &collections)
{
	std::unordered_map<int, int> inversions;
	std::vector<int> supressions;
	std::vector<int> copyCollections(collections);
	std::vector<int> temp(collections.size());
	mergeSort(copyCollections, temp, 0, copyCollections.size() - 1, inversions);

	for (int i = 0; i < collections.size(); ++i)
	{
		supressions.push_back((collections.size() - 1) - i - inversions[collections[i]]);
	}

	for (auto it = supressions.cbegin(); it != supressions.cend(); ++it)
		std::cout << *it << " ";

	return supressions;
}

// utility function t count bits
int countBit(int input)
{
	int count = 0;
	while (input)
	{
		if (input & 1) //if last bits is one;
			count += 1;
		input = input >> 1; //shift to the right;
	}
	return count;
}

void sortByBitCount(std::vector<int> &collections)
{
	std::vector<std::pair<int, int>> bitsCount;
	for (auto it = collections.cbegin(); it != collections.cend(); ++it)
		bitsCount.push_back(std::make_pair(*it, countBit(*it)));

	std::sort(bitsCount.begin(), bitsCount.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
		return a.second > b.second;
	});

	for (auto it = bitsCount.cbegin(); it != bitsCount.cend(); ++it)
		std::cout << it->first << " ";
}
