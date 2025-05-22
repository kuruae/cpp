#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() :
_name("default"),
_requieredSignGrade(75),
_requieredExecGrade(75),
_isSigned(false) {}

Form::Form(const str& name, const int gradeSign, const int gradeExec) :
_name(name.empty() ? "default" : name),
_requieredSignGrade(gradeSign),
_requieredExecGrade(gradeExec),
_isSigned(false)
{
	checkGrade(gradeSign);
	checkGrade(gradeExec);
}

Form::Form(const Form& other) : 
_name(other._name), 
_requieredSignGrade(other._requieredSignGrade),
_requieredExecGrade(other._requieredExecGrade),
_isSigned(other._isSigned) {}

Form::~Form() {}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

// == getters ========
str		Form::getName() const
{
	return (this->_name);
}

int		Form::getSignGrade() const
{
	return (this->_requieredSignGrade);
}

int		Form::getExecGrade() const
{
	return (this->_requieredExecGrade);
}

bool	Form::getSignedState() const
{
	return (this->_isSigned);
}
// ===================


void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_requieredSignGrade)
		throw Bureaucrat::GradeTooLowException();
	if (this->_isSigned)
		throw Form::AlreadySignedException();
	this->_isSigned = true;
}

Form::AlreadySignedException::AlreadySignedException() :
	std::runtime_error("Form is already signed") {}

std::ostream&	operator<<(std::ostream& os, const Form& other)
{
	os	<< "Name: " << other.getName() << "\n"
		<< "Requiered grade to sign: " << other.getSignGrade() << "\n"
		<< "Requiered grade to execute: " << other.getExecGrade() << "\n"
		<< "Is this form signed: " << (other.getSignedState() ? "Yes" : "No")
		<< std::endl;
	return (os);
}