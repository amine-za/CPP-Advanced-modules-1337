#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <limits>
#include <ctime>


std::string    *add_arg_to_array(std::string *array, std::string arg);
int             form_check(std::string line);
std::string     get_date(std::string line);
float           get_value(std::string line, int flag);
void            fill_the_container(std::map<std::string, float> *Map);
void            print_result(std::string line, std::map<std::string, float> Map);
bool            leapTrueFalse(int year);
void            DoTheRealWork(std::map<std::string, float> Map, std::string input);

bool    valide_date( int *date, std::map<std::string, float> Map,  std::string line, bool &leap_year);
int    date_to_int_array(std::string line, int *date);
float   get_input_value(std::string line);

#endif