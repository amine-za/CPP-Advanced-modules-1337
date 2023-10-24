#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"
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

//------------------------Exceptions functions------------------------//
        // class   FormNotSigned : public std::exception
        // {
        //     public :
        //         virtual const char *what() const throw();
        // };
        
        // class   GradeDontPermit : public std::exception
        // {
        //     public :
        //         virtual const char *what() const throw();
        // };

//-----------------------operators assignement-----------------------//
        RobotomyRequestForm &operator=(RobotomyRequestForm &obj);
};

#endif