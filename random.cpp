#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "common.h"
#include "config.h"
#include "file.h"

bool is_schedule(const std::vector<struct task> task_list);
double get_gap(const std::vector<struct task> task_list, int i);

int main()
{
	std::srand(std::time(nullptr));
	std::vector<struct task> task0 = readFile(TASK0);
	std::vector<struct task> task1 = readFile(TASK1);
	std::vector<struct task> task2 = readFile(TASK2);
	std::vector<struct task> task3 = readFile(TASK3);
	std::vector<struct task> task4 = readFile(TASK4);
	std::vector<struct task> task5 = readFile(TASK5);
	std::vector<struct task> task6 = readFile(TASK6);
	std::vector<struct task> task7 = readFile(TASK7);
	std::vector<struct task> task8 = readFile(TASK8);
	std::vector<struct task> task9 = readFile(TASK9);
	/*
	std::vector<struct task> task0 = readFile(CON(TASK0));
	std::vector<struct task> task1 = readFile(CON(TASK1));
	std::vector<struct task> task2 = readFile(CON(TASK2));
	std::vector<struct task> task3 = readFile(CON(TASK3));
	std::vector<struct task> task4 = readFile(CON(TASK4));
	std::vector<struct task> task5 = readFile(CON(TASK5));
	std::vector<struct task> task6 = readFile(CON(TASK6));
	std::vector<struct task> task7 = readFile(CON(TASK7));
	std::vector<struct task> task8 = readFile(CON(TASK8));
	std::vector<struct task> task9 = readFile(CON(TASK9));
	*/

	std::stable_sort(task0.begin(), task0.end(), sort_utilization);
	std::stable_sort(task1.begin(), task1.end(), sort_utilization);
	std::stable_sort(task2.begin(), task2.end(), sort_utilization);
	std::stable_sort(task3.begin(), task3.end(), sort_utilization);
	std::stable_sort(task4.begin(), task4.end(), sort_utilization);
	std::stable_sort(task5.begin(), task5.end(), sort_utilization);
	std::stable_sort(task6.begin(), task6.end(), sort_utilization);
	std::stable_sort(task7.begin(), task7.end(), sort_utilization);
	std::stable_sort(task8.begin(), task8.end(), sort_utilization);
	std::stable_sort(task9.begin(), task9.end(), sort_utilization);

	for (int j=0; j<10; j++)
	{
		int i0=std::rand() % task0.size();
		int i1=std::rand() % task1.size();
		int i2=std::rand() % task2.size();
		int i3=std::rand() % task3.size();
		int i4=std::rand() % task4.size();
		int i5=std::rand() % task5.size();
		int i6=std::rand() % task6.size();
		int i7=std::rand() % task7.size();
		int i8=std::rand() % task8.size();
		int i9=std::rand() % task9.size();

		std::vector<struct task> task_list;
		task_list.push_back(task0[i0]);
		task_list.push_back(task1[i1]);
		task_list.push_back(task2[i2]);
		task_list.push_back(task3[i3]);
		task_list.push_back(task4[i4]);
		task_list.push_back(task5[i5]);
		task_list.push_back(task6[i6]);
		task_list.push_back(task7[i7]);
		task_list.push_back(task8[i8]);
		task_list.push_back(task9[i9]);

		double gap;
		while(!is_schedulable(task_list)){
			task_list.clear();

			i0=std::rand() % task0.size();
			i1=std::rand() % task1.size();
			i2=std::rand() % task2.size();
			i3=std::rand() % task3.size();
			i4=std::rand() % task4.size();
			i5=std::rand() % task5.size();
			i6=std::rand() % task6.size();
			i7=std::rand() % task7.size();
			i8=std::rand() % task8.size();
			i9=std::rand() % task9.size();

			task_list.push_back(task0[i0]);
			task_list.push_back(task1[i1]);
			task_list.push_back(task2[i2]);
			task_list.push_back(task3[i3]);
			task_list.push_back(task4[i4]);
			task_list.push_back(task5[i5]);
			task_list.push_back(task6[i6]);
			task_list.push_back(task7[i7]);
			task_list.push_back(task8[i8]);
			task_list.push_back(task9[i9]);
		}


		double result = 0;
		result += task0[i0].quality;
		result += task1[i1].quality;
		result += task2[i2].quality;
		result += task3[i3].quality;
		result += task4[i4].quality;
		result += task5[i5].quality;
		result += task6[i6].quality;
		result += task7[i7].quality;
		result += task8[i8].quality;
		result += task9[i9].quality;

		std::cout<<i0<<" "<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<i5<<" "<<i6<<" "<<i7<<" "<<i8<<" "<<i9<<std::endl;
		std::cout<<"Random: "<<result<<std::endl;
	}
	return 0;
}


bool is_schedule(const std::vector<struct task> task_list)
{
	std::vector<struct task> tasks = task_list;
	std::stable_sort(tasks.begin(), tasks.end(), sort_period);

	std::vector<struct task> tass;

	for (int i=0; i<tasks.size(); i++)
	{
		tass.push_back(tasks[i]);
		if (!is_schedulable(tass))
			return false;
	}
	return true;
}

double get_gap(const std::vector<struct task> task_list, int i)
{
	if (i+1 >= task_list.size())
		return -1;

	return (task_list[i+1].quality - task_list[i].quality)/(task_list[i+1].execute/task_list[i+1].period - task_list[i].execute/task_list[i].period);
}
