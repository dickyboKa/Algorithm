#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

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
