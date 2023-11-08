#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
T min(T a, T b)
{
    if (b < a)
        return b;
    else if (b > a)
        return a;
    else
        return b;
}

template <typename T>
T max(T a, T b)
{
    if (a > b)
        return a;
    else if (a < b)
        return b;
    else
        return b;
}

#endif