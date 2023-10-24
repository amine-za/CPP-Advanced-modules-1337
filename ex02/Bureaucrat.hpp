#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private :
        int grade;
        const std::string name;

    public :
//--------------------Construcotrs And Destructors--------------------//
        Bureaucrat();
        Bureaucrat(int G);
        Bureaucrat(int G, std::string N);
        Bureaucrat(Bureaucrat &obj);
        ~Bureaucrat();

//-------------------------------Getters-------------------------------//
        const std::string getName() const;
        int getGrade() const;

//--------------------------Membre function--------------------------//
        void    executeForm(AForm const & form);
        void    signForm(AForm &obj);
        void    IncrementGrade();
        void    DecrementGrade();

//-------------------------Exceptions functions-------------------------//

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
        class   FormNotSigned : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };
        
        class   GradeDontPermit : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };
//---------------------operators assignement---------------------//

        Bureaucrat  &operator=(Bureaucrat &obj);

};

std::ostream & operator<<( std::ostream & o, const Bureaucrat & rhs);

#endif