/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:43:55 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/31 15:35:13 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Static.hpp"
#include <cfloat>

int main(int ac, char **av)
{
    Static S;

    if (ac == 2)
        S.convert(av[1]);

    // Static Cast  
    // reinterpret cast  
    // dynamic cast   
    // const cast
}
