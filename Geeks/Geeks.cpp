#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "Searching/SmallestElement.h"

using namespace std;


int main()
{
	vector<int> a = { 1, 6, 4, 10, 2, 5 };
	auto r = prevSmallesElement(a);
	copy(r.cbegin(), r.cend(), ostream_iterator<std::string>(cout, ", "));
	return 0;
}


