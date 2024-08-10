#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
		PresidentialPardonForm(void);
	public:
        // CLASS MANIPULATION METHODS
		PresidentialPardonForm(std::string const target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &element);

        // ACCESSOR METHODS
		std::string getTarget(void) const;
        
        // OTHER MEMBER FUNCTIONS
        void execute(Bureaucrat const &executor) const;
		void print(std::ostream &out) const;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm &var);
