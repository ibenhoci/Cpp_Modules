#include "Intern.hpp"
Intern::Intern() {
	std::cout << "New Intern!" << std::endl;
}

Intern::~Intern() {
}

Intern::Intern(const Intern &copy) {
	(void)copy;
}

Intern &Intern::operator=(const Intern &element) {
	(void)element;
	return *this;
}
        
// OTHER MEMBER FUNCTIONS

static AForm	*makePresident(const std::string target)
{
	PresidentialPardonForm *ptr = new PresidentialPardonForm(target);
	std::cout << *ptr;
	return ptr;
}

static AForm	*makeRobot(const std::string target)
{
	RobotomyRequestForm *ptr = new RobotomyRequestForm(target);
	std::cout << *ptr;
	return ptr;
}

static AForm	*makeShrubbery(const std::string target)
{
	ShrubberyCreationForm *ptr = new ShrubberyCreationForm(target);
	std::cout << *ptr;
	return ptr;
}

AForm *Intern::makeForm(const std::string form, const std::string target) {
	std::string list[3] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
	AForm *(*all_forms[])(const std::string target) = {&makeShrubbery, &makePresident, &makeRobot};
	for (int i = 0; i < 3; i++)
	{
		if (list[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			return (all_forms[i](target));
		}
	}
	std::cout << "Intern could not create the form!" << std::endl;
	return (NULL);
}
