# include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc != 2)
        std::cout << "Usage: ./RPN \" SOME RANDOM RPN \"" << std::endl;
    else
        RPN r(argv[1]);
    return 0;
}