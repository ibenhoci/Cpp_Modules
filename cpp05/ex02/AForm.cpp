# include "AForm.hpp"

AForm::AForm() : _name("Random_AForm"), _isSigned(false), _reqSignGrade(150), _reqExecGrade(150) {
    std::cout << "Default AForm Constructor called!" << std::endl;
}

AForm::~AForm() {
    std::cout << "AForm Deconstructor called!" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _reqSignGrade(signGrade), _reqExecGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHigh();
    else if (signGrade > 150 || execGrade > 150)
        throw GradeTooLow();
}

AForm::AForm(const AForm &copy) : _name(copy.getName()), _isSigned(copy.getSign()), _reqSignGrade(copy.getSignGrade()), _reqExecGrade(copy.getExecGrade()){
}

AForm &AForm::operator=(const AForm &element) {
    if (this != &element) {
        this->_isSigned = element.getSign();
    }
    return *this;
}


// ACCESSOR METHODS
std::string AForm::getName() const {
    return this->_name;
}

bool        AForm::getSign() const {
    return this->_isSigned;
}

int         AForm::getSignGrade() const {
    return this->_reqSignGrade;
}

int         AForm::getExecGrade() const {
    return this->_reqExecGrade;
}

void        AForm::setSign(bool sign) {
    this->_isSigned = sign;
}

// OTHER MEMBER FUNCTIONS
void    AForm::beSigned(Bureaucrat &b) {
    if (this->getSign() == true)
        throw AlreadySigned();
    if (b.GetGrade() <= this->getSignGrade()) {
        this->_isSigned = true;
    }
    else
        throw GradeTooLow();
}
        
// EXCEPTIONS
const char* AForm::GradeTooLow::what() const throw() {
	return "Grade is too low";
}

const char* AForm::GradeTooHigh::what() const throw() {
	return "Grade is too high";
}

const char* AForm::AlreadySigned::what() const throw() {
    return "Form Already Signed!";
}

const char* AForm::NotSigned::what() const throw() {
    return "Form Is Not Signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &var) {
    var.print(out);
    return out;
}
