#pragma once
#include <string>
#include <vector>
#include <iostream>


bool compareDictionary(std::vector<int> &dictA, std::vector<int> &dictB)
{
	if (dictA.size() != dictB.size())
		return false; // something is teribly wrong

	for (int i = 0; i < dictA.size(); ++i)
	{
		if (dictA[i] != dictB[i])
			return false;
	}

	return true;
}


void anagaramSearch(std::string text, std::string pattern)
{
	const int ASCI_MAX = 256;
	const int patternLenght = pattern.size();
	const int textLenght = text.size();
	std::vector<int> patternCharDictionary(ASCI_MAX);
	std::vector<int> textCharDictionary(ASCI_MAX);

	// countP[]:  Store count of all characters of pattern 
	// countTW[]: Store count of current window of text 
	for (int i = 0; i < patternLenght; ++i)
	{
		patternCharDictionary[pattern[i]]++;
		textCharDictionary[text[i]]++;
	}

	// Traverse through remaining characters of pattern 
	for (int i = patternLenght; i < textLenght; ++i)
	{
		// Compare counts of current window of text with 
		// counts of pattern[] 
		if (compareDictionary(patternCharDictionary, textCharDictionary))
			std::cout << "Found at index " << (i - patternLenght) << std::endl;

		// Add current character to current window 
		textCharDictionary[text[i]]++;

		// Remove the first character of previous window 
		textCharDictionary[text[i - patternLenght]]--;

	}

	if (compareDictionary(patternCharDictionary, textCharDictionary))
		std::cout << "Found at index " << (textLenght - patternLenght) << std::endl;

}