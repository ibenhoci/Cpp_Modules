# include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "./PmergeMe <numbers> ..." << std::endl;
        return 0;
    }

    try {
        PmergeMe(argc, argv);
    }
    catch (const std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    
    return 0;
}
