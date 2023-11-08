/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:22:34 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/06 08:26:02 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <vector>



int main()
{
    int int_array[3] = {10, 20, 30};
    std::string str_array[5] = {"first", "second", "third", "fourth", "fifth"};
    float float_array[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    
    iter<int *, void (*)(int)>(int_array, 3, ::print_template<int>);
    std::cout << std::endl;
    iter<std::string *, void (*)(std::string)>(str_array, 3, ::print_template<std::string>);
    std::cout << std::endl;
    iter<float *, void (*)(float)>(float_array, 3, ::print_template<float>);
    return 0;
}
