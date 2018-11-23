#include <iostream>
#include <vector>
#include <algorithm>

#include "file.h"

int main()
{
	std::vector<struct task> task_list;
	task_list.push_back({0.1, 0.2, 0.3});
	task_list.push_back({0.1, 0.5, 0.5});
	task_list.push_back({0.1, 0.4, 0.3});
	task_list.push_back({0.1, 0.5, 0.3});
	task_list.push_back({0.1, 0.6, 0.3});

	std::stable_sort(task_list.begin(), task_list.end(), sort_quality);

	for (int i=0; i<task_list.size(); i++)
		std::cout<<task_list[i].execute <<" "<<task_list[i].period<<" "<<task_list[i].quality<<std::endl;

	writeFile("1.txt", task_list);
	return 0;
}
