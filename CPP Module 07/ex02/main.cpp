/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:28:43 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/10 18:47:25 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
 //          I will create an array of number of arguments with different constructors in every test         //
//                     and print its size and try to point with an out of bounds index                      //

                                    /* Test 01 : With Default Constructor */
    {
        std::cout << BLUE_TEXT << "Test 01 : Just testing the size function and pointing into the argument with the index '0" << RESET_TEXT << std::endl;
        
        Array <int>Ar;
        std::cout << ORANGE_TEXT << "Size function test :  " << RESET_TEXT <<  "This array have " << Ar.size() << " arguments" << std::endl;
        try
        {
            Ar[0];
        }
        catch(std::out_of_range &e)
        {
            std::cout << ORANGE_TEXT << "index = 0 : " << RESET_TEXT  << e.what() << std::endl;
        }
    }
    
    
                                    /* Test 02 : With size taking Constructor */
    {
        std::cout << BLUE_TEXT << "\nTest 02 : An infinite loop with filling the arguments until an exception is thrown" << RESET_TEXT << std::endl;

        Array <std::string>Ar(5);
        int store = 0; // Just for storing the index that went out of bounds in the for loop
        try
        {
            for(int x = 0; ; x++)
            {
                store = x;
                Ar[x] = "triying";
            }
            std::cout << "no exception has been thrown\n"; // Thats impossible
        }
        catch(std::out_of_range &e)
        {
            std::cout << ORANGE_TEXT << "Index = " << store << " : " << RESET_TEXT << e.what() << std::endl;
            // std::cout << e.what() << std::endl;
        }
    }
}
