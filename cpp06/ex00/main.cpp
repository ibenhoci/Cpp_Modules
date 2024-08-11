# include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./ScalarConverter [arg]" << std::endl;
        return 0;
    }
    ScalarConverter::convert(argv[1]);
    return (0);
    /*std::cout << "-------------------CHAR TEST-------------------" << std::endl;
    ScalarConverter::convert("-");
    ScalarConverter::convert("{");
    ScalarConverter::convert("b");
    ScalarConverter::convert("Z");
    ScalarConverter::convert("/");
    ScalarConverter::convert("*");

    std::cout << "-------------------INT TEST-------------------" << std::endl;
    ScalarConverter::convert("-64");
    ScalarConverter::convert("+64");
    ScalarConverter::convert("64");
    ScalarConverter::convert("6431551386");
    ScalarConverter::convert("0");

    std::cout << "-------------------DOUBLE TEST-------------------" << std::endl;
    ScalarConverter::convert("-64.0");
    ScalarConverter::convert("+64.0");
    ScalarConverter::convert("64.0");
    ScalarConverter::convert("-64.0131");
    ScalarConverter::convert("+64.0131");
    ScalarConverter::convert("64.0131");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("inf");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("-inf");
    
    std::cout << "-------------------FLOAT TEST-------------------" << std::endl;
    ScalarConverter::convert("-64.0f");
    ScalarConverter::convert("+64.0f");
    ScalarConverter::convert("64.0f");
    ScalarConverter::convert("-64.0131f");
    ScalarConverter::convert("+64.0131f");
    ScalarConverter::convert("64.0131f");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("inff");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("-inff");

    std::cout << "-----------------------------------------------------------------" << std::endl;

    std::cout << "-------------------INVALID INPUT TEST-------------------" << std::endl;
    ScalarConverter::convert("verrvd");
    ScalarConverter::convert("156a2");
    ScalarConverter::convert("132azsdvs4d6v8");
    ScalarConverter::convert("-*8");
    ScalarConverter::convert("--8");
    ScalarConverter::convert("+-8");
    ScalarConverter::convert("++8");
    ScalarConverter::convert("8..");
    ScalarConverter::convert("8.");
    ScalarConverter::convert("8.-");
    ScalarConverter::convert("8.+");
    ScalarConverter::convert("8.-f");
    ScalarConverter::convert("8.+f");
    ScalarConverter::convert("8.-f-");
    ScalarConverter::convert("8.+f+");
    ScalarConverter::convert("8.--f");
    ScalarConverter::convert("8.++f");
    ScalarConverter::convert("8.f");
    ScalarConverter::convert("8f.");
    ScalarConverter::convert(".8");
    ScalarConverter::convert("165..161");
    ScalarConverter::convert("318ff");
    ScalarConverter::convert("3135.416ff");
    ScalarConverter::convert("1864.138.68");
    ScalarConverter::convert("15615.-16811");
    ScalarConverter::convert("4.+1631");
    ScalarConverter::convert("15615.-16811f");
    ScalarConverter::convert("4.+1631f");
    ScalarConverter::convert("f156156");
    ScalarConverter::convert("f1561.1561f");
    ScalarConverter::convert("f1541.1651.f561");
    */
    
}