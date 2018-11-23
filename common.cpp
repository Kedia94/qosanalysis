#include <algorithm>
#include <cassert>

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
	assert(task_list.size() == 10);
	std::vector<struct task> tasks = task_list;

	std::stable_sort(tasks.begin(), tasks.end(), sort_period);

	double sum_util = 0;
	for (int i=0; i<tasks.size(); i++)
	{
		sum_util += tasks[i].execute / tasks[i].period;
	}
	if (sum_util >= 1)
		return false;

	for (int i=0; i<tasks.size(); i++)
	{
		for (int L = tasks[0].period*L_FACTOR+1; L < tasks[i].period*L_FACTOR; L++)
		{
			long right = tasks[i].execute * L_FACTOR;
			for (int j=0; j<i; i++)
			{
				right += (long)((L-1)/tasks[j].period/L_FACTOR) * tasks[j].execute * L_FACTOR;
			}
			if (L < right)
				return false;
		}
	}

	return true;
}
