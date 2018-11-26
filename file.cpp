#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

#include "common.h"
#include "file.h"

std::vector<struct task> readFile(std::string filename)
{
	std::vector<struct task> task_list;

	std::ifstream inFile(filename);

	if (inFile.is_open())
	{
		std::string line;
		while(getline(inFile, line)){
			if (line.length() == 0)
				continue;

			std::size_t sp0 = line.find(' ');
			std::size_t sp1 = line.substr(sp0+1).find(' ');
//			std::cout<<"first: "<<line.substr(0, sp0)<<std::endl;
//			std::cout <<"second: "<<line.substr(sp0+1, sp1)<<std::endl;
//			std::cout <<"third: "<<line.substr(sp0+sp1+2)<<std::endl;

//			std::cout<<sp0<<" "<<sp1<<" "<<line.length()<<" "<<std::endl<<std::endl;

			double execute = std::stod(line.substr(0,sp0));
			double period = std::stod(line.substr(sp0+1, sp1));
			double quality = std::stod(line.substr(sp0+sp1+2));

			task_list.push_back({execute, period, quality});

		}

	}
	else
	{
		std::cerr<<"[ERROR] Write file open: "<<filename<<std::endl;
	}

	return task_list;
}

std::vector<struct task> readFileBig(std::string filename)
{
	std::vector<struct task> task_list;

	std::ifstream inFile(filename);

	if (inFile.is_open())
	{
		std::string line;
		while(getline(inFile, line)){
			if (line.length() == 0)
				continue;

			std::size_t sp0 = line.find(' ');
			std::size_t sp1 = line.substr(sp0+1).find(' ');
//			std::cout<<"first: "<<line.substr(0, sp0)<<std::endl;
//			std::cout <<"second: "<<line.substr(sp0+1, sp1)<<std::endl;
//			std::cout <<"third: "<<line.substr(sp0+sp1+2)<<std::endl;

//			std::cout<<sp0<<" "<<sp1<<" "<<line.length()<<" "<<std::endl<<std::endl;

			double execute = std::stod(line.substr(0,sp0))*L_FACTOR;
			double period = std::stod(line.substr(sp0+1, sp1))*L_FACTOR;
			double quality = std::stod(line.substr(sp0+sp1+2));

			task_list.push_back({execute, period, quality});

		}

	}
	else
	{
		std::cerr<<"[ERROR] Write file open: "<<filename<<std::endl;
	}

	return task_list;
}

void writeFile(std::string filename, std::vector<struct task> task_list)
{
	std::ofstream outFile(filename);

	if (outFile.is_open())
	{
		for (int i=0; i<task_list.size(); i++)
		{
			outFile<<task_list[i].execute<<" "<<task_list[i].period<<" "<<task_list[i].quality<<std::setprecision(16)<<std::endl;
		}
		outFile.close();
	}
	else
	{
		std::cerr<<"[ERROR] Write file open: "<<filename<<std::endl;
	}
}

