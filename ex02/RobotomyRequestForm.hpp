#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private :
        std::string Target;
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(std::string N);
        RobotomyRequestForm(RobotomyRequestForm &obj);
        ~RobotomyRequestForm();

        std::string GetTarget();

        void    execute();

        RobotomyRequestForm &operator=(RobotomyRequestForm &obj);
};

#endif