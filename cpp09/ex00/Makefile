Name = btc
Source_Files = main.cpp BitcoinExchange.cpp
Object_Files = $(Source_Files:.cpp=.o)

all: $(Name)

$(Name): $(Object_Files)
	g++ $(Object_Files) -o $(Name)

%.o: %.cpp
	g++ -Wall -Wextra -Werror -std=c++98 -pedantic -c $< -o $@

clean:
	rm -f $(Object_Files)

fclean: clean
	rm -f $(Name)

re: fclean $(Name)

.PHONY: all clean fclean re