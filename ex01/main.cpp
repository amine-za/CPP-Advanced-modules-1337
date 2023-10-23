/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:43:53 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/23 17:54:49 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#define BLUE_TEXT "\033[34m"
#define RESET_TEXT "\033[0m"

int main()
{
    Form F1("F1", 43, 22);
    Bureaucrat B1(48, "B1");

    F1.beSigned(B1);
    std::cout << BLUE_TEXT << "Test 01 : " << RESET_TEXT;
    std::cout << "the form grade is higher than the bureau grade, so the boolean should be true and the form should be signed" << std::endl;
    std::cout << BLUE_TEXT << "Result 01 : " << RESET_TEXT;
    std::cout << "Form signed boolean = " << F1.GetSignBoolean() << "   |   ";
    B1.signForm(F1);

//------------------------------------------------------------------------------------------------------------------------------//

    Form F2("F2", 49, 22);
    Bureaucrat B2(48, "B2");
    F2.beSigned(B2);
    std::cout << BLUE_TEXT << "\nTest 02 : " << RESET_TEXT;
    std::cout << "the form grade is lower than the bureau grade, so the boolean should be false and the form should not be signed" << std::endl;
    std::cout << BLUE_TEXT << "Result 02 : " << RESET_TEXT;
    std::cout << "Form signed boolean = " << F2.GetSignBoolean() << "   |   ";
    B2.signForm(F2);

//------------------------------------------------------------------------------------------------------------------------------//

    std::cout << BLUE_TEXT << "\nTest 03 : " << RESET_TEXT;
    std::cout << "printing F2 form and B2 bureaucrat with the overload of the insertion '<<' " << std::endl;
    std::cout << BLUE_TEXT << "Result 03 : " << RESET_TEXT << std::endl;
    std::cout << F2 << std::endl;
    std::cout << B2 << std::endl;

//------------------------------------------------------------------------------------------------------------------------------//
    std::cout << BLUE_TEXT << "\nTest 04 : " << RESET_TEXT;
    std::cout << "testing throws in form class" << std::endl;
    std::cout << BLUE_TEXT << "Result 04 : " << RESET_TEXT << std::endl;
    try
    {
        Form F2("F2", -42, 22);
    }
    catch(const Form::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Form F2("F2", 150, 151);
    }
    catch(const Form::GradeTooHighException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const Form::GradeTooLowException& e)
    {
        std::cerr << e.what() << '\n';
    }

    
}

// int main()
// {
//     Bureaucrat B(48, "numnum");

//     //---------------Grade higher test---------------
//     std::cout << "\n                  TEST 01\n";
//     try
//     {
//         Bureaucrat B1(4869, "test");
//     }
//     catch (Bureaucrat::GradeTooHighException &e)
//     {
//         std::cerr << e.what() << std::endl;
//     }
//     catch (Bureaucrat::GradeTooLowException &e)
//     {
//         std::cerr << e.what() << std::endl;
//     }

//     //---------------Grade lower test---------------
//     std::cout << "\n                  TEST 02\n";
//     try
//     {
//         Bureaucrat B2(0, "test");
//     }
//     catch (Bureaucrat::GradeTooHighException &e)
//     {
//         std::cerr << e.what() << std::endl;
//     }
//     catch (Bureaucrat::GradeTooLowException &e)
//     {
//         std::cerr << e.what() << std::endl;
//     }
    
//     //---------------Grade in range test---------------
//     std::cout << "\n                  TEST 03\n";
//     try
//     {
//         Bureaucrat B2(14, "test");
//     }    
//     catch (Bureaucrat::GradeTooHighException &e)
//     {
//         std::cerr << e.what() << std::endl;
//     }
//     catch (Bureaucrat::GradeTooLowException &e)
//     {
//         std::cerr << e.what() << std::endl;
//     }
    
//     //---------------IncrementGrade function test---------------
//     std::cout << "\n                  TEST 04\n";
//     std::cout << "Grade before increment : " << B.getGrade() << std::endl;
//     B.IncrementGrade();
//     std::cout << "Grade after increment  : " << B.getGrade() << std::endl;

//     //---------------DecrementGrade function test---------------
//     std::cout << "\n                  TEST 05\n";
//     std::cout << "Grade before decrement : " << B.getGrade() << std::endl;
//     B.DecrementGrade();
//     std::cout << "Grade after decrement  : " << B.getGrade() << std::endl;


//     //---------------operator << test---------------
//     std::cout << "\n                  TEST 06\n";
//     std::cout << B << std::endl;
//     return 0;
// }
