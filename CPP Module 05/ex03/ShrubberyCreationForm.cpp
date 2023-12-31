/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:30:19 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/25 18:30:23 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//---------------------Construcotrs And Destructors---------------------//
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("the form", 145, 137)
{
    this->Target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string N): AForm("the form", 145, 137)
{
    this->Target = N;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &obj) : AForm("the form", 145, 137)
{
    *this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

//-------------------------------Getters-------------------------------//
std::string    ShrubberyCreationForm::GetTarget() const
{
    return (Target);
}

//---------------------------Membre function---------------------------//
void    ShrubberyCreationForm::execute(Bureaucrat const &bureau) const
{
    if (!this->GetSignBoolean())
        throw(FormNotSigned());
    else if (this->GetSignGrade() < bureau.getGrade())
        throw(GradeDontPermit());
    else
    {
        std::string tree = 
        "      *\n"
        "     ***\n"
        "    *****\n"
        "   *******\n"
        "  *********\n"
        "     | |\n";

        std::ofstream file(this->GetTarget() + "_shrubbery");
        if (!file)
        {
            std::cout << "it looks like an error appears while creating the output file" << std::endl;
            return;
        }
        file << tree;
    }
}

//-----------------------operators assignement-----------------------//
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &obj)
{
    this->Target = obj.Target;
    return *this;
}
