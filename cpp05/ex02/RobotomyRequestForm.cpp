# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45), _target("default") {
}

// CLASS MANIPULATION METHOD
RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("Robotomy Request Form", 72, 45), _target(target) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy), _target(copy.getTarget()){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &element) {
    if (this != &element)
	{
		this->setSign(element.getSign());
		this->_target = element.getTarget();
	}
	return *this;
}

// ACCESSOR METHOD
std::string RobotomyRequestForm::getTarget(void) const {
    return this->_target;
}
        
// OTHER MEMBER FUNCTION
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (this->getSign() == false)
        throw NotSigned();
    if (executor.GetGrade() > this->getExecGrade())
        throw GradeTooLow();
    std::cout << "Drilling noise..." << std::endl;
    if (rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getTarget() << ": robotomy has failed" << std::endl;
}

void RobotomyRequestForm::print(std::ostream &out) const{
    out << _target << ", signed: " << getSign() << ", required sign grade: " << getSignGrade() << ", required execute grade: " << getExecGrade();
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm &var) {
    var.print(out);
	return out;
}