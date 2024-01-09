Name = PmergeMe

CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all     : $(Name)

$(Name) : $(OBJ) 
	$(CC) $(CPPFLAGS) $(OBJ) -o $(Name)

clean : 
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(Name)

re : fclean all

# my RULE: A rule that call the 're' and 'clean' rules and clears the screen output
my : re 
	@rm -rf $(OBJ)
	clear
