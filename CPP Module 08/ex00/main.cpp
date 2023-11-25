/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 07:41:26 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/24 19:44:02 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main()
{
    int arr[] = {10, 20, 5, 23, 42, 20, 10};
    std::vector<int> vect(arr, arr + 7);

//  Note : If an exception is thrown, i print its message in a red color
    std::cout << BLUE_TEXT << "Test 01 : " << RESET_COLOR;         //TEST 01 : should throw an exception
    try
    {
        easyfind(vect, 1337);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << RED_TEXT << e.what() << RESET_COLOR << std::endl;;
    }
    
    
    std::cout << BLUE_TEXT << "Test 02 : " << RESET_COLOR;         //TEST 02 : should work well
    try
    {
        easyfind(vect, 42);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << RED_TEXT << e.what() << RESET_COLOR << std::endl;;
    }
    
}
