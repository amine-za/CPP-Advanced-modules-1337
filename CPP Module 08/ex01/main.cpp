/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:41:53 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/24 19:37:26 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    int var;
    Span sp(7);
    int array[] = {1, 2, 1412, 4, 4869};
    std::vector<int> additionalNumbers(array, array + 5); // used in addRange() function

//-----------------------------------addNumber()-----------------------------------
    try
    {
        sp.addNumber(1412);
        std::cout << "No exception has been thrown while using addNumber() function" << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << ORANGE_TEXT << "Exception : " << RESET_TEXT << e.what()  << '\n';
    }
    try
    {
        sp.addNumber(4869);
        std::cout << "No exception has been thrown while using addNumber() function" << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << ORANGE_TEXT << "Exception : " << RESET_TEXT << e.what()  << '\n';
    }

//-----------------------------------addRange()-----------------------------------
    try
    {
        sp.addRange(additionalNumbers.begin(), additionalNumbers.end());
        std::cout << "No exception has been thrown while using addRange() function" << std::endl;
    }
    catch(const std::overflow_error& e)
    {
        std::cerr << ORANGE_TEXT << "Exception : " << RESET_TEXT << e.what()  << '\n';
    }

    sp.print_container();
//-----------------------------------shortestSpan()-----------------------------------
    try
    {
        var = sp.shortestSpan();
        std::cout << "No exception has been thrown in shortestSpan(), and the result is : " << var << std::endl;
    }
    catch(const std::logic_error& e)
    {
        std::cerr << ORANGE_TEXT << "Exception : " << RESET_TEXT << e.what() << '\n';
    }

//-----------------------------------longestSpan()-----------------------------------
    try
    {
        var = sp.longestSpan();
        std::cout << "No exception has been thrown in longestSpan(), and the result is : " << var << std::endl;
    }
    catch(const std::logic_error& e)
    {
        std::cerr << ORANGE_TEXT << "Exception : " << RESET_TEXT << e.what()  << '\n';
    }
    return 0;
}

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }
