#ifndef GRADETOOHIGHEXCEPTION_HPP
#define GRADETOOHIGHEXCEPTION_HPP

#include "iostream"
#include <stdexcept>

class   GradeTooHighException : public std::exception
{
    public :
        GradeTooHighException();
        GradeTooHighException(GradeTooHighException &obj);
        ~GradeTooHighException();
        
        const char* what() const;

        GradeTooHighException &operator=(const GradeTooHighException &obj);
};

#endif