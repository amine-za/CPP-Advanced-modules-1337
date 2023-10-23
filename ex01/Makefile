Name = ex01

CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address

SRC = main.cpp Bureaucrat.cpp Form.cpp

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
