# pragma once

# include <algorithm>
# include <exception>
# include <iostream>

class NoSuchVal : public std::exception {
    public:
        virtual const char * what() const throw();
};

const char * NoSuchVal::what() const throw() {
    return "No such value";
}

template<typename T>
void easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it != container.end())
        std::cout << "The value: " << value << " is in the container" << std::endl;
    else
        throw NoSuchVal();
}