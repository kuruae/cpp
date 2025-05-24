#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5),
	_target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const str& target) :
	AForm("PresidentialPardonForm", 25, 5),
	_target(target.empty() ? "default" : target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other.getName(), other.getSignGrade(), other.getExecGrade()),
	_target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (this->getSignedState() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	this->pardon();
}

void PresidentialPardonForm::pardon() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}