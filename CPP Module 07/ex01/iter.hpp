#ifndef ITER_HPP
#define ITER_HPP

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