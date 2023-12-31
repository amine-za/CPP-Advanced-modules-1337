#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private :
        std::string Target;
    public :

//---------------------Construcotrs And Destructors---------------------//
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string N);
        ShrubberyCreationForm(ShrubberyCreationForm &obj);
        ~ShrubberyCreationForm();

//-------------------------------Getters-------------------------------//
        std::string GetTarget() const;

//---------------------------Membre function---------------------------//
        void    execute(Bureaucrat const &obj) const;

//-----------------------operators assignement-----------------------//
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &obj);
};

#endif