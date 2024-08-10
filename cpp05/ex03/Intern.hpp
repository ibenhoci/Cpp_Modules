# pragma once

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class AForm;

class Intern {
    public:
        // CLASS MANIPULATION METHODS
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &element);
        
        // OTHER MEMBER FUNCTIONS
		AForm *makeForm(const std::string form, const std::string target);
};
