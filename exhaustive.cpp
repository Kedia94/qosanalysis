#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#include "config.h"
#include "common.h"
#include "file.h"

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
/*    std::vector<struct task> task1 = readFile(TASK1);
    std::vector<struct task> task2 = readFile(TASK2);
    std::vector<struct task> task3 = readFile(TASK3);
    std::vector<struct task> task4 = readFile(TASK4);
    std::vector<struct task> task5 = readFile(TASK5);
    std::vector<struct task> task6 = readFile(TASK6);
    std::vector<struct task> task7 = readFile(TASK7);
    std::vector<struct task> task8 = readFile(TASK8);
    std::vector<struct task> task9 = readFile(TASK9);
*/
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
		printf("%d / %d\n", i0, task0.size());
		std::vector<struct task> temp_task_set;
		temp_task_set.push_back(task0[i0]);
		assert(temp_task_set.size() == 1);

		if (!is_schedulable(temp_task_set))
			continue;
		for (int i1=0; i1<task1.size(); i1++)
		{
		printf("\t%d / %d\n", i1, task1.size());
			while (temp_task_set.size() != 1)
				temp_task_set.pop_back();
			temp_task_set.push_back(task1[i1]);
			assert(temp_task_set.size() == 2);

			if (!is_schedulable(temp_task_set))
				continue;
			for (int i2=0; i2<task2.size(); i2++)
			{
		printf("\t\t%d / %d\n", i2, task2.size());
				while (temp_task_set.size() != 2)
					temp_task_set.pop_back();
				temp_task_set.push_back(task2[i2]);
				assert(temp_task_set.size() == 3);

				if (!is_schedulable(temp_task_set))
					continue;
				for (int i3=0; i3<task3.size(); i3++)
				{
		printf("\t\t\t%d / %d\n", i3, task3.size());
					while (temp_task_set.size() != 3)
						temp_task_set.pop_back();
					temp_task_set.push_back(task3[i3]);
					assert(temp_task_set.size() == 4);

					if (!is_schedulable(temp_task_set))
						continue;
					for (int i4=0; i4<task4.size(); i4++)
					{
		printf("\t\t\t\t%d / %d\n", i4, task4.size());
						while (temp_task_set.size() != 4)
							temp_task_set.pop_back();
						temp_task_set.push_back(task4[i4]);
						assert(temp_task_set.size() == 5);

						if (!is_schedulable(temp_task_set))
							continue;
						for (int i5=0; i5<task5.size(); i5++)
						{
		printf("\t\t\t\t\t%d / %d\n", i5, task5.size());
							while (temp_task_set.size() != 5)
								temp_task_set.pop_back();
							temp_task_set.push_back(task5[i5]);
							assert(temp_task_set.size() == 6);

							if (!is_schedulable(temp_task_set))
								continue;
							for (int i6=0; i6<task6.size(); i6++)
							{
								while (temp_task_set.size() != 6)
									temp_task_set.pop_back();
								temp_task_set.push_back(task6[i6]);
								assert(temp_task_set.size() == 7);

								if (!is_schedulable(temp_task_set))
									continue;
								for (int i7=0; i7<task7.size(); i7++)
								{
									while (temp_task_set.size() != 7)
										temp_task_set.pop_back();
									temp_task_set.push_back(task7[i7]);
									assert(temp_task_set.size() == 8);

									if (!is_schedulable(temp_task_set))
										continue;
									for (int i8=0; i8<task8.size(); i8++)
									{
										while (temp_task_set.size() != 8)
											temp_task_set.pop_back();
										temp_task_set.push_back(task8[i8]);
										assert(temp_task_set.size() == 9);

										if (!is_schedulable(temp_task_set))
											continue;
										for (int i9=0; i9<task9.size(); i9++)
										{
											while (temp_task_set.size() != 9)
												temp_task_set.pop_back();
											temp_task_set.push_back(task9[i9]);
											assert(temp_task_set.size() == 10);

											if (!is_schedulable(temp_task_set))
												continue;

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
	std::cout<<"Exhaustive: "<<maxQ<<std::endl;

	return 0;
}
