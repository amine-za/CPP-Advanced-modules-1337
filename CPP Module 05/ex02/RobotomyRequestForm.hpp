#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include <random>
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private :
        std::string Target;
        
    public :

//---------------------Construcotrs And Destructors---------------------//
        RobotomyRequestForm();
        RobotomyRequestForm(std::string N);
        RobotomyRequestForm(RobotomyRequestForm &obj);
        ~RobotomyRequestForm();

//-------------------------------Getters-------------------------------//
        std::string GetTarget();

//---------------------------Membre function---------------------------//
        void    execute(Bureaucrat const &obj) const;

//-----------------------operators assignement-----------------------//
        RobotomyRequestForm &operator=(RobotomyRequestForm &obj);
};

#endif