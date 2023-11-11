#ifndef ITER_HPP
#define ITER_HPP

#define RESET_TEXT "\033[0m"
#define BLUE_TEXT "\033[34m"
#define ORANGE_TEXT "\033[38;5;208m"

#include <iostream>

template <typename T, typename func>
void iter(T address, int length, func ft)
{
    for(int x = 0; x < length; x++)
        ft(address[x]);
}

// Example of an instantiated function template
template <typename X>
void print_template(X i)
{
    std::cout << "The template is: " << i << std::endl;
}


#endif