Name = Bureaucrat
Source_Files = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
Object_Files = $(Source_Files:.cpp=.o)

all: $(Name)

$(Name): $(Object_Files)
	g++ -Wall -Wextra -Werror -std=c++98 -pedantic $(Object_Files) -o $(Name)

clean:
	rm -f $(Object_Files)

fclean: clean
	rm -f $(Name)

re: fclean $(Name)

.PHONY: all clean fclean re