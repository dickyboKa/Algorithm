#include <iostream>
#include <vector>
#include "Searching/PairSortedArray.h"

using namespace std;


int main()
{
	// how many one
	vector<int> a = { 1, 4, 5, 7 };
	vector<int> b = { 10, 20, 30, 40 };
	auto result = findThePairByTheSum(a, b, 32);
	cout << "(" << result.first << "," << result.second << ")" << endl;
	result = findThePairByTheSum(a, b, 50);
	cout << "(" << result.first << "," << result.second << ")" << endl;
	return 0;
}


