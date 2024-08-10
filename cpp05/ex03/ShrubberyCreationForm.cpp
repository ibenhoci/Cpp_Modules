# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 145, 137), _target("default") {
}

// CLASS MANIPULATION METHOD
ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy), _target(copy.getTarget()){
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &element) {
    if (this != &element)
	{
		this->setSign(element.getSign());
		this->_target = element.getTarget();
	}
	return *this;
}

// ACCESSOR METHOD
std::string ShrubberyCreationForm::getTarget(void) const {
    return this->_target;
}
        
// OTHER MEMBER FUNCTION
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (this->getSign() == false)
        throw NotSigned();
    if (executor.GetGrade() > this->getExecGrade())
        throw GradeTooLow();
    std::ofstream ofs(_target + "_shrubbery");
    if (!ofs)
        throw std::runtime_error("Error creating file.");
    ofs << "       *\n"
        << "      ***\n"
        << "     *****\n"
        << "    *******\n"
        << "   *********\n"
        << "  ***********\n"
        << " *************\n"
        << "***************\n"
        << "      |||\n"
        << "      |||\n"
        << "      |||\n";

    ofs.close();
}

void ShrubberyCreationForm::print(std::ostream &out) const{
    out << _target << ", signed: " << getSign() << ", required sign grade: " << getSignGrade() << ", required execute grade: " << getExecGrade();
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm &var) {
    var.print(out);
	return out;
}