# include "ScalarConverter.hpp"

bool isNumber(const std::string &input, bool flag) {
    int j = 0;
    if (flag && (input[0] == '+' || input[0] == '-'))
        j = 1;
    for (int i = j; i < input.length(); i++) {
        if (!std::isdigit(input[i]))
            return false;
    }
    return true;
}

bool isOverflow(const std::string& str) {
    bool isNegative = str[0] == '-';
    std::string maxIntStr = isNegative ? "2147483648" : "2147483647";

    if (str.length() > maxIntStr.length()) {
        return true;
    }
    if (str.length() == maxIntStr.length()) {
        return str > maxIntStr;
    }
    return false;
}

std::string determineType(const std::string &input) {
    // First we check for the obvious double literals
    if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan")
        return "double";
    // Next we check for the obvious float literals
    if (input == "inff" || input == "+inff" || input == "-inff" || input == "nanf")
        return "float";
    // Next we check if it is a character
    if (input.length() == 1 && input[0] >= 32 && input[0] <= 126) {
        if (std::isdigit(input[0]))
            return "int";
        return "char";
    }
    // Now we know the only thing left is a number
    // We check if it is a valid number
    // Lets check if we have a floating point
    size_t posF;
    size_t posP;
    posF = input.find("f");
    posP = input.find(".");
    // If we dont have a . or an f then its an int, we just need to check if its valid
    if (posF == std::string::npos && posP == std::string::npos) {
        if (isNumber(input, true))
            return "int";
        return "invalid_input";
    }
    if (posP == std::string::npos && posF != std::string::npos) {
        if (input.find("f", posF+1) != std::string::npos)
            return "invalid_input";
        return "float";
    }
    // If the . or f is at the start or they trail each other then it isnt valid
    if (input[0] == 'f' || input[0] == '.' || posF == posP+1 || posF == posP-1)
        return "invalid_input";
    // Now we check if we have duplicate .
    size_t oldPosP = posP;
    posP = input.find(".", posP+1);
    if (posP != std::string::npos)
        return "invalid_input";
    // Now we check if the first part of the number is correct
    if (!isNumber(input.substr(0, oldPosP-1), true))
        return "invalid_input";
    // Now we need to figure out if its a float or a double
    if (posF == std::string::npos) {
        if(isNumber(input.substr(oldPosP+1), false) && input.substr(oldPosP+1).length() >= 1)
            return "double";
        return "invalid_input";
    }
    posF = input.find("f", posF+1);
    if (posF != std::string::npos)
        return "invalid_input";
    // here still need to check if second part of the number is correct
    size_t len = input.substr(oldPosP+1).length();
    if (isNumber(input.substr(oldPosP+1, len-1), false))
        return "float";
    return "invalid_input";
}

void print_conversion(std::string type, const std::string &input) {
    if (type == "invalid_input") {
        std::cout << "INVALID INPUT: " << input << std::endl; 
        return ;
    }
    std::string res;
    int         i;
    float       f;
    double      d;
    char        *buf;
    if (type == "char") {
        res = input[0];
        i = static_cast<int>(input[0]);
        f = static_cast<float>(input[0]);
        d = static_cast<double>(input[0]);
    }
    if (type == "int") {
        if (isOverflow(input)) {
            type = "double";  
        }
        else {
            i = std::atoi(input.c_str());
            if (i < 0 || i > 255)
                res = "Impossible";
            else if (i >= 32 && i <= 127)
                res = static_cast<char>(i);
            else
                res = "Non-Displayable";
            f = static_cast<float>(i);
            d = static_cast<double>(i);
        }
    }
    if (type == "double") {
        d = std::strtod(input.c_str(), &buf);
        if (*buf != '\0') {
            std::cout << "INVALID INPUT: " << input << std::endl; 
            return ;
        }
        if (d < 0.0 || d > 255.0)
            res = "Impossible";
        else if (d >= 32.0 && d <= 127.0)
            res = static_cast<char>(d);
        else
            res = "Non-Displayable";
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    }
    if (type == "float") {
        std::string tmp = input.substr(0, input.length()-1);
        f = std::strtof(tmp.c_str(), &buf);
        if (*buf != '\0') {
            std::cout << "INVALID INPUT: " << input << std::endl; 
            return;
        }
        if (f < 0.0f || f > 255.0f)
            res = "Impossible";
        else if (f >= 32.0f && f <= 127.0f)
            res = static_cast<char>(f);
        else
            res = "Non-Displayable";
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    }

    if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan" || input == "nanf"
            || input == "inff" || input == "+inff" || input == "-inff" || isOverflow(input)) {

        std::cout << "CHAR   : Impossible" << std::endl;
        std::cout << "INT    : Impossible" << std::endl;
    }
    else {
        std::cout << "CHAR   : " << res << std::endl;
        std::cout << "INT    : " << i << std::endl;
    }
    
    if (type == "int" || type == "char" || (type == "double" && isOverflow(input))) {
        std::cout << std::fixed << std::setprecision(1) << "FLOAT  : " << f << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "DOUBLE : " << d << std::endl;       
    }
    else {
        std::cout << std::fixed << "FLOAT  : " << f << "f" << std::endl;
        std::cout << std::fixed << "DOUBLE : " << d << std::endl;
    }
    //std::cout << "-----------------------------------------------------------------" << std::endl;
}

void ScalarConverter::convert(const std::string &input) {
    std::string type = determineType(input);
    print_conversion(type, input);
}