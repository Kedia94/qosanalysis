#include <iostream>
#include <vector>
#include <algorithm>

#include "config.h"
#include "common.h"
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

    std::stable_sort(task1.begin(), task1.end(), sort_quality);
    std::stable_sort(task2.begin(), task2.end(), sort_quality);
    std::stable_sort(task3.begin(), task3.end(), sort_quality);
    std::stable_sort(task4.begin(), task4.end(), sort_quality);
    std::stable_sort(task5.begin(), task5.end(), sort_quality);
    std::stable_sort(task6.begin(), task6.end(), sort_quality);
    std::stable_sort(task7.begin(), task7.end(), sort_quality);
    std::stable_sort(task8.begin(), task8.end(), sort_quality);
    std::stable_sort(task9.begin(), task9.end(), sort_quality);

	double maxQ = -1;

	for (int i0=0; i0<task0.size(); i0++)
	{
		for (int i1=0; i1<task1.size(); i1++)
		{
			for (int i2=0; i2<task2.size(); i2++)
			{
				for (int i3=0; i3<task3.size(); i3++)
				{
					for (int i4=0; i4<task4.size(); i4++)
					{
						for (int i5=0; i5<task5.size(); i5++)
						{
							for (int i6=0; i6<task6.size(); i6++)
							{
								for (int i7=0; i7<task7.size(); i7++)
								{
									for (int i8=0; i8<task8.size(); i8++)
									{
										for (int i9=0; i9<task9.size(); i9++)
										{
											std::cout<<i0<<" "<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<i5<<" "<<i6<<" "<<i7<<" "<<i8<<" "<<i9<<" "<<std::endl;
											std::vector<struct task> temp_task_set;
											temp_task_set.push_back(task0[i0]);
											temp_task_set.push_back(task1[i1]);
											temp_task_set.push_back(task2[i2]);
											temp_task_set.push_back(task3[i3]);
											temp_task_set.push_back(task4[i4]);
											temp_task_set.push_back(task5[i5]);
											temp_task_set.push_back(task6[i6]);
											temp_task_set.push_back(task7[i7]);
											temp_task_set.push_back(task8[i8]);
											temp_task_set.push_back(task9[i9]);

											if (is_schedulable(temp_task_set))
											{
												double soq = 0;
												soq += task0[i0].quality;
												soq += task1[i1].quality;
												soq += task2[i2].quality;
												soq += task3[i3].quality;
												soq += task4[i4].quality;
												soq += task5[i5].quality;
												soq += task6[i6].quality;
												soq += task7[i7].quality;
												soq += task8[i8].quality;
												soq += task9[i9].quality;

												if (maxQ < soq)
													maxQ = soq;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	std::cout<<"Exhaustive: "<<maxQ<<std::endl;

	return 0;
}
