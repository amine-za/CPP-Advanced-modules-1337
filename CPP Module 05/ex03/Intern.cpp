/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:46:20 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/26 11:16:18 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// PresidentialPardonForm   ShrubberyCreationForm   RobotomyRequestForm

AForm    *Intern::makeForm(std::string type, std::string target)
{
    std::string array[] = {"presidential", "shrubbery", "robotomy"};
    fct_ptr intern_ptr[3] = {&Intern::CreatePresidentialPardonForm, &Intern::CreateShrubberyCreationForm, &Intern::CreateRobotomyRequestForm};;

    for(int x = 0; x < 3; x++)
    {
        if (type.find(array[x]) != std::string::npos)
        {
            std::cout << "Intern creates " << type << std::endl;
            return (this->*intern_ptr[x])(target);
        }
    }
    std::cout << "An error appearse in makeForm function, it seems that the parameters you entered are wrong\n";
    return NULL;
}

AForm  *Intern::CreatePresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm  *Intern::CreateShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm  *Intern::CreateRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}
