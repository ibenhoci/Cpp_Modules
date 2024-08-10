# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Random_Worker"), _grade(10) {
    std::cout << "Default Constructor Called!" << std::endl;
}
Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Deconstructor Called!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) {
    if (grade < 1)
        throw GradeTooHigh();
    else if (grade > 150)
        throw GradeTooLow();
    else {
        this->_grade = grade;
        this->_name = name;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    this->_grade = copy.GetGrade();
    this->_name = copy.GetName();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &element) {
    if (this != &element) {
        this->SetGrade(element.GetGrade());
        this->SetName(element.GetName());
    }
    return *this;
}

// ACCESSOR METHODS
std::string Bureaucrat::GetName() const {
    return this->_name;
}

int         Bureaucrat::GetGrade() const {
    return this->_grade;
}

void        Bureaucrat::SetName(std::string name) {
    this->_name = name;
}

void        Bureaucrat::SetGrade(int grade) {
    if (grade < 1)
        throw GradeTooHigh();
    else if (grade > 150)
        throw GradeTooLow();
    else
        this->_grade = grade;
}

// OTHER var FUNCTIONS
void Bureaucrat::IncrementGrade() {
    this->SetGrade(this->GetGrade() - 1);
}
void Bureaucrat::DecrementGrade() {
    this->SetGrade(this->GetGrade() + 1);
}
void Bureaucrat::signForm(Form &f) {
    try {
        f.beSigned(*this);
        std::cout << *this << " signed " << f << std::endl;
    }
    catch (std::exception &e) {
        std::cout << *this << " couldnt sign form: " << f << " because " << e.what() << std::endl; 
    }
}

// EXCEPTIONS
const char* Bureaucrat::GradeTooLow::what() const throw() {
	return "Grade is too low";
}

const char* Bureaucrat::GradeTooHigh::what() const throw() {
	return "Grade is too high";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &var) {
	out << var.GetName() << ", bureaucrat grade " << var.GetGrade() << ".";
	return (out);
}