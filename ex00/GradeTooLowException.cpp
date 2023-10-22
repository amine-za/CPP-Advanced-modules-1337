#include "GradeTooLowException.hpp"
#include <stdexcept>

GradeTooLowException::GradeTooLowException()
{
    std::cout << "GradeTooLowException default constructor has been called" << std::endl;
}

GradeTooLowException::GradeTooLowException(GradeTooLowException &obj)
{
    std::cout << "GradeTooLowException copy constructor has been called" << std::endl;
    *this = obj;
}

GradeTooLowException::~GradeTooLowException()
{
    std::cout << "GradeTooLowException destructor has been called" << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what() const
{
    std::cout << "It seems that you entered a grade higher than" << 
    "what it should be, it should be not higher that 150" << std::endl;
}

GradeTooLowException &GradeTooLowException::operator=(const GradeTooLowException &obj)
{
    return *this;
}
