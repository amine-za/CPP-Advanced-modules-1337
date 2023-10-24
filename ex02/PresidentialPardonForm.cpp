/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:47:36 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/24 18:20:24 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


//---------------------Construcotrs And Destructors---------------------//
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
    else if (this->GetSignGrade() > bureau.getGrade()) //if the bureaucrat's grade isn't high enough
        throw(GradeDontPermit());
    else
        std::cout << this->GetTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

//------------------------Exceptions functions------------------------//
// const char *PresidentialPardonForm::FormNotSigned::what() const throw()
// {
//     return ("An error appearse, it seems that the form isn't signed");
// }

// const char *PresidentialPardonForm::GradeDontPermit::what() const throw()
// {
//     return ("An error appearse, it seems that the grade of the bureaucrat dont permit to sing the form");
// }

//-----------------------operators assignement-----------------------//
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &obj)
{
    this->Target = obj.Target;
    return *this;
}
