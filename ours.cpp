#include <iostream>
#include <vector>
#include <algorithm>

#include "common.h"
#include "config.h"
#include "file.h"

bool is_schedule(const std::vector<struct task> task_list);
double get_gap(const std::vector<struct task> task_list, int i);

int main()
{
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

	int i0=0;
	int i1=0;
	int i2=0;
	int i3=0;
	int i4=0;
	int i5=0;
	int i6=0;
	int i7=0;
	int i8=0;
	int i9=0;

	int p0=0;
	int p1=0;
	int p2=0;
	int p3=0;
	int p4=0;
	int p5=0;
	int p6=0;
	int p7=0;
	int p8=0;
	int p9=0;

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
	while(is_schedulable(task_list)){
		task_list.clear();

		p0=i0;
		p1=i1;
		p2=i2;
		p3=i3;
		p4=i4;
		p5=i5;
		p6=i6;
		p7=i7;
		p8=i8;
		p9=i9;
		
		int num = -1;
		double max = -1;

		gap = get_gap(task0, i0);
		if (gap > max)
		{
			max = gap;
			num = 0;
		}
		gap = get_gap(task1, i1);
		if (gap > max)
		{
			max = gap;
			num = 1;
		}
		gap = get_gap(task2, i2);
		if (gap > max)
		{
			max = gap;
			num = 2;
		}
		gap = get_gap(task3, i3);
		if (gap > max)
		{
			max = gap;
			num = 3;
		}
		gap = get_gap(task4, i4);
		if (gap > max)
		{
			max = gap;
			num = 4;
		}
		gap = get_gap(task5, i5);
		if (gap > max)
		{
			max = gap;
			num = 5;
		}
		gap = get_gap(task6, i6);
		if (gap > max)
		{
			max = gap;
			num = 6;
		}
		gap = get_gap(task7, i7);
		if (gap > max)
		{
			max = gap;
			num = 7;
		}
		gap = get_gap(task8, i8);
		if (gap > max)
		{
			max = gap;
			num = 8;
		}
		gap = get_gap(task9, i9);
		if (gap > max)
		{
			max = gap;
			num = 9;
		}

		switch (num)
		{
			case 0: i0++; break; 
			case 1: i1++; break; 
			case 2: i2++; break; 
			case 3: i3++; break; 
			case 4: i4++; break; 
			case 5: i5++; break; 
			case 6: i6++; break; 
			case 7: i7++; break; 
			case 8: i8++; break; 
			case 9: i9++; break; 
		}

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
	result += task0[p0].quality;
	result += task1[p1].quality;
	result += task2[p2].quality;
	result += task3[p3].quality;
	result += task4[p4].quality;
	result += task5[p5].quality;
	result += task6[p6].quality;
	result += task7[p7].quality;
	result += task8[p8].quality;
	result += task9[p9].quality;

	double result2 = 0;
	result2 += task0[task0.size()-1].quality;
	result2 += task1[task1.size()-1].quality;
	result2 += task2[task2.size()-1].quality;
	result2 += task3[task3.size()-1].quality;
	result2 += task4[task4.size()-1].quality;
	result2 += task5[task5.size()-1].quality;
	result2 += task6[task6.size()-1].quality;
	result2 += task7[task7.size()-1].quality;
	result2 += task8[task8.size()-1].quality;
	result2 += task9[task9.size()-1].quality;

	double result1 = 0;
	result1 += task0[p0].execute / task0[p0].period;
	result1 += task1[p1].execute / task1[p1].period;
	result1 += task2[p2].execute / task2[p2].period;
	result1 += task3[p3].execute / task3[p3].period;
	result1 += task4[p4].execute / task4[p4].period;
	result1 += task5[p5].execute / task5[p5].period;
	result1 += task6[p6].execute / task6[p6].period;
	result1 += task7[p7].execute / task7[p7].period;
	result1 += task8[p8].execute / task8[p8].period;
	result1 += task9[p9].execute / task9[p9].period;

	std::cout<<"0: "<<task0[p0].quality <<" "<< task0[task0.size()-1].quality<<std::endl;
	std::cout<<"1: "<<task1[p1].quality <<" "<< task1[task1.size()-1].quality<<std::endl;
	std::cout<<"2: "<<task2[p2].quality <<" "<< task2[task2.size()-1].quality<<std::endl;
	std::cout<<"3: "<<task3[p3].quality <<" "<< task3[task3.size()-1].quality<<std::endl;
	std::cout<<"4: "<<task4[p4].quality <<" "<< task4[task4.size()-1].quality<<std::endl;
	std::cout<<"5: "<<task5[p5].quality <<" "<< task5[task5.size()-1].quality<<std::endl;
	std::cout<<"6: "<<task6[p6].quality <<" "<< task6[task6.size()-1].quality<<std::endl;
	std::cout<<"7: "<<task7[p7].quality <<" "<< task7[task7.size()-1].quality<<std::endl;
	std::cout<<"8: "<<task8[p8].quality <<" "<< task8[task8.size()-1].quality<<std::endl;
	std::cout<<"9: "<<task9[p9].quality <<" "<< task9[task9.size()-1].quality<<std::endl;
	std::cout<<"0: "<<task0[p0].quality - task0[task0.size()-1].quality<<std::endl;
	std::cout<<"1: "<<task1[p1].quality - task1[task1.size()-1].quality<<std::endl;
	std::cout<<"2: "<<task2[p2].quality - task2[task2.size()-1].quality<<std::endl;
    std::cout<<"3: "<<task3[p3].quality - task3[task3.size()-1].quality<<std::endl;
    std::cout<<"4: "<<task4[p4].quality - task4[task4.size()-1].quality<<std::endl;
    std::cout<<"5: "<<task5[p5].quality - task5[task5.size()-1].quality<<std::endl;
    std::cout<<"6: "<<task6[p6].quality - task6[task6.size()-1].quality<<std::endl;
    std::cout<<"7: "<<task7[p7].quality - task7[task7.size()-1].quality<<std::endl;
    std::cout<<"8: "<<task8[p8].quality - task8[task8.size()-1].quality<<std::endl;
    std::cout<<"9: "<<task9[p9].quality - task9[task9.size()-1].quality<<std::endl;

	std::cout<<p0<<" "<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<" "<<p5<<" "<<p6<<" "<<p7<<" "<<p8<<" "<<p9<<std::endl;
	std::cout<<"Ours: "<<result<<std::endl;
	std::cout<<"Best: "<<result2<<std::endl;
	std::cout<<"Util: "<<result1<<std::endl;

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
		double qual = 0;
		for (int j=0; j<tass.size();j++)
			qual += tass[j].execute/tass[j].period;
		if (qual > 1)
			std::cout<<"Over 1: "<<qual<<std::endl;
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
