#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#include "Form.hpp"

class Form;


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

        const std::string getName() const;
        int getGrade() const;

        void    IncrementGrade();
        void    DecrementGrade();

        void    signForm(Form &obj);

        Bureaucrat  &operator=(Bureaucrat &obj);

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
};

std::ostream & operator<<( std::ostream & o, const Bureaucrat & rhs);

#endif