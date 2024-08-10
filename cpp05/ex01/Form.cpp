# include "Form.hpp"

Form::Form() : _name("Random_Form"), _isSigned(false), _reqSignGrade(150), _reqExecGrade(150) {
    std::cout << "Default Form Constructor called!" << std::endl;
}

Form::~Form() {
    std::cout << "Form Deconstructor called!" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _reqSignGrade(signGrade), _reqExecGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHigh();
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLow();
}

Form::Form(const Form &copy) : _name(copy.getName()), _isSigned(copy.getSign()), _reqSignGrade(copy.getSignGrade()), _reqExecGrade(copy.getExecGrade()){
}

Form &Form::operator=(const Form &element) {
    if (this != &element) {
        this->_isSigned = element.getSign();
    }
    return *this;
}


// ACCESSOR METHODS
std::string Form::getName() const {
    return this->_name;
}

bool        Form::getSign() const {
    return this->_isSigned;
}

int         Form::getSignGrade() const {
    return this->_reqSignGrade;
}

int         Form::getExecGrade() const {
    return this->_reqExecGrade;
}


// OTHER MEMBER FUNCTIONS
void    Form::beSigned(Bureaucrat &b) {
    if (this->getSign() == true)
        throw AlreadySigned();
    if (b.GetGrade() <= this->getSignGrade()) {
        this->_isSigned = true;
    }
    else
        throw GradeTooLow();
}

        
// EXCEPTIONS
const char* Form::GradeTooLow::what() const throw() {
	return "Grade is too low";
}

const char* Form::GradeTooHigh::what() const throw() {
	return "Grade is too high";
}

const char* Form::AlreadySigned::what() const throw() {
    return "Form Already Signed!";
}

std::ostream &operator<<(std::ostream &out, const Form &var) {
    out << "Name: " << var.getName() << ", Signature: " << var.getSign() << ", RSign: " << var.getSignGrade() << ", RExec: " << var.getExecGrade();
    return out;
}
