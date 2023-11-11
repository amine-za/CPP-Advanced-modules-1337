#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

#define RED_TEXT "\033[31m"
#define BLUE_TEXT "\033[34m"
#define RESET_COLOR "\033[0m"

template <typename T>
void    easyfind(T tmplt, int i)
{
    if (find(tmplt.begin(), tmplt.end(), i) != tmplt.end())
        std::cout << "The integer " << i << " is found" << std::endl;
    else
        throw(std::invalid_argument("It seems that the integer that you entered don't exist in that int container"));
}

#endif