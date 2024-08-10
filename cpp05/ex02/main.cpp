# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat b = Bureaucrat("Boss", 1);
        Bureaucrat b1 = Bureaucrat("Random-employee", 140);
        ShrubberyCreationForm f1 = ShrubberyCreationForm("Shrubbery-targett");
        PresidentialPardonForm f2 = PresidentialPardonForm("Pardon-targettt");
        RobotomyRequestForm f3 = RobotomyRequestForm("Robotomy-targettt");

        std::cout << b << std::endl;
	    std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;
        
        // all these should work, boss is signing and executing all the forms

        b.signForm(f1);
        b.signForm(f2);
        b.signForm(f3);
        
        b.executeForm(f1);
        b.executeForm(f2);
        b.executeForm(f3);
    } 
    catch (std::exception &e) {
        std::cout << "Exception raised: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    Bureaucrat b1 = Bureaucrat("Random-employee", 140);
    ShrubberyCreationForm f1 = ShrubberyCreationForm("Shrubbery-targett");
    PresidentialPardonForm f2 = PresidentialPardonForm("Pardon-targettt");
    RobotomyRequestForm f3 = RobotomyRequestForm("Robotomy-targettt");
    std::cout << b1 << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;
    try {
        // only f1 should be signed, everything else should fail

        b1.signForm(f1);
        b1.signForm(f2);
        b1.signForm(f3);
        
        b1.executeForm(f1);
        b1.executeForm(f2);
        b1.executeForm(f3);

        b1.SetGrade(10);
        std::cout << std::endl;
        std::cout << std::endl;
        // now signing f1 should fail because alrdy signed, executing prespardon should also fail because grade is 10 but all else should work
         b1.signForm(f1);
        b1.signForm(f2);
        b1.signForm(f3);
        
        b1.executeForm(f1);
        b1.executeForm(f2);
        b1.executeForm(f3);
    } 
    catch (std::exception &e) {
        std::cout << "Exception raised: " << e.what() << std::endl;
    }
    return 0;
}
