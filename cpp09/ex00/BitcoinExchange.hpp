# pragma once

# include <iostream>
# include <string>
# include <map>
# include <exception>
# include <fstream>

class BitcoinExchange {
    private:
        std::map<std::string, double> _map;
        BitcoinExchange();
    public:
        BitcoinExchange(std::string file_name);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &element);

        void load_data();
        void compute(const std::string file_name);

        class BadInput : public std::exception {
            private:
                std::string _message;
            public:
                BadInput(const std::string &message);
                virtual ~BadInput() throw();
                virtual const char * what() const throw();
        };
        class NumberTooLarge : public std::exception {
            public:
                virtual const char * what() const throw();
        };
        class NegativeNumber : public std::exception {
            public:
                virtual const char * what() const throw();
        };
        class NoDataFileAvailable : public std::exception {
            public:
                virtual const char * what() const throw();
        };
        class DataFileCorrupt : public std::exception {
            public:
                virtual const char * what() const throw();
        };
        class BadFileHeader : public std::exception {
            public:
                virtual const char * what() const throw();
        };
};
