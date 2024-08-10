# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", 25, 5), _target("default") {
}

// CLASS MANIPULATION METHOD
PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("Presidential Pardon Form", 25, 5), _target(target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy), _target(copy.getTarget()){
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &element) {
    if (this != &element)
	{
		this->setSign(element.getSign());
		this->_target = element.getTarget();
	}
	return *this;
}

// ACCESSOR METHOD
std::string PresidentialPardonForm::getTarget(void) const {
    return this->_target;
}
        
// OTHER MEMBER FUNCTION
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (this->getSign() == false)
        throw NotSigned();
    if (executor.GetGrade() > this->getExecGrade())
        throw GradeTooLow();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::print(std::ostream &out) const{
    out << _target << ", signed: " << getSign() << ", required sign grade: " << getSignGrade() << ", required execute grade: " << getExecGrade();
}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm &var) {
    var.print(out);
	return out;
}