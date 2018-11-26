#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "common.h"
#include "config.h"
#include "file.h"

void process_file(std::string filename);
int get_max_grad(std::vector<struct task> tasklist, int target);

int main()
{
	process_file(TASK0);
	process_file(TASK1);
	process_file(TASK2);
	process_file(TASK3);
	process_file(TASK4);
	process_file(TASK5);
	process_file(TASK6);
	process_file(TASK7);
	process_file(TASK8);
	process_file(TASK9);
}

void process_file(std::string filename)
{
	std::vector<struct task> task_list = readFile(filename);

	std::stable_sort(task_list.begin(), task_list.end(), sort_utilization);

	std::vector<struct task> new_task_list;

	new_task_list.push_back(task_list[0]);

	int i=0;
	while((i=get_max_grad(task_list, i)) > 0)
	{
		new_task_list.push_back(task_list[i]);
		
	}
	writeFile(CON(filename), new_task_list);
}

int get_max_grad(std::vector<struct task> tasklist, int target)
{
	double utilization = tasklist[target].execute / tasklist[target].period;
	double quality = tasklist[target].quality;

	int iter = -1;
	double max_grad = -1;
	for (int i=target+1; i<tasklist.size(); i++)
	{
		double util_now = tasklist[i].execute/tasklist[i].period;

		if (util_now <= utilization)
			continue;

		double grad_now = (quality - tasklist[i].quality) / (utilization - util_now);
		if (grad_now < 0)
			continue;
		if (grad_now > max_grad)
		{
			iter = i;
			max_grad = grad_now;
		}
	}
	return iter;
}
