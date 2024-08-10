# pragma once

# include <iostream>
# include <exception>
# include <string>
# include "Form.hpp"


class Form;

class Bureaucrat {
    private:
        std::string _name;
        int         _grade;
    
    public:
        // CLASS MANIPULATION METHODS
        Bureaucrat();
        ~Bureaucrat();

        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &element);

        // ACCESSOR METHODS
        std::string GetName() const;
        int         GetGrade() const;
        void        SetName(std::string name);
        void        SetGrade(int grade);

        // OTHER MEMBER FUNCTIONS
        void IncrementGrade();
        void DecrementGrade();
        void signForm(Form &f);

        // EXCEPTIONS
        class GradeTooLow : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooHigh : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &var);
