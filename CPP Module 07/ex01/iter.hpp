#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>

void    iter(T *address, int length, void (*fct)(T &ref))
{
    for(int x = 0; x < length; x++)
        fct(address[x]);
}

#endif