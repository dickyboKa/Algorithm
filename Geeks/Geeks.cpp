#include <iostream>
#include <vector>
#include "Searching/SortedArray.h"

using namespace std;


int main()
{
	vector<int> a = { 1, 1, 3, 3, 4, 4, 5, 5, 7, 7, 8 };
	cout << findElementThatAppearOnce(a) << endl;

	return 0;
}


