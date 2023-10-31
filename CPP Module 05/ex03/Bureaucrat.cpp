/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:29:54 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/25 18:29:56 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//-----------------------------------Constructors------------------------------------

Bureaucrat::Bureaucrat() : name("default")
{
    this->grade = 1;
    // By default i set the grade the the most higher one 
}

Bureaucrat::Bureaucrat(int G) : name("default")
{
    this->grade = G;
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(int G, std::string N) : name(N)
{
    this->grade = G;
    if (this->grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    if (this->grade < 1)
        throw(Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(Bureaucrat &obj)
{
    *this = obj;
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    else if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
}

//------------------------------------Destructor-------------------------------------

Bureaucrat::~Bureaucrat()
{}

//------------------------------------Exceptions-------------------------------------

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("It seems that you entered a grade lower than what it should be");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("It seems that you entered a grade higher than what it should be");
}

//--------------------------------------Getters---------------------------------------

const std::string Bureaucrat::getName() const
{
    return(this->name);
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

//---------------------------Grade Increment and Decrement----------------------------

void    Bureaucrat::IncrementGrade()
{
    if (this->grade > 1)
        this->grade--;
    else
        throw(Bureaucrat::GradeTooHighException());
}

void    Bureaucrat::DecrementGrade()
{
    if (this->grade < 150)
        this->grade++;
    else
        throw(Bureaucrat::GradeTooLowException());
}

//----------------------------------signForm function---------------------------------

void    Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.GetName() << std::endl;
    }
    catch(AForm::FormNotSigned &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(AForm::GradeDontPermit &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void    Bureaucrat::signForm(AForm &obj)
{
    if (obj.GetSignBoolean())
        std::cout << this->getName() <<  " signed "  << obj.GetName() << std::endl;
    else
        std::cout << this->getName() <<  " couldn't sign "  << obj.GetName() <<  " because their grade dont allow that" << std::endl;
}

//-------------------------------Operator assignement--------------------------------

Bureaucrat &Bureaucrat::operator=(Bureaucrat &obj)
{
    this->grade = obj.grade;
    return *this;
}

std::ostream & operator<<( std::ostream & o, const Bureaucrat & rhs)
{
	o << "Bureaucrat " << rhs.getName() << " has a grade " << rhs.getGrade();
	return (o);
}
