#include <iostream>
#include <string>
#include <vector>
#include "Searching/RotateArray.h"

using namespace std;


int main()
{
	vector<int> a = { 11, 15, 6, 8, 9, 10 };
	auto r = findPairWithGivenSum(a, 16);
	std::cout << r.empty();
	return 0;
}


