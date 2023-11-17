/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:41:53 by azaghlou          #+#    #+#             */
/*   Updated: 2023/11/14 22:19:32 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    int array[] = {1, 2, 1412, 4, 4869};
    std::vector<int> additionalNumbers(array, array + 5);
    std::cout << "before: " << std::endl;
    sp.print_container();
    sp.addRange(additionalNumbers.begin(), additionalNumbers.end());
    std::cout << "after: " <<  std::endl;
    sp.print_container();
    return 0;
}