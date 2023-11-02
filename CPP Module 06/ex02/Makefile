Name = convert

CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp

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
