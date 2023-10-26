/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:30:08 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/25 18:30:10 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//---------------------Construcotrs And Destructors---------------------//
PresidentialPardonForm::PresidentialPardonForm() : AForm("the form", 25, 5)
{
    this->Target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string N): AForm("the form", 25, 5)
{
    this->Target = N;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &obj) : AForm("the form", 25, 5)
{
    *this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

//-------------------------------Getters-------------------------------//
std::string    PresidentialPardonForm::GetTarget() const
{
    return (Target);
}

//---------------------------Membre function---------------------------//
void    PresidentialPardonForm::execute(Bureaucrat const &bureau) const
{
    if (!this->GetSignBoolean()) //if the form is not signed 
        throw(FormNotSigned());
    else if (this->GetSignGrade() < bureau.getGrade()) //if the bureaucrat's grade isn't high enough
        throw(GradeDontPermit());
    else
        std::cout << this->GetTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

//-----------------------operators assignement-----------------------//
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &obj)
{
    this->Target = obj.Target;
    return *this;
}
