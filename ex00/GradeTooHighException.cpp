#include "GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException()
{
    std::cout << "GradeTooHighException default constructor has been called" << std::endl;
}

GradeTooHighException::GradeTooHighException(GradeTooHighException &obj)
{
    std::cout << "GradeTooHighException copy constructor has been called" << std::endl;
    *this = obj;
}

GradeTooHighException::~GradeTooHighException()
{
    std::cout << "GradeTooHighException destructor has been called" << std::endl;
}

const char *GradeTooHighException::what() const
{
    std::cout << "It seems that you entered a grade lower than" << 
    "what it should be, it should be not lower that 1" << std::endl;
}

GradeTooHighException &GradeTooHighException::operator=(const GradeTooHighException &obj)
{
    return *this;
}
