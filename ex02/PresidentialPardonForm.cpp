/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:47:36 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/23 23:51:22 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("none", 25, 5)
{
    this->Target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string N): AForm("none", 25, 5)
{
    this->Target = N;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &obj) : AForm("none", 25, 5)
{
    *this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

std::string    PresidentialPardonForm::GetTarget()
{
    return (Target);
}

void    PresidentialPardonForm::execute()
{
    std::cout << this->GetTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &obj)
{
    this->Target = obj.Target;
    return *this;
}

