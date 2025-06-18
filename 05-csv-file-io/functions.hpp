#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <utility>

void readOutputFile(const std::vector<std::pair<std::string, int>> &outputFile);
void writeInputFile(std::vector<std::pair<std::string, int>> inputFile, const int &usersQtd);
void writeFile(const int &usersQtd, const std::string &data);
void readFile(const std::string &data);
#endif