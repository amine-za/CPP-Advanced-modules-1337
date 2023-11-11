/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 07:41:26 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/11 19:41:30 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    int arr[] = {10, 20, 5, 23, 42, 20, 10};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> vect(arr, &arr[n]);
    std::deque<int> dq(5, 0);
    
    dq.push_front(2);
    std::cout << BLUE_TEXT << "Test 01 : " << RESET_COLOR;         //TEST 01 : should throw an exception
    try
    {
        easyfind(dq, 1);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << RED_TEXT << e.what() << RESET_COLOR << std::endl;;
    }
    
    
    std::cout << BLUE_TEXT << "Test 02 : " << RESET_COLOR;         //TEST 02 : should work well
    try
    {
        easyfind(vect, 10);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << RED_TEXT << e.what() << RESET_COLOR << std::endl;;
    }
    
}

