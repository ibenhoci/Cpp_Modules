# include "easyfind.hpp"
# include <vector>
# include <list>
# include <deque>

int main() {
    // Test with vector
    try {
        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::cout << "Testing with vector..." << std::endl;
        easyfind(vec, 3);
        easyfind(vec, 10);
    }
    catch (std::exception &e) {
        std::cout << "Caught the following exception: " << e.what() << std::endl;
    }

    // Test with deque
    try {
        std::deque<int> deq = {10, 20, 30, 40, 50};
        std::cout << "Testing with deque..." << std::endl;
        easyfind(deq, 10);
        easyfind(deq, 3);
    }
    catch (std::exception &e) {
        std::cout << "Caught the following exception: " << e.what() << std::endl;
    }

    // Test with list
    try {
        std::list<int> lst = {100, 200, 300, 400};
        std::cout << "Testing with list..." << std::endl;
        easyfind(lst, 300);
        easyfind(lst, 500);
    }
    catch (std::exception &e) {
        std::cout << "Caught the following exception: " << e.what() << std::endl;
    }
}