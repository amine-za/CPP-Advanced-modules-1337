/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaghlou <azaghlou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:30:01 by azaghlou          #+#    #+#             */
/*   Updated: 2023/10/26 11:17:02 by azaghlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("presidential quest", "Bender");
        rrf = someRandomIntern.makeForm("shrubbery quest", "Bender");
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        rrf = someRandomIntern.makeForm("president quest", "Bender");
        rrf = someRandomIntern.makeForm("shrubery quest", "Bender");
        rrf = someRandomIntern.makeForm("roboto request", "Bender");
    }

}

// int main()
// {
//     bool CatchOrNot = false;
//     //----------------------------------------------------Test 01----------------------------------------------------//
//     {
//         std::cout << "-------------------------Test 01 : Can sign all the forms-------------------------" << std::endl;
//         Bureaucrat  bureau(5, "Bureau");
//         PresidentialPardonForm pres("pres");
//         ShrubberyCreationForm shrub("shrub");
//         RobotomyRequestForm robot("robot");

//                                                         /*   Sign forms   */
//         try
//         {
//             std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the PresidentialPardonForm" << RESET_TEXT << std::endl;
//             pres.beSigned(bureau);
//         }
//         catch(AForm::CantSignForm &e)
//         {
//             std::cerr << e.what() << std::endl;
//             CatchOrNot = true;
//         }
//         if (!CatchOrNot)
//             std::cout << "That Form has been signed successfully by the Bureaucrat\n";
//         CatchOrNot = false;

//         try
//         {
//             std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the ShrubberyCreationForm" << RESET_TEXT << std::endl;
//             shrub.beSigned(bureau);
//         }
//         catch(AForm::CantSignForm & e)
//         {
//             std::cerr << e.what() << '\n';
//             CatchOrNot = true;
//         }
//         if (!CatchOrNot)
//             std::cout << "That Form has been signed successfully by the Bureaucrat\n";
//         CatchOrNot = false;

//         try
//         {
//             std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the RobotomyRequestForm" << RESET_TEXT << std::endl;
//             robot.beSigned(bureau);        
//         }
//         catch(AForm::CantSignForm & e)
//         {
//             std::cerr << e.what() << '\n';
//             CatchOrNot = true;
//         }
//         if (!CatchOrNot)
//             std::cout << "That Form has been signed successfully by the Bureaucrat\n";
//         CatchOrNot = false;

//                                                     /*   Applicate forms   */
//         std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the presidentialPardonForm" << RESET_TEXT << std::endl;
//         bureau.executeForm(pres);
//         std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the ShrubberyCreationForm" << RESET_TEXT << std::endl;
//         bureau.executeForm(shrub);
//         std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the RobotomyRequestForm" << RESET_TEXT << std::endl;
//         bureau.executeForm(robot);
//     }
    
    
//     //----------------------------------------------------Test 02----------------------------------------------------//
//     {
//         std::cout << "\n\n--Test 02 : Can sign only ShrubberyCreationForm and RobotomyRequestForm forms--" << std::endl;
//         Bureaucrat  bureau(50, "Bureau");

//         PresidentialPardonForm pres("pres");
//         ShrubberyCreationForm shrub("shrub");
//         RobotomyRequestForm robot("robot");

//                                                         /*   Sign forms   */
//         try
//         {
//             std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the presidentialPardonForm" << RESET_TEXT << std::endl;
//             pres.beSigned(bureau);
//         }
//         catch(AForm::CantSignForm & e)
//         {
//             std::cerr << e.what() << '\n';
//             CatchOrNot = true;
//         }
//         if (!CatchOrNot)
//             std::cout << "That Form has been signed successfully by the Bureaucrat\n";
//         CatchOrNot = false;

//         try
//         {
//             std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the ShrubberyCreationForm" << RESET_TEXT << std::endl;
//             shrub.beSigned(bureau);
//         }
//         catch(AForm::CantSignForm & e)
//         {
//             std::cerr << e.what() << '\n';
//             CatchOrNot = true;
//         }
//         if (!CatchOrNot)
//             std::cout << "That Form has been signed successfully by the Bureaucrat\n";
//         CatchOrNot = false;

//         try
//         {
//             std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the RobotomyRequestForm" << RESET_TEXT << std::endl;
//             robot.beSigned(bureau);
//         }
//         catch(AForm::CantSignForm & e)
//         {
//             std::cerr << e.what() << '\n';
//             CatchOrNot = true;
//         }
//         if (!CatchOrNot)
//             std::cout << "That Form has been signed successfully by the Bureaucrat\n";
//         CatchOrNot = false;
        
