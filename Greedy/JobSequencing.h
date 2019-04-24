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
