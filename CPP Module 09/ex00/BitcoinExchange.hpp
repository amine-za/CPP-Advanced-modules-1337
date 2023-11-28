#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <limits>
#include <ctime>

// i have to check the leaks when i use exit() function in that exersice

std::string    *add_arg_to_array(std::string *array, std::string arg);
int             count_lines(std::string *file_content);
int             form_check(std::string line);
int             *date_to_int_array(std::string line);
std::string     return_date(std::string line);
double          return_value(std::string line, int flag);
void            fill_the_container(std::map<std::string, double> *Map);
void            print_result(std::string line, std::map<std::string, double> Map);
bool            leapTrueFalse(int year);
void            DoTheRealWork(std::string *file_content, std::map<std::string, double> Map);
std::map<std::string, double> completeTask(char *input);


#endif