//                                                     /*   Applicate forms   */
//         std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the presidentialPardonForm" << RESET_TEXT << std::endl;
//         bureau.executeForm(pres);
//         std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the ShrubberyCreationForm" << RESET_TEXT << std::endl;
//         bureau.executeForm(shrub);
//         std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the RobotomyRequestForm" << RESET_TEXT << std::endl;
//         bureau.executeForm(robot);
//     }
    
    
//     //----------------------------------------------------Test 03----------------------------------------------------//
//     {
//         std::cout << "\n\n------------Test 03 : Can sign only the ShrubberyCreationForm form------------" << std::endl;
//         Bureaucrat  bureau(130, "Bureau");
//         PresidentialPardonForm pres("pres");
//         ShrubberyCreationForm shrub("shrub");
//         RobotomyRequestForm robot("robot");

//                                                         /*   Sign forms   */
//         try
//         {
//             std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the presidentialPardonForm" << RESET_TEXT << std::endl;
//           pres.beSigned(bureau);
//         }
//         catch(AForm::CantSignForm & e)
//         {
//             std::cerr << e.what() << '\n';
//             CatchOrNot = true;
//         }
//         if (!CatchOrNot)
//             std::cout << "That Form has been signed successfully by the Bureaucrat\n";
//         CatchOrNot = false;

//         try
//         {
//             std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the ShrubberyCreationForm" << RESET_TEXT << std::endl;
//             shrub.beSigned(bureau);
//         }
//         catch(AForm::CantSignForm & e)
//         {
//             std::cerr << e.what() << '\n';
//             CatchOrNot = true;

//         }
//         if (!CatchOrNot)
//             std::cout << "That Form has been signed successfully by the Bureaucrat\n";
//         CatchOrNot = false;

//         try
//         {
//             std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the RobotomyRequestForm" << RESET_TEXT << std::endl;
//             robot.beSigned(bureau);
//         }
//         catch(AForm::CantSignForm & e)
//         {
//             std::cerr << e.what() << '\n';
//             CatchOrNot = true;
//         }
//         if (!CatchOrNot)
//             std::cout << "That Form has been signed successfully by the Bureaucrat\n";
//         CatchOrNot = false;

//                                                     /*   Applicate forms   */
//         std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the presidentialPardonForm" << RESET_TEXT << std::endl;
//         bureau.executeForm(pres);
//         std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the ShrubberyCreationForm" << RESET_TEXT << std::endl;
//         bureau.executeForm(shrub);
//         std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the RobotomyRequestForm" << RESET_TEXT << std::endl;
//         bureau.executeForm(robot);
//     }
    

//     //----------------------------------------------------Test 04----------------------------------------------------//
//     {
//         std::cout << "\n\n-------------------------Test 04 : Can't sign any form-------------------------" << std::endl;
//         Bureaucrat  bureau(147, "Bureau");
//         PresidentialPardonForm pres("pres");
//         ShrubberyCreationForm shrub("shrub");
//         RobotomyRequestForm robot("robot");

//                                                         /*   Sign forms   */
//         try
//         {
//             std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the presidentialPardonForm" << RESET_TEXT << std::endl;
//             pres.beSigned(bureau);
//         }
//         catch(AForm::CantSignForm & e)
//         {
//             std::cerr << e.what() << '\n';
//             CatchOrNot = true;
//         }
//         if (!CatchOrNot)
//             std::cout << "That Form has been signed successfully by the Bureaucrat\n";
//         CatchOrNot = false;

//         try
//         {
//             std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the ShrubberyCreationForm" << RESET_TEXT << std::endl;
//             shrub.beSigned(bureau);
//         }
//         catch(AForm::CantSignForm & e)
//         {
//             std::cerr << e.what() << '\n';
//             CatchOrNot = true;
//         }
//         if (!CatchOrNot)
//             std::cout << "That Form has been signed successfully by the Bureaucrat\n";
//         CatchOrNot = false;

//         try
//         {
//             std::cout << ORANGE_TEXT << "\nBureaucrat trying to sign the RobotomyRequestForm" << RESET_TEXT << std::endl;
//             robot.beSigned(bureau);
//         }
//         catch(AForm::CantSignForm & e)
//         {
//             std::cerr << e.what() << '\n';
//             CatchOrNot = true;
//         }
//         if (!CatchOrNot)
//             std::cout << "That Form has been signed successfully by the Bureaucrat\n";
//         CatchOrNot = false;

//                                                     /*   Applicate forms   */
//         std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the presidentialPardonForm" << RESET_TEXT << std::endl;
//         bureau.executeForm(pres);
//         std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the ShrubberyCreationForm" << RESET_TEXT << std::endl;
//         bureau.executeForm(shrub);
//         std::cout << BLUE_TEXT << "\nBureaucrat trying to applicate the RobotomyRequestForm" << RESET_TEXT << std::endl;
//         bureau.executeForm(robot);
//     }
// }
