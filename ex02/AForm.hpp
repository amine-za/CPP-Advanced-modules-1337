#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

// #include "Bureaucrat.hpp"

class Bureaucrat; 

class AForm 
{
    private :
        const std::string name;
        bool signd;
        const int GradeToSign;
        const int GradeToExecute;

    public :
        AForm();
        AForm(std::string N, int Gs, int Ge);
        AForm(AForm &obj);
        virtual ~AForm();

        virtual std::string GetName() const = 0;
        virtual bool        GetSignBoolean() const = 0;
        virtual int         GetSignGrade() const = 0;
        virtual int         GetExecuteGrade() const = 0;

        virtual void    beSigned(Bureaucrat &obj) = 0;

        void    execute(Bureaucrat const & executor) const;

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

        AForm &operator=(AForm &obj);

};

std::ostream & operator<<( std::ostream & o, const AForm & rhs);

#endif