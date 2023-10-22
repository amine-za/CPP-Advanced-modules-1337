#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <string>
// #include "GradeTooHighException.hpp"
// #include "GradeTooLowException.hpp"

// class GradeTooLowException;
// class GradeTooHighException;

class Bureaucrat
{
    private :
        int grade;
        const std::string name;

    public :
        Bureaucrat();
        Bureaucrat(int G);
        Bureaucrat(int G, std::string N);
        Bureaucrat(Bureaucrat &obj);
        ~Bureaucrat();

        // GradeTooLowException GradeTooLowException;
        // GradeTooHighException GradeTooHighException;
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

        Bureaucrat  &operator=(Bureaucrat &obj);
};

#endif