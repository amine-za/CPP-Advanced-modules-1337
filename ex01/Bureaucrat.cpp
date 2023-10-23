/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:43:43 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/23 17:28:15 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//-----------------------------------Constructors------------------------------------

Bureaucrat::Bureaucrat() : name("default")
{
    this->grade = 1;
//  Because you dident identify a value to the grade variable,
//  by default it's set to zero so its lower than the range.
    // throw(Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(int G) : name("default")
{
    this->grade = G;
    if (grade > 150)
        throw(Bureaucrat::GradeTooHighException());
    if (grade < 1)
        throw(Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(int G, std::string N) : name(N)
{
    this->grade = G;
    if (this->grade > 150)
        throw(Bureaucrat::GradeTooHighException());
    if (this->grade < 1)
        throw(Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat &obj)
{
    *this = obj;
    if (grade > 150)
        throw(Bureaucrat::GradeTooHighException());
    else if (grade < 1)
        throw(Bureaucrat::GradeTooLowException());
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
    this->grade++;
    if (grade > 150)
        throw(Bureaucrat::GradeTooHighException());
}

void    Bureaucrat::DecrementGrade()
{
    this->grade--;
    if (grade < 1)
        throw(Bureaucrat::GradeTooLowException());
}

//---------------------------------------------------------------//

void    Bureaucrat::signForm(Form &obj)
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
