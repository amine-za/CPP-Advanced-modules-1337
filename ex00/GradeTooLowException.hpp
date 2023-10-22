#ifndef GRADETOOLOWEXCEPTION_HPP
#define GRADETOOLOWEXCEPTION_HPP

#include <iostream>

class   GradeTooLowException : public std::exception
{
    public :
        GradeTooLowException();
        GradeTooLowException(GradeTooLowException &obj);
        ~GradeTooLowException();
        
        const char* what() const;

        GradeTooLowException &operator=(const GradeTooLowException &obj);
};

#endif