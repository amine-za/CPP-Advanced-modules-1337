/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:48:01 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/22 13:36:24 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default")
{
    this->grade = 0;
}

Bureaucrat::Bureaucrat(int G) : name("default")
{
    this->grade = G;
}

Bureaucrat::Bureaucrat(int G, std::string N) : name(N)
{
    this->grade = G;
}

Bureaucrat::Bureaucrat(Bureaucrat &obj)
{
    *this = obj;
}

Bureaucrat::~Bureaucrat()
{}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    std::cout << "It seems that you entered a grade lower than" << 
    "what it should be, it should be not lower than 1" << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    std::cout << "It seems that you entered a grade higher than" << 
    "what it should be, it should be not higher than 150" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &obj)
{
    this->grade = obj.grade;
    return *this;
}
