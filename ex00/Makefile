NAME = hermees_and_friends
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
FILES = main.cpp\
		Burecraut.cpp
HFILES = Burecraut.hpp

OBJ = $(FILES:.cpp=.o)

all : $(OBJ) $(NAME)
	

$(NAME): $(OBJ) $(HFILES)
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME)


%.o : %.c
	$(CC) $(CFLAGS) -c -O  $< -o $@
	
clean :
	rm -f $(OBJ) $(BOBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all re fclean clean
