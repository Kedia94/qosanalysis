#include <algorithm>
#include <cassert>
#include <iostream>

#include "common.h"

bool sort_execute(const struct task &i, const struct task &j)
{
	return i.execute < j.execute;
}
bool sort_period(const struct task &i, const struct task &j)
{
	return i.period < j.period;
}
bool sort_quality(const struct task &i, const struct task &j)
{
    return i.quality < j.quality;
}

bool sort_utilization(const struct task &i, const struct task &j)
{
    return i.execute/i.period < j.execute/j.period;
}

bool is_schedulable(const std::vector<struct task> task_list)
{
	std::vector<struct task> tasks = task_list;


	double sum_util = 0;
	for (int i=0; i<tasks.size(); i++)
	{
		sum_util += tasks[i].execute / tasks[i].period;
	}
	if (sum_util >= 1)
		return false;

	int i= tasks.size()-1;

	for (int L = tasks[0].period+1; L < tasks[i].period; L++)
	{

		long right = tasks[i].execute;
		for (int j=0; j<i; j++)
		{
			right += (long)((L-1)/tasks[j].period) * tasks[j].execute;
		}
		if (L < right)
			return false;
	}

	return true;
}
