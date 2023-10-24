/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:56:10 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/23 23:51:53 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("none", 145, 137)
{
    this->Target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string N): AForm("none", 145, 137)
{
    this->Target = N;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &obj) : AForm("none", 145, 137)
{
    *this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

std::string    ShrubberyCreationForm::GetTarget()
{
    return (Target);
}

void    ShrubberyCreationForm::execute()
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


ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &obj)
{
    this->Target = obj.Target;
    return *this;
}

