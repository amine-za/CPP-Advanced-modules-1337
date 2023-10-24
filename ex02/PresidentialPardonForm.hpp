#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private :
        std::string Target;
    public :
        PresidentialPardonForm();
        PresidentialPardonForm(std::string N);
        PresidentialPardonForm(PresidentialPardonForm &obj);
        ~PresidentialPardonForm();

        std::string GetTarget();

        void    execute();

        PresidentialPardonForm &operator=(PresidentialPardonForm &obj);
};

#endif