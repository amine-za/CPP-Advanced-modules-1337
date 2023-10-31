/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:31:09 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/25 11:06:47 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//---------------------Construcotrs And Destructors---------------------//
RobotomyRequestForm::RobotomyRequestForm() : AForm("the form", 72, 45)
{
    this->Target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string N): AForm("the form", 72, 45)
{
    this->Target = N;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &obj) : AForm("the form", 72, 45)
{
    *this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

//-------------------------------Getters-------------------------------//
std::string    RobotomyRequestForm::GetTarget()
{
    return (Target);
}

//---------------------------Membre function---------------------------//
void    RobotomyRequestForm::execute(Bureaucrat const &bureau) const
{
    if (!this->GetSignBoolean())
        throw(FormNotSigned());
    else if (this->GetSignGrade() < bureau.getGrade())
        throw(GradeDontPermit());
    else
    {
        std::cout << "Occurrence of some drilling noises" << std::endl;
        std::random_device rand;
        std::uniform_int_distribution<int> dist(1,2);
        if (dist(rand) == 1)
            std::cout << this->GetName() << " has been robotomized successfully 50% of the time" << std::endl;
        else
            std::cout << "The robotomy failed" << std::endl;
    }
}

//-----------------------operators assignement-----------------------//
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &obj)
{
    this->Target = obj.Target;
    return *this;
}

