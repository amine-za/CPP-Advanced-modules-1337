#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private :
        std::string Target;
    public :
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string N);
        ShrubberyCreationForm(ShrubberyCreationForm &obj);
        ~ShrubberyCreationForm();

        std::string GetTarget();

        void    execute();

        ShrubberyCreationForm &operator=(ShrubberyCreationForm &obj);
};

#endif