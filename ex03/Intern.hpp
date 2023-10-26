#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// PresidentialPardonForm   ShrubberyCreationForm   RobotomyRequestForm

class Intern
{
private:
    AForm *CreatePresidentialPardonForm(std::string target);
    AForm *CreateShrubberyCreationForm(std::string target);
    AForm *CreateRobotomyRequestForm(std::string target);

public:
    AForm *makeForm(std::string type, std::string target);
};

typedef AForm *(Intern::*fct_ptr)(std::string);

#endif