# pragma once

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
		ShrubberyCreationForm(void);
	public:
        // CLASS MANIPULATION METHODS
		ShrubberyCreationForm(std::string const target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &element);

        // ACCESSOR METHODS
		std::string getTarget(void) const;
        
        // OTHER MEMBER FUNCTIONS
        void execute(Bureaucrat const &executor) const;
		void print(std::ostream &out) const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm &var);