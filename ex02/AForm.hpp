#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

#define RESET_TEXT "\033[0m"
#define BLUE_TEXT "\033[34m"

class Bureaucrat; 

class AForm 
{
    private :
        const std::string name;
        bool signd;
        const int GradeToSign;
        const int GradeToExecute;

    public :
//--------------------Construcotrs And Destructors--------------------//
        AForm();
        AForm(std::string N, int Gs, int Ge);
        AForm(AForm &obj);
        virtual ~AForm();

//-------------------------------Getters-------------------------------//
        virtual std::string GetName() const;
        virtual bool        GetSignBoolean() const;
        virtual int         GetSignGrade() const;
        virtual int         GetExecuteGrade() const;

//--------------------------Membre functions--------------------------//
        virtual void    beSigned(Bureaucrat &obj);

        virtual void    execute(Bureaucrat const & executor) const = 0;


//-------------------------Exceptions classes-------------------------//
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

//---------------------copy operator assignement---------------------//
        AForm &operator=(AForm &obj);

};

std::ostream & operator<<( std::ostream & o, const AForm & rhs);

#endif