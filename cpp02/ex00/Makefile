NAME		= Fixed
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98

OBJDIR = .objFiles

FILES		= Fixed main

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all