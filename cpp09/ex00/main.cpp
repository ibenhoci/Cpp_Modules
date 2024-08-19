# include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2)
        std::cout << "Usage: ./btc <input_file>" << std::endl;
    else
        BitcoinExchange btc(argv[1]);
    return 0;
}
