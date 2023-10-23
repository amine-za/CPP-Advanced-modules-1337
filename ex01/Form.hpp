#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Bureaucrat; 

class Form 
{
    private :
        const std::string name;
        bool signd;
        const int GradeToSign;
        const int GradeToExecute;

    public :
        Form();
        Form(std::string N, int Gs, int Ge);
        Form(Form &obj);
        ~Form();

        std::string GetName() const;
        bool        GetSignBoolean() const;
        int         GetSignGrade() const;
        int         GetExecuteGrade() const;

        void    beSigned(Bureaucrat &obj);

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw();
    
        };

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char *what() const throw();
    
        };

        Form &operator=(Form &obj);

};

std::ostream & operator<<( std::ostream & o, const Form & rhs);

#endif