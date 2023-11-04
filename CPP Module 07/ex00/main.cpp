/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:32:47 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/03 15:22:28 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.hpp"

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

int main()
{
    int a = 2;
    int b = 3;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    return 0;
}