# include "BitcoinExchange.hpp"
# include <vector>

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(std::string file_name) {
    try {
        load_data();
        compute(file_name);
    }
    catch(const std::exception &e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange() {    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _map(copy._map) {
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &element) {
    if (this != &element)
        _map = element._map;
    return *this;
}

void BitcoinExchange::load_data() {
    std::ifstream file("data.csv");

    if (!file.is_open())
        throw NoDataFileAvailable();
    
    std::string buffer;
    char *buf;
    double value;
    size_t  eol;

    std::getline(file, buffer);
    if (buffer != "date,exchange_rate") {
        file.close();
        throw BadFileHeader();
    }
    while (std::getline(file, buffer)) {
        eol = buffer.find(",");
        if (eol != std::string::npos) {
            value = std::strtod(buffer.substr(eol+1).c_str(), &buf);
            if (*buf != '\0') {
                file.close();
                throw DataFileCorrupt();
            }
            _map.insert(std::pair<std::string, double>(buffer.substr(0, eol), value));
        }
    }
}

void BitcoinExchange::compute(const std::string file_name) {
    std::ifstream file(file_name);
    if (!file.is_open())
        throw NoDataFileAvailable();
    
    std::string buffer;
    std::getline(file, buffer);
    if (buffer != "date | value") {
        file.close();
        throw BadFileHeader();
    }

    char *buf;
    size_t eol;
    double value;

    while (std::getline(file, buffer)) {
        try {
            eol = buffer.find("|");
            if (eol == std::string::npos)
                throw BadInput("bad input => " + buffer);
            
            value = std::strtod(buffer.substr(eol+1).c_str(), &buf);
            if (*buf != '\0')
                throw BadInput("bad input => " + buffer);
            
            if (value > 1000.00)
                throw NumberTooLarge();
            if (value < 0.00)
                throw NegativeNumber();
            
            // Here have to add date parser
            std::map<std::string, double>::iterator it = _map.lower_bound(buffer.substr(0, eol-1));
            if (it == _map.end())
                it--;
            
            // Printing the result
            std::cout << buffer.substr(0, eol-1) << " => " << value << " = " << it->second*value << std::endl;
        }
        catch(std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    file.close();
}

BitcoinExchange::BadInput::BadInput(const std::string &message) : _message(message) {
}

BitcoinExchange::BadInput::~BadInput() throw() {
}

const char *BitcoinExchange::BadInput::what() const throw() {
    return _message.c_str();
}

const char *BitcoinExchange::NumberTooLarge::what() const throw() {
    return "too large a number";
}

const char *BitcoinExchange::NegativeNumber::what() const throw() {
    return "not a positive number";
}

const char *BitcoinExchange::NoDataFileAvailable::what() const throw() {
    return "Bad Data File";
}

const char *BitcoinExchange::DataFileCorrupt::what() const throw() {
    return "Data File Content Is Corrupt";
}

const char *BitcoinExchange::BadFileHeader::what() const throw() {
    return "Bad File Header";
}
