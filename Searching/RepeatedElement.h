#include <vector>
#include <unordered_set>


/*
answer to geek exercises: https://www.geeksforgeeks.org/find-first-repeating-element-array-integers/
*/
int findRepeteadElementFrom(std::vector<int> &v)
{
	std::unordered_set<int> s;
	int answer;
	for (std::vector<int>::const_reverse_iterator it = v.crbegin(); it != v.crend(); ++it)
	{
		std::pair<std::unordered_set<int>::iterator, bool> check = s.insert(*it);
		if (check.second == false)
			answer = *it;
	}
	return answer;
}
