#include <iostream>
#include <vector>
#include "Searching/LargestElement.h"

using namespace std;


int main()
{
	vector<int> a = { 10, 4, 3, 50, 23, 90 };
	auto r = findlargestElement(a);
	std::copy(r.begin(), r.end(), ostream_iterator<int>(std::cout, ", "));
	return 0;
}


