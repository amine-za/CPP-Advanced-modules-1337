/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:48:01 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/25 15:49:41 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//-----------------------------------Constructors------------------------------------

Bureaucrat::Bureaucrat() : name("default")
{
    this->grade = 1;
    // By default i set the grade to the highest one so its set to "1"
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
    // this->grade++;
    // if (grade > 150)
    //     throw(Bureaucrat::GradeTooHighException());
    if (this->grade > 1)
        this->grade--;
}

void    Bureaucrat::DecrementGrade()
{
    // this->grade--;
    // if (grade < 1)
    //     throw(Bureaucrat::GradeTooLowException());
    if (this->grade < 150)
        this->grade++;
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
