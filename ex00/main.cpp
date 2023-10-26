/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:41:32 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/26 12:11:36 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat B(48, "numnum");

    //---------------Grade higher test---------------
    std::cout << "\n                  TEST 01 : Grade higher\n";
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
    std::cout << "\n                  TEST 02 : Grade lower\n";
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
    std::cout << "\n                  TEST 03 : Grade in range\n";
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
    std::cout << "\n                  TEST 04 : IncrementGrade function\n";
    std::cout << "Grade before increment : " << B.getGrade() << std::endl;
    try
    {
        B.IncrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << "Grade after increment  : " << B.getGrade() << std::endl;

    //---------------DecrementGrade function test---------------
    std::cout << "\n                  TEST 05 : DecrementGrade function\n";
    std::cout << "Grade before decrement : " << B.getGrade() << std::endl;
    try
    {
        B.DecrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Grade after decrement  : " << B.getGrade() << std::endl;


    //---------------operator << test---------------
    std::cout << "\n                  TEST 06 : \"<<\" operator\n";
    std::cout << B << std::endl;
    return 0;
}
