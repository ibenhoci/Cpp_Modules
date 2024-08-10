# pragma once

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Bureaucrat;

class AForm {
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _reqSignGrade;
        int const           _reqExecGrade;
    public:
        // CLASS MANIPULATION METHODS
        AForm();
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &copy);
        AForm &operator=(const AForm &element);
        virtual ~AForm();
        // ACCESSOR METHODS
        std::string getName() const;
        bool        getSign() const;
        int         getSignGrade() const;
        int         getExecGrade() const;
        void        setSign(bool sign);

        // OTHER MEMBER FUNCTIONS
        void    beSigned(Bureaucrat &b);
        virtual void    execute(Bureaucrat const &executor) const = 0;
        virtual void    print(std::ostream &out) const = 0;
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
        class NotSigned : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &var);
