/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:44:12 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/25 11:05:47 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), GradeToSign(1), GradeToExecute(1)
{
    signd = false;
}

Form::Form(std::string N, int Gs, int Ge) : name(N), GradeToSign(Gs), GradeToExecute(Ge)
{
    this->signd = false;
    if (this->GradeToExecute > 150 || this->GradeToSign > 150)
        throw(GradeTooHighException());
    if (this->GradeToExecute < 1 || this->GradeToSign < 1)
        throw(GradeTooLowException());
}

Form::Form(Form &obj) : name(obj.name), GradeToSign(obj.GradeToSign), GradeToExecute(obj.GradeToExecute)
{
    *this = obj;
}

Form::~Form()
{
}

std::string Form::GetName() const
{
    return (this->name);
}

bool        Form::GetSignBoolean() const
{
    return (this->signd);
}

int         Form::GetSignGrade() const
{
    return (this->GradeToSign);
}

int         Form::GetExecuteGrade() const
{
    return (this->GradeToExecute);
}

void    Form::beSigned(Bureaucrat &obj)
{
    if (this->GetSignGrade() >= obj.getGrade()) // this mean that the grade of the bureaucrate is greater than the grade of the form
        this->signd = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("It seems that you entered a grade higher than the bounds");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("It seems that you entered a grade lower than the bounds");
}

Form &Form::operator=(Form &obj)
{
    this->signd = obj.signd;
    return *this;
}

std::ostream & operator<<( std::ostream & o, const Form & rhs)
{
    std::string TF;
    if (rhs.GetSignBoolean())
        TF = "True";
    else
        TF = "False";
	o << "Form " << rhs.GetName() << " has a signing grade of " << rhs.GetSignGrade()
    << " and an execution grade of " << rhs.GetExecuteGrade() << " and the signed boolean is " << TF;
	return (o);
}
