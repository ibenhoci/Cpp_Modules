# pragma once

# include <iostream>
# include <stack>
# include <algorithm>
# include <exception>
# include <string>


class RPN {
    private:
        std::stack<double> _stk;
        RPN();
    public:
        RPN(const std::string line);
        ~RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &element);

        void launch(const std::string line);
    class ZeroDivision : public std::exception {
        public:
            virtual const char * what() const throw();
    };
    class BadInput : public std::exception {
        public:
            virtual const char * what() const throw();
    };
};