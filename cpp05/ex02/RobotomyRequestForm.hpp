# pragma once

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		RobotomyRequestForm(void);
	public:
        // CLASS MANIPULATION METHODS
		RobotomyRequestForm(std::string const target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &element);

        // ACCESSOR METHODS
		std::string getTarget(void) const;
        
        // OTHER MEMBER FUNCTIONS
        void execute(Bureaucrat const &executor) const;
		void print(std::ostream &out) const;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm &var);