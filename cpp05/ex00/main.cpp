#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1 = Bureaucrat("Boss", 1);
        std::cout << b1 << std::endl;

        // Lets decrement his grade, this should work
        b1.DecrementGrade();
        std::cout << b1 << std::endl;

        // Lets increment it back to max grade
        b1.IncrementGrade();
        std::cout << b1 << std::endl;

        // Lets try to increment once more, this should throw an exception!
        b1.IncrementGrade(); 
    } 
    catch (std::exception &e) {
        std::cout << "Exception raised in first block: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b1 = Bureaucrat("Random", 150);
        std::cout << b1 << std::endl;

        // Lets decrement his grade, this should throw an exception
        b1.DecrementGrade();
    } 
    catch (std::exception &e) {
        std::cout << "Exception raised in second block: " << e.what() << std::endl;
    }

    try {
        // Lets try to create a bureaucrat with an invalid grade
        Bureaucrat b1 = Bureaucrat("Random", -1);
    }
    catch (std::exception &e) {
        std::cout << "Exception raised in third block: " << e.what() << std::endl;
    }
    try {
        // Lets try to create a bureaucrat with an invalid grade
        Bureaucrat b1 = Bureaucrat("Random", 151);
    }
    catch (std::exception &e) {
        std::cout << "Exception raised in fourth block: " << e.what() << std::endl;
    }

    return 0;
}
