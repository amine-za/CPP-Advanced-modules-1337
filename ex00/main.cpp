/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:41:32 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/25 12:55:15 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat B(48, "numnum");

    //---------------Grade higher test---------------
    std::cout << "\n                  TEST 01\n";
    try
    {
        Bureaucrat B1(4869, "test");
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    //---------------Grade lower test---------------
    std::cout << "\n                  TEST 02\n";
    try
    {
        Bureaucrat B2(0, "test");
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    //---------------Grade in range test---------------
    std::cout << "\n                  TEST 03\n";
    try
    {
        Bureaucrat B2(14, "test");
    }    
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    //---------------IncrementGrade function test---------------
    std::cout << "\n                  TEST 04\n";
    std::cout << "Grade before increment : " << B.getGrade() << std::endl;
    B.IncrementGrade();
    std::cout << "Grade after increment  : " << B.getGrade() << std::endl;

    //---------------DecrementGrade function test---------------
    std::cout << "\n                  TEST 05\n";
    std::cout << "Grade before decrement : " << B.getGrade() << std::endl;
    B.DecrementGrade();
    std::cout << "Grade after decrement  : " << B.getGrade() << std::endl;


    //---------------operator << test---------------
    std::cout << "\n                  TEST 06\n";
    std::cout << B << std::endl;
    return 0;
}
