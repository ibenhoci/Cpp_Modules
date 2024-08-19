# include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(const std::string line) {
    try {
        launch(line);
    }
    catch(const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

RPN::~RPN() {
}

RPN::RPN(const RPN &copy) : _stk(copy._stk) {
}

RPN &RPN::operator=(const RPN &element) {
    if (this != &element)
        _stk = element._stk;
    return *this;
}

bool isValidChar(char c) {
    return std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == ' ';
}

void RPN::launch(const std::string line) {
    for (size_t i = 0; i < line.length(); i++) {
        if (!isValidChar(line[i]))
            throw BadInput();
    }

    double v;
    for (size_t i = 0; i < line.length(); i++) {
        if (std::isdigit(line[i]))
            _stk.push((double)(line[i] - '0'));
        else if (isValidChar(line[i]) && line[i] != ' ') {
            if (_stk.empty())
                throw BadInput();
            v = _stk.top();
            _stk.pop();
            if (_stk.empty())
                throw BadInput();
            switch(line[i]) {
                case '+':
                    v += _stk.top();
                    break;
                case '-':
                    v = _stk.top() - v;
                    break;
                case '*':
                    v *= _stk.top();
                    break;
                case '/':
                    if (v == 0.0)
                        throw ZeroDivision();
                    v = _stk.top() / v;
            }
            _stk.pop();
            _stk.push(v);
        }
    }
    if (_stk.empty() || _stk.size() != 1)
        throw BadInput();
    std::cout << "Result is: " << _stk.top() << std::endl;
}

const char *RPN::ZeroDivision::what() const throw() {
    return "Division By Zero";
}

const char *RPN::BadInput::what() const throw() {
    return "Bad Input";
}