#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() :
_name("default"),
_requieredSignGrade(75),
_requieredExecGrade(75),
_isSigned(false) {}

AForm::AForm(const str& name, const int gradeSign, const int gradeExec) :
_name(name.empty() ? "default" : name),
_requieredSignGrade(gradeSign),
_requieredExecGrade(gradeExec),
_isSigned(false)
{
	checkGrade(gradeSign);
	checkGrade(gradeExec);
}

AForm::AForm(const AForm& other) : 
_name(other._name), 
_requieredSignGrade(other._requieredSignGrade),
_requieredExecGrade(other._requieredExecGrade),
_isSigned(other._isSigned) {}

AForm::~AForm() {}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

// == getters ========
str		AForm::getName() const
{
	return (this->_name);
}

int		AForm::getSignGrade() const
{
	return (this->_requieredSignGrade);
}

int		AForm::getExecGrade() const
{
	return (this->_requieredExecGrade);
}

bool	AForm::getSignedState() const
{
	return (this->_isSigned);
}
// ===================


void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_requieredSignGrade)
		throw Bureaucrat::GradeTooLowException();
	if (this->_isSigned)
		throw AForm::AlreadySignedException();
	this->_isSigned = true;
}

AForm::AlreadySignedException::AlreadySignedException() :
	std::runtime_error("AForm is already signed") {}

AForm::NotSignedException::NotSignedException() :
	std::runtime_error("AForm is not signed") {}

std::ostream&	operator<<(std::ostream& os, const AForm& other)
{
	os	<< "Name: " << other.getName() << "\n"
		<< "Requiered grade to sign: " << other.getSignGrade() << "\n"
		<< "Requiered grade to execute: " << other.getExecGrade() << "\n"
		<< "Is this form signed: " << (other.getSignedState() ? "Yes" : "No")
		<< std::endl;
	return (os);
}