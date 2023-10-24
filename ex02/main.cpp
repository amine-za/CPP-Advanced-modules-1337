/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:38:36 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/24 19:29:49 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat  bureau(14, "Bureau");
    PresidentialPardonForm pres("pres");
    ShrubberyCreationForm shrub("shrub");
    RobotomyRequestForm robot("robot");

    pres.beSigned(bureau);
    shrub.beSigned(bureau);
    robot.beSigned(bureau);
    bureau.executeForm(pres);
    bureau.executeForm(shrub);
    bureau.executeForm(robot);
    
    // try
    // {
    //     pres.execute(bureau);
    // }
    // catch(AForm::FormNotSigned& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
}