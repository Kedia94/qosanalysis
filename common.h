#ifndef __COMMON_H__
#define __COMMON_H__

struct task
{
	double execute;
	double period;
	double quality;
};

bool sort_quality(const struct task &i, const struct task &j);
bool sort_execute(const struct task &i, const struct task &j);


#endif
