#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RobotomyRequestForm", 72, 45),
	_target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const str& target) :
	AForm("RobotomyRequestForm", 72, 45),
	_target(target.empty() ? "default" : target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other.getName(), other.getSignGrade(), other.getExecGrade()),
	_target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (this->getSignedState() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	this->robotomize();
}

void RobotomyRequestForm::robotomize() const
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int random = rand() % 2;

	std::cout << "*DRILLING NOISES* DRRRRRRRR" << std::endl;

	if (random == 0)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " robotomy failed." << std::endl;
}