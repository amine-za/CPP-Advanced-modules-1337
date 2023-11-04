/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:22:34 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/03 22:58:41 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void    print_string(std::string str)
{
    std::cout << str << std::endl;
}

int main()
{
    std::string array[6] = {"first", "second", "third", "fourth", "fifth", "sixth"};
    iter(&array, 6, print_string(array[0]));
    return 0;
}