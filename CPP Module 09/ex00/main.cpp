/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:39:06 by azaghlou          #+#    #+#             */
/*   Updated: 2023/12/07 21:38:53 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// #include <iostream>

// int main() {
//     // Representing a null-like value for a float
//     float myValue = std::numeric_limits<float>::quiet_NaN();

//     // Check if the value is NaN
//     if (std::isnan(myValue))
//         std::cout << "The value is NaN." << std::endl;
//     else
//         std::cout << "The value is not NaN." << std::endl;
//     return 0;
// }

        // if (file_content[x][4] != '-' || file_content[x][7] != '-' 
        // || file_content[x][10] != ' ' || file_content[x][11] != '|' || file_content[x][12] != ' ')
        //     return (1);
        
            // if (!std::isdigit(file_content[x][y]) && file_content[x][y] != '-' && file_content[x][y] != '+'
            //         && file_content[x][y] != ' ' && file_content[x][y] != '|' && file_content[x][y] != '\n')
            //     return (1);

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string input = av[1];
        std::map<std::string, float> Map;
        fill_the_container(&Map);
        // for(std::map<std::string, float>::iterator it = Map.begin(); it->first != "2017-03-18" && it != Map.end(); it++)
        // {
        //     if (it->second != 0)
        //     {
        //         std::cout << "first : " << it->first << " second : " << it->second << std::endl;
        //         break;
        //     }
        // }
        
        // // std::cout << "0 : " << Map["2010-08-17"] << "   |    1 : " << Map["2012-07-10"] << std::endl;
        DoTheRealWork(Map, input);
    }
    else
        std::cerr << "Error: could not open file.\n";
}
