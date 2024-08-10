# pragma once

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Bureaucrat;

class Form {
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _reqSignGrade;
        int const           _reqExecGrade;
    public:
        // CLASS MANIPULATION METHODS
        Form();
        ~Form();

        Form(std::string name, int signGrade, int execGrade);
        Form(const Form &copy);
        Form &operator=(const Form &element);

        // ACCESSOR METHODS
        std::string getName() const;
        bool        getSign() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

        // OTHER MEMBER FUNCTIONS
        void    beSigned(Bureaucrat &b);

        // EXCEPTIONS
        class GradeTooLow : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHigh : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class AlreadySigned : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &var);
