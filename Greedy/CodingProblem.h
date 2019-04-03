#include <vector>
#include <algorithm>
#include <iostream>

// activities selection problem
std::vector<std::pair<int, int>> activitiesPairsStartFinish(std::vector<int> &start, std::vector<int> &finish)
{
	std::vector<std::pair<int, int>> activites;

	auto s = start.cbegin();
	auto f = finish.cbegin();
	while (s != start.cend())
	{
		activites.push_back(std::make_pair(*s, *f));
		++s;
		++f;
	}
	return activites;
}

void sortByFinishTime(std::vector<std::pair<int, int>> &activites)
{
	std::sort(activites.begin(), activites.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
		return a.second < b.second;
	});
}

void printMaxActivites(std::vector<int> &startTime, std::vector<int> &finishTime)
{
	std::vector<std::pair<int, int>> activites = activitiesPairsStartFinish(startTime, finishTime);
	sortByFinishTime(activites);
		
	auto print_it = activites.cbegin();
	std::cout << print_it->first << " / " << print_it->second << std::endl;

	// first = is start time, second = is finish time
	for (auto it = activites.cbegin() + 1; it != activites.cend(); ++it)
	{
		if (it->first > print_it->second)
		{
			print_it = it;
			std::cout << print_it->first << " / " << print_it->second << std::endl;
		}
	}
}


void printEgyptianFraction(int numerator, int denominator)
{
	if (numerator == 0 || denominator == 0)
		return;

	if (denominator % numerator == 0)
	{
		std::cout << "1/" << denominator / numerator;
		return;
	}

	if (numerator % denominator == 0)
	{
		std::cout << numerator / denominator;
		return;
	}

	// If numerator is more than denominator 
	if (numerator > denominator)
	{
		std::cout << numerator / denominator << " + ";
		printEgyptianFraction(numerator % denominator, denominator);
		return;
	}

	int denominatorOfUnitFraction = denominator / numerator + 1;
	std::cout << "1/" << denominatorOfUnitFraction << " + ";

	printEgyptianFraction(numerator*denominatorOfUnitFraction - denominator, denominator*denominatorOfUnitFraction);
}

struct Job
{
	char id;
	int deadLine;
	int profit;
};

bool byProfit(Job a, Job b)
{
	return a.profit > b.profit;
}

void printJobScheduling(std::vector<Job> jobs)
{
	int jobsCount = jobs.size();

	std::sort(jobs.begin(), jobs.end(), byProfit);

	std::vector<int> result(jobsCount);
	std::vector<bool> slot(jobsCount, false);

	for (int i = 0; i < jobsCount; ++i)
	{
		for (int j = std::min(jobsCount, jobs[i].deadLine) - 1; j >= 0; j--)
		{
			if (!slot[j])
			{
				result[j] = i;
				slot[j] = true;
				break;
			}
		}
	}

	for (int i = 0; i < jobsCount; i++)
	{
		if (slot[i])
			std::cout << jobs[result[i]].id << " ";
	}
}
