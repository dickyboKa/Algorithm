#include <vector>
#include <iostream>


std::vector<int> longestPrefixSuffix(std::string pattern);

void kmpSearch(std::string text, std::string pattern)
{

	auto lps = longestPrefixSuffix(pattern);

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < text.size()) 
	{
		if (pattern[j] == text[i]) 
		{
			j++;
			i++;
		}

		if (j == pattern.size()) 
		{
			std::cout << "Found pattern at index " << i - j << std::endl;
			j = lps[j - 1];
		}
		else if (i < text.size() && pattern[j] != text[i]) 
		{
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

std::vector<int> longestPrefixSuffix(std::string pattern)
{
	std::vector<int> result(pattern.size());

	int length = 0;
	result[0] = 0;

	int index = 1;
	while (index < pattern.size())
	{
		if (pattern[index] == pattern[length])
		{
			result[index] = ++length;
			++index;
		}
		else
		{
			if (length != 0) {
				length = result[length - 1];
			}
			else
			{
				result[index] = 0;
				index++;
			}
		}
	}

	return result;
}
