#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <assert.h>

struct Job
{
	char id;
	int deadLine;
	int profit;
};

class SlotSet
{
public:
	SlotSet(int n)
	{
		for (int i = 0; i <= n; i++)
			parent.push_back(i);
	}

	int findAvailableSlot(int s)
	{
		if (s == parent[s])
			return s;
		return parent[s] = findAvailableSlot(parent[s]);
	}

	void saveForNextSlot(int u, int v)
	{
		parent[v] = u;
	}
private:	
	std::vector<int> parent;
};

bool byProfit(Job a, Job b)
{
	return a.profit > b.profit;
}

bool byDeadLineAscending(Job a, Job b)
{
	return a.deadLine < b.deadLine;
}
int findMaxDeadline(std::vector<Job> &jobs)
{
	int result = std::numeric_limits<int>::min();
	for(auto it = jobs.cbegin(); it != jobs.cend(); ++it)
		result = std::max(result, it->deadLine);
	return result;
}

void printJobScheduling(std::vector<Job> jobs)
{

	std::sort(jobs.begin(), jobs.end(), byProfit);
	SlotSet slotSet(findMaxDeadline(jobs));
	std::vector<Job> result;
	for (auto it = jobs.cbegin(); it != jobs.cend(); ++it)
	{
		int availableSlot = slotSet.findAvailableSlot(it->deadLine);
		if (availableSlot > 0)
		{
			result.push_back(*it);
			slotSet.saveForNextSlot(slotSet.findAvailableSlot(availableSlot - 1), availableSlot);
		}
	}

	std::sort(result.begin(), result.end(), byDeadLineAscending);
	for (auto it = result.cbegin(); it != result.cend(); ++it)
	{
		std::cout << it->id << " ";
	}

}


// lost minimization

// each job consist of index, and pair of loss, and timeToFinish
typedef std::pair<int, std::pair<int, int> > job;

bool sortByRatioOFLossAndTimeToFinish(job a, job b)
{
	int a_loss, a_time, b_loss, b_time;
	a_loss = a.second.first;
	a_time = a.second.second;
	b_loss = b.second.first;
	b_time = b.second.second;
	return (a_loss * b_time) > (a_time * b_loss);
}


void printJobSchedulingWithMinimumLoss(std::vector<int> loss, std::vector<int> timeToFinish)
{
	std::vector<job> jobs;
	assert(loss.size() == timeToFinish.size());

	for (int i = 0; i < loss.size(); ++i)
	{
		int ls = loss[i];
		int finishTime = timeToFinish[i];
		jobs.push_back(std::make_pair(i + 1, std::make_pair(ls, finishTime)));
	}

	std::stable_sort(jobs.begin(), jobs.end(), sortByRatioOFLossAndTimeToFinish);

	std::cout << "Job numbers in optimal sequence are\n";
	for (auto it = jobs.cbegin(); it != jobs.cend(); ++it)
	{
		std::cout << it->first << " ";
	}
}


// Job Selection Problem – Loss Minimization Strategy | Set 2

void optimumSequenceJob(std::vector<int> &jobs, double decayingPercentage)
{
	int fillIndex = 1;
	int arrSize = jobs.size() - 1;
	std::priority_queue<int, std::vector<int>, std::greater<int> > queueJobs;

	for (int i = 1; i <= arrSize; ++i)
	{
		queueJobs.push(jobs[i]);
	}

	while (!queueJobs.empty())
	{
		std::cout << queueJobs.top();

		jobs[fillIndex++] = queueJobs.top();
		queueJobs.pop();
	}

	double result = 0;
	for (int i = arrSize; i >= 1; --i)
	{
		result += pow((1 - decayingPercentage), arrSize - i) * jobs[i];
	}
	std::cout << std::endl << result;
}