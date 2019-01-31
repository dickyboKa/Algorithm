#include <iostream>
#include <vector>
#include "Searching/TournamentTree.h"

using namespace std;


int main()
{
	vector<int> a = { 61, 6, 100, 9, 10, 12, 17 };
	TourNamentTree *tree = new TourNamentTree(a);
	cout << tree->getFirstRankedValue() << endl;
	cout << tree->getSecondRankedValue();
	return 0;
}


