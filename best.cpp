#include <iostream>
#include <vector>
#include <algorithm>

#include "config.h"
#include "file.h"

int main()
{

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

	std::stable_sort(task0.begin(), task0.end(), sort_quality);
	std::stable_sort(task1.begin(), task1.end(), sort_quality);
	std::stable_sort(task2.begin(), task2.end(), sort_quality);
	std::stable_sort(task3.begin(), task3.end(), sort_quality);
	std::stable_sort(task4.begin(), task4.end(), sort_quality);
	std::stable_sort(task5.begin(), task5.end(), sort_quality);
	std::stable_sort(task6.begin(), task6.end(), sort_quality);
	std::stable_sort(task7.begin(), task7.end(), sort_quality);
	std::stable_sort(task8.begin(), task8.end(), sort_quality);
	std::stable_sort(task9.begin(), task9.end(), sort_quality);

	double quality = 0;

	quality += task0[task0.size()-1].quality;
	quality += task1[task1.size()-1].quality;
	quality += task2[task2.size()-1].quality;
	quality += task3[task3.size()-1].quality;
	quality += task4[task4.size()-1].quality;
	quality += task5[task5.size()-1].quality;
	quality += task6[task6.size()-1].quality;
	quality += task7[task7.size()-1].quality;
	quality += task8[task8.size()-1].quality;
	quality += task9[task9.size()-1].quality;

	std::cout<<"Best: "<<quality<<std::endl;
	return 0;
}
