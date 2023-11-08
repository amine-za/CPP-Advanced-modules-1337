/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:43:55 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/08 13:25:54 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Static.hpp"
#include <cfloat>

int main(int ac, char **av)
{   
    // char s[9] = "999999.5";
    if (ac == 2)
        Static::convert(av[1]);
    else if (ac == 1)
        std::cout << "It seems that you didn't entered an argument" << std::endl;
    else
        std::cout << "It seems that you entered more than one argument" << std::endl;
}
