/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:39:06 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/28 11:59:43 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// #include <iostream>

// int main() {
//     // Representing a null-like value for a double
//     double myValue = std::numeric_limits<double>::quiet_NaN();

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
        std::map<std::string, double> Map = completeTask(av[1]);
        // while(1);
        system("leaks btc");
    }
    else
        std::cerr << "Error: could not open file.\n";
}
