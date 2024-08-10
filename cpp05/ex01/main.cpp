# include "Bureaucrat.hpp"
# include "Form.hpp"

int main() {
    try {
        Bureaucrat b1 = Bureaucrat("Boss", 1);
        Form f1 = Form("Generic-Form", 100, 100);
        Form f2 = Form("Second-Generic-Form", 100, 100);
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        // We sign the form for the first time
        b1.signForm(f1);
        std::cout << f1 << std::endl;
        std::cout << std::endl;

        // We try to sign it again, should fail
        b1.signForm(f1);
        std::cout << f1 << std::endl;
        std::cout << std::endl;

        // We reduce the grade of the bureaucrat and try to sign, should also fail
        // We created another form because once a form is signed it cant be unsigned

        b1.SetGrade(101);
        b1.signForm(f2);
        std::cout << f2 << std::endl;
        std::cout << std::endl;
    } 
    catch (std::exception &e) {
        std::cout << "Exception raised in first block: " << e.what() << std::endl;
    }

    try {
        // should fail, invalid sign grade
        Form f1 = Form("Generic-form", 0, 150);
    } 
    catch (std::exception &e) {
        std::cout << "Exception raised in second block: " << e.what() << std::endl;
    }

    try {
        // should fail, invalid sign grade
        Form f1 = Form("Generic-form", 151, 150);
    }
    catch (std::exception &e) {
        std::cout << "Exception raised in third block: " << e.what() << std::endl;
    }
    try {
        // should fail, invalid exec grade
        Form f1 = Form("Generic-form", 10, 0);
    }
    catch (std::exception &e) {
        std::cout << "Exception raised in fourth block: " << e.what() << std::endl;
    }
    try {
        // should fail, invalid exec grade
        Form f1 = Form("Generic-form", 10, 151);
    }
    catch (std::exception &e) {
        std::cout << "Exception raised in fifth block: " << e.what() << std::endl;
    }
    return 0;
}
