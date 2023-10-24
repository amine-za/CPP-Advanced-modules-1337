/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:31:09 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/23 23:51:00 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("none", 72, 45)
{
    this->Target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string N): AForm("none", 72, 45)
{
    this->Target = N;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &obj) : AForm("none", 72, 45)
{
    *this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

std::string    RobotomyRequestForm::GetTarget()
{
    return (Target);
}

void    RobotomyRequestForm::execute()
{
    std::cout << "Occurrence of some drilling noises" << std::endl;
    int random = std::rand() %50;
    if (random == 0)
        std::cout << this->GetName() << " has been robotomized successfully 50% of the time" << std::endl;
    else
        std::cout << "The robotomy failed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &obj)
{
    this->Target = obj.Target;
    return *this;
}

