#ifndef __FILE_H__
#define __FILE_H__

#include <fstream>
#include <vector>

#include "common.h"

std::vector<struct task> ReadFile(std::string filename);
void writeFile(std::string filename, std::vector<struct task>);

#endif
