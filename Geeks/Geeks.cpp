#include <iostream>
#include <vector>
#include <iterator>
#include "Mathematical/Combinations.h"

using namespace std;


int main()
{
	vector<int> a = { 1, -2, 1, 0, 5 };
	int sum = 0;
	auto r = findTripletsSumWithSort(a, sum);
	if (!r.empty())
	{
		for (auto it = r.cbegin(); it != r.cend(); ++it)
			cout << "Triplets with Sum[" << sum << "] are: {" << it->x << ", " << it->y << ", " << it->z << "}" << endl;
	}
	else
		cout << "No Triplets Found That Have Sum: " << sum << endl;
	return 0;
}


