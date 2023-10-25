/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:38:36 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/25 10:31:56 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    //                                                      Test 01
    {
        std::cout << "------------------Test 01 : Can sign all the forms------------------" << std::endl;
        Bureaucrat  bureau(5, "Bureau");
        PresidentialPardonForm pres("pres");
        ShrubberyCreationForm shrub("shrub");
        RobotomyRequestForm robot("robot");

        pres.beSigned(bureau);
        shrub.beSigned(bureau);
        robot.beSigned(bureau);
        
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the presidentialPardonForm" << RESET_TEXT << std::endl;
        bureau.executeForm(pres);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the ShrubberyCreationForm" << RESET_TEXT << std::endl;
        bureau.executeForm(shrub);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the RobotomyRequestForm" << RESET_TEXT << std::endl;
        bureau.executeForm(robot);
    }
    
    //                                                      Test 02
    {
        std::cout << "\n\n--Test 02 : Can sign only the ShrubberyCreationForm and the RobotomyRequestForm forms--" << std::endl;
        Bureaucrat  bureau(50, "Bureau");

        PresidentialPardonForm pres("pres");
        ShrubberyCreationForm shrub("shrub");
        RobotomyRequestForm robot("robot");

        pres.beSigned(bureau);
        shrub.beSigned(bureau);
        robot.beSigned(bureau);

        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the presidentialPardonForm" << RESET_TEXT << std::endl;
        bureau.executeForm(pres);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the ShrubberyCreationForm" << RESET_TEXT << std::endl;
        bureau.executeForm(shrub);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the RobotomyRequestForm" << RESET_TEXT << std::endl;
        bureau.executeForm(robot);
    }
    
    //                                                      Test 03
    {
        std::cout << "\n\n----------------Test 03 : Can sign only the ShrubberyCreationForm form----------------" << std::endl;
        Bureaucrat  bureau(130, "Bureau");
        PresidentialPardonForm pres("pres");
        ShrubberyCreationForm shrub("shrub");
        RobotomyRequestForm robot("robot");

        pres.beSigned(bureau);
        shrub.beSigned(bureau);
        robot.beSigned(bureau);

        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the presidentialPardonForm" << RESET_TEXT << std::endl;
        bureau.executeForm(pres);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the ShrubberyCreationForm" << RESET_TEXT << std::endl;
        bureau.executeForm(shrub);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the RobotomyRequestForm" << RESET_TEXT << std::endl;
        bureau.executeForm(robot);
    }
    
    //                                                      Test 04
    {
        std::cout << "\n\n------------------Test 04 : Can't sign any form------------------" << std::endl;
        Bureaucrat  bureau(147, "Bureau");
        PresidentialPardonForm pres("pres");
        ShrubberyCreationForm shrub("shrub");
        RobotomyRequestForm robot("robot");

        pres.beSigned(bureau);
        shrub.beSigned(bureau);
        robot.beSigned(bureau);

        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the presidentialPardonForm" << RESET_TEXT << std::endl;
        bureau.executeForm(pres);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the ShrubberyCreationForm" << RESET_TEXT << std::endl;
        bureau.executeForm(shrub);
        std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the RobotomyRequestForm" << RESET_TEXT << std::endl;
        bureau.executeForm(robot);
    }
}
