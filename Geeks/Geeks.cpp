#include <iostream>
#include <vector>
#include "Searching/BinarySearch.h"

using namespace std;


int main()
{
	vector<int> a = { 3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170 };
	cout << infiniteSearch(a, 10) << endl;
	

	return 0;
}


