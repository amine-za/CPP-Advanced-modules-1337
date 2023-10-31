Name = ex03

CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp AForm.cpp Bureaucrat.cpp \
PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
ShrubberyCreationForm.cpp Intern.cpp

OBJ = $(SRC:.cpp=.o)

all     : $(Name)

$(Name) : $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(Name)

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(Name)

re : fclean all

my : re
	@rm -rf $(OBJ)
	clear
