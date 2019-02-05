#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Searching/ClosestElement.h"

using namespace std;


int main()
{
	
	vector<int> A = { 5, 2, 8 };
	sort(A.begin(), A.end());
	copy(A.cbegin(), A.cend(), ostream_iterator<int>(cout, ", "));
	cout << endl;
	vector<int> B = { 10, 7, 12 };
	sort(B.begin(), B.end());
	copy(B.cbegin(), B.cend(), ostream_iterator<int>(cout, ", "));
	cout << endl;
	vector<int> C = { 9, 14, 6 };
	sort(C.begin(), C.end());
	copy(C.cbegin(), C.cend(), ostream_iterator<int>(cout, ", "));
	cout << endl;

	auto r = findThreeClosesElement(A, B, C);
	copy(r.cbegin(), r.cend(), ostream_iterator<int>(cout, ", "));
	return 0;
}


