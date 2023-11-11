/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:22:34 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/10 18:54:57 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <vector>



int main()
{
    int int_array[3] = {10, 20, 30};
    std::string str_array[5] = {"first", "second", "third", "fourth", "fifth"};
    float float_array[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    
    std::cout << BLUE_TEXT << "Int array :" << RESET_TEXT << std::endl;
    iter<int *, void (*)(int)>(int_array, 3, ::print_template<int>); // int array

    std::cout << BLUE_TEXT << "\nString array :" << RESET_TEXT << std::endl;
    iter<std::string *, void (*)(std::string)>(str_array, 5, ::print_template<std::string>); // string array
    
    std::cout << BLUE_TEXT << "\nFloat array :" << RESET_TEXT << std::endl;
    iter<float *, void (*)(float)>(float_array, 7, ::print_template<float>); // float array
    return 0;
}
