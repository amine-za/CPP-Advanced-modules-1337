/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:30:01 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/26 19:17:08 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat bureau;
    Intern someRandomIntern;
    AForm* rrf;
//---------------------------Should create tests---------------------------//
    std::cout << ORANGE_TEXT << "should create president\n" << RESET_TEXT;
    rrf = someRandomIntern.makeForm("presidential quest", "Bender");
    
    std::cout << ORANGE_TEXT << "\nshould create shrubbery\n" << RESET_TEXT;
    rrf = someRandomIntern.makeForm("shrubbery quest", "Bender");
    
    std::cout << ORANGE_TEXT << "\nshould create robotomy\n" << RESET_TEXT;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    

//-------------------------Should not create tests-------------------------//
    std::cout << ORANGE_TEXT << "\nshould not create president\n" << RESET_TEXT;
    rrf = someRandomIntern.makeForm("president quest", "Bender");

    std::cout << ORANGE_TEXT << "\nshould not create shrubbery\n" << RESET_TEXT;
    rrf = someRandomIntern.makeForm("shrubery quest", "Bender");

    std::cout << ORANGE_TEXT << "\nshould not create robotomy\n" << RESET_TEXT;
    rrf = someRandomIntern.makeForm("roboto request", "Bender");
}
