#ifndef __COMMON_H__
#define __COMMON_H__

#include <vector>

#define L_FACTOR (1<<10)

struct task
{
	double execute;
	double period;
	double quality;
};

bool sort_execute(const struct task &i, const struct task &j);
bool sort_period(const struct task &i, const struct task &j);
bool sort_quality(const struct task &i, const struct task &j);
bool sort_utilization(const struct task &i, const struct task &j);

bool is_schedulable(const std::vector<struct task> task_list);


#endif
