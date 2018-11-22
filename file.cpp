#include <iostream>
#include "file.h"

std::vector<struct task> ReadFile(std::string filename)
{
	std::vector<struct task> task_list;


	return task_list;
}
void writeFile(std::string filename, std::vector<struct task> task_list)
{
	std::ofstream writeFile(filename);

	if (writeFile.is_open())
	{
		for (int i=0; i<task_list.size(); i++)
		{
			writeFile<<task_list[i].execute<<" "<<task_list[i].period<<" "<<task_list[i].quality<<std::endl;
		}
		writeFile.close();
	}
	else
	{
		std::cerr<<"[ERROR] Write file open: "<<filename<<std::endl;
	}
}

