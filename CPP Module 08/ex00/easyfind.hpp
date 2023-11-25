#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

#define RED_TEXT "\033[31m"
#define BLUE_TEXT "\033[34m"
#define RESET_COLOR "\033[0m"

template <typename T>
void    easyfind(T tmplt, int i)
{
    if (find(tmplt.begin(), tmplt.end(), i) != tmplt.end())
        std::cout << "The element " << i << " is found" << std::endl;
    else
        throw(std::invalid_argument("It seems that the element you entered don't exist in the container"));
}

#endif