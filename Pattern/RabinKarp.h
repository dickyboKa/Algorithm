#pragma once
#include <string>
#include <iostream>

#define ASCI_COUNT 256 

int getHashing(int patternSize, int primeNumber)
{
	int result = 1;
	for (int i = 0; i < patternSize - 1; i++)
		result = (result * ASCI_COUNT) % primeNumber;
	return result;
}

int createHashValue(std::string word, int primeNumber)
{
	int result = 0;
	for (int i = 0; i < word.size(); i++)
	{
		result = (ASCI_COUNT * result + word[i]) % primeNumber;
	}
	return result;
}

int subtractHash(int originalHash, int subtractWith)
{
	return ASCI_COUNT *(originalHash - subtractWith);
}

int addHash(int originalHash, int addWith)
{
	return originalHash + addWith;
}

int moduloHash(int originalHash, int moduloWith)
{
	int result = originalHash % moduloWith;
	if (result < 0)
		result = (result + moduloWith);
	return result;
}

void patternSearch(std::string txt, std::string pat, int q)
{	
	int hashing = getHashing(pat.size(), q);
	int patHash = createHashValue(pat, q);
	int txtHash = createHashValue(txt.substr(0, pat.size()), q);

	for (int i = 0; i <= txt.size() - pat.size(); i++)
	{
		if (patHash == txtHash && pat.compare(txt.substr(i, pat.size())) == 0)
			std::cout << "Pattern found at index " << i << std::endl;

		if (i < txt.size() - pat.size())
		{
			txtHash = subtractHash(txtHash, txt[i] * hashing);
			txtHash = addHash(txtHash, txt[i + pat.size()]);
			txtHash = moduloHash(txtHash, q);
		}
	}
